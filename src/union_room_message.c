#include "global.h"
#include "link_rfu.h"
#include "mystery_gift_server.h"
#include "mystery_gift_client.h"
#include "constants/union_room.h"

ALIGNED(4) const u8 gText_UR_EmptyString[] = _("");
ALIGNED(4) const u8 gText_UR_Colon[] = _(":");
ALIGNED(4) const u8 gText_UR_ID[] = _("{ID}");
ALIGNED(4) const u8 gText_UR_PleaseStartOver[] = _("Veuillez recommencer depuis le début.");
ALIGNED(4) const u8 gText_UR_WirelessSearchCanceled[] = _("La recherche de la COMMUNICATION\nSANS FIL a été annulée.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("ともだちからの れんらくを\nまっています");
ALIGNED(4) const u8 gText_UR_AwaitingCommunication[] = _("{STR_VAR_1}! Attente \nd'un autre joueur.");
ALIGNED(4) const u8 gText_UR_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Attente de\nlink! App. sur START une fois prêts");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする");
ALIGNED(4) static const u8 sText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sLinkGroupActionTexts[] = {
    sText_SingleBattle,
    sText_DoubleBattle,
    sText_MultiBattle,
    sText_TradePokemon,
    sText_Chat,
    sText_DistWonderCard,
    sText_DistWonderNews,
    sText_DistWonderCard,
    sText_HoldPokemonJump,
    sText_HoldBerryCrush,
    sText_HoldBerryPicking,
    sText_HoldBerryPicking,
    sText_HoldSpinTrade,
    sText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("Manque\n1 J.");
static const u8 sText_2PlayersNeeded[] = _("Manque\n2 J.");
static const u8 sText_3PlayersNeeded[] = _("Manque\n3 J.");
static const u8 sText_4PlayersNeeded[] = _("あと4にん\nひつよう");
static const u8 sText_2PlayerMode[] = _("MODE\n2 JOUEURS");
static const u8 sText_3PlayerMode[] = _("MODE\n3 JOUEURS");
static const u8 sText_4PlayerMode[] = _("MODE\n4 JOUEURS");
static const u8 sText_5PlayerMode[] = _("MODE\n5 JOUEURS");
const u8 *const gTexts_UR_PlayersNeededOrMode[][5] = {
    { // 2 players required
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    { // 4 players required
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    { // 2-5 players required
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    { // 3-5 players required
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    }
};

ALIGNED(4) const u8 gText_UR_BButtonCancel[] = _("{B_BUTTON}RETOUR");
ALIGNED(4) static const u8 sText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} vous contacte pour un\n{STR_VAR_1}. Accepter?");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouShareX[] = _("{STR_VAR_2} vous a contacté.\nPartager {STR_VAR_1}?");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} vous a contacté.\nL'ajouter aux membres?");
ALIGNED(4) const u8 gText_UR_AreTheseMembersOK[] = _("{STR_VAR_1}!\nOK avec ces membres?");
ALIGNED(4) const u8 gText_UR_CancelModeWithTheseMembers[] = _("Annuler le MODE {STR_VAR_1}\navec ces membres?");
ALIGNED(4) const u8 gText_UR_AnOKWasSentToPlayer[] = _("“OK” a été envoyé\nà {STR_VAR_1}.");

ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("L'autre DRESSEUR ne semble\npas être disponible…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("Transmission impossible avec\nun DRESSEUR trop éloigné.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("Tous les DRESSEURS\nne sont pas prêts.\p");
const u8 *const gTexts_UR_CantTransmitToTrainer[] = {
    sText_CantTransmitTrainerTooFar,
    sText_TrainersNotReadyYet
};

ALIGNED(4) const u8 gText_UR_ModeWithTheseMembersWillBeCanceled[] = _("Le MODE {STR_VAR_1} avec\nces membres va être annulé.{PAUSE}Í");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("Un des membres ne sera\nbientôt plus disponible.\p");
const u8 *const gTexts_UR_PlayerUnavailable[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("L'autre DRESSEUR est\nindisponible…\p");
ALIGNED(4) const u8 gText_UR_PlayerSentBackOK[] = _("{STR_VAR_1} renvoie un “OK”!");
ALIGNED(4) const u8 gText_UR_PlayerOKdRegistration[] = _("{STR_VAR_1} vous accepte comme\nmembre.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} répond “Non…”.\p");
ALIGNED(4) const u8 gText_UR_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nAttente d'autres membres!");
ALIGNED(4) const u8 gText_UR_QuitBeingMember[] = _("Se désinscrire?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Vous n'êtes plus membre.\p");
const u8 *const gTexts_UR_PlayerDisconnected[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) const u8 gText_UR_WirelessLinkEstablished[] = _("Le réseau de COMMUNICATION SANS\nFIL a été établi.");
ALIGNED(4) const u8 gText_UR_WirelessLinkDropped[] = _("Le réseau de COMMUNICATION SANS\nFIL a été interrompu.");
ALIGNED(4) const u8 gText_UR_LinkWithFriendDropped[] = _("Le link avec votre ami a été\ninterrompu…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} répond “Non…”.");
const u8 *const gTexts_UR_LinkDropped[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = gText_UR_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = gText_UR_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Voulez-vous le MODE\n{STR_VAR_2}?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Voulez-vous le MODE\n{STR_VAR_2}?");
// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("はなしかけています…\nしょうしょう おまちください"); // Unused
ALIGNED(4) const u8 gText_UR_AwaitingPlayersResponseAboutTrade[] = _("Attente d'une réponse de {STR_VAR_1}\npour l'échange…");

ALIGNED(4) static const u8 sText_Communicating[] = _("Communication en cours{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("Communication avec {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("Patienter un instant{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
const u8 *const gTexts_UR_CommunicatingWait[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Salut! Vous vouliez quelque chose?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Bonjour jeune fille.\nJe peux vous aider?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Content de vous revoir!\nQu'est-ce que ça sera cette fois?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Oh! Bonjour, {PLAYER}!\nVous désirez quelque chose?");
const u8 *const gTexts_UR_HiDoSomething[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Quelque chose vous tente?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Vous désirez quelque chose?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: Qu'est-ce que vous\nvoulez faire maintenant?");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}‘また なにかする？");

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Quelqu'un vous contacte.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} essaie de vous contacter.{PAUSE 60}");
const u8 *const gTexts_UR_PlayerContactedYou[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("En attente d'une réponse de\nl'autre DRESSEUR…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("En attente d'une réponse de\n{STR_VAR_1}…");
const u8 *const gTexts_UR_AwaitingResponse[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_AwaitingResponseCancelBButton[] = _("あいての ていあんを まっています\nビーボタンで キャンセル");

ALIGNED(4) const u8 gText_UR_ShowTrainerCard[] = _("L'autre DRESSEUR vous montre\nsa CARTE DE DRESSEUR.\pVoulez-vous montrer votre\nCARTE DE DRESSEUR?");
ALIGNED(4) const u8 gText_UR_BattleChallenge[] = _("L'autre DRESSEUR veut se\nbattre contre vous.\pAccepter le combat?");
ALIGNED(4) const u8 gText_UR_ChatInvitation[] = _("L'autre DRESSEUR vous invite\nà discuter.\pAccepter l'invitation?");
ALIGNED(4) const u8 gText_UR_OfferToTradeMon[] = _("Il y a une offre d'échange pour\nvotre {DYNAMIC 1} de N. {DYNAMIC} \pcontre un\n{DYNAMIC 3} de N. {DYNAMIC 2}.\pAccepter l'échange?");
ALIGNED(4) const u8 gText_UR_OfferToTradeEgg[] = _("Il y a une offre d'échange pour\nvotre OEUF enregistré.\lAccepter l'offre d'échange?");
ALIGNED(4) const u8 gText_UR_ChatDropped[] = _("Le tchat est abandonné.");
ALIGNED(4) const u8 gText_UR_OfferDeclined1[] = _("Vous déclinez l'offre.\p");
ALIGNED(4) const u8 gText_UR_OfferDeclined2[] = _("L'offre est déclinée.\p");
ALIGNED(4) const u8 gText_UR_ChatEnded[] = _("La discussion est terminée.");
// Unused
static const u8 *const sInvitationTexts[] = {
    gText_UR_ShowTrainerCard,
    gText_UR_BattleChallenge,
    gText_UR_ChatInvitation,
    gText_UR_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("On est en plein dans un tchat.\nTu nous rejoins?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Salut, {PLAYER}!\nOn est en train de tchater.\lTu veux nous rejoindre?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Bonjour! On est en plein dans\nun tchat. Tu nous rejoins?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Oh, coucou, {PLAYER}!\nNous sommes en train de tchater.\lTu te joins à nous?");
const u8 *const gTexts_UR_JoinChat[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) const u8 gText_UR_TrainerAppearsBusy[] = _("……\nLe DRESSEUR est occupé…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("Un combat, hein?\nTrès bien, juste un instant.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Un tchat?\nPas de problème, juste un instant.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Pareil pour moi!\nVoilà ma CARTE DE DRESSEUR.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("Un combat? Bien sûr!\nJuste un instant, je me prépare.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Un tchat?\nPas de problème, juste un instant.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("On se présente?\nVoilà ma CARTE DE DRESSEUR.");
const u8 *const gTexts_UR_WaitOrShowCard[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("チャットだね！\nわかった ちょっと まってて！");
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Merci d'avoir patienté!\nAllez, commençons le combat!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("Parfait!\nCommençons le tchat.{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Tu n'as pas trop attendu?\nCommençons!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Tu n'as pas trop attendu?\nCommençons le tchat.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("L'échange va commencer.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("Le combat va commencer.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Début du tchat…{PAUSE 60}");
const u8 *const gTexts_UR_StartActivity[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Dommage! Mes POKéMON ne sont\npas vraiment en forme.\lJe t'écraserai une prochaine fois.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Je suis désolée, mais mes POKéMON\nne se sentent pas bien…\pBattons-nous une prochaine fois!\p");
const u8 *const gTexts_UR_BattleDeclined[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Hein? Ma CARTE DE DRESSEUR…\nJ'l'ai mise où?\lTant pis, la prochaine alors!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Oh! Mais où est passée ma\nCARTE DE DRESSEUR?\lDésolée! La prochaine fois alors!\p");
const u8 *const gTexts_UR_ShowTrainerCardDeclined[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Si tu as besoin de moi,\nfais-moi signe!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Si tu veux faire un truc, n'hésite\npas à demander.\p");
const u8 *const gTexts_UR_IfYouWantToDoSomething[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) const u8 gText_UR_TrainerBattleBusy[] = _("Oups! Dommage, j'ai autre \nchose à faire.\lUne autre fois, OK?\p");
ALIGNED(4) const u8 gText_UR_NeedTwoMonsOfLevel30OrLower1[] = _("Si tu veux te battre, il te faut\ndeux POKéMON de niveau\linférieur à 30.\p");
ALIGNED(4) const u8 gText_UR_NeedTwoMonsOfLevel30OrLower2[] = _("Pour combattre, il te faut deux\nPOKéMON de niveau inférieur\là 30.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Bon, OK.\nA la prochaine alors.\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Oh…\nA la prochaine alors.\p");
// Response from partner when player declines chat
const u8 *const gTexts_UR_DeclineChat[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Bon…\nC'est pas vraiment le moment.\lOn tchatera une prochaine fois.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Vraiment navrée.\nJ'ai plein de choses à faire.\lCe sera pour la prochaine fois.\p");
// Response from partner when they decline chat
const u8 *const gTexts_UR_ChatDeclined[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Waouh!\nT'en as dans le ventre!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("T'as utilisé cette capacité?\nBonne stratégie!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Voilà!\nC'est comme ça qu'y faut faire!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Oh! C'est pas le bon moment\npour utiliser ce POKéMON!\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("Ce POKéMON…\nIl est super bien dressé!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("C'est ça!\nC'est la bonne capacité!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("Incroyable!\nTu peux te battre comme ça?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("Tu sais vraiment changer de\nPOKéMON au bon moment!\p");
const u8 *const gTexts_UR_BattleReaction[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    }, {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Oh, je vois!\nC'était plutôt instructif!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Ne dis plus rien! J'ai des crampes\nà force de rire!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Oh?\nC'est vraiment arrivé?\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Hm… Quoi?\nSi tu le dis…\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Vraiment?\nJe savais pas.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Ahaha!\nVraiment?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Oui, c'est ça!\nC'est ce que je voulais dire.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("En d'autres termes…\nOui, c'est ça!\p");
const u8 *const gTexts_UR_ChatReaction[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    }, {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("Je montre toujours ma CARTE DE\nDRESSEUR pour me présenter.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("J'espère qu'on apprendra à se\nconnaître!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("On se présente notre CARTE DE\nDRESSEUR pour faire connaissance.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Ravie de te connaître. On va\nbien s'entendre tous les deux!\p");
const u8 *const gTexts_UR_TrainerCardReaction[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    }, {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Cool! \nJe le voulais vraiment ce POKéMON!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Finalement, j'obtiens ce\nPOKéMON grâce à un échange.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("Je suis en train de faire\nun échange.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("C'est le POKéMON que je voulais\ntellement!\p");
const u8 *const gTexts_UR_TradeReaction[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    }, {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

const u8 gText_UR_XCheckedTradingBoard[] = _("{STR_VAR_1} vérifie le\nPANNEAU D'ECHANGE.\p");
ALIGNED(4) const u8 gText_UR_RegisterMonAtTradingBoard[] = _("Bienvenue au PANNEAU D'ECHANGE.\pVous pouvez enregistrer vos\nPOKéMON pour un échange.\pVoulez-vous enregistrer un de vos\nPOKéMON?");
ALIGNED(4) const u8 gText_UR_TradingBoardInfo[] = _("Ce PANNEAU D'ECHANGE sert aux\n"
                                                    "échanges de POKéMON.\p"
                                                    "Tout ce que vous devez faire est\n"
                                                    "d'enregister un POKéMON avant.\p"
                                                    "Un autre DRESSEUR peut offrir un\n"
                                                    "POKéMON de son équipe en retour.\p"
                                                    "Nous espérons que vous échangerez\n"
                                                    "vos POKéMON avec le plus de \l"
                                                    "DRESSEURS possible.\p"
                                                    "Voulez-vous enregistrer un de vos\n"
                                                    "POKéMON?");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("こうかんけいじばん の とうろくが\nかんりょう しました\pごりよう ありがとう\nございました！\p");
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("けいじばんに だれも ポケモンを\nとうろく していません\p\n");
ALIGNED(4) const u8 gText_UR_ChooseRequestedMonType[] = _("Choisissez le type de POKéMON\nque vous voulez pour l'échange.\n");
ALIGNED(4) const u8 gText_UR_WhichMonWillYouOffer[] = _("Quel POKéMON de votre équipe\nvoulez-vous échanger?\p");
ALIGNED(4) const u8 gText_UR_RegistrationCanceled[] = _("L'enregistrement a été annulé.\p");
ALIGNED(4) const u8 gText_UR_RegistraionCompleted[] = _("L'enregistrement est terminé.\p");
ALIGNED(4) const u8 gText_UR_TradeCanceled[] = _("L'échange a été annulé.\p");
ALIGNED(4) const u8 gText_UR_CancelRegistrationOfMon[] = _("Annuler l'enregistrement de votre\n{STR_VAR_1} de N. {STR_VAR_2}?");
ALIGNED(4) const u8 gText_UR_CancelRegistrationOfEgg[] = _("Annuler l'enregistrement de votre\nOEUF?");
ALIGNED(4) const u8 gText_UR_RegistrationCanceled2[] = _("L'enregistrement a été annulé.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("こうかんを きぼうしているひとを\nひょうじします");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("こうかん したい トレーナーを\nえらんで ください");
ALIGNED(4) const u8 gText_UR_AskTrainerToMakeTrade[] = _("Voulez-vous demander à {STR_VAR_1}\nde faire un échange?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("……\nあいての へんじを まっています");
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("あなたが こうかんにだす\nポケモンが とうろくされていません\p");
ALIGNED(4) const u8 gText_UR_DontHaveTypeTrainerWants[] = _("Vous n'avez pas de POKéMON\ndu type {STR_VAR_2}\pque veut {STR_VAR_1}.\p");
ALIGNED(4) const u8 gText_UR_DontHaveEggTrainerWants[] = _("Vous n'avez pas l'OEUF que veut\n{STR_VAR_1}.\p");

ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} ne peut faire d'échange\npour votre POKéMON maintenant.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("Vous ne pouvez pas échanger le\nPOKéMON de {STR_VAR_1} maintenant.\p");
// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) const u8 gText_UR_TradeOfferRejected[] = _("Votre offre d'échange a\nété refusée.\p");
ALIGNED(4) const u8 gText_UR_EggTrade[] = _("ECHANGE D'OEUF");
ALIGNED(4) const u8 gText_UR_ChooseJoinCancel[] = _("{DPAD_UPDOWN}CHOISIR  {A_BUTTON}JOINDRE  {B_BUTTON}ANNULER");
ALIGNED(4) const u8 gText_UR_ChooseTrainer[] = _("Veuillez choisir un DRESSEUR.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Veuillez choisir un DRESSEUR\npour un combat SOLO.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Veuillez choisir un DRESSEUR\npour un combat DUO.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Veuillez choisir un DRESSEUR\npour un combat MULTI.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Veuillez choisir le DRESSEUR avec\nqui faire l'échange.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Veuillez choisir le DRESSEUR qui\npartage les CARTES MIRACLE.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Veuillez choisir le DRESSEUR qui\npartage les INFOS MIRACLE.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Sautez avec un mini POKéMON!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("BROYEUR DE BAIES!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("ATTRAPE-BAIES DODRIO!\nChoisissez le MENEUR.");
const u8 *const gTexts_UR_ChooseTrainer[] = {
    [LINK_GROUP_SINGLE_BATTLE] = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE] = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]  = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]         = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]  = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]   = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING] = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]   = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]   = sText_ChooseTrainerToShareWonderNews
};

ALIGNED(4) const u8 gText_UR_SearchingForWirelessSystemWait[] = _("Recherche d'un système de\nCOMMUNICATION SANS FIL. Patienter.");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("ダブルバトルでは 2ひき いじょうの\nポケモンが ひつようです\p");
ALIGNED(4) const u8 gText_UR_AwaitingPlayersResponse[] = _("Attente d'une réponse de {STR_VAR_1}…");
ALIGNED(4) const u8 gText_UR_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1} doit vous enregistrer\ncomme membre. Veuillez patienter.");
ALIGNED(4) const u8 gText_UR_AwaitingResponseFromWirelessSystem[] = _("Attente d'une réponse d'un système\nde COMMUNICATION SANS FIL.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("ほかの さんかしゃが そろうまで\nしょうしょう おまちください");

ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Aucune CARTE n'est échangée pour\nl'instant.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("Aucune INFO n'est échangée pour\nl'instant.");
const u8 *const gTexts_UR_NoWonderShared[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) const u8 gText_UR_Battle[] = _("COMBAT");
ALIGNED(4) const u8 gText_UR_Chat2[] = _("TCHAT");
ALIGNED(4) const u8 gText_UR_Greetings[] = _("SALUT");
ALIGNED(4) const u8 gText_UR_Exit[] = _("RETOUR");

ALIGNED(4) const u8 gText_UR_Exit2[] = _("RETOUR");
ALIGNED(4) const u8 gText_UR_Info[] = _("INFOS");
ALIGNED(4) const u8 gText_UR_NameWantedOfferLv[] = _("NOM{CLEAR_TO 0x3C}RECHERCHE{CLEAR_TO 0x6E}OFFRE{CLEAR_TO 0xC6}N.");

ALIGNED(4) const u8 gText_UR_SingleBattle[] = _("COMBAT SOLO");
ALIGNED(4) const u8 gText_UR_DoubleBattle[] = _("COMBAT DUO");
ALIGNED(4) const u8 gText_UR_MultiBattle[] = _("COMBAT MULTI.");
ALIGNED(4) const u8 gText_UR_PokemonTrades[] = _("ECHANGES DE PKMN");
ALIGNED(4) const u8 gText_UR_Chat[] = _("TCHAT");
ALIGNED(4) const u8 gText_UR_Cards[] = _("CARTES");
ALIGNED(4) const u8 gText_UR_WonderCards[] = _("CARTES MIRACLE");
ALIGNED(4) const u8 gText_UR_WonderNews[] = _("INFOS MIRACLE");
ALIGNED(4) const u8 gText_UR_PokemonJump[] = _("SAUT POKéMON");
ALIGNED(4) const u8 gText_UR_BerryCrush[] = _("BROYEUR DE BAIES");
ALIGNED(4) const u8 gText_UR_BerryPicking[] = _("ATTRAPE-BAIES");
ALIGNED(4) const u8 gText_UR_Search[] = _("RECHERCHE");
ALIGNED(4) const u8 gText_UR_SpinTrade[] = _("ぐるぐるこうかん");
ALIGNED(4) const u8 gText_UR_ItemTrade[] = _("アイテムトレード");

ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("C'est une carte NORMALE!");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("C'est une carte en BRONZE!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("C'est une carte en CUIVRE!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("C'est une carte en ARGENT!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("C'est une carte en OR!");
const u8 *const gTexts_UR_CardColor[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) const u8 gText_UR_TrainerCardInfoPage1[] = _("C'est la CARTE DE DRESSEUR\nde {DYNAMIC 0} {DYNAMIC 1}…\l{DYNAMIC 2}\pPOKéDEX: {DYNAMIC 3}\nTEMPS:    {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) const u8 gText_UR_TrainerCardInfoPage2[] = _("COMBATS: {DYNAMIC 0} VICT.  {DYNAMIC 2} DEF.\nECHANGES:  {DYNAMIC 3}\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Ravi de te connaître!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Ravie de te connaître!{PAUSE 60}");
const u8 *const gTexts_UR_GladToMeetYou[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) const u8 gText_UR_FinishedCheckingPlayersTrainerCard[] = _("La CARTE DE DRESSEUR de\n{DYNAMIC 1} a été lue.");
static const u8 sText_CanceledReadingCard[] = _("La lecture de la carte a\nété annulée.");
static const struct MysteryGiftClientCmd sClientScript_DynamicError[] = {
    {CLI_RECV, MG_LINKID_DYNAMIC_MSG},
    {CLI_COPY_MSG},
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_BUFFER_FAILURE}
};

const struct MysteryGiftServerCmd gServerScript_ClientCanceledCard[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_DynamicError)},
    {SVR_SEND},
    {SVR_LOAD_MSG, PTR_ARG(sText_CanceledReadingCard)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_CLIENT_CANCELED}
};
