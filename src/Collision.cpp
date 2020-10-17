#include "Collision.h"


//--------------------Constructor--------------------
Collision::Collision()
{
	// slayer & ammo---------
	m_collisionMap[Key(typeid(Slayer), typeid(PistolAmmo))] = &SlayerPistolAmmo;
	m_collisionMap[Key(typeid(PistolAmmo), typeid(Slayer))] = &PistolAmmoSlayer; 
	m_collisionMap[Key(typeid(Slayer), typeid(ShotGunAmmo))] = &SlayerShotgunAmmo;
	m_collisionMap[Key(typeid(ShotGunAmmo), typeid(Slayer))] = &ShotgunAmmoSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(ChainGunAmmo))] = &SlayerChainGunAmmo;
	m_collisionMap[Key(typeid(ChainGunAmmo), typeid(Slayer))] = &ChainGunAmmoSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(BFGAmmo))] = &SlayerBFGAmmo;
	m_collisionMap[Key(typeid(BFGAmmo), typeid(Slayer))] = &BFGAmmoSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(PlasmaRifleAmmo))] = &SlayerPlasmaRifleAmmo;
	m_collisionMap[Key(typeid(PlasmaRifleAmmo), typeid(Slayer))] = &PlasmaRifleAmmoSlayer;

	// slayer & health---------
	m_collisionMap[Key(typeid(Slayer), typeid(SmallHealth))] = &SlayerSmallHealth;
	m_collisionMap[Key(typeid(SmallHealth), typeid(Slayer))] = &SmallHealthSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(BigHealth))] = &SlayerBigHealth;
	m_collisionMap[Key(typeid(BigHealth), typeid(Slayer))] = &BigHealthSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(UltraHealth))] = &SlayerUltraHealth;
	m_collisionMap[Key(typeid(UltraHealth), typeid(Slayer))] = &UltraHealthSlayer;

	//--------------------
	m_collisionMap[Key(typeid(Slayer), typeid(Fire))] = &SlayerFire;//slayer & fire --------
	m_collisionMap[Key(typeid(Fire), typeid(Slayer))] = &FireSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(Armor))] = &SlayerArmor;//slayer & armor --------
	m_collisionMap[Key(typeid(Armor), typeid(Slayer))] = &ArmorSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(BFG9000))] = &SlayerBFG;//slayer & bfg --------
	m_collisionMap[Key(typeid(BFG9000), typeid(Slayer))] = &BFGSlayer;

	//------------------
	//Mancubus & weapons ---------------
	m_collisionMap[Key(typeid(ShotGun), typeid(Mancubus))] = &ShotGunMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(ShotGun))] = &MancubusShotGun;
	m_collisionMap[Key(typeid(ChainGun), typeid(Mancubus))] = &ChainGunMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(ChainGun))] = &MancubusChainGun;
	m_collisionMap[Key(typeid(Pistol), typeid(Mancubus))] = &PistolMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(Pistol))] = &MancubusPistol;
	m_collisionMap[Key(typeid(BFG9000), typeid(Mancubus))] = &BFGMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(BFG9000))] = &MancubusBFG;
	m_collisionMap[Key(typeid(PlasmaRifle), typeid(Mancubus))] = &PlasmaRifleMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(PlasmaRifle))] = &MancubusPlasmaRifle;
	//baron & weapons ---------------
	m_collisionMap[Key(typeid(ShotGun), typeid(BaronOfHell))] = &ShotGunBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(ShotGun))] = &BaronOfHellShotGun;
	m_collisionMap[Key(typeid(ChainGun), typeid(BaronOfHell))] = &ChainGunBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(ChainGun))] = &BaronOfHellChainGun;
	m_collisionMap[Key(typeid(Pistol), typeid(BaronOfHell))] = &PistolBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(Pistol))] = &BaronOfHellPistol;
	m_collisionMap[Key(typeid(BFG9000), typeid(BaronOfHell))] = &BFGBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(BFG9000))] = &BaronOfHellBFG;	
	m_collisionMap[Key(typeid(PlasmaRifle), typeid(BaronOfHell))] = &PlasmaRifleBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(PlasmaRifle))] = &BaronOfHellPlasmaRifle;
	//cacodemon & weapons ---------------
	m_collisionMap[Key(typeid(ShotGun), typeid(Cacodemon))] = &ShotGunCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(ShotGun))] = &CacodemonShotGun;
	m_collisionMap[Key(typeid(ChainGun), typeid(Cacodemon))] = &ChainGunCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(ChainGun))] = &CacodemonChainGun;
	m_collisionMap[Key(typeid(Pistol), typeid(Cacodemon))] = &PistolCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(Pistol))] = &CacodemonPistol;
	m_collisionMap[Key(typeid(BFG9000), typeid(Cacodemon))] = &BFGCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(BFG9000))] = &CacodemonBFG;
	m_collisionMap[Key(typeid(PlasmaRifle), typeid(Cacodemon))] = &PlasmaRifleCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(PlasmaRifle))] = &CacodemonPlasmaRifle;
	//Revenant & weapons ---------------
	m_collisionMap[Key(typeid(ShotGun), typeid(Revenant))] = &ShotGunRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(ShotGun))] = &RevenantShotGun;
	m_collisionMap[Key(typeid(ChainGun), typeid(Revenant))] = &ChainGunRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(ChainGun))] = &RevenantChainGun;
	m_collisionMap[Key(typeid(Pistol), typeid(Revenant))] = &PistolRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(Pistol))] = &RevenantPistol;
	m_collisionMap[Key(typeid(BFG9000), typeid(Revenant))] = &BFGRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(BFG9000))] = &RevenantBFG;
	m_collisionMap[Key(typeid(PlasmaRifle), typeid(Revenant))] = &PlasmaRifleRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(PlasmaRifle))] = &RevenantPlasmaRifle;
	//CyberDemon & weapons ---------------
	m_collisionMap[Key(typeid(ShotGun), typeid(CyberDemon))] = &ShotGunCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(ShotGun))] = &CyberDemonShotGun;
	m_collisionMap[Key(typeid(ChainGun), typeid(CyberDemon))] = &ChainGunCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(ChainGun))] = &CyberDemonChainGun;
	m_collisionMap[Key(typeid(Pistol), typeid(CyberDemon))] = &PistolCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(Pistol))] = &CyberDemonPistol;
	m_collisionMap[Key(typeid(BFG9000), typeid(CyberDemon))] = &BFGCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(BFG9000))] = &CyberDemonBFG;
	m_collisionMap[Key(typeid(PlasmaRifle), typeid(CyberDemon))] = &PlasmaRifleCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(PlasmaRifle))] = &CyberDemonPlasmaRifle;
	//HeavyWeaponDude & weapons ---------------
	m_collisionMap[Key(typeid(ShotGun), typeid(HeavyWeaponDude))] = &ShotGunHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(ShotGun))] = &HeavyWeaponDudeShotGun;
	m_collisionMap[Key(typeid(ChainGun), typeid(HeavyWeaponDude))] = &ChainGunHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(ChainGun))] = &HeavyWeaponDudeChainGun;
	m_collisionMap[Key(typeid(Pistol), typeid(HeavyWeaponDude))] = &PistolHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(Pistol))] = &HeavyWeaponDudePistol;
	m_collisionMap[Key(typeid(BFG9000), typeid(HeavyWeaponDude))] = &BFGHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(BFG9000))] = &HeavyWeaponDudeBFG;
	m_collisionMap[Key(typeid(PlasmaRifle), typeid(HeavyWeaponDude))] = &PlasmaRifleHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(PlasmaRifle))] = &HeavyWeaponDudePlasmaRifle;

	//-------------------------WALLS COLLISION-----------------------
	//Slayer & walls---------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(Slayer))] = &HorizontalWallSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(HorizontalWall))] = &SlayerHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(Slayer))] = &VerticalWallSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(VerticalWall))] = &SlayerVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(Slayer))] = &DiagonalWallRSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(DiagonalWallR))] = &SlayerDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(Slayer))] = &DiagonalWallLSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(DiagonalWallL))] = &SlayerDiagonalWallL;

	//baron & Walls ---------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(BaronOfHell))] = &HorizontalWallBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(HorizontalWall))] = &BaronOfHellHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(BaronOfHell))] = &VerticalWallBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(VerticalWall))] = &BaronOfHellVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(BaronOfHell))] = &DiagonalWallRBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(DiagonalWallR))] = &BaronOfHellDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(BaronOfHell))] = &DiagonalWallLBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(DiagonalWallL))] = &BaronOfHellDiagonalWallL;

	//cacodemon & Walls ---------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(Cacodemon))] = &HorizontalWallCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(HorizontalWall))] = &CacodemonHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(Cacodemon))] = &VerticalWallCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(VerticalWall))] = &CacodemonVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(Cacodemon))] = &DiagonalWallRCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(DiagonalWallR))] = &CacodemonDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(Cacodemon))] = &DiagonalWallLCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(DiagonalWallL))] = &CacodemonDiagonalWallL;

	//Revenant & Walls ---------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(Revenant))] = &HorizontalWallRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(HorizontalWall))] = &RevenantHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(Revenant))] = &VerticalWallRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(VerticalWall))] = &RevenantVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(Revenant))] = &DiagonalWallRRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(DiagonalWallR))] = &RevenantDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(Revenant))] = &DiagonalWallLRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(DiagonalWallL))] = &RevenantDiagonalWallL;
	//CyberDemon & Walls ---------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(CyberDemon))] = &HorizontalWallCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(HorizontalWall))] = &CyberDemonHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(CyberDemon))] = &VerticalWallCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(VerticalWall))] = &CyberDemonVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(CyberDemon))] = &DiagonalWallRCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(DiagonalWallR))] = &CyberDemonDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(CyberDemon))] = &DiagonalWallLCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(DiagonalWallL))] = &CyberDemonDiagonalWallL;

	//HeavyWeaponDude & Walls ---------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(HeavyWeaponDude))] = &HorizontalWallHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(HorizontalWall))] = &HeavyWeaponDudeHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(HeavyWeaponDude))] = &VerticalWallHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(VerticalWall))] = &HeavyWeaponDudeVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(HeavyWeaponDude))] = &DiagonalWallRHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(DiagonalWallR))] = &HeavyWeaponDudeDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(HeavyWeaponDude))] = &DiagonalWallLHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(DiagonalWallL))] = &HeavyWeaponDudeDiagonalWallL;


	//Mancubus & Walls ---------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(Mancubus))] = &HorizontalWallMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(HorizontalWall))] = &MancubusHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(Mancubus))] = &VerticalWallMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(VerticalWall))] = &MancubusVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(Mancubus))] = &DiagonalWallRMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(DiagonalWallR))] = &MancubusDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(Mancubus))] = &DiagonalWallLMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(DiagonalWallL))] = &MancubusDiagonalWallL;

	//Pistol & Walls------------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(Pistol))] = &HorizontalWallPistol;
	m_collisionMap[Key(typeid(Pistol), typeid(HorizontalWall))] = &PistolHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(Pistol))] = &VerticalWallPistol;
	m_collisionMap[Key(typeid(Pistol), typeid(VerticalWall))] = &PistolVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(Pistol))] = &DiagonalWallRPistol;
	m_collisionMap[Key(typeid(Pistol), typeid(DiagonalWallR))] = &PistolDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(Pistol))] = &DiagonalWallLPistol;
	m_collisionMap[Key(typeid(Pistol), typeid(DiagonalWallL))] = &PistolDiagonalWallL;
	//BFG9000 & Walls------------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(BFG9000))] = &HorizontalWallBFG9000;
	m_collisionMap[Key(typeid(BFG9000), typeid(HorizontalWall))] = &BFG9000HorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(BFG9000))] = &VerticalWallBFG9000;
	m_collisionMap[Key(typeid(BFG9000), typeid(VerticalWall))] = &BFG9000VerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(BFG9000))] = &DiagonalWallRBFG9000;
	m_collisionMap[Key(typeid(BFG9000), typeid(DiagonalWallR))] = &BFG9000DiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(BFG9000))] = &DiagonalWallLBFG9000;
	m_collisionMap[Key(typeid(BFG9000), typeid(DiagonalWallL))] = &BFG9000DiagonalWallL;
	//ChainGun & Walls------------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(ChainGun))] = &HorizontalWallChainGun;
	m_collisionMap[Key(typeid(ChainGun), typeid(HorizontalWall))] = &ChainGunHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(ChainGun))] = &VerticalWallChainGun;
	m_collisionMap[Key(typeid(ChainGun), typeid(VerticalWall))] = &ChainGunVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(ChainGun))] = &DiagonalWallRChainGun;
	m_collisionMap[Key(typeid(ChainGun), typeid(DiagonalWallR))] = &ChainGunDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(ChainGun))] = &DiagonalWallLChainGun;
	m_collisionMap[Key(typeid(ChainGun), typeid(DiagonalWallL))] = &ChainGunDiagonalWallL;

	//ShotGun & Walls------------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(ShotGun))] = &HorizontalWallShotGun;
	m_collisionMap[Key(typeid(ShotGun), typeid(HorizontalWall))] = &ShotGunHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(ShotGun))] = &VerticalWallShotGun;
	m_collisionMap[Key(typeid(ShotGun), typeid(VerticalWall))] = &ShotGunVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(ShotGun))] = &DiagonalWallRShotGun;
	m_collisionMap[Key(typeid(ShotGun), typeid(DiagonalWallR))] = &ShotGunDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(ShotGun))] = &DiagonalWallLShotGun;
	m_collisionMap[Key(typeid(ShotGun), typeid(DiagonalWallL))] = &ShotGunDiagonalWallL;

	///--------------------------------------------------------------------------

	//Slayer & Demons------------------
	m_collisionMap[Key(typeid(Slayer), typeid(CyberDemon))] = &SlayerCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(Slayer))] = &CyberDemonSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(HeavyWeaponDude))] = &SlayerHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(Slayer))] = &HeavyWeaponDudeSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(Cacodemon))] = &SlayerCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(Slayer))] = &CacodemonSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(Revenant))] = &SlayerRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(Slayer))] = &RevenantSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(BaronOfHell))] = &SlayerBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(Slayer))] = &BaronOfHellSlayer;	
	m_collisionMap[Key(typeid(Slayer), typeid(Mancubus))] = &SlayerMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(Slayer))] = &MancubusSlayer;
	//Slayer & EnemyShots------------------
	m_collisionMap[Key(typeid(MancubusShot), typeid(Slayer))] = &MancubusShotSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(MancubusShot))] = &SlayerMancubusShot;
	m_collisionMap[Key(typeid(CyberDemonShot), typeid(Slayer))] = &CyberDemonShotSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(CyberDemonShot))] = &SlayerCyberDemonShot;
	m_collisionMap[Key(typeid(HeavyWeaponDudeShot), typeid(Slayer))] = &HeavyWeaponDudeShotSlayer;
	m_collisionMap[Key(typeid(Slayer), typeid(HeavyWeaponDudeShot))] = &SlayerHeavyWeaponDudeShot;

	//Walls & EnemyShots------------------

	m_collisionMap[Key(typeid(HorizontalWall), typeid(MancubusShot))] = &HorizontalWallMancubusShot;
	m_collisionMap[Key(typeid(MancubusShot), typeid(HorizontalWall))] = &MancubusShotHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(MancubusShot))] = &VerticalWallMancubusShot;
	m_collisionMap[Key(typeid(MancubusShot), typeid(VerticalWall))] = &MancubusShotVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(MancubusShot))] = &DiagonalWallRMancubusShot;
	m_collisionMap[Key(typeid(MancubusShot), typeid(DiagonalWallR))] = &MancubusShotDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(MancubusShot))] = &DiagonalWallLMancubusShot;
	m_collisionMap[Key(typeid(MancubusShot), typeid(DiagonalWallL))] = &MancubusShotDiagonalWallL;
	//------------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(CyberDemonShot))] = &HorizontalWallCyberDemonShot;
	m_collisionMap[Key(typeid(CyberDemonShot), typeid(HorizontalWall))] = &CyberDemonShotHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(CyberDemonShot))] = &VerticalWallCyberDemonShot;
	m_collisionMap[Key(typeid(CyberDemonShot), typeid(VerticalWall))] = &CyberDemonShotVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(CyberDemonShot))] = &DiagonalWallRCyberDemonShot;
	m_collisionMap[Key(typeid(CyberDemonShot), typeid(DiagonalWallR))] = &CyberDemonShotDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(CyberDemonShot))] = &DiagonalWallLCyberDemonShot;
	m_collisionMap[Key(typeid(CyberDemonShot), typeid(DiagonalWallL))] = &CyberDemonShotDiagonalWallL;

	//------------------
	m_collisionMap[Key(typeid(HorizontalWall), typeid(HeavyWeaponDudeShot))] = &HorizontalWallHeavyWeaponDudeShot;
	m_collisionMap[Key(typeid(HeavyWeaponDudeShot), typeid(HorizontalWall))] = &HeavyWeaponDudeShotHorizontalWall;
	m_collisionMap[Key(typeid(VerticalWall), typeid(HeavyWeaponDudeShot))] = &VerticalWallHeavyWeaponDudeShot;
	m_collisionMap[Key(typeid(HeavyWeaponDudeShot), typeid(VerticalWall))] = &HeavyWeaponDudeShotVerticalWall;
	m_collisionMap[Key(typeid(DiagonalWallR), typeid(HeavyWeaponDudeShot))] = &DiagonalWallRHeavyWeaponDudeShot;
	m_collisionMap[Key(typeid(HeavyWeaponDudeShot), typeid(DiagonalWallR))] = &HeavyWeaponDudeShotDiagonalWallR;
	m_collisionMap[Key(typeid(DiagonalWallL), typeid(HeavyWeaponDudeShot))] = &DiagonalWallLHeavyWeaponDudeShot;
	m_collisionMap[Key(typeid(HeavyWeaponDudeShot), typeid(DiagonalWallL))] = &HeavyWeaponDudeShotDiagonalWallL;

	//------------------------Demons & Demons Collision------------------------

	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(Mancubus))] = &HeavyWeaponDudeMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(HeavyWeaponDude))] = &MancubusHeavyWeaponDude;
	m_collisionMap[Key(typeid(CyberDemon), typeid(Mancubus))] = &CyberDemonMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(CyberDemon))] = &MancubusCyberDemon;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(CyberDemon))] = &HeavyWeaponDudeCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(HeavyWeaponDude))] = &CyberDemonHeavyWeaponDude;
	m_collisionMap[Key(typeid(Cacodemon), typeid(CyberDemon))] = &CacodemonCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(Cacodemon))] = &CyberDemonCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(HeavyWeaponDude))] = &CacodemonHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(Cacodemon))] = &HeavyWeaponDudeCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(BaronOfHell))] = &CacodemonBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(Cacodemon))] = &BaronOfHellCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(Mancubus))] = &CacodemonMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(Cacodemon))] = &MancubusCacodemon;
	m_collisionMap[Key(typeid(Revenant), typeid(CyberDemon))] = &RevenantCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(Revenant))] = &CyberDemonRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(HeavyWeaponDude))] = &RevenantHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(Revenant))] = &HeavyWeaponDudeRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(Mancubus))] = &RevenantMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(Revenant))] = &MancubusRevenant;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(CyberDemon))] = &BaronOfHellCyberDemon;
	m_collisionMap[Key(typeid(CyberDemon), typeid(BaronOfHell))] = &CyberDemonBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(HeavyWeaponDude))] = &BaronOfHellHeavyWeaponDude;
	m_collisionMap[Key(typeid(HeavyWeaponDude), typeid(BaronOfHell))] = &HeavyWeaponDudeBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(Cacodemon))] = &BaronOfHellCacodemon;
	m_collisionMap[Key(typeid(Cacodemon), typeid(BaronOfHell))] = &CacodemonBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(Revenant))] = &BaronOfHellRevenant;
	m_collisionMap[Key(typeid(Revenant), typeid(BaronOfHell))] = &RevenantBaronOfHell;
	m_collisionMap[Key(typeid(Mancubus), typeid(BaronOfHell))] = &MancubusBaronOfHell;
	m_collisionMap[Key(typeid(BaronOfHell), typeid(Mancubus))] = &BaronOfHellMancubus;	
	
	//demon&himself----------
	m_collisionMap[Key(typeid(Mancubus), typeid(Mancubus))] = &MancubusMancubus;
	m_collisionMap[Key(typeid(Mancubus), typeid(Mancubus))] = &BaronOfHellBaronOfHell;	
	m_collisionMap[Key(typeid(Mancubus), typeid(Mancubus))] = &CyberDemonCyberDemon;
	m_collisionMap[Key(typeid(Mancubus), typeid(Mancubus))] = &CacodemonCacodemon;
	m_collisionMap[Key(typeid(Mancubus), typeid(Mancubus))] = &RevenantRevenant;
	m_collisionMap[Key(typeid(Mancubus), typeid(Mancubus))] = &HeavyWeaponDudeHeavyWeaponDude;

}

