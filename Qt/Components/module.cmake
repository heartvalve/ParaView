set (__depends)
if (PARAVIEW_ENABLE_PYTHON)
  set (__depends pqPython)
endif()

vtk_module(pqComponents
  GROUPS
    ParaViewQt
  DEPENDS
    pqCore
    ${__depends}
  PRIVATE_DEPENDS
    vtksys
  EXCLUDE_FROM_WRAPPING
  TEST_LABELS
    PARAVIEW
)
