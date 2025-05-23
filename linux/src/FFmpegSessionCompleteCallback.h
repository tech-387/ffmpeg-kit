/*
 * Copyright (c) 2022 Taner Sener
 *
 * This file is part of FFmpegKit.
 *
 * FFmpegKit is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FFmpegKit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with FFmpegKit.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FFMPEG_KIT_FFMPEG_SESSION_COMPLETE_CALLBACK_H
#define FFMPEG_KIT_FFMPEG_SESSION_COMPLETE_CALLBACK_H

#include <functional>
#include <iostream>
#include <memory>

namespace ffmpegkit {

class FFmpegSession;

/**
 * <p>Callback function that is invoked when an asynchronous <code>FFmpeg</code>
 * session has ended. <p>Session has either SessionStateCompleted or
 * SessionStateFailed state when the callback is invoked. <p>If it has
 * SessionStateCompleted state, <code>ReturnCode</code> should be checked to see
 * the execution result. <p>If <code>getState</code> returns SessionStateFailed
 * then <code>getFailStackTrace</code> should be used to get the failure reason.
 * <pre>
 *  switch (session->getState()) {
 *      case SessionStateCompleted:
 *          auto returnCode = session->getReturnCode();
 *          break;
 *      case SessionStateFailed:
 *          auto failStackTrace = session->getFailStackTrace();
 *          break;
 *  }
 * </pre>
 *
 * @param session session of the completed execution
 */
typedef std::function<void(
    const std::shared_ptr<ffmpegkit::FFmpegSession> session)>
    FFmpegSessionCompleteCallback;

#include "FFmpegSession.h"

} // namespace ffmpegkit

#endif // FFMPEG_KIT_FFMPEG_SESSION_COMPLETE_CALLBACK_H
