import React, { useEffect, useState } from "react";

const CountdownTimer = ({ targetDate }: { targetDate: string }) => {
  const calculateTimeLeft = () => {
    const difference = +new Date(targetDate) - +new Date();
    let timeLeft = { days: 0, hours: 0, minutes: 0, seconds: 0 };
    if (difference > 0) {
      timeLeft = {
        days: Math.floor(difference / (1000 * 60 * 60 * 24)),
        hours: Math.floor((difference / (1000 * 60 * 60)) % 24),
        minutes: Math.floor((difference / 1000 / 60) % 60),
        seconds: Math.floor((difference / 1000) % 60),
      };
    }
    return timeLeft;
  };

  const [timeLeft, setTimeLeft] = useState(calculateTimeLeft());

  useEffect(() => {
    const timer = setInterval(() => setTimeLeft(calculateTimeLeft()), 1000);
    return () => clearInterval(timer);
  }, []);

  return (
    <div className="flex justify-center gap-6 text-center font-mono text-lg text-foreground">
      <div>
        <div className="text-3xl font-bold">{timeLeft.days}</div>
        <div className="text-muted-foreground text-sm">Days</div>
      </div>
      <div>
        <div className="text-3xl font-bold">{timeLeft.hours}</div>
        <div className="text-muted-foreground text-sm">Hours</div>
      </div>
      <div>
        <div className="text-3xl font-bold">{timeLeft.minutes}</div>
        <div className="text-muted-foreground text-sm">Mins</div>
      </div>
      <div>
        <div className="text-3xl font-bold">{timeLeft.seconds}</div>
        <div className="text-muted-foreground text-sm">Secs</div>
      </div>
    </div>
  );
};
export default CountdownTimer;