//--------------------Slayer&BFG collision--------------------
void BFGSlayer(GameObject& BFG, GameObject& slayer)
{
	BFG9000& bfg = static_cast<BFG9000&>(BFG);
	Slayer& slay = static_cast<Slayer&>(slayer);
	if (!slay.getIsDead())
	{
		if (bfg.getToExplode())
			slay.takeDamage(bfg.getWeaponDamage());

	}
}
void SlayerBFG(GameObject& slayer, GameObject& BFG)
{SlayerBFG(slayer, BFG);}

//--------------------Slayer&Armor collision--------------------
void SlayerArmor(GameObject& slayer, GameObject& armor)
{
	Slayer& slaye = static_cast<Slayer&>(slayer);
	Armor& armo = static_cast<Armor&>(armor);			
	if(slaye.pickArmor(armo.getArmor()))
	armo.setDelete();
}
void ArmorSlayer(GameObject& armor, GameObject& slayer)
{SlayerArmor(slayer, armor);}

//---------------Slayer&Ammo collision-------------------------
void SlayerPlasmaRifleAmmo(GameObject& slayer, GameObject& plasmaAmmo)
{
	Slayer& slaye = static_cast<Slayer&>(slayer);
	PlasmaRifleAmmo& ammo = static_cast<PlasmaRifleAmmo&>(plasmaAmmo);
	if (slaye.pickAmmo(PLASMA_RIFLE, ammo.getSizeOfMag()))
		ammo.setDelete();
}
void PlasmaRifleAmmoSlayer(GameObject& plasmaAmmo, GameObject& slayer)
{SlayerPlasmaRifleAmmo(slayer, plasmaAmmo);}

