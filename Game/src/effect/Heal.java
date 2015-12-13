package effect;

import state.select.Selectable;
import effect.Effect;
import unit.PlayableCharacter;

public class Heal extends Effect {
	
	private int hp;
	
	public Heal(int hp) {
		
		this.hp = hp;
	}
	
	public void doEffect(Selectable selectable) {
		
		PlayableCharacter pc = (PlayableCharacter) selectable;
		pc.setHp(Math.min(pc.getMaxHp(),pc.getHp()+this.hp));
	}
}

