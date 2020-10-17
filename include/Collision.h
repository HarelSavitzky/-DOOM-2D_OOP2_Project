#pragma once
//--------------------include Section --------------------
#include<iostream>
#include "GameObject.h"
#include <typeindex>
#include "Slayer.h"
#include "Fire.h"
#include "Cacodemon.h"
#include "BaronOfHell.h"
#include "HeavyWeaponDude.h"
#include "CyberDemon.h"
#include "Revenant.h"
#include "Mancubus.h"
#include "PlasmaRifle.h"
#include "BFG9000.h"
#include "Pistol.h"
#include "ShotGun.h"
#include "ChainGun.h"
#include "MancubusShot.h"
#include "HeavyWeaponDudeShot.h"
#include "CyberDemonShot.h"
#include "Ammo.h"
#include "PistolAmmo.h"
#include "ChainGunAmmo.h"
#include "ShotGunAmmo.h"
#include "BFGAmmo.h"
#include "PlasmaRifleAmmo.h"
#include "Armor.h"
#include "Health.h"
#include "SmallHealth.h"
#include "BigHealth.h"
#include "UltraHealth.h"
#include "HorizontalWall.h"
#include "VerticalWall.h"
#include "DiagonalWallR.h"
#include "DiagonalWallL.h"

//--------------------using Section --------------------
using collisionFuncPtr = void (*)(GameObject&, GameObject&);
using Key = std::pair<std::type_index, std::type_index>;   
using collisionMap = std::map<Key, collisionFuncPtr>;

//--------------------Collision Class definition --------------------
class Collision
{
public:
    static Collision& instance();

    Collision(const Collision&) = delete;
    Collision& operator=(const Collision&) = delete;

    void handleCollision(GameObject& object1, GameObject& object2);

    collisionFuncPtr lookup(const std::type_index& class1, const std::type_index& class2);


private:
    Collision();
    collisionMap m_collisionMap;

};

//--------------------collisions--------------------
//---------slayer-------
void BFGSlayer(GameObject& BFG, GameObject& slayer);        //handle
void SlayerBFG(GameObject& slayer, GameObject& BFG);
//----------------------------------------
// slayer & ammo---------
void SlayerPistolAmmo(GameObject& slayer, GameObject& pistolammo);
void PistolAmmoSlayer(GameObject& pistolammo, GameObject& slayer);
void SlayerShotgunAmmo(GameObject& slayer, GameObject& shotgun);
void ShotgunAmmoSlayer(GameObject& shotgun, GameObject& slayer);
void SlayerChainGunAmmo(GameObject& slayer, GameObject& machinegun);
void ChainGunAmmoSlayer(GameObject& machinegun, GameObject& slayer);
void SlayerBFGAmmo(GameObject& slayer, GameObject& bfgAmmo);
void BFGAmmoSlayer(GameObject& bfgAmmo, GameObject& slayer);
void SlayerPlasmaRifleAmmo(GameObject& slayer, GameObject& plasmaAmmo);
void PlasmaRifleAmmoSlayer(GameObject& plasmaAmmo, GameObject& slayer);

//slayer & armor--------
void SlayerArmor(GameObject& slayer, GameObject& armor);
void ArmorSlayer(GameObject& armor, GameObject& slayer);

//slayer & health--------
void SlayerSmallHealth(GameObject& slayer, GameObject& health);
void SmallHealthSlayer(GameObject& health, GameObject& slayer);
void SlayerBigHealth(GameObject& slayer, GameObject& health);
void BigHealthSlayer(GameObject& health, GameObject& slayer);
void SlayerUltraHealth(GameObject& slayer, GameObject& health);
void UltraHealthSlayer(GameObject& health, GameObject& slayer);

//slayer & fire--------
void SlayerFire(GameObject& slayer, GameObject& fire);
void FireSlayer(GameObject& fire, GameObject& slayer);