void SlayerPistolAmmo(GameObject& slayer, GameObject& pistolammo)
{
	Slayer& slaye = static_cast<Slayer&>(slayer);
	PistolAmmo& ammo = static_cast<PistolAmmo&>(pistolammo);		
	if (slaye.pickAmmo(PISTOL, ammo.getSizeOfMag()))
		ammo.setDelete();
}
void PistolAmmoSlayer(GameObject& pistolammo, GameObject& slayer)
{SlayerPistolAmmo(slayer, pistolammo);}
//----------------------------------------
void SlayerShotgunAmmo(GameObject& slayer, GameObject& shotgun)
{
	Slayer& slaye = static_cast<Slayer&>(slayer);
	ShotGunAmmo& ammo = static_cast<ShotGunAmmo&>(shotgun);		

	if (slaye.pickAmmo(SHOTGUN, ammo.getSizeOfMag()))
		ammo.setDelete();
}
void ShotgunAmmoSlayer(GameObject& shotgun, GameObject& slayer)
{SlayerShotgunAmmo(slayer, shotgun);}
//----------------------------------------
void SlayerChainGunAmmo(GameObject& slayer, GameObject& machinegun)
{
	Slayer& slaye = static_cast<Slayer&>(slayer);
	ChainGunAmmo& ammo = static_cast<ChainGunAmmo&>(machinegun);		

	if (slaye.pickAmmo(CHAIN_GUN, ammo.getSizeOfMag()))
		ammo.setDelete();
}
void ChainGunAmmoSlayer(GameObject& machinegun, GameObject& slayer)
{SlayerChainGunAmmo(slayer, machinegun);}
//----------------------------------------
void SlayerBFGAmmo(GameObject& slayer, GameObject& bfgAmmo)
{
	Slayer& slaye = static_cast<Slayer&>(slayer);
	BFGAmmo& ammo = static_cast<BFGAmmo&>(bfgAmmo);				

	if (slaye.pickAmmo(BFG, ammo.getSizeOfMag()))
		ammo.setDelete();
}
void BFGAmmoSlayer(GameObject& bfgAmmo, GameObject& slayer)
{SlayerBFGAmmo(slayer, bfgAmmo);}


//--------------------Slayer&HHealth collision--------------------
void SlayerSmallHealth(GameObject& slayer, GameObject& health)
{
	Slayer& slaye = static_cast<Slayer&>(slayer);
	SmallHealth& healt = static_cast<SmallHealth&>(health);
	if (slaye.pickHealth(healt.getHealth()))
		healt.setDelete();
}
void SmallHealthSlayer(GameObject& health, GameObject& slayer)
{SlayerSmallHealth(slayer, health);}

void SlayerBigHealth(GameObject& slayer, GameObject& health)
{
	Slayer& slaye = static_cast<Slayer&>(slayer);
	BigHealth& healt = static_cast<BigHealth&>(health);
	if (slaye.pickHealth(healt.getHealth()))
		healt.setDelete();
}
void BigHealthSlayer(GameObject& health, GameObject& slayer)
{SlayerBigHealth(slayer, health);}

void SlayerUltraHealth(GameObject& slayer, GameObject& health)
{
	Slayer& slaye = static_cast<Slayer&>(slayer);
	UltraHealth& healt = static_cast<UltraHealth&>(health);
	if (slaye.pickHealth(healt.getHealth()))
		healt.setDelete();
}
void UltraHealthSlayer(GameObject& health, GameObject& slayer)
{SlayerUltraHealth(slayer, health);}
//--------------------Slayer&Fire collision--------------------
void SlayerFire(GameObject& slayer, GameObject& fire)
{
	Slayer& slaye = static_cast<Slayer&>(slayer);
	Fire& fir = static_cast<Fire&>(fire);	
	if (slaye.getCanGetBurned())
	{
		slaye.takeDamage(fir.getDamage());
		slaye.setGetBurned();
	}
}
void FireSlayer(GameObject& fire, GameObject& slayer)
{SlayerFire(slayer, fire);}

