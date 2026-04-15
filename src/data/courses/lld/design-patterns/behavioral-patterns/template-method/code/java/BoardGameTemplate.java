// Template Method — Game Turn Sequence
abstract class BoardGame {
    // Template method — skeleton is fixed
    public final void playTurn(Player player) {
        System.out.println("\n--- " + player.getName() + "'s turn ---");
        rollDice(player);
        movePlayer(player);
        if (landedOnSpecialSquare(player)) {
            handleSpecialSquare(player);
        }
        checkWinCondition(player);
    }
    
    protected void rollDice(Player player) {
        int roll = (int)(Math.random() * 6) + 1;
        System.out.println("Rolled: " + roll);
        player.setLastRoll(roll);
    }
    
    protected abstract void movePlayer(Player player);
    protected abstract boolean landedOnSpecialSquare(Player player);
    protected abstract void handleSpecialSquare(Player player);
    protected abstract void checkWinCondition(Player player);
}

class SnakesAndLadders extends BoardGame {
    protected void movePlayer(Player p) {
        p.setPosition(p.getPosition() + p.getLastRoll());
        System.out.println("Moved to position " + p.getPosition());
    }
    protected boolean landedOnSpecialSquare(Player p) {
        return snakes.containsKey(p.getPosition()) || ladders.containsKey(p.getPosition());
    }
    protected void handleSpecialSquare(Player p) {
        if (snakes.containsKey(p.getPosition())) {
            System.out.println("🐍 Snake! Sliding down...");
            p.setPosition(snakes.get(p.getPosition()));
        } else {
            System.out.println("🪜 Ladder! Climbing up...");
            p.setPosition(ladders.get(p.getPosition()));
        }
    }
    protected void checkWinCondition(Player p) {
        if (p.getPosition() >= 100) System.out.println("🏆 " + p.getName() + " wins!");
    }
}
