if(PARAVIEW_BUILD_QT_GUI)

  include_directories(${VTK_INCLUDE_DIRS})
  include_directories(${PARAVIEW_GUI_INCLUDE_DIRS})
  include(${QT_USE_FILE})

  set(srcs
    pqRemoteControl.cxx
    pqRemoteControlThread.cxx)

  QT4_WRAP_CPP(MOC_SRCS
    pqRemoteControl.h
    pqRemoteControlThread.h)

  QT4_WRAP_UI(UI_SRCS pqRemoteControl.ui)

  ADD_PARAVIEW_DOCK_WINDOW(
    OUTIFACES
    OUTSRCS
    CLASS_NAME pqRemoteControl
    DOCK_AREA Right)

  ADD_PARAVIEW_PLUGIN(MobileRemoteControl "1.0"
                      REQUIRED_ON_CLIENT
                      GUI_INTERFACES ${OUTIFACES}
                      GUI_SOURCES ${OUTSRCS} ${MOC_SRCS} ${UI_SRCS} ${srcs})

  target_link_libraries(MobileRemoteControl
                        LINK_PRIVATE pqApplicationComponents)
endif()
