package state.attack;

import java.lang.reflect.InvocationTargetException;

import state.select.*;

public interface CanAttack extends CanSelect {
	
	long getCritModifier();
	
	int getAttack(); 
	
	int getLuck();
	
	int getDamage(Attack attack)throws ClassNotFoundException, NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, InstantiationException; 
	
	void autoAttack(Attackable attackable)throws ClassNotFoundException, NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, InstantiationException;

}