target_sources(proj PRIVATE
	"imgui.cpp"
	"imgui_demo.cpp"
	"imgui_draw.cpp"
	"imgui_impl_dx12.cpp"
	"imgui_impl_win32.cpp"
	"imgui_tables.cpp"
	"imgui_widgets.cpp"
)

target_include_directories(proj PRIVATE "${CMAKE_CURRENT_LIST_DIR}")