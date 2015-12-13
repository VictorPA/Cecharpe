package consumable;

import item.Item;
import effect.Effect;
import effect.ManaReplenish;

public class ManaPotion extends Item {

		public ManaPotion(int amount) {
			
			this.effects = new Effect[1];
			this.effects[0] = new ManaReplenish(amount);
		}

}