//--------------------------------Mancubus & Weapons collision---------------------------------
void BFGMancubus(GameObject& BFG, GameObject& demon)
{
	BFG9000& bfg = static_cast<BFG9000&>(BFG);
	Mancubus& demo = static_cast<Mancubus&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		bfg.setToExplode();
		demo.takeDamage(bfg.getWeaponDamage());
	}
}
void MancubusBFG(GameObject& demon, GameObject& BFG)
{BFGMancubus(BFG, demon);}

void ShotGunMancubus(GameObject& Shotgun, GameObject& demon)
{
	ShotGun& Shotg = static_cast<ShotGun&>(Shotgun);
	Mancubus& demo = static_cast<Mancubus&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(Shotg.getWeaponDamage());
		Shotg.setDelete();
	}
}
void MancubusShotGun(GameObject& demon, GameObject& Shotgun)
{ShotGunMancubus(Shotgun, demon);}

void ChainGunMancubus(GameObject& Machinegun, GameObject& demon)
{
	ChainGun& machinegun = static_cast<ChainGun&>(Machinegun);
	Mancubus& demo = static_cast<Mancubus&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(machinegun.getWeaponDamage());
		machinegun.setDelete();
	}
}
void MancubusChainGun(GameObject& demon, GameObject& Machinegun)
{ChainGunMancubus(Machinegun, demon);}

void PistolMancubus(GameObject& pistol, GameObject& demon)
{
	Pistol& pisto = static_cast<Pistol&>(pistol);
	Mancubus& demo = static_cast<Mancubus&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(pisto.getWeaponDamage());
		pisto.setDelete();
	}
}
void MancubusPistol(GameObject& demon, GameObject& pistol)
{	PistolMancubus(pistol, demon);}

void PlasmaRifleMancubus(GameObject& plasma, GameObject& demon)
{
	Pistol& plas = static_cast<Pistol&>(plasma);
	Mancubus& demo = static_cast<Mancubus&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(plas.getWeaponDamage());
		plas.setDelete();
	}
}
void MancubusPlasmaRifle(GameObject& demon, GameObject& plasma)
{PlasmaRifleMancubus(plasma, demon);}

//--------------------------------BaronOfHell & Weapons collision---------------------------------
void BFGBaronOfHell(GameObject& BFG, GameObject& demon)
{
	BFG9000& bfg = static_cast<BFG9000&>(BFG);
	BaronOfHell& demo = static_cast<BaronOfHell&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		bfg.setToExplode();
		demo.takeDamage(bfg.getWeaponDamage());
	}
}
void BaronOfHellBFG(GameObject& demon, GameObject& BFG)
{BFGBaronOfHell(BFG, demon);}
//----------------------------------------
void ShotGunBaronOfHell(GameObject& Shotgun, GameObject& demon)
{
	ShotGun& Shotg = static_cast<ShotGun&>(Shotgun);
	BaronOfHell& demo = static_cast<BaronOfHell&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(Shotg.getWeaponDamage());
		Shotg.setDelete();
	}
}
void BaronOfHellShotGun(GameObject& demon, GameObject& Shotgun)
{ShotGunBaronOfHell(Shotgun, demon);}
//----------------------------------------
void ChainGunBaronOfHell(GameObject& Machinegun, GameObject& demon)
{
	ChainGun& machinegun = static_cast<ChainGun&>(Machinegun);
	BaronOfHell& demo = static_cast<BaronOfHell&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(machinegun.getWeaponDamage());
		machinegun.setDelete();
	}
}
void BaronOfHellChainGun(GameObject& demon, GameObject& Machinegun)
{ChainGunBaronOfHell(Machinegun, demon);}
//----------------------------------------

void PistolBaronOfHell(GameObject& pistol, GameObject& demon)
{
	Pistol& pisto = static_cast<Pistol&>(pistol);
	BaronOfHell& demo = static_cast<BaronOfHell&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(pisto.getWeaponDamage());
		pisto.setDelete();
	}
}
void BaronOfHellPistol(GameObject& demon, GameObject& pistol)
{PistolBaronOfHell(pistol, demon);}

void PlasmaRifleBaronOfHell(GameObject& plasma, GameObject& demon)
{
	Pistol& plas = static_cast<Pistol&>(plasma);
	BaronOfHell& demo = static_cast<BaronOfHell&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		demo.takeDamage(plas.getWeaponDamage());
		plas.setDelete();
	}
}
void BaronOfHellPlasmaRifle(GameObject& demon, GameObject& plasma)
{PlasmaRifleBaronOfHell(plasma, demon);}
//--------------------------------Revenant & Weapons collision---------------------------------
void BFGRevenant(GameObject& BFG, GameObject& demon)
{
	BFG9000& bfg = static_cast<BFG9000&>(BFG);
	Revenant& demo = static_cast<Revenant&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		bfg.setToExplode();
		demo.takeDamage(bfg.getWeaponDamage());
	}
}
void RevenantBFG(GameObject& demon, GameObject& BFG)
{BFGRevenant(BFG, demon);}
//----------------------------------------
void ShotGunRevenant(GameObject& Shotgun, GameObject& demon)
{
	ShotGun& Shotg = static_cast<ShotGun&>(Shotgun);
	Revenant& demo = static_cast<Revenant&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(Shotg.getWeaponDamage());
		Shotg.setDelete();
	}
}
void RevenantShotGun(GameObject& demon, GameObject& Shotgun)
{ShotGunRevenant(Shotgun, demon);}
//----------------------------------------
void ChainGunRevenant(GameObject& Machinegun, GameObject& demon)
{
	ChainGun& machinegun = static_cast<ChainGun&>(Machinegun);
	Revenant& demo = static_cast<Revenant&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(machinegun.getWeaponDamage());
		machinegun.setDelete();
	}
}
void RevenantChainGun(GameObject& demon, GameObject& Machinegun)
{ChainGunRevenant(Machinegun, demon);}
//----------------------------------------
void PistolRevenant(GameObject& pistol, GameObject& demon)
{
	Pistol& pisto = static_cast<Pistol&>(pistol);
	Revenant& demo = static_cast<Revenant&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(pisto.getWeaponDamage());
		pisto.setDelete();
	}
}
void RevenantPistol(GameObject& demon, GameObject& pistol)
{PistolRevenant(pistol, demon);}

void PlasmaRifleRevenant(GameObject& plasma, GameObject& demon)
{
	Pistol& plas = static_cast<Pistol&>(plasma);
	Revenant& demo = static_cast<Revenant&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		demo.takeDamage(plas.getWeaponDamage());
		plas.setDelete();
	}
}
void RevenantPlasmaRifle(GameObject& demon, GameObject& plasma)
{PlasmaRifleRevenant(plasma, demon);}
//--------------------------------CyberDemon & Weapons collision---------------------------------
void BFGCyberDemon(GameObject& BFG, GameObject& demon)
{
	BFG9000& bfg = static_cast<BFG9000&>(BFG);
	CyberDemon& demo = static_cast<CyberDemon&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		bfg.setToExplode();
		demo.takeDamage(bfg.getWeaponDamage());
	}
}
void CyberDemonBFG(GameObject& demon, GameObject& BFG)
{BFGCyberDemon(BFG, demon);}
//----------------------------------------
void ShotGunCyberDemon(GameObject& Shotgun, GameObject& demon)
{
	ShotGun& Shotg = static_cast<ShotGun&>(Shotgun);
	CyberDemon& demo = static_cast<CyberDemon&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(Shotg.getWeaponDamage());
		Shotg.setDelete();
	}
}
void CyberDemonShotGun(GameObject& demon, GameObject& Shotgun)
{ShotGunCyberDemon(Shotgun, demon);}
//----------------------------------------
void ChainGunCyberDemon(GameObject& Machinegun, GameObject& demon)
{
	ChainGun& machinegun = static_cast<ChainGun&>(Machinegun);
	CyberDemon& demo = static_cast<CyberDemon&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(machinegun.getWeaponDamage());
		machinegun.setDelete();
	}
}
void CyberDemonChainGun(GameObject& demon, GameObject& Machinegun)
{ChainGunCyberDemon(Machinegun, demon);}
//----------------------------------------
void PistolCyberDemon(GameObject& pistol, GameObject& demon)
{
	Pistol& pisto = static_cast<Pistol&>(pistol);
	CyberDemon& demo = static_cast<CyberDemon&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(pisto.getWeaponDamage());
		pisto.setDelete();
	}
}
void CyberDemonPistol(GameObject& demon, GameObject& pistol)
{PistolCyberDemon(pistol, demon);}

