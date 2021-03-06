//
// NeighboursWithG2.h
//
// This file is part of Envy (getenvy.com) � 2016
// Portions copyright PeerProject 2008-2014 and Shareaza 2002-2007
//
// Envy is free software. You may redistribute and/or modify it
// under the terms of the GNU Affero General Public License
// as published by the Free Software Foundation (fsf.org);
// version 3 or later at your option. (AGPLv3)
//
// Envy is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Affero General Public License 3.0 for details:
// (http://www.gnu.org/licenses/agpl.html)
//

// Adds 2 methods helpful for Gnutella2 that look at the list of neighbours
// http://shareaza.sourceforge.net/mediawiki/index.php/Developers.Code.CNeighboursWithG2
// http://getenvy.com/shareazawiki/Developers.Code.CNeighboursWithG2.html

#pragma once

#include "NeighboursWithG1.h"

class CG2Neighbour;
class CG2Packet;

// Add methods helpful for Gnutella that need to look at the list of computers we're connected to
// Continue the inheritance column CNeighbours : CNeighboursWithConnect : Routing : ED2K : G2 : G1 : CNeighboursBase
class CNeighboursWithG2 : public CNeighboursWithG1
{
protected:
	// Constructor/destructor don't do anything
	CNeighboursWithG2();
	virtual ~CNeighboursWithG2();

public:
	// Methods implimented by several classes in the CNeighbours inheritance column
	// Set the ping route duration and setup the hub horizon pool
	virtual void Connect();

public:
	// Make and return a query web packet with IP addresses from the neighbours list and the Gnutella2 host cache
	CG2Packet* CreateQueryWeb(const Hashes::Guid& oGUID, bool bWithHubs, CNeighbour* pExcept = NULL, bool bDone = true);

	// Return a random Gnutella2 hub neighbour that isn't pExcept and doesn't know about pGUID
	CG2Neighbour* GetRandomHub(CG2Neighbour* pExcept, const Hashes::Guid& oGUID);
};
