/*
 * Copyright (c) 2018 Particle Industries, Inc.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "dynalib.h"

#ifdef DYNALIB_EXPORT
#include "system_mesh.h"
#endif

DYNALIB_BEGIN(system_mesh)

DYNALIB_FN(0, system_mesh, mesh_set_device_role, int(int, int, unsigned, void*))
DYNALIB_FN(1, system_mesh, mesh_get_device_role, int(int*, int*, int*, void*))
DYNALIB_FN(2, system_mesh, mesh_get_network_info, int(mesh_network_info*, void*))

DYNALIB_END(system_mesh)