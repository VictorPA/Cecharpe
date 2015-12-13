package state.select;

import java.util.HashMap;
import effect.status.StatusEffect;
import graphicInterface.Option;

public interface Selectable {
	
	public static final byte CANATTACK = 0;
	public static final byte CANMOVE = 1;
	public static final byte CANCAST = 2;
	public static final byte KILLABLE = 3;
	public static final byte TARGETABLE = 4;
	public static final byte DESTROYABLE = 5;
	
	Option options();
	
	boolean getCanMove();
	
	boolean getCanAttack();
	
	boolean getCanCast();
	
	boolean getDestroyable();
	
	boolean getKillable();
	
	boolean getTargetable();
	
	HashMap<Byte,StatusEffect> getStatus();
	
	void setCanMove(boolean canMove);
	
	void setCanAttack(boolean canAttack);
	
	void setCanCast(boolean canCast);
	
	void setKillable(boolean killable);
	
	void setTargetable(boolean targetable);
	
	void setDestroyable(boolean destroyable);
		
}