//slayer & demons--------
void SlayerBaronOfHell(GameObject& slayer, GameObject& demon);
void BaronOfHellSlayer(GameObject& demon, GameObject& slayer);
void SlayerHeavyWeaponDude(GameObject& slayer, GameObject& demon);
void HeavyWeaponDudeSlayer(GameObject& demon, GameObject& slayer);
void SlayerRevenant(GameObject& slayer, GameObject& demon);
void RevenantSlayer(GameObject& demon, GameObject& slayer);
void SlayerCacodemon(GameObject& slayer, GameObject& demon);
void CacodemonSlayer(GameObject& demon, GameObject& slayer);
void SlayerCyberDemon(GameObject& slayer, GameObject& demon);
void CyberDemonSlayer(GameObject& demon, GameObject& slayer);
void MancubusSlayer(GameObject& demon, GameObject& slayer);
void SlayerMancubus(GameObject& slayer, GameObject& demon);
//slayer & enemyShots--------
void MancubusShotSlayer(GameObject& demon, GameObject& slayer);
void SlayerMancubusShot(GameObject& slayer, GameObject& demon);
void CyberDemonShotSlayer(GameObject& demon, GameObject& slayer);
void SlayerCyberDemonShot(GameObject& slayer, GameObject& demon);
void HeavyWeaponDudeShotSlayer(GameObject& demon, GameObject& slayer);
void SlayerHeavyWeaponDudeShot(GameObject& slayer, GameObject& demon);
//Walls & EnemyShots------------------
void HorizontalWallHeavyWeaponDudeShot(GameObject& wall, GameObject& demon);
void HeavyWeaponDudeShotHorizontalWall(GameObject& demon, GameObject& wall);
void VerticalWallHeavyWeaponDudeShot(GameObject& wall, GameObject& demon);
void HeavyWeaponDudeShotVerticalWall(GameObject& demon, GameObject& wall);
void DiagonalWallRHeavyWeaponDudeShot(GameObject& wall, GameObject& demon);
void HeavyWeaponDudeShotDiagonalWallR(GameObject& demon, GameObject& wall);
void DiagonalWallLHeavyWeaponDudeShot(GameObject& wall, GameObject& demon);
void HeavyWeaponDudeShotDiagonalWallL(GameObject& demon, GameObject& wall);
  //------------------
void HorizontalWallMancubusShot(GameObject& wall, GameObject& demon);
void MancubusShotHorizontalWall(GameObject& demon, GameObject& wall);
void VerticalWallMancubusShot(GameObject& wall, GameObject& demon);
void MancubusShotVerticalWall(GameObject& demon, GameObject& wall);
void DiagonalWallRMancubusShot(GameObject& wall, GameObject& demon);
void MancubusShotDiagonalWallR(GameObject& demon, GameObject& wall);
void DiagonalWallLMancubusShot(GameObject& wall, GameObject& demon);
void MancubusShotDiagonalWallL(GameObject& demon, GameObject& wall);
  //------------------
void HorizontalWallCyberDemonShot(GameObject& wall, GameObject& demon);
void CyberDemonShotHorizontalWall(GameObject& demon, GameObject& wall);
void VerticalWallCyberDemonShot(GameObject& wall, GameObject& demon);
void CyberDemonShotVerticalWall(GameObject& demon, GameObject& wall);
void DiagonalWallRCyberDemonShot(GameObject& wall, GameObject& demon);
void CyberDemonShotDiagonalWallR(GameObject& demon, GameObject& wall);
void DiagonalWallLCyberDemonShot(GameObject& wall, GameObject& demon);
void CyberDemonShotDiagonalWallL(GameObject& demon, GameObject& wall);
//---------demons & demons-------

void CacodemonCyberDemon(GameObject& demon2, GameObject& demon);               
void CyberDemonCacodemon(GameObject& demon, GameObject& demon2);
void MancubusCacodemon(GameObject& demon, GameObject& demon2);
void CacodemonMancubus(GameObject& demon2, GameObject& demon);
void MancubusCyberDemon(GameObject& demon, GameObject& demon2);
void CyberDemonMancubus(GameObject& demon2, GameObject& demon);
void HeavyWeaponDudeCyberDemon(GameObject& demon2, GameObject& demon);
void CyberDemonHeavyWeaponDude(GameObject& demon, GameObject& demon2);
void MancubusHeavyWeaponDude(GameObject& demon, GameObject& demon2);
void HeavyWeaponDudeMancubus(GameObject& demon2, GameObject& demon);
void CacodemonBaronOfHell(GameObject& demon2, GameObject& demon);
void BaronOfHellCacodemon(GameObject& demon, GameObject& demon2);
void CacodemonHeavyWeaponDude(GameObject& demon2, GameObject& demon);
void HeavyWeaponDudeCacodemon(GameObject& demon, GameObject& demon2);
void RevenantHeavyWeaponDude(GameObject& demon2, GameObject& demon);
void HeavyWeaponDudeRevenant(GameObject& demon, GameObject& demon2);
void RevenantCyberDemon(GameObject& demon2, GameObject& demon);
void CyberDemonRevenant(GameObject& demon, GameObject& demon2);
void MancubusRevenant(GameObject& demon, GameObject& demon2);
void RevenantMancubus(GameObject& demon2, GameObject& demon);
void BaronOfHellHeavyWeaponDude(GameObject& demon2, GameObject& demon);
void HeavyWeaponDudeBaronOfHell(GameObject& demon, GameObject& demon2);
void BaronOfHellRevenant(GameObject& demon2, GameObject& demon);
void RevenantBaronOfHell(GameObject& demon, GameObject& demon2);
void BaronOfHellCacodemon(GameObject& demon2, GameObject& demon);
void CacodemonBaronOfHell(GameObject& demon, GameObject& demon2);
void BaronOfHellCyberDemon(GameObject& demon2, GameObject& demon);
void CyberDemonBaronOfHell(GameObject& demon, GameObject& demon2);
void MancubusBaronOfHell(GameObject& demon2, GameObject& demon);
void BaronOfHellMancubus(GameObject& demon, GameObject& demon2);