void PlasmaRifleCyberDemon(GameObject& plasma, GameObject& demon)
{
	Pistol& plas = static_cast<Pistol&>(plasma);
	CyberDemon& demo = static_cast<CyberDemon&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(plas.getWeaponDamage());
		plas.setDelete();
	}
}
void CyberDemonPlasmaRifle(GameObject& demon, GameObject& plasma)
{PlasmaRifleCyberDemon(plasma, demon);}
//--------------------------------HeavyWeaponDude & Weapons collision---------------------------------
void BFGHeavyWeaponDude(GameObject& BFG, GameObject& demon)
{
	BFG9000& bfg = static_cast<BFG9000&>(BFG);
	HeavyWeaponDude& demo = static_cast<HeavyWeaponDude&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		bfg.setToExplode();
		demo.takeDamage(bfg.getWeaponDamage());
	}
}
void HeavyWeaponDudeBFG(GameObject& demon, GameObject& BFG)
{BFGHeavyWeaponDude(BFG, demon);}
//----------------------------------------
void ShotGunHeavyWeaponDude(GameObject& Shotgun, GameObject& demon)
{
	ShotGun& Shotg = static_cast<ShotGun&>(Shotgun);
	HeavyWeaponDude& demo = static_cast<HeavyWeaponDude&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(Shotg.getWeaponDamage());
		Shotg.setDelete();
	}
}
void HeavyWeaponDudeShotGun(GameObject& demon, GameObject& Shotgun)
{ShotGunHeavyWeaponDude(Shotgun, demon);}
//----------------------------------------
void ChainGunHeavyWeaponDude(GameObject& Machinegun, GameObject& demon)
{
	ChainGun& machinegun = static_cast<ChainGun&>(Machinegun);
	HeavyWeaponDude& demo = static_cast<HeavyWeaponDude&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(machinegun.getWeaponDamage());
		machinegun.setDelete();
	}
}
void HeavyWeaponDudeChainGun(GameObject& demon, GameObject& Machinegun)
{ChainGunHeavyWeaponDude(Machinegun, demon);}
//----------------------------------------
void PistolHeavyWeaponDude(GameObject& pistol, GameObject& demon)
{
	Pistol& pisto = static_cast<Pistol&>(pistol);
	HeavyWeaponDude& demo = static_cast<HeavyWeaponDude&>(demon);
	if (!demo.getIsDead())
	{
		demo.takeDamage(pisto.getWeaponDamage());
		pisto.setDelete();
	}
}
void HeavyWeaponDudePistol(GameObject& demon, GameObject& pistol)
{PistolHeavyWeaponDude(pistol, demon);}

void PlasmaRifleHeavyWeaponDude(GameObject& plasma, GameObject& demon)
{
	Pistol& plas = static_cast<Pistol&>(plasma);
	HeavyWeaponDude& demo = static_cast<HeavyWeaponDude&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		demo.takeDamage(plas.getWeaponDamage());
		plas.setDelete();
	}
}
void HeavyWeaponDudePlasmaRifle(GameObject& demon, GameObject& plasma)
{PlasmaRifleHeavyWeaponDude(plasma, demon);}
//------------------------------------------------------------------------------------------------

//--------------------------------Cacodemon & Weapons collision---------------------------------

void BFGCacodemon(GameObject& BFG, GameObject& demon)
{
	BFG9000& bfg = static_cast<BFG9000&>(BFG);
	Cacodemon& demo = static_cast<Cacodemon&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		bfg.setToExplode();
		demo.takeDamage(bfg.getWeaponDamage());
	}
}
void CacodemonBFG(GameObject& demon, GameObject& BFG)
{BFGCacodemon(BFG, demon);}
//----------------------------------------
void ShotGunCacodemon(GameObject& Shotgun, GameObject& demon)
{
	ShotGun& Shotg = static_cast<ShotGun&>(Shotgun);
	Cacodemon& demo = static_cast<Cacodemon&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		demo.takeDamage(Shotg.getWeaponDamage());
		Shotg.setDelete();
	}
}
void CacodemonShotGun(GameObject& demon, GameObject& Shotgun)
{ShotGunCacodemon(Shotgun, demon);}
//----------------------------------------
void ChainGunCacodemon(GameObject& Machinegun, GameObject& demon)
{
	ChainGun& machinegun = static_cast<ChainGun&>(Machinegun);
	Cacodemon& demo = static_cast<Cacodemon&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		demo.takeDamage(machinegun.getWeaponDamage());
		machinegun.setDelete();
	}
}
void CacodemonChainGun(GameObject& demon, GameObject& Machinegun)
{ChainGunCacodemon(Machinegun, demon);}
//----------------------------------------
void PistolCacodemon(GameObject& pistol, GameObject& demon)
{
	Pistol& pisto = static_cast<Pistol&>(pistol);
	Cacodemon& demo = static_cast<Cacodemon&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		demo.takeDamage(pisto.getWeaponDamage());
		pisto.setDelete();
	}
}
void CacodemonPistol(GameObject& demon, GameObject& pistol)
{PistolCacodemon(pistol, demon);}

void PlasmaRifleCacodemon(GameObject& plasma, GameObject& demon)
{
	Pistol& plas = static_cast<Pistol&>(plasma);
	Cacodemon& demo = static_cast<Cacodemon&>(demon);
	if (!demo.getIsDead())
	{
		demo.stopObject();
		demo.takeDamage(plas.getWeaponDamage());
		plas.setDelete();
	}
}
void CacodemonPlasmaRifle(GameObject& demon, GameObject& plasma)
{PlasmaRifleCacodemon(plasma, demon);}

//------------------------------------------------------------------------------------------------
//--------------------Slayer&Demon Shots collision--------------------

void MancubusShotSlayer(GameObject& demon, GameObject& slayer)
{
	Slayer& slayerr = static_cast<Slayer&>(slayer);
	MancubusShot& dem = static_cast<MancubusShot&>(demon);
	if (!slayerr.getIsDead())
	{
		slayerr.takeDamage(dem.getWeaponDamage());
		dem.setToExplode();
	}
}
void SlayerMancubusShot(GameObject& slayer, GameObject& demon)
{MancubusShotSlayer(demon, slayer);}

void CyberDemonShotSlayer(GameObject& demon, GameObject& slayer)
{
	Slayer& slayerr = static_cast<Slayer&>(slayer);
	CyberDemonShot& dem = static_cast<CyberDemonShot&>(demon);
	if (!slayerr.getIsDead())
	{
		slayerr.takeDamage(dem.getWeaponDamage());
		dem.setToExplode();
	}
}
void SlayerCyberDemonShot(GameObject& slayer, GameObject& demon)
{CyberDemonShotSlayer(demon, slayer);}

void HeavyWeaponDudeShotSlayer(GameObject& demon, GameObject& slayer)
{
	Slayer& slayerr = static_cast<Slayer&>(slayer);
	HeavyWeaponDudeShot& dem = static_cast<HeavyWeaponDudeShot&>(demon);
	if (!slayerr.getIsDead())
	{
		slayerr.takeDamage(dem.getWeaponDamage());
		dem.setDelete();
	}
}
void SlayerHeavyWeaponDudeShot(GameObject& slayer, GameObject& demon)
{HeavyWeaponDudeShotSlayer(demon, slayer);}
//--------------------Slayer&Demons collision--------------------
void SlayerBaronOfHell(GameObject& slayer, GameObject& demon)
{
	Slayer& slayerr = static_cast<Slayer&>(slayer);
	BaronOfHell& dem = static_cast<BaronOfHell&>(demon);

	if (!dem.getIsDead())
	{
		if (!slayerr.getIsDead())
			dem.stopObject();

		if (dem.getCanHit() && (!slayerr.getIsDead()))
		{
			dem.playDemonActionSound(ATTACKING);
			dem.setIsAttacking(true);
			slayerr.takeDamage(dem.getDamage());
			dem.setCanHit(false);
		}
	}
}
//----------------------------------------
void BaronOfHellSlayer(GameObject& demon, GameObject& slayer)
{SlayerBaronOfHell(slayer, demon);}

void SlayerRevenant(GameObject& slayer, GameObject& demon)
{
	Slayer& slayerr = static_cast<Slayer&>(slayer);
	Revenant& dem = static_cast<Revenant&>(demon);
	if (!dem.getIsDead())
	{
		if (!slayerr.getIsDead())
			dem.stopObject();

		if (dem.getCanHit() && (!slayerr.getIsDead()))
		{
			dem.playDemonActionSound(ATTACKING);
			dem.setIsAttacking(true);
			slayerr.takeDamage(dem.getDamage());
			dem.setCanHit(false);
		}
	}
}
void RevenantSlayer(GameObject& demon, GameObject& slayer)
{SlayerRevenant(slayer, demon);}

void SlayerHeavyWeaponDude(GameObject& slayer, GameObject& demon)
{
	Slayer& slayerr = static_cast<Slayer&>(slayer);
	HeavyWeaponDude& dem = static_cast<HeavyWeaponDude&>(demon);

	if (!dem.getIsDead())
	{
	//	slayerr.stopObject();
	//	dem.stopObject();
	}
}
void HeavyWeaponDudeSlayer(GameObject& demon, GameObject& slayer) 
{SlayerHeavyWeaponDude(slayer, demon);}

