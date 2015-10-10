/*
    This file is part of Android File Transfer For Linux.
    Copyright (C) 2015  Vladimir Menshakov

    Android File Transfer For Linux is free software: you can redistribute
    it and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    Android File Transfer For Linux is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Android File Transfer For Linux.
    If not, see <http://www.gnu.org/licenses/>.
 */

#include <cli/CommandLine.h>

#include <stdio.h>

namespace cli
{
	CommandLine::CommandLine()
	{ }

	CommandLine & CommandLine::Get()
	{
		static CommandLine cmd;
		return cmd;
	}

	bool CommandLine::ReadLine(const std::string &prompt, std::string &input)
	{
		char buf[1024];
		fputs(prompt.c_str(), stdout);
		fflush(stdout);
		char *line = fgets(buf, sizeof(buf), stdin);
		if (!line)
			return false;

		input.assign(line);
		return true;
	}

	std::string CommandLine::GetLineBuffer() const
	{ return std::string(); }
}
