package effect.status;

import java.util.HashMap;

import spell.Spell;
import state.select.Selectable;

public abstract class StatusEffect {
	
	public static final byte BURN = 0;
	public static final byte FREEZE = 0;
	
	protected Spell spell;
	protected static HashMap<Byte,StatusEffect> oldStatusEffects = new HashMap<Byte,StatusEffect>();
	protected int turnDuration;
	protected boolean firstTime;
	
	protected StatusEffect(int turnDuration, Spell spell) {
		
		this.turnDuration = turnDuration;
		this.spell = spell;
		this.firstTime = true;
	}
	
	public abstract void theEffect(Selectable selectable);
	
	public void applyStatusEffect(Selectable selectable) {	
			
			this.theEffect(selectable);
			firstTime = false;
									
			if(this.checkTurnDuration())
			
				this.decreaseTurnDuration();
			
			else
			
				this.swapEffect(selectable);		
	}
	
	protected void swapEffect(Selectable selectable) {
		
		oldStatusEffects.put(this.getStatusType(),this);
		selectable.getStatus().remove(this.getStatusType());
	}

	public void decreaseTurnDuration() { this.turnDuration--; }
	
	public void removeTurnDuration() { this.turnDuration = 0; }
	
	public boolean checkTurnDuration() { return this.turnDuration > 0; }
	
	public int getTurnDuration() { return turnDuration; }
	
	public void addTurnDuration(int duration) { this.turnDuration += duration; }
	
	public abstract byte getStatusType();
	
	public static boolean checkOldStatusEffects(byte StatusEffect) { return oldStatusEffects.get(StatusEffect) == null; }
	
	public static StatusEffect getOldStatusEffect(byte StatusEffect) { return oldStatusEffects.get(StatusEffect); }
	
	public static void removeOldStatusEffect(byte StatusEffect) {oldStatusEffects.put(StatusEffect,null);}

}
