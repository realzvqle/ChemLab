set_project("chemlab")

set_xmakever("2.6.0")

set_languages("c99")

target("chemlab")
    set_kind("binary")  
    add_files("src/*.c")
    add_files("src/**/*.c") 
    add_includedirs("src") 
    add_links("raylibdll", "raylib")

if is_os("windows") then
    add_linkdirs("lib") 
    add_syslinks("gdi32", "winmm") 
end