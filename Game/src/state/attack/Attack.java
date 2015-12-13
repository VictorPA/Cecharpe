package state.attack;

import java.lang.reflect.InvocationTargetException;

import unit.*;

public abstract class Attack {
	
	protected byte typeOfAttack;
	protected Attackable attackable;
	protected CanAttack attacker;
	
	public Attack(byte typeOfAttack) {
		
		this.typeOfAttack = typeOfAttack;
	}
	
	public static class AutoAttack extends Attack {
	
		public AutoAttack(CanAttack attacker) {
			
			super(PlayableCharacter.PHYSICAL);
			this.attacker = attacker; 
		}

		public long RNG(CanAttack attacker) {
		
			int luk = attacker.getLuck();
			long critModifier = attacker.getCritModifier();
		
			return ((int)(Math.random()*100) < luk)?critModifier:1;
		
		} 
		
		public int attackEffect() {

			long modifier = this.RNG(attacker);
			return (int)(this.attacker.getAttack()*modifier);
 
		}
		
	};

	public abstract int attackEffect() throws ClassNotFoundException, NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, InstantiationException;
	
	public void setAttackable(Attackable attackable) {this.attackable = attackable;}	
	
	public byte getTypeOfAttack() { return this.typeOfAttack; }
}