/*
	------------------------------------------------------------------------------------
	LICENSE:
	------------------------------------------------------------------------------------
	This file is part of EVEmu: EVE Online Server Emulator
	Copyright 2006 - 2008 The EVEmu Team
	For the latest information visit http://evemu.mmoforge.org
	------------------------------------------------------------------------------------
	This program is free software; you can redistribute it and/or modify it under
	the terms of the GNU Lesser General Public License as published by the Free Software
	Foundation; either version 2 of the License, or (at your option) any later
	version.

	This program is distributed in the hope that it will be useful, but WITHOUT
	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
	FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with
	this program; if not, write to the Free Software Foundation, Inc., 59 Temple
	Place - Suite 330, Boston, MA 02111-1307, USA, or go to
	http://www.gnu.org/copyleft/lesser.txt.
	------------------------------------------------------------------------------------
	Author:		Zhur
*/


#ifndef __CORPORATIONDB_H_INCL__
#define __CORPORATIONDB_H_INCL__

#include "../ServiceDB.h"
#include <map>
#include "../common/PyRep.h"
#include "../../packets/CorporationPkts.h"
#include "../../packets/General.h"
#include "CorporationCarrier.h"

class PyRep;
class OfficeInfo;

class CorporationDB
: public ServiceDB {
public:
	CorporationDB(DBcore *db);
	virtual ~CorporationDB();

	PyRepObject *ListCorpStations(uint32 corp_id);

	PyRepObject *ListStationOffices(uint32 station_id);
	PyRepObject *ListStationCorps(uint32 station_id);
	PyRepObject *ListStationOwners(uint32 station_id);
	PyRepObject *GetEmploymentRecord(uint32 charID);
	PyRepObject *GetMedalsReceived(uint32 charID);
	
	PyRepDict *ListAllCorpInfo();
	bool ListAllCorpFactions(std::map<uint32, uint32> &into);
	bool ListAllFactionStationCounts(std::map<uint32, uint32> &into);
	bool ListAllFactionSystemCounts(std::map<uint32, uint32> &into);
	bool ListAllFactionRegions(std::map<uint32, PyRep *> &into);
	bool ListAllFactionConstellations(std::map<uint32, PyRep *> &into);
	bool ListAllFactionSolarSystems(std::map<uint32, PyRep *> &into);
	bool ListAllFactionRaces(std::map<uint32, PyRep *> &into);
	
	bool AddCorporation(Call_AddCorporation & corpInfo, uint32 charID, uint32 stationID, uint32 & corpID);
	bool JoinCorporation(uint32 charID, uint32 corpID, uint32 oldCorpID, const CorpMemberInfo &roles);
	bool CreateCorporationChangePacket(Notify_OnCorporaionChanged & cc, uint32 oldCorpID, uint32 newCorpID);
	bool CreateCorporationCreatePacket(Notify_OnCorporaionChanged & cc, uint32 oldCorpID, uint32 newCorpID);
	PyRepObject *GetCorporation(uint32 corpID);
	PyRepObject *GetEveOwners();
	bool StoreCharacterRoles(uint32 charID, const CorpMemberInfo &info);
	PyRepObject *GetStations(uint32 corpID);
	uint32 GetOffices(uint32 corpID);
	PyRep *Fetch(uint32 corpID, uint32 from, uint32 count);

	PyRepObject *ListNPCDivisions();
	uint32 GetQuoteForRentingAnOffice(uint32 corpID);
	uint32 ReserveOffice(const OfficeInfo & oInfo);

	uint32 GetStationOwner(uint32 stationID);
	uint32 GetStationCorporationCEO(uint32);
	uint32 GetCorporationCEO(uint32);

	PyRep *GetMyApplications(uint32 charID);
	bool InsertApplication(const ApplicationInfo & aInfo);
	PyRep *GetApplications(uint32 corpID);
	bool GetCurrentApplicationInfo(uint32 charID, uint32 corpID, ApplicationInfo &app);
	bool UpdateApplication(const ApplicationInfo &app);
	bool DeleteApplication(const ApplicationInfo &app);
	bool CreateMemberAttributeUpdate(MemberAttributeUpdate & attrib, uint32 newCorpID, uint32 charID);

	bool UpdateDivisionNames(uint32 corpID, const Call_UpdateDivisionNames & divs, PyRepDict * notif);
	bool UpdateCorporation(uint32 corpID, const Call_UpdateCorporation & upd, PyRepDict * notif);
	bool UpdateLogo(uint32 corpID, const Call_UpdateLogo & upd, PyRepDict * notif);

protected:
};





#endif

