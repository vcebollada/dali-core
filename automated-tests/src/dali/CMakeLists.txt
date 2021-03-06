SET(PKG_NAME "dali")

SET(EXEC_NAME "tct-${PKG_NAME}-core")
SET(RPM_NAME "core-${PKG_NAME}-tests")

SET(CAPI_LIB "dali")

SET(TC_SOURCES
        utc-Dali-Actor.cpp
        utc-Dali-AlphaFunction.cpp
        utc-Dali-AngleAxis.cpp
        utc-Dali-Animation.cpp
        utc-Dali-Any.cpp
        utc-Dali-BaseHandle.cpp
        utc-Dali-BufferImage.cpp
        utc-Dali-CameraActor.cpp
        utc-Dali-CircularQueue.cpp
        utc-Dali-ConditionalWait.cpp
        utc-Dali-ConnectionTracker.cpp
        utc-Dali-Constrainer.cpp
        utc-Dali-Constraint.cpp
        utc-Dali-ConstraintFunction.cpp
        utc-Dali-Constraints.cpp
        utc-Dali-ConstraintSource.cpp
        utc-Dali-Context.cpp
        utc-Dali-Core.cpp
        utc-Dali-CustomActor.cpp
        utc-Dali-Degree.cpp
        utc-Dali-DistanceField.cpp
        utc-Dali-EncodedBufferImage.cpp
        utc-Dali-Extents.cpp
        utc-Dali-FrameBuffer.cpp
        utc-Dali-FrameBufferImage.cpp
        utc-Dali-FrameCallbackInterface.cpp
        utc-Dali-Geometry.cpp
        utc-Dali-Gesture.cpp
        utc-Dali-GestureDetector.cpp
        utc-Dali-Handle.cpp
        utc-Dali-Hash.cpp
        utc-Dali-HitTestAlgorithm.cpp
        utc-Dali-HoverProcessing.cpp
        utc-Dali-Image.cpp
        utc-Dali-IntrusivePtr.cpp
        utc-Dali-KeyEvent.cpp
        utc-Dali-Layer.cpp
        utc-Dali-LocklessBuffer.cpp
        utc-Dali-LongPressGesture.cpp
        utc-Dali-LongPressGestureDetector.cpp
        utc-Dali-LongPressGestureRecognizer.cpp
        utc-Dali-MathUtils.cpp
        utc-Dali-Matrix.cpp
        utc-Dali-Matrix3.cpp
        utc-Dali-MeshMaterial.cpp
        utc-Dali-Mutex.cpp
        utc-Dali-NativeImage.cpp
        utc-Dali-NinePatchImages.cpp
        utc-Dali-ObjectRegistry.cpp
        utc-Dali-PanGesture.cpp
        utc-Dali-PanGestureDetector.cpp
        utc-Dali-PanGestureRecognizer.cpp
        utc-Dali-Path.cpp
        utc-Dali-PinchGesture.cpp
        utc-Dali-PinchGestureDetector.cpp
        utc-Dali-PinchGestureRecognizer.cpp
        utc-Dali-Pixel.cpp
        utc-Dali-PixelData.cpp
        utc-Dali-Processors.cpp
        utc-Dali-PropertyArray.cpp
        utc-Dali-PropertyBuffer.cpp
        utc-Dali-PropertyMap.cpp
        utc-Dali-PropertyNotification.cpp
        utc-Dali-PropertyTypes.cpp
        utc-Dali-PropertyValue.cpp
        utc-Dali-Quaternion.cpp
        utc-Dali-Radian.cpp
        utc-Dali-Random.cpp
        utc-Dali-Rect.cpp
        utc-Dali-Renderer.cpp
        utc-Dali-RenderTask.cpp
        utc-Dali-RenderTaskList.cpp
        utc-Dali-ResourceImage.cpp
        utc-Dali-RotationGesture.cpp
        utc-Dali-RotationGestureDetector.cpp
        utc-Dali-RotationGestureRecognizer.cpp
        utc-Dali-Sampler.cpp
        utc-Dali-Scene.cpp
        utc-Dali-Scripting.cpp
        utc-Dali-Shader.cpp
        utc-Dali-SignalDelegate.cpp
        utc-Dali-SignalTemplatesFunctors.cpp
        utc-Dali-SignalTemplates.cpp
        utc-Dali-SingletonService.cpp
        utc-Dali-Stage.cpp
        utc-Dali-TapGesture.cpp
        utc-Dali-TapGestureDetector.cpp
        utc-Dali-TapGestureRecognizer.cpp
        utc-Dali-Texture.cpp
        utc-Dali-TextureSet.cpp
        utc-Dali-Thread.cpp
        utc-Dali-ThreadPool.cpp
        utc-Dali-TouchEventCombiner.cpp
        utc-Dali-TouchProcessing.cpp
        utc-Dali-TouchDataProcessing.cpp
        utc-Dali-TypeRegistry.cpp
        utc-Dali-CSharp-TypeRegistry.cpp
        utc-Dali-Uint16Pair.cpp
        utc-Dali-Vector.cpp
        utc-Dali-Vector2.cpp
        utc-Dali-Vector3.cpp
        utc-Dali-Vector4.cpp
        utc-Dali-WeakHandle.cpp
        utc-Dali-WheelEvent.cpp
)

LIST(APPEND TC_SOURCES
        dali-test-suite-utils/mesh-builder.cpp
        dali-test-suite-utils/dali-test-suite-utils.cpp
        dali-test-suite-utils/test-actor-utils.cpp
        dali-test-suite-utils/test-custom-actor.cpp
        dali-test-suite-utils/test-harness.cpp
        dali-test-suite-utils/test-application.cpp
        dali-test-suite-utils/test-gesture-generator.cpp
        dali-test-suite-utils/test-gl-abstraction.cpp
        dali-test-suite-utils/test-gl-sync-abstraction.cpp
        dali-test-suite-utils/test-native-image.cpp
        dali-test-suite-utils/test-platform-abstraction.cpp
        dali-test-suite-utils/test-render-controller.cpp
        dali-test-suite-utils/test-trace-call-stack.cpp
)

PKG_CHECK_MODULES(${CAPI_LIB} REQUIRED
     dali2-core
)

ADD_COMPILE_OPTIONS( -O0 -ggdb --coverage -Wall -Werror )
ADD_COMPILE_OPTIONS( ${${CAPI_LIB}_CFLAGS_OTHER} )

FOREACH(directory ${${CAPI_LIB}_LIBRARY_DIRS})
    SET(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -L${directory}")
ENDFOREACH(directory ${CAPI_LIB_LIBRARY_DIRS})

INCLUDE_DIRECTORIES(
    ../../../
    ${${CAPI_LIB}_INCLUDE_DIRS}
    dali-test-suite-utils
)

ADD_EXECUTABLE(${EXEC_NAME} ${EXEC_NAME}.cpp ${TC_SOURCES})
TARGET_LINK_LIBRARIES(${EXEC_NAME}
    ${${CAPI_LIB}_LIBRARIES}
    -lpthread --coverage
)

INSTALL(PROGRAMS ${EXEC_NAME}
    DESTINATION ${BIN_DIR}/${EXEC_NAME}
)
