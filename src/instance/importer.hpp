/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/poll/timer.hpp>
#include <dci/sbs.hpp>
#include <dci/aup/catalog/object.hpp>
#include <dci/aup/storage.hpp>
#include <filesystem>

namespace dci::aup::instance
{
    class Importer
    {
    public:
        Importer();
        ~Importer();

        void setup(const std::filesystem::path& dir);
        void start();
        void stop();

    public:
        sbs::Signal<void> emitStart();
        sbs::Signal<void, impl::Catalog*, impl::Storage*> emitData();
        sbs::Signal<void> emitFinish();

    private:
        void onTicker();
        bool tryImport(const std::filesystem::path& path);

    private:
        std::filesystem::path   _dir;
        bool                    _started{false};

        poll::Timer             _ticker
        {
            std::chrono::seconds{1},
            true,
            [this](){ onTicker(); }
        };

        using SomeFound = std::map<std::filesystem::path /*_someFoundPath*/, std::chrono::steady_clock::time_point /*_someFoundMoment*/>;
        SomeFound _someFound;

    private:
        sbs::Wire<void>                                 _emitStart;
        sbs::Wire<void, impl::Catalog*, impl::Storage*> _emitData;
        sbs::Wire<void>                                 _emitFinish;
    };
}