void SlayerCacodemon(GameObject& slayer, GameObject& demon)
{
	Slayer& slayerr = static_cast<Slayer&>(slayer);
	Cacodemon& dem = static_cast<Cacodemon&>(demon);
	if (!dem.getIsDead())
	{
		if (!slayerr.getIsDead())
			dem.stopObject();

		if (dem.getCanHit() && (!slayerr.getIsDead()))
		{
			dem.playDemonActionSound(ATTACKING);
			dem.setIsAttacking(true);
			slayerr.takeDamage(dem.getDamage());
			dem.setCanHit(false);
		}

	}
}
void CacodemonSlayer(GameObject& demon, GameObject& slayer)
{SlayerCacodemon(slayer, demon);}

void SlayerCyberDemon(GameObject& slayer, GameObject& demon)
{
	Slayer& slayerr = static_cast<Slayer&>(slayer);
	CyberDemon& dem = static_cast<CyberDemon&>(demon);

	if (!dem.getIsDead())
	{
		slayerr.stopObject();
	//	dem.stopObject();
	}
}
void CyberDemonSlayer(GameObject& demon, GameObject& slayer)
{SlayerCyberDemon(slayer, demon);}

void SlayerMancubus(GameObject& slayer, GameObject& demon)
{
	Slayer& slayerr = static_cast<Slayer&>(slayer);
	Mancubus& dem = static_cast<Mancubus&>(demon);

	if (!dem.getIsDead())
	{
		//slayerr.stopObject();
		//dem.stopObject();
	}
}
void MancubusSlayer(GameObject& demon, GameObject& slayer)
{
	SlayerMancubus(slayer, demon);
}

//-------------------------WALLS COLLISION-----------------------
//Walls & EnemyShots------------------
void HorizontalWallHeavyWeaponDudeShot(GameObject& wall, GameObject& demon)
{
	HeavyWeaponDudeShot& shotr = static_cast<HeavyWeaponDudeShot&>(demon);
	shotr.setDelete();
}
void HeavyWeaponDudeShotHorizontalWall(GameObject& demon, GameObject& wall)
{HorizontalWallHeavyWeaponDudeShot(wall, demon);}

void VerticalWallHeavyWeaponDudeShot(GameObject& wall, GameObject& demon)
{HorizontalWallHeavyWeaponDudeShot(wall, demon); }
void HeavyWeaponDudeShotVerticalWall(GameObject& demon, GameObject& wall)
{VerticalWallHeavyWeaponDudeShot(wall, demon);}

void DiagonalWallRHeavyWeaponDudeShot(GameObject& wall, GameObject& demon)
{HorizontalWallHeavyWeaponDudeShot(wall, demon); }
void HeavyWeaponDudeShotDiagonalWallR(GameObject& demon, GameObject& wall)
{DiagonalWallRHeavyWeaponDudeShot(wall, demon);}

void DiagonalWallLHeavyWeaponDudeShot(GameObject& wall, GameObject& demon)
{HorizontalWallHeavyWeaponDudeShot(wall, demon); }
void HeavyWeaponDudeShotDiagonalWallL(GameObject& demon, GameObject& wall)
{DiagonalWallLHeavyWeaponDudeShot(wall, demon);}
//------------------
void HorizontalWallMancubusShot(GameObject& wall, GameObject& demon)
{
	MancubusShot& shotr = static_cast<MancubusShot&>(demon);
	shotr.setToExplode();
}
void MancubusShotHorizontalWall(GameObject& demon, GameObject& wall)
{HorizontalWallMancubusShot(wall, demon);}

void VerticalWallMancubusShot(GameObject& wall, GameObject& demon)
{HorizontalWallMancubusShot(wall, demon);}
void MancubusShotVerticalWall(GameObject& demon, GameObject& wall)
{VerticalWallMancubusShot(wall, demon);}

void DiagonalWallRMancubusShot(GameObject& wall, GameObject& demon)
{	HorizontalWallMancubusShot(wall, demon);}

void MancubusShotDiagonalWallR(GameObject& demon, GameObject& wall)
{DiagonalWallRMancubusShot(wall, demon);}

void DiagonalWallLMancubusShot(GameObject& wall, GameObject& demon)
{	HorizontalWallMancubusShot(wall, demon);}

void MancubusShotDiagonalWallL(GameObject& demon, GameObject& wall)
{DiagonalWallLMancubusShot(wall, demon);}
//------------------
void HorizontalWallCyberDemonShot(GameObject& wall, GameObject& demon)
{
	CyberDemonShot& shotr = static_cast<CyberDemonShot&>(demon);
	shotr.setToExplode();
}
void CyberDemonShotHorizontalWall(GameObject& demon, GameObject& wall)
{	HorizontalWallCyberDemonShot(wall, demon);}

void VerticalWallCyberDemonShot(GameObject& wall, GameObject& demon)
{	HorizontalWallCyberDemonShot(wall, demon); }
void CyberDemonShotVerticalWall(GameObject& demon, GameObject& wall)
{VerticalWallCyberDemonShot(wall, demon);}

void DiagonalWallRCyberDemonShot(GameObject& wall, GameObject& demon)
{HorizontalWallCyberDemonShot(wall, demon);}

void CyberDemonShotDiagonalWallR(GameObject& demon, GameObject& wall)
{DiagonalWallRCyberDemonShot(wall, demon);}

void DiagonalWallLCyberDemonShot(GameObject& wall, GameObject& demon)
{	HorizontalWallCyberDemonShot(wall, demon); }
void CyberDemonShotDiagonalWallL(GameObject& demon, GameObject& wall)
{DiagonalWallLCyberDemonShot(wall, demon);}

//Slayer & walls---------------
void HorizontalWallSlayer(GameObject& wall, GameObject& slayer)
{
	Slayer& slayerr = static_cast<Slayer&>(slayer);
	slayerr.stopObject();
}
void SlayerHorizontalWall(GameObject& slayer, GameObject& wall)
{HorizontalWallSlayer(wall, slayer);}

void VerticalWallSlayer(GameObject& wall, GameObject& slayer)
{HorizontalWallSlayer(wall, slayer);}

void SlayerVerticalWall(GameObject& slayer, GameObject& wall)
{VerticalWallSlayer(wall, slayer);}

void DiagonalWallRSlayer(GameObject& wall, GameObject& slayer)
{HorizontalWallSlayer(wall, slayer);}

void SlayerDiagonalWallR(GameObject& slayer, GameObject& wall)
{DiagonalWallRSlayer(wall, slayer);}

void DiagonalWallLSlayer(GameObject& wall, GameObject& slayer)
{HorizontalWallSlayer(wall, slayer);}

void SlayerDiagonalWallL(GameObject& slayer, GameObject& wall)
{DiagonalWallLSlayer(wall, slayer);}

//baron & Walls ---------------
void HorizontalWallBaronOfHell(GameObject& wall, GameObject& demon)
{
	BaronOfHell& demonr = static_cast<BaronOfHell&>(demon);
	demonr.stopObject();
	demonr.setRandMove();
}
void BaronOfHellHorizontalWall(GameObject& demon, GameObject& wall)
{	HorizontalWallBaronOfHell(wall, demon);}

void VerticalWallBaronOfHell(GameObject& wall, GameObject& demon)
{HorizontalWallBaronOfHell(wall, demon);}

void BaronOfHellVerticalWall(GameObject& demon, GameObject& wall)
{VerticalWallBaronOfHell(wall, demon);}

void DiagonalWallRBaronOfHell(GameObject& wall, GameObject& demon)
{HorizontalWallBaronOfHell(wall, demon);}

void BaronOfHellDiagonalWallR(GameObject& demon, GameObject& wall)
{DiagonalWallRBaronOfHell(wall, demon);}

void DiagonalWallLBaronOfHell(GameObject& wall, GameObject& demon)
{HorizontalWallBaronOfHell(wall, demon);}

void BaronOfHellDiagonalWallL(GameObject& demon, GameObject& wall)
{DiagonalWallLBaronOfHell(wall, demon);}

//cacodemon & Walls ---------------
void HorizontalWallCacodemon(GameObject& wall, GameObject& demon)
{
	Cacodemon& demonr = static_cast<Cacodemon&>(demon);
	demonr.stopObject();
	demonr.setRandMove();
}
void CacodemonHorizontalWall(GameObject& demon, GameObject& wall)
{HorizontalWallCacodemon(wall, demon);}

void VerticalWallCacodemon(GameObject& wall, GameObject& demon)
{HorizontalWallCacodemon(wall, demon);}

void CacodemonVerticalWall(GameObject& demon, GameObject& wall)
{VerticalWallCacodemon(wall, demon);}

void DiagonalWallRCacodemon(GameObject& wall, GameObject& demon)
{HorizontalWallCacodemon(wall, demon);}

void CacodemonDiagonalWallR(GameObject& demon, GameObject& wall)
{DiagonalWallRCacodemon(wall, demon);}

