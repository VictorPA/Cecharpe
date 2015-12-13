package unit;

import item.*;

public class Player {
	
	private static final byte maxWeight = 100;
	private String name;
	private PlayableCharacter playableCharacter;
	private Item[] inventory;
	
	public Player(String name,PlayableCharacter playableCharacter) {
		
		this.name = name;
		this.playableCharacter = playableCharacter;
		this.inventory = new Item[maxWeight];
	}
	
	public String getName() {
		return name;
	}

	public PlayableCharacter getPlayableCharacter() {
		return playableCharacter;
	}

	public void setPlayableCharacter(PlayableCharacter playableCharacter) {
		this.playableCharacter = playableCharacter;
	}

	public Item[] getInventory() {
		return inventory;
	}
	
}