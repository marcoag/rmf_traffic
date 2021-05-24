/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef RMF_TRAFFIC__RESERVATIONS__INTERNAL_PARTICIPANTSTORE_HPP
#define RMF_TRAFFIC__RESERVATIONS__INTERNAL_PARTICIPANTSTORE_HPP

#include <rmf_traffic/reservations/Database.hpp>
#include <unordered_map>

namespace rmf_traffic {
namespace reservations {

class ParticipantStore
{
public:
  void add_participant(
    ParticipantId id,
    std::shared_ptr<Participant> participant
  )
  {
    _participants.insert_or_assign(
      id,
      participant
    );
  }

  void remove_participant(ParticipantId id)
  {
    auto participant = _participants.find(id);
    if(participant == _participants.end())
      return;
    _participants.erase(participant);
  }

  std::optional<std::shared_ptr<Participant>>
    get_participant(ParticipantId id)
  {
    auto participant = _participants.find(id);
    if(participant == _participants.end())
      return std::nullopt;
    return {participant->second};
  }
private:
  std::unordered_map<ParticipantId, std::shared_ptr<Participant>>
    _participants;
};

}
}
#endif