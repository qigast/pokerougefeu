@ These are event scripts. They should not be moved to C.

#include "constants/global.h"
#include "constants/flags.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "constants/region_map_sections.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"

	.section .rodata
	
	.align 2
MysteryEventScript_StampCard::
	setvaddress MysteryEventScript_StampCard
	setorcopyvar VAR_RESULT, 1
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	setorcopyvar VAR_RESULT, 0
	specialvar VAR_0x8009, GetMysteryGiftCardStat
	subvar VAR_0x8008, VAR_0x8009
	buffernumberstring STR_VAR_1, VAR_0x8008
	lock
	faceplayer
	vmessage sText_MysteryGiftStampCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftStampCard:
	.string "Merci d'utiliser le système\n"
	.string "CARTE TAMPON.\p"
	.string "Il vous en faut {STR_VAR_1} de plus pour\n"
	.string "remplir complètement la carte.$"

MysteryEventScript_SurfPichu::
	setvaddress MysteryEventScript_SurfPichu
	vgoto_if_unset FLAG_MYSTERY_GIFT_DONE, SurfPichu_GiveIfPossible
	returnram

SurfPichu_GiveIfPossible:
	specialvar VAR_EVENT_PICHU_SLOT, CalculatePlayerPartyCount
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, PARTY_SIZE, SurfPichu_FullParty
	setflag FLAG_MYSTERY_GIFT_DONE
	vcall SurfPichu_GiveEgg
	lock
	faceplayer
	vmessage sText_MysteryGiftEgg
	waitmessage
	waitbuttonpress
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	release
	end

SurfPichu_FullParty:
	lock
	faceplayer
	vmessage sText_FullParty
	waitmessage
	waitbuttonpress
	release
	end

SurfPichu_GiveEgg:
	giveegg SPECIES_PICHU
	setmonmodernfatefulencounter VAR_EVENT_PICHU_SLOT
	setmonmetlocation VAR_EVENT_PICHU_SLOT, METLOC_FATEFUL_ENCOUNTER
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, 1, SurfPichu_Slot1
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, 2, SurfPichu_Slot2
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, 3, SurfPichu_Slot3
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, 4, SurfPichu_Slot4
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, 5, SurfPichu_Slot5
	return

SurfPichu_Slot1:
	setmonmove 1, 2, MOVE_SURF
	return

SurfPichu_Slot2:
	setmonmove 2, 2, MOVE_SURF
	return

SurfPichu_Slot3:
	setmonmove 3, 2, MOVE_SURF
	return

SurfPichu_Slot4:
	setmonmove 4, 2, MOVE_SURF
	return

SurfPichu_Slot5:
	setmonmove 5, 2, MOVE_SURF
	return

sText_MysteryGiftEgg:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Nous avons un OEUF pour vous!\p"
	.string "Elevez-le avec amour et\n"
	.string "gentillesse.$"

sText_FullParty:
	.string "Oh, l'équipe est pleine.\p"
	.string "Revenez quand vous aurez rangé\n"
	.string "un POKéMON dans votre PC.$"

MysteryEventScript_VisitingTrainer::
	setvaddress MysteryEventScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryEventScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainer
	waitmessage
	waitbuttonpress
	release
	end

MysteryEventScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainer_2
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainer:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "En tenant la CARTE MIRACLE,\n"
	.string "vous pouvez effectuer des\p"
	.string "sondages dans les BOUTIQUES\n"
	.string "POKéMON.\p"
	.string "Utilisez ces sondages pour inviter\n"
	.string "des DRESSEURS aux ILES SEVII.\p"
	.string "Laissez-moi vous donner un mot\n"
	.string "de passe secret:\p"
	.string "“DONNE-MOI\n"
	.string "UN COMBAT”\p"
	.string "Ecrivez ça sur un sondage et\n"
	.string "envoyez-le au SYSTEME DE\p"
	.string "COMMUNICATION SANS FIL.$"

sText_MysteryGiftVisitingTrainer_2:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Un DRESSEUR arrivé aux\n"
	.string "ILES SEVII vous cherche.\p"
	.string "On espère que vous aimerez\n"
	.string "vous battre contre ce DRESSEUR.\p"
	.string "Vous pouvez inviter des DRESSEURS\n"
	.string "en entrant le mot de passe.\p"
	.string "Essayez de trouver des mots de\n"
	.string "passe qui pourraient fonctionner.$"

MysteryEventScript_BattleCard::
	setvaddress MysteryEventScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryEventScript_BattleCardInfo
	setorcopyvar VAR_RESULT, 2
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, 3, MysteryEventScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_2
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryEventScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "La CARTE COMBAT garde la trace\n"
	.string "de vos combats contre les\p"
	.string "DRESSEURS ayant la même\n"
	.string "CARTE.\p"
	.string "Recherchez les DRESSEURS ayant\n"
	.string "la même carte que vous.\p"
	.string "Vous pouvez voir le classement\n"
	.string "général en lisant les JOURNAUX.\p"
	.string "Vous devriez essayer!$"

sText_MysteryGiftBattleCountCard_2:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Félicitations!\p"
	.string "Vous recevez un prix pour avoir\n"
	.string "gagné trois combats!\p"
	.string "On espère que ça vous donnera\n"
	.string "envie de combattre encore plus.$"

MysteryEventScript_AuroraTicket::
	setvaddress MysteryEventScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_FOUGHT_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET, 1
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicket1
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET, 1
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicket2
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketNoPlace
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketGot
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicket1:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Vous devez être {PLAYER}.\n"
	.string "Il y a un ticket pour vous.$"

sText_AuroraTicket2:
	.string "Il peut être utilisé au port de\n"
	.string "CARMIN SUR MER.\p"
	.string "Essayez-le pour voir de quoi \n"
	.string "il s'agit.$"

sText_AuroraTicketGot:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYST.$"

sText_AuroraTicketNoPlace:
	.string "Oh, je regrette {PLAYER}. La POCHE\n"
	.string "OBJ. RARES du SAC est pleine.\p"
	.string "Faites le tri dans votre SAC et\n"
	.string "revenez plus tard.$"

MysteryEventScript_MysticTicket::
	setvaddress MysteryEventScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_FOUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_FOUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET, 1
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicket2
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET, 1
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicket1
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketNoPlace
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketGot
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicket2:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYST.$"

sText_MysticTicket1:
	.string "Il peut être utilisé au port de\n"
	.string "CARMIN SUR MER.\p"
	.string "Essayez-le pour voir de quoi \n"
	.string "il s'agit.$"

sText_MysticTicketGot:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYST.$"

sText_MysticTicketNoPlace:
	.string "Oh, je regrette {PLAYER}. La POCHE\n"
	.string "OBJ. RARES du SAC est pleine.\p"
	.string "Faites le tri dans votre SAC et\n"
	.string "revenez plus tard.$"

MysteryEventScript_AlteringCave::
	setvaddress MysteryEventScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, 10, MysteryEventScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryEventScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Il y a de plus en plus de rumeurs\n"
	.string "sur l'apparition de POKéMON rares.\p"
	.string "Les rumeurs parlent de la GROTTE\n"
	.string "METAMO sur l'ILE DU LOINTAIN.\p"
	.string "Vous devriez y aller pour vérifier\n"
	.string "si les rumeurs sont vraies.$"
