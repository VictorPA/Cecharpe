package effect.status;

import effect.status.StatusEffect;
import spell.Spell;
import state.attack.Attackable;
import state.select.Selectable;

public class Burn extends StatusEffect {
	
	private Spell spell;
	
	public Burn(int turnDuration, Spell spell) {
		
		super(turnDuration,spell);
	}

	public void theEffect(Selectable selectable) {
		
		Attackable attackable = (Attackable) selectable;
		
		try {unfreeze(attackable);}
			
		catch(NullPointerException e) {attackable.getDamaged(attackable.getHp()*spell.getSpellLevel()/10);}
	
	}
	
	private void unfreeze(Attackable attackable) {
		
		StatusEffect freeze = attackable.getStatus().get(FREEZE);
		
		if(this.firstTime) {
			
			freeze.removeTurnDuration();
			this.swapEffect(attackable);
		}
	}
	
	public byte getStatusType() {
	
		return BURN;
	}

}