void DiagonalWallLCacodemon(GameObject& wall, GameObject& demon)
{HorizontalWallCacodemon(wall, demon);}

void CacodemonDiagonalWallL(GameObject& demon, GameObject& wall)
{DiagonalWallLCacodemon(wall, demon);}

//Revenant & Walls ---------------
void HorizontalWallRevenant(GameObject& wall, GameObject& demon)
{
	Revenant& demonr = static_cast<Revenant&>(demon);
	demonr.stopObject();
	demonr.setRandMove();
}
void RevenantHorizontalWall(GameObject& demon, GameObject& wall)
{HorizontalWallRevenant(wall, demon);}

void VerticalWallRevenant(GameObject& wall, GameObject& demon)
{HorizontalWallRevenant(wall, demon);}

void RevenantVerticalWall(GameObject& demon, GameObject& wall)
{VerticalWallRevenant(wall, demon);}

void DiagonalWallRRevenant(GameObject& wall, GameObject& demon)
{HorizontalWallRevenant(wall, demon);}

void RevenantDiagonalWallR(GameObject& demon, GameObject& wall)
{DiagonalWallRRevenant(wall, demon);}

void DiagonalWallLRevenant(GameObject& wall, GameObject& demon)
{HorizontalWallRevenant(wall, demon);}

void RevenantDiagonalWallL(GameObject& demon, GameObject& wall)
{DiagonalWallLRevenant(wall, demon);}

//CyberDemon & Walls ---------------

void HorizontalWallCyberDemon(GameObject& wall, GameObject& demon)
{
	CyberDemon& demonr = static_cast<CyberDemon&>(demon);
	demonr.stopObject();
	demonr.setRandMove();
}
void CyberDemonHorizontalWall(GameObject& demon, GameObject& wall)
{HorizontalWallCyberDemon(wall, demon);}

void VerticalWallCyberDemon(GameObject& wall, GameObject& demon)
{HorizontalWallCyberDemon(wall, demon);}

void CyberDemonVerticalWall(GameObject& demon, GameObject& wall)
{VerticalWallCyberDemon(wall, demon);}

void DiagonalWallRCyberDemon(GameObject& wall, GameObject& demon)
{HorizontalWallCyberDemon(wall, demon);}

void CyberDemonDiagonalWallR(GameObject& demon, GameObject& wall)
{DiagonalWallRCyberDemon(wall, demon);}

void DiagonalWallLCyberDemon(GameObject& wall, GameObject& demon)
{HorizontalWallCyberDemon(wall, demon);}

void CyberDemonDiagonalWallL(GameObject& demon, GameObject& wall)
{DiagonalWallLCyberDemon(wall, demon);}
//HeavyWeaponDude & Walls ---------------

void HorizontalWallHeavyWeaponDude(GameObject& wall, GameObject& demon)
{
	HeavyWeaponDude& demonr = static_cast<HeavyWeaponDude&>(demon);
	demonr.stopObject();
	demonr.setRandMove();
}
void HeavyWeaponDudeHorizontalWall(GameObject& demon, GameObject& wall)
{HorizontalWallHeavyWeaponDude(wall, demon);}

void VerticalWallHeavyWeaponDude(GameObject& wall, GameObject& demon)
{HorizontalWallHeavyWeaponDude(wall, demon);}

void HeavyWeaponDudeVerticalWall(GameObject& demon, GameObject& wall)
{VerticalWallHeavyWeaponDude(wall, demon);}

void DiagonalWallRHeavyWeaponDude(GameObject& wall, GameObject& demon)
{HorizontalWallHeavyWeaponDude(wall, demon);}

void HeavyWeaponDudeDiagonalWallR(GameObject& demon, GameObject& wall)
{DiagonalWallRHeavyWeaponDude(wall, demon);}

void DiagonalWallLHeavyWeaponDude(GameObject& wall, GameObject& demon)
{HorizontalWallHeavyWeaponDude(wall, demon);}

void HeavyWeaponDudeDiagonalWallL(GameObject& demon, GameObject& wall)
{DiagonalWallLHeavyWeaponDude(wall, demon);}

//Mancubus & Walls ---------------
void HorizontalWallMancubus(GameObject& wall, GameObject& demon)
{
	Mancubus& demonr = static_cast<Mancubus&>(demon);
	demonr.stopObject();
	demonr.setRandMove();
}
void MancubusHorizontalWall(GameObject& demon, GameObject& wall)
{HorizontalWallMancubus(wall, demon);}

void VerticalWallMancubus(GameObject& wall, GameObject& demon)
{HorizontalWallMancubus(wall, demon);}

void MancubusVerticalWall(GameObject& demon, GameObject& wall)
{VerticalWallMancubus(wall, demon);}

void DiagonalWallRMancubus(GameObject& wall, GameObject& demon)
{HorizontalWallMancubus(wall, demon);}

void MancubusDiagonalWallR(GameObject& demon, GameObject& wall)
{	DiagonalWallRMancubus(wall, demon);}

void DiagonalWallLMancubus(GameObject& wall, GameObject& demon)
{HorizontalWallMancubus(wall, demon);}

void MancubusDiagonalWallL(GameObject& demon, GameObject& wall)
{DiagonalWallLMancubus(wall, demon);}

//Pistol & Walls------------------
void HorizontalWallPistol(GameObject& wall, GameObject& shot)
{
	Pistol& shotr = static_cast<Pistol&>(shot);
	shotr.setDelete();
}
void PistolHorizontalWall(GameObject& shot, GameObject& wall)
{HorizontalWallPistol(wall, shot);}

void VerticalWallPistol(GameObject& wall, GameObject& shot)
{HorizontalWallPistol(wall, shot);}

void PistolVerticalWall(GameObject& shot, GameObject& wall)
{VerticalWallPistol(wall, shot);}

void DiagonalWallRPistol(GameObject& wall, GameObject& shot)
{HorizontalWallPistol(wall, shot);}

void PistolDiagonalWallR(GameObject& shot, GameObject& wall)
{DiagonalWallRPistol(wall, shot);}

void DiagonalWallLPistol(GameObject& wall, GameObject& shot)
{HorizontalWallPistol(wall, shot);}

void PistolDiagonalWallL(GameObject& shot, GameObject& wall)
{DiagonalWallLPistol(wall, shot);}




//BFG9000 & Walls------------------
void HorizontalWallBFG9000(GameObject& wall, GameObject& shot)
{
	BFG9000& shotr = static_cast<BFG9000&>(shot);
	shotr.setToExplode();
}
void BFG9000HorizontalWall(GameObject& shot, GameObject& wall)
{HorizontalWallBFG9000(wall, shot);}

void VerticalWallBFG9000(GameObject& wall, GameObject& shot)
{HorizontalWallBFG9000(wall, shot);}

void BFG9000VerticalWall(GameObject& shot, GameObject& wall)
{VerticalWallBFG9000(wall, shot);}

void DiagonalWallRBFG9000(GameObject& wall, GameObject& shot)
{HorizontalWallBFG9000(wall, shot);}

void BFG9000DiagonalWallR(GameObject& shot, GameObject& wall)
{DiagonalWallRBFG9000(wall, shot);}

void DiagonalWallLBFG9000(GameObject& wall, GameObject& shot)
{HorizontalWallBFG9000(wall, shot);}

void BFG9000DiagonalWallL(GameObject& shot, GameObject& wall)
{DiagonalWallLBFG9000(wall, shot);}

//ChainGun & Walls------------------
void HorizontalWallChainGun(GameObject& wall, GameObject& shot)
{
	ChainGun& shotr = static_cast<ChainGun&>(shot);
	shotr.setDelete();
}
void ChainGunHorizontalWall(GameObject& shot, GameObject& wall)
{HorizontalWallChainGun(wall, shot);}

void VerticalWallChainGun(GameObject& wall, GameObject& shot)
{HorizontalWallChainGun(wall, shot);}

void ChainGunVerticalWall(GameObject& shot, GameObject& wall)
{VerticalWallChainGun(wall, shot);}

void DiagonalWallRChainGun(GameObject& wall, GameObject& shot)
{HorizontalWallChainGun(wall, shot);}

void ChainGunDiagonalWallR(GameObject& shot, GameObject& wall)
{DiagonalWallRChainGun(wall, shot);}

void DiagonalWallLChainGun(GameObject& wall, GameObject& shot)
{HorizontalWallChainGun(wall, shot);}

void ChainGunDiagonalWallL(GameObject& shot, GameObject& wall)
{DiagonalWallLChainGun(wall, shot);}

//ShotGun & Walls------------------
void HorizontalWallShotGun(GameObject& wall, GameObject& shot)
{
	ShotGun& shotr = static_cast<ShotGun&>(shot);
	shotr.setDelete();
}
void ShotGunHorizontalWall(GameObject& shot, GameObject& wall)
{HorizontalWallShotGun(wall, shot);}

