/*
 * Copyright 2012-2014 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// C++ standard includes

// Falltergeist includes
#include "../../Game/CritterObject.h"
#include "../../Logger.h"
#include "../../VM/Handlers/Opcode8145Handler.h"
#include "../../VM/VM.h"


// Third party includes

namespace Falltergeist
{

Opcode8145Handler::Opcode8145Handler(VM* vm) : OpcodeHandler(vm)
{
}

void Opcode8145Handler::_run()
{
    Logger::debug("SCRIPT") << "[8145] [=] void use_obj_on_obj(void* item, void* target)" << std::endl;
    auto selfCritter = dynamic_cast<Game::CritterObject*>(_vm->owner());
    if (!selfCritter)
    {
        _error("use_obj_on_obj: owner is not a critter!");
    }
    auto target = _vm->dataStack()->popObject();
    if (!target)
    {
        _error("use_obj_on_obj: target is null");
    }
    auto item = _vm->dataStack()->popObject();
    if (!item)
    {
        _error("use_obj_on_obj: item is null");
    }
    // @TODO: play animation
    //selfCritter->setActionAnimation("al");
    target->use_obj_on_p_proc(item, selfCritter);
    
}

}

