/*	Copyright 2014 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_LOG_LOGGER_INC
#	define ENTROPY_LOG_LOGGER_INC

#	include "../Log.hh"

#	include <boost/log/sources/severity_channel_logger.hpp>

	namespace Entropy
	{
		namespace Log
		{
			class Logger :
				public boost::log::sources::severity_channel_logger_mt<Severity, std::string>
			{
				public:
					Logger();
					explicit Logger(const std::string &);
					explicit Logger(const Severity &);
					Logger(const std::string &, const Severity &);
					virtual ~Logger();
					Logger &operator << (const std::exception &);
			};
		}
	}

#endif