void VerticalWallShotGun(GameObject& wall, GameObject& shot)
{HorizontalWallShotGun(wall, shot);}

void ShotGunVerticalWall(GameObject& shot, GameObject& wall)
{VerticalWallShotGun(wall, shot);}

void DiagonalWallRShotGun(GameObject& wall, GameObject& shot)
{HorizontalWallShotGun(wall, shot);}

void ShotGunDiagonalWallR(GameObject& shot, GameObject& wall)
{DiagonalWallRShotGun(wall, shot);}

void DiagonalWallLShotGun(GameObject& wall, GameObject& shot)
{HorizontalWallShotGun(wall, shot);}

void ShotGunDiagonalWallL(GameObject& shot, GameObject& wall)
{DiagonalWallLShotGun(wall, shot);}

//---------demons & demons-------

//CyberDemon & demons---------------------
void CyberDemonBaronOfHell(GameObject& demon2, GameObject& demon)
{
	CyberDemon& dem1 = static_cast<CyberDemon&>(demon2);
	BaronOfHell& dem2 = static_cast<BaronOfHell&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem1.stopObject();
	}
}
void BaronOfHellCyberDemon(GameObject& demon, GameObject& demon2)
{CyberDemonBaronOfHell(demon2, demon);}

void CyberDemonHeavyWeaponDude(GameObject& demon2, GameObject& demon)
{
	CyberDemon& dem1 = static_cast<CyberDemon&>(demon2);
	HeavyWeaponDude& dem2 = static_cast<HeavyWeaponDude&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem1.stopObject();
	}
}

void HeavyWeaponDudeCyberDemon(GameObject& demon, GameObject& demon2)
{CyberDemonHeavyWeaponDude(demon2, demon);}

void CyberDemonRevenant(GameObject& demon2, GameObject& demon)
{
	CyberDemon& dem1 = static_cast<CyberDemon&>(demon2);
	Revenant& dem2 = static_cast<Revenant&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem1.stopObject();
	}
}
void RevenantCyberDemon(GameObject& demon, GameObject& demon2)
{CyberDemonRevenant(demon2, demon);}

void CyberDemonCacodemon(GameObject& demon2, GameObject& demon)
{
	CyberDemon& dem1 = static_cast<CyberDemon&>(demon2);
	Cacodemon& dem2 = static_cast<Cacodemon&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem1.stopObject();
	}
}
void CacodemonCyberDemon(GameObject& demon, GameObject& demon2)
{CyberDemonCacodemon(demon2, demon);}

void MancubusCyberDemon(GameObject& demon, GameObject& demon2)
{
	CyberDemon& dem1 = static_cast<CyberDemon&>(demon2);
	Mancubus& dem2 = static_cast<Mancubus&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		dem1.stopObject();
	}
}
void CyberDemonMancubus(GameObject& demon2, GameObject& demon)
{MancubusCyberDemon(demon2, demon);}

//HeavyWeaponDude & demons---------------------
void HeavyWeaponDudeBaronOfHell(GameObject& demon2, GameObject& demon)
{
	HeavyWeaponDude& dem1 = static_cast<HeavyWeaponDude&>(demon2);
	BaronOfHell& dem2 = static_cast<BaronOfHell&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem1.stopObject();
	}
}
void BaronOfHellHeavyWeaponDude(GameObject& demon, GameObject& demon2)
{HeavyWeaponDudeBaronOfHell(demon2, demon);}

void HeavyWeaponDudeRevenant(GameObject& demon2, GameObject& demon)
{
	HeavyWeaponDude& dem1 = static_cast<HeavyWeaponDude&>(demon2);
	Revenant& dem2 = static_cast<Revenant&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem1.stopObject();
	}
}
void RevenantHeavyWeaponDude(GameObject& demon, GameObject& demon2)
{HeavyWeaponDudeRevenant(demon2, demon);}

void HeavyWeaponDudeCacodemon(GameObject& demon2, GameObject& demon)
{
	HeavyWeaponDude& dem1 = static_cast<HeavyWeaponDude&>(demon2);
	Cacodemon& dem2 = static_cast<Cacodemon&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem1.stopObject();
	}
}
void CacodemonHeavyWeaponDude(GameObject& demon, GameObject& demon2)
{HeavyWeaponDudeCacodemon(demon2, demon);}

void MancubusHeavyWeaponDude(GameObject& demon, GameObject& demon2)			
{
}
void HeavyWeaponDudeMancubus(GameObject& demon2, GameObject& demon)
{MancubusHeavyWeaponDude(demon2, demon);}

//Cacodemon & demons---------------------
void CacodemonBaronOfHell(GameObject& demon2, GameObject& demon)
{
	Cacodemon& dem1 = static_cast<Cacodemon&>(demon2);
	BaronOfHell& dem2 = static_cast<BaronOfHell&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem2.stopObject();
	}
}
void BaronOfHellCacodemon(GameObject& demon, GameObject& demon2)	
{CacodemonBaronOfHell(demon2, demon);}

void CacodemonRevenant(GameObject& demon2, GameObject& demon)
{
	Cacodemon& dem1 = static_cast<Cacodemon&>(demon2);
	Revenant& dem2 = static_cast<Revenant&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		dem2.stopObject();
	}
}
void RevenantCacodemon(GameObject& demon, GameObject& demon2)
{CacodemonRevenant(demon2, demon);}


void MancubusCacodemon(GameObject& demon, GameObject& demon2)
{
	Cacodemon& dem1 = static_cast<Cacodemon&>(demon2);
	Mancubus& dem2 = static_cast<Mancubus&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem2.stopObject();
	}
}
void CacodemonMancubus(GameObject& demon2, GameObject& demon)
{MancubusCacodemon(demon2, demon);}

//Revenant & demons---------------------
void RevenantBaronOfHell(GameObject& demon2, GameObject& demon)
{
	Revenant& dem1 = static_cast<Revenant&>(demon2);
	BaronOfHell& dem2 = static_cast<BaronOfHell&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem1.stopObject();
	}
}
void BaronOfHellRevenant(GameObject& demon, GameObject& demon2)
{RevenantBaronOfHell(demon2, demon);}

void MancubusRevenant(GameObject& demon, GameObject& demon2)
{
	Mancubus& dem1 = static_cast<Mancubus&>(demon2);
	Revenant& dem2 = static_cast<Revenant&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
	//	dem1.stopObject();
	}
}
void RevenantMancubus(GameObject& demon2, GameObject& demon)
{MancubusRevenant(demon2, demon);}


void MancubusBaronOfHell(GameObject& demon, GameObject& demon2)
{
	Mancubus& dem1 = static_cast<Mancubus&>(demon2);
	BaronOfHell& dem2 = static_cast<BaronOfHell&>(demon);
	if (!dem1.getIsDead() && !dem2.getIsDead())
	{
		//dem1.stopObject();
	}
}
void BaronOfHellMancubus(GameObject& demon2, GameObject& demon)
{MancubusBaronOfHell(demon2, demon);}

//demons&themselvs
void MancubusMancubus(GameObject& demon2, GameObject& demon)
{
	Mancubus& dem1 = static_cast<Mancubus&>(demon2);
	dem1.stopObject();
}
void BaronOfHellBaronOfHell(GameObject& demon2, GameObject& demon)
{
	BaronOfHell& dem1 = static_cast<BaronOfHell&>(demon2);
	dem1.stopObject();
}
void CyberDemonCyberDemon(GameObject& demon2, GameObject& demon)
{
	CyberDemon& dem1 = static_cast<CyberDemon&>(demon2);
	dem1.stopObject();
}
void CacodemonCacodemon(GameObject& demon2, GameObject& demon)
{
	Cacodemon& dem1 = static_cast<Cacodemon&>(demon2);
	dem1.stopObject();
}
void RevenantRevenant(GameObject& demon2, GameObject& demon)
{
	Revenant& dem1 = static_cast<Revenant&>(demon2);
	dem1.stopObject();
}
void HeavyWeaponDudeHeavyWeaponDude(GameObject& demon2, GameObject& demon)
{
	HeavyWeaponDude& dem1 = static_cast<HeavyWeaponDude&>(demon2);
	dem1.stopObject();
}

//----------------------------------------
//--------------------instance func--------------------

Collision& Collision::instance()
{
	static Collision instance;
	return instance;
}
//----------------------------------------

//--------------------lookup func--------------------
//function to look for the pair of objects in the map
//function returns a pointer to the function if the right pair found
collisionFuncPtr Collision::lookup(const std::type_index& class1, const std::type_index& class2)     
{
	auto mapEntry = m_collisionMap.find(std::make_pair(class1, class2));

	if (mapEntry == m_collisionMap.end())
		return nullptr;

	return mapEntry->second;
}
//----------------------------------------
//--------------------handleCollision func--------------------
//function to check in the lookup function, than initiate if found
void Collision::handleCollision(GameObject& object1, GameObject& object2)  
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if(phf)
		phf(object1, object2);
}