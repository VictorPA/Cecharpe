package item;

import unit.*;
import effect.*;

public abstract class Item {

	protected Effect[] effects;
		
	public void applyEffect(PlayableCharacter playableCharacter) {
		
		for(Effect effect : this.effects)
			
			effect.doEffect(playableCharacter); 
	}
	
}