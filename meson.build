project(
    'xenon', 'cpp',
    version : '0.00',
    default_options : [
        'cpp_std=c++17',
        'warning_level=3',
        'b_pie=false',
        'cpp_eh=none',
        'cpp_rtti=false'
    ]
)

kernel_sources = []
inc = include_directories('include', '.', 'external')

architecture = meson.get_cross_property('architecture')

subdir('arch/' + architecture)
subdir('kernel')

kernel_lib = static_library('kernel',
    kernel_sources,
    include_directories: inc,
    link_args : [ '-T' + meson.current_source_dir()/'arch/linker.ld' ],
)

xenon_bin = executable('xenon.elf',
    boot_sources,
    include_directories: inc,
    link_args : [ '-T' + meson.current_source_dir()/'arch/linker.ld' ],
    link_with: [arch_lib, kernel_lib]
)