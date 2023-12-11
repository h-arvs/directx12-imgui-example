#pragma once

#include "imgui.h"

#include <string>

typedef int ImGuiTooltipFlags;
namespace ImGui
{
    ImFont* FontFromSystem(std::string fontName, float fontSize);
    template<typename T, size_t SIZE>
    ImFont* FontFromArray(T(&data)[SIZE], float fontSize, const ImFontConfig* font_cfg_template = NULL, const ImWchar* glyph_ranges = NULL) {
        ImGuiIO& io = ImGui::GetIO();
        return io.Fonts->AddFontFromMemoryTTF(data, SIZE, fontSize, font_cfg_template, glyph_ranges);
    }
    ImGuiKey ImGui_ImplWin32_VirtualKeyToImGuiKey(uintptr_t wParam);

    void RenderCheckMarkAnimated(ImDrawList* draw_list, ImVec2 pos, ImU32 col, float sz, bool checked);
    bool ToggleAnimated(const char* label, bool* v);
    bool CheckboxAnimated(const char* label, bool* v);
    bool ButtonAnimatedEx(const char* label, const ImVec2& size_arg, ImGuiButtonFlags flags);
    bool ButtonAnimated(const char* label, const ImVec2& size = ImVec2(0, 0));
    bool BeginComboAnimated(const char* label, const char* preview_value, ImGuiComboFlags flags = 0);
    bool SliderScalarAnimated(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format = NULL, ImGuiSliderFlags flags = 0);
    bool SliderFloatAnimated(const char* label, float* v, float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
    bool SliderIntAnimated(const char* label, int* v, int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0);
    bool CollapsingHeaderAnimated(const char* label, ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_None);
    bool TreeNodeBehaviorAnimated(ImGuiID id, ImGuiTreeNodeFlags flags, const char* label, const char* label_end = NULL);
    void BeginTooltipThemedEx(ImGuiTooltipFlags tooltip_flags, ImGuiWindowFlags extra_window_flags);
    void EndTooltipThemed();
    void SetTooltipThemedV(const char* fmt, va_list args);
    void SetTooltipThemed(const char* fmt, ...);
    bool BeginThemed(const char* name, float blurValue = 0.0f, bool* p_open = nullptr, ImGuiWindowFlags flags = ImGuiWindowFlags_None);
    void EndThemed();
    bool ModuleButton(const char* label, bool toggled = false, float darkTheme = 0.0f, float blurValue = 0.0f, const ImVec2& size = ImVec2(0, 0), ImGuiButtonFlags flags = ImGuiButtonFlags_None);

    float easeOutQuart(float x);
    float easeInOutCubic(float x);
}
