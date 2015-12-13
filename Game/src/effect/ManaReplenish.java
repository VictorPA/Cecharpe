package effect;

import state.select.Selectable;
import effect.Effect;
import unit.PlayableCharacter;

public class ManaReplenish extends Effect{
	
	private int mana;
	
	public ManaReplenish(int mana) {
		
		this.mana = mana;
	}
	
	public void doEffect(Selectable selectable) {
		
		PlayableCharacter pc = (PlayableCharacter) selectable;
		pc.setMana(Math.min(pc.getMaxMana(),pc.getMana()+this.mana));
	}
	
}