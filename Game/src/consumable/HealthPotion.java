package consumable;

import item.Item;
import effect.Effect;
import effect.Heal;

public class HealthPotion extends Item {

	public HealthPotion(int amount) {
		
		this.effects = new Effect[1];
		this.effects[0] = new Heal(amount);
	}
	
}
