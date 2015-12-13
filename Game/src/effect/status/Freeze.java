package effect.status;

import spell.Spell;
import state.select.Selectable;

public class Freeze extends StatusEffect {
	
	Freeze(int turnDuration, Spell spell) {
		
		super(turnDuration,spell);
	}

	public void theEffect(Selectable selectable) {
		
		selectable.setCanMove(false);
		selectable.setCanAttack(false);
		selectable.setCanCast(false);
	}

	public byte getStatusType() {
	
		return FREEZE;
	}
	
}