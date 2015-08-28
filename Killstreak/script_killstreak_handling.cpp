#include "ScriptMgr.h"
#include "KillstreakManager.h"

class script_killstreak_handling : public PlayerScript {

public:

	// Constructor ===================================================================================================================================================
	script_killstreak_handling() : PlayerScript("script_killstreak_handling") {}
	//================================================================================================================================================================

	// Overriding script functions ===================================================================================================================================
	void OnPVPKill(Player* killer, Player* killed) {
			try {
				//Don't modify the two following instructions
				Maelstrom::sKillstreakMgr->InsertNewPlayer(killer);
				Maelstrom::sKillstreakMgr->InsertNewPlayer(killed);

				//We increase the killer's killstreak
				//If you want to do it under certain conditions only, wrap the two following instructions in a "if" block
				//For instance:
				//if(killer->GetAreaId() == 720) {
				// Maelstrom::sKillstreakMgr->IncrementPlayerKS(killer);
				// Maelstrom::sKillstreakMgr->ResetPlayerKS(killed);
				// } -> it will only count kills and reset killstreaks if the killer is in area 720

				Maelstrom::sKillstreakMgr->IncrementPlayerKS(killer);
				//We reset the killed's killstreak
				Maelstrom::sKillstreakMgr->ResetPlayerKS(killed);
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
	}

	void OnLogout(Player* player) {
		Maelstrom::sKillstreakMgr->RemovePlayer(player);
	}
	//================================================================================================================================================================
};

void AddSC_script_killstreak_handling() {
	new script_killstreak_handling();
}
