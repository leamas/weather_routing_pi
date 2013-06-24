/***************************************************************************
 *
 * Project:  OpenCPN Weather Routing plugin
 * Author:   Sean D'Epagnier
 *
 ***************************************************************************
 *   Copyright (C) 2013 by Sean D'Epagnier                                 *
 *   sean@depagnier.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 */

#ifndef _BATCH_DIALOG_H_
#define _BATCH_DIALOG_H_

#include <wx/fileconf.h>

#include "WeatherRoutingUI.h"

struct RouteMapConfiguration;
class WeatherRouting;
class weather_routing_pi;
class ocpnDC;

struct BatchSource
{
    wxString name;
    double lat, lon;

    std::list<BatchSource*> destinations;
};

class ConfigurationBatchDialog : public ConfigurationBatchDialogBase
{
public:
    ConfigurationBatchDialog(WeatherRouting *parent);
    ~ConfigurationBatchDialog() {}

    void Render(ocpnDC &dc, PlugIn_ViewPort &vp);
    void AddSource(double lat, double lon);

protected:
    void RemoveSource( wxString name );

    void OnSources( wxCommandEvent& event );
    void OnDestinations( wxCommandEvent& event );
    void OnRemoveSource( wxCommandEvent& event );
    void OnConnect( wxCommandEvent& event );
    void OnAddBoat( wxCommandEvent& event );
    void OnRemoveBoat( wxCommandEvent& event );
    void OnReset( wxCommandEvent& event );
    void OnInformation( wxCommandEvent& event );
    void OnCancel( wxCommandEvent& event );
    void OnGenerate( wxCommandEvent& event );

    void Reset();

    wxString m_boatFileName;

    WeatherRouting &m_WeatherRouting;

    std::vector<BatchSource*> sources;
};

#endif
