package unit;

import java.util.ArrayList;
import state.select.*;
import spell.*;
import graphicInterface.Option;

public class Mage extends PlayableCharacter {

	private ArrayList<Spell> listOfSpells;
	
	public Mage(int id, int hp, int mana) {
		
		super(id, hp, mana);
		this.state[CANCAST] = true;
		this.listOfSpells = new ArrayList<Spell>();
		this.addSpells();

	}
	
	private void addSpells() {
		
		this.listOfSpells.add(Bolt.FIRE,new Firebolt(this));
		this.listOfSpells.add(Bolt.ICE,new Icebolt(this));
	
	}

	public void select(Selectable selectable) {

	}

	public Option options() {

		return null;
	}

}


