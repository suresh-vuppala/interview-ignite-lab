from enum import Enum
from datetime import datetime, timedelta
from typing import Optional, List, Dict
from threading import Lock, RLock
from abc import ABC, abstractmethod
import time

# ============================================================
# Enumerations
# ============================================================

class VehicleType(Enum):
    MOTORCYCLE = "MOTORCYCLE"
    CAR = "CAR"
    TRUCK = "TRUCK"

class SpotType(Enum):
    COMPACT = "COMPACT"
    REGULAR = "REGULAR"
    LARGE = "LARGE"

class TicketStatus(Enum):
    ACTIVE = "ACTIVE"
    PAID = "PAID"
    LOST = "LOST"

class PaymentMethod(Enum):
    CASH = "CASH"
    CREDIT_CARD = "CREDIT_CARD"
    DIGITAL_WALLET = "DIGITAL_WALLET"

# ============================================================
# Vehicle Class
# ============================================================

class Vehicle:
    def __init__(self, license_plate: str, vehicle_type: VehicleType, color: str):
        self.license_plate = license_plate
        self.vehicle_type = vehicle_type
        self.color = color

    def get_vehicle_type(self) -> VehicleType:
        return self.vehicle_type

    def get_license_plate(self) -> str:
        return self.license_plate

# ============================================================
# ParkingSpot Class
# ============================================================

class ParkingSpot:
    def __init__(self, spot_id: str, spot_type: SpotType, floor: int):
        self.spot_id = spot_id
        self.spot_type = spot_type
        self.floor = floor
        self.is_occupied = False
        self.vehicle: Optional[Vehicle] = None
        self.lock = Lock()  # Thread safety

    def can_fit_vehicle(self, vehicle_type: VehicleType) -> bool:
        """Check if vehicle can fit in this spot"""
        if vehicle_type == VehicleType.MOTORCYCLE:
            return True  # Can park anywhere
        elif vehicle_type == VehicleType.CAR:
            return self.spot_type in [SpotType.REGULAR, SpotType.LARGE]
        elif vehicle_type == VehicleType.TRUCK:
            return self.spot_type == SpotType.LARGE
        return False

    def assign_vehicle(self, vehicle: Vehicle) -> bool:
        """Thread-safe vehicle assignment"""
        with self.lock:
            if self.is_occupied:
                return False  # Already occupied
            
            if not self.can_fit_vehicle(vehicle.get_vehicle_type()):
                return False  # Vehicle doesn't fit
            
            self.vehicle = vehicle
            self.is_occupied = True
            return True

    def remove_vehicle(self) -> None:
        """Thread-safe vehicle removal"""
        with self.lock:
            self.vehicle = None
            self.is_occupied = False

    def get_spot_id(self) -> str:
        return self.spot_id

    def get_floor(self) -> int:
        return self.floor

    def get_spot_type(self) -> SpotType:
        return self.spot_type

# ============================================================
# ParkingTicket Class
# ============================================================

class ParkingTicket:
    def __init__(self, ticket_id: str, vehicle: Vehicle, spot: ParkingSpot):
        self.ticket_id = ticket_id
        self.vehicle = vehicle
        self.spot = spot
        self.entry_time = datetime.now()
        self.exit_time: Optional[datetime] = None
        self.status = TicketStatus.ACTIVE

    def calculate_duration(self) -> int:
        """Calculate parking duration in hours"""
        end_time = datetime.now() if self.status == TicketStatus.ACTIVE else self.exit_time
        duration = (end_time - self.entry_time).total_seconds() / 3600
        return max(1, int(duration))  # Minimum 1 hour

    def mark_exit(self) -> None:
        self.exit_time = datetime.now()
        self.status = TicketStatus.PAID

    def get_ticket_id(self) -> str:
        return self.ticket_id

    def get_vehicle(self) -> Vehicle:
        return self.vehicle

    def get_spot(self) -> ParkingSpot:
        return self.spot

    def get_status(self) -> TicketStatus:
        return self.status

# ============================================================
# Strategy Pattern: Pricing Strategy
# ============================================================

class PricingStrategy(ABC):
    @abstractmethod
    def calculate_fee(self, vehicle_type: VehicleType, hours: int) -> float:
        pass

class HourlyPricingStrategy(PricingStrategy):
    def calculate_fee(self, vehicle_type: VehicleType, hours: int) -> float:
        rates = {
            VehicleType.MOTORCYCLE: 2.0,
            VehicleType.CAR: 4.0,
            VehicleType.TRUCK: 6.0
        }
        hourly_rate = rates.get(vehicle_type, 4.0)
        return hourly_rate * hours

# ============================================================
# Payment Class
# ============================================================

class Payment:
    def __init__(self, amount: float, payment_method: PaymentMethod):
        self.amount = amount
        self.payment_method = payment_method
        self.timestamp = datetime.now()
        self.processed = False

    def process_payment(self) -> bool:
        """Simulate payment processing"""
        self.processed = True
        print(f"Payment of ${self.amount:.2f} processed successfully.")
        return True

    def get_amount(self) -> float:
        return self.amount

    def is_processed(self) -> bool:
        return self.processed

# ============================================================
# Observer Pattern: DisplayBoard
# ============================================================

class DisplayBoard:
    def __init__(self, floor_number: int):
        self.floor_number = floor_number
        self.available_spots: Dict[SpotType, int] = {
            SpotType.COMPACT: 0,
            SpotType.REGULAR: 0,
            SpotType.LARGE: 0
        }

    def update(self, spot_type: SpotType, count: int) -> None:
        self.available_spots[spot_type] = count
        self.display()

    def display(self) -> None:
        print(f"Floor {self.floor_number} - Available Spots: "
              f"Compact={self.available_spots[SpotType.COMPACT]}, "
              f"Regular={self.available_spots[SpotType.REGULAR]}, "
              f"Large={self.available_spots[SpotType.LARGE]}")

# ============================================================
# ParkingFloor Class
# ============================================================

class ParkingFloor:
    def __init__(self, floor_number: int):
        self.floor_number = floor_number
        self.spots: Dict[str, ParkingSpot] = {}
        self.display_board = DisplayBoard(floor_number)
        self.lock = RLock()

    def add_spot(self, spot: ParkingSpot) -> None:
        with self.lock:
            self.spots[spot.get_spot_id()] = spot
            self.update_display_board()

    def get_available_spot(self, vehicle_type: VehicleType) -> Optional[ParkingSpot]:
        """Find available spot for vehicle type"""
        with self.lock:
            for spot in self.spots.values():
                if not spot.is_occupied and spot.can_fit_vehicle(vehicle_type):
                    return spot
            return None

    def update_display_board(self) -> None:
        """Count available spots by type and update display"""
        counts = {
            SpotType.COMPACT: 0,
            SpotType.REGULAR: 0,
            SpotType.LARGE: 0
        }

        for spot in self.spots.values():
            if not spot.is_occupied:
                counts[spot.get_spot_type()] += 1

        # Update display board
        for spot_type, count in counts.items():
            self.display_board.update(spot_type, count)

    def get_floor_number(self) -> int:
        return self.floor_number

# ============================================================
# Singleton Pattern: ParkingLot
# ============================================================