//demons&themself
void MancubusMancubus(GameObject& demon2, GameObject& demon);
void BaronOfHellBaronOfHell(GameObject& demon2, GameObject& demon);
void CyberDemonCyberDemon(GameObject& demon2, GameObject& demon);
void CacodemonCacodemon(GameObject& demon2, GameObject& demon);
void RevenantRevenant(GameObject& demon2, GameObject& demon);
void HeavyWeaponDudeHeavyWeaponDude(GameObject& demon2, GameObject& demon);

//---------demons&shooting-------
//---------Cacodemon----------
void BFGCacodemon(GameObject& BFG, GameObject& demon);
void CacodemonBFG(GameObject& demon, GameObject& BFG);
void ShotGunCacodemon(GameObject& Shotgun, GameObject& demon);
void CacodemonShotGun(GameObject& demon, GameObject& Shotgun);
void ChainGunCacodemon(GameObject& Machinegun, GameObject& demon);
void CacodemonChainGun(GameObject& demon, GameObject& Machinegun);
void PistolCacodemon(GameObject& pistol, GameObject& demon);
void CacodemonPistol(GameObject& demon, GameObject& pistol);
void PlasmaRifleCacodemon(GameObject& plasma, GameObject& demon);
void CacodemonPlasmaRifle(GameObject& demon, GameObject& plasma);
//---------Mancubus-------
void BFGMancubus(GameObject& BFG, GameObject& demon);
void MancubusBFG(GameObject& demon, GameObject& BFG);
void ShotGunMancubus(GameObject& Shotgun, GameObject& demon);
void MancubusShotGun(GameObject& demon, GameObject& Shotgun);
void ChainGunMancubus(GameObject& Machinegun, GameObject& demon);
void MancubusChainGun(GameObject& demon, GameObject& Machinegun);
void PistolMancubus(GameObject& pistol, GameObject& demon);
void MancubusPistol(GameObject& demon, GameObject& pistol);
void PlasmaRifleMancubus(GameObject& plasma, GameObject& demon);
void MancubusPlasmaRifle(GameObject& demon, GameObject& plasma);
//---------BaronOfHell-------
void BFGBaronOfHell(GameObject& BFG, GameObject& demon);
void BaronOfHellBFG(GameObject& demon, GameObject& BFG);
void ShotGunBaronOfHell(GameObject& Shotgun, GameObject& demon);
void BaronOfHellShotGun(GameObject& demon, GameObject& Shotgun);
void ChainGunBaronOfHell(GameObject& Machinegun, GameObject& demon);
void BaronOfHellChainGun(GameObject& demon, GameObject& Machinegun);
void PistolBaronOfHell(GameObject& pistol, GameObject& demon);
void BaronOfHellPistol(GameObject& demon, GameObject& pistol);
void PlasmaRifleBaronOfHell(GameObject& plasma, GameObject& demon);
void BaronOfHellPlasmaRifle(GameObject& demon, GameObject& plasma);
//---------Revenant----------
void BFGRevenant(GameObject& BFG, GameObject& demon);
void RevenantBFG(GameObject& demon, GameObject& BFG);
void ShotGunRevenant(GameObject& Shotgun, GameObject& demon);
void RevenantShotGun(GameObject& demon, GameObject& Shotgun);
void ChainGunRevenant(GameObject& Machinegun, GameObject& demon);
void RevenantChainGun(GameObject& demon, GameObject& Machinegun);
void PistolRevenant(GameObject& pistol, GameObject& demon);
void RevenantPistol(GameObject& demon, GameObject& pistol);
void PlasmaRifleRevenant(GameObject& plasma, GameObject& demon);
void RevenantPlasmaRifle(GameObject& demon, GameObject& plasma);
//---------CyberDemon----------
void BFGCyberDemon(GameObject& BFG, GameObject& demon);
void CyberDemonBFG(GameObject& demon, GameObject& BFG);
void ShotGunCyberDemon(GameObject& Shotgun, GameObject& demon);
void CyberDemonShotGun(GameObject& demon, GameObject& Shotgun);
void ChainGunCyberDemon(GameObject& Machinegun, GameObject& demon);
void CyberDemonChainGun(GameObject& demon, GameObject& Machinegun);
void PistolCyberDemon(GameObject& pistol, GameObject& demon);
void CyberDemonPistol(GameObject& demon, GameObject& pistol);
void PlasmaRifleCyberDemon(GameObject& plasma, GameObject& demon);
void CyberDemonPlasmaRifle(GameObject& demon, GameObject& plasma);
//---------HeavyWeaponDude-------
void BFGHeavyWeaponDude(GameObject& BFG, GameObject& demon);
void HeavyWeaponDudeBFG(GameObject& demon, GameObject& BFG);
void ShotGunHeavyWeaponDude(GameObject& Shotgun, GameObject& demon);
void HeavyWeaponDudeShotGun(GameObject& demon, GameObject& Shotgun);
void ChainGunHeavyWeaponDude(GameObject& Machinegun, GameObject& demon);
void HeavyWeaponDudeChainGun(GameObject& demon, GameObject& Machinegun);
void PistolHeavyWeaponDude(GameObject& pistol, GameObject& demon);
void HeavyWeaponDudePistol(GameObject& demon, GameObject& pistol);
void PlasmaRifleHeavyWeaponDude(GameObject& plasma, GameObject& demon);
void HeavyWeaponDudePlasmaRifle(GameObject& demon, GameObject& plasma);

