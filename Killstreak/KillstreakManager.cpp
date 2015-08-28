#include "KillstreakManager.h"

using namespace Maelstrom;

// Constructor ============================================================================================================================================
KillstreakManager::KillstreakManager() : mKillstreakMap() {}
//=========================================================================================================================================================

// Private member functions ===============================================================================================================================
void KillstreakManager::ThrowNullPtrExceptionIfNecessary(void* ptr) const {
	if (ptr == nullptr)
		throw NullPointerException();
}


bool KillstreakManager::PlayerHasKS(Player* player) const  {
	ThrowNullPtrExceptionIfNecessary(player);

	auto it = mKillstreakMap.find(player->GetGUID());
	if (it == mKillstreakMap.end())
		return false;

	return true;
}
//=========================================================================================================================================================

// Public member functions ================================================================================================================================
void KillstreakManager::InsertNewPlayer(Player* player) {
	if (PlayerHasKS(player))
		return;

	mKillstreakMap.insert({ player->GetGUID(), 0 });
}

void KillstreakManager::RemovePlayer(Player* player){
	ThrowNullPtrExceptionIfNecessary(player);

	mKillstreakMap.erase(player->GetGUID());
}

void KillstreakManager::IncrementPlayerKS(Player* player) {
	if (!PlayerHasKS(player))
		return;

	mKillstreakMap[player->GetGUID()] += 1;
}

uint64 KillstreakManager::GetPlayerKS(Player* player) const {
	if (!PlayerHasKS(player))
		return 0;

	return mKillstreakMap.at(player->GetGUID());
}

void KillstreakManager::ResetPlayerKS(Player* player) {
	if (!PlayerHasKS(player))
		return;

	mKillstreakMap[player->GetGUID()] = 0;
}
//=========================================================================================================================================================