/*
 * Copyright (C) 2021 BfaCore Reforged
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "InstanceScript.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "nyalotha.h"

const Position middle_of_the_room_pos = { -1485.0f, 487.0f, -556.0f, 1.58f };
const Position mana_orb_pos = { -1463.0f, 481.0f, -556.0f, 3.19f };

enum Spells
{
	PERIODIC_ENERGY_GAIN = 299956,
	CONSUMING_SHADOWS = 308158, //every 15s
	CONSUMING_SHADOWS_DAMAGE = 308168,
	DEVOUR_MAGIC_CAST = 307805, //every 25s
	DEVOUR_MAGIC_DAMAGE = 307821,
	DEVOUR_MAGIC_MARK = 307806,
	DEVOUR_MAGIC_GIVE_POWER = 309498,
	DEVOURED_ABYSS_CREATE_AT = 307839,
	DEVOURED_ABYSS_AT_DAMAGE = 307586, //pacify, silence, screen effect
	DEVOURED_ABYSS_DAMAGE_9Y = 315291,
	DEVOURED_ABYSS_DRAIN_MANA = 309853, // drain mana, silence
	STYGIAN_ANNIHILATION_CAST = 308044, //every 40s
	STYGIAN_ANNIHILATION_DAMAGE = 307773,
	SHADOW_CLAWS = 310129, //leaving 24s debuff on tank
	SHADOW_WOUNDS_PERIODIC = 315882,
	DARK_AEGIS = 305675, //passive for add 156650
	DARK_OFFERING = 308872, //casted on boss, interrupted by entering to devoured abyss ats
	DARK_OFFERING_GIVE_POWER_MANA = 309514,
	DARK_MANIFESTATION_CREATE_AT = 312117, //no data?
	DARK_MANIFESTATION_CREAT_AT_PULL = 308904, //22237
    DARK_MANIFESTATION_DAMAGE = 308908,
    DARK_MANIFESTATION_SUMMON = 305625,
	DARK_MANIFESTATION_EXP = 308908,
	//PHASE 2
	OBSIDIAN_SKIN = 306005,
	OBSIDIAN_SKIN_DAMAGE = 306070,
	OBISIDAN_SKIN_DAMAGE_2 = 314907,
    OBSIDIAN_SHATTER_DAMAGE = 315098,
	OBSIDIAN_SKIN_VISUAL = 315198,
	OBSIDIAN_SHATTER_TRIGGER_CONSUME_MAGIC = 305722,
    OBSIDIAN_SKIN_LOSE_MANA_INSTEAD_OF_HP = 314803,
	FORBIDDEN_MANA_DEBUFF = 306301,
	FORBIDDEN_MANA_EXP = 306295,
	FORBIDDEN_MANA_MOD_HEALING_AND_MANA_REGEN = 310611,
    FORBIDDEN_MANA_GIVE_POWER_MAUT = 306296,
	//Heroic
	BLACK_WINGS = 305663,
	DRAIN_ESSENCE_PERIODIC = 314993,
	DRAIN_ESSENCE_EXP = 314995,
	//Mythic
	ANCIENT_CURSE = 315025,
	ANCIENT_CURSE_INSTAKILL = 315083,
    ANCIENT_CURSE_DAMAGE = 314390,
	ENRAGED = 310613
};

void AddSC_maut()
{

}