//-------------------------WALLS COLLISION-----------------------
//Slayer & walls---------------
void HorizontalWallSlayer(GameObject& wall, GameObject& demon);
void SlayerHorizontalWall(GameObject& demon, GameObject& wall);
void VerticalWallSlayer(GameObject& wall, GameObject& demon);
void SlayerVerticalWall(GameObject& demon, GameObject& wall);
void DiagonalWallRSlayer(GameObject& wall, GameObject& demon);
void SlayerDiagonalWallR(GameObject& demon, GameObject& wall);
void DiagonalWallLSlayer(GameObject& wall, GameObject& demon);
void SlayerDiagonalWallL(GameObject& demon, GameObject& wall);

//baron & Walls ---------------
void HorizontalWallBaronOfHell(GameObject& wall, GameObject& demon);
void BaronOfHellHorizontalWall(GameObject& demon, GameObject& wall);
void VerticalWallBaronOfHell(GameObject& wall, GameObject& demon);
void BaronOfHellVerticalWall(GameObject& demon, GameObject& wall);
void DiagonalWallRBaronOfHell(GameObject& wall, GameObject& demon);
void BaronOfHellDiagonalWallR(GameObject& demon, GameObject& wall);
void DiagonalWallLBaronOfHell(GameObject& wall, GameObject& demon);
void BaronOfHellDiagonalWallL(GameObject& demon, GameObject& wall);

//cacodemon & Walls ---------------
void HorizontalWallCacodemon(GameObject& wall, GameObject& demon);
void CacodemonHorizontalWall(GameObject& demon, GameObject& wall);
void VerticalWallCacodemon(GameObject& wall, GameObject& demon);
void CacodemonVerticalWall(GameObject& demon, GameObject& wall);
void DiagonalWallRCacodemon(GameObject& wall, GameObject& demon);
void CacodemonDiagonalWallR(GameObject& demon, GameObject& wall);
void DiagonalWallLCacodemon(GameObject& wall, GameObject& demon);
void CacodemonDiagonalWallL(GameObject& demon, GameObject& wall);

//Revenant & Walls ---------------
void HorizontalWallRevenant(GameObject& wall, GameObject& demon);
void RevenantHorizontalWall(GameObject& demon, GameObject& wall);
void VerticalWallRevenant(GameObject& wall, GameObject& demon);
void RevenantVerticalWall(GameObject& demon, GameObject& wall);
void DiagonalWallRRevenant(GameObject& wall, GameObject& demon);
void RevenantDiagonalWallR(GameObject& demon, GameObject& wall);
void DiagonalWallLRevenant(GameObject& wall, GameObject& demon);
void RevenantDiagonalWallL(GameObject& demon, GameObject& wall);

//HeavyWeaponDude & Walls ---------------
void HorizontalWallHeavyWeaponDude(GameObject& wall, GameObject& demon);
void HeavyWeaponDudeHorizontalWall(GameObject& demon, GameObject& wall);
void VerticalWallHeavyWeaponDude(GameObject& wall, GameObject& demon);
void HeavyWeaponDudeVerticalWall(GameObject& demon, GameObject& wall);
void DiagonalWallRHeavyWeaponDude(GameObject& wall, GameObject& demon);
void HeavyWeaponDudeDiagonalWallR(GameObject& demon, GameObject& wall);
void DiagonalWallLHeavyWeaponDude(GameObject& wall, GameObject& demon);
void HeavyWeaponDudeDiagonalWallL(GameObject& demon, GameObject& wall);

//CyberDemon & Walls ---------------
void HorizontalWallCyberDemon(GameObject& wall, GameObject& demon);
void CyberDemonHorizontalWall(GameObject& demon, GameObject& wall);
void VerticalWallCyberDemon(GameObject& wall, GameObject& demon);
void CyberDemonVerticalWall(GameObject& demon, GameObject& wall);
void DiagonalWallRCyberDemon(GameObject& wall, GameObject& demon);
void CyberDemonDiagonalWallR(GameObject& demon, GameObject& wall);
void DiagonalWallLCyberDemon(GameObject& wall, GameObject& demon);
void CyberDemonDiagonalWallL(GameObject& demon, GameObject& wall);

//Mancubus & Walls ---------------
void HorizontalWallMancubus(GameObject& wall, GameObject& demon);
void MancubusHorizontalWall(GameObject& demon, GameObject& wall);
void VerticalWallMancubus(GameObject& wall, GameObject& demon);
void MancubusVerticalWall(GameObject& demon, GameObject& wall);
void DiagonalWallRMancubus(GameObject& wall, GameObject& demon);
void MancubusDiagonalWallR(GameObject& demon, GameObject& wall);
void DiagonalWallLMancubus(GameObject& wall, GameObject& demon);
void MancubusDiagonalWallL(GameObject& demon, GameObject& wall);

//Pistol & Walls------------------
void HorizontalWallPistol(GameObject& wall, GameObject& shot);
void PistolHorizontalWall(GameObject& shot, GameObject& wall);
void VerticalWallPistol(GameObject& wall, GameObject& shot);
void PistolVerticalWall(GameObject& shot, GameObject& wall);
void DiagonalWallRPistol(GameObject& wall, GameObject& shot);
void PistolDiagonalWallR(GameObject& shot, GameObject& wall);
void DiagonalWallLPistol(GameObject& wall, GameObject& shot);
void PistolDiagonalWallL(GameObject& shot, GameObject& wall);

 //BFG9000 & Walls------------------
void HorizontalWallBFG9000(GameObject& wall, GameObject& shot);
void BFG9000HorizontalWall(GameObject& shot, GameObject& wall);
void VerticalWallBFG9000(GameObject& wall, GameObject& shot);
void BFG9000VerticalWall(GameObject& shot, GameObject& wall);
void DiagonalWallRBFG9000(GameObject& wall, GameObject& shot);
void BFG9000DiagonalWallR(GameObject& shot, GameObject& wall);
void DiagonalWallLBFG9000(GameObject& wall, GameObject& shot);
void BFG9000DiagonalWallL(GameObject& shot, GameObject& wall);

//ChainGun & Walls------------------
void HorizontalWallChainGun(GameObject& wall, GameObject& shot);
void ChainGunHorizontalWall(GameObject& shot, GameObject& wall);
void VerticalWallChainGun(GameObject& wall, GameObject& shot);
void ChainGunVerticalWall(GameObject& shot, GameObject& wall);
void DiagonalWallRChainGun(GameObject& wall, GameObject& shot);
void ChainGunDiagonalWallR(GameObject& shot, GameObject& wall);
void DiagonalWallLChainGun(GameObject& wall, GameObject& shot);
void ChainGunDiagonalWallL(GameObject& shot, GameObject& wall);

//ShotGun & Walls------------------
void HorizontalWallShotGun(GameObject& wall, GameObject& shot);
void ShotGunHorizontalWall(GameObject& shot, GameObject& wall);
void VerticalWallShotGun(GameObject& wall, GameObject& shot);
void ShotGunVerticalWall(GameObject& shot, GameObject& wall);
void DiagonalWallRShotGun(GameObject& wall, GameObject& shot);
void ShotGunDiagonalWallR(GameObject& shot, GameObject& wall);
void DiagonalWallLShotGun(GameObject& wall, GameObject& shot);
void ShotGunDiagonalWallL(GameObject& shot, GameObject& wall);
