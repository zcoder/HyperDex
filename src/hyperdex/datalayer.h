// Copyright (c) 2011, Cornell University
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of HyperDex nor the names of its contributors may be
//       used to endorse or promote products derived from this software without
//       specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef hyperdex_datalayer_h_
#define hyperdex_datalayer_h_

#define __STDC_LIMIT_MACROS

// C
#include <stdint.h>

// STL
#include <map>
#include <set>
#include <tr1/memory>
#include <vector>

// po6
#include <po6/threads/rwlock.h>

// e
#include <e/buffer.h>

// HyperDex
#include <hyperdex/entity.h>

namespace hyperdex
{

class datalayer
{
    public:
        struct regionid
        {
            regionid(uint32_t t, uint16_t s, uint8_t p, uint64_t m)
                : space(t), subspace(s), prefix(p), mask(m) {}
            regionid(const entity& e)
                : space(e.space), subspace(e.subspace), prefix(e.prefix), mask(e.mask) {}

            int compare(const regionid& other) const;

            bool operator < (const regionid& other) const
            { return compare(other) < 0; }
            bool operator == (const regionid& other) const
            { return compare(other) == 0; }
            bool operator != (const regionid& other) const
            { return compare(other) != 0; }

            const uint32_t space;
            const uint16_t subspace;
            const uint8_t prefix;
            const uint64_t mask;
        };

    public:
        datalayer();

    // Space operations.
    public:
        std::set<regionid> regions();
        void create(const regionid& ri, uint16_t numcolumns);
        void drop(const regionid& ri);

    // Key-Value store operations.
    public:
        bool get(const regionid& ri, const e::buffer& key, std::vector<e::buffer>* value);
        bool put(const regionid& ri, const e::buffer& key, const std::vector<e::buffer>& value);
        bool del(const regionid& ri, const e::buffer& key);

    private:
        datalayer(const datalayer&);

    private:
        datalayer& operator = (const datalayer&);
};

} // namespace hyperdex

#endif // hyperdex_datalayer_h_
