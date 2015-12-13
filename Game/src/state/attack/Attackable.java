package state.attack;

import state.select.*;

import java.lang.reflect.InvocationTargetException;

import effect.status.StatusEffect;

public interface Attackable extends Selectable {
	
	int getLuck();
	
	int getDefense(byte typeOfAttack);
	
	int getDamaged(int dmg); 
	
	int getHp();
	
	int getMaxHp();
	
	void getAttacked(CanAttack canAttack,Attack attack)throws ClassNotFoundException, NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, InstantiationException; 
	
	void addStatusEffect(StatusEffect statusEffect);
	
	
}