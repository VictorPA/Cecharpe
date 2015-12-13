package unit;

import java.util.HashMap;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import effect.status.StatusEffect;
import state.attack.*;
import state.select.*;
import item.*;
import javafx.util.*;


public abstract class PlayableCharacter implements Attackable,CanAttack {
	
	public static final byte nbOfStats = 5;
	public static final byte ATK = 0;
	public static final byte DEF = 1;
	public static final byte LUK = 2;
	public static final byte INT = 3;
	public static final byte MDF = 4;
	public static final byte HEALTH = 5;
	public static final byte MANA = 6;
	public static final byte PHYSICAL = 0;
	public static final byte MAGICAL = 4;
	public static final ArrayList<PlayableCharacter> playableCharacters = new ArrayList<PlayableCharacter>();
	protected HashMap<Byte,StatusEffect> statusEffects;
	protected int id;
	protected int hp;
	protected int mana;
	protected int maxHp;
	protected int maxMana;
	protected int[] stats;
	protected boolean isAlive;
	protected long critModifier;
	protected Equipment equipment;
	protected Attack AUTOATTACK;
	protected boolean[] state;
	
	protected PlayableCharacter(int id, int hp, int mana) {
		
		this.AUTOATTACK = new Attack.AutoAttack(this);
		this.id = id;
		this.hp = hp;
		this.maxHp = hp;
		this.mana = mana;
		this.maxMana = mana;
		this.isAlive = true;
		this.critModifier = 2;
		this.stats = new int[nbOfStats];
		this.state = new boolean[5];
		this.state[CANATTACK] = this.state[CANMOVE] = this.state[KILLABLE] = this.state[TARGETABLE] = true;
		playableCharacters.add(this); // may be useful later if something affects all playableCharacters
	
	}
		
	public abstract void select(Selectable selectable);
	
	public int getMaxHp() {
		
		return this.maxHp;
	}
	
	public int getMaxMana() {
		
		return this.maxMana;
	}
	
	public int getHp() { 
		
		return this.hp;
	}
	
	public void setHp(int hp) {
		
		this.hp = hp;
	}
	
	public int getMana() {
		
		return this.mana;
	}
	public void setMana(int mana) {
		
		this.mana = mana;
	}
	
	public void setMaxHp(int hp) {
		
		this.maxHp = hp;
	}
	
	public void setMaxMana(int mana) {
		
		this.maxMana = mana;
	}
	
	public int getDamage(Attack attack) throws ClassNotFoundException, NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, InstantiationException {
		
		return attack.attackEffect();
	}
	
	public int getAttack() {
		
		return stats[ATK];
	}
	 
	public int getDefense(byte typeOfAttack) {
		 
		return stats[typeOfAttack];
	}
	 
	public int getLuck() {
		 
		return stats[LUK];
	}
	
	public int getIntelligence() {
		
		return stats[INT];
	}
	
	public int getMagicDefense() {
		
		return stats[MDF];
	}
	
	public long getCritModifier() {
		 
		  return this.critModifier;
	}
	
	public Equipment getEquipment() {
		
		return this.equipment;
	}

	public int getDamaged(int dmg) {
		
		// later: make a list of Health "substitution" like shields, iterate through it and apply damage to them first before health
		
		this.hp -= Math.max(this.hp,dmg);
		
		return dmg;
	}
	
	protected void updateStatus() {
		
		this.isAlive = this.hp == 0?false:true;			
			
	}
	
	public void getAttacked(CanAttack attacker, Attack attack) throws ClassNotFoundException, NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, InstantiationException { 
		 
		int dmg = attacker.getDamage(attack);
		int def = this.getDefense(attack.getTypeOfAttack());
		  
		dmg -= def;
		this.getDamaged(dmg);
		this.updateStatus();
	}
	
	public void autoAttack(Attackable attackable) throws ClassNotFoundException, NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, InstantiationException {
		
		// later: make test to see if the condition of attack are satisfied
		// example isInRange();
        		
		attackable.getAttacked(this,AUTOATTACK);
	}
	
	public void addStatusEffect(StatusEffect statusEffect) {
		
		if(this.statusEffects == null)
			
			this.statusEffects = new HashMap<Byte,StatusEffect>();
		
		this.statusEffects.put(statusEffect.getStatusType(),statusEffect);
	}
	
	public HashMap<Byte,StatusEffect> getStatus() {
		
		return this.statusEffects;
	}
	
	public boolean getCanAttack() { return this.state[CANATTACK];}
	
	public boolean getCanMove() { return this.state[CANMOVE];}
	
	public boolean getCanCast() { return this.state[CANCAST];}
	
	public boolean getKillable() { return this.state[KILLABLE];}
	
	public boolean getTargetable() {return this.state[TARGETABLE];}
	
	public boolean getDestroyable() {return false;}
	
	public void setCanAttack(boolean canAttack) { this.state[CANATTACK] = canAttack;}
	
	public void setCanMove(boolean canMove) {this.state[CANMOVE] = canMove;}
	
	public void setCanCast(boolean canCast) {this.state[CANCAST] = canCast;}
	
	public void setKillable(boolean killable) {this.state[KILLABLE] = killable;}
	
	public void setTargetable(boolean targetable) {this.state[TARGETABLE] = targetable;}
	
	public void setDestroyable(boolean destroyable) {};
	

}