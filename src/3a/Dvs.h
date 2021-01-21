/*
 * Copyright (C) 2017-2020 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <ia_dvs.h>
#include <ia_dvs_types.h>
#include <ia_isp_bxt.h>

#include <memory>
#include <vector>

#include "AiqSetting.h"
#include "CameraEvent.h"
#include "iutils/Errors.h"
#include "iutils/Thread.h"

namespace icamera {
class Dvs : public EventListener {
 public:
    explicit Dvs(int cameraId);
    ~Dvs();

    int configure(const std::vector<ConfigMode>& configMode);
    void handleEvent(EventData eventData);

 private:
    int mCameraId;
    TuningMode mTuningMode;

    // prevent copy constructor and assignment operator
    DISALLOW_COPY_AND_ASSIGN(Dvs);
};

} /* namespace icamera */
