/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2018  yuribadz yuribadz@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef PROPERTIESSINGLETON_H
#define PROPERTIESSINGLETON_H


class PropertiesSingleton
{
    public:
        static PropertiesSingleton& getInstance()
        {
            static PropertiesSingleton    instance;
            return instance;
        }
    private:
        PropertiesSingleton() {}
    public:
        PropertiesSingleton(PropertiesSingleton const&) = delete;
        void operator=(PropertiesSingleton const&) = delete;
		
	bool mainwindowActive;
	bool actionTCPActive;
	bool actionTCPToggled;
	bool actionHTTPActive;
	bool actionHTTPToggled;
	bool createRadioButtonActive;
	bool createRadioButtonToggled;
	bool updateRadioButtonActive;
        bool updateRadioButtonToggled;
	bool deleteRadioButtonActive;
        bool deleteRadioButtonToggled;
	bool userNameLabelActive;
	bool firstNameLabelActive;
	bool lastNameLabelActive;
	bool phoneLabelActive;
	bool companyLabelActive;
	bool userNamelineEditActive;
	bool firstNamelineEditActive;
	bool lastNamelineEditActive;
	bool phonelineEditActive;
	bool companyLineEditActive;
	bool commitPushButtonActive;
};
#endif // PROPERTIESSINGLETON_H
