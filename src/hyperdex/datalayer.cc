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

// C
#include <cassert>

// HyperDex
#include <hyperdex/datalayer.h>

using po6::threads::rwlock;
using std::tr1::shared_ptr;

int
hyperdex :: datalayer :: regionid :: compare (const regionid& rhs)
                                     const
{
    const regionid& lhs(*this);

    if (lhs.space < rhs.space)
    {
        return -1;
    }
    else if (lhs.space > rhs.space)
    {
        return 1;
    }

    if (lhs.subspace < rhs.subspace)
    {
        return -1;
    }
    else if (lhs.subspace > rhs.subspace)
    {
        return 1;
    }

    if (lhs.prefix < rhs.prefix)
    {
        return -1;
    }
    else if (lhs.prefix > rhs.prefix)
    {
        return 1;
    }

    return lhs.mask - rhs.mask;
}

hyperdex :: datalayer :: datalayer()
{
}

void
hyperdex :: datalayer :: create(const regionid& ri,
                                uint16_t numcolumns)
{
}

void
hyperdex :: datalayer :: drop(const regionid& ri)
{
}

bool
hyperdex :: datalayer :: get(const regionid& ri,
                             const e::buffer& key,
                             std::vector<e::buffer>* value)
{
    // XXX
    return false;
}

bool
hyperdex :: datalayer :: put(const regionid& ri,
                             const e::buffer& key,
                             const std::vector<e::buffer>& value)
{
    // XXX
    return false;
}

bool
hyperdex :: datalayer :: del(const regionid& ri,
                             const e::buffer& key)
{
    // XXX
    return false;
}
