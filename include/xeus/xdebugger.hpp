/***************************************************************************
* Copyright (c) 2016, Johan Mabille and Sylvain Corlay                     *
*                                                                          *
* Distributed under the terms of the BSD 3-Clause License.                 *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/

#ifndef XEUS_DEBUGGER_HPP
#define XEUS_DEBUGGER_HPP

#include "zmq.hpp"
#include "nlohmann/json.hpp"

#include "xeus.hpp"
#include "xkernel_configuration.hpp"

namespace nl = nlohmann;

namespace xeus
{
    class XEUS_API xdebugger
    {
    public:

        virtual ~xdebugger() = default;

        xdebugger(const xdebugger&) = delete;
        xdebugger& operator=(const xdebugger&) = delete;

        xdebugger(xdebugger&&) = delete;
        xdebugger& operator=(xdebugger&&) = delete;

        nl::json process_request(const nl::json& header,
                                 const nl::json& message);

    protected:

        xdebugger() = default;

    private:

        virtual nl::json process_request_impl(const nl::json& header,
                                              const nl::json& message) = 0;
    };

    XEUS_API
    std::unique_ptr<xdebugger> make_null_debugger(zmq::context_t& context,
                                                  const xconfiguration& kernel_configuration,
                                                  const std::string& user_name,
                                                  const std::string& session_id);
            
}

#endif