class ParkingLot:
    _instance = None
    _lock = Lock()

    def __new__(cls, name: str = "Main Parking Lot", address: str = "123 Main St"):
        if cls._instance is None:
            with cls._lock:
                if cls._instance is None:
                    cls._instance = super().__new__(cls)
                    cls._instance._initialized = False
        return cls._instance

    def __init__(self, name: str = "Main Parking Lot", address: str = "123 Main St"):
        if self._initialized:
            return
        
        self.name = name
        self.address = address
        self.floors: List[ParkingFloor] = []
        self.active_tickets: Dict[str, ParkingTicket] = {}
        self.pricing_strategy: PricingStrategy = HourlyPricingStrategy()
        self.ticket_counter = 0
        self.lot_lock = RLock()
        self._initialized = True

    @classmethod
    def get_instance(cls, name: str = "Main Parking Lot", address: str = "123 Main St"):
        """Thread-safe Singleton instance"""
        return cls(name, address)

    def add_floor(self, floor: ParkingFloor) -> None:
        with self.lot_lock:
            self.floors.append(floor)

    def get_available_spot(self, vehicle_type: VehicleType) -> Optional[ParkingSpot]:
        """Find available spot across all floors"""
        for floor in self.floors:
            spot = floor.get_available_spot(vehicle_type)
            if spot is not None:
                return spot
        return None

    def process_entry(self, vehicle: Vehicle) -> ParkingTicket:
        """Process vehicle entry"""
        with self.lot_lock:
            # Find available spot
            spot = self.get_available_spot(vehicle.get_vehicle_type())
            if spot is None:
                raise Exception("No available spot for vehicle type")

            # Assign vehicle to spot
            if not spot.assign_vehicle(vehicle):
                raise Exception("Failed to assign vehicle to spot")

            # Generate ticket
            self.ticket_counter += 1
            ticket_id = f"T{self.ticket_counter}"
            ticket = ParkingTicket(ticket_id, vehicle, spot)
            self.active_tickets[ticket_id] = ticket

            print(f"Vehicle {vehicle.get_license_plate()} "
                  f"parked at spot {spot.get_spot_id()} "
                  f"on floor {spot.get_floor()}")

            # Update display boards
            for floor in self.floors:
                floor.update_display_board()

            return ticket

    def process_exit(self, ticket: ParkingTicket) -> Payment:
        """Process vehicle exit"""
        with self.lot_lock:
            if ticket.get_status() != TicketStatus.ACTIVE:
                raise Exception("Ticket is not active")

            # Calculate fee
            hours = ticket.calculate_duration()
            fee = self.pricing_strategy.calculate_fee(
                ticket.get_vehicle().get_vehicle_type(), hours)

            # Create payment
            payment = Payment(fee, PaymentMethod.CREDIT_CARD)

            # Process payment
            if payment.process_payment():
                # Mark ticket as paid
                ticket.mark_exit()

                # Free the spot
                ticket.get_spot().remove_vehicle()

                # Remove from active tickets
                del self.active_tickets[ticket.get_ticket_id()]

                print(f"Vehicle {ticket.get_vehicle().get_license_plate()} "
                      f"exited. Duration: {hours} hours, Fee: ${fee:.2f}")

                # Update display boards
                for floor in self.floors:
                    floor.update_display_board()

            return payment

    def display_status(self) -> None:
        print("\n=== Parking Lot Status ===")
        print(f"Name: {self.name}")
        print(f"Active Tickets: {len(self.active_tickets)}")
        for floor in self.floors:
            floor.update_display_board()
        print("========================\n")

# ============================================================
# Main - Example Usage
# ============================================================

def main():
    try:
        # Get parking lot instance (Singleton)
        parking_lot = ParkingLot.get_instance("City Center Parking", "Downtown")

        # Create floors
        floor1 = ParkingFloor(1)
        floor2 = ParkingFloor(2)

        # Add spots to floor 1
        floor1.add_spot(ParkingSpot("F1-C1", SpotType.COMPACT, 1))
        floor1.add_spot(ParkingSpot("F1-C2", SpotType.COMPACT, 1))
        floor1.add_spot(ParkingSpot("F1-R1", SpotType.REGULAR, 1))
        floor1.add_spot(ParkingSpot("F1-R2", SpotType.REGULAR, 1))
        floor1.add_spot(ParkingSpot("F1-L1", SpotType.LARGE, 1))

        # Add spots to floor 2
        floor2.add_spot(ParkingSpot("F2-C1", SpotType.COMPACT, 2))
        floor2.add_spot(ParkingSpot("F2-R1", SpotType.REGULAR, 2))
        floor2.add_spot(ParkingSpot("F2-L1", SpotType.LARGE, 2))

        # Add floors to parking lot
        parking_lot.add_floor(floor1)
        parking_lot.add_floor(floor2)

        parking_lot.display_status()

        # Create vehicles
        car1 = Vehicle("ABC123", VehicleType.CAR, "Red")
        bike1 = Vehicle("XYZ789", VehicleType.MOTORCYCLE, "Black")
        truck1 = Vehicle("TRK456", VehicleType.TRUCK, "White")

        # Process entries
        ticket1 = parking_lot.process_entry(car1)
        ticket2 = parking_lot.process_entry(bike1)
        ticket3 = parking_lot.process_entry(truck1)

        parking_lot.display_status()

        # Simulate some time passing
        print("\n[Simulating time passage...]\n")
        time.sleep(1)

        # Process exits
        parking_lot.process_exit(ticket1)
        parking_lot.process_exit(ticket2)

        parking_lot.display_status()

        # Try to park another car
        car2 = Vehicle("DEF456", VehicleType.CAR, "Blue")
        ticket4 = parking_lot.process_entry(car2)

        parking_lot.display_status()

    except Exception as e:
        print(f"Error: {str(e)}")

if __name__ == "__main__":
    main()
