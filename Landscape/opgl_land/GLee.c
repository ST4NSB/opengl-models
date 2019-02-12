

#ifdef _MSC_VER
	#pragma optimize( "g", off )
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GLee.h"

#if defined(__APPLE__) || defined(__APPLE_CC__)
	#include <Carbon/Carbon.h>
#endif

typedef GLuint(*GLEE_LINK_FUNCTION)(void);

GLboolean __GLeeInited=GL_FALSE;

#ifndef _WIN32
	#define __stdcall  /* nothing */
#endif 

void * __GLeeGetProcAddress(const char *extname)
{
#ifdef WIN32
	return (void*)wglGetProcAddress(extname);
#elif defined(__APPLE__) || defined(__APPLE_CC__)
    CFBundleRef bundle;
    CFURLRef bundleURL = CFURLCreateWithFileSystemPath(kCFAllocatorDefault, CFSTR("/System/Library/Frameworks/OpenGL.framework"), kCFURLPOSIXPathStyle, true);

    CFStringRef functionName = CFStringCreateWithCString(kCFAllocatorDefault, extname, kCFStringEncodingASCII);

    void *function;

    bundle = CFBundleCreate(kCFAllocatorDefault, bundleURL);
    assert(bundle != NULL);

    function = CFBundleGetFunctionPointerForName(bundle, functionName);

    CFRelease(bundleURL);
    CFRelease(functionName);
    CFRelease(bundle);

    return function;
#else
	return (void*)glXGetProcAddressARB((const GLubyte *)extname);
#endif
}




/* Extension querying variables */

GLboolean _GLEE_VERSION_1_2 = GL_FALSE;
GLboolean _GLEE_ARB_imaging = GL_FALSE;
GLboolean _GLEE_VERSION_1_3 = GL_FALSE;
GLboolean _GLEE_VERSION_1_4 = GL_FALSE;
GLboolean _GLEE_VERSION_1_5 = GL_FALSE;
GLboolean _GLEE_VERSION_2_0 = GL_FALSE;
GLboolean _GLEE_VERSION_2_1 = GL_FALSE;
GLboolean _GLEE_ARB_multitexture = GL_FALSE;
GLboolean _GLEE_ARB_transpose_matrix = GL_FALSE;
GLboolean _GLEE_ARB_multisample = GL_FALSE;
GLboolean _GLEE_ARB_texture_env_add = GL_FALSE;
GLboolean _GLEE_ARB_texture_cube_map = GL_FALSE;
GLboolean _GLEE_ARB_texture_compression = GL_FALSE;
GLboolean _GLEE_ARB_texture_border_clamp = GL_FALSE;
GLboolean _GLEE_ARB_point_parameters = GL_FALSE;
GLboolean _GLEE_ARB_vertex_blend = GL_FALSE;
GLboolean _GLEE_ARB_matrix_palette = GL_FALSE;
GLboolean _GLEE_ARB_texture_env_combine = GL_FALSE;
GLboolean _GLEE_ARB_texture_env_crossbar = GL_FALSE;
GLboolean _GLEE_ARB_texture_env_dot3 = GL_FALSE;
GLboolean _GLEE_ARB_texture_mirrored_repeat = GL_FALSE;
GLboolean _GLEE_ARB_depth_texture = GL_FALSE;
GLboolean _GLEE_ARB_shadow = GL_FALSE;
GLboolean _GLEE_ARB_shadow_ambient = GL_FALSE;
GLboolean _GLEE_ARB_window_pos = GL_FALSE;
GLboolean _GLEE_ARB_vertex_program = GL_FALSE;
GLboolean _GLEE_ARB_fragment_program = GL_FALSE;
GLboolean _GLEE_ARB_vertex_buffer_object = GL_FALSE;
GLboolean _GLEE_ARB_occlusion_query = GL_FALSE;
GLboolean _GLEE_ARB_shader_objects = GL_FALSE;
GLboolean _GLEE_ARB_vertex_shader = GL_FALSE;
GLboolean _GLEE_ARB_fragment_shader = GL_FALSE;
GLboolean _GLEE_ARB_shading_language_100 = GL_FALSE;
GLboolean _GLEE_ARB_texture_non_power_of_two = GL_FALSE;
GLboolean _GLEE_ARB_point_sprite = GL_FALSE;
GLboolean _GLEE_ARB_fragment_program_shadow = GL_FALSE;
GLboolean _GLEE_ARB_draw_buffers = GL_FALSE;
GLboolean _GLEE_ARB_texture_rectangle = GL_FALSE;
GLboolean _GLEE_ARB_color_buffer_float = GL_FALSE;
GLboolean _GLEE_ARB_half_float_pixel = GL_FALSE;
GLboolean _GLEE_ARB_texture_float = GL_FALSE;
GLboolean _GLEE_ARB_pixel_buffer_object = GL_FALSE;
GLboolean _GLEE_EXT_abgr = GL_FALSE;
GLboolean _GLEE_EXT_blend_color = GL_FALSE;
GLboolean _GLEE_EXT_polygon_offset = GL_FALSE;
GLboolean _GLEE_EXT_texture = GL_FALSE;
GLboolean _GLEE_EXT_texture3D = GL_FALSE;
GLboolean _GLEE_SGIS_texture_filter4 = GL_FALSE;
GLboolean _GLEE_EXT_subtexture = GL_FALSE;
GLboolean _GLEE_EXT_copy_texture = GL_FALSE;
GLboolean _GLEE_EXT_histogram = GL_FALSE;
GLboolean _GLEE_EXT_convolution = GL_FALSE;
GLboolean _GLEE_SGI_color_matrix = GL_FALSE;
GLboolean _GLEE_SGI_color_table = GL_FALSE;
GLboolean _GLEE_SGIS_pixel_texture = GL_FALSE;
GLboolean _GLEE_SGIX_pixel_texture = GL_FALSE;
GLboolean _GLEE_SGIS_texture4D = GL_FALSE;
GLboolean _GLEE_SGI_texture_color_table = GL_FALSE;
GLboolean _GLEE_EXT_cmyka = GL_FALSE;
GLboolean _GLEE_EXT_texture_object = GL_FALSE;
GLboolean _GLEE_SGIS_detail_texture = GL_FALSE;
GLboolean _GLEE_SGIS_sharpen_texture = GL_FALSE;
GLboolean _GLEE_EXT_packed_pixels = GL_FALSE;
GLboolean _GLEE_SGIS_texture_lod = GL_FALSE;
GLboolean _GLEE_SGIS_multisample = GL_FALSE;
GLboolean _GLEE_EXT_rescale_normal = GL_FALSE;
GLboolean _GLEE_EXT_vertex_array = GL_FALSE;
GLboolean _GLEE_EXT_misc_attribute = GL_FALSE;
GLboolean _GLEE_SGIS_generate_mipmap = GL_FALSE;
GLboolean _GLEE_SGIX_clipmap = GL_FALSE;
GLboolean _GLEE_SGIX_shadow = GL_FALSE;
GLboolean _GLEE_SGIS_texture_edge_clamp = GL_FALSE;
GLboolean _GLEE_SGIS_texture_border_clamp = GL_FALSE;
GLboolean _GLEE_EXT_blend_minmax = GL_FALSE;
GLboolean _GLEE_EXT_blend_subtract = GL_FALSE;
GLboolean _GLEE_EXT_blend_logic_op = GL_FALSE;
GLboolean _GLEE_SGIX_interlace = GL_FALSE;
GLboolean _GLEE_SGIX_pixel_tiles = GL_FALSE;
GLboolean _GLEE_SGIS_texture_select = GL_FALSE;
GLboolean _GLEE_SGIX_sprite = GL_FALSE;
GLboolean _GLEE_SGIX_texture_multi_buffer = GL_FALSE;
GLboolean _GLEE_EXT_point_parameters = GL_FALSE;
GLboolean _GLEE_SGIS_point_parameters = GL_FALSE;
GLboolean _GLEE_SGIX_instruments = GL_FALSE;
GLboolean _GLEE_SGIX_texture_scale_bias = GL_FALSE;
GLboolean _GLEE_SGIX_framezoom = GL_FALSE;
GLboolean _GLEE_SGIX_tag_sample_buffer = GL_FALSE;
GLboolean _GLEE_FfdMaskSGIX = GL_FALSE;
GLboolean _GLEE_SGIX_polynomial_ffd = GL_FALSE;
GLboolean _GLEE_SGIX_reference_plane = GL_FALSE;
GLboolean _GLEE_SGIX_flush_raster = GL_FALSE;
GLboolean _GLEE_SGIX_depth_texture = GL_FALSE;
GLboolean _GLEE_SGIS_fog_function = GL_FALSE;
GLboolean _GLEE_SGIX_fog_offset = GL_FALSE;
GLboolean _GLEE_HP_image_transform = GL_FALSE;
GLboolean _GLEE_HP_convolution_border_modes = GL_FALSE;
GLboolean _GLEE_INGR_palette_buffer = GL_FALSE;
GLboolean _GLEE_SGIX_texture_add_env = GL_FALSE;
GLboolean _GLEE_EXT_color_subtable = GL_FALSE;
GLboolean _GLEE_PGI_vertex_hints = GL_FALSE;
GLboolean _GLEE_PGI_misc_hints = GL_FALSE;
GLboolean _GLEE_EXT_paletted_texture = GL_FALSE;
GLboolean _GLEE_EXT_clip_volume_hint = GL_FALSE;
GLboolean _GLEE_SGIX_list_priority = GL_FALSE;
GLboolean _GLEE_SGIX_ir_instrument1 = GL_FALSE;
GLboolean _GLEE_SGIX_calligraphic_fragment = GL_FALSE;
GLboolean _GLEE_SGIX_texture_lod_bias = GL_FALSE;
GLboolean _GLEE_SGIX_shadow_ambient = GL_FALSE;
GLboolean _GLEE_EXT_index_texture = GL_FALSE;
GLboolean _GLEE_EXT_index_material = GL_FALSE;
GLboolean _GLEE_EXT_index_func = GL_FALSE;
GLboolean _GLEE_EXT_index_array_formats = GL_FALSE;
GLboolean _GLEE_EXT_compiled_vertex_array = GL_FALSE;
GLboolean _GLEE_EXT_cull_vertex = GL_FALSE;
GLboolean _GLEE_SGIX_ycrcb = GL_FALSE;
GLboolean _GLEE_SGIX_fragment_lighting = GL_FALSE;
GLboolean _GLEE_IBM_rasterpos_clip = GL_FALSE;
GLboolean _GLEE_HP_texture_lighting = GL_FALSE;
GLboolean _GLEE_EXT_draw_range_elements = GL_FALSE;
GLboolean _GLEE_WIN_phong_shading = GL_FALSE;
GLboolean _GLEE_WIN_specular_fog = GL_FALSE;
GLboolean _GLEE_EXT_light_texture = GL_FALSE;
GLboolean _GLEE_SGIX_blend_alpha_minmax = GL_FALSE;
GLboolean _GLEE_SGIX_impact_pixel_texture = GL_FALSE;
GLboolean _GLEE_EXT_bgra = GL_FALSE;
GLboolean _GLEE_SGIX_async = GL_FALSE;
GLboolean _GLEE_SGIX_async_pixel = GL_FALSE;
GLboolean _GLEE_SGIX_async_histogram = GL_FALSE;
GLboolean _GLEE_INTEL_texture_scissor = GL_FALSE;
GLboolean _GLEE_INTEL_parallel_arrays = GL_FALSE;
GLboolean _GLEE_HP_occlusion_test = GL_FALSE;
GLboolean _GLEE_EXT_pixel_transform = GL_FALSE;
GLboolean _GLEE_EXT_pixel_transform_color_table = GL_FALSE;
GLboolean _GLEE_EXT_shared_texture_palette = GL_FALSE;
GLboolean _GLEE_EXT_separate_specular_color = GL_FALSE;
GLboolean _GLEE_EXT_secondary_color = GL_FALSE;
GLboolean _GLEE_EXT_texture_perturb_normal = GL_FALSE;
GLboolean _GLEE_EXT_multi_draw_arrays = GL_FALSE;
GLboolean _GLEE_EXT_fog_coord = GL_FALSE;
GLboolean _GLEE_REND_screen_coordinates = GL_FALSE;
GLboolean _GLEE_EXT_coordinate_frame = GL_FALSE;
GLboolean _GLEE_EXT_texture_env_combine = GL_FALSE;
GLboolean _GLEE_APPLE_specular_vector = GL_FALSE;
GLboolean _GLEE_APPLE_transform_hint = GL_FALSE;
GLboolean _GLEE_SGIX_fog_scale = GL_FALSE;
GLboolean _GLEE_SUNX_constant_data = GL_FALSE;
GLboolean _GLEE_SUN_global_alpha = GL_FALSE;
GLboolean _GLEE_SUN_triangle_list = GL_FALSE;
GLboolean _GLEE_SUN_vertex = GL_FALSE;
GLboolean _GLEE_EXT_blend_func_separate = GL_FALSE;
GLboolean _GLEE_INGR_color_clamp = GL_FALSE;
GLboolean _GLEE_INGR_interlace_read = GL_FALSE;
GLboolean _GLEE_EXT_stencil_wrap = GL_FALSE;
GLboolean _GLEE_EXT_422_pixels = GL_FALSE;
GLboolean _GLEE_NV_texgen_reflection = GL_FALSE;
GLboolean _GLEE_EXT_texture_cube_map = GL_FALSE;
GLboolean _GLEE_SUN_convolution_border_modes = GL_FALSE;
GLboolean _GLEE_EXT_texture_env_add = GL_FALSE;
GLboolean _GLEE_EXT_texture_lod_bias = GL_FALSE;
GLboolean _GLEE_EXT_texture_filter_anisotropic = GL_FALSE;
GLboolean _GLEE_EXT_vertex_weighting = GL_FALSE;
GLboolean _GLEE_NV_light_max_exponent = GL_FALSE;
GLboolean _GLEE_NV_vertex_array_range = GL_FALSE;
GLboolean _GLEE_NV_register_combiners = GL_FALSE;
GLboolean _GLEE_NV_fog_distance = GL_FALSE;
GLboolean _GLEE_NV_texgen_emboss = GL_FALSE;
GLboolean _GLEE_NV_blend_square = GL_FALSE;
GLboolean _GLEE_NV_texture_env_combine4 = GL_FALSE;
GLboolean _GLEE_MESA_resize_buffers = GL_FALSE;
GLboolean _GLEE_MESA_window_pos = GL_FALSE;
GLboolean _GLEE_EXT_texture_compression_s3tc = GL_FALSE;
GLboolean _GLEE_IBM_cull_vertex = GL_FALSE;
GLboolean _GLEE_IBM_multimode_draw_arrays = GL_FALSE;
GLboolean _GLEE_IBM_vertex_array_lists = GL_FALSE;
GLboolean _GLEE_SGIX_subsample = GL_FALSE;
GLboolean _GLEE_SGIX_ycrcb_subsample = GL_FALSE;
GLboolean _GLEE_SGIX_ycrcba = GL_FALSE;
GLboolean _GLEE_SGI_depth_pass_instrument = GL_FALSE;
GLboolean _GLEE_3DFX_texture_compression_FXT1 = GL_FALSE;
GLboolean _GLEE_3DFX_multisample = GL_FALSE;
GLboolean _GLEE_3DFX_tbuffer = GL_FALSE;
GLboolean _GLEE_EXT_multisample = GL_FALSE;
GLboolean _GLEE_SGIX_vertex_preclip = GL_FALSE;
GLboolean _GLEE_SGIX_convolution_accuracy = GL_FALSE;
GLboolean _GLEE_SGIX_resample = GL_FALSE;
GLboolean _GLEE_SGIS_point_line_texgen = GL_FALSE;
GLboolean _GLEE_SGIS_texture_color_mask = GL_FALSE;
GLboolean _GLEE_EXT_texture_env_dot3 = GL_FALSE;
GLboolean _GLEE_ATI_texture_mirror_once = GL_FALSE;
GLboolean _GLEE_NV_fence = GL_FALSE;
GLboolean _GLEE_IBM_texture_mirrored_repeat = GL_FALSE;
GLboolean _GLEE_NV_evaluators = GL_FALSE;
GLboolean _GLEE_NV_packed_depth_stencil = GL_FALSE;
GLboolean _GLEE_NV_register_combiners2 = GL_FALSE;
GLboolean _GLEE_NV_texture_compression_vtc = GL_FALSE;
GLboolean _GLEE_NV_texture_rectangle = GL_FALSE;
GLboolean _GLEE_NV_texture_shader = GL_FALSE;
GLboolean _GLEE_NV_texture_shader2 = GL_FALSE;
GLboolean _GLEE_NV_vertex_array_range2 = GL_FALSE;
GLboolean _GLEE_NV_vertex_program = GL_FALSE;
GLboolean _GLEE_SGIX_texture_coordinate_clamp = GL_FALSE;
GLboolean _GLEE_SGIX_scalebias_hint = GL_FALSE;
GLboolean _GLEE_OML_interlace = GL_FALSE;
GLboolean _GLEE_OML_subsample = GL_FALSE;
GLboolean _GLEE_OML_resample = GL_FALSE;
GLboolean _GLEE_NV_copy_depth_to_color = GL_FALSE;
GLboolean _GLEE_ATI_envmap_bumpmap = GL_FALSE;
GLboolean _GLEE_ATI_fragment_shader = GL_FALSE;
GLboolean _GLEE_ATI_pn_triangles = GL_FALSE;
GLboolean _GLEE_ATI_vertex_array_object = GL_FALSE;
GLboolean _GLEE_EXT_vertex_shader = GL_FALSE;
GLboolean _GLEE_ATI_vertex_streams = GL_FALSE;
GLboolean _GLEE_ATI_element_array = GL_FALSE;
GLboolean _GLEE_SUN_mesh_array = GL_FALSE;
GLboolean _GLEE_SUN_slice_accum = GL_FALSE;
GLboolean _GLEE_NV_multisample_filter_hint = GL_FALSE;
GLboolean _GLEE_NV_depth_clamp = GL_FALSE;
GLboolean _GLEE_NV_occlusion_query = GL_FALSE;
GLboolean _GLEE_NV_point_sprite = GL_FALSE;
GLboolean _GLEE_NV_texture_shader3 = GL_FALSE;
GLboolean _GLEE_NV_vertex_program1_1 = GL_FALSE;
GLboolean _GLEE_EXT_shadow_funcs = GL_FALSE;
GLboolean _GLEE_EXT_stencil_two_side = GL_FALSE;
GLboolean _GLEE_ATI_text_fragment_shader = GL_FALSE;
GLboolean _GLEE_APPLE_client_storage = GL_FALSE;
GLboolean _GLEE_APPLE_element_array = GL_FALSE;
GLboolean _GLEE_APPLE_fence = GL_FALSE;
GLboolean _GLEE_APPLE_vertex_array_object = GL_FALSE;
GLboolean _GLEE_APPLE_vertex_array_range = GL_FALSE;
GLboolean _GLEE_APPLE_ycbcr_422 = GL_FALSE;
GLboolean _GLEE_S3_s3tc = GL_FALSE;
GLboolean _GLEE_ATI_draw_buffers = GL_FALSE;
GLboolean _GLEE_ATI_pixel_format_float = GL_FALSE;
GLboolean _GLEE_ATI_texture_env_combine3 = GL_FALSE;
GLboolean _GLEE_ATI_texture_float = GL_FALSE;
GLboolean _GLEE_NV_float_buffer = GL_FALSE;
GLboolean _GLEE_NV_fragment_program = GL_FALSE;
GLboolean _GLEE_NV_half_float = GL_FALSE;
GLboolean _GLEE_NV_pixel_data_range = GL_FALSE;
GLboolean _GLEE_NV_primitive_restart = GL_FALSE;
GLboolean _GLEE_NV_texture_expand_normal = GL_FALSE;
GLboolean _GLEE_NV_vertex_program2 = GL_FALSE;
GLboolean _GLEE_ATI_map_object_buffer = GL_FALSE;
GLboolean _GLEE_ATI_separate_stencil = GL_FALSE;
GLboolean _GLEE_ATI_vertex_attrib_array_object = GL_FALSE;
GLboolean _GLEE_OES_read_format = GL_FALSE;
GLboolean _GLEE_EXT_depth_bounds_test = GL_FALSE;
GLboolean _GLEE_EXT_texture_mirror_clamp = GL_FALSE;
GLboolean _GLEE_EXT_blend_equation_separate = GL_FALSE;
GLboolean _GLEE_MESA_pack_invert = GL_FALSE;
GLboolean _GLEE_MESA_ycbcr_texture = GL_FALSE;
GLboolean _GLEE_EXT_pixel_buffer_object = GL_FALSE;
GLboolean _GLEE_NV_fragment_program_option = GL_FALSE;
GLboolean _GLEE_NV_fragment_program2 = GL_FALSE;
GLboolean _GLEE_NV_vertex_program2_option = GL_FALSE;
GLboolean _GLEE_NV_vertex_program3 = GL_FALSE;
GLboolean _GLEE_EXT_framebuffer_object = GL_FALSE;
GLboolean _GLEE_GREMEDY_string_marker = GL_FALSE;
GLboolean _GLEE_EXT_Cg_shader = GL_FALSE;
GLboolean _GLEE_EXT_timer_query = GL_FALSE;
GLboolean _GLEE_EXT_texture_buffer_object = GL_FALSE;
GLboolean _GLEE_EXT_gpu_shader4 = GL_FALSE;
GLboolean _GLEE_EXT_geometry_shader4 = GL_FALSE;
GLboolean _GLEE_EXT_bindable_uniform = GL_FALSE;
GLboolean _GLEE_EXT_framebuffer_sRGB = GL_FALSE;
GLboolean _GLEE_EXT_texture_shared_exponent = GL_FALSE;
GLboolean _GLEE_EXT_packed_float = GL_FALSE;
GLboolean _GLEE_EXT_texture_array = GL_FALSE;
GLboolean _GLEE_EXT_texture_integer = GL_FALSE;
GLboolean _GLEE_NV_depth_buffer_float = GL_FALSE;
GLboolean _GLEE_EXT_texture_compression_latc = GL_FALSE;
GLboolean _GLEE_NV_transform_feedback = GL_FALSE;
GLboolean _GLEE_NV_geometry_program4 = GL_FALSE;
GLboolean _GLEE_NV_gpu_program4 = GL_FALSE;
GLboolean _GLEE_NV_framebuffer_multisample_coverage = GL_FALSE;
GLboolean _GLEE_EXT_framebuffer_multisample = GL_FALSE;
GLboolean _GLEE_EXT_framebuffer_blit = GL_FALSE;
GLboolean _GLEE_EXT_texture_compression_rgtc = GL_FALSE;
GLboolean _GLEE_EXT_color_matrix = GL_FALSE;
GLboolean _GLEE_SGIX_texture_select = GL_FALSE;
GLboolean _GLEE_INGR_blend_func_separate = GL_FALSE;
GLboolean _GLEE_SGIX_depth_pass_instrument = GL_FALSE;
GLboolean _GLEE_SGIX_igloo_interface = GL_FALSE;
GLboolean _GLEE_EXT_draw_buffers2 = GL_FALSE;
GLboolean _GLEE_NV_parameter_buffer_object = GL_FALSE;
GLboolean _GLEE_EXT_draw_instanced = GL_FALSE;
GLboolean _GLEE_EXT_fragment_lighting = GL_FALSE;
GLboolean _GLEE_EXT_packed_depth_stencil = GL_FALSE;
GLboolean _GLEE_EXT_scene_marker = GL_FALSE;
GLboolean _GLEE_EXT_stencil_clear_tag = GL_FALSE;
GLboolean _GLEE_EXT_texture_compression_dxt1 = GL_FALSE;
GLboolean _GLEE_EXT_texture_env = GL_FALSE;
GLboolean _GLEE_EXT_texture_sRGB = GL_FALSE;
GLboolean _GLEE_IBM_static_data = GL_FALSE;
GLboolean _GLEE_MESAX_texture_stack = GL_FALSE;
GLboolean _GLEE_OES_byte_coordinates = GL_FALSE;
GLboolean _GLEE_OES_compressed_paletted_texture = GL_FALSE;
GLboolean _GLEE_OES_single_precision = GL_FALSE;
GLboolean _GLEE_SGIX_pixel_texture_bits = GL_FALSE;
GLboolean _GLEE_SGIX_texture_range = GL_FALSE;

/*  GL Extension names */

char __GLeeGLExtensionNames[300][39]={
    "GL_VERSION_1_2",
    "GL_ARB_imaging",
    "GL_VERSION_1_3",
    "GL_VERSION_1_4",
    "GL_VERSION_1_5",
    "GL_VERSION_2_0",
    "GL_VERSION_2_1",
    "GL_ARB_multitexture",
    "GL_ARB_transpose_matrix",
    "GL_ARB_multisample",
    "GL_ARB_texture_env_add",
    "GL_ARB_texture_cube_map",
    "GL_ARB_texture_compression",
    "GL_ARB_texture_border_clamp",
    "GL_ARB_point_parameters",
    "GL_ARB_vertex_blend",
    "GL_ARB_matrix_palette",
    "GL_ARB_texture_env_combine",
    "GL_ARB_texture_env_crossbar",
    "GL_ARB_texture_env_dot3",
    "GL_ARB_texture_mirrored_repeat",
    "GL_ARB_depth_texture",
    "GL_ARB_shadow",
    "GL_ARB_shadow_ambient",
    "GL_ARB_window_pos",
    "GL_ARB_vertex_program",
    "GL_ARB_fragment_program",
    "GL_ARB_vertex_buffer_object",
    "GL_ARB_occlusion_query",
    "GL_ARB_shader_objects",
    "GL_ARB_vertex_shader",
    "GL_ARB_fragment_shader",
    "GL_ARB_shading_language_100",
    "GL_ARB_texture_non_power_of_two",
    "GL_ARB_point_sprite",
    "GL_ARB_fragment_program_shadow",
    "GL_ARB_draw_buffers",
    "GL_ARB_texture_rectangle",
    "GL_ARB_color_buffer_float",
    "GL_ARB_half_float_pixel",
    "GL_ARB_texture_float",
    "GL_ARB_pixel_buffer_object",
    "GL_EXT_abgr",
    "GL_EXT_blend_color",
    "GL_EXT_polygon_offset",
    "GL_EXT_texture",
    "GL_EXT_texture3D",
    "GL_SGIS_texture_filter4",
    "GL_EXT_subtexture",
    "GL_EXT_copy_texture",
    "GL_EXT_histogram",
    "GL_EXT_convolution",
    "GL_SGI_color_matrix",
    "GL_SGI_color_table",
    "GL_SGIS_pixel_texture",
    "GL_SGIX_pixel_texture",
    "GL_SGIS_texture4D",
    "GL_SGI_texture_color_table",
    "GL_EXT_cmyka",
    "GL_EXT_texture_object",
    "GL_SGIS_detail_texture",
    "GL_SGIS_sharpen_texture",
    "GL_EXT_packed_pixels",
    "GL_SGIS_texture_lod",
    "GL_SGIS_multisample",
    "GL_EXT_rescale_normal",
    "GL_EXT_vertex_array",
    "GL_EXT_misc_attribute",
    "GL_SGIS_generate_mipmap",
    "GL_SGIX_clipmap",
    "GL_SGIX_shadow",
    "GL_SGIS_texture_edge_clamp",
    "GL_SGIS_texture_border_clamp",
    "GL_EXT_blend_minmax",
    "GL_EXT_blend_subtract",
    "GL_EXT_blend_logic_op",
    "GL_SGIX_interlace",
    "GL_SGIX_pixel_tiles",
    "GL_SGIS_texture_select",
    "GL_SGIX_sprite",
    "GL_SGIX_texture_multi_buffer",
    "GL_EXT_point_parameters",
    "GL_SGIS_point_parameters",
    "GL_SGIX_instruments",
    "GL_SGIX_texture_scale_bias",
    "GL_SGIX_framezoom",
    "GL_SGIX_tag_sample_buffer",
    "GL_FfdMaskSGIX",
    "GL_SGIX_polynomial_ffd",
    "GL_SGIX_reference_plane",
    "GL_SGIX_flush_raster",
    "GL_SGIX_depth_texture",
    "GL_SGIS_fog_function",
    "GL_SGIX_fog_offset",
    "GL_HP_image_transform",
    "GL_HP_convolution_border_modes",
    "GL_INGR_palette_buffer",
    "GL_SGIX_texture_add_env",
    "GL_EXT_color_subtable",
    "GL_PGI_vertex_hints",
    "GL_PGI_misc_hints",
    "GL_EXT_paletted_texture",
    "GL_EXT_clip_volume_hint",
    "GL_SGIX_list_priority",
    "GL_SGIX_ir_instrument1",
    "GL_SGIX_calligraphic_fragment",
    "GL_SGIX_texture_lod_bias",
    "GL_SGIX_shadow_ambient",
    "GL_EXT_index_texture",
    "GL_EXT_index_material",
    "GL_EXT_index_func",
    "GL_EXT_index_array_formats",
    "GL_EXT_compiled_vertex_array",
    "GL_EXT_cull_vertex",
    "GL_SGIX_ycrcb",
    "GL_SGIX_fragment_lighting",
    "GL_IBM_rasterpos_clip",
    "GL_HP_texture_lighting",
    "GL_EXT_draw_range_elements",
    "GL_WIN_phong_shading",
    "GL_WIN_specular_fog",
    "GL_EXT_light_texture",
    "GL_SGIX_blend_alpha_minmax",
    "GL_SGIX_impact_pixel_texture",
    "GL_EXT_bgra",
    "GL_SGIX_async",
    "GL_SGIX_async_pixel",
    "GL_SGIX_async_histogram",
    "GL_INTEL_texture_scissor",
    "GL_INTEL_parallel_arrays",
    "GL_HP_occlusion_test",
    "GL_EXT_pixel_transform",
    "GL_EXT_pixel_transform_color_table",
    "GL_EXT_shared_texture_palette",
    "GL_EXT_separate_specular_color",
    "GL_EXT_secondary_color",
    "GL_EXT_texture_perturb_normal",
    "GL_EXT_multi_draw_arrays",
    "GL_EXT_fog_coord",
    "GL_REND_screen_coordinates",
    "GL_EXT_coordinate_frame",
    "GL_EXT_texture_env_combine",
    "GL_APPLE_specular_vector",
    "GL_APPLE_transform_hint",
    "GL_SGIX_fog_scale",
    "GL_SUNX_constant_data",
    "GL_SUN_global_alpha",
    "GL_SUN_triangle_list",
    "GL_SUN_vertex",
    "GL_EXT_blend_func_separate",
    "GL_INGR_color_clamp",
    "GL_INGR_interlace_read",
    "GL_EXT_stencil_wrap",
    "GL_EXT_422_pixels",
    "GL_NV_texgen_reflection",
    "GL_EXT_texture_cube_map",
    "GL_SUN_convolution_border_modes",
    "GL_EXT_texture_env_add",
    "GL_EXT_texture_lod_bias",
    "GL_EXT_texture_filter_anisotropic",
    "GL_EXT_vertex_weighting",
    "GL_NV_light_max_exponent",
    "GL_NV_vertex_array_range",
    "GL_NV_register_combiners",
    "GL_NV_fog_distance",
    "GL_NV_texgen_emboss",
    "GL_NV_blend_square",
    "GL_NV_texture_env_combine4",
    "GL_MESA_resize_buffers",
    "GL_MESA_window_pos",
    "GL_EXT_texture_compression_s3tc",
    "GL_IBM_cull_vertex",
    "GL_IBM_multimode_draw_arrays",
    "GL_IBM_vertex_array_lists",
    "GL_SGIX_subsample",
    "GL_SGIX_ycrcb_subsample",
    "GL_SGIX_ycrcba",
    "GL_SGI_depth_pass_instrument",
    "GL_3DFX_texture_compression_FXT1",
    "GL_3DFX_multisample",
    "GL_3DFX_tbuffer",
    "GL_EXT_multisample",
    "GL_SGIX_vertex_preclip",
    "GL_SGIX_convolution_accuracy",
    "GL_SGIX_resample",
    "GL_SGIS_point_line_texgen",
    "GL_SGIS_texture_color_mask",
    "GL_EXT_texture_env_dot3",
    "GL_ATI_texture_mirror_once",
    "GL_NV_fence",
    "GL_IBM_texture_mirrored_repeat",
    "GL_NV_evaluators",
    "GL_NV_packed_depth_stencil",
    "GL_NV_register_combiners2",
    "GL_NV_texture_compression_vtc",
    "GL_NV_texture_rectangle",
    "GL_NV_texture_shader",
    "GL_NV_texture_shader2",
    "GL_NV_vertex_array_range2",
    "GL_NV_vertex_program",
    "GL_SGIX_texture_coordinate_clamp",
    "GL_SGIX_scalebias_hint",
    "GL_OML_interlace",
    "GL_OML_subsample",
    "GL_OML_resample",
    "GL_NV_copy_depth_to_color",
    "GL_ATI_envmap_bumpmap",
    "GL_ATI_fragment_shader",
    "GL_ATI_pn_triangles",
    "GL_ATI_vertex_array_object",
    "GL_EXT_vertex_shader",
    "GL_ATI_vertex_streams",
    "GL_ATI_element_array",
    "GL_SUN_mesh_array",
    "GL_SUN_slice_accum",
    "GL_NV_multisample_filter_hint",
    "GL_NV_depth_clamp",
    "GL_NV_occlusion_query",
    "GL_NV_point_sprite",
    "GL_NV_texture_shader3",
    "GL_NV_vertex_program1_1",
    "GL_EXT_shadow_funcs",
    "GL_EXT_stencil_two_side",
    "GL_ATI_text_fragment_shader",
    "GL_APPLE_client_storage",
    "GL_APPLE_element_array",
    "GL_APPLE_fence",
    "GL_APPLE_vertex_array_object",
    "GL_APPLE_vertex_array_range",
    "GL_APPLE_ycbcr_422",
    "GL_S3_s3tc",
    "GL_ATI_draw_buffers",
    "GL_ATI_pixel_format_float",
    "GL_ATI_texture_env_combine3",
    "GL_ATI_texture_float",
    "GL_NV_float_buffer",
    "GL_NV_fragment_program",
    "GL_NV_half_float",
    "GL_NV_pixel_data_range",
    "GL_NV_primitive_restart",
    "GL_NV_texture_expand_normal",
    "GL_NV_vertex_program2",
    "GL_ATI_map_object_buffer",
    "GL_ATI_separate_stencil",
    "GL_ATI_vertex_attrib_array_object",
    "GL_OES_read_format",
    "GL_EXT_depth_bounds_test",
    "GL_EXT_texture_mirror_clamp",
    "GL_EXT_blend_equation_separate",
    "GL_MESA_pack_invert",
    "GL_MESA_ycbcr_texture",
    "GL_EXT_pixel_buffer_object",
    "GL_NV_fragment_program_option",
    "GL_NV_fragment_program2",
    "GL_NV_vertex_program2_option",
    "GL_NV_vertex_program3",
    "GL_EXT_framebuffer_object",
    "GL_GREMEDY_string_marker",
    "GL_EXT_Cg_shader",
    "GL_EXT_timer_query",
    "GL_EXT_texture_buffer_object",
    "GL_EXT_gpu_shader4",
    "GL_EXT_geometry_shader4",
    "GL_EXT_bindable_uniform",
    "GL_EXT_framebuffer_sRGB",
    "GL_EXT_texture_shared_exponent",
    "GL_EXT_packed_float",
    "GL_EXT_texture_array",
    "GL_EXT_texture_integer",
    "GL_NV_depth_buffer_float",
    "GL_EXT_texture_compression_latc",
    "GL_NV_transform_feedback",
    "GL_NV_geometry_program4",
    "GL_NV_gpu_program4",
    "GL_NV_framebuffer_multisample_coverage",
    "GL_EXT_framebuffer_multisample",
    "GL_EXT_framebuffer_blit",
    "GL_EXT_texture_compression_rgtc",
    "GL_EXT_color_matrix",
    "GL_SGIX_texture_select",
    "GL_INGR_blend_func_separate",
    "GL_SGIX_depth_pass_instrument",
    "GL_SGIX_igloo_interface",
    "GL_EXT_draw_buffers2",
    "GL_NV_parameter_buffer_object",
    "GL_EXT_draw_instanced",
    "GL_EXT_fragment_lighting",
    "GL_EXT_packed_depth_stencil",
    "GL_EXT_scene_marker",
    "GL_EXT_stencil_clear_tag",
    "GL_EXT_texture_compression_dxt1",
    "GL_EXT_texture_env",
    "GL_EXT_texture_sRGB",
    "GL_IBM_static_data",
    "GL_MESAX_texture_stack",
    "GL_OES_byte_coordinates",
    "GL_OES_compressed_paletted_texture",
    "GL_OES_single_precision",
    "GL_SGIX_pixel_texture_bits",
    "GL_SGIX_texture_range"
};
int __GLeeGLNumExtensions=300;

/* GL_VERSION_1_2 */

#ifdef __GLEE_GL_VERSION_1_2
void __stdcall _Lazy_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)  {if (GLeeInit()) glBlendColor(red, green, blue, alpha);}
void __stdcall _Lazy_glBlendEquation(GLenum mode)                                         {if (GLeeInit()) glBlendEquation(mode);}
void __stdcall _Lazy_glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices)  {if (GLeeInit()) glDrawRangeElements(mode, start, end, count, type, indices);}
void __stdcall _Lazy_glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table)  {if (GLeeInit()) glColorTable(target, internalformat, width, format, type, table);}
void __stdcall _Lazy_glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glColorTableParameterfv(target, pname, params);}
void __stdcall _Lazy_glColorTableParameteriv(GLenum target, GLenum pname, const GLint * params)  {if (GLeeInit()) glColorTableParameteriv(target, pname, params);}
void __stdcall _Lazy_glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)  {if (GLeeInit()) glCopyColorTable(target, internalformat, x, y, width);}
void __stdcall _Lazy_glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid * table)  {if (GLeeInit()) glGetColorTable(target, format, type, table);}
void __stdcall _Lazy_glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetColorTableParameterfv(target, pname, params);}
void __stdcall _Lazy_glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetColorTableParameteriv(target, pname, params);}
void __stdcall _Lazy_glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data)  {if (GLeeInit()) glColorSubTable(target, start, count, format, type, data);}
void __stdcall _Lazy_glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width)  {if (GLeeInit()) glCopyColorSubTable(target, start, x, y, width);}
void __stdcall _Lazy_glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image)  {if (GLeeInit()) glConvolutionFilter1D(target, internalformat, width, format, type, image);}
void __stdcall _Lazy_glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image)  {if (GLeeInit()) glConvolutionFilter2D(target, internalformat, width, height, format, type, image);}
void __stdcall _Lazy_glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params)  {if (GLeeInit()) glConvolutionParameterf(target, pname, params);}
void __stdcall _Lazy_glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glConvolutionParameterfv(target, pname, params);}
void __stdcall _Lazy_glConvolutionParameteri(GLenum target, GLenum pname, GLint params)   {if (GLeeInit()) glConvolutionParameteri(target, pname, params);}
void __stdcall _Lazy_glConvolutionParameteriv(GLenum target, GLenum pname, const GLint * params)  {if (GLeeInit()) glConvolutionParameteriv(target, pname, params);}
void __stdcall _Lazy_glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)  {if (GLeeInit()) glCopyConvolutionFilter1D(target, internalformat, x, y, width);}
void __stdcall _Lazy_glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height)  {if (GLeeInit()) glCopyConvolutionFilter2D(target, internalformat, x, y, width, height);}
void __stdcall _Lazy_glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid * image)  {if (GLeeInit()) glGetConvolutionFilter(target, format, type, image);}
void __stdcall _Lazy_glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetConvolutionParameterfv(target, pname, params);}
void __stdcall _Lazy_glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetConvolutionParameteriv(target, pname, params);}
void __stdcall _Lazy_glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span)  {if (GLeeInit()) glGetSeparableFilter(target, format, type, row, column, span);}
void __stdcall _Lazy_glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column)  {if (GLeeInit()) glSeparableFilter2D(target, internalformat, width, height, format, type, row, column);}
void __stdcall _Lazy_glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values)  {if (GLeeInit()) glGetHistogram(target, reset, format, type, values);}
void __stdcall _Lazy_glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetHistogramParameterfv(target, pname, params);}
void __stdcall _Lazy_glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetHistogramParameteriv(target, pname, params);}
void __stdcall _Lazy_glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values)  {if (GLeeInit()) glGetMinmax(target, reset, format, type, values);}
void __stdcall _Lazy_glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetMinmaxParameterfv(target, pname, params);}
void __stdcall _Lazy_glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetMinmaxParameteriv(target, pname, params);}
void __stdcall _Lazy_glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)  {if (GLeeInit()) glHistogram(target, width, internalformat, sink);}
void __stdcall _Lazy_glMinmax(GLenum target, GLenum internalformat, GLboolean sink)       {if (GLeeInit()) glMinmax(target, internalformat, sink);}
void __stdcall _Lazy_glResetHistogram(GLenum target)                                      {if (GLeeInit()) glResetHistogram(target);}
void __stdcall _Lazy_glResetMinmax(GLenum target)                                         {if (GLeeInit()) glResetMinmax(target);}
void __stdcall _Lazy_glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels)  {if (GLeeInit()) glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);}
void __stdcall _Lazy_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels)  {if (GLeeInit()) glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);}
void __stdcall _Lazy_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)  {if (GLeeInit()) glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);}
PFNGLBLENDCOLORPROC pglBlendColor=_Lazy_glBlendColor;
PFNGLBLENDEQUATIONPROC pglBlendEquation=_Lazy_glBlendEquation;
PFNGLDRAWRANGEELEMENTSPROC pglDrawRangeElements=_Lazy_glDrawRangeElements;
PFNGLCOLORTABLEPROC pglColorTable=_Lazy_glColorTable;
PFNGLCOLORTABLEPARAMETERFVPROC pglColorTableParameterfv=_Lazy_glColorTableParameterfv;
PFNGLCOLORTABLEPARAMETERIVPROC pglColorTableParameteriv=_Lazy_glColorTableParameteriv;
PFNGLCOPYCOLORTABLEPROC pglCopyColorTable=_Lazy_glCopyColorTable;
PFNGLGETCOLORTABLEPROC pglGetColorTable=_Lazy_glGetColorTable;
PFNGLGETCOLORTABLEPARAMETERFVPROC pglGetColorTableParameterfv=_Lazy_glGetColorTableParameterfv;
PFNGLGETCOLORTABLEPARAMETERIVPROC pglGetColorTableParameteriv=_Lazy_glGetColorTableParameteriv;
PFNGLCOLORSUBTABLEPROC pglColorSubTable=_Lazy_glColorSubTable;
PFNGLCOPYCOLORSUBTABLEPROC pglCopyColorSubTable=_Lazy_glCopyColorSubTable;
PFNGLCONVOLUTIONFILTER1DPROC pglConvolutionFilter1D=_Lazy_glConvolutionFilter1D;
PFNGLCONVOLUTIONFILTER2DPROC pglConvolutionFilter2D=_Lazy_glConvolutionFilter2D;
PFNGLCONVOLUTIONPARAMETERFPROC pglConvolutionParameterf=_Lazy_glConvolutionParameterf;
PFNGLCONVOLUTIONPARAMETERFVPROC pglConvolutionParameterfv=_Lazy_glConvolutionParameterfv;
PFNGLCONVOLUTIONPARAMETERIPROC pglConvolutionParameteri=_Lazy_glConvolutionParameteri;
PFNGLCONVOLUTIONPARAMETERIVPROC pglConvolutionParameteriv=_Lazy_glConvolutionParameteriv;
PFNGLCOPYCONVOLUTIONFILTER1DPROC pglCopyConvolutionFilter1D=_Lazy_glCopyConvolutionFilter1D;
PFNGLCOPYCONVOLUTIONFILTER2DPROC pglCopyConvolutionFilter2D=_Lazy_glCopyConvolutionFilter2D;
PFNGLGETCONVOLUTIONFILTERPROC pglGetConvolutionFilter=_Lazy_glGetConvolutionFilter;
PFNGLGETCONVOLUTIONPARAMETERFVPROC pglGetConvolutionParameterfv=_Lazy_glGetConvolutionParameterfv;
PFNGLGETCONVOLUTIONPARAMETERIVPROC pglGetConvolutionParameteriv=_Lazy_glGetConvolutionParameteriv;
PFNGLGETSEPARABLEFILTERPROC pglGetSeparableFilter=_Lazy_glGetSeparableFilter;
PFNGLSEPARABLEFILTER2DPROC pglSeparableFilter2D=_Lazy_glSeparableFilter2D;
PFNGLGETHISTOGRAMPROC pglGetHistogram=_Lazy_glGetHistogram;
PFNGLGETHISTOGRAMPARAMETERFVPROC pglGetHistogramParameterfv=_Lazy_glGetHistogramParameterfv;
PFNGLGETHISTOGRAMPARAMETERIVPROC pglGetHistogramParameteriv=_Lazy_glGetHistogramParameteriv;
PFNGLGETMINMAXPROC pglGetMinmax=_Lazy_glGetMinmax;
PFNGLGETMINMAXPARAMETERFVPROC pglGetMinmaxParameterfv=_Lazy_glGetMinmaxParameterfv;
PFNGLGETMINMAXPARAMETERIVPROC pglGetMinmaxParameteriv=_Lazy_glGetMinmaxParameteriv;
PFNGLHISTOGRAMPROC pglHistogram=_Lazy_glHistogram;
PFNGLMINMAXPROC pglMinmax=_Lazy_glMinmax;
PFNGLRESETHISTOGRAMPROC pglResetHistogram=_Lazy_glResetHistogram;
PFNGLRESETMINMAXPROC pglResetMinmax=_Lazy_glResetMinmax;
PFNGLTEXIMAGE3DPROC pglTexImage3D=_Lazy_glTexImage3D;
PFNGLTEXSUBIMAGE3DPROC pglTexSubImage3D=_Lazy_glTexSubImage3D;
PFNGLCOPYTEXSUBIMAGE3DPROC pglCopyTexSubImage3D=_Lazy_glCopyTexSubImage3D;
#endif 

/* GL_ARB_imaging */

#ifdef __GLEE_GL_ARB_imaging
#endif 

/* GL_VERSION_1_3 */

#ifdef __GLEE_GL_VERSION_1_3
void __stdcall _Lazy_glActiveTexture(GLenum texture)                                      {if (GLeeInit()) glActiveTexture(texture);}
void __stdcall _Lazy_glClientActiveTexture(GLenum texture)                                {if (GLeeInit()) glClientActiveTexture(texture);}
void __stdcall _Lazy_glMultiTexCoord1d(GLenum target, GLdouble s)                         {if (GLeeInit()) glMultiTexCoord1d(target, s);}
void __stdcall _Lazy_glMultiTexCoord1dv(GLenum target, const GLdouble * v)                {if (GLeeInit()) glMultiTexCoord1dv(target, v);}
void __stdcall _Lazy_glMultiTexCoord1f(GLenum target, GLfloat s)                          {if (GLeeInit()) glMultiTexCoord1f(target, s);}
void __stdcall _Lazy_glMultiTexCoord1fv(GLenum target, const GLfloat * v)                 {if (GLeeInit()) glMultiTexCoord1fv(target, v);}
void __stdcall _Lazy_glMultiTexCoord1i(GLenum target, GLint s)                            {if (GLeeInit()) glMultiTexCoord1i(target, s);}
void __stdcall _Lazy_glMultiTexCoord1iv(GLenum target, const GLint * v)                   {if (GLeeInit()) glMultiTexCoord1iv(target, v);}
void __stdcall _Lazy_glMultiTexCoord1s(GLenum target, GLshort s)                          {if (GLeeInit()) glMultiTexCoord1s(target, s);}
void __stdcall _Lazy_glMultiTexCoord1sv(GLenum target, const GLshort * v)                 {if (GLeeInit()) glMultiTexCoord1sv(target, v);}
void __stdcall _Lazy_glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t)             {if (GLeeInit()) glMultiTexCoord2d(target, s, t);}
void __stdcall _Lazy_glMultiTexCoord2dv(GLenum target, const GLdouble * v)                {if (GLeeInit()) glMultiTexCoord2dv(target, v);}
void __stdcall _Lazy_glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t)               {if (GLeeInit()) glMultiTexCoord2f(target, s, t);}
void __stdcall _Lazy_glMultiTexCoord2fv(GLenum target, const GLfloat * v)                 {if (GLeeInit()) glMultiTexCoord2fv(target, v);}
void __stdcall _Lazy_glMultiTexCoord2i(GLenum target, GLint s, GLint t)                   {if (GLeeInit()) glMultiTexCoord2i(target, s, t);}
void __stdcall _Lazy_glMultiTexCoord2iv(GLenum target, const GLint * v)                   {if (GLeeInit()) glMultiTexCoord2iv(target, v);}
void __stdcall _Lazy_glMultiTexCoord2s(GLenum target, GLshort s, GLshort t)               {if (GLeeInit()) glMultiTexCoord2s(target, s, t);}
void __stdcall _Lazy_glMultiTexCoord2sv(GLenum target, const GLshort * v)                 {if (GLeeInit()) glMultiTexCoord2sv(target, v);}
void __stdcall _Lazy_glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r)  {if (GLeeInit()) glMultiTexCoord3d(target, s, t, r);}
void __stdcall _Lazy_glMultiTexCoord3dv(GLenum target, const GLdouble * v)                {if (GLeeInit()) glMultiTexCoord3dv(target, v);}
void __stdcall _Lazy_glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r)    {if (GLeeInit()) glMultiTexCoord3f(target, s, t, r);}
void __stdcall _Lazy_glMultiTexCoord3fv(GLenum target, const GLfloat * v)                 {if (GLeeInit()) glMultiTexCoord3fv(target, v);}
void __stdcall _Lazy_glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r)          {if (GLeeInit()) glMultiTexCoord3i(target, s, t, r);}
void __stdcall _Lazy_glMultiTexCoord3iv(GLenum target, const GLint * v)                   {if (GLeeInit()) glMultiTexCoord3iv(target, v);}
void __stdcall _Lazy_glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r)    {if (GLeeInit()) glMultiTexCoord3s(target, s, t, r);}
void __stdcall _Lazy_glMultiTexCoord3sv(GLenum target, const GLshort * v)                 {if (GLeeInit()) glMultiTexCoord3sv(target, v);}
void __stdcall _Lazy_glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)  {if (GLeeInit()) glMultiTexCoord4d(target, s, t, r, q);}
void __stdcall _Lazy_glMultiTexCoord4dv(GLenum target, const GLdouble * v)                {if (GLeeInit()) glMultiTexCoord4dv(target, v);}
void __stdcall _Lazy_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)  {if (GLeeInit()) glMultiTexCoord4f(target, s, t, r, q);}
void __stdcall _Lazy_glMultiTexCoord4fv(GLenum target, const GLfloat * v)                 {if (GLeeInit()) glMultiTexCoord4fv(target, v);}
void __stdcall _Lazy_glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q)  {if (GLeeInit()) glMultiTexCoord4i(target, s, t, r, q);}
void __stdcall _Lazy_glMultiTexCoord4iv(GLenum target, const GLint * v)                   {if (GLeeInit()) glMultiTexCoord4iv(target, v);}
void __stdcall _Lazy_glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)  {if (GLeeInit()) glMultiTexCoord4s(target, s, t, r, q);}
void __stdcall _Lazy_glMultiTexCoord4sv(GLenum target, const GLshort * v)                 {if (GLeeInit()) glMultiTexCoord4sv(target, v);}
void __stdcall _Lazy_glLoadTransposeMatrixf(const GLfloat * m)                            {if (GLeeInit()) glLoadTransposeMatrixf(m);}
void __stdcall _Lazy_glLoadTransposeMatrixd(const GLdouble * m)                           {if (GLeeInit()) glLoadTransposeMatrixd(m);}
void __stdcall _Lazy_glMultTransposeMatrixf(const GLfloat * m)                            {if (GLeeInit()) glMultTransposeMatrixf(m);}
void __stdcall _Lazy_glMultTransposeMatrixd(const GLdouble * m)                           {if (GLeeInit()) glMultTransposeMatrixd(m);}
void __stdcall _Lazy_glSampleCoverage(GLclampf value, GLboolean invert)                   {if (GLeeInit()) glSampleCoverage(value, invert);}
void __stdcall _Lazy_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);}
void __stdcall _Lazy_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);}
void __stdcall _Lazy_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);}
void __stdcall _Lazy_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);}
void __stdcall _Lazy_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);}
void __stdcall _Lazy_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);}
void __stdcall _Lazy_glGetCompressedTexImage(GLenum target, GLint level, GLvoid * img)    {if (GLeeInit()) glGetCompressedTexImage(target, level, img);}
PFNGLACTIVETEXTUREPROC pglActiveTexture=_Lazy_glActiveTexture;
PFNGLCLIENTACTIVETEXTUREPROC pglClientActiveTexture=_Lazy_glClientActiveTexture;
PFNGLMULTITEXCOORD1DPROC pglMultiTexCoord1d=_Lazy_glMultiTexCoord1d;
PFNGLMULTITEXCOORD1DVPROC pglMultiTexCoord1dv=_Lazy_glMultiTexCoord1dv;
PFNGLMULTITEXCOORD1FPROC pglMultiTexCoord1f=_Lazy_glMultiTexCoord1f;
PFNGLMULTITEXCOORD1FVPROC pglMultiTexCoord1fv=_Lazy_glMultiTexCoord1fv;
PFNGLMULTITEXCOORD1IPROC pglMultiTexCoord1i=_Lazy_glMultiTexCoord1i;
PFNGLMULTITEXCOORD1IVPROC pglMultiTexCoord1iv=_Lazy_glMultiTexCoord1iv;
PFNGLMULTITEXCOORD1SPROC pglMultiTexCoord1s=_Lazy_glMultiTexCoord1s;
PFNGLMULTITEXCOORD1SVPROC pglMultiTexCoord1sv=_Lazy_glMultiTexCoord1sv;
PFNGLMULTITEXCOORD2DPROC pglMultiTexCoord2d=_Lazy_glMultiTexCoord2d;
PFNGLMULTITEXCOORD2DVPROC pglMultiTexCoord2dv=_Lazy_glMultiTexCoord2dv;
PFNGLMULTITEXCOORD2FPROC pglMultiTexCoord2f=_Lazy_glMultiTexCoord2f;
PFNGLMULTITEXCOORD2FVPROC pglMultiTexCoord2fv=_Lazy_glMultiTexCoord2fv;
PFNGLMULTITEXCOORD2IPROC pglMultiTexCoord2i=_Lazy_glMultiTexCoord2i;
PFNGLMULTITEXCOORD2IVPROC pglMultiTexCoord2iv=_Lazy_glMultiTexCoord2iv;
PFNGLMULTITEXCOORD2SPROC pglMultiTexCoord2s=_Lazy_glMultiTexCoord2s;
PFNGLMULTITEXCOORD2SVPROC pglMultiTexCoord2sv=_Lazy_glMultiTexCoord2sv;
PFNGLMULTITEXCOORD3DPROC pglMultiTexCoord3d=_Lazy_glMultiTexCoord3d;
PFNGLMULTITEXCOORD3DVPROC pglMultiTexCoord3dv=_Lazy_glMultiTexCoord3dv;
PFNGLMULTITEXCOORD3FPROC pglMultiTexCoord3f=_Lazy_glMultiTexCoord3f;
PFNGLMULTITEXCOORD3FVPROC pglMultiTexCoord3fv=_Lazy_glMultiTexCoord3fv;
PFNGLMULTITEXCOORD3IPROC pglMultiTexCoord3i=_Lazy_glMultiTexCoord3i;
PFNGLMULTITEXCOORD3IVPROC pglMultiTexCoord3iv=_Lazy_glMultiTexCoord3iv;
PFNGLMULTITEXCOORD3SPROC pglMultiTexCoord3s=_Lazy_glMultiTexCoord3s;
PFNGLMULTITEXCOORD3SVPROC pglMultiTexCoord3sv=_Lazy_glMultiTexCoord3sv;
PFNGLMULTITEXCOORD4DPROC pglMultiTexCoord4d=_Lazy_glMultiTexCoord4d;
PFNGLMULTITEXCOORD4DVPROC pglMultiTexCoord4dv=_Lazy_glMultiTexCoord4dv;
PFNGLMULTITEXCOORD4FPROC pglMultiTexCoord4f=_Lazy_glMultiTexCoord4f;
PFNGLMULTITEXCOORD4FVPROC pglMultiTexCoord4fv=_Lazy_glMultiTexCoord4fv;
PFNGLMULTITEXCOORD4IPROC pglMultiTexCoord4i=_Lazy_glMultiTexCoord4i;
PFNGLMULTITEXCOORD4IVPROC pglMultiTexCoord4iv=_Lazy_glMultiTexCoord4iv;
PFNGLMULTITEXCOORD4SPROC pglMultiTexCoord4s=_Lazy_glMultiTexCoord4s;
PFNGLMULTITEXCOORD4SVPROC pglMultiTexCoord4sv=_Lazy_glMultiTexCoord4sv;
PFNGLLOADTRANSPOSEMATRIXFPROC pglLoadTransposeMatrixf=_Lazy_glLoadTransposeMatrixf;
PFNGLLOADTRANSPOSEMATRIXDPROC pglLoadTransposeMatrixd=_Lazy_glLoadTransposeMatrixd;
PFNGLMULTTRANSPOSEMATRIXFPROC pglMultTransposeMatrixf=_Lazy_glMultTransposeMatrixf;
PFNGLMULTTRANSPOSEMATRIXDPROC pglMultTransposeMatrixd=_Lazy_glMultTransposeMatrixd;
PFNGLSAMPLECOVERAGEPROC pglSampleCoverage=_Lazy_glSampleCoverage;
PFNGLCOMPRESSEDTEXIMAGE3DPROC pglCompressedTexImage3D=_Lazy_glCompressedTexImage3D;
PFNGLCOMPRESSEDTEXIMAGE2DPROC pglCompressedTexImage2D=_Lazy_glCompressedTexImage2D;
PFNGLCOMPRESSEDTEXIMAGE1DPROC pglCompressedTexImage1D=_Lazy_glCompressedTexImage1D;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC pglCompressedTexSubImage3D=_Lazy_glCompressedTexSubImage3D;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC pglCompressedTexSubImage2D=_Lazy_glCompressedTexSubImage2D;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC pglCompressedTexSubImage1D=_Lazy_glCompressedTexSubImage1D;
PFNGLGETCOMPRESSEDTEXIMAGEPROC pglGetCompressedTexImage=_Lazy_glGetCompressedTexImage;
#endif 

/* GL_VERSION_1_4 */

#ifdef __GLEE_GL_VERSION_1_4
void __stdcall _Lazy_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)  {if (GLeeInit()) glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);}
void __stdcall _Lazy_glFogCoordf(GLfloat coord)                                           {if (GLeeInit()) glFogCoordf(coord);}
void __stdcall _Lazy_glFogCoordfv(const GLfloat * coord)                                  {if (GLeeInit()) glFogCoordfv(coord);}
void __stdcall _Lazy_glFogCoordd(GLdouble coord)                                          {if (GLeeInit()) glFogCoordd(coord);}
void __stdcall _Lazy_glFogCoorddv(const GLdouble * coord)                                 {if (GLeeInit()) glFogCoorddv(coord);}
void __stdcall _Lazy_glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glFogCoordPointer(type, stride, pointer);}
void __stdcall _Lazy_glMultiDrawArrays(GLenum mode, GLint * first, GLsizei * count, GLsizei primcount)  {if (GLeeInit()) glMultiDrawArrays(mode, first, count, primcount);}
void __stdcall _Lazy_glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const GLvoid* * indices, GLsizei primcount)  {if (GLeeInit()) glMultiDrawElements(mode, count, type, indices, primcount);}
void __stdcall _Lazy_glPointParameterf(GLenum pname, GLfloat param)                       {if (GLeeInit()) glPointParameterf(pname, param);}
void __stdcall _Lazy_glPointParameterfv(GLenum pname, const GLfloat * params)             {if (GLeeInit()) glPointParameterfv(pname, params);}
void __stdcall _Lazy_glPointParameteri(GLenum pname, GLint param)                         {if (GLeeInit()) glPointParameteri(pname, param);}
void __stdcall _Lazy_glPointParameteriv(GLenum pname, const GLint * params)               {if (GLeeInit()) glPointParameteriv(pname, params);}
void __stdcall _Lazy_glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue)            {if (GLeeInit()) glSecondaryColor3b(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3bv(const GLbyte * v)                                {if (GLeeInit()) glSecondaryColor3bv(v);}
void __stdcall _Lazy_glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue)      {if (GLeeInit()) glSecondaryColor3d(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3dv(const GLdouble * v)                              {if (GLeeInit()) glSecondaryColor3dv(v);}
void __stdcall _Lazy_glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue)         {if (GLeeInit()) glSecondaryColor3f(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3fv(const GLfloat * v)                               {if (GLeeInit()) glSecondaryColor3fv(v);}
void __stdcall _Lazy_glSecondaryColor3i(GLint red, GLint green, GLint blue)               {if (GLeeInit()) glSecondaryColor3i(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3iv(const GLint * v)                                 {if (GLeeInit()) glSecondaryColor3iv(v);}
void __stdcall _Lazy_glSecondaryColor3s(GLshort red, GLshort green, GLshort blue)         {if (GLeeInit()) glSecondaryColor3s(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3sv(const GLshort * v)                               {if (GLeeInit()) glSecondaryColor3sv(v);}
void __stdcall _Lazy_glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue)        {if (GLeeInit()) glSecondaryColor3ub(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3ubv(const GLubyte * v)                              {if (GLeeInit()) glSecondaryColor3ubv(v);}
void __stdcall _Lazy_glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue)           {if (GLeeInit()) glSecondaryColor3ui(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3uiv(const GLuint * v)                               {if (GLeeInit()) glSecondaryColor3uiv(v);}
void __stdcall _Lazy_glSecondaryColor3us(GLushort red, GLushort green, GLushort blue)     {if (GLeeInit()) glSecondaryColor3us(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3usv(const GLushort * v)                             {if (GLeeInit()) glSecondaryColor3usv(v);}
void __stdcall _Lazy_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glSecondaryColorPointer(size, type, stride, pointer);}
void __stdcall _Lazy_glWindowPos2d(GLdouble x, GLdouble y)                                {if (GLeeInit()) glWindowPos2d(x, y);}
void __stdcall _Lazy_glWindowPos2dv(const GLdouble * v)                                   {if (GLeeInit()) glWindowPos2dv(v);}
void __stdcall _Lazy_glWindowPos2f(GLfloat x, GLfloat y)                                  {if (GLeeInit()) glWindowPos2f(x, y);}
void __stdcall _Lazy_glWindowPos2fv(const GLfloat * v)                                    {if (GLeeInit()) glWindowPos2fv(v);}
void __stdcall _Lazy_glWindowPos2i(GLint x, GLint y)                                      {if (GLeeInit()) glWindowPos2i(x, y);}
void __stdcall _Lazy_glWindowPos2iv(const GLint * v)                                      {if (GLeeInit()) glWindowPos2iv(v);}
void __stdcall _Lazy_glWindowPos2s(GLshort x, GLshort y)                                  {if (GLeeInit()) glWindowPos2s(x, y);}
void __stdcall _Lazy_glWindowPos2sv(const GLshort * v)                                    {if (GLeeInit()) glWindowPos2sv(v);}
void __stdcall _Lazy_glWindowPos3d(GLdouble x, GLdouble y, GLdouble z)                    {if (GLeeInit()) glWindowPos3d(x, y, z);}
void __stdcall _Lazy_glWindowPos3dv(const GLdouble * v)                                   {if (GLeeInit()) glWindowPos3dv(v);}
void __stdcall _Lazy_glWindowPos3f(GLfloat x, GLfloat y, GLfloat z)                       {if (GLeeInit()) glWindowPos3f(x, y, z);}
void __stdcall _Lazy_glWindowPos3fv(const GLfloat * v)                                    {if (GLeeInit()) glWindowPos3fv(v);}
void __stdcall _Lazy_glWindowPos3i(GLint x, GLint y, GLint z)                             {if (GLeeInit()) glWindowPos3i(x, y, z);}
void __stdcall _Lazy_glWindowPos3iv(const GLint * v)                                      {if (GLeeInit()) glWindowPos3iv(v);}
void __stdcall _Lazy_glWindowPos3s(GLshort x, GLshort y, GLshort z)                       {if (GLeeInit()) glWindowPos3s(x, y, z);}
void __stdcall _Lazy_glWindowPos3sv(const GLshort * v)                                    {if (GLeeInit()) glWindowPos3sv(v);}
PFNGLBLENDFUNCSEPARATEPROC pglBlendFuncSeparate=_Lazy_glBlendFuncSeparate;
PFNGLFOGCOORDFPROC pglFogCoordf=_Lazy_glFogCoordf;
PFNGLFOGCOORDFVPROC pglFogCoordfv=_Lazy_glFogCoordfv;
PFNGLFOGCOORDDPROC pglFogCoordd=_Lazy_glFogCoordd;
PFNGLFOGCOORDDVPROC pglFogCoorddv=_Lazy_glFogCoorddv;
PFNGLFOGCOORDPOINTERPROC pglFogCoordPointer=_Lazy_glFogCoordPointer;
PFNGLMULTIDRAWARRAYSPROC pglMultiDrawArrays=_Lazy_glMultiDrawArrays;
PFNGLMULTIDRAWELEMENTSPROC pglMultiDrawElements=_Lazy_glMultiDrawElements;
PFNGLPOINTPARAMETERFPROC pglPointParameterf=_Lazy_glPointParameterf;
PFNGLPOINTPARAMETERFVPROC pglPointParameterfv=_Lazy_glPointParameterfv;
PFNGLPOINTPARAMETERIPROC pglPointParameteri=_Lazy_glPointParameteri;
PFNGLPOINTPARAMETERIVPROC pglPointParameteriv=_Lazy_glPointParameteriv;
PFNGLSECONDARYCOLOR3BPROC pglSecondaryColor3b=_Lazy_glSecondaryColor3b;
PFNGLSECONDARYCOLOR3BVPROC pglSecondaryColor3bv=_Lazy_glSecondaryColor3bv;
PFNGLSECONDARYCOLOR3DPROC pglSecondaryColor3d=_Lazy_glSecondaryColor3d;
PFNGLSECONDARYCOLOR3DVPROC pglSecondaryColor3dv=_Lazy_glSecondaryColor3dv;
PFNGLSECONDARYCOLOR3FPROC pglSecondaryColor3f=_Lazy_glSecondaryColor3f;
PFNGLSECONDARYCOLOR3FVPROC pglSecondaryColor3fv=_Lazy_glSecondaryColor3fv;
PFNGLSECONDARYCOLOR3IPROC pglSecondaryColor3i=_Lazy_glSecondaryColor3i;
PFNGLSECONDARYCOLOR3IVPROC pglSecondaryColor3iv=_Lazy_glSecondaryColor3iv;
PFNGLSECONDARYCOLOR3SPROC pglSecondaryColor3s=_Lazy_glSecondaryColor3s;
PFNGLSECONDARYCOLOR3SVPROC pglSecondaryColor3sv=_Lazy_glSecondaryColor3sv;
PFNGLSECONDARYCOLOR3UBPROC pglSecondaryColor3ub=_Lazy_glSecondaryColor3ub;
PFNGLSECONDARYCOLOR3UBVPROC pglSecondaryColor3ubv=_Lazy_glSecondaryColor3ubv;
PFNGLSECONDARYCOLOR3UIPROC pglSecondaryColor3ui=_Lazy_glSecondaryColor3ui;
PFNGLSECONDARYCOLOR3UIVPROC pglSecondaryColor3uiv=_Lazy_glSecondaryColor3uiv;
PFNGLSECONDARYCOLOR3USPROC pglSecondaryColor3us=_Lazy_glSecondaryColor3us;
PFNGLSECONDARYCOLOR3USVPROC pglSecondaryColor3usv=_Lazy_glSecondaryColor3usv;
PFNGLSECONDARYCOLORPOINTERPROC pglSecondaryColorPointer=_Lazy_glSecondaryColorPointer;
PFNGLWINDOWPOS2DPROC pglWindowPos2d=_Lazy_glWindowPos2d;
PFNGLWINDOWPOS2DVPROC pglWindowPos2dv=_Lazy_glWindowPos2dv;
PFNGLWINDOWPOS2FPROC pglWindowPos2f=_Lazy_glWindowPos2f;
PFNGLWINDOWPOS2FVPROC pglWindowPos2fv=_Lazy_glWindowPos2fv;
PFNGLWINDOWPOS2IPROC pglWindowPos2i=_Lazy_glWindowPos2i;
PFNGLWINDOWPOS2IVPROC pglWindowPos2iv=_Lazy_glWindowPos2iv;
PFNGLWINDOWPOS2SPROC pglWindowPos2s=_Lazy_glWindowPos2s;
PFNGLWINDOWPOS2SVPROC pglWindowPos2sv=_Lazy_glWindowPos2sv;
PFNGLWINDOWPOS3DPROC pglWindowPos3d=_Lazy_glWindowPos3d;
PFNGLWINDOWPOS3DVPROC pglWindowPos3dv=_Lazy_glWindowPos3dv;
PFNGLWINDOWPOS3FPROC pglWindowPos3f=_Lazy_glWindowPos3f;
PFNGLWINDOWPOS3FVPROC pglWindowPos3fv=_Lazy_glWindowPos3fv;
PFNGLWINDOWPOS3IPROC pglWindowPos3i=_Lazy_glWindowPos3i;
PFNGLWINDOWPOS3IVPROC pglWindowPos3iv=_Lazy_glWindowPos3iv;
PFNGLWINDOWPOS3SPROC pglWindowPos3s=_Lazy_glWindowPos3s;
PFNGLWINDOWPOS3SVPROC pglWindowPos3sv=_Lazy_glWindowPos3sv;
#endif 

/* GL_VERSION_1_5 */

#ifdef __GLEE_GL_VERSION_1_5
void __stdcall _Lazy_glGenQueries(GLsizei n, GLuint * ids)                                {if (GLeeInit()) glGenQueries(n, ids);}
void __stdcall _Lazy_glDeleteQueries(GLsizei n, const GLuint * ids)                       {if (GLeeInit()) glDeleteQueries(n, ids);}
GLboolean __stdcall _Lazy_glIsQuery(GLuint id)                                            {if (GLeeInit()) return glIsQuery(id); return (GLboolean)0;}
void __stdcall _Lazy_glBeginQuery(GLenum target, GLuint id)                               {if (GLeeInit()) glBeginQuery(target, id);}
void __stdcall _Lazy_glEndQuery(GLenum target)                                            {if (GLeeInit()) glEndQuery(target);}
void __stdcall _Lazy_glGetQueryiv(GLenum target, GLenum pname, GLint * params)            {if (GLeeInit()) glGetQueryiv(target, pname, params);}
void __stdcall _Lazy_glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params)          {if (GLeeInit()) glGetQueryObjectiv(id, pname, params);}
void __stdcall _Lazy_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params)        {if (GLeeInit()) glGetQueryObjectuiv(id, pname, params);}
void __stdcall _Lazy_glBindBuffer(GLenum target, GLuint buffer)                           {if (GLeeInit()) glBindBuffer(target, buffer);}
void __stdcall _Lazy_glDeleteBuffers(GLsizei n, const GLuint * buffers)                   {if (GLeeInit()) glDeleteBuffers(n, buffers);}
void __stdcall _Lazy_glGenBuffers(GLsizei n, GLuint * buffers)                            {if (GLeeInit()) glGenBuffers(n, buffers);}
GLboolean __stdcall _Lazy_glIsBuffer(GLuint buffer)                                       {if (GLeeInit()) return glIsBuffer(buffer); return (GLboolean)0;}
void __stdcall _Lazy_glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage)  {if (GLeeInit()) glBufferData(target, size, data, usage);}
void __stdcall _Lazy_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data)  {if (GLeeInit()) glBufferSubData(target, offset, size, data);}
void __stdcall _Lazy_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data)  {if (GLeeInit()) glGetBufferSubData(target, offset, size, data);}
GLvoid* __stdcall _Lazy_glMapBuffer(GLenum target, GLenum access)                         {if (GLeeInit()) return glMapBuffer(target, access); return (GLvoid*)0;}
GLboolean __stdcall _Lazy_glUnmapBuffer(GLenum target)                                    {if (GLeeInit()) return glUnmapBuffer(target); return (GLboolean)0;}
void __stdcall _Lazy_glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetBufferParameteriv(target, pname, params);}
void __stdcall _Lazy_glGetBufferPointerv(GLenum target, GLenum pname, GLvoid* * params)   {if (GLeeInit()) glGetBufferPointerv(target, pname, params);}
PFNGLGENQUERIESPROC pglGenQueries=_Lazy_glGenQueries;
PFNGLDELETEQUERIESPROC pglDeleteQueries=_Lazy_glDeleteQueries;
PFNGLISQUERYPROC pglIsQuery=_Lazy_glIsQuery;
PFNGLBEGINQUERYPROC pglBeginQuery=_Lazy_glBeginQuery;
PFNGLENDQUERYPROC pglEndQuery=_Lazy_glEndQuery;
PFNGLGETQUERYIVPROC pglGetQueryiv=_Lazy_glGetQueryiv;
PFNGLGETQUERYOBJECTIVPROC pglGetQueryObjectiv=_Lazy_glGetQueryObjectiv;
PFNGLGETQUERYOBJECTUIVPROC pglGetQueryObjectuiv=_Lazy_glGetQueryObjectuiv;
PFNGLBINDBUFFERPROC pglBindBuffer=_Lazy_glBindBuffer;
PFNGLDELETEBUFFERSPROC pglDeleteBuffers=_Lazy_glDeleteBuffers;
PFNGLGENBUFFERSPROC pglGenBuffers=_Lazy_glGenBuffers;
PFNGLISBUFFERPROC pglIsBuffer=_Lazy_glIsBuffer;
PFNGLBUFFERDATAPROC pglBufferData=_Lazy_glBufferData;
PFNGLBUFFERSUBDATAPROC pglBufferSubData=_Lazy_glBufferSubData;
PFNGLGETBUFFERSUBDATAPROC pglGetBufferSubData=_Lazy_glGetBufferSubData;
PFNGLMAPBUFFERPROC pglMapBuffer=_Lazy_glMapBuffer;
PFNGLUNMAPBUFFERPROC pglUnmapBuffer=_Lazy_glUnmapBuffer;
PFNGLGETBUFFERPARAMETERIVPROC pglGetBufferParameteriv=_Lazy_glGetBufferParameteriv;
PFNGLGETBUFFERPOINTERVPROC pglGetBufferPointerv=_Lazy_glGetBufferPointerv;
#endif 

/* GL_VERSION_2_0 */

#ifdef __GLEE_GL_VERSION_2_0
void __stdcall _Lazy_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)            {if (GLeeInit()) glBlendEquationSeparate(modeRGB, modeAlpha);}
void __stdcall _Lazy_glDrawBuffers(GLsizei n, const GLenum * bufs)                        {if (GLeeInit()) glDrawBuffers(n, bufs);}
void __stdcall _Lazy_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)  {if (GLeeInit()) glStencilOpSeparate(face, sfail, dpfail, dppass);}
void __stdcall _Lazy_glStencilFuncSeparate(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask)  {if (GLeeInit()) glStencilFuncSeparate(frontfunc, backfunc, ref, mask);}
void __stdcall _Lazy_glStencilMaskSeparate(GLenum face, GLuint mask)                      {if (GLeeInit()) glStencilMaskSeparate(face, mask);}
void __stdcall _Lazy_glAttachShader(GLuint program, GLuint shader)                        {if (GLeeInit()) glAttachShader(program, shader);}
void __stdcall _Lazy_glBindAttribLocation(GLuint program, GLuint index, const GLchar * name)  {if (GLeeInit()) glBindAttribLocation(program, index, name);}
void __stdcall _Lazy_glCompileShader(GLuint shader)                                       {if (GLeeInit()) glCompileShader(shader);}
GLuint __stdcall _Lazy_glCreateProgram(void)                                              {if (GLeeInit()) return glCreateProgram(); return (GLuint)0;}
GLuint __stdcall _Lazy_glCreateShader(GLenum type)                                        {if (GLeeInit()) return glCreateShader(type); return (GLuint)0;}
void __stdcall _Lazy_glDeleteProgram(GLuint program)                                      {if (GLeeInit()) glDeleteProgram(program);}
void __stdcall _Lazy_glDeleteShader(GLuint shader)                                        {if (GLeeInit()) glDeleteShader(shader);}
void __stdcall _Lazy_glDetachShader(GLuint program, GLuint shader)                        {if (GLeeInit()) glDetachShader(program, shader);}
void __stdcall _Lazy_glDisableVertexAttribArray(GLuint index)                             {if (GLeeInit()) glDisableVertexAttribArray(index);}
void __stdcall _Lazy_glEnableVertexAttribArray(GLuint index)                              {if (GLeeInit()) glEnableVertexAttribArray(index);}
void __stdcall _Lazy_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name)  {if (GLeeInit()) glGetActiveAttrib(program, index, bufSize, length, size, type, name);}
void __stdcall _Lazy_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name)  {if (GLeeInit()) glGetActiveUniform(program, index, bufSize, length, size, type, name);}
void __stdcall _Lazy_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj)  {if (GLeeInit()) glGetAttachedShaders(program, maxCount, count, obj);}
GLint __stdcall _Lazy_glGetAttribLocation(GLuint program, const GLchar * name)            {if (GLeeInit()) return glGetAttribLocation(program, name); return (GLint)0;}
void __stdcall _Lazy_glGetProgramiv(GLuint program, GLenum pname, GLint * params)         {if (GLeeInit()) glGetProgramiv(program, pname, params);}
void __stdcall _Lazy_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog)  {if (GLeeInit()) glGetProgramInfoLog(program, bufSize, length, infoLog);}
void __stdcall _Lazy_glGetShaderiv(GLuint shader, GLenum pname, GLint * params)           {if (GLeeInit()) glGetShaderiv(shader, pname, params);}
void __stdcall _Lazy_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog)  {if (GLeeInit()) glGetShaderInfoLog(shader, bufSize, length, infoLog);}
void __stdcall _Lazy_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source)  {if (GLeeInit()) glGetShaderSource(shader, bufSize, length, source);}
GLint __stdcall _Lazy_glGetUniformLocation(GLuint program, const GLchar * name)           {if (GLeeInit()) return glGetUniformLocation(program, name); return (GLint)0;}
void __stdcall _Lazy_glGetUniformfv(GLuint program, GLint location, GLfloat * params)     {if (GLeeInit()) glGetUniformfv(program, location, params);}
void __stdcall _Lazy_glGetUniformiv(GLuint program, GLint location, GLint * params)       {if (GLeeInit()) glGetUniformiv(program, location, params);}
void __stdcall _Lazy_glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params)   {if (GLeeInit()) glGetVertexAttribdv(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params)    {if (GLeeInit()) glGetVertexAttribfv(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params)      {if (GLeeInit()) glGetVertexAttribiv(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid* * pointer)  {if (GLeeInit()) glGetVertexAttribPointerv(index, pname, pointer);}
GLboolean __stdcall _Lazy_glIsProgram(GLuint program)                                     {if (GLeeInit()) return glIsProgram(program); return (GLboolean)0;}
GLboolean __stdcall _Lazy_glIsShader(GLuint shader)                                       {if (GLeeInit()) return glIsShader(shader); return (GLboolean)0;}
void __stdcall _Lazy_glLinkProgram(GLuint program)                                        {if (GLeeInit()) glLinkProgram(program);}
void __stdcall _Lazy_glShaderSource(GLuint shader, GLsizei count, const GLchar* * string, const GLint * length)  {if (GLeeInit()) glShaderSource(shader, count, string, length);}
void __stdcall _Lazy_glUseProgram(GLuint program)                                         {if (GLeeInit()) glUseProgram(program);}
void __stdcall _Lazy_glUniform1f(GLint location, GLfloat v0)                              {if (GLeeInit()) glUniform1f(location, v0);}
void __stdcall _Lazy_glUniform2f(GLint location, GLfloat v0, GLfloat v1)                  {if (GLeeInit()) glUniform2f(location, v0, v1);}
void __stdcall _Lazy_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)      {if (GLeeInit()) glUniform3f(location, v0, v1, v2);}
void __stdcall _Lazy_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)  {if (GLeeInit()) glUniform4f(location, v0, v1, v2, v3);}
void __stdcall _Lazy_glUniform1i(GLint location, GLint v0)                                {if (GLeeInit()) glUniform1i(location, v0);}
void __stdcall _Lazy_glUniform2i(GLint location, GLint v0, GLint v1)                      {if (GLeeInit()) glUniform2i(location, v0, v1);}
void __stdcall _Lazy_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2)            {if (GLeeInit()) glUniform3i(location, v0, v1, v2);}
void __stdcall _Lazy_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)  {if (GLeeInit()) glUniform4i(location, v0, v1, v2, v3);}
void __stdcall _Lazy_glUniform1fv(GLint location, GLsizei count, const GLfloat * value)   {if (GLeeInit()) glUniform1fv(location, count, value);}
void __stdcall _Lazy_glUniform2fv(GLint location, GLsizei count, const GLfloat * value)   {if (GLeeInit()) glUniform2fv(location, count, value);}
void __stdcall _Lazy_glUniform3fv(GLint location, GLsizei count, const GLfloat * value)   {if (GLeeInit()) glUniform3fv(location, count, value);}
void __stdcall _Lazy_glUniform4fv(GLint location, GLsizei count, const GLfloat * value)   {if (GLeeInit()) glUniform4fv(location, count, value);}
void __stdcall _Lazy_glUniform1iv(GLint location, GLsizei count, const GLint * value)     {if (GLeeInit()) glUniform1iv(location, count, value);}
void __stdcall _Lazy_glUniform2iv(GLint location, GLsizei count, const GLint * value)     {if (GLeeInit()) glUniform2iv(location, count, value);}
void __stdcall _Lazy_glUniform3iv(GLint location, GLsizei count, const GLint * value)     {if (GLeeInit()) glUniform3iv(location, count, value);}
void __stdcall _Lazy_glUniform4iv(GLint location, GLsizei count, const GLint * value)     {if (GLeeInit()) glUniform4iv(location, count, value);}
void __stdcall _Lazy_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix2fv(location, count, transpose, value);}
void __stdcall _Lazy_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix3fv(location, count, transpose, value);}
void __stdcall _Lazy_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix4fv(location, count, transpose, value);}
void __stdcall _Lazy_glValidateProgram(GLuint program)                                    {if (GLeeInit()) glValidateProgram(program);}
void __stdcall _Lazy_glVertexAttrib1d(GLuint index, GLdouble x)                           {if (GLeeInit()) glVertexAttrib1d(index, x);}
void __stdcall _Lazy_glVertexAttrib1dv(GLuint index, const GLdouble * v)                  {if (GLeeInit()) glVertexAttrib1dv(index, v);}
void __stdcall _Lazy_glVertexAttrib1f(GLuint index, GLfloat x)                            {if (GLeeInit()) glVertexAttrib1f(index, x);}
void __stdcall _Lazy_glVertexAttrib1fv(GLuint index, const GLfloat * v)                   {if (GLeeInit()) glVertexAttrib1fv(index, v);}
void __stdcall _Lazy_glVertexAttrib1s(GLuint index, GLshort x)                            {if (GLeeInit()) glVertexAttrib1s(index, x);}
void __stdcall _Lazy_glVertexAttrib1sv(GLuint index, const GLshort * v)                   {if (GLeeInit()) glVertexAttrib1sv(index, v);}
void __stdcall _Lazy_glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y)               {if (GLeeInit()) glVertexAttrib2d(index, x, y);}
void __stdcall _Lazy_glVertexAttrib2dv(GLuint index, const GLdouble * v)                  {if (GLeeInit()) glVertexAttrib2dv(index, v);}
void __stdcall _Lazy_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y)                 {if (GLeeInit()) glVertexAttrib2f(index, x, y);}
void __stdcall _Lazy_glVertexAttrib2fv(GLuint index, const GLfloat * v)                   {if (GLeeInit()) glVertexAttrib2fv(index, v);}
void __stdcall _Lazy_glVertexAttrib2s(GLuint index, GLshort x, GLshort y)                 {if (GLeeInit()) glVertexAttrib2s(index, x, y);}
void __stdcall _Lazy_glVertexAttrib2sv(GLuint index, const GLshort * v)                   {if (GLeeInit()) glVertexAttrib2sv(index, v);}
void __stdcall _Lazy_glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)   {if (GLeeInit()) glVertexAttrib3d(index, x, y, z);}
void __stdcall _Lazy_glVertexAttrib3dv(GLuint index, const GLdouble * v)                  {if (GLeeInit()) glVertexAttrib3dv(index, v);}
void __stdcall _Lazy_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z)      {if (GLeeInit()) glVertexAttrib3f(index, x, y, z);}
void __stdcall _Lazy_glVertexAttrib3fv(GLuint index, const GLfloat * v)                   {if (GLeeInit()) glVertexAttrib3fv(index, v);}
void __stdcall _Lazy_glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z)      {if (GLeeInit()) glVertexAttrib3s(index, x, y, z);}
void __stdcall _Lazy_glVertexAttrib3sv(GLuint index, const GLshort * v)                   {if (GLeeInit()) glVertexAttrib3sv(index, v);}
void __stdcall _Lazy_glVertexAttrib4Nbv(GLuint index, const GLbyte * v)                   {if (GLeeInit()) glVertexAttrib4Nbv(index, v);}
void __stdcall _Lazy_glVertexAttrib4Niv(GLuint index, const GLint * v)                    {if (GLeeInit()) glVertexAttrib4Niv(index, v);}
void __stdcall _Lazy_glVertexAttrib4Nsv(GLuint index, const GLshort * v)                  {if (GLeeInit()) glVertexAttrib4Nsv(index, v);}
void __stdcall _Lazy_glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)  {if (GLeeInit()) glVertexAttrib4Nub(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4Nubv(GLuint index, const GLubyte * v)                 {if (GLeeInit()) glVertexAttrib4Nubv(index, v);}
void __stdcall _Lazy_glVertexAttrib4Nuiv(GLuint index, const GLuint * v)                  {if (GLeeInit()) glVertexAttrib4Nuiv(index, v);}
void __stdcall _Lazy_glVertexAttrib4Nusv(GLuint index, const GLushort * v)                {if (GLeeInit()) glVertexAttrib4Nusv(index, v);}
void __stdcall _Lazy_glVertexAttrib4bv(GLuint index, const GLbyte * v)                    {if (GLeeInit()) glVertexAttrib4bv(index, v);}
void __stdcall _Lazy_glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)  {if (GLeeInit()) glVertexAttrib4d(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4dv(GLuint index, const GLdouble * v)                  {if (GLeeInit()) glVertexAttrib4dv(index, v);}
void __stdcall _Lazy_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)  {if (GLeeInit()) glVertexAttrib4f(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4fv(GLuint index, const GLfloat * v)                   {if (GLeeInit()) glVertexAttrib4fv(index, v);}
void __stdcall _Lazy_glVertexAttrib4iv(GLuint index, const GLint * v)                     {if (GLeeInit()) glVertexAttrib4iv(index, v);}
void __stdcall _Lazy_glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)  {if (GLeeInit()) glVertexAttrib4s(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4sv(GLuint index, const GLshort * v)                   {if (GLeeInit()) glVertexAttrib4sv(index, v);}
void __stdcall _Lazy_glVertexAttrib4ubv(GLuint index, const GLubyte * v)                  {if (GLeeInit()) glVertexAttrib4ubv(index, v);}
void __stdcall _Lazy_glVertexAttrib4uiv(GLuint index, const GLuint * v)                   {if (GLeeInit()) glVertexAttrib4uiv(index, v);}
void __stdcall _Lazy_glVertexAttrib4usv(GLuint index, const GLushort * v)                 {if (GLeeInit()) glVertexAttrib4usv(index, v);}
void __stdcall _Lazy_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glVertexAttribPointer(index, size, type, normalized, stride, pointer);}
PFNGLBLENDEQUATIONSEPARATEPROC pglBlendEquationSeparate=_Lazy_glBlendEquationSeparate;
PFNGLDRAWBUFFERSPROC pglDrawBuffers=_Lazy_glDrawBuffers;
PFNGLSTENCILOPSEPARATEPROC pglStencilOpSeparate=_Lazy_glStencilOpSeparate;
PFNGLSTENCILFUNCSEPARATEPROC pglStencilFuncSeparate=_Lazy_glStencilFuncSeparate;
PFNGLSTENCILMASKSEPARATEPROC pglStencilMaskSeparate=_Lazy_glStencilMaskSeparate;
PFNGLATTACHSHADERPROC pglAttachShader=_Lazy_glAttachShader;
PFNGLBINDATTRIBLOCATIONPROC pglBindAttribLocation=_Lazy_glBindAttribLocation;
PFNGLCOMPILESHADERPROC pglCompileShader=_Lazy_glCompileShader;
PFNGLCREATEPROGRAMPROC pglCreateProgram=_Lazy_glCreateProgram;
PFNGLCREATESHADERPROC pglCreateShader=_Lazy_glCreateShader;
PFNGLDELETEPROGRAMPROC pglDeleteProgram=_Lazy_glDeleteProgram;
PFNGLDELETESHADERPROC pglDeleteShader=_Lazy_glDeleteShader;
PFNGLDETACHSHADERPROC pglDetachShader=_Lazy_glDetachShader;
PFNGLDISABLEVERTEXATTRIBARRAYPROC pglDisableVertexAttribArray=_Lazy_glDisableVertexAttribArray;
PFNGLENABLEVERTEXATTRIBARRAYPROC pglEnableVertexAttribArray=_Lazy_glEnableVertexAttribArray;
PFNGLGETACTIVEATTRIBPROC pglGetActiveAttrib=_Lazy_glGetActiveAttrib;
PFNGLGETACTIVEUNIFORMPROC pglGetActiveUniform=_Lazy_glGetActiveUniform;
PFNGLGETATTACHEDSHADERSPROC pglGetAttachedShaders=_Lazy_glGetAttachedShaders;
PFNGLGETATTRIBLOCATIONPROC pglGetAttribLocation=_Lazy_glGetAttribLocation;
PFNGLGETPROGRAMIVPROC pglGetProgramiv=_Lazy_glGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC pglGetProgramInfoLog=_Lazy_glGetProgramInfoLog;
PFNGLGETSHADERIVPROC pglGetShaderiv=_Lazy_glGetShaderiv;
PFNGLGETSHADERINFOLOGPROC pglGetShaderInfoLog=_Lazy_glGetShaderInfoLog;
PFNGLGETSHADERSOURCEPROC pglGetShaderSource=_Lazy_glGetShaderSource;
PFNGLGETUNIFORMLOCATIONPROC pglGetUniformLocation=_Lazy_glGetUniformLocation;
PFNGLGETUNIFORMFVPROC pglGetUniformfv=_Lazy_glGetUniformfv;
PFNGLGETUNIFORMIVPROC pglGetUniformiv=_Lazy_glGetUniformiv;
PFNGLGETVERTEXATTRIBDVPROC pglGetVertexAttribdv=_Lazy_glGetVertexAttribdv;
PFNGLGETVERTEXATTRIBFVPROC pglGetVertexAttribfv=_Lazy_glGetVertexAttribfv;
PFNGLGETVERTEXATTRIBIVPROC pglGetVertexAttribiv=_Lazy_glGetVertexAttribiv;
PFNGLGETVERTEXATTRIBPOINTERVPROC pglGetVertexAttribPointerv=_Lazy_glGetVertexAttribPointerv;
PFNGLISPROGRAMPROC pglIsProgram=_Lazy_glIsProgram;
PFNGLISSHADERPROC pglIsShader=_Lazy_glIsShader;
PFNGLLINKPROGRAMPROC pglLinkProgram=_Lazy_glLinkProgram;
PFNGLSHADERSOURCEPROC pglShaderSource=_Lazy_glShaderSource;
PFNGLUSEPROGRAMPROC pglUseProgram=_Lazy_glUseProgram;
PFNGLUNIFORM1FPROC pglUniform1f=_Lazy_glUniform1f;
PFNGLUNIFORM2FPROC pglUniform2f=_Lazy_glUniform2f;
PFNGLUNIFORM3FPROC pglUniform3f=_Lazy_glUniform3f;
PFNGLUNIFORM4FPROC pglUniform4f=_Lazy_glUniform4f;
PFNGLUNIFORM1IPROC pglUniform1i=_Lazy_glUniform1i;
PFNGLUNIFORM2IPROC pglUniform2i=_Lazy_glUniform2i;
PFNGLUNIFORM3IPROC pglUniform3i=_Lazy_glUniform3i;
PFNGLUNIFORM4IPROC pglUniform4i=_Lazy_glUniform4i;
PFNGLUNIFORM1FVPROC pglUniform1fv=_Lazy_glUniform1fv;
PFNGLUNIFORM2FVPROC pglUniform2fv=_Lazy_glUniform2fv;
PFNGLUNIFORM3FVPROC pglUniform3fv=_Lazy_glUniform3fv;
PFNGLUNIFORM4FVPROC pglUniform4fv=_Lazy_glUniform4fv;
PFNGLUNIFORM1IVPROC pglUniform1iv=_Lazy_glUniform1iv;
PFNGLUNIFORM2IVPROC pglUniform2iv=_Lazy_glUniform2iv;
PFNGLUNIFORM3IVPROC pglUniform3iv=_Lazy_glUniform3iv;
PFNGLUNIFORM4IVPROC pglUniform4iv=_Lazy_glUniform4iv;
PFNGLUNIFORMMATRIX2FVPROC pglUniformMatrix2fv=_Lazy_glUniformMatrix2fv;
PFNGLUNIFORMMATRIX3FVPROC pglUniformMatrix3fv=_Lazy_glUniformMatrix3fv;
PFNGLUNIFORMMATRIX4FVPROC pglUniformMatrix4fv=_Lazy_glUniformMatrix4fv;
PFNGLVALIDATEPROGRAMPROC pglValidateProgram=_Lazy_glValidateProgram;
PFNGLVERTEXATTRIB1DPROC pglVertexAttrib1d=_Lazy_glVertexAttrib1d;
PFNGLVERTEXATTRIB1DVPROC pglVertexAttrib1dv=_Lazy_glVertexAttrib1dv;
PFNGLVERTEXATTRIB1FPROC pglVertexAttrib1f=_Lazy_glVertexAttrib1f;
PFNGLVERTEXATTRIB1FVPROC pglVertexAttrib1fv=_Lazy_glVertexAttrib1fv;
PFNGLVERTEXATTRIB1SPROC pglVertexAttrib1s=_Lazy_glVertexAttrib1s;
PFNGLVERTEXATTRIB1SVPROC pglVertexAttrib1sv=_Lazy_glVertexAttrib1sv;
PFNGLVERTEXATTRIB2DPROC pglVertexAttrib2d=_Lazy_glVertexAttrib2d;
PFNGLVERTEXATTRIB2DVPROC pglVertexAttrib2dv=_Lazy_glVertexAttrib2dv;
PFNGLVERTEXATTRIB2FPROC pglVertexAttrib2f=_Lazy_glVertexAttrib2f;
PFNGLVERTEXATTRIB2FVPROC pglVertexAttrib2fv=_Lazy_glVertexAttrib2fv;
PFNGLVERTEXATTRIB2SPROC pglVertexAttrib2s=_Lazy_glVertexAttrib2s;
PFNGLVERTEXATTRIB2SVPROC pglVertexAttrib2sv=_Lazy_glVertexAttrib2sv;
PFNGLVERTEXATTRIB3DPROC pglVertexAttrib3d=_Lazy_glVertexAttrib3d;
PFNGLVERTEXATTRIB3DVPROC pglVertexAttrib3dv=_Lazy_glVertexAttrib3dv;
PFNGLVERTEXATTRIB3FPROC pglVertexAttrib3f=_Lazy_glVertexAttrib3f;
PFNGLVERTEXATTRIB3FVPROC pglVertexAttrib3fv=_Lazy_glVertexAttrib3fv;
PFNGLVERTEXATTRIB3SPROC pglVertexAttrib3s=_Lazy_glVertexAttrib3s;
PFNGLVERTEXATTRIB3SVPROC pglVertexAttrib3sv=_Lazy_glVertexAttrib3sv;
PFNGLVERTEXATTRIB4NBVPROC pglVertexAttrib4Nbv=_Lazy_glVertexAttrib4Nbv;
PFNGLVERTEXATTRIB4NIVPROC pglVertexAttrib4Niv=_Lazy_glVertexAttrib4Niv;
PFNGLVERTEXATTRIB4NSVPROC pglVertexAttrib4Nsv=_Lazy_glVertexAttrib4Nsv;
PFNGLVERTEXATTRIB4NUBPROC pglVertexAttrib4Nub=_Lazy_glVertexAttrib4Nub;
PFNGLVERTEXATTRIB4NUBVPROC pglVertexAttrib4Nubv=_Lazy_glVertexAttrib4Nubv;
PFNGLVERTEXATTRIB4NUIVPROC pglVertexAttrib4Nuiv=_Lazy_glVertexAttrib4Nuiv;
PFNGLVERTEXATTRIB4NUSVPROC pglVertexAttrib4Nusv=_Lazy_glVertexAttrib4Nusv;
PFNGLVERTEXATTRIB4BVPROC pglVertexAttrib4bv=_Lazy_glVertexAttrib4bv;
PFNGLVERTEXATTRIB4DPROC pglVertexAttrib4d=_Lazy_glVertexAttrib4d;
PFNGLVERTEXATTRIB4DVPROC pglVertexAttrib4dv=_Lazy_glVertexAttrib4dv;
PFNGLVERTEXATTRIB4FPROC pglVertexAttrib4f=_Lazy_glVertexAttrib4f;
PFNGLVERTEXATTRIB4FVPROC pglVertexAttrib4fv=_Lazy_glVertexAttrib4fv;
PFNGLVERTEXATTRIB4IVPROC pglVertexAttrib4iv=_Lazy_glVertexAttrib4iv;
PFNGLVERTEXATTRIB4SPROC pglVertexAttrib4s=_Lazy_glVertexAttrib4s;
PFNGLVERTEXATTRIB4SVPROC pglVertexAttrib4sv=_Lazy_glVertexAttrib4sv;
PFNGLVERTEXATTRIB4UBVPROC pglVertexAttrib4ubv=_Lazy_glVertexAttrib4ubv;
PFNGLVERTEXATTRIB4UIVPROC pglVertexAttrib4uiv=_Lazy_glVertexAttrib4uiv;
PFNGLVERTEXATTRIB4USVPROC pglVertexAttrib4usv=_Lazy_glVertexAttrib4usv;
PFNGLVERTEXATTRIBPOINTERPROC pglVertexAttribPointer=_Lazy_glVertexAttribPointer;
#endif 

/* GL_VERSION_2_1 */

#ifdef __GLEE_GL_VERSION_2_1
void __stdcall _Lazy_glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix2x3fv(location, count, transpose, value);}
void __stdcall _Lazy_glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix3x2fv(location, count, transpose, value);}
void __stdcall _Lazy_glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix2x4fv(location, count, transpose, value);}
void __stdcall _Lazy_glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix4x2fv(location, count, transpose, value);}
void __stdcall _Lazy_glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix3x4fv(location, count, transpose, value);}
void __stdcall _Lazy_glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix4x3fv(location, count, transpose, value);}
PFNGLUNIFORMMATRIX2X3FVPROC pglUniformMatrix2x3fv=_Lazy_glUniformMatrix2x3fv;
PFNGLUNIFORMMATRIX3X2FVPROC pglUniformMatrix3x2fv=_Lazy_glUniformMatrix3x2fv;
PFNGLUNIFORMMATRIX2X4FVPROC pglUniformMatrix2x4fv=_Lazy_glUniformMatrix2x4fv;
PFNGLUNIFORMMATRIX4X2FVPROC pglUniformMatrix4x2fv=_Lazy_glUniformMatrix4x2fv;
PFNGLUNIFORMMATRIX3X4FVPROC pglUniformMatrix3x4fv=_Lazy_glUniformMatrix3x4fv;
PFNGLUNIFORMMATRIX4X3FVPROC pglUniformMatrix4x3fv=_Lazy_glUniformMatrix4x3fv;
#endif 

/* GL_ARB_multitexture */

#ifdef __GLEE_GL_ARB_multitexture
void __stdcall _Lazy_glActiveTextureARB(GLenum texture)                                   {if (GLeeInit()) glActiveTextureARB(texture);}
void __stdcall _Lazy_glClientActiveTextureARB(GLenum texture)                             {if (GLeeInit()) glClientActiveTextureARB(texture);}
void __stdcall _Lazy_glMultiTexCoord1dARB(GLenum target, GLdouble s)                      {if (GLeeInit()) glMultiTexCoord1dARB(target, s);}
void __stdcall _Lazy_glMultiTexCoord1dvARB(GLenum target, const GLdouble * v)             {if (GLeeInit()) glMultiTexCoord1dvARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord1fARB(GLenum target, GLfloat s)                       {if (GLeeInit()) glMultiTexCoord1fARB(target, s);}
void __stdcall _Lazy_glMultiTexCoord1fvARB(GLenum target, const GLfloat * v)              {if (GLeeInit()) glMultiTexCoord1fvARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord1iARB(GLenum target, GLint s)                         {if (GLeeInit()) glMultiTexCoord1iARB(target, s);}
void __stdcall _Lazy_glMultiTexCoord1ivARB(GLenum target, const GLint * v)                {if (GLeeInit()) glMultiTexCoord1ivARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord1sARB(GLenum target, GLshort s)                       {if (GLeeInit()) glMultiTexCoord1sARB(target, s);}
void __stdcall _Lazy_glMultiTexCoord1svARB(GLenum target, const GLshort * v)              {if (GLeeInit()) glMultiTexCoord1svARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t)          {if (GLeeInit()) glMultiTexCoord2dARB(target, s, t);}
void __stdcall _Lazy_glMultiTexCoord2dvARB(GLenum target, const GLdouble * v)             {if (GLeeInit()) glMultiTexCoord2dvARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t)            {if (GLeeInit()) glMultiTexCoord2fARB(target, s, t);}
void __stdcall _Lazy_glMultiTexCoord2fvARB(GLenum target, const GLfloat * v)              {if (GLeeInit()) glMultiTexCoord2fvARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord2iARB(GLenum target, GLint s, GLint t)                {if (GLeeInit()) glMultiTexCoord2iARB(target, s, t);}
void __stdcall _Lazy_glMultiTexCoord2ivARB(GLenum target, const GLint * v)                {if (GLeeInit()) glMultiTexCoord2ivARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t)            {if (GLeeInit()) glMultiTexCoord2sARB(target, s, t);}
void __stdcall _Lazy_glMultiTexCoord2svARB(GLenum target, const GLshort * v)              {if (GLeeInit()) glMultiTexCoord2svARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r)  {if (GLeeInit()) glMultiTexCoord3dARB(target, s, t, r);}
void __stdcall _Lazy_glMultiTexCoord3dvARB(GLenum target, const GLdouble * v)             {if (GLeeInit()) glMultiTexCoord3dvARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r)  {if (GLeeInit()) glMultiTexCoord3fARB(target, s, t, r);}
void __stdcall _Lazy_glMultiTexCoord3fvARB(GLenum target, const GLfloat * v)              {if (GLeeInit()) glMultiTexCoord3fvARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r)       {if (GLeeInit()) glMultiTexCoord3iARB(target, s, t, r);}
void __stdcall _Lazy_glMultiTexCoord3ivARB(GLenum target, const GLint * v)                {if (GLeeInit()) glMultiTexCoord3ivARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r)  {if (GLeeInit()) glMultiTexCoord3sARB(target, s, t, r);}
void __stdcall _Lazy_glMultiTexCoord3svARB(GLenum target, const GLshort * v)              {if (GLeeInit()) glMultiTexCoord3svARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)  {if (GLeeInit()) glMultiTexCoord4dARB(target, s, t, r, q);}
void __stdcall _Lazy_glMultiTexCoord4dvARB(GLenum target, const GLdouble * v)             {if (GLeeInit()) glMultiTexCoord4dvARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)  {if (GLeeInit()) glMultiTexCoord4fARB(target, s, t, r, q);}
void __stdcall _Lazy_glMultiTexCoord4fvARB(GLenum target, const GLfloat * v)              {if (GLeeInit()) glMultiTexCoord4fvARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q)  {if (GLeeInit()) glMultiTexCoord4iARB(target, s, t, r, q);}
void __stdcall _Lazy_glMultiTexCoord4ivARB(GLenum target, const GLint * v)                {if (GLeeInit()) glMultiTexCoord4ivARB(target, v);}
void __stdcall _Lazy_glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)  {if (GLeeInit()) glMultiTexCoord4sARB(target, s, t, r, q);}
void __stdcall _Lazy_glMultiTexCoord4svARB(GLenum target, const GLshort * v)              {if (GLeeInit()) glMultiTexCoord4svARB(target, v);}
PFNGLACTIVETEXTUREARBPROC pglActiveTextureARB=_Lazy_glActiveTextureARB;
PFNGLCLIENTACTIVETEXTUREARBPROC pglClientActiveTextureARB=_Lazy_glClientActiveTextureARB;
PFNGLMULTITEXCOORD1DARBPROC pglMultiTexCoord1dARB=_Lazy_glMultiTexCoord1dARB;
PFNGLMULTITEXCOORD1DVARBPROC pglMultiTexCoord1dvARB=_Lazy_glMultiTexCoord1dvARB;
PFNGLMULTITEXCOORD1FARBPROC pglMultiTexCoord1fARB=_Lazy_glMultiTexCoord1fARB;
PFNGLMULTITEXCOORD1FVARBPROC pglMultiTexCoord1fvARB=_Lazy_glMultiTexCoord1fvARB;
PFNGLMULTITEXCOORD1IARBPROC pglMultiTexCoord1iARB=_Lazy_glMultiTexCoord1iARB;
PFNGLMULTITEXCOORD1IVARBPROC pglMultiTexCoord1ivARB=_Lazy_glMultiTexCoord1ivARB;
PFNGLMULTITEXCOORD1SARBPROC pglMultiTexCoord1sARB=_Lazy_glMultiTexCoord1sARB;
PFNGLMULTITEXCOORD1SVARBPROC pglMultiTexCoord1svARB=_Lazy_glMultiTexCoord1svARB;
PFNGLMULTITEXCOORD2DARBPROC pglMultiTexCoord2dARB=_Lazy_glMultiTexCoord2dARB;
PFNGLMULTITEXCOORD2DVARBPROC pglMultiTexCoord2dvARB=_Lazy_glMultiTexCoord2dvARB;
PFNGLMULTITEXCOORD2FARBPROC pglMultiTexCoord2fARB=_Lazy_glMultiTexCoord2fARB;
PFNGLMULTITEXCOORD2FVARBPROC pglMultiTexCoord2fvARB=_Lazy_glMultiTexCoord2fvARB;
PFNGLMULTITEXCOORD2IARBPROC pglMultiTexCoord2iARB=_Lazy_glMultiTexCoord2iARB;
PFNGLMULTITEXCOORD2IVARBPROC pglMultiTexCoord2ivARB=_Lazy_glMultiTexCoord2ivARB;
PFNGLMULTITEXCOORD2SARBPROC pglMultiTexCoord2sARB=_Lazy_glMultiTexCoord2sARB;
PFNGLMULTITEXCOORD2SVARBPROC pglMultiTexCoord2svARB=_Lazy_glMultiTexCoord2svARB;
PFNGLMULTITEXCOORD3DARBPROC pglMultiTexCoord3dARB=_Lazy_glMultiTexCoord3dARB;
PFNGLMULTITEXCOORD3DVARBPROC pglMultiTexCoord3dvARB=_Lazy_glMultiTexCoord3dvARB;
PFNGLMULTITEXCOORD3FARBPROC pglMultiTexCoord3fARB=_Lazy_glMultiTexCoord3fARB;
PFNGLMULTITEXCOORD3FVARBPROC pglMultiTexCoord3fvARB=_Lazy_glMultiTexCoord3fvARB;
PFNGLMULTITEXCOORD3IARBPROC pglMultiTexCoord3iARB=_Lazy_glMultiTexCoord3iARB;
PFNGLMULTITEXCOORD3IVARBPROC pglMultiTexCoord3ivARB=_Lazy_glMultiTexCoord3ivARB;
PFNGLMULTITEXCOORD3SARBPROC pglMultiTexCoord3sARB=_Lazy_glMultiTexCoord3sARB;
PFNGLMULTITEXCOORD3SVARBPROC pglMultiTexCoord3svARB=_Lazy_glMultiTexCoord3svARB;
PFNGLMULTITEXCOORD4DARBPROC pglMultiTexCoord4dARB=_Lazy_glMultiTexCoord4dARB;
PFNGLMULTITEXCOORD4DVARBPROC pglMultiTexCoord4dvARB=_Lazy_glMultiTexCoord4dvARB;
PFNGLMULTITEXCOORD4FARBPROC pglMultiTexCoord4fARB=_Lazy_glMultiTexCoord4fARB;
PFNGLMULTITEXCOORD4FVARBPROC pglMultiTexCoord4fvARB=_Lazy_glMultiTexCoord4fvARB;
PFNGLMULTITEXCOORD4IARBPROC pglMultiTexCoord4iARB=_Lazy_glMultiTexCoord4iARB;
PFNGLMULTITEXCOORD4IVARBPROC pglMultiTexCoord4ivARB=_Lazy_glMultiTexCoord4ivARB;
PFNGLMULTITEXCOORD4SARBPROC pglMultiTexCoord4sARB=_Lazy_glMultiTexCoord4sARB;
PFNGLMULTITEXCOORD4SVARBPROC pglMultiTexCoord4svARB=_Lazy_glMultiTexCoord4svARB;
#endif 

/* GL_ARB_transpose_matrix */

#ifdef __GLEE_GL_ARB_transpose_matrix
void __stdcall _Lazy_glLoadTransposeMatrixfARB(const GLfloat * m)                         {if (GLeeInit()) glLoadTransposeMatrixfARB(m);}
void __stdcall _Lazy_glLoadTransposeMatrixdARB(const GLdouble * m)                        {if (GLeeInit()) glLoadTransposeMatrixdARB(m);}
void __stdcall _Lazy_glMultTransposeMatrixfARB(const GLfloat * m)                         {if (GLeeInit()) glMultTransposeMatrixfARB(m);}
void __stdcall _Lazy_glMultTransposeMatrixdARB(const GLdouble * m)                        {if (GLeeInit()) glMultTransposeMatrixdARB(m);}
PFNGLLOADTRANSPOSEMATRIXFARBPROC pglLoadTransposeMatrixfARB=_Lazy_glLoadTransposeMatrixfARB;
PFNGLLOADTRANSPOSEMATRIXDARBPROC pglLoadTransposeMatrixdARB=_Lazy_glLoadTransposeMatrixdARB;
PFNGLMULTTRANSPOSEMATRIXFARBPROC pglMultTransposeMatrixfARB=_Lazy_glMultTransposeMatrixfARB;
PFNGLMULTTRANSPOSEMATRIXDARBPROC pglMultTransposeMatrixdARB=_Lazy_glMultTransposeMatrixdARB;
#endif 

/* GL_ARB_multisample */

#ifdef __GLEE_GL_ARB_multisample
void __stdcall _Lazy_glSampleCoverageARB(GLclampf value, GLboolean invert)                {if (GLeeInit()) glSampleCoverageARB(value, invert);}
PFNGLSAMPLECOVERAGEARBPROC pglSampleCoverageARB=_Lazy_glSampleCoverageARB;
#endif 

/* GL_ARB_texture_env_add */

#ifdef __GLEE_GL_ARB_texture_env_add
#endif 

/* GL_ARB_texture_cube_map */

#ifdef __GLEE_GL_ARB_texture_cube_map
#endif 

/* GL_ARB_texture_compression */

#ifdef __GLEE_GL_ARB_texture_compression
void __stdcall _Lazy_glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexImage3DARB(target, level, internalformat, width, height, depth, border, imageSize, data);}
void __stdcall _Lazy_glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexImage2DARB(target, level, internalformat, width, height, border, imageSize, data);}
void __stdcall _Lazy_glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexImage1DARB(target, level, internalformat, width, border, imageSize, data);}
void __stdcall _Lazy_glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexSubImage3DARB(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);}
void __stdcall _Lazy_glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexSubImage2DARB(target, level, xoffset, yoffset, width, height, format, imageSize, data);}
void __stdcall _Lazy_glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data)  {if (GLeeInit()) glCompressedTexSubImage1DARB(target, level, xoffset, width, format, imageSize, data);}
void __stdcall _Lazy_glGetCompressedTexImageARB(GLenum target, GLint level, GLvoid * img)  {if (GLeeInit()) glGetCompressedTexImageARB(target, level, img);}
PFNGLCOMPRESSEDTEXIMAGE3DARBPROC pglCompressedTexImage3DARB=_Lazy_glCompressedTexImage3DARB;
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC pglCompressedTexImage2DARB=_Lazy_glCompressedTexImage2DARB;
PFNGLCOMPRESSEDTEXIMAGE1DARBPROC pglCompressedTexImage1DARB=_Lazy_glCompressedTexImage1DARB;
PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC pglCompressedTexSubImage3DARB=_Lazy_glCompressedTexSubImage3DARB;
PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC pglCompressedTexSubImage2DARB=_Lazy_glCompressedTexSubImage2DARB;
PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC pglCompressedTexSubImage1DARB=_Lazy_glCompressedTexSubImage1DARB;
PFNGLGETCOMPRESSEDTEXIMAGEARBPROC pglGetCompressedTexImageARB=_Lazy_glGetCompressedTexImageARB;
#endif 

/* GL_ARB_texture_border_clamp */

#ifdef __GLEE_GL_ARB_texture_border_clamp
#endif 

/* GL_ARB_point_parameters */

#ifdef __GLEE_GL_ARB_point_parameters
void __stdcall _Lazy_glPointParameterfARB(GLenum pname, GLfloat param)                    {if (GLeeInit()) glPointParameterfARB(pname, param);}
void __stdcall _Lazy_glPointParameterfvARB(GLenum pname, const GLfloat * params)          {if (GLeeInit()) glPointParameterfvARB(pname, params);}
PFNGLPOINTPARAMETERFARBPROC pglPointParameterfARB=_Lazy_glPointParameterfARB;
PFNGLPOINTPARAMETERFVARBPROC pglPointParameterfvARB=_Lazy_glPointParameterfvARB;
#endif 

/* GL_ARB_vertex_blend */

#ifdef __GLEE_GL_ARB_vertex_blend
void __stdcall _Lazy_glWeightbvARB(GLint size, const GLbyte * weights)                    {if (GLeeInit()) glWeightbvARB(size, weights);}
void __stdcall _Lazy_glWeightsvARB(GLint size, const GLshort * weights)                   {if (GLeeInit()) glWeightsvARB(size, weights);}
void __stdcall _Lazy_glWeightivARB(GLint size, const GLint * weights)                     {if (GLeeInit()) glWeightivARB(size, weights);}
void __stdcall _Lazy_glWeightfvARB(GLint size, const GLfloat * weights)                   {if (GLeeInit()) glWeightfvARB(size, weights);}
void __stdcall _Lazy_glWeightdvARB(GLint size, const GLdouble * weights)                  {if (GLeeInit()) glWeightdvARB(size, weights);}
void __stdcall _Lazy_glWeightubvARB(GLint size, const GLubyte * weights)                  {if (GLeeInit()) glWeightubvARB(size, weights);}
void __stdcall _Lazy_glWeightusvARB(GLint size, const GLushort * weights)                 {if (GLeeInit()) glWeightusvARB(size, weights);}
void __stdcall _Lazy_glWeightuivARB(GLint size, const GLuint * weights)                   {if (GLeeInit()) glWeightuivARB(size, weights);}
void __stdcall _Lazy_glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glWeightPointerARB(size, type, stride, pointer);}
void __stdcall _Lazy_glVertexBlendARB(GLint count)                                        {if (GLeeInit()) glVertexBlendARB(count);}
PFNGLWEIGHTBVARBPROC pglWeightbvARB=_Lazy_glWeightbvARB;
PFNGLWEIGHTSVARBPROC pglWeightsvARB=_Lazy_glWeightsvARB;
PFNGLWEIGHTIVARBPROC pglWeightivARB=_Lazy_glWeightivARB;
PFNGLWEIGHTFVARBPROC pglWeightfvARB=_Lazy_glWeightfvARB;
PFNGLWEIGHTDVARBPROC pglWeightdvARB=_Lazy_glWeightdvARB;
PFNGLWEIGHTUBVARBPROC pglWeightubvARB=_Lazy_glWeightubvARB;
PFNGLWEIGHTUSVARBPROC pglWeightusvARB=_Lazy_glWeightusvARB;
PFNGLWEIGHTUIVARBPROC pglWeightuivARB=_Lazy_glWeightuivARB;
PFNGLWEIGHTPOINTERARBPROC pglWeightPointerARB=_Lazy_glWeightPointerARB;
PFNGLVERTEXBLENDARBPROC pglVertexBlendARB=_Lazy_glVertexBlendARB;
#endif 

/* GL_ARB_matrix_palette */

#ifdef __GLEE_GL_ARB_matrix_palette
void __stdcall _Lazy_glCurrentPaletteMatrixARB(GLint index)                               {if (GLeeInit()) glCurrentPaletteMatrixARB(index);}
void __stdcall _Lazy_glMatrixIndexubvARB(GLint size, const GLubyte * indices)             {if (GLeeInit()) glMatrixIndexubvARB(size, indices);}
void __stdcall _Lazy_glMatrixIndexusvARB(GLint size, const GLushort * indices)            {if (GLeeInit()) glMatrixIndexusvARB(size, indices);}
void __stdcall _Lazy_glMatrixIndexuivARB(GLint size, const GLuint * indices)              {if (GLeeInit()) glMatrixIndexuivARB(size, indices);}
void __stdcall _Lazy_glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glMatrixIndexPointerARB(size, type, stride, pointer);}
PFNGLCURRENTPALETTEMATRIXARBPROC pglCurrentPaletteMatrixARB=_Lazy_glCurrentPaletteMatrixARB;
PFNGLMATRIXINDEXUBVARBPROC pglMatrixIndexubvARB=_Lazy_glMatrixIndexubvARB;
PFNGLMATRIXINDEXUSVARBPROC pglMatrixIndexusvARB=_Lazy_glMatrixIndexusvARB;
PFNGLMATRIXINDEXUIVARBPROC pglMatrixIndexuivARB=_Lazy_glMatrixIndexuivARB;
PFNGLMATRIXINDEXPOINTERARBPROC pglMatrixIndexPointerARB=_Lazy_glMatrixIndexPointerARB;
#endif 

/* GL_ARB_texture_env_combine */

#ifdef __GLEE_GL_ARB_texture_env_combine
#endif 

/* GL_ARB_texture_env_crossbar */

#ifdef __GLEE_GL_ARB_texture_env_crossbar
#endif 

/* GL_ARB_texture_env_dot3 */

#ifdef __GLEE_GL_ARB_texture_env_dot3
#endif 

/* GL_ARB_texture_mirrored_repeat */

#ifdef __GLEE_GL_ARB_texture_mirrored_repeat
#endif 

/* GL_ARB_depth_texture */

#ifdef __GLEE_GL_ARB_depth_texture
#endif 

/* GL_ARB_shadow */

#ifdef __GLEE_GL_ARB_shadow
#endif 

/* GL_ARB_shadow_ambient */

#ifdef __GLEE_GL_ARB_shadow_ambient
#endif 

/* GL_ARB_window_pos */

#ifdef __GLEE_GL_ARB_window_pos
void __stdcall _Lazy_glWindowPos2dARB(GLdouble x, GLdouble y)                             {if (GLeeInit()) glWindowPos2dARB(x, y);}
void __stdcall _Lazy_glWindowPos2dvARB(const GLdouble * v)                                {if (GLeeInit()) glWindowPos2dvARB(v);}
void __stdcall _Lazy_glWindowPos2fARB(GLfloat x, GLfloat y)                               {if (GLeeInit()) glWindowPos2fARB(x, y);}
void __stdcall _Lazy_glWindowPos2fvARB(const GLfloat * v)                                 {if (GLeeInit()) glWindowPos2fvARB(v);}
void __stdcall _Lazy_glWindowPos2iARB(GLint x, GLint y)                                   {if (GLeeInit()) glWindowPos2iARB(x, y);}
void __stdcall _Lazy_glWindowPos2ivARB(const GLint * v)                                   {if (GLeeInit()) glWindowPos2ivARB(v);}
void __stdcall _Lazy_glWindowPos2sARB(GLshort x, GLshort y)                               {if (GLeeInit()) glWindowPos2sARB(x, y);}
void __stdcall _Lazy_glWindowPos2svARB(const GLshort * v)                                 {if (GLeeInit()) glWindowPos2svARB(v);}
void __stdcall _Lazy_glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z)                 {if (GLeeInit()) glWindowPos3dARB(x, y, z);}
void __stdcall _Lazy_glWindowPos3dvARB(const GLdouble * v)                                {if (GLeeInit()) glWindowPos3dvARB(v);}
void __stdcall _Lazy_glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z)                    {if (GLeeInit()) glWindowPos3fARB(x, y, z);}
void __stdcall _Lazy_glWindowPos3fvARB(const GLfloat * v)                                 {if (GLeeInit()) glWindowPos3fvARB(v);}
void __stdcall _Lazy_glWindowPos3iARB(GLint x, GLint y, GLint z)                          {if (GLeeInit()) glWindowPos3iARB(x, y, z);}
void __stdcall _Lazy_glWindowPos3ivARB(const GLint * v)                                   {if (GLeeInit()) glWindowPos3ivARB(v);}
void __stdcall _Lazy_glWindowPos3sARB(GLshort x, GLshort y, GLshort z)                    {if (GLeeInit()) glWindowPos3sARB(x, y, z);}
void __stdcall _Lazy_glWindowPos3svARB(const GLshort * v)                                 {if (GLeeInit()) glWindowPos3svARB(v);}
PFNGLWINDOWPOS2DARBPROC pglWindowPos2dARB=_Lazy_glWindowPos2dARB;
PFNGLWINDOWPOS2DVARBPROC pglWindowPos2dvARB=_Lazy_glWindowPos2dvARB;
PFNGLWINDOWPOS2FARBPROC pglWindowPos2fARB=_Lazy_glWindowPos2fARB;
PFNGLWINDOWPOS2FVARBPROC pglWindowPos2fvARB=_Lazy_glWindowPos2fvARB;
PFNGLWINDOWPOS2IARBPROC pglWindowPos2iARB=_Lazy_glWindowPos2iARB;
PFNGLWINDOWPOS2IVARBPROC pglWindowPos2ivARB=_Lazy_glWindowPos2ivARB;
PFNGLWINDOWPOS2SARBPROC pglWindowPos2sARB=_Lazy_glWindowPos2sARB;
PFNGLWINDOWPOS2SVARBPROC pglWindowPos2svARB=_Lazy_glWindowPos2svARB;
PFNGLWINDOWPOS3DARBPROC pglWindowPos3dARB=_Lazy_glWindowPos3dARB;
PFNGLWINDOWPOS3DVARBPROC pglWindowPos3dvARB=_Lazy_glWindowPos3dvARB;
PFNGLWINDOWPOS3FARBPROC pglWindowPos3fARB=_Lazy_glWindowPos3fARB;
PFNGLWINDOWPOS3FVARBPROC pglWindowPos3fvARB=_Lazy_glWindowPos3fvARB;
PFNGLWINDOWPOS3IARBPROC pglWindowPos3iARB=_Lazy_glWindowPos3iARB;
PFNGLWINDOWPOS3IVARBPROC pglWindowPos3ivARB=_Lazy_glWindowPos3ivARB;
PFNGLWINDOWPOS3SARBPROC pglWindowPos3sARB=_Lazy_glWindowPos3sARB;
PFNGLWINDOWPOS3SVARBPROC pglWindowPos3svARB=_Lazy_glWindowPos3svARB;
#endif 

/* GL_ARB_vertex_program */

#ifdef __GLEE_GL_ARB_vertex_program
void __stdcall _Lazy_glVertexAttrib1dARB(GLuint index, GLdouble x)                        {if (GLeeInit()) glVertexAttrib1dARB(index, x);}
void __stdcall _Lazy_glVertexAttrib1dvARB(GLuint index, const GLdouble * v)               {if (GLeeInit()) glVertexAttrib1dvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib1fARB(GLuint index, GLfloat x)                         {if (GLeeInit()) glVertexAttrib1fARB(index, x);}
void __stdcall _Lazy_glVertexAttrib1fvARB(GLuint index, const GLfloat * v)                {if (GLeeInit()) glVertexAttrib1fvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib1sARB(GLuint index, GLshort x)                         {if (GLeeInit()) glVertexAttrib1sARB(index, x);}
void __stdcall _Lazy_glVertexAttrib1svARB(GLuint index, const GLshort * v)                {if (GLeeInit()) glVertexAttrib1svARB(index, v);}
void __stdcall _Lazy_glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y)            {if (GLeeInit()) glVertexAttrib2dARB(index, x, y);}
void __stdcall _Lazy_glVertexAttrib2dvARB(GLuint index, const GLdouble * v)               {if (GLeeInit()) glVertexAttrib2dvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y)              {if (GLeeInit()) glVertexAttrib2fARB(index, x, y);}
void __stdcall _Lazy_glVertexAttrib2fvARB(GLuint index, const GLfloat * v)                {if (GLeeInit()) glVertexAttrib2fvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y)              {if (GLeeInit()) glVertexAttrib2sARB(index, x, y);}
void __stdcall _Lazy_glVertexAttrib2svARB(GLuint index, const GLshort * v)                {if (GLeeInit()) glVertexAttrib2svARB(index, v);}
void __stdcall _Lazy_glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z)  {if (GLeeInit()) glVertexAttrib3dARB(index, x, y, z);}
void __stdcall _Lazy_glVertexAttrib3dvARB(GLuint index, const GLdouble * v)               {if (GLeeInit()) glVertexAttrib3dvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z)   {if (GLeeInit()) glVertexAttrib3fARB(index, x, y, z);}
void __stdcall _Lazy_glVertexAttrib3fvARB(GLuint index, const GLfloat * v)                {if (GLeeInit()) glVertexAttrib3fvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z)   {if (GLeeInit()) glVertexAttrib3sARB(index, x, y, z);}
void __stdcall _Lazy_glVertexAttrib3svARB(GLuint index, const GLshort * v)                {if (GLeeInit()) glVertexAttrib3svARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4NbvARB(GLuint index, const GLbyte * v)                {if (GLeeInit()) glVertexAttrib4NbvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4NivARB(GLuint index, const GLint * v)                 {if (GLeeInit()) glVertexAttrib4NivARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4NsvARB(GLuint index, const GLshort * v)               {if (GLeeInit()) glVertexAttrib4NsvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)  {if (GLeeInit()) glVertexAttrib4NubARB(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4NubvARB(GLuint index, const GLubyte * v)              {if (GLeeInit()) glVertexAttrib4NubvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4NuivARB(GLuint index, const GLuint * v)               {if (GLeeInit()) glVertexAttrib4NuivARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4NusvARB(GLuint index, const GLushort * v)             {if (GLeeInit()) glVertexAttrib4NusvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4bvARB(GLuint index, const GLbyte * v)                 {if (GLeeInit()) glVertexAttrib4bvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)  {if (GLeeInit()) glVertexAttrib4dARB(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4dvARB(GLuint index, const GLdouble * v)               {if (GLeeInit()) glVertexAttrib4dvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)  {if (GLeeInit()) glVertexAttrib4fARB(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4fvARB(GLuint index, const GLfloat * v)                {if (GLeeInit()) glVertexAttrib4fvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4ivARB(GLuint index, const GLint * v)                  {if (GLeeInit()) glVertexAttrib4ivARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)  {if (GLeeInit()) glVertexAttrib4sARB(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4svARB(GLuint index, const GLshort * v)                {if (GLeeInit()) glVertexAttrib4svARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4ubvARB(GLuint index, const GLubyte * v)               {if (GLeeInit()) glVertexAttrib4ubvARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4uivARB(GLuint index, const GLuint * v)                {if (GLeeInit()) glVertexAttrib4uivARB(index, v);}
void __stdcall _Lazy_glVertexAttrib4usvARB(GLuint index, const GLushort * v)              {if (GLeeInit()) glVertexAttrib4usvARB(index, v);}
void __stdcall _Lazy_glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glVertexAttribPointerARB(index, size, type, normalized, stride, pointer);}
void __stdcall _Lazy_glEnableVertexAttribArrayARB(GLuint index)                           {if (GLeeInit()) glEnableVertexAttribArrayARB(index);}
void __stdcall _Lazy_glDisableVertexAttribArrayARB(GLuint index)                          {if (GLeeInit()) glDisableVertexAttribArrayARB(index);}
void __stdcall _Lazy_glProgramStringARB(GLenum target, GLenum format, GLsizei len, const GLvoid * string)  {if (GLeeInit()) glProgramStringARB(target, format, len, string);}
void __stdcall _Lazy_glBindProgramARB(GLenum target, GLuint program)                      {if (GLeeInit()) glBindProgramARB(target, program);}
void __stdcall _Lazy_glDeleteProgramsARB(GLsizei n, const GLuint * programs)              {if (GLeeInit()) glDeleteProgramsARB(n, programs);}
void __stdcall _Lazy_glGenProgramsARB(GLsizei n, GLuint * programs)                       {if (GLeeInit()) glGenProgramsARB(n, programs);}
void __stdcall _Lazy_glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)  {if (GLeeInit()) glProgramEnvParameter4dARB(target, index, x, y, z, w);}
void __stdcall _Lazy_glProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble * params)  {if (GLeeInit()) glProgramEnvParameter4dvARB(target, index, params);}
void __stdcall _Lazy_glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)  {if (GLeeInit()) glProgramEnvParameter4fARB(target, index, x, y, z, w);}
void __stdcall _Lazy_glProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat * params)  {if (GLeeInit()) glProgramEnvParameter4fvARB(target, index, params);}
void __stdcall _Lazy_glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)  {if (GLeeInit()) glProgramLocalParameter4dARB(target, index, x, y, z, w);}
void __stdcall _Lazy_glProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble * params)  {if (GLeeInit()) glProgramLocalParameter4dvARB(target, index, params);}
void __stdcall _Lazy_glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)  {if (GLeeInit()) glProgramLocalParameter4fARB(target, index, x, y, z, w);}
void __stdcall _Lazy_glProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat * params)  {if (GLeeInit()) glProgramLocalParameter4fvARB(target, index, params);}
void __stdcall _Lazy_glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble * params)  {if (GLeeInit()) glGetProgramEnvParameterdvARB(target, index, params);}
void __stdcall _Lazy_glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat * params)  {if (GLeeInit()) glGetProgramEnvParameterfvARB(target, index, params);}
void __stdcall _Lazy_glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble * params)  {if (GLeeInit()) glGetProgramLocalParameterdvARB(target, index, params);}
void __stdcall _Lazy_glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat * params)  {if (GLeeInit()) glGetProgramLocalParameterfvARB(target, index, params);}
void __stdcall _Lazy_glGetProgramivARB(GLenum target, GLenum pname, GLint * params)       {if (GLeeInit()) glGetProgramivARB(target, pname, params);}
void __stdcall _Lazy_glGetProgramStringARB(GLenum target, GLenum pname, GLvoid * string)  {if (GLeeInit()) glGetProgramStringARB(target, pname, string);}
void __stdcall _Lazy_glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble * params)  {if (GLeeInit()) glGetVertexAttribdvARB(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetVertexAttribfvARB(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribivARB(GLuint index, GLenum pname, GLint * params)   {if (GLeeInit()) glGetVertexAttribivARB(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid* * pointer)  {if (GLeeInit()) glGetVertexAttribPointervARB(index, pname, pointer);}
GLboolean __stdcall _Lazy_glIsProgramARB(GLuint program)                                  {if (GLeeInit()) return glIsProgramARB(program); return (GLboolean)0;}
PFNGLVERTEXATTRIB1DARBPROC pglVertexAttrib1dARB=_Lazy_glVertexAttrib1dARB;
PFNGLVERTEXATTRIB1DVARBPROC pglVertexAttrib1dvARB=_Lazy_glVertexAttrib1dvARB;
PFNGLVERTEXATTRIB1FARBPROC pglVertexAttrib1fARB=_Lazy_glVertexAttrib1fARB;
PFNGLVERTEXATTRIB1FVARBPROC pglVertexAttrib1fvARB=_Lazy_glVertexAttrib1fvARB;
PFNGLVERTEXATTRIB1SARBPROC pglVertexAttrib1sARB=_Lazy_glVertexAttrib1sARB;
PFNGLVERTEXATTRIB1SVARBPROC pglVertexAttrib1svARB=_Lazy_glVertexAttrib1svARB;
PFNGLVERTEXATTRIB2DARBPROC pglVertexAttrib2dARB=_Lazy_glVertexAttrib2dARB;
PFNGLVERTEXATTRIB2DVARBPROC pglVertexAttrib2dvARB=_Lazy_glVertexAttrib2dvARB;
PFNGLVERTEXATTRIB2FARBPROC pglVertexAttrib2fARB=_Lazy_glVertexAttrib2fARB;
PFNGLVERTEXATTRIB2FVARBPROC pglVertexAttrib2fvARB=_Lazy_glVertexAttrib2fvARB;
PFNGLVERTEXATTRIB2SARBPROC pglVertexAttrib2sARB=_Lazy_glVertexAttrib2sARB;
PFNGLVERTEXATTRIB2SVARBPROC pglVertexAttrib2svARB=_Lazy_glVertexAttrib2svARB;
PFNGLVERTEXATTRIB3DARBPROC pglVertexAttrib3dARB=_Lazy_glVertexAttrib3dARB;
PFNGLVERTEXATTRIB3DVARBPROC pglVertexAttrib3dvARB=_Lazy_glVertexAttrib3dvARB;
PFNGLVERTEXATTRIB3FARBPROC pglVertexAttrib3fARB=_Lazy_glVertexAttrib3fARB;
PFNGLVERTEXATTRIB3FVARBPROC pglVertexAttrib3fvARB=_Lazy_glVertexAttrib3fvARB;
PFNGLVERTEXATTRIB3SARBPROC pglVertexAttrib3sARB=_Lazy_glVertexAttrib3sARB;
PFNGLVERTEXATTRIB3SVARBPROC pglVertexAttrib3svARB=_Lazy_glVertexAttrib3svARB;
PFNGLVERTEXATTRIB4NBVARBPROC pglVertexAttrib4NbvARB=_Lazy_glVertexAttrib4NbvARB;
PFNGLVERTEXATTRIB4NIVARBPROC pglVertexAttrib4NivARB=_Lazy_glVertexAttrib4NivARB;
PFNGLVERTEXATTRIB4NSVARBPROC pglVertexAttrib4NsvARB=_Lazy_glVertexAttrib4NsvARB;
PFNGLVERTEXATTRIB4NUBARBPROC pglVertexAttrib4NubARB=_Lazy_glVertexAttrib4NubARB;
PFNGLVERTEXATTRIB4NUBVARBPROC pglVertexAttrib4NubvARB=_Lazy_glVertexAttrib4NubvARB;
PFNGLVERTEXATTRIB4NUIVARBPROC pglVertexAttrib4NuivARB=_Lazy_glVertexAttrib4NuivARB;
PFNGLVERTEXATTRIB4NUSVARBPROC pglVertexAttrib4NusvARB=_Lazy_glVertexAttrib4NusvARB;
PFNGLVERTEXATTRIB4BVARBPROC pglVertexAttrib4bvARB=_Lazy_glVertexAttrib4bvARB;
PFNGLVERTEXATTRIB4DARBPROC pglVertexAttrib4dARB=_Lazy_glVertexAttrib4dARB;
PFNGLVERTEXATTRIB4DVARBPROC pglVertexAttrib4dvARB=_Lazy_glVertexAttrib4dvARB;
PFNGLVERTEXATTRIB4FARBPROC pglVertexAttrib4fARB=_Lazy_glVertexAttrib4fARB;
PFNGLVERTEXATTRIB4FVARBPROC pglVertexAttrib4fvARB=_Lazy_glVertexAttrib4fvARB;
PFNGLVERTEXATTRIB4IVARBPROC pglVertexAttrib4ivARB=_Lazy_glVertexAttrib4ivARB;
PFNGLVERTEXATTRIB4SARBPROC pglVertexAttrib4sARB=_Lazy_glVertexAttrib4sARB;
PFNGLVERTEXATTRIB4SVARBPROC pglVertexAttrib4svARB=_Lazy_glVertexAttrib4svARB;
PFNGLVERTEXATTRIB4UBVARBPROC pglVertexAttrib4ubvARB=_Lazy_glVertexAttrib4ubvARB;
PFNGLVERTEXATTRIB4UIVARBPROC pglVertexAttrib4uivARB=_Lazy_glVertexAttrib4uivARB;
PFNGLVERTEXATTRIB4USVARBPROC pglVertexAttrib4usvARB=_Lazy_glVertexAttrib4usvARB;
PFNGLVERTEXATTRIBPOINTERARBPROC pglVertexAttribPointerARB=_Lazy_glVertexAttribPointerARB;
PFNGLENABLEVERTEXATTRIBARRAYARBPROC pglEnableVertexAttribArrayARB=_Lazy_glEnableVertexAttribArrayARB;
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC pglDisableVertexAttribArrayARB=_Lazy_glDisableVertexAttribArrayARB;
PFNGLPROGRAMSTRINGARBPROC pglProgramStringARB=_Lazy_glProgramStringARB;
PFNGLBINDPROGRAMARBPROC pglBindProgramARB=_Lazy_glBindProgramARB;
PFNGLDELETEPROGRAMSARBPROC pglDeleteProgramsARB=_Lazy_glDeleteProgramsARB;
PFNGLGENPROGRAMSARBPROC pglGenProgramsARB=_Lazy_glGenProgramsARB;
PFNGLPROGRAMENVPARAMETER4DARBPROC pglProgramEnvParameter4dARB=_Lazy_glProgramEnvParameter4dARB;
PFNGLPROGRAMENVPARAMETER4DVARBPROC pglProgramEnvParameter4dvARB=_Lazy_glProgramEnvParameter4dvARB;
PFNGLPROGRAMENVPARAMETER4FARBPROC pglProgramEnvParameter4fARB=_Lazy_glProgramEnvParameter4fARB;
PFNGLPROGRAMENVPARAMETER4FVARBPROC pglProgramEnvParameter4fvARB=_Lazy_glProgramEnvParameter4fvARB;
PFNGLPROGRAMLOCALPARAMETER4DARBPROC pglProgramLocalParameter4dARB=_Lazy_glProgramLocalParameter4dARB;
PFNGLPROGRAMLOCALPARAMETER4DVARBPROC pglProgramLocalParameter4dvARB=_Lazy_glProgramLocalParameter4dvARB;
PFNGLPROGRAMLOCALPARAMETER4FARBPROC pglProgramLocalParameter4fARB=_Lazy_glProgramLocalParameter4fARB;
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC pglProgramLocalParameter4fvARB=_Lazy_glProgramLocalParameter4fvARB;
PFNGLGETPROGRAMENVPARAMETERDVARBPROC pglGetProgramEnvParameterdvARB=_Lazy_glGetProgramEnvParameterdvARB;
PFNGLGETPROGRAMENVPARAMETERFVARBPROC pglGetProgramEnvParameterfvARB=_Lazy_glGetProgramEnvParameterfvARB;
PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC pglGetProgramLocalParameterdvARB=_Lazy_glGetProgramLocalParameterdvARB;
PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC pglGetProgramLocalParameterfvARB=_Lazy_glGetProgramLocalParameterfvARB;
PFNGLGETPROGRAMIVARBPROC pglGetProgramivARB=_Lazy_glGetProgramivARB;
PFNGLGETPROGRAMSTRINGARBPROC pglGetProgramStringARB=_Lazy_glGetProgramStringARB;
PFNGLGETVERTEXATTRIBDVARBPROC pglGetVertexAttribdvARB=_Lazy_glGetVertexAttribdvARB;
PFNGLGETVERTEXATTRIBFVARBPROC pglGetVertexAttribfvARB=_Lazy_glGetVertexAttribfvARB;
PFNGLGETVERTEXATTRIBIVARBPROC pglGetVertexAttribivARB=_Lazy_glGetVertexAttribivARB;
PFNGLGETVERTEXATTRIBPOINTERVARBPROC pglGetVertexAttribPointervARB=_Lazy_glGetVertexAttribPointervARB;
PFNGLISPROGRAMARBPROC pglIsProgramARB=_Lazy_glIsProgramARB;
#endif 

/* GL_ARB_fragment_program */

#ifdef __GLEE_GL_ARB_fragment_program
#endif 

/* GL_ARB_vertex_buffer_object */

#ifdef __GLEE_GL_ARB_vertex_buffer_object
void __stdcall _Lazy_glBindBufferARB(GLenum target, GLuint buffer)                        {if (GLeeInit()) glBindBufferARB(target, buffer);}
void __stdcall _Lazy_glDeleteBuffersARB(GLsizei n, const GLuint * buffers)                {if (GLeeInit()) glDeleteBuffersARB(n, buffers);}
void __stdcall _Lazy_glGenBuffersARB(GLsizei n, GLuint * buffers)                         {if (GLeeInit()) glGenBuffersARB(n, buffers);}
GLboolean __stdcall _Lazy_glIsBufferARB(GLuint buffer)                                    {if (GLeeInit()) return glIsBufferARB(buffer); return (GLboolean)0;}
void __stdcall _Lazy_glBufferDataARB(GLenum target, GLsizeiptrARB size, const GLvoid * data, GLenum usage)  {if (GLeeInit()) glBufferDataARB(target, size, data, usage);}
void __stdcall _Lazy_glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid * data)  {if (GLeeInit()) glBufferSubDataARB(target, offset, size, data);}
void __stdcall _Lazy_glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid * data)  {if (GLeeInit()) glGetBufferSubDataARB(target, offset, size, data);}
GLvoid* __stdcall _Lazy_glMapBufferARB(GLenum target, GLenum access)                      {if (GLeeInit()) return glMapBufferARB(target, access); return (GLvoid*)0;}
GLboolean __stdcall _Lazy_glUnmapBufferARB(GLenum target)                                 {if (GLeeInit()) return glUnmapBufferARB(target); return (GLboolean)0;}
void __stdcall _Lazy_glGetBufferParameterivARB(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetBufferParameterivARB(target, pname, params);}
void __stdcall _Lazy_glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid* * params)  {if (GLeeInit()) glGetBufferPointervARB(target, pname, params);}
PFNGLBINDBUFFERARBPROC pglBindBufferARB=_Lazy_glBindBufferARB;
PFNGLDELETEBUFFERSARBPROC pglDeleteBuffersARB=_Lazy_glDeleteBuffersARB;
PFNGLGENBUFFERSARBPROC pglGenBuffersARB=_Lazy_glGenBuffersARB;
PFNGLISBUFFERARBPROC pglIsBufferARB=_Lazy_glIsBufferARB;
PFNGLBUFFERDATAARBPROC pglBufferDataARB=_Lazy_glBufferDataARB;
PFNGLBUFFERSUBDATAARBPROC pglBufferSubDataARB=_Lazy_glBufferSubDataARB;
PFNGLGETBUFFERSUBDATAARBPROC pglGetBufferSubDataARB=_Lazy_glGetBufferSubDataARB;
PFNGLMAPBUFFERARBPROC pglMapBufferARB=_Lazy_glMapBufferARB;
PFNGLUNMAPBUFFERARBPROC pglUnmapBufferARB=_Lazy_glUnmapBufferARB;
PFNGLGETBUFFERPARAMETERIVARBPROC pglGetBufferParameterivARB=_Lazy_glGetBufferParameterivARB;
PFNGLGETBUFFERPOINTERVARBPROC pglGetBufferPointervARB=_Lazy_glGetBufferPointervARB;
#endif 

/* GL_ARB_occlusion_query */

#ifdef __GLEE_GL_ARB_occlusion_query
void __stdcall _Lazy_glGenQueriesARB(GLsizei n, GLuint * ids)                             {if (GLeeInit()) glGenQueriesARB(n, ids);}
void __stdcall _Lazy_glDeleteQueriesARB(GLsizei n, const GLuint * ids)                    {if (GLeeInit()) glDeleteQueriesARB(n, ids);}
GLboolean __stdcall _Lazy_glIsQueryARB(GLuint id)                                         {if (GLeeInit()) return glIsQueryARB(id); return (GLboolean)0;}
void __stdcall _Lazy_glBeginQueryARB(GLenum target, GLuint id)                            {if (GLeeInit()) glBeginQueryARB(target, id);}
void __stdcall _Lazy_glEndQueryARB(GLenum target)                                         {if (GLeeInit()) glEndQueryARB(target);}
void __stdcall _Lazy_glGetQueryivARB(GLenum target, GLenum pname, GLint * params)         {if (GLeeInit()) glGetQueryivARB(target, pname, params);}
void __stdcall _Lazy_glGetQueryObjectivARB(GLuint id, GLenum pname, GLint * params)       {if (GLeeInit()) glGetQueryObjectivARB(id, pname, params);}
void __stdcall _Lazy_glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint * params)     {if (GLeeInit()) glGetQueryObjectuivARB(id, pname, params);}
PFNGLGENQUERIESARBPROC pglGenQueriesARB=_Lazy_glGenQueriesARB;
PFNGLDELETEQUERIESARBPROC pglDeleteQueriesARB=_Lazy_glDeleteQueriesARB;
PFNGLISQUERYARBPROC pglIsQueryARB=_Lazy_glIsQueryARB;
PFNGLBEGINQUERYARBPROC pglBeginQueryARB=_Lazy_glBeginQueryARB;
PFNGLENDQUERYARBPROC pglEndQueryARB=_Lazy_glEndQueryARB;
PFNGLGETQUERYIVARBPROC pglGetQueryivARB=_Lazy_glGetQueryivARB;
PFNGLGETQUERYOBJECTIVARBPROC pglGetQueryObjectivARB=_Lazy_glGetQueryObjectivARB;
PFNGLGETQUERYOBJECTUIVARBPROC pglGetQueryObjectuivARB=_Lazy_glGetQueryObjectuivARB;
#endif 

/* GL_ARB_shader_objects */

#ifdef __GLEE_GL_ARB_shader_objects
void __stdcall _Lazy_glDeleteObjectARB(GLhandleARB obj)                                   {if (GLeeInit()) glDeleteObjectARB(obj);}
GLhandleARB __stdcall _Lazy_glGetHandleARB(GLenum pname)                                  {if (GLeeInit()) return glGetHandleARB(pname); return (GLhandleARB)0;}
void __stdcall _Lazy_glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj)  {if (GLeeInit()) glDetachObjectARB(containerObj, attachedObj);}
GLhandleARB __stdcall _Lazy_glCreateShaderObjectARB(GLenum shaderType)                    {if (GLeeInit()) return glCreateShaderObjectARB(shaderType); return (GLhandleARB)0;}
void __stdcall _Lazy_glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB* * string, const GLint * length)  {if (GLeeInit()) glShaderSourceARB(shaderObj, count, string, length);}
void __stdcall _Lazy_glCompileShaderARB(GLhandleARB shaderObj)                            {if (GLeeInit()) glCompileShaderARB(shaderObj);}
GLhandleARB __stdcall _Lazy_glCreateProgramObjectARB(void)                                {if (GLeeInit()) return glCreateProgramObjectARB(); return (GLhandleARB)0;}
void __stdcall _Lazy_glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj)         {if (GLeeInit()) glAttachObjectARB(containerObj, obj);}
void __stdcall _Lazy_glLinkProgramARB(GLhandleARB programObj)                             {if (GLeeInit()) glLinkProgramARB(programObj);}
void __stdcall _Lazy_glUseProgramObjectARB(GLhandleARB programObj)                        {if (GLeeInit()) glUseProgramObjectARB(programObj);}
void __stdcall _Lazy_glValidateProgramARB(GLhandleARB programObj)                         {if (GLeeInit()) glValidateProgramARB(programObj);}
void __stdcall _Lazy_glUniform1fARB(GLint location, GLfloat v0)                           {if (GLeeInit()) glUniform1fARB(location, v0);}
void __stdcall _Lazy_glUniform2fARB(GLint location, GLfloat v0, GLfloat v1)               {if (GLeeInit()) glUniform2fARB(location, v0, v1);}
void __stdcall _Lazy_glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)   {if (GLeeInit()) glUniform3fARB(location, v0, v1, v2);}
void __stdcall _Lazy_glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)  {if (GLeeInit()) glUniform4fARB(location, v0, v1, v2, v3);}
void __stdcall _Lazy_glUniform1iARB(GLint location, GLint v0)                             {if (GLeeInit()) glUniform1iARB(location, v0);}
void __stdcall _Lazy_glUniform2iARB(GLint location, GLint v0, GLint v1)                   {if (GLeeInit()) glUniform2iARB(location, v0, v1);}
void __stdcall _Lazy_glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2)         {if (GLeeInit()) glUniform3iARB(location, v0, v1, v2);}
void __stdcall _Lazy_glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)  {if (GLeeInit()) glUniform4iARB(location, v0, v1, v2, v3);}
void __stdcall _Lazy_glUniform1fvARB(GLint location, GLsizei count, const GLfloat * value)  {if (GLeeInit()) glUniform1fvARB(location, count, value);}
void __stdcall _Lazy_glUniform2fvARB(GLint location, GLsizei count, const GLfloat * value)  {if (GLeeInit()) glUniform2fvARB(location, count, value);}
void __stdcall _Lazy_glUniform3fvARB(GLint location, GLsizei count, const GLfloat * value)  {if (GLeeInit()) glUniform3fvARB(location, count, value);}
void __stdcall _Lazy_glUniform4fvARB(GLint location, GLsizei count, const GLfloat * value)  {if (GLeeInit()) glUniform4fvARB(location, count, value);}
void __stdcall _Lazy_glUniform1ivARB(GLint location, GLsizei count, const GLint * value)  {if (GLeeInit()) glUniform1ivARB(location, count, value);}
void __stdcall _Lazy_glUniform2ivARB(GLint location, GLsizei count, const GLint * value)  {if (GLeeInit()) glUniform2ivARB(location, count, value);}
void __stdcall _Lazy_glUniform3ivARB(GLint location, GLsizei count, const GLint * value)  {if (GLeeInit()) glUniform3ivARB(location, count, value);}
void __stdcall _Lazy_glUniform4ivARB(GLint location, GLsizei count, const GLint * value)  {if (GLeeInit()) glUniform4ivARB(location, count, value);}
void __stdcall _Lazy_glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix2fvARB(location, count, transpose, value);}
void __stdcall _Lazy_glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix3fvARB(location, count, transpose, value);}
void __stdcall _Lazy_glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)  {if (GLeeInit()) glUniformMatrix4fvARB(location, count, transpose, value);}
void __stdcall _Lazy_glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetObjectParameterfvARB(obj, pname, params);}
void __stdcall _Lazy_glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint * params)  {if (GLeeInit()) glGetObjectParameterivARB(obj, pname, params);}
void __stdcall _Lazy_glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * infoLog)  {if (GLeeInit()) glGetInfoLogARB(obj, maxLength, length, infoLog);}
void __stdcall _Lazy_glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei * count, GLhandleARB * obj)  {if (GLeeInit()) glGetAttachedObjectsARB(containerObj, maxCount, count, obj);}
GLint __stdcall _Lazy_glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB * name)  {if (GLeeInit()) return glGetUniformLocationARB(programObj, name); return (GLint)0;}
void __stdcall _Lazy_glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name)  {if (GLeeInit()) glGetActiveUniformARB(programObj, index, maxLength, length, size, type, name);}
void __stdcall _Lazy_glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat * params)  {if (GLeeInit()) glGetUniformfvARB(programObj, location, params);}
void __stdcall _Lazy_glGetUniformivARB(GLhandleARB programObj, GLint location, GLint * params)  {if (GLeeInit()) glGetUniformivARB(programObj, location, params);}
void __stdcall _Lazy_glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * source)  {if (GLeeInit()) glGetShaderSourceARB(obj, maxLength, length, source);}
PFNGLDELETEOBJECTARBPROC pglDeleteObjectARB=_Lazy_glDeleteObjectARB;
PFNGLGETHANDLEARBPROC pglGetHandleARB=_Lazy_glGetHandleARB;
PFNGLDETACHOBJECTARBPROC pglDetachObjectARB=_Lazy_glDetachObjectARB;
PFNGLCREATESHADEROBJECTARBPROC pglCreateShaderObjectARB=_Lazy_glCreateShaderObjectARB;
PFNGLSHADERSOURCEARBPROC pglShaderSourceARB=_Lazy_glShaderSourceARB;
PFNGLCOMPILESHADERARBPROC pglCompileShaderARB=_Lazy_glCompileShaderARB;
PFNGLCREATEPROGRAMOBJECTARBPROC pglCreateProgramObjectARB=_Lazy_glCreateProgramObjectARB;
PFNGLATTACHOBJECTARBPROC pglAttachObjectARB=_Lazy_glAttachObjectARB;
PFNGLLINKPROGRAMARBPROC pglLinkProgramARB=_Lazy_glLinkProgramARB;
PFNGLUSEPROGRAMOBJECTARBPROC pglUseProgramObjectARB=_Lazy_glUseProgramObjectARB;
PFNGLVALIDATEPROGRAMARBPROC pglValidateProgramARB=_Lazy_glValidateProgramARB;
PFNGLUNIFORM1FARBPROC pglUniform1fARB=_Lazy_glUniform1fARB;
PFNGLUNIFORM2FARBPROC pglUniform2fARB=_Lazy_glUniform2fARB;
PFNGLUNIFORM3FARBPROC pglUniform3fARB=_Lazy_glUniform3fARB;
PFNGLUNIFORM4FARBPROC pglUniform4fARB=_Lazy_glUniform4fARB;
PFNGLUNIFORM1IARBPROC pglUniform1iARB=_Lazy_glUniform1iARB;
PFNGLUNIFORM2IARBPROC pglUniform2iARB=_Lazy_glUniform2iARB;
PFNGLUNIFORM3IARBPROC pglUniform3iARB=_Lazy_glUniform3iARB;
PFNGLUNIFORM4IARBPROC pglUniform4iARB=_Lazy_glUniform4iARB;
PFNGLUNIFORM1FVARBPROC pglUniform1fvARB=_Lazy_glUniform1fvARB;
PFNGLUNIFORM2FVARBPROC pglUniform2fvARB=_Lazy_glUniform2fvARB;
PFNGLUNIFORM3FVARBPROC pglUniform3fvARB=_Lazy_glUniform3fvARB;
PFNGLUNIFORM4FVARBPROC pglUniform4fvARB=_Lazy_glUniform4fvARB;
PFNGLUNIFORM1IVARBPROC pglUniform1ivARB=_Lazy_glUniform1ivARB;
PFNGLUNIFORM2IVARBPROC pglUniform2ivARB=_Lazy_glUniform2ivARB;
PFNGLUNIFORM3IVARBPROC pglUniform3ivARB=_Lazy_glUniform3ivARB;
PFNGLUNIFORM4IVARBPROC pglUniform4ivARB=_Lazy_glUniform4ivARB;
PFNGLUNIFORMMATRIX2FVARBPROC pglUniformMatrix2fvARB=_Lazy_glUniformMatrix2fvARB;
PFNGLUNIFORMMATRIX3FVARBPROC pglUniformMatrix3fvARB=_Lazy_glUniformMatrix3fvARB;
PFNGLUNIFORMMATRIX4FVARBPROC pglUniformMatrix4fvARB=_Lazy_glUniformMatrix4fvARB;
PFNGLGETOBJECTPARAMETERFVARBPROC pglGetObjectParameterfvARB=_Lazy_glGetObjectParameterfvARB;
PFNGLGETOBJECTPARAMETERIVARBPROC pglGetObjectParameterivARB=_Lazy_glGetObjectParameterivARB;
PFNGLGETINFOLOGARBPROC pglGetInfoLogARB=_Lazy_glGetInfoLogARB;
PFNGLGETATTACHEDOBJECTSARBPROC pglGetAttachedObjectsARB=_Lazy_glGetAttachedObjectsARB;
PFNGLGETUNIFORMLOCATIONARBPROC pglGetUniformLocationARB=_Lazy_glGetUniformLocationARB;
PFNGLGETACTIVEUNIFORMARBPROC pglGetActiveUniformARB=_Lazy_glGetActiveUniformARB;
PFNGLGETUNIFORMFVARBPROC pglGetUniformfvARB=_Lazy_glGetUniformfvARB;
PFNGLGETUNIFORMIVARBPROC pglGetUniformivARB=_Lazy_glGetUniformivARB;
PFNGLGETSHADERSOURCEARBPROC pglGetShaderSourceARB=_Lazy_glGetShaderSourceARB;
#endif 

/* GL_ARB_vertex_shader */

#ifdef __GLEE_GL_ARB_vertex_shader
void __stdcall _Lazy_glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB * name)  {if (GLeeInit()) glBindAttribLocationARB(programObj, index, name);}
void __stdcall _Lazy_glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name)  {if (GLeeInit()) glGetActiveAttribARB(programObj, index, maxLength, length, size, type, name);}
GLint __stdcall _Lazy_glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB * name)  {if (GLeeInit()) return glGetAttribLocationARB(programObj, name); return (GLint)0;}
PFNGLBINDATTRIBLOCATIONARBPROC pglBindAttribLocationARB=_Lazy_glBindAttribLocationARB;
PFNGLGETACTIVEATTRIBARBPROC pglGetActiveAttribARB=_Lazy_glGetActiveAttribARB;
PFNGLGETATTRIBLOCATIONARBPROC pglGetAttribLocationARB=_Lazy_glGetAttribLocationARB;
#endif 

/* GL_ARB_fragment_shader */

#ifdef __GLEE_GL_ARB_fragment_shader
#endif 

/* GL_ARB_shading_language_100 */

#ifdef __GLEE_GL_ARB_shading_language_100
#endif 

/* GL_ARB_texture_non_power_of_two */

#ifdef __GLEE_GL_ARB_texture_non_power_of_two
#endif 

/* GL_ARB_point_sprite */

#ifdef __GLEE_GL_ARB_point_sprite
#endif 

/* GL_ARB_fragment_program_shadow */

#ifdef __GLEE_GL_ARB_fragment_program_shadow
#endif 

/* GL_ARB_draw_buffers */

#ifdef __GLEE_GL_ARB_draw_buffers
void __stdcall _Lazy_glDrawBuffersARB(GLsizei n, const GLenum * bufs)                     {if (GLeeInit()) glDrawBuffersARB(n, bufs);}
PFNGLDRAWBUFFERSARBPROC pglDrawBuffersARB=_Lazy_glDrawBuffersARB;
#endif 

/* GL_ARB_texture_rectangle */

#ifdef __GLEE_GL_ARB_texture_rectangle
#endif 

/* GL_ARB_color_buffer_float */

#ifdef __GLEE_GL_ARB_color_buffer_float
void __stdcall _Lazy_glClampColorARB(GLenum target, GLenum clamp)                         {if (GLeeInit()) glClampColorARB(target, clamp);}
PFNGLCLAMPCOLORARBPROC pglClampColorARB=_Lazy_glClampColorARB;
#endif 

/* GL_ARB_half_float_pixel */

#ifdef __GLEE_GL_ARB_half_float_pixel
#endif 

/* GL_ARB_texture_float */

#ifdef __GLEE_GL_ARB_texture_float
#endif 

/* GL_ARB_pixel_buffer_object */

#ifdef __GLEE_GL_ARB_pixel_buffer_object
#endif 

/* GL_EXT_abgr */

#ifdef __GLEE_GL_EXT_abgr
#endif 

/* GL_EXT_blend_color */

#ifdef __GLEE_GL_EXT_blend_color
void __stdcall _Lazy_glBlendColorEXT(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)  {if (GLeeInit()) glBlendColorEXT(red, green, blue, alpha);}
PFNGLBLENDCOLOREXTPROC pglBlendColorEXT=_Lazy_glBlendColorEXT;
#endif 

/* GL_EXT_polygon_offset */

#ifdef __GLEE_GL_EXT_polygon_offset
void __stdcall _Lazy_glPolygonOffsetEXT(GLfloat factor, GLfloat bias)                     {if (GLeeInit()) glPolygonOffsetEXT(factor, bias);}
PFNGLPOLYGONOFFSETEXTPROC pglPolygonOffsetEXT=_Lazy_glPolygonOffsetEXT;
#endif 

/* GL_EXT_texture */

#ifdef __GLEE_GL_EXT_texture
#endif 

/* GL_EXT_texture3D */

#ifdef __GLEE_GL_EXT_texture3D
void __stdcall _Lazy_glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels)  {if (GLeeInit()) glTexImage3DEXT(target, level, internalformat, width, height, depth, border, format, type, pixels);}
void __stdcall _Lazy_glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels)  {if (GLeeInit()) glTexSubImage3DEXT(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);}
PFNGLTEXIMAGE3DEXTPROC pglTexImage3DEXT=_Lazy_glTexImage3DEXT;
PFNGLTEXSUBIMAGE3DEXTPROC pglTexSubImage3DEXT=_Lazy_glTexSubImage3DEXT;
#endif 

/* GL_SGIS_texture_filter4 */

#ifdef __GLEE_GL_SGIS_texture_filter4
void __stdcall _Lazy_glGetTexFilterFuncSGIS(GLenum target, GLenum filter, GLfloat * weights)  {if (GLeeInit()) glGetTexFilterFuncSGIS(target, filter, weights);}
void __stdcall _Lazy_glTexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, const GLfloat * weights)  {if (GLeeInit()) glTexFilterFuncSGIS(target, filter, n, weights);}
PFNGLGETTEXFILTERFUNCSGISPROC pglGetTexFilterFuncSGIS=_Lazy_glGetTexFilterFuncSGIS;
PFNGLTEXFILTERFUNCSGISPROC pglTexFilterFuncSGIS=_Lazy_glTexFilterFuncSGIS;
#endif 

/* GL_EXT_subtexture */

#ifdef __GLEE_GL_EXT_subtexture
void __stdcall _Lazy_glTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels)  {if (GLeeInit()) glTexSubImage1DEXT(target, level, xoffset, width, format, type, pixels);}
void __stdcall _Lazy_glTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels)  {if (GLeeInit()) glTexSubImage2DEXT(target, level, xoffset, yoffset, width, height, format, type, pixels);}
PFNGLTEXSUBIMAGE1DEXTPROC pglTexSubImage1DEXT=_Lazy_glTexSubImage1DEXT;
PFNGLTEXSUBIMAGE2DEXTPROC pglTexSubImage2DEXT=_Lazy_glTexSubImage2DEXT;
#endif 

/* GL_EXT_copy_texture */

#ifdef __GLEE_GL_EXT_copy_texture
void __stdcall _Lazy_glCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)  {if (GLeeInit()) glCopyTexImage1DEXT(target, level, internalformat, x, y, width, border);}
void __stdcall _Lazy_glCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)  {if (GLeeInit()) glCopyTexImage2DEXT(target, level, internalformat, x, y, width, height, border);}
void __stdcall _Lazy_glCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)  {if (GLeeInit()) glCopyTexSubImage1DEXT(target, level, xoffset, x, y, width);}
void __stdcall _Lazy_glCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)  {if (GLeeInit()) glCopyTexSubImage2DEXT(target, level, xoffset, yoffset, x, y, width, height);}
void __stdcall _Lazy_glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)  {if (GLeeInit()) glCopyTexSubImage3DEXT(target, level, xoffset, yoffset, zoffset, x, y, width, height);}
PFNGLCOPYTEXIMAGE1DEXTPROC pglCopyTexImage1DEXT=_Lazy_glCopyTexImage1DEXT;
PFNGLCOPYTEXIMAGE2DEXTPROC pglCopyTexImage2DEXT=_Lazy_glCopyTexImage2DEXT;
PFNGLCOPYTEXSUBIMAGE1DEXTPROC pglCopyTexSubImage1DEXT=_Lazy_glCopyTexSubImage1DEXT;
PFNGLCOPYTEXSUBIMAGE2DEXTPROC pglCopyTexSubImage2DEXT=_Lazy_glCopyTexSubImage2DEXT;
PFNGLCOPYTEXSUBIMAGE3DEXTPROC pglCopyTexSubImage3DEXT=_Lazy_glCopyTexSubImage3DEXT;
#endif 

/* GL_EXT_histogram */

#ifdef __GLEE_GL_EXT_histogram
void __stdcall _Lazy_glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values)  {if (GLeeInit()) glGetHistogramEXT(target, reset, format, type, values);}
void __stdcall _Lazy_glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetHistogramParameterfvEXT(target, pname, params);}
void __stdcall _Lazy_glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetHistogramParameterivEXT(target, pname, params);}
void __stdcall _Lazy_glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values)  {if (GLeeInit()) glGetMinmaxEXT(target, reset, format, type, values);}
void __stdcall _Lazy_glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetMinmaxParameterfvEXT(target, pname, params);}
void __stdcall _Lazy_glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetMinmaxParameterivEXT(target, pname, params);}
void __stdcall _Lazy_glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)  {if (GLeeInit()) glHistogramEXT(target, width, internalformat, sink);}
void __stdcall _Lazy_glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink)    {if (GLeeInit()) glMinmaxEXT(target, internalformat, sink);}
void __stdcall _Lazy_glResetHistogramEXT(GLenum target)                                   {if (GLeeInit()) glResetHistogramEXT(target);}
void __stdcall _Lazy_glResetMinmaxEXT(GLenum target)                                      {if (GLeeInit()) glResetMinmaxEXT(target);}
PFNGLGETHISTOGRAMEXTPROC pglGetHistogramEXT=_Lazy_glGetHistogramEXT;
PFNGLGETHISTOGRAMPARAMETERFVEXTPROC pglGetHistogramParameterfvEXT=_Lazy_glGetHistogramParameterfvEXT;
PFNGLGETHISTOGRAMPARAMETERIVEXTPROC pglGetHistogramParameterivEXT=_Lazy_glGetHistogramParameterivEXT;
PFNGLGETMINMAXEXTPROC pglGetMinmaxEXT=_Lazy_glGetMinmaxEXT;
PFNGLGETMINMAXPARAMETERFVEXTPROC pglGetMinmaxParameterfvEXT=_Lazy_glGetMinmaxParameterfvEXT;
PFNGLGETMINMAXPARAMETERIVEXTPROC pglGetMinmaxParameterivEXT=_Lazy_glGetMinmaxParameterivEXT;
PFNGLHISTOGRAMEXTPROC pglHistogramEXT=_Lazy_glHistogramEXT;
PFNGLMINMAXEXTPROC pglMinmaxEXT=_Lazy_glMinmaxEXT;
PFNGLRESETHISTOGRAMEXTPROC pglResetHistogramEXT=_Lazy_glResetHistogramEXT;
PFNGLRESETMINMAXEXTPROC pglResetMinmaxEXT=_Lazy_glResetMinmaxEXT;
#endif 

/* GL_EXT_convolution */

#ifdef __GLEE_GL_EXT_convolution
void __stdcall _Lazy_glConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image)  {if (GLeeInit()) glConvolutionFilter1DEXT(target, internalformat, width, format, type, image);}
void __stdcall _Lazy_glConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image)  {if (GLeeInit()) glConvolutionFilter2DEXT(target, internalformat, width, height, format, type, image);}
void __stdcall _Lazy_glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params)  {if (GLeeInit()) glConvolutionParameterfEXT(target, pname, params);}
void __stdcall _Lazy_glConvolutionParameterfvEXT(GLenum target, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glConvolutionParameterfvEXT(target, pname, params);}
void __stdcall _Lazy_glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params)  {if (GLeeInit()) glConvolutionParameteriEXT(target, pname, params);}
void __stdcall _Lazy_glConvolutionParameterivEXT(GLenum target, GLenum pname, const GLint * params)  {if (GLeeInit()) glConvolutionParameterivEXT(target, pname, params);}
void __stdcall _Lazy_glCopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)  {if (GLeeInit()) glCopyConvolutionFilter1DEXT(target, internalformat, x, y, width);}
void __stdcall _Lazy_glCopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height)  {if (GLeeInit()) glCopyConvolutionFilter2DEXT(target, internalformat, x, y, width, height);}
void __stdcall _Lazy_glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid * image)  {if (GLeeInit()) glGetConvolutionFilterEXT(target, format, type, image);}
void __stdcall _Lazy_glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetConvolutionParameterfvEXT(target, pname, params);}
void __stdcall _Lazy_glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetConvolutionParameterivEXT(target, pname, params);}
void __stdcall _Lazy_glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span)  {if (GLeeInit()) glGetSeparableFilterEXT(target, format, type, row, column, span);}
void __stdcall _Lazy_glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column)  {if (GLeeInit()) glSeparableFilter2DEXT(target, internalformat, width, height, format, type, row, column);}
PFNGLCONVOLUTIONFILTER1DEXTPROC pglConvolutionFilter1DEXT=_Lazy_glConvolutionFilter1DEXT;
PFNGLCONVOLUTIONFILTER2DEXTPROC pglConvolutionFilter2DEXT=_Lazy_glConvolutionFilter2DEXT;
PFNGLCONVOLUTIONPARAMETERFEXTPROC pglConvolutionParameterfEXT=_Lazy_glConvolutionParameterfEXT;
PFNGLCONVOLUTIONPARAMETERFVEXTPROC pglConvolutionParameterfvEXT=_Lazy_glConvolutionParameterfvEXT;
PFNGLCONVOLUTIONPARAMETERIEXTPROC pglConvolutionParameteriEXT=_Lazy_glConvolutionParameteriEXT;
PFNGLCONVOLUTIONPARAMETERIVEXTPROC pglConvolutionParameterivEXT=_Lazy_glConvolutionParameterivEXT;
PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC pglCopyConvolutionFilter1DEXT=_Lazy_glCopyConvolutionFilter1DEXT;
PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC pglCopyConvolutionFilter2DEXT=_Lazy_glCopyConvolutionFilter2DEXT;
PFNGLGETCONVOLUTIONFILTEREXTPROC pglGetConvolutionFilterEXT=_Lazy_glGetConvolutionFilterEXT;
PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC pglGetConvolutionParameterfvEXT=_Lazy_glGetConvolutionParameterfvEXT;
PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC pglGetConvolutionParameterivEXT=_Lazy_glGetConvolutionParameterivEXT;
PFNGLGETSEPARABLEFILTEREXTPROC pglGetSeparableFilterEXT=_Lazy_glGetSeparableFilterEXT;
PFNGLSEPARABLEFILTER2DEXTPROC pglSeparableFilter2DEXT=_Lazy_glSeparableFilter2DEXT;
#endif 

/* GL_SGI_color_matrix */

#ifdef __GLEE_GL_SGI_color_matrix
#endif 

/* GL_SGI_color_table */

#ifdef __GLEE_GL_SGI_color_table
void __stdcall _Lazy_glColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table)  {if (GLeeInit()) glColorTableSGI(target, internalformat, width, format, type, table);}
void __stdcall _Lazy_glColorTableParameterfvSGI(GLenum target, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glColorTableParameterfvSGI(target, pname, params);}
void __stdcall _Lazy_glColorTableParameterivSGI(GLenum target, GLenum pname, const GLint * params)  {if (GLeeInit()) glColorTableParameterivSGI(target, pname, params);}
void __stdcall _Lazy_glCopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)  {if (GLeeInit()) glCopyColorTableSGI(target, internalformat, x, y, width);}
void __stdcall _Lazy_glGetColorTableSGI(GLenum target, GLenum format, GLenum type, GLvoid * table)  {if (GLeeInit()) glGetColorTableSGI(target, format, type, table);}
void __stdcall _Lazy_glGetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetColorTableParameterfvSGI(target, pname, params);}
void __stdcall _Lazy_glGetColorTableParameterivSGI(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetColorTableParameterivSGI(target, pname, params);}
PFNGLCOLORTABLESGIPROC pglColorTableSGI=_Lazy_glColorTableSGI;
PFNGLCOLORTABLEPARAMETERFVSGIPROC pglColorTableParameterfvSGI=_Lazy_glColorTableParameterfvSGI;
PFNGLCOLORTABLEPARAMETERIVSGIPROC pglColorTableParameterivSGI=_Lazy_glColorTableParameterivSGI;
PFNGLCOPYCOLORTABLESGIPROC pglCopyColorTableSGI=_Lazy_glCopyColorTableSGI;
PFNGLGETCOLORTABLESGIPROC pglGetColorTableSGI=_Lazy_glGetColorTableSGI;
PFNGLGETCOLORTABLEPARAMETERFVSGIPROC pglGetColorTableParameterfvSGI=_Lazy_glGetColorTableParameterfvSGI;
PFNGLGETCOLORTABLEPARAMETERIVSGIPROC pglGetColorTableParameterivSGI=_Lazy_glGetColorTableParameterivSGI;
#endif 

/* GL_SGIS_pixel_texture */

#ifdef __GLEE_GL_SGIS_pixel_texture
void __stdcall _Lazy_glPixelTexGenParameteriSGIS(GLenum pname, GLint param)               {if (GLeeInit()) glPixelTexGenParameteriSGIS(pname, param);}
void __stdcall _Lazy_glPixelTexGenParameterivSGIS(GLenum pname, const GLint * params)     {if (GLeeInit()) glPixelTexGenParameterivSGIS(pname, params);}
void __stdcall _Lazy_glPixelTexGenParameterfSGIS(GLenum pname, GLfloat param)             {if (GLeeInit()) glPixelTexGenParameterfSGIS(pname, param);}
void __stdcall _Lazy_glPixelTexGenParameterfvSGIS(GLenum pname, const GLfloat * params)   {if (GLeeInit()) glPixelTexGenParameterfvSGIS(pname, params);}
void __stdcall _Lazy_glGetPixelTexGenParameterivSGIS(GLenum pname, GLint * params)        {if (GLeeInit()) glGetPixelTexGenParameterivSGIS(pname, params);}
void __stdcall _Lazy_glGetPixelTexGenParameterfvSGIS(GLenum pname, GLfloat * params)      {if (GLeeInit()) glGetPixelTexGenParameterfvSGIS(pname, params);}
PFNGLPIXELTEXGENPARAMETERISGISPROC pglPixelTexGenParameteriSGIS=_Lazy_glPixelTexGenParameteriSGIS;
PFNGLPIXELTEXGENPARAMETERIVSGISPROC pglPixelTexGenParameterivSGIS=_Lazy_glPixelTexGenParameterivSGIS;
PFNGLPIXELTEXGENPARAMETERFSGISPROC pglPixelTexGenParameterfSGIS=_Lazy_glPixelTexGenParameterfSGIS;
PFNGLPIXELTEXGENPARAMETERFVSGISPROC pglPixelTexGenParameterfvSGIS=_Lazy_glPixelTexGenParameterfvSGIS;
PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC pglGetPixelTexGenParameterivSGIS=_Lazy_glGetPixelTexGenParameterivSGIS;
PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC pglGetPixelTexGenParameterfvSGIS=_Lazy_glGetPixelTexGenParameterfvSGIS;
#endif 

/* GL_SGIX_pixel_texture */

#ifdef __GLEE_GL_SGIX_pixel_texture
void __stdcall _Lazy_glPixelTexGenSGIX(GLenum mode)                                       {if (GLeeInit()) glPixelTexGenSGIX(mode);}
PFNGLPIXELTEXGENSGIXPROC pglPixelTexGenSGIX=_Lazy_glPixelTexGenSGIX;
#endif 

/* GL_SGIS_texture4D */

#ifdef __GLEE_GL_SGIS_texture4D
void __stdcall _Lazy_glTexImage4DSGIS(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const GLvoid * pixels)  {if (GLeeInit()) glTexImage4DSGIS(target, level, internalformat, width, height, depth, size4d, border, format, type, pixels);}
void __stdcall _Lazy_glTexSubImage4DSGIS(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const GLvoid * pixels)  {if (GLeeInit()) glTexSubImage4DSGIS(target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels);}
PFNGLTEXIMAGE4DSGISPROC pglTexImage4DSGIS=_Lazy_glTexImage4DSGIS;
PFNGLTEXSUBIMAGE4DSGISPROC pglTexSubImage4DSGIS=_Lazy_glTexSubImage4DSGIS;
#endif 

/* GL_SGI_texture_color_table */

#ifdef __GLEE_GL_SGI_texture_color_table
#endif 

/* GL_EXT_cmyka */

#ifdef __GLEE_GL_EXT_cmyka
#endif 

/* GL_EXT_texture_object */

#ifdef __GLEE_GL_EXT_texture_object
GLboolean __stdcall _Lazy_glAreTexturesResidentEXT(GLsizei n, const GLuint * textures, GLboolean * residences)  {if (GLeeInit()) return glAreTexturesResidentEXT(n, textures, residences); return (GLboolean)0;}
void __stdcall _Lazy_glBindTextureEXT(GLenum target, GLuint texture)                      {if (GLeeInit()) glBindTextureEXT(target, texture);}
void __stdcall _Lazy_glDeleteTexturesEXT(GLsizei n, const GLuint * textures)              {if (GLeeInit()) glDeleteTexturesEXT(n, textures);}
void __stdcall _Lazy_glGenTexturesEXT(GLsizei n, GLuint * textures)                       {if (GLeeInit()) glGenTexturesEXT(n, textures);}
GLboolean __stdcall _Lazy_glIsTextureEXT(GLuint texture)                                  {if (GLeeInit()) return glIsTextureEXT(texture); return (GLboolean)0;}
void __stdcall _Lazy_glPrioritizeTexturesEXT(GLsizei n, const GLuint * textures, const GLclampf * priorities)  {if (GLeeInit()) glPrioritizeTexturesEXT(n, textures, priorities);}
PFNGLARETEXTURESRESIDENTEXTPROC pglAreTexturesResidentEXT=_Lazy_glAreTexturesResidentEXT;
PFNGLBINDTEXTUREEXTPROC pglBindTextureEXT=_Lazy_glBindTextureEXT;
PFNGLDELETETEXTURESEXTPROC pglDeleteTexturesEXT=_Lazy_glDeleteTexturesEXT;
PFNGLGENTEXTURESEXTPROC pglGenTexturesEXT=_Lazy_glGenTexturesEXT;
PFNGLISTEXTUREEXTPROC pglIsTextureEXT=_Lazy_glIsTextureEXT;
PFNGLPRIORITIZETEXTURESEXTPROC pglPrioritizeTexturesEXT=_Lazy_glPrioritizeTexturesEXT;
#endif 

/* GL_SGIS_detail_texture */

#ifdef __GLEE_GL_SGIS_detail_texture
void __stdcall _Lazy_glDetailTexFuncSGIS(GLenum target, GLsizei n, const GLfloat * points)  {if (GLeeInit()) glDetailTexFuncSGIS(target, n, points);}
void __stdcall _Lazy_glGetDetailTexFuncSGIS(GLenum target, GLfloat * points)              {if (GLeeInit()) glGetDetailTexFuncSGIS(target, points);}
PFNGLDETAILTEXFUNCSGISPROC pglDetailTexFuncSGIS=_Lazy_glDetailTexFuncSGIS;
PFNGLGETDETAILTEXFUNCSGISPROC pglGetDetailTexFuncSGIS=_Lazy_glGetDetailTexFuncSGIS;
#endif 

/* GL_SGIS_sharpen_texture */

#ifdef __GLEE_GL_SGIS_sharpen_texture
void __stdcall _Lazy_glSharpenTexFuncSGIS(GLenum target, GLsizei n, const GLfloat * points)  {if (GLeeInit()) glSharpenTexFuncSGIS(target, n, points);}
void __stdcall _Lazy_glGetSharpenTexFuncSGIS(GLenum target, GLfloat * points)             {if (GLeeInit()) glGetSharpenTexFuncSGIS(target, points);}
PFNGLSHARPENTEXFUNCSGISPROC pglSharpenTexFuncSGIS=_Lazy_glSharpenTexFuncSGIS;
PFNGLGETSHARPENTEXFUNCSGISPROC pglGetSharpenTexFuncSGIS=_Lazy_glGetSharpenTexFuncSGIS;
#endif 

/* GL_EXT_packed_pixels */

#ifdef __GLEE_GL_EXT_packed_pixels
#endif 

/* GL_SGIS_texture_lod */

#ifdef __GLEE_GL_SGIS_texture_lod
#endif 

/* GL_SGIS_multisample */

#ifdef __GLEE_GL_SGIS_multisample
void __stdcall _Lazy_glSampleMaskSGIS(GLclampf value, GLboolean invert)                   {if (GLeeInit()) glSampleMaskSGIS(value, invert);}
void __stdcall _Lazy_glSamplePatternSGIS(GLenum pattern)                                  {if (GLeeInit()) glSamplePatternSGIS(pattern);}
PFNGLSAMPLEMASKSGISPROC pglSampleMaskSGIS=_Lazy_glSampleMaskSGIS;
PFNGLSAMPLEPATTERNSGISPROC pglSamplePatternSGIS=_Lazy_glSamplePatternSGIS;
#endif 

/* GL_EXT_rescale_normal */

#ifdef __GLEE_GL_EXT_rescale_normal
#endif 

/* GL_EXT_vertex_array */

#ifdef __GLEE_GL_EXT_vertex_array
void __stdcall _Lazy_glArrayElementEXT(GLint i)                                           {if (GLeeInit()) glArrayElementEXT(i);}
void __stdcall _Lazy_glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer)  {if (GLeeInit()) glColorPointerEXT(size, type, stride, count, pointer);}
void __stdcall _Lazy_glDrawArraysEXT(GLenum mode, GLint first, GLsizei count)             {if (GLeeInit()) glDrawArraysEXT(mode, first, count);}
void __stdcall _Lazy_glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean * pointer)  {if (GLeeInit()) glEdgeFlagPointerEXT(stride, count, pointer);}
void __stdcall _Lazy_glGetPointervEXT(GLenum pname, GLvoid* * params)                     {if (GLeeInit()) glGetPointervEXT(pname, params);}
void __stdcall _Lazy_glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer)  {if (GLeeInit()) glIndexPointerEXT(type, stride, count, pointer);}
void __stdcall _Lazy_glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer)  {if (GLeeInit()) glNormalPointerEXT(type, stride, count, pointer);}
void __stdcall _Lazy_glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer)  {if (GLeeInit()) glTexCoordPointerEXT(size, type, stride, count, pointer);}
void __stdcall _Lazy_glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer)  {if (GLeeInit()) glVertexPointerEXT(size, type, stride, count, pointer);}
PFNGLARRAYELEMENTEXTPROC pglArrayElementEXT=_Lazy_glArrayElementEXT;
PFNGLCOLORPOINTEREXTPROC pglColorPointerEXT=_Lazy_glColorPointerEXT;
PFNGLDRAWARRAYSEXTPROC pglDrawArraysEXT=_Lazy_glDrawArraysEXT;
PFNGLEDGEFLAGPOINTEREXTPROC pglEdgeFlagPointerEXT=_Lazy_glEdgeFlagPointerEXT;
PFNGLGETPOINTERVEXTPROC pglGetPointervEXT=_Lazy_glGetPointervEXT;
PFNGLINDEXPOINTEREXTPROC pglIndexPointerEXT=_Lazy_glIndexPointerEXT;
PFNGLNORMALPOINTEREXTPROC pglNormalPointerEXT=_Lazy_glNormalPointerEXT;
PFNGLTEXCOORDPOINTEREXTPROC pglTexCoordPointerEXT=_Lazy_glTexCoordPointerEXT;
PFNGLVERTEXPOINTEREXTPROC pglVertexPointerEXT=_Lazy_glVertexPointerEXT;
#endif 

/* GL_EXT_misc_attribute */

#ifdef __GLEE_GL_EXT_misc_attribute
#endif 

/* GL_SGIS_generate_mipmap */

#ifdef __GLEE_GL_SGIS_generate_mipmap
#endif 

/* GL_SGIX_clipmap */

#ifdef __GLEE_GL_SGIX_clipmap
#endif 

/* GL_SGIX_shadow */

#ifdef __GLEE_GL_SGIX_shadow
#endif 

/* GL_SGIS_texture_edge_clamp */

#ifdef __GLEE_GL_SGIS_texture_edge_clamp
#endif 

/* GL_SGIS_texture_border_clamp */

#ifdef __GLEE_GL_SGIS_texture_border_clamp
#endif 

/* GL_EXT_blend_minmax */

#ifdef __GLEE_GL_EXT_blend_minmax
void __stdcall _Lazy_glBlendEquationEXT(GLenum mode)                                      {if (GLeeInit()) glBlendEquationEXT(mode);}
PFNGLBLENDEQUATIONEXTPROC pglBlendEquationEXT=_Lazy_glBlendEquationEXT;
#endif 

/* GL_EXT_blend_subtract */

#ifdef __GLEE_GL_EXT_blend_subtract
#endif 

/* GL_EXT_blend_logic_op */

#ifdef __GLEE_GL_EXT_blend_logic_op
#endif 

/* GL_SGIX_interlace */

#ifdef __GLEE_GL_SGIX_interlace
#endif 

/* GL_SGIX_pixel_tiles */

#ifdef __GLEE_GL_SGIX_pixel_tiles
#endif 

/* GL_SGIS_texture_select */

#ifdef __GLEE_GL_SGIS_texture_select
#endif 

/* GL_SGIX_sprite */

#ifdef __GLEE_GL_SGIX_sprite
void __stdcall _Lazy_glSpriteParameterfSGIX(GLenum pname, GLfloat param)                  {if (GLeeInit()) glSpriteParameterfSGIX(pname, param);}
void __stdcall _Lazy_glSpriteParameterfvSGIX(GLenum pname, const GLfloat * params)        {if (GLeeInit()) glSpriteParameterfvSGIX(pname, params);}
void __stdcall _Lazy_glSpriteParameteriSGIX(GLenum pname, GLint param)                    {if (GLeeInit()) glSpriteParameteriSGIX(pname, param);}
void __stdcall _Lazy_glSpriteParameterivSGIX(GLenum pname, const GLint * params)          {if (GLeeInit()) glSpriteParameterivSGIX(pname, params);}
PFNGLSPRITEPARAMETERFSGIXPROC pglSpriteParameterfSGIX=_Lazy_glSpriteParameterfSGIX;
PFNGLSPRITEPARAMETERFVSGIXPROC pglSpriteParameterfvSGIX=_Lazy_glSpriteParameterfvSGIX;
PFNGLSPRITEPARAMETERISGIXPROC pglSpriteParameteriSGIX=_Lazy_glSpriteParameteriSGIX;
PFNGLSPRITEPARAMETERIVSGIXPROC pglSpriteParameterivSGIX=_Lazy_glSpriteParameterivSGIX;
#endif 

/* GL_SGIX_texture_multi_buffer */

#ifdef __GLEE_GL_SGIX_texture_multi_buffer
#endif 

/* GL_EXT_point_parameters */

#ifdef __GLEE_GL_EXT_point_parameters
void __stdcall _Lazy_glPointParameterfEXT(GLenum pname, GLfloat param)                    {if (GLeeInit()) glPointParameterfEXT(pname, param);}
void __stdcall _Lazy_glPointParameterfvEXT(GLenum pname, const GLfloat * params)          {if (GLeeInit()) glPointParameterfvEXT(pname, params);}
PFNGLPOINTPARAMETERFEXTPROC pglPointParameterfEXT=_Lazy_glPointParameterfEXT;
PFNGLPOINTPARAMETERFVEXTPROC pglPointParameterfvEXT=_Lazy_glPointParameterfvEXT;
#endif 

/* GL_SGIS_point_parameters */

#ifdef __GLEE_GL_SGIS_point_parameters
void __stdcall _Lazy_glPointParameterfSGIS(GLenum pname, GLfloat param)                   {if (GLeeInit()) glPointParameterfSGIS(pname, param);}
void __stdcall _Lazy_glPointParameterfvSGIS(GLenum pname, const GLfloat * params)         {if (GLeeInit()) glPointParameterfvSGIS(pname, params);}
PFNGLPOINTPARAMETERFSGISPROC pglPointParameterfSGIS=_Lazy_glPointParameterfSGIS;
PFNGLPOINTPARAMETERFVSGISPROC pglPointParameterfvSGIS=_Lazy_glPointParameterfvSGIS;
#endif 

/* GL_SGIX_instruments */

#ifdef __GLEE_GL_SGIX_instruments
GLint __stdcall _Lazy_glGetInstrumentsSGIX(void)                                          {if (GLeeInit()) return glGetInstrumentsSGIX(); return (GLint)0;}
void __stdcall _Lazy_glInstrumentsBufferSGIX(GLsizei size, GLint * buffer)                {if (GLeeInit()) glInstrumentsBufferSGIX(size, buffer);}
GLint __stdcall _Lazy_glPollInstrumentsSGIX(GLint * marker_p)                             {if (GLeeInit()) return glPollInstrumentsSGIX(marker_p); return (GLint)0;}
void __stdcall _Lazy_glReadInstrumentsSGIX(GLint marker)                                  {if (GLeeInit()) glReadInstrumentsSGIX(marker);}
void __stdcall _Lazy_glStartInstrumentsSGIX(void)                                         {if (GLeeInit()) glStartInstrumentsSGIX();}
void __stdcall _Lazy_glStopInstrumentsSGIX(GLint marker)                                  {if (GLeeInit()) glStopInstrumentsSGIX(marker);}
PFNGLGETINSTRUMENTSSGIXPROC pglGetInstrumentsSGIX=_Lazy_glGetInstrumentsSGIX;
PFNGLINSTRUMENTSBUFFERSGIXPROC pglInstrumentsBufferSGIX=_Lazy_glInstrumentsBufferSGIX;
PFNGLPOLLINSTRUMENTSSGIXPROC pglPollInstrumentsSGIX=_Lazy_glPollInstrumentsSGIX;
PFNGLREADINSTRUMENTSSGIXPROC pglReadInstrumentsSGIX=_Lazy_glReadInstrumentsSGIX;
PFNGLSTARTINSTRUMENTSSGIXPROC pglStartInstrumentsSGIX=_Lazy_glStartInstrumentsSGIX;
PFNGLSTOPINSTRUMENTSSGIXPROC pglStopInstrumentsSGIX=_Lazy_glStopInstrumentsSGIX;
#endif 

/* GL_SGIX_texture_scale_bias */

#ifdef __GLEE_GL_SGIX_texture_scale_bias
#endif 

/* GL_SGIX_framezoom */

#ifdef __GLEE_GL_SGIX_framezoom
void __stdcall _Lazy_glFrameZoomSGIX(GLint factor)                                        {if (GLeeInit()) glFrameZoomSGIX(factor);}
PFNGLFRAMEZOOMSGIXPROC pglFrameZoomSGIX=_Lazy_glFrameZoomSGIX;
#endif 

/* GL_SGIX_tag_sample_buffer */

#ifdef __GLEE_GL_SGIX_tag_sample_buffer
void __stdcall _Lazy_glTagSampleBufferSGIX(void)                                          {if (GLeeInit()) glTagSampleBufferSGIX();}
PFNGLTAGSAMPLEBUFFERSGIXPROC pglTagSampleBufferSGIX=_Lazy_glTagSampleBufferSGIX;
#endif 

/* GL_FfdMaskSGIX */

#ifdef __GLEE_GL_FfdMaskSGIX
#endif 

/* GL_SGIX_polynomial_ffd */

#ifdef __GLEE_GL_SGIX_polynomial_ffd
void __stdcall _Lazy_glDeformationMap3dSGIX(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble * points)  {if (GLeeInit()) glDeformationMap3dSGIX(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points);}
void __stdcall _Lazy_glDeformationMap3fSGIX(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat * points)  {if (GLeeInit()) glDeformationMap3fSGIX(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points);}
void __stdcall _Lazy_glDeformSGIX(GLbitfield mask)                                        {if (GLeeInit()) glDeformSGIX(mask);}
void __stdcall _Lazy_glLoadIdentityDeformationMapSGIX(GLbitfield mask)                    {if (GLeeInit()) glLoadIdentityDeformationMapSGIX(mask);}
PFNGLDEFORMATIONMAP3DSGIXPROC pglDeformationMap3dSGIX=_Lazy_glDeformationMap3dSGIX;
PFNGLDEFORMATIONMAP3FSGIXPROC pglDeformationMap3fSGIX=_Lazy_glDeformationMap3fSGIX;
PFNGLDEFORMSGIXPROC pglDeformSGIX=_Lazy_glDeformSGIX;
PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC pglLoadIdentityDeformationMapSGIX=_Lazy_glLoadIdentityDeformationMapSGIX;
#endif 

/* GL_SGIX_reference_plane */

#ifdef __GLEE_GL_SGIX_reference_plane
void __stdcall _Lazy_glReferencePlaneSGIX(const GLdouble * equation)                      {if (GLeeInit()) glReferencePlaneSGIX(equation);}
PFNGLREFERENCEPLANESGIXPROC pglReferencePlaneSGIX=_Lazy_glReferencePlaneSGIX;
#endif 

/* GL_SGIX_flush_raster */

#ifdef __GLEE_GL_SGIX_flush_raster
void __stdcall _Lazy_glFlushRasterSGIX(void)                                              {if (GLeeInit()) glFlushRasterSGIX();}
PFNGLFLUSHRASTERSGIXPROC pglFlushRasterSGIX=_Lazy_glFlushRasterSGIX;
#endif 

/* GL_SGIX_depth_texture */

#ifdef __GLEE_GL_SGIX_depth_texture
#endif 

/* GL_SGIS_fog_function */

#ifdef __GLEE_GL_SGIS_fog_function
void __stdcall _Lazy_glFogFuncSGIS(GLsizei n, const GLfloat * points)                     {if (GLeeInit()) glFogFuncSGIS(n, points);}
void __stdcall _Lazy_glGetFogFuncSGIS(GLfloat * points)                                   {if (GLeeInit()) glGetFogFuncSGIS(points);}
PFNGLFOGFUNCSGISPROC pglFogFuncSGIS=_Lazy_glFogFuncSGIS;
PFNGLGETFOGFUNCSGISPROC pglGetFogFuncSGIS=_Lazy_glGetFogFuncSGIS;
#endif 

/* GL_SGIX_fog_offset */

#ifdef __GLEE_GL_SGIX_fog_offset
#endif 

/* GL_HP_image_transform */

#ifdef __GLEE_GL_HP_image_transform
void __stdcall _Lazy_glImageTransformParameteriHP(GLenum target, GLenum pname, GLint param)  {if (GLeeInit()) glImageTransformParameteriHP(target, pname, param);}
void __stdcall _Lazy_glImageTransformParameterfHP(GLenum target, GLenum pname, GLfloat param)  {if (GLeeInit()) glImageTransformParameterfHP(target, pname, param);}
void __stdcall _Lazy_glImageTransformParameterivHP(GLenum target, GLenum pname, const GLint * params)  {if (GLeeInit()) glImageTransformParameterivHP(target, pname, params);}
void __stdcall _Lazy_glImageTransformParameterfvHP(GLenum target, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glImageTransformParameterfvHP(target, pname, params);}
void __stdcall _Lazy_glGetImageTransformParameterivHP(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetImageTransformParameterivHP(target, pname, params);}
void __stdcall _Lazy_glGetImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetImageTransformParameterfvHP(target, pname, params);}
PFNGLIMAGETRANSFORMPARAMETERIHPPROC pglImageTransformParameteriHP=_Lazy_glImageTransformParameteriHP;
PFNGLIMAGETRANSFORMPARAMETERFHPPROC pglImageTransformParameterfHP=_Lazy_glImageTransformParameterfHP;
PFNGLIMAGETRANSFORMPARAMETERIVHPPROC pglImageTransformParameterivHP=_Lazy_glImageTransformParameterivHP;
PFNGLIMAGETRANSFORMPARAMETERFVHPPROC pglImageTransformParameterfvHP=_Lazy_glImageTransformParameterfvHP;
PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC pglGetImageTransformParameterivHP=_Lazy_glGetImageTransformParameterivHP;
PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC pglGetImageTransformParameterfvHP=_Lazy_glGetImageTransformParameterfvHP;
#endif 

/* GL_HP_convolution_border_modes */

#ifdef __GLEE_GL_HP_convolution_border_modes
#endif 

/* GL_INGR_palette_buffer */

#ifdef __GLEE_GL_INGR_palette_buffer
#endif 

/* GL_SGIX_texture_add_env */

#ifdef __GLEE_GL_SGIX_texture_add_env
#endif 

/* GL_EXT_color_subtable */

#ifdef __GLEE_GL_EXT_color_subtable
void __stdcall _Lazy_glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data)  {if (GLeeInit()) glColorSubTableEXT(target, start, count, format, type, data);}
void __stdcall _Lazy_glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width)  {if (GLeeInit()) glCopyColorSubTableEXT(target, start, x, y, width);}
PFNGLCOLORSUBTABLEEXTPROC pglColorSubTableEXT=_Lazy_glColorSubTableEXT;
PFNGLCOPYCOLORSUBTABLEEXTPROC pglCopyColorSubTableEXT=_Lazy_glCopyColorSubTableEXT;
#endif 

/* GL_PGI_vertex_hints */

#ifdef __GLEE_GL_PGI_vertex_hints
#endif 

/* GL_PGI_misc_hints */

#ifdef __GLEE_GL_PGI_misc_hints
void __stdcall _Lazy_glHintPGI(GLenum target, GLint mode)                                 {if (GLeeInit()) glHintPGI(target, mode);}
PFNGLHINTPGIPROC pglHintPGI=_Lazy_glHintPGI;
#endif 

/* GL_EXT_paletted_texture */

#ifdef __GLEE_GL_EXT_paletted_texture
void __stdcall _Lazy_glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid * table)  {if (GLeeInit()) glColorTableEXT(target, internalFormat, width, format, type, table);}
void __stdcall _Lazy_glGetColorTableEXT(GLenum target, GLenum format, GLenum type, GLvoid * data)  {if (GLeeInit()) glGetColorTableEXT(target, format, type, data);}
void __stdcall _Lazy_glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetColorTableParameterivEXT(target, pname, params);}
void __stdcall _Lazy_glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetColorTableParameterfvEXT(target, pname, params);}
PFNGLCOLORTABLEEXTPROC pglColorTableEXT=_Lazy_glColorTableEXT;
PFNGLGETCOLORTABLEEXTPROC pglGetColorTableEXT=_Lazy_glGetColorTableEXT;
PFNGLGETCOLORTABLEPARAMETERIVEXTPROC pglGetColorTableParameterivEXT=_Lazy_glGetColorTableParameterivEXT;
PFNGLGETCOLORTABLEPARAMETERFVEXTPROC pglGetColorTableParameterfvEXT=_Lazy_glGetColorTableParameterfvEXT;
#endif 

/* GL_EXT_clip_volume_hint */

#ifdef __GLEE_GL_EXT_clip_volume_hint
#endif 

/* GL_SGIX_list_priority */

#ifdef __GLEE_GL_SGIX_list_priority
void __stdcall _Lazy_glGetListParameterfvSGIX(GLuint list, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetListParameterfvSGIX(list, pname, params);}
void __stdcall _Lazy_glGetListParameterivSGIX(GLuint list, GLenum pname, GLint * params)  {if (GLeeInit()) glGetListParameterivSGIX(list, pname, params);}
void __stdcall _Lazy_glListParameterfSGIX(GLuint list, GLenum pname, GLfloat param)       {if (GLeeInit()) glListParameterfSGIX(list, pname, param);}
void __stdcall _Lazy_glListParameterfvSGIX(GLuint list, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glListParameterfvSGIX(list, pname, params);}
void __stdcall _Lazy_glListParameteriSGIX(GLuint list, GLenum pname, GLint param)         {if (GLeeInit()) glListParameteriSGIX(list, pname, param);}
void __stdcall _Lazy_glListParameterivSGIX(GLuint list, GLenum pname, const GLint * params)  {if (GLeeInit()) glListParameterivSGIX(list, pname, params);}
PFNGLGETLISTPARAMETERFVSGIXPROC pglGetListParameterfvSGIX=_Lazy_glGetListParameterfvSGIX;
PFNGLGETLISTPARAMETERIVSGIXPROC pglGetListParameterivSGIX=_Lazy_glGetListParameterivSGIX;
PFNGLLISTPARAMETERFSGIXPROC pglListParameterfSGIX=_Lazy_glListParameterfSGIX;
PFNGLLISTPARAMETERFVSGIXPROC pglListParameterfvSGIX=_Lazy_glListParameterfvSGIX;
PFNGLLISTPARAMETERISGIXPROC pglListParameteriSGIX=_Lazy_glListParameteriSGIX;
PFNGLLISTPARAMETERIVSGIXPROC pglListParameterivSGIX=_Lazy_glListParameterivSGIX;
#endif 

/* GL_SGIX_ir_instrument1 */

#ifdef __GLEE_GL_SGIX_ir_instrument1
#endif 

/* GL_SGIX_calligraphic_fragment */

#ifdef __GLEE_GL_SGIX_calligraphic_fragment
#endif 

/* GL_SGIX_texture_lod_bias */

#ifdef __GLEE_GL_SGIX_texture_lod_bias
#endif 

/* GL_SGIX_shadow_ambient */

#ifdef __GLEE_GL_SGIX_shadow_ambient
#endif 

/* GL_EXT_index_texture */

#ifdef __GLEE_GL_EXT_index_texture
#endif 

/* GL_EXT_index_material */

#ifdef __GLEE_GL_EXT_index_material
void __stdcall _Lazy_glIndexMaterialEXT(GLenum face, GLenum mode)                         {if (GLeeInit()) glIndexMaterialEXT(face, mode);}
PFNGLINDEXMATERIALEXTPROC pglIndexMaterialEXT=_Lazy_glIndexMaterialEXT;
#endif 

/* GL_EXT_index_func */

#ifdef __GLEE_GL_EXT_index_func
void __stdcall _Lazy_glIndexFuncEXT(GLenum func, GLclampf ref)                            {if (GLeeInit()) glIndexFuncEXT(func, ref);}
PFNGLINDEXFUNCEXTPROC pglIndexFuncEXT=_Lazy_glIndexFuncEXT;
#endif 

/* GL_EXT_index_array_formats */

#ifdef __GLEE_GL_EXT_index_array_formats
#endif 

/* GL_EXT_compiled_vertex_array */

#ifdef __GLEE_GL_EXT_compiled_vertex_array
void __stdcall _Lazy_glLockArraysEXT(GLint first, GLsizei count)                          {if (GLeeInit()) glLockArraysEXT(first, count);}
void __stdcall _Lazy_glUnlockArraysEXT(void)                                              {if (GLeeInit()) glUnlockArraysEXT();}
PFNGLLOCKARRAYSEXTPROC pglLockArraysEXT=_Lazy_glLockArraysEXT;
PFNGLUNLOCKARRAYSEXTPROC pglUnlockArraysEXT=_Lazy_glUnlockArraysEXT;
#endif 

/* GL_EXT_cull_vertex */

#ifdef __GLEE_GL_EXT_cull_vertex
void __stdcall _Lazy_glCullParameterdvEXT(GLenum pname, GLdouble * params)                {if (GLeeInit()) glCullParameterdvEXT(pname, params);}
void __stdcall _Lazy_glCullParameterfvEXT(GLenum pname, GLfloat * params)                 {if (GLeeInit()) glCullParameterfvEXT(pname, params);}
PFNGLCULLPARAMETERDVEXTPROC pglCullParameterdvEXT=_Lazy_glCullParameterdvEXT;
PFNGLCULLPARAMETERFVEXTPROC pglCullParameterfvEXT=_Lazy_glCullParameterfvEXT;
#endif 

/* GL_SGIX_ycrcb */

#ifdef __GLEE_GL_SGIX_ycrcb
#endif 

/* GL_SGIX_fragment_lighting */

#ifdef __GLEE_GL_SGIX_fragment_lighting
void __stdcall _Lazy_glFragmentColorMaterialSGIX(GLenum face, GLenum mode)                {if (GLeeInit()) glFragmentColorMaterialSGIX(face, mode);}
void __stdcall _Lazy_glFragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param)      {if (GLeeInit()) glFragmentLightfSGIX(light, pname, param);}
void __stdcall _Lazy_glFragmentLightfvSGIX(GLenum light, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glFragmentLightfvSGIX(light, pname, params);}
void __stdcall _Lazy_glFragmentLightiSGIX(GLenum light, GLenum pname, GLint param)        {if (GLeeInit()) glFragmentLightiSGIX(light, pname, param);}
void __stdcall _Lazy_glFragmentLightivSGIX(GLenum light, GLenum pname, const GLint * params)  {if (GLeeInit()) glFragmentLightivSGIX(light, pname, params);}
void __stdcall _Lazy_glFragmentLightModelfSGIX(GLenum pname, GLfloat param)               {if (GLeeInit()) glFragmentLightModelfSGIX(pname, param);}
void __stdcall _Lazy_glFragmentLightModelfvSGIX(GLenum pname, const GLfloat * params)     {if (GLeeInit()) glFragmentLightModelfvSGIX(pname, params);}
void __stdcall _Lazy_glFragmentLightModeliSGIX(GLenum pname, GLint param)                 {if (GLeeInit()) glFragmentLightModeliSGIX(pname, param);}
void __stdcall _Lazy_glFragmentLightModelivSGIX(GLenum pname, const GLint * params)       {if (GLeeInit()) glFragmentLightModelivSGIX(pname, params);}
void __stdcall _Lazy_glFragmentMaterialfSGIX(GLenum face, GLenum pname, GLfloat param)    {if (GLeeInit()) glFragmentMaterialfSGIX(face, pname, param);}
void __stdcall _Lazy_glFragmentMaterialfvSGIX(GLenum face, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glFragmentMaterialfvSGIX(face, pname, params);}
void __stdcall _Lazy_glFragmentMaterialiSGIX(GLenum face, GLenum pname, GLint param)      {if (GLeeInit()) glFragmentMaterialiSGIX(face, pname, param);}
void __stdcall _Lazy_glFragmentMaterialivSGIX(GLenum face, GLenum pname, const GLint * params)  {if (GLeeInit()) glFragmentMaterialivSGIX(face, pname, params);}
void __stdcall _Lazy_glGetFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetFragmentLightfvSGIX(light, pname, params);}
void __stdcall _Lazy_glGetFragmentLightivSGIX(GLenum light, GLenum pname, GLint * params)  {if (GLeeInit()) glGetFragmentLightivSGIX(light, pname, params);}
void __stdcall _Lazy_glGetFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetFragmentMaterialfvSGIX(face, pname, params);}
void __stdcall _Lazy_glGetFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint * params)  {if (GLeeInit()) glGetFragmentMaterialivSGIX(face, pname, params);}
void __stdcall _Lazy_glLightEnviSGIX(GLenum pname, GLint param)                           {if (GLeeInit()) glLightEnviSGIX(pname, param);}
PFNGLFRAGMENTCOLORMATERIALSGIXPROC pglFragmentColorMaterialSGIX=_Lazy_glFragmentColorMaterialSGIX;
PFNGLFRAGMENTLIGHTFSGIXPROC pglFragmentLightfSGIX=_Lazy_glFragmentLightfSGIX;
PFNGLFRAGMENTLIGHTFVSGIXPROC pglFragmentLightfvSGIX=_Lazy_glFragmentLightfvSGIX;
PFNGLFRAGMENTLIGHTISGIXPROC pglFragmentLightiSGIX=_Lazy_glFragmentLightiSGIX;
PFNGLFRAGMENTLIGHTIVSGIXPROC pglFragmentLightivSGIX=_Lazy_glFragmentLightivSGIX;
PFNGLFRAGMENTLIGHTMODELFSGIXPROC pglFragmentLightModelfSGIX=_Lazy_glFragmentLightModelfSGIX;
PFNGLFRAGMENTLIGHTMODELFVSGIXPROC pglFragmentLightModelfvSGIX=_Lazy_glFragmentLightModelfvSGIX;
PFNGLFRAGMENTLIGHTMODELISGIXPROC pglFragmentLightModeliSGIX=_Lazy_glFragmentLightModeliSGIX;
PFNGLFRAGMENTLIGHTMODELIVSGIXPROC pglFragmentLightModelivSGIX=_Lazy_glFragmentLightModelivSGIX;
PFNGLFRAGMENTMATERIALFSGIXPROC pglFragmentMaterialfSGIX=_Lazy_glFragmentMaterialfSGIX;
PFNGLFRAGMENTMATERIALFVSGIXPROC pglFragmentMaterialfvSGIX=_Lazy_glFragmentMaterialfvSGIX;
PFNGLFRAGMENTMATERIALISGIXPROC pglFragmentMaterialiSGIX=_Lazy_glFragmentMaterialiSGIX;
PFNGLFRAGMENTMATERIALIVSGIXPROC pglFragmentMaterialivSGIX=_Lazy_glFragmentMaterialivSGIX;
PFNGLGETFRAGMENTLIGHTFVSGIXPROC pglGetFragmentLightfvSGIX=_Lazy_glGetFragmentLightfvSGIX;
PFNGLGETFRAGMENTLIGHTIVSGIXPROC pglGetFragmentLightivSGIX=_Lazy_glGetFragmentLightivSGIX;
PFNGLGETFRAGMENTMATERIALFVSGIXPROC pglGetFragmentMaterialfvSGIX=_Lazy_glGetFragmentMaterialfvSGIX;
PFNGLGETFRAGMENTMATERIALIVSGIXPROC pglGetFragmentMaterialivSGIX=_Lazy_glGetFragmentMaterialivSGIX;
PFNGLLIGHTENVISGIXPROC pglLightEnviSGIX=_Lazy_glLightEnviSGIX;
#endif 

/* GL_IBM_rasterpos_clip */

#ifdef __GLEE_GL_IBM_rasterpos_clip
#endif 

/* GL_HP_texture_lighting */

#ifdef __GLEE_GL_HP_texture_lighting
#endif 

/* GL_EXT_draw_range_elements */

#ifdef __GLEE_GL_EXT_draw_range_elements
void __stdcall _Lazy_glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices)  {if (GLeeInit()) glDrawRangeElementsEXT(mode, start, end, count, type, indices);}
PFNGLDRAWRANGEELEMENTSEXTPROC pglDrawRangeElementsEXT=_Lazy_glDrawRangeElementsEXT;
#endif 

/* GL_WIN_phong_shading */

#ifdef __GLEE_GL_WIN_phong_shading
#endif 

/* GL_WIN_specular_fog */

#ifdef __GLEE_GL_WIN_specular_fog
#endif 

/* GL_EXT_light_texture */

#ifdef __GLEE_GL_EXT_light_texture
void __stdcall _Lazy_glApplyTextureEXT(GLenum mode)                                       {if (GLeeInit()) glApplyTextureEXT(mode);}
void __stdcall _Lazy_glTextureLightEXT(GLenum pname)                                      {if (GLeeInit()) glTextureLightEXT(pname);}
void __stdcall _Lazy_glTextureMaterialEXT(GLenum face, GLenum mode)                       {if (GLeeInit()) glTextureMaterialEXT(face, mode);}
PFNGLAPPLYTEXTUREEXTPROC pglApplyTextureEXT=_Lazy_glApplyTextureEXT;
PFNGLTEXTURELIGHTEXTPROC pglTextureLightEXT=_Lazy_glTextureLightEXT;
PFNGLTEXTUREMATERIALEXTPROC pglTextureMaterialEXT=_Lazy_glTextureMaterialEXT;
#endif 

/* GL_SGIX_blend_alpha_minmax */

#ifdef __GLEE_GL_SGIX_blend_alpha_minmax
#endif 

/* GL_SGIX_impact_pixel_texture */

#ifdef __GLEE_GL_SGIX_impact_pixel_texture
#endif 

/* GL_EXT_bgra */

#ifdef __GLEE_GL_EXT_bgra
#endif 

/* GL_SGIX_async */

#ifdef __GLEE_GL_SGIX_async
void __stdcall _Lazy_glAsyncMarkerSGIX(GLuint marker)                                     {if (GLeeInit()) glAsyncMarkerSGIX(marker);}
GLint __stdcall _Lazy_glFinishAsyncSGIX(GLuint * markerp)                                 {if (GLeeInit()) return glFinishAsyncSGIX(markerp); return (GLint)0;}
GLint __stdcall _Lazy_glPollAsyncSGIX(GLuint * markerp)                                   {if (GLeeInit()) return glPollAsyncSGIX(markerp); return (GLint)0;}
GLuint __stdcall _Lazy_glGenAsyncMarkersSGIX(GLsizei range)                               {if (GLeeInit()) return glGenAsyncMarkersSGIX(range); return (GLuint)0;}
void __stdcall _Lazy_glDeleteAsyncMarkersSGIX(GLuint marker, GLsizei range)               {if (GLeeInit()) glDeleteAsyncMarkersSGIX(marker, range);}
GLboolean __stdcall _Lazy_glIsAsyncMarkerSGIX(GLuint marker)                              {if (GLeeInit()) return glIsAsyncMarkerSGIX(marker); return (GLboolean)0;}
PFNGLASYNCMARKERSGIXPROC pglAsyncMarkerSGIX=_Lazy_glAsyncMarkerSGIX;
PFNGLFINISHASYNCSGIXPROC pglFinishAsyncSGIX=_Lazy_glFinishAsyncSGIX;
PFNGLPOLLASYNCSGIXPROC pglPollAsyncSGIX=_Lazy_glPollAsyncSGIX;
PFNGLGENASYNCMARKERSSGIXPROC pglGenAsyncMarkersSGIX=_Lazy_glGenAsyncMarkersSGIX;
PFNGLDELETEASYNCMARKERSSGIXPROC pglDeleteAsyncMarkersSGIX=_Lazy_glDeleteAsyncMarkersSGIX;
PFNGLISASYNCMARKERSGIXPROC pglIsAsyncMarkerSGIX=_Lazy_glIsAsyncMarkerSGIX;
#endif 

/* GL_SGIX_async_pixel */

#ifdef __GLEE_GL_SGIX_async_pixel
#endif 

/* GL_SGIX_async_histogram */

#ifdef __GLEE_GL_SGIX_async_histogram
#endif 

/* GL_INTEL_texture_scissor */

#ifdef __GLEE_GL_INTEL_texture_scissor
#endif 

/* GL_INTEL_parallel_arrays */

#ifdef __GLEE_GL_INTEL_parallel_arrays
void __stdcall _Lazy_glVertexPointervINTEL(GLint size, GLenum type, const GLvoid* * pointer)  {if (GLeeInit()) glVertexPointervINTEL(size, type, pointer);}
void __stdcall _Lazy_glNormalPointervINTEL(GLenum type, const GLvoid* * pointer)          {if (GLeeInit()) glNormalPointervINTEL(type, pointer);}
void __stdcall _Lazy_glColorPointervINTEL(GLint size, GLenum type, const GLvoid* * pointer)  {if (GLeeInit()) glColorPointervINTEL(size, type, pointer);}
void __stdcall _Lazy_glTexCoordPointervINTEL(GLint size, GLenum type, const GLvoid* * pointer)  {if (GLeeInit()) glTexCoordPointervINTEL(size, type, pointer);}
PFNGLVERTEXPOINTERVINTELPROC pglVertexPointervINTEL=_Lazy_glVertexPointervINTEL;
PFNGLNORMALPOINTERVINTELPROC pglNormalPointervINTEL=_Lazy_glNormalPointervINTEL;
PFNGLCOLORPOINTERVINTELPROC pglColorPointervINTEL=_Lazy_glColorPointervINTEL;
PFNGLTEXCOORDPOINTERVINTELPROC pglTexCoordPointervINTEL=_Lazy_glTexCoordPointervINTEL;
#endif 

/* GL_HP_occlusion_test */

#ifdef __GLEE_GL_HP_occlusion_test
#endif 

/* GL_EXT_pixel_transform */

#ifdef __GLEE_GL_EXT_pixel_transform
void __stdcall _Lazy_glPixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param)  {if (GLeeInit()) glPixelTransformParameteriEXT(target, pname, param);}
void __stdcall _Lazy_glPixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param)  {if (GLeeInit()) glPixelTransformParameterfEXT(target, pname, param);}
void __stdcall _Lazy_glPixelTransformParameterivEXT(GLenum target, GLenum pname, const GLint * params)  {if (GLeeInit()) glPixelTransformParameterivEXT(target, pname, params);}
void __stdcall _Lazy_glPixelTransformParameterfvEXT(GLenum target, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glPixelTransformParameterfvEXT(target, pname, params);}
PFNGLPIXELTRANSFORMPARAMETERIEXTPROC pglPixelTransformParameteriEXT=_Lazy_glPixelTransformParameteriEXT;
PFNGLPIXELTRANSFORMPARAMETERFEXTPROC pglPixelTransformParameterfEXT=_Lazy_glPixelTransformParameterfEXT;
PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC pglPixelTransformParameterivEXT=_Lazy_glPixelTransformParameterivEXT;
PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC pglPixelTransformParameterfvEXT=_Lazy_glPixelTransformParameterfvEXT;
#endif 

/* GL_EXT_pixel_transform_color_table */

#ifdef __GLEE_GL_EXT_pixel_transform_color_table
#endif 

/* GL_EXT_shared_texture_palette */

#ifdef __GLEE_GL_EXT_shared_texture_palette
#endif 

/* GL_EXT_separate_specular_color */

#ifdef __GLEE_GL_EXT_separate_specular_color
#endif 

/* GL_EXT_secondary_color */

#ifdef __GLEE_GL_EXT_secondary_color
void __stdcall _Lazy_glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue)         {if (GLeeInit()) glSecondaryColor3bEXT(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3bvEXT(const GLbyte * v)                             {if (GLeeInit()) glSecondaryColor3bvEXT(v);}
void __stdcall _Lazy_glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue)   {if (GLeeInit()) glSecondaryColor3dEXT(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3dvEXT(const GLdouble * v)                           {if (GLeeInit()) glSecondaryColor3dvEXT(v);}
void __stdcall _Lazy_glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue)      {if (GLeeInit()) glSecondaryColor3fEXT(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3fvEXT(const GLfloat * v)                            {if (GLeeInit()) glSecondaryColor3fvEXT(v);}
void __stdcall _Lazy_glSecondaryColor3iEXT(GLint red, GLint green, GLint blue)            {if (GLeeInit()) glSecondaryColor3iEXT(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3ivEXT(const GLint * v)                              {if (GLeeInit()) glSecondaryColor3ivEXT(v);}
void __stdcall _Lazy_glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue)      {if (GLeeInit()) glSecondaryColor3sEXT(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3svEXT(const GLshort * v)                            {if (GLeeInit()) glSecondaryColor3svEXT(v);}
void __stdcall _Lazy_glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue)     {if (GLeeInit()) glSecondaryColor3ubEXT(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3ubvEXT(const GLubyte * v)                           {if (GLeeInit()) glSecondaryColor3ubvEXT(v);}
void __stdcall _Lazy_glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue)        {if (GLeeInit()) glSecondaryColor3uiEXT(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3uivEXT(const GLuint * v)                            {if (GLeeInit()) glSecondaryColor3uivEXT(v);}
void __stdcall _Lazy_glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue)  {if (GLeeInit()) glSecondaryColor3usEXT(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3usvEXT(const GLushort * v)                          {if (GLeeInit()) glSecondaryColor3usvEXT(v);}
void __stdcall _Lazy_glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glSecondaryColorPointerEXT(size, type, stride, pointer);}
PFNGLSECONDARYCOLOR3BEXTPROC pglSecondaryColor3bEXT=_Lazy_glSecondaryColor3bEXT;
PFNGLSECONDARYCOLOR3BVEXTPROC pglSecondaryColor3bvEXT=_Lazy_glSecondaryColor3bvEXT;
PFNGLSECONDARYCOLOR3DEXTPROC pglSecondaryColor3dEXT=_Lazy_glSecondaryColor3dEXT;
PFNGLSECONDARYCOLOR3DVEXTPROC pglSecondaryColor3dvEXT=_Lazy_glSecondaryColor3dvEXT;
PFNGLSECONDARYCOLOR3FEXTPROC pglSecondaryColor3fEXT=_Lazy_glSecondaryColor3fEXT;
PFNGLSECONDARYCOLOR3FVEXTPROC pglSecondaryColor3fvEXT=_Lazy_glSecondaryColor3fvEXT;
PFNGLSECONDARYCOLOR3IEXTPROC pglSecondaryColor3iEXT=_Lazy_glSecondaryColor3iEXT;
PFNGLSECONDARYCOLOR3IVEXTPROC pglSecondaryColor3ivEXT=_Lazy_glSecondaryColor3ivEXT;
PFNGLSECONDARYCOLOR3SEXTPROC pglSecondaryColor3sEXT=_Lazy_glSecondaryColor3sEXT;
PFNGLSECONDARYCOLOR3SVEXTPROC pglSecondaryColor3svEXT=_Lazy_glSecondaryColor3svEXT;
PFNGLSECONDARYCOLOR3UBEXTPROC pglSecondaryColor3ubEXT=_Lazy_glSecondaryColor3ubEXT;
PFNGLSECONDARYCOLOR3UBVEXTPROC pglSecondaryColor3ubvEXT=_Lazy_glSecondaryColor3ubvEXT;
PFNGLSECONDARYCOLOR3UIEXTPROC pglSecondaryColor3uiEXT=_Lazy_glSecondaryColor3uiEXT;
PFNGLSECONDARYCOLOR3UIVEXTPROC pglSecondaryColor3uivEXT=_Lazy_glSecondaryColor3uivEXT;
PFNGLSECONDARYCOLOR3USEXTPROC pglSecondaryColor3usEXT=_Lazy_glSecondaryColor3usEXT;
PFNGLSECONDARYCOLOR3USVEXTPROC pglSecondaryColor3usvEXT=_Lazy_glSecondaryColor3usvEXT;
PFNGLSECONDARYCOLORPOINTEREXTPROC pglSecondaryColorPointerEXT=_Lazy_glSecondaryColorPointerEXT;
#endif 

/* GL_EXT_texture_perturb_normal */

#ifdef __GLEE_GL_EXT_texture_perturb_normal
void __stdcall _Lazy_glTextureNormalEXT(GLenum mode)                                      {if (GLeeInit()) glTextureNormalEXT(mode);}
PFNGLTEXTURENORMALEXTPROC pglTextureNormalEXT=_Lazy_glTextureNormalEXT;
#endif 

/* GL_EXT_multi_draw_arrays */

#ifdef __GLEE_GL_EXT_multi_draw_arrays
void __stdcall _Lazy_glMultiDrawArraysEXT(GLenum mode, GLint * first, GLsizei * count, GLsizei primcount)  {if (GLeeInit()) glMultiDrawArraysEXT(mode, first, count, primcount);}
void __stdcall _Lazy_glMultiDrawElementsEXT(GLenum mode, const GLsizei * count, GLenum type, const GLvoid* * indices, GLsizei primcount)  {if (GLeeInit()) glMultiDrawElementsEXT(mode, count, type, indices, primcount);}
PFNGLMULTIDRAWARRAYSEXTPROC pglMultiDrawArraysEXT=_Lazy_glMultiDrawArraysEXT;
PFNGLMULTIDRAWELEMENTSEXTPROC pglMultiDrawElementsEXT=_Lazy_glMultiDrawElementsEXT;
#endif 

/* GL_EXT_fog_coord */

#ifdef __GLEE_GL_EXT_fog_coord
void __stdcall _Lazy_glFogCoordfEXT(GLfloat coord)                                        {if (GLeeInit()) glFogCoordfEXT(coord);}
void __stdcall _Lazy_glFogCoordfvEXT(const GLfloat * coord)                               {if (GLeeInit()) glFogCoordfvEXT(coord);}
void __stdcall _Lazy_glFogCoorddEXT(GLdouble coord)                                       {if (GLeeInit()) glFogCoorddEXT(coord);}
void __stdcall _Lazy_glFogCoorddvEXT(const GLdouble * coord)                              {if (GLeeInit()) glFogCoorddvEXT(coord);}
void __stdcall _Lazy_glFogCoordPointerEXT(GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glFogCoordPointerEXT(type, stride, pointer);}
PFNGLFOGCOORDFEXTPROC pglFogCoordfEXT=_Lazy_glFogCoordfEXT;
PFNGLFOGCOORDFVEXTPROC pglFogCoordfvEXT=_Lazy_glFogCoordfvEXT;
PFNGLFOGCOORDDEXTPROC pglFogCoorddEXT=_Lazy_glFogCoorddEXT;
PFNGLFOGCOORDDVEXTPROC pglFogCoorddvEXT=_Lazy_glFogCoorddvEXT;
PFNGLFOGCOORDPOINTEREXTPROC pglFogCoordPointerEXT=_Lazy_glFogCoordPointerEXT;
#endif 

/* GL_REND_screen_coordinates */

#ifdef __GLEE_GL_REND_screen_coordinates
#endif 

/* GL_EXT_coordinate_frame */

#ifdef __GLEE_GL_EXT_coordinate_frame
void __stdcall _Lazy_glTangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz)                      {if (GLeeInit()) glTangent3bEXT(tx, ty, tz);}
void __stdcall _Lazy_glTangent3bvEXT(const GLbyte * v)                                    {if (GLeeInit()) glTangent3bvEXT(v);}
void __stdcall _Lazy_glTangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz)                {if (GLeeInit()) glTangent3dEXT(tx, ty, tz);}
void __stdcall _Lazy_glTangent3dvEXT(const GLdouble * v)                                  {if (GLeeInit()) glTangent3dvEXT(v);}
void __stdcall _Lazy_glTangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz)                   {if (GLeeInit()) glTangent3fEXT(tx, ty, tz);}
void __stdcall _Lazy_glTangent3fvEXT(const GLfloat * v)                                   {if (GLeeInit()) glTangent3fvEXT(v);}
void __stdcall _Lazy_glTangent3iEXT(GLint tx, GLint ty, GLint tz)                         {if (GLeeInit()) glTangent3iEXT(tx, ty, tz);}
void __stdcall _Lazy_glTangent3ivEXT(const GLint * v)                                     {if (GLeeInit()) glTangent3ivEXT(v);}
void __stdcall _Lazy_glTangent3sEXT(GLshort tx, GLshort ty, GLshort tz)                   {if (GLeeInit()) glTangent3sEXT(tx, ty, tz);}
void __stdcall _Lazy_glTangent3svEXT(const GLshort * v)                                   {if (GLeeInit()) glTangent3svEXT(v);}
void __stdcall _Lazy_glBinormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz)                     {if (GLeeInit()) glBinormal3bEXT(bx, by, bz);}
void __stdcall _Lazy_glBinormal3bvEXT(const GLbyte * v)                                   {if (GLeeInit()) glBinormal3bvEXT(v);}
void __stdcall _Lazy_glBinormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz)               {if (GLeeInit()) glBinormal3dEXT(bx, by, bz);}
void __stdcall _Lazy_glBinormal3dvEXT(const GLdouble * v)                                 {if (GLeeInit()) glBinormal3dvEXT(v);}
void __stdcall _Lazy_glBinormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz)                  {if (GLeeInit()) glBinormal3fEXT(bx, by, bz);}
void __stdcall _Lazy_glBinormal3fvEXT(const GLfloat * v)                                  {if (GLeeInit()) glBinormal3fvEXT(v);}
void __stdcall _Lazy_glBinormal3iEXT(GLint bx, GLint by, GLint bz)                        {if (GLeeInit()) glBinormal3iEXT(bx, by, bz);}
void __stdcall _Lazy_glBinormal3ivEXT(const GLint * v)                                    {if (GLeeInit()) glBinormal3ivEXT(v);}
void __stdcall _Lazy_glBinormal3sEXT(GLshort bx, GLshort by, GLshort bz)                  {if (GLeeInit()) glBinormal3sEXT(bx, by, bz);}
void __stdcall _Lazy_glBinormal3svEXT(const GLshort * v)                                  {if (GLeeInit()) glBinormal3svEXT(v);}
void __stdcall _Lazy_glTangentPointerEXT(GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glTangentPointerEXT(type, stride, pointer);}
void __stdcall _Lazy_glBinormalPointerEXT(GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glBinormalPointerEXT(type, stride, pointer);}
PFNGLTANGENT3BEXTPROC pglTangent3bEXT=_Lazy_glTangent3bEXT;
PFNGLTANGENT3BVEXTPROC pglTangent3bvEXT=_Lazy_glTangent3bvEXT;
PFNGLTANGENT3DEXTPROC pglTangent3dEXT=_Lazy_glTangent3dEXT;
PFNGLTANGENT3DVEXTPROC pglTangent3dvEXT=_Lazy_glTangent3dvEXT;
PFNGLTANGENT3FEXTPROC pglTangent3fEXT=_Lazy_glTangent3fEXT;
PFNGLTANGENT3FVEXTPROC pglTangent3fvEXT=_Lazy_glTangent3fvEXT;
PFNGLTANGENT3IEXTPROC pglTangent3iEXT=_Lazy_glTangent3iEXT;
PFNGLTANGENT3IVEXTPROC pglTangent3ivEXT=_Lazy_glTangent3ivEXT;
PFNGLTANGENT3SEXTPROC pglTangent3sEXT=_Lazy_glTangent3sEXT;
PFNGLTANGENT3SVEXTPROC pglTangent3svEXT=_Lazy_glTangent3svEXT;
PFNGLBINORMAL3BEXTPROC pglBinormal3bEXT=_Lazy_glBinormal3bEXT;
PFNGLBINORMAL3BVEXTPROC pglBinormal3bvEXT=_Lazy_glBinormal3bvEXT;
PFNGLBINORMAL3DEXTPROC pglBinormal3dEXT=_Lazy_glBinormal3dEXT;
PFNGLBINORMAL3DVEXTPROC pglBinormal3dvEXT=_Lazy_glBinormal3dvEXT;
PFNGLBINORMAL3FEXTPROC pglBinormal3fEXT=_Lazy_glBinormal3fEXT;
PFNGLBINORMAL3FVEXTPROC pglBinormal3fvEXT=_Lazy_glBinormal3fvEXT;
PFNGLBINORMAL3IEXTPROC pglBinormal3iEXT=_Lazy_glBinormal3iEXT;
PFNGLBINORMAL3IVEXTPROC pglBinormal3ivEXT=_Lazy_glBinormal3ivEXT;
PFNGLBINORMAL3SEXTPROC pglBinormal3sEXT=_Lazy_glBinormal3sEXT;
PFNGLBINORMAL3SVEXTPROC pglBinormal3svEXT=_Lazy_glBinormal3svEXT;
PFNGLTANGENTPOINTEREXTPROC pglTangentPointerEXT=_Lazy_glTangentPointerEXT;
PFNGLBINORMALPOINTEREXTPROC pglBinormalPointerEXT=_Lazy_glBinormalPointerEXT;
#endif 

/* GL_EXT_texture_env_combine */

#ifdef __GLEE_GL_EXT_texture_env_combine
#endif 

/* GL_APPLE_specular_vector */

#ifdef __GLEE_GL_APPLE_specular_vector
#endif 

/* GL_APPLE_transform_hint */

#ifdef __GLEE_GL_APPLE_transform_hint
#endif 

/* GL_SGIX_fog_scale */

#ifdef __GLEE_GL_SGIX_fog_scale
#endif 

/* GL_SUNX_constant_data */

#ifdef __GLEE_GL_SUNX_constant_data
void __stdcall _Lazy_glFinishTextureSUNX(void)                                            {if (GLeeInit()) glFinishTextureSUNX();}
PFNGLFINISHTEXTURESUNXPROC pglFinishTextureSUNX=_Lazy_glFinishTextureSUNX;
#endif 

/* GL_SUN_global_alpha */

#ifdef __GLEE_GL_SUN_global_alpha
void __stdcall _Lazy_glGlobalAlphaFactorbSUN(GLbyte factor)                               {if (GLeeInit()) glGlobalAlphaFactorbSUN(factor);}
void __stdcall _Lazy_glGlobalAlphaFactorsSUN(GLshort factor)                              {if (GLeeInit()) glGlobalAlphaFactorsSUN(factor);}
void __stdcall _Lazy_glGlobalAlphaFactoriSUN(GLint factor)                                {if (GLeeInit()) glGlobalAlphaFactoriSUN(factor);}
void __stdcall _Lazy_glGlobalAlphaFactorfSUN(GLfloat factor)                              {if (GLeeInit()) glGlobalAlphaFactorfSUN(factor);}
void __stdcall _Lazy_glGlobalAlphaFactordSUN(GLdouble factor)                             {if (GLeeInit()) glGlobalAlphaFactordSUN(factor);}
void __stdcall _Lazy_glGlobalAlphaFactorubSUN(GLubyte factor)                             {if (GLeeInit()) glGlobalAlphaFactorubSUN(factor);}
void __stdcall _Lazy_glGlobalAlphaFactorusSUN(GLushort factor)                            {if (GLeeInit()) glGlobalAlphaFactorusSUN(factor);}
void __stdcall _Lazy_glGlobalAlphaFactoruiSUN(GLuint factor)                              {if (GLeeInit()) glGlobalAlphaFactoruiSUN(factor);}
PFNGLGLOBALALPHAFACTORBSUNPROC pglGlobalAlphaFactorbSUN=_Lazy_glGlobalAlphaFactorbSUN;
PFNGLGLOBALALPHAFACTORSSUNPROC pglGlobalAlphaFactorsSUN=_Lazy_glGlobalAlphaFactorsSUN;
PFNGLGLOBALALPHAFACTORISUNPROC pglGlobalAlphaFactoriSUN=_Lazy_glGlobalAlphaFactoriSUN;
PFNGLGLOBALALPHAFACTORFSUNPROC pglGlobalAlphaFactorfSUN=_Lazy_glGlobalAlphaFactorfSUN;
PFNGLGLOBALALPHAFACTORDSUNPROC pglGlobalAlphaFactordSUN=_Lazy_glGlobalAlphaFactordSUN;
PFNGLGLOBALALPHAFACTORUBSUNPROC pglGlobalAlphaFactorubSUN=_Lazy_glGlobalAlphaFactorubSUN;
PFNGLGLOBALALPHAFACTORUSSUNPROC pglGlobalAlphaFactorusSUN=_Lazy_glGlobalAlphaFactorusSUN;
PFNGLGLOBALALPHAFACTORUISUNPROC pglGlobalAlphaFactoruiSUN=_Lazy_glGlobalAlphaFactoruiSUN;
#endif 

/* GL_SUN_triangle_list */

#ifdef __GLEE_GL_SUN_triangle_list
void __stdcall _Lazy_glReplacementCodeuiSUN(GLuint code)                                  {if (GLeeInit()) glReplacementCodeuiSUN(code);}
void __stdcall _Lazy_glReplacementCodeusSUN(GLushort code)                                {if (GLeeInit()) glReplacementCodeusSUN(code);}
void __stdcall _Lazy_glReplacementCodeubSUN(GLubyte code)                                 {if (GLeeInit()) glReplacementCodeubSUN(code);}
void __stdcall _Lazy_glReplacementCodeuivSUN(const GLuint * code)                         {if (GLeeInit()) glReplacementCodeuivSUN(code);}
void __stdcall _Lazy_glReplacementCodeusvSUN(const GLushort * code)                       {if (GLeeInit()) glReplacementCodeusvSUN(code);}
void __stdcall _Lazy_glReplacementCodeubvSUN(const GLubyte * code)                        {if (GLeeInit()) glReplacementCodeubvSUN(code);}
void __stdcall _Lazy_glReplacementCodePointerSUN(GLenum type, GLsizei stride, const GLvoid* * pointer)  {if (GLeeInit()) glReplacementCodePointerSUN(type, stride, pointer);}
PFNGLREPLACEMENTCODEUISUNPROC pglReplacementCodeuiSUN=_Lazy_glReplacementCodeuiSUN;
PFNGLREPLACEMENTCODEUSSUNPROC pglReplacementCodeusSUN=_Lazy_glReplacementCodeusSUN;
PFNGLREPLACEMENTCODEUBSUNPROC pglReplacementCodeubSUN=_Lazy_glReplacementCodeubSUN;
PFNGLREPLACEMENTCODEUIVSUNPROC pglReplacementCodeuivSUN=_Lazy_glReplacementCodeuivSUN;
PFNGLREPLACEMENTCODEUSVSUNPROC pglReplacementCodeusvSUN=_Lazy_glReplacementCodeusvSUN;
PFNGLREPLACEMENTCODEUBVSUNPROC pglReplacementCodeubvSUN=_Lazy_glReplacementCodeubvSUN;
PFNGLREPLACEMENTCODEPOINTERSUNPROC pglReplacementCodePointerSUN=_Lazy_glReplacementCodePointerSUN;
#endif 

/* GL_SUN_vertex */

#ifdef __GLEE_GL_SUN_vertex
void __stdcall _Lazy_glColor4ubVertex2fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y)  {if (GLeeInit()) glColor4ubVertex2fSUN(r, g, b, a, x, y);}
void __stdcall _Lazy_glColor4ubVertex2fvSUN(const GLubyte * c, const GLfloat * v)         {if (GLeeInit()) glColor4ubVertex2fvSUN(c, v);}
void __stdcall _Lazy_glColor4ubVertex3fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glColor4ubVertex3fSUN(r, g, b, a, x, y, z);}
void __stdcall _Lazy_glColor4ubVertex3fvSUN(const GLubyte * c, const GLfloat * v)         {if (GLeeInit()) glColor4ubVertex3fvSUN(c, v);}
void __stdcall _Lazy_glColor3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glColor3fVertex3fSUN(r, g, b, x, y, z);}
void __stdcall _Lazy_glColor3fVertex3fvSUN(const GLfloat * c, const GLfloat * v)          {if (GLeeInit()) glColor3fVertex3fvSUN(c, v);}
void __stdcall _Lazy_glNormal3fVertex3fSUN(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glNormal3fVertex3fSUN(nx, ny, nz, x, y, z);}
void __stdcall _Lazy_glNormal3fVertex3fvSUN(const GLfloat * n, const GLfloat * v)         {if (GLeeInit()) glNormal3fVertex3fvSUN(n, v);}
void __stdcall _Lazy_glColor4fNormal3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glColor4fNormal3fVertex3fSUN(r, g, b, a, nx, ny, nz, x, y, z);}
void __stdcall _Lazy_glColor4fNormal3fVertex3fvSUN(const GLfloat * c, const GLfloat * n, const GLfloat * v)  {if (GLeeInit()) glColor4fNormal3fVertex3fvSUN(c, n, v);}
void __stdcall _Lazy_glTexCoord2fVertex3fSUN(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glTexCoord2fVertex3fSUN(s, t, x, y, z);}
void __stdcall _Lazy_glTexCoord2fVertex3fvSUN(const GLfloat * tc, const GLfloat * v)      {if (GLeeInit()) glTexCoord2fVertex3fvSUN(tc, v);}
void __stdcall _Lazy_glTexCoord4fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w)  {if (GLeeInit()) glTexCoord4fVertex4fSUN(s, t, p, q, x, y, z, w);}
void __stdcall _Lazy_glTexCoord4fVertex4fvSUN(const GLfloat * tc, const GLfloat * v)      {if (GLeeInit()) glTexCoord4fVertex4fvSUN(tc, v);}
void __stdcall _Lazy_glTexCoord2fColor4ubVertex3fSUN(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glTexCoord2fColor4ubVertex3fSUN(s, t, r, g, b, a, x, y, z);}
void __stdcall _Lazy_glTexCoord2fColor4ubVertex3fvSUN(const GLfloat * tc, const GLubyte * c, const GLfloat * v)  {if (GLeeInit()) glTexCoord2fColor4ubVertex3fvSUN(tc, c, v);}
void __stdcall _Lazy_glTexCoord2fColor3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glTexCoord2fColor3fVertex3fSUN(s, t, r, g, b, x, y, z);}
void __stdcall _Lazy_glTexCoord2fColor3fVertex3fvSUN(const GLfloat * tc, const GLfloat * c, const GLfloat * v)  {if (GLeeInit()) glTexCoord2fColor3fVertex3fvSUN(tc, c, v);}
void __stdcall _Lazy_glTexCoord2fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glTexCoord2fNormal3fVertex3fSUN(s, t, nx, ny, nz, x, y, z);}
void __stdcall _Lazy_glTexCoord2fNormal3fVertex3fvSUN(const GLfloat * tc, const GLfloat * n, const GLfloat * v)  {if (GLeeInit()) glTexCoord2fNormal3fVertex3fvSUN(tc, n, v);}
void __stdcall _Lazy_glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glTexCoord2fColor4fNormal3fVertex3fSUN(s, t, r, g, b, a, nx, ny, nz, x, y, z);}
void __stdcall _Lazy_glTexCoord2fColor4fNormal3fVertex3fvSUN(const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v)  {if (GLeeInit()) glTexCoord2fColor4fNormal3fVertex3fvSUN(tc, c, n, v);}
void __stdcall _Lazy_glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w)  {if (GLeeInit()) glTexCoord4fColor4fNormal3fVertex4fSUN(s, t, p, q, r, g, b, a, nx, ny, nz, x, y, z, w);}
void __stdcall _Lazy_glTexCoord4fColor4fNormal3fVertex4fvSUN(const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v)  {if (GLeeInit()) glTexCoord4fColor4fNormal3fVertex4fvSUN(tc, c, n, v);}
void __stdcall _Lazy_glReplacementCodeuiVertex3fSUN(GLuint rc, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glReplacementCodeuiVertex3fSUN(rc, x, y, z);}
void __stdcall _Lazy_glReplacementCodeuiVertex3fvSUN(const GLuint * rc, const GLfloat * v)  {if (GLeeInit()) glReplacementCodeuiVertex3fvSUN(rc, v);}
void __stdcall _Lazy_glReplacementCodeuiColor4ubVertex3fSUN(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glReplacementCodeuiColor4ubVertex3fSUN(rc, r, g, b, a, x, y, z);}
void __stdcall _Lazy_glReplacementCodeuiColor4ubVertex3fvSUN(const GLuint * rc, const GLubyte * c, const GLfloat * v)  {if (GLeeInit()) glReplacementCodeuiColor4ubVertex3fvSUN(rc, c, v);}
void __stdcall _Lazy_glReplacementCodeuiColor3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glReplacementCodeuiColor3fVertex3fSUN(rc, r, g, b, x, y, z);}
void __stdcall _Lazy_glReplacementCodeuiColor3fVertex3fvSUN(const GLuint * rc, const GLfloat * c, const GLfloat * v)  {if (GLeeInit()) glReplacementCodeuiColor3fVertex3fvSUN(rc, c, v);}
void __stdcall _Lazy_glReplacementCodeuiNormal3fVertex3fSUN(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glReplacementCodeuiNormal3fVertex3fSUN(rc, nx, ny, nz, x, y, z);}
void __stdcall _Lazy_glReplacementCodeuiNormal3fVertex3fvSUN(const GLuint * rc, const GLfloat * n, const GLfloat * v)  {if (GLeeInit()) glReplacementCodeuiNormal3fVertex3fvSUN(rc, n, v);}
void __stdcall _Lazy_glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glReplacementCodeuiColor4fNormal3fVertex3fSUN(rc, r, g, b, a, nx, ny, nz, x, y, z);}
void __stdcall _Lazy_glReplacementCodeuiColor4fNormal3fVertex3fvSUN(const GLuint * rc, const GLfloat * c, const GLfloat * n, const GLfloat * v)  {if (GLeeInit()) glReplacementCodeuiColor4fNormal3fVertex3fvSUN(rc, c, n, v);}
void __stdcall _Lazy_glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glReplacementCodeuiTexCoord2fVertex3fSUN(rc, s, t, x, y, z);}
void __stdcall _Lazy_glReplacementCodeuiTexCoord2fVertex3fvSUN(const GLuint * rc, const GLfloat * tc, const GLfloat * v)  {if (GLeeInit()) glReplacementCodeuiTexCoord2fVertex3fvSUN(rc, tc, v);}
void __stdcall _Lazy_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(rc, s, t, nx, ny, nz, x, y, z);}
void __stdcall _Lazy_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(const GLuint * rc, const GLfloat * tc, const GLfloat * n, const GLfloat * v)  {if (GLeeInit()) glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(rc, tc, n, v);}
void __stdcall _Lazy_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(rc, s, t, r, g, b, a, nx, ny, nz, x, y, z);}
void __stdcall _Lazy_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(const GLuint * rc, const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v)  {if (GLeeInit()) glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(rc, tc, c, n, v);}
PFNGLCOLOR4UBVERTEX2FSUNPROC pglColor4ubVertex2fSUN=_Lazy_glColor4ubVertex2fSUN;
PFNGLCOLOR4UBVERTEX2FVSUNPROC pglColor4ubVertex2fvSUN=_Lazy_glColor4ubVertex2fvSUN;
PFNGLCOLOR4UBVERTEX3FSUNPROC pglColor4ubVertex3fSUN=_Lazy_glColor4ubVertex3fSUN;
PFNGLCOLOR4UBVERTEX3FVSUNPROC pglColor4ubVertex3fvSUN=_Lazy_glColor4ubVertex3fvSUN;
PFNGLCOLOR3FVERTEX3FSUNPROC pglColor3fVertex3fSUN=_Lazy_glColor3fVertex3fSUN;
PFNGLCOLOR3FVERTEX3FVSUNPROC pglColor3fVertex3fvSUN=_Lazy_glColor3fVertex3fvSUN;
PFNGLNORMAL3FVERTEX3FSUNPROC pglNormal3fVertex3fSUN=_Lazy_glNormal3fVertex3fSUN;
PFNGLNORMAL3FVERTEX3FVSUNPROC pglNormal3fVertex3fvSUN=_Lazy_glNormal3fVertex3fvSUN;
PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC pglColor4fNormal3fVertex3fSUN=_Lazy_glColor4fNormal3fVertex3fSUN;
PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC pglColor4fNormal3fVertex3fvSUN=_Lazy_glColor4fNormal3fVertex3fvSUN;
PFNGLTEXCOORD2FVERTEX3FSUNPROC pglTexCoord2fVertex3fSUN=_Lazy_glTexCoord2fVertex3fSUN;
PFNGLTEXCOORD2FVERTEX3FVSUNPROC pglTexCoord2fVertex3fvSUN=_Lazy_glTexCoord2fVertex3fvSUN;
PFNGLTEXCOORD4FVERTEX4FSUNPROC pglTexCoord4fVertex4fSUN=_Lazy_glTexCoord4fVertex4fSUN;
PFNGLTEXCOORD4FVERTEX4FVSUNPROC pglTexCoord4fVertex4fvSUN=_Lazy_glTexCoord4fVertex4fvSUN;
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC pglTexCoord2fColor4ubVertex3fSUN=_Lazy_glTexCoord2fColor4ubVertex3fSUN;
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC pglTexCoord2fColor4ubVertex3fvSUN=_Lazy_glTexCoord2fColor4ubVertex3fvSUN;
PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC pglTexCoord2fColor3fVertex3fSUN=_Lazy_glTexCoord2fColor3fVertex3fSUN;
PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC pglTexCoord2fColor3fVertex3fvSUN=_Lazy_glTexCoord2fColor3fVertex3fvSUN;
PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC pglTexCoord2fNormal3fVertex3fSUN=_Lazy_glTexCoord2fNormal3fVertex3fSUN;
PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC pglTexCoord2fNormal3fVertex3fvSUN=_Lazy_glTexCoord2fNormal3fVertex3fvSUN;
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC pglTexCoord2fColor4fNormal3fVertex3fSUN=_Lazy_glTexCoord2fColor4fNormal3fVertex3fSUN;
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC pglTexCoord2fColor4fNormal3fVertex3fvSUN=_Lazy_glTexCoord2fColor4fNormal3fVertex3fvSUN;
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC pglTexCoord4fColor4fNormal3fVertex4fSUN=_Lazy_glTexCoord4fColor4fNormal3fVertex4fSUN;
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC pglTexCoord4fColor4fNormal3fVertex4fvSUN=_Lazy_glTexCoord4fColor4fNormal3fVertex4fvSUN;
PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC pglReplacementCodeuiVertex3fSUN=_Lazy_glReplacementCodeuiVertex3fSUN;
PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC pglReplacementCodeuiVertex3fvSUN=_Lazy_glReplacementCodeuiVertex3fvSUN;
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC pglReplacementCodeuiColor4ubVertex3fSUN=_Lazy_glReplacementCodeuiColor4ubVertex3fSUN;
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC pglReplacementCodeuiColor4ubVertex3fvSUN=_Lazy_glReplacementCodeuiColor4ubVertex3fvSUN;
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC pglReplacementCodeuiColor3fVertex3fSUN=_Lazy_glReplacementCodeuiColor3fVertex3fSUN;
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC pglReplacementCodeuiColor3fVertex3fvSUN=_Lazy_glReplacementCodeuiColor3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC pglReplacementCodeuiNormal3fVertex3fSUN=_Lazy_glReplacementCodeuiNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC pglReplacementCodeuiNormal3fVertex3fvSUN=_Lazy_glReplacementCodeuiNormal3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC pglReplacementCodeuiColor4fNormal3fVertex3fSUN=_Lazy_glReplacementCodeuiColor4fNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC pglReplacementCodeuiColor4fNormal3fVertex3fvSUN=_Lazy_glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC pglReplacementCodeuiTexCoord2fVertex3fSUN=_Lazy_glReplacementCodeuiTexCoord2fVertex3fSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC pglReplacementCodeuiTexCoord2fVertex3fvSUN=_Lazy_glReplacementCodeuiTexCoord2fVertex3fvSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC pglReplacementCodeuiTexCoord2fNormal3fVertex3fSUN=_Lazy_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC pglReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN=_Lazy_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC pglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN=_Lazy_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC pglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN=_Lazy_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
#endif 

/* GL_EXT_blend_func_separate */

#ifdef __GLEE_GL_EXT_blend_func_separate
void __stdcall _Lazy_glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)  {if (GLeeInit()) glBlendFuncSeparateEXT(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);}
PFNGLBLENDFUNCSEPARATEEXTPROC pglBlendFuncSeparateEXT=_Lazy_glBlendFuncSeparateEXT;
#endif 

/* GL_INGR_color_clamp */

#ifdef __GLEE_GL_INGR_color_clamp
#endif 

/* GL_INGR_interlace_read */

#ifdef __GLEE_GL_INGR_interlace_read
#endif 

/* GL_EXT_stencil_wrap */

#ifdef __GLEE_GL_EXT_stencil_wrap
#endif 

/* GL_EXT_422_pixels */

#ifdef __GLEE_GL_EXT_422_pixels
#endif 

/* GL_NV_texgen_reflection */

#ifdef __GLEE_GL_NV_texgen_reflection
#endif 

/* GL_EXT_texture_cube_map */

#ifdef __GLEE_GL_EXT_texture_cube_map
#endif 

/* GL_SUN_convolution_border_modes */

#ifdef __GLEE_GL_SUN_convolution_border_modes
#endif 

/* GL_EXT_texture_env_add */

#ifdef __GLEE_GL_EXT_texture_env_add
#endif 

/* GL_EXT_texture_lod_bias */

#ifdef __GLEE_GL_EXT_texture_lod_bias
#endif 

/* GL_EXT_texture_filter_anisotropic */

#ifdef __GLEE_GL_EXT_texture_filter_anisotropic
#endif 

/* GL_EXT_vertex_weighting */

#ifdef __GLEE_GL_EXT_vertex_weighting
void __stdcall _Lazy_glVertexWeightfEXT(GLfloat weight)                                   {if (GLeeInit()) glVertexWeightfEXT(weight);}
void __stdcall _Lazy_glVertexWeightfvEXT(const GLfloat * weight)                          {if (GLeeInit()) glVertexWeightfvEXT(weight);}
void __stdcall _Lazy_glVertexWeightPointerEXT(GLsizei size, GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glVertexWeightPointerEXT(size, type, stride, pointer);}
PFNGLVERTEXWEIGHTFEXTPROC pglVertexWeightfEXT=_Lazy_glVertexWeightfEXT;
PFNGLVERTEXWEIGHTFVEXTPROC pglVertexWeightfvEXT=_Lazy_glVertexWeightfvEXT;
PFNGLVERTEXWEIGHTPOINTEREXTPROC pglVertexWeightPointerEXT=_Lazy_glVertexWeightPointerEXT;
#endif 

/* GL_NV_light_max_exponent */

#ifdef __GLEE_GL_NV_light_max_exponent
#endif 

/* GL_NV_vertex_array_range */

#ifdef __GLEE_GL_NV_vertex_array_range
void __stdcall _Lazy_glFlushVertexArrayRangeNV(void)                                      {if (GLeeInit()) glFlushVertexArrayRangeNV();}
void __stdcall _Lazy_glVertexArrayRangeNV(GLsizei length, const GLvoid * pointer)         {if (GLeeInit()) glVertexArrayRangeNV(length, pointer);}
PFNGLFLUSHVERTEXARRAYRANGENVPROC pglFlushVertexArrayRangeNV=_Lazy_glFlushVertexArrayRangeNV;
PFNGLVERTEXARRAYRANGENVPROC pglVertexArrayRangeNV=_Lazy_glVertexArrayRangeNV;
#endif 

/* GL_NV_register_combiners */

#ifdef __GLEE_GL_NV_register_combiners
void __stdcall _Lazy_glCombinerParameterfvNV(GLenum pname, const GLfloat * params)        {if (GLeeInit()) glCombinerParameterfvNV(pname, params);}
void __stdcall _Lazy_glCombinerParameterfNV(GLenum pname, GLfloat param)                  {if (GLeeInit()) glCombinerParameterfNV(pname, param);}
void __stdcall _Lazy_glCombinerParameterivNV(GLenum pname, const GLint * params)          {if (GLeeInit()) glCombinerParameterivNV(pname, params);}
void __stdcall _Lazy_glCombinerParameteriNV(GLenum pname, GLint param)                    {if (GLeeInit()) glCombinerParameteriNV(pname, param);}
void __stdcall _Lazy_glCombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage)  {if (GLeeInit()) glCombinerInputNV(stage, portion, variable, input, mapping, componentUsage);}
void __stdcall _Lazy_glCombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum)  {if (GLeeInit()) glCombinerOutputNV(stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum);}
void __stdcall _Lazy_glFinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage)  {if (GLeeInit()) glFinalCombinerInputNV(variable, input, mapping, componentUsage);}
void __stdcall _Lazy_glGetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetCombinerInputParameterfvNV(stage, portion, variable, pname, params);}
void __stdcall _Lazy_glGetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint * params)  {if (GLeeInit()) glGetCombinerInputParameterivNV(stage, portion, variable, pname, params);}
void __stdcall _Lazy_glGetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetCombinerOutputParameterfvNV(stage, portion, pname, params);}
void __stdcall _Lazy_glGetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint * params)  {if (GLeeInit()) glGetCombinerOutputParameterivNV(stage, portion, pname, params);}
void __stdcall _Lazy_glGetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetFinalCombinerInputParameterfvNV(variable, pname, params);}
void __stdcall _Lazy_glGetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint * params)  {if (GLeeInit()) glGetFinalCombinerInputParameterivNV(variable, pname, params);}
PFNGLCOMBINERPARAMETERFVNVPROC pglCombinerParameterfvNV=_Lazy_glCombinerParameterfvNV;
PFNGLCOMBINERPARAMETERFNVPROC pglCombinerParameterfNV=_Lazy_glCombinerParameterfNV;
PFNGLCOMBINERPARAMETERIVNVPROC pglCombinerParameterivNV=_Lazy_glCombinerParameterivNV;
PFNGLCOMBINERPARAMETERINVPROC pglCombinerParameteriNV=_Lazy_glCombinerParameteriNV;
PFNGLCOMBINERINPUTNVPROC pglCombinerInputNV=_Lazy_glCombinerInputNV;
PFNGLCOMBINEROUTPUTNVPROC pglCombinerOutputNV=_Lazy_glCombinerOutputNV;
PFNGLFINALCOMBINERINPUTNVPROC pglFinalCombinerInputNV=_Lazy_glFinalCombinerInputNV;
PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC pglGetCombinerInputParameterfvNV=_Lazy_glGetCombinerInputParameterfvNV;
PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC pglGetCombinerInputParameterivNV=_Lazy_glGetCombinerInputParameterivNV;
PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC pglGetCombinerOutputParameterfvNV=_Lazy_glGetCombinerOutputParameterfvNV;
PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC pglGetCombinerOutputParameterivNV=_Lazy_glGetCombinerOutputParameterivNV;
PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC pglGetFinalCombinerInputParameterfvNV=_Lazy_glGetFinalCombinerInputParameterfvNV;
PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC pglGetFinalCombinerInputParameterivNV=_Lazy_glGetFinalCombinerInputParameterivNV;
#endif 

/* GL_NV_fog_distance */

#ifdef __GLEE_GL_NV_fog_distance
#endif 

/* GL_NV_texgen_emboss */

#ifdef __GLEE_GL_NV_texgen_emboss
#endif 

/* GL_NV_blend_square */

#ifdef __GLEE_GL_NV_blend_square
#endif 

/* GL_NV_texture_env_combine4 */

#ifdef __GLEE_GL_NV_texture_env_combine4
#endif 

/* GL_MESA_resize_buffers */

#ifdef __GLEE_GL_MESA_resize_buffers
void __stdcall _Lazy_glResizeBuffersMESA(void)                                            {if (GLeeInit()) glResizeBuffersMESA();}
PFNGLRESIZEBUFFERSMESAPROC pglResizeBuffersMESA=_Lazy_glResizeBuffersMESA;
#endif 

/* GL_MESA_window_pos */

#ifdef __GLEE_GL_MESA_window_pos
void __stdcall _Lazy_glWindowPos2dMESA(GLdouble x, GLdouble y)                            {if (GLeeInit()) glWindowPos2dMESA(x, y);}
void __stdcall _Lazy_glWindowPos2dvMESA(const GLdouble * v)                               {if (GLeeInit()) glWindowPos2dvMESA(v);}
void __stdcall _Lazy_glWindowPos2fMESA(GLfloat x, GLfloat y)                              {if (GLeeInit()) glWindowPos2fMESA(x, y);}
void __stdcall _Lazy_glWindowPos2fvMESA(const GLfloat * v)                                {if (GLeeInit()) glWindowPos2fvMESA(v);}
void __stdcall _Lazy_glWindowPos2iMESA(GLint x, GLint y)                                  {if (GLeeInit()) glWindowPos2iMESA(x, y);}
void __stdcall _Lazy_glWindowPos2ivMESA(const GLint * v)                                  {if (GLeeInit()) glWindowPos2ivMESA(v);}
void __stdcall _Lazy_glWindowPos2sMESA(GLshort x, GLshort y)                              {if (GLeeInit()) glWindowPos2sMESA(x, y);}
void __stdcall _Lazy_glWindowPos2svMESA(const GLshort * v)                                {if (GLeeInit()) glWindowPos2svMESA(v);}
void __stdcall _Lazy_glWindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z)                {if (GLeeInit()) glWindowPos3dMESA(x, y, z);}
void __stdcall _Lazy_glWindowPos3dvMESA(const GLdouble * v)                               {if (GLeeInit()) glWindowPos3dvMESA(v);}
void __stdcall _Lazy_glWindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z)                   {if (GLeeInit()) glWindowPos3fMESA(x, y, z);}
void __stdcall _Lazy_glWindowPos3fvMESA(const GLfloat * v)                                {if (GLeeInit()) glWindowPos3fvMESA(v);}
void __stdcall _Lazy_glWindowPos3iMESA(GLint x, GLint y, GLint z)                         {if (GLeeInit()) glWindowPos3iMESA(x, y, z);}
void __stdcall _Lazy_glWindowPos3ivMESA(const GLint * v)                                  {if (GLeeInit()) glWindowPos3ivMESA(v);}
void __stdcall _Lazy_glWindowPos3sMESA(GLshort x, GLshort y, GLshort z)                   {if (GLeeInit()) glWindowPos3sMESA(x, y, z);}
void __stdcall _Lazy_glWindowPos3svMESA(const GLshort * v)                                {if (GLeeInit()) glWindowPos3svMESA(v);}
void __stdcall _Lazy_glWindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w)    {if (GLeeInit()) glWindowPos4dMESA(x, y, z, w);}
void __stdcall _Lazy_glWindowPos4dvMESA(const GLdouble * v)                               {if (GLeeInit()) glWindowPos4dvMESA(v);}
void __stdcall _Lazy_glWindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w)        {if (GLeeInit()) glWindowPos4fMESA(x, y, z, w);}
void __stdcall _Lazy_glWindowPos4fvMESA(const GLfloat * v)                                {if (GLeeInit()) glWindowPos4fvMESA(v);}
void __stdcall _Lazy_glWindowPos4iMESA(GLint x, GLint y, GLint z, GLint w)                {if (GLeeInit()) glWindowPos4iMESA(x, y, z, w);}
void __stdcall _Lazy_glWindowPos4ivMESA(const GLint * v)                                  {if (GLeeInit()) glWindowPos4ivMESA(v);}
void __stdcall _Lazy_glWindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w)        {if (GLeeInit()) glWindowPos4sMESA(x, y, z, w);}
void __stdcall _Lazy_glWindowPos4svMESA(const GLshort * v)                                {if (GLeeInit()) glWindowPos4svMESA(v);}
PFNGLWINDOWPOS2DMESAPROC pglWindowPos2dMESA=_Lazy_glWindowPos2dMESA;
PFNGLWINDOWPOS2DVMESAPROC pglWindowPos2dvMESA=_Lazy_glWindowPos2dvMESA;
PFNGLWINDOWPOS2FMESAPROC pglWindowPos2fMESA=_Lazy_glWindowPos2fMESA;
PFNGLWINDOWPOS2FVMESAPROC pglWindowPos2fvMESA=_Lazy_glWindowPos2fvMESA;
PFNGLWINDOWPOS2IMESAPROC pglWindowPos2iMESA=_Lazy_glWindowPos2iMESA;
PFNGLWINDOWPOS2IVMESAPROC pglWindowPos2ivMESA=_Lazy_glWindowPos2ivMESA;
PFNGLWINDOWPOS2SMESAPROC pglWindowPos2sMESA=_Lazy_glWindowPos2sMESA;
PFNGLWINDOWPOS2SVMESAPROC pglWindowPos2svMESA=_Lazy_glWindowPos2svMESA;
PFNGLWINDOWPOS3DMESAPROC pglWindowPos3dMESA=_Lazy_glWindowPos3dMESA;
PFNGLWINDOWPOS3DVMESAPROC pglWindowPos3dvMESA=_Lazy_glWindowPos3dvMESA;
PFNGLWINDOWPOS3FMESAPROC pglWindowPos3fMESA=_Lazy_glWindowPos3fMESA;
PFNGLWINDOWPOS3FVMESAPROC pglWindowPos3fvMESA=_Lazy_glWindowPos3fvMESA;
PFNGLWINDOWPOS3IMESAPROC pglWindowPos3iMESA=_Lazy_glWindowPos3iMESA;
PFNGLWINDOWPOS3IVMESAPROC pglWindowPos3ivMESA=_Lazy_glWindowPos3ivMESA;
PFNGLWINDOWPOS3SMESAPROC pglWindowPos3sMESA=_Lazy_glWindowPos3sMESA;
PFNGLWINDOWPOS3SVMESAPROC pglWindowPos3svMESA=_Lazy_glWindowPos3svMESA;
PFNGLWINDOWPOS4DMESAPROC pglWindowPos4dMESA=_Lazy_glWindowPos4dMESA;
PFNGLWINDOWPOS4DVMESAPROC pglWindowPos4dvMESA=_Lazy_glWindowPos4dvMESA;
PFNGLWINDOWPOS4FMESAPROC pglWindowPos4fMESA=_Lazy_glWindowPos4fMESA;
PFNGLWINDOWPOS4FVMESAPROC pglWindowPos4fvMESA=_Lazy_glWindowPos4fvMESA;
PFNGLWINDOWPOS4IMESAPROC pglWindowPos4iMESA=_Lazy_glWindowPos4iMESA;
PFNGLWINDOWPOS4IVMESAPROC pglWindowPos4ivMESA=_Lazy_glWindowPos4ivMESA;
PFNGLWINDOWPOS4SMESAPROC pglWindowPos4sMESA=_Lazy_glWindowPos4sMESA;
PFNGLWINDOWPOS4SVMESAPROC pglWindowPos4svMESA=_Lazy_glWindowPos4svMESA;
#endif 

/* GL_EXT_texture_compression_s3tc */

#ifdef __GLEE_GL_EXT_texture_compression_s3tc
#endif 

/* GL_IBM_cull_vertex */

#ifdef __GLEE_GL_IBM_cull_vertex
#endif 

/* GL_IBM_multimode_draw_arrays */

#ifdef __GLEE_GL_IBM_multimode_draw_arrays
void __stdcall _Lazy_glMultiModeDrawArraysIBM(const GLenum * mode, const GLint * first, const GLsizei * count, GLsizei primcount, GLint modestride)  {if (GLeeInit()) glMultiModeDrawArraysIBM(mode, first, count, primcount, modestride);}
void __stdcall _Lazy_glMultiModeDrawElementsIBM(const GLenum * mode, const GLsizei * count, GLenum type, const GLvoid* const * indices, GLsizei primcount, GLint modestride)  {if (GLeeInit()) glMultiModeDrawElementsIBM(mode, count, type, indices, primcount, modestride);}
PFNGLMULTIMODEDRAWARRAYSIBMPROC pglMultiModeDrawArraysIBM=_Lazy_glMultiModeDrawArraysIBM;
PFNGLMULTIMODEDRAWELEMENTSIBMPROC pglMultiModeDrawElementsIBM=_Lazy_glMultiModeDrawElementsIBM;
#endif 

/* GL_IBM_vertex_array_lists */

#ifdef __GLEE_GL_IBM_vertex_array_lists
void __stdcall _Lazy_glColorPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride)  {if (GLeeInit()) glColorPointerListIBM(size, type, stride, pointer, ptrstride);}
void __stdcall _Lazy_glSecondaryColorPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride)  {if (GLeeInit()) glSecondaryColorPointerListIBM(size, type, stride, pointer, ptrstride);}
void __stdcall _Lazy_glEdgeFlagPointerListIBM(GLint stride, const GLboolean* * pointer, GLint ptrstride)  {if (GLeeInit()) glEdgeFlagPointerListIBM(stride, pointer, ptrstride);}
void __stdcall _Lazy_glFogCoordPointerListIBM(GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride)  {if (GLeeInit()) glFogCoordPointerListIBM(type, stride, pointer, ptrstride);}
void __stdcall _Lazy_glIndexPointerListIBM(GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride)  {if (GLeeInit()) glIndexPointerListIBM(type, stride, pointer, ptrstride);}
void __stdcall _Lazy_glNormalPointerListIBM(GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride)  {if (GLeeInit()) glNormalPointerListIBM(type, stride, pointer, ptrstride);}
void __stdcall _Lazy_glTexCoordPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride)  {if (GLeeInit()) glTexCoordPointerListIBM(size, type, stride, pointer, ptrstride);}
void __stdcall _Lazy_glVertexPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride)  {if (GLeeInit()) glVertexPointerListIBM(size, type, stride, pointer, ptrstride);}
PFNGLCOLORPOINTERLISTIBMPROC pglColorPointerListIBM=_Lazy_glColorPointerListIBM;
PFNGLSECONDARYCOLORPOINTERLISTIBMPROC pglSecondaryColorPointerListIBM=_Lazy_glSecondaryColorPointerListIBM;
PFNGLEDGEFLAGPOINTERLISTIBMPROC pglEdgeFlagPointerListIBM=_Lazy_glEdgeFlagPointerListIBM;
PFNGLFOGCOORDPOINTERLISTIBMPROC pglFogCoordPointerListIBM=_Lazy_glFogCoordPointerListIBM;
PFNGLINDEXPOINTERLISTIBMPROC pglIndexPointerListIBM=_Lazy_glIndexPointerListIBM;
PFNGLNORMALPOINTERLISTIBMPROC pglNormalPointerListIBM=_Lazy_glNormalPointerListIBM;
PFNGLTEXCOORDPOINTERLISTIBMPROC pglTexCoordPointerListIBM=_Lazy_glTexCoordPointerListIBM;
PFNGLVERTEXPOINTERLISTIBMPROC pglVertexPointerListIBM=_Lazy_glVertexPointerListIBM;
#endif 

/* GL_SGIX_subsample */

#ifdef __GLEE_GL_SGIX_subsample
#endif 

/* GL_SGIX_ycrcb_subsample */

#ifdef __GLEE_GL_SGIX_ycrcb_subsample
#endif 

/* GL_SGIX_ycrcba */

#ifdef __GLEE_GL_SGIX_ycrcba
#endif 

/* GL_SGI_depth_pass_instrument */

#ifdef __GLEE_GL_SGI_depth_pass_instrument
#endif 

/* GL_3DFX_texture_compression_FXT1 */

#ifdef __GLEE_GL_3DFX_texture_compression_FXT1
#endif 

/* GL_3DFX_multisample */

#ifdef __GLEE_GL_3DFX_multisample
#endif 

/* GL_3DFX_tbuffer */

#ifdef __GLEE_GL_3DFX_tbuffer
void __stdcall _Lazy_glTbufferMask3DFX(GLuint mask)                                       {if (GLeeInit()) glTbufferMask3DFX(mask);}
PFNGLTBUFFERMASK3DFXPROC pglTbufferMask3DFX=_Lazy_glTbufferMask3DFX;
#endif 

/* GL_EXT_multisample */

#ifdef __GLEE_GL_EXT_multisample
void __stdcall _Lazy_glSampleMaskEXT(GLclampf value, GLboolean invert)                    {if (GLeeInit()) glSampleMaskEXT(value, invert);}
void __stdcall _Lazy_glSamplePatternEXT(GLenum pattern)                                   {if (GLeeInit()) glSamplePatternEXT(pattern);}
PFNGLSAMPLEMASKEXTPROC pglSampleMaskEXT=_Lazy_glSampleMaskEXT;
PFNGLSAMPLEPATTERNEXTPROC pglSamplePatternEXT=_Lazy_glSamplePatternEXT;
#endif 

/* GL_SGIX_vertex_preclip */

#ifdef __GLEE_GL_SGIX_vertex_preclip
#endif 

/* GL_SGIX_convolution_accuracy */

#ifdef __GLEE_GL_SGIX_convolution_accuracy
#endif 

/* GL_SGIX_resample */

#ifdef __GLEE_GL_SGIX_resample
#endif 

/* GL_SGIS_point_line_texgen */

#ifdef __GLEE_GL_SGIS_point_line_texgen
#endif 

/* GL_SGIS_texture_color_mask */

#ifdef __GLEE_GL_SGIS_texture_color_mask
void __stdcall _Lazy_glTextureColorMaskSGIS(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)  {if (GLeeInit()) glTextureColorMaskSGIS(red, green, blue, alpha);}
PFNGLTEXTURECOLORMASKSGISPROC pglTextureColorMaskSGIS=_Lazy_glTextureColorMaskSGIS;
#endif 

/* GL_EXT_texture_env_dot3 */

#ifdef __GLEE_GL_EXT_texture_env_dot3
#endif 

/* GL_ATI_texture_mirror_once */

#ifdef __GLEE_GL_ATI_texture_mirror_once
#endif 

/* GL_NV_fence */

#ifdef __GLEE_GL_NV_fence
void __stdcall _Lazy_glDeleteFencesNV(GLsizei n, const GLuint * fences)                   {if (GLeeInit()) glDeleteFencesNV(n, fences);}
void __stdcall _Lazy_glGenFencesNV(GLsizei n, GLuint * fences)                            {if (GLeeInit()) glGenFencesNV(n, fences);}
GLboolean __stdcall _Lazy_glIsFenceNV(GLuint fence)                                       {if (GLeeInit()) return glIsFenceNV(fence); return (GLboolean)0;}
GLboolean __stdcall _Lazy_glTestFenceNV(GLuint fence)                                     {if (GLeeInit()) return glTestFenceNV(fence); return (GLboolean)0;}
void __stdcall _Lazy_glGetFenceivNV(GLuint fence, GLenum pname, GLint * params)           {if (GLeeInit()) glGetFenceivNV(fence, pname, params);}
void __stdcall _Lazy_glFinishFenceNV(GLuint fence)                                        {if (GLeeInit()) glFinishFenceNV(fence);}
void __stdcall _Lazy_glSetFenceNV(GLuint fence, GLenum condition)                         {if (GLeeInit()) glSetFenceNV(fence, condition);}
PFNGLDELETEFENCESNVPROC pglDeleteFencesNV=_Lazy_glDeleteFencesNV;
PFNGLGENFENCESNVPROC pglGenFencesNV=_Lazy_glGenFencesNV;
PFNGLISFENCENVPROC pglIsFenceNV=_Lazy_glIsFenceNV;
PFNGLTESTFENCENVPROC pglTestFenceNV=_Lazy_glTestFenceNV;
PFNGLGETFENCEIVNVPROC pglGetFenceivNV=_Lazy_glGetFenceivNV;
PFNGLFINISHFENCENVPROC pglFinishFenceNV=_Lazy_glFinishFenceNV;
PFNGLSETFENCENVPROC pglSetFenceNV=_Lazy_glSetFenceNV;
#endif 

/* GL_IBM_texture_mirrored_repeat */

#ifdef __GLEE_GL_IBM_texture_mirrored_repeat
#endif 

/* GL_NV_evaluators */

#ifdef __GLEE_GL_NV_evaluators
void __stdcall _Lazy_glMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const GLvoid * points)  {if (GLeeInit()) glMapControlPointsNV(target, index, type, ustride, vstride, uorder, vorder, packed, points);}
void __stdcall _Lazy_glMapParameterivNV(GLenum target, GLenum pname, const GLint * params)  {if (GLeeInit()) glMapParameterivNV(target, pname, params);}
void __stdcall _Lazy_glMapParameterfvNV(GLenum target, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glMapParameterfvNV(target, pname, params);}
void __stdcall _Lazy_glGetMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid * points)  {if (GLeeInit()) glGetMapControlPointsNV(target, index, type, ustride, vstride, packed, points);}
void __stdcall _Lazy_glGetMapParameterivNV(GLenum target, GLenum pname, GLint * params)   {if (GLeeInit()) glGetMapParameterivNV(target, pname, params);}
void __stdcall _Lazy_glGetMapParameterfvNV(GLenum target, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetMapParameterfvNV(target, pname, params);}
void __stdcall _Lazy_glGetMapAttribParameterivNV(GLenum target, GLuint index, GLenum pname, GLint * params)  {if (GLeeInit()) glGetMapAttribParameterivNV(target, index, pname, params);}
void __stdcall _Lazy_glGetMapAttribParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetMapAttribParameterfvNV(target, index, pname, params);}
void __stdcall _Lazy_glEvalMapsNV(GLenum target, GLenum mode)                             {if (GLeeInit()) glEvalMapsNV(target, mode);}
PFNGLMAPCONTROLPOINTSNVPROC pglMapControlPointsNV=_Lazy_glMapControlPointsNV;
PFNGLMAPPARAMETERIVNVPROC pglMapParameterivNV=_Lazy_glMapParameterivNV;
PFNGLMAPPARAMETERFVNVPROC pglMapParameterfvNV=_Lazy_glMapParameterfvNV;
PFNGLGETMAPCONTROLPOINTSNVPROC pglGetMapControlPointsNV=_Lazy_glGetMapControlPointsNV;
PFNGLGETMAPPARAMETERIVNVPROC pglGetMapParameterivNV=_Lazy_glGetMapParameterivNV;
PFNGLGETMAPPARAMETERFVNVPROC pglGetMapParameterfvNV=_Lazy_glGetMapParameterfvNV;
PFNGLGETMAPATTRIBPARAMETERIVNVPROC pglGetMapAttribParameterivNV=_Lazy_glGetMapAttribParameterivNV;
PFNGLGETMAPATTRIBPARAMETERFVNVPROC pglGetMapAttribParameterfvNV=_Lazy_glGetMapAttribParameterfvNV;
PFNGLEVALMAPSNVPROC pglEvalMapsNV=_Lazy_glEvalMapsNV;
#endif 

/* GL_NV_packed_depth_stencil */

#ifdef __GLEE_GL_NV_packed_depth_stencil
#endif 

/* GL_NV_register_combiners2 */

#ifdef __GLEE_GL_NV_register_combiners2
void __stdcall _Lazy_glCombinerStageParameterfvNV(GLenum stage, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glCombinerStageParameterfvNV(stage, pname, params);}
void __stdcall _Lazy_glGetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetCombinerStageParameterfvNV(stage, pname, params);}
PFNGLCOMBINERSTAGEPARAMETERFVNVPROC pglCombinerStageParameterfvNV=_Lazy_glCombinerStageParameterfvNV;
PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC pglGetCombinerStageParameterfvNV=_Lazy_glGetCombinerStageParameterfvNV;
#endif 

/* GL_NV_texture_compression_vtc */

#ifdef __GLEE_GL_NV_texture_compression_vtc
#endif 

/* GL_NV_texture_rectangle */

#ifdef __GLEE_GL_NV_texture_rectangle
#endif 

/* GL_NV_texture_shader */

#ifdef __GLEE_GL_NV_texture_shader
#endif 

/* GL_NV_texture_shader2 */

#ifdef __GLEE_GL_NV_texture_shader2
#endif 

/* GL_NV_vertex_array_range2 */

#ifdef __GLEE_GL_NV_vertex_array_range2
#endif 

/* GL_NV_vertex_program */

#ifdef __GLEE_GL_NV_vertex_program
GLboolean __stdcall _Lazy_glAreProgramsResidentNV(GLsizei n, const GLuint * programs, GLboolean * residences)  {if (GLeeInit()) return glAreProgramsResidentNV(n, programs, residences); return (GLboolean)0;}
void __stdcall _Lazy_glBindProgramNV(GLenum target, GLuint id)                            {if (GLeeInit()) glBindProgramNV(target, id);}
void __stdcall _Lazy_glDeleteProgramsNV(GLsizei n, const GLuint * programs)               {if (GLeeInit()) glDeleteProgramsNV(n, programs);}
void __stdcall _Lazy_glExecuteProgramNV(GLenum target, GLuint id, const GLfloat * params)  {if (GLeeInit()) glExecuteProgramNV(target, id, params);}
void __stdcall _Lazy_glGenProgramsNV(GLsizei n, GLuint * programs)                        {if (GLeeInit()) glGenProgramsNV(n, programs);}
void __stdcall _Lazy_glGetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble * params)  {if (GLeeInit()) glGetProgramParameterdvNV(target, index, pname, params);}
void __stdcall _Lazy_glGetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetProgramParameterfvNV(target, index, pname, params);}
void __stdcall _Lazy_glGetProgramivNV(GLuint id, GLenum pname, GLint * params)            {if (GLeeInit()) glGetProgramivNV(id, pname, params);}
void __stdcall _Lazy_glGetProgramStringNV(GLuint id, GLenum pname, GLubyte * program)     {if (GLeeInit()) glGetProgramStringNV(id, pname, program);}
void __stdcall _Lazy_glGetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint * params)  {if (GLeeInit()) glGetTrackMatrixivNV(target, address, pname, params);}
void __stdcall _Lazy_glGetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble * params)  {if (GLeeInit()) glGetVertexAttribdvNV(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetVertexAttribfvNV(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribivNV(GLuint index, GLenum pname, GLint * params)    {if (GLeeInit()) glGetVertexAttribivNV(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribPointervNV(GLuint index, GLenum pname, GLvoid* * pointer)  {if (GLeeInit()) glGetVertexAttribPointervNV(index, pname, pointer);}
GLboolean __stdcall _Lazy_glIsProgramNV(GLuint id)                                        {if (GLeeInit()) return glIsProgramNV(id); return (GLboolean)0;}
void __stdcall _Lazy_glLoadProgramNV(GLenum target, GLuint id, GLsizei len, const GLubyte * program)  {if (GLeeInit()) glLoadProgramNV(target, id, len, program);}
void __stdcall _Lazy_glProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)  {if (GLeeInit()) glProgramParameter4dNV(target, index, x, y, z, w);}
void __stdcall _Lazy_glProgramParameter4dvNV(GLenum target, GLuint index, const GLdouble * v)  {if (GLeeInit()) glProgramParameter4dvNV(target, index, v);}
void __stdcall _Lazy_glProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)  {if (GLeeInit()) glProgramParameter4fNV(target, index, x, y, z, w);}
void __stdcall _Lazy_glProgramParameter4fvNV(GLenum target, GLuint index, const GLfloat * v)  {if (GLeeInit()) glProgramParameter4fvNV(target, index, v);}
void __stdcall _Lazy_glProgramParameters4dvNV(GLenum target, GLuint index, GLuint count, const GLdouble * v)  {if (GLeeInit()) glProgramParameters4dvNV(target, index, count, v);}
void __stdcall _Lazy_glProgramParameters4fvNV(GLenum target, GLuint index, GLuint count, const GLfloat * v)  {if (GLeeInit()) glProgramParameters4fvNV(target, index, count, v);}
void __stdcall _Lazy_glRequestResidentProgramsNV(GLsizei n, const GLuint * programs)      {if (GLeeInit()) glRequestResidentProgramsNV(n, programs);}
void __stdcall _Lazy_glTrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform)  {if (GLeeInit()) glTrackMatrixNV(target, address, matrix, transform);}
void __stdcall _Lazy_glVertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glVertexAttribPointerNV(index, fsize, type, stride, pointer);}
void __stdcall _Lazy_glVertexAttrib1dNV(GLuint index, GLdouble x)                         {if (GLeeInit()) glVertexAttrib1dNV(index, x);}
void __stdcall _Lazy_glVertexAttrib1dvNV(GLuint index, const GLdouble * v)                {if (GLeeInit()) glVertexAttrib1dvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib1fNV(GLuint index, GLfloat x)                          {if (GLeeInit()) glVertexAttrib1fNV(index, x);}
void __stdcall _Lazy_glVertexAttrib1fvNV(GLuint index, const GLfloat * v)                 {if (GLeeInit()) glVertexAttrib1fvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib1sNV(GLuint index, GLshort x)                          {if (GLeeInit()) glVertexAttrib1sNV(index, x);}
void __stdcall _Lazy_glVertexAttrib1svNV(GLuint index, const GLshort * v)                 {if (GLeeInit()) glVertexAttrib1svNV(index, v);}
void __stdcall _Lazy_glVertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y)             {if (GLeeInit()) glVertexAttrib2dNV(index, x, y);}
void __stdcall _Lazy_glVertexAttrib2dvNV(GLuint index, const GLdouble * v)                {if (GLeeInit()) glVertexAttrib2dvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y)               {if (GLeeInit()) glVertexAttrib2fNV(index, x, y);}
void __stdcall _Lazy_glVertexAttrib2fvNV(GLuint index, const GLfloat * v)                 {if (GLeeInit()) glVertexAttrib2fvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib2sNV(GLuint index, GLshort x, GLshort y)               {if (GLeeInit()) glVertexAttrib2sNV(index, x, y);}
void __stdcall _Lazy_glVertexAttrib2svNV(GLuint index, const GLshort * v)                 {if (GLeeInit()) glVertexAttrib2svNV(index, v);}
void __stdcall _Lazy_glVertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z)  {if (GLeeInit()) glVertexAttrib3dNV(index, x, y, z);}
void __stdcall _Lazy_glVertexAttrib3dvNV(GLuint index, const GLdouble * v)                {if (GLeeInit()) glVertexAttrib3dvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z)    {if (GLeeInit()) glVertexAttrib3fNV(index, x, y, z);}
void __stdcall _Lazy_glVertexAttrib3fvNV(GLuint index, const GLfloat * v)                 {if (GLeeInit()) glVertexAttrib3fvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z)    {if (GLeeInit()) glVertexAttrib3sNV(index, x, y, z);}
void __stdcall _Lazy_glVertexAttrib3svNV(GLuint index, const GLshort * v)                 {if (GLeeInit()) glVertexAttrib3svNV(index, v);}
void __stdcall _Lazy_glVertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)  {if (GLeeInit()) glVertexAttrib4dNV(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4dvNV(GLuint index, const GLdouble * v)                {if (GLeeInit()) glVertexAttrib4dvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)  {if (GLeeInit()) glVertexAttrib4fNV(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4fvNV(GLuint index, const GLfloat * v)                 {if (GLeeInit()) glVertexAttrib4fvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)  {if (GLeeInit()) glVertexAttrib4sNV(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4svNV(GLuint index, const GLshort * v)                 {if (GLeeInit()) glVertexAttrib4svNV(index, v);}
void __stdcall _Lazy_glVertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)  {if (GLeeInit()) glVertexAttrib4ubNV(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4ubvNV(GLuint index, const GLubyte * v)                {if (GLeeInit()) glVertexAttrib4ubvNV(index, v);}
void __stdcall _Lazy_glVertexAttribs1dvNV(GLuint index, GLsizei count, const GLdouble * v)  {if (GLeeInit()) glVertexAttribs1dvNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs1fvNV(GLuint index, GLsizei count, const GLfloat * v)  {if (GLeeInit()) glVertexAttribs1fvNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs1svNV(GLuint index, GLsizei count, const GLshort * v)  {if (GLeeInit()) glVertexAttribs1svNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs2dvNV(GLuint index, GLsizei count, const GLdouble * v)  {if (GLeeInit()) glVertexAttribs2dvNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs2fvNV(GLuint index, GLsizei count, const GLfloat * v)  {if (GLeeInit()) glVertexAttribs2fvNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs2svNV(GLuint index, GLsizei count, const GLshort * v)  {if (GLeeInit()) glVertexAttribs2svNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs3dvNV(GLuint index, GLsizei count, const GLdouble * v)  {if (GLeeInit()) glVertexAttribs3dvNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs3fvNV(GLuint index, GLsizei count, const GLfloat * v)  {if (GLeeInit()) glVertexAttribs3fvNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs3svNV(GLuint index, GLsizei count, const GLshort * v)  {if (GLeeInit()) glVertexAttribs3svNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs4dvNV(GLuint index, GLsizei count, const GLdouble * v)  {if (GLeeInit()) glVertexAttribs4dvNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs4fvNV(GLuint index, GLsizei count, const GLfloat * v)  {if (GLeeInit()) glVertexAttribs4fvNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs4svNV(GLuint index, GLsizei count, const GLshort * v)  {if (GLeeInit()) glVertexAttribs4svNV(index, count, v);}
void __stdcall _Lazy_glVertexAttribs4ubvNV(GLuint index, GLsizei count, const GLubyte * v)  {if (GLeeInit()) glVertexAttribs4ubvNV(index, count, v);}
PFNGLAREPROGRAMSRESIDENTNVPROC pglAreProgramsResidentNV=_Lazy_glAreProgramsResidentNV;
PFNGLBINDPROGRAMNVPROC pglBindProgramNV=_Lazy_glBindProgramNV;
PFNGLDELETEPROGRAMSNVPROC pglDeleteProgramsNV=_Lazy_glDeleteProgramsNV;
PFNGLEXECUTEPROGRAMNVPROC pglExecuteProgramNV=_Lazy_glExecuteProgramNV;
PFNGLGENPROGRAMSNVPROC pglGenProgramsNV=_Lazy_glGenProgramsNV;
PFNGLGETPROGRAMPARAMETERDVNVPROC pglGetProgramParameterdvNV=_Lazy_glGetProgramParameterdvNV;
PFNGLGETPROGRAMPARAMETERFVNVPROC pglGetProgramParameterfvNV=_Lazy_glGetProgramParameterfvNV;
PFNGLGETPROGRAMIVNVPROC pglGetProgramivNV=_Lazy_glGetProgramivNV;
PFNGLGETPROGRAMSTRINGNVPROC pglGetProgramStringNV=_Lazy_glGetProgramStringNV;
PFNGLGETTRACKMATRIXIVNVPROC pglGetTrackMatrixivNV=_Lazy_glGetTrackMatrixivNV;
PFNGLGETVERTEXATTRIBDVNVPROC pglGetVertexAttribdvNV=_Lazy_glGetVertexAttribdvNV;
PFNGLGETVERTEXATTRIBFVNVPROC pglGetVertexAttribfvNV=_Lazy_glGetVertexAttribfvNV;
PFNGLGETVERTEXATTRIBIVNVPROC pglGetVertexAttribivNV=_Lazy_glGetVertexAttribivNV;
PFNGLGETVERTEXATTRIBPOINTERVNVPROC pglGetVertexAttribPointervNV=_Lazy_glGetVertexAttribPointervNV;
PFNGLISPROGRAMNVPROC pglIsProgramNV=_Lazy_glIsProgramNV;
PFNGLLOADPROGRAMNVPROC pglLoadProgramNV=_Lazy_glLoadProgramNV;
PFNGLPROGRAMPARAMETER4DNVPROC pglProgramParameter4dNV=_Lazy_glProgramParameter4dNV;
PFNGLPROGRAMPARAMETER4DVNVPROC pglProgramParameter4dvNV=_Lazy_glProgramParameter4dvNV;
PFNGLPROGRAMPARAMETER4FNVPROC pglProgramParameter4fNV=_Lazy_glProgramParameter4fNV;
PFNGLPROGRAMPARAMETER4FVNVPROC pglProgramParameter4fvNV=_Lazy_glProgramParameter4fvNV;
PFNGLPROGRAMPARAMETERS4DVNVPROC pglProgramParameters4dvNV=_Lazy_glProgramParameters4dvNV;
PFNGLPROGRAMPARAMETERS4FVNVPROC pglProgramParameters4fvNV=_Lazy_glProgramParameters4fvNV;
PFNGLREQUESTRESIDENTPROGRAMSNVPROC pglRequestResidentProgramsNV=_Lazy_glRequestResidentProgramsNV;
PFNGLTRACKMATRIXNVPROC pglTrackMatrixNV=_Lazy_glTrackMatrixNV;
PFNGLVERTEXATTRIBPOINTERNVPROC pglVertexAttribPointerNV=_Lazy_glVertexAttribPointerNV;
PFNGLVERTEXATTRIB1DNVPROC pglVertexAttrib1dNV=_Lazy_glVertexAttrib1dNV;
PFNGLVERTEXATTRIB1DVNVPROC pglVertexAttrib1dvNV=_Lazy_glVertexAttrib1dvNV;
PFNGLVERTEXATTRIB1FNVPROC pglVertexAttrib1fNV=_Lazy_glVertexAttrib1fNV;
PFNGLVERTEXATTRIB1FVNVPROC pglVertexAttrib1fvNV=_Lazy_glVertexAttrib1fvNV;
PFNGLVERTEXATTRIB1SNVPROC pglVertexAttrib1sNV=_Lazy_glVertexAttrib1sNV;
PFNGLVERTEXATTRIB1SVNVPROC pglVertexAttrib1svNV=_Lazy_glVertexAttrib1svNV;
PFNGLVERTEXATTRIB2DNVPROC pglVertexAttrib2dNV=_Lazy_glVertexAttrib2dNV;
PFNGLVERTEXATTRIB2DVNVPROC pglVertexAttrib2dvNV=_Lazy_glVertexAttrib2dvNV;
PFNGLVERTEXATTRIB2FNVPROC pglVertexAttrib2fNV=_Lazy_glVertexAttrib2fNV;
PFNGLVERTEXATTRIB2FVNVPROC pglVertexAttrib2fvNV=_Lazy_glVertexAttrib2fvNV;
PFNGLVERTEXATTRIB2SNVPROC pglVertexAttrib2sNV=_Lazy_glVertexAttrib2sNV;
PFNGLVERTEXATTRIB2SVNVPROC pglVertexAttrib2svNV=_Lazy_glVertexAttrib2svNV;
PFNGLVERTEXATTRIB3DNVPROC pglVertexAttrib3dNV=_Lazy_glVertexAttrib3dNV;
PFNGLVERTEXATTRIB3DVNVPROC pglVertexAttrib3dvNV=_Lazy_glVertexAttrib3dvNV;
PFNGLVERTEXATTRIB3FNVPROC pglVertexAttrib3fNV=_Lazy_glVertexAttrib3fNV;
PFNGLVERTEXATTRIB3FVNVPROC pglVertexAttrib3fvNV=_Lazy_glVertexAttrib3fvNV;
PFNGLVERTEXATTRIB3SNVPROC pglVertexAttrib3sNV=_Lazy_glVertexAttrib3sNV;
PFNGLVERTEXATTRIB3SVNVPROC pglVertexAttrib3svNV=_Lazy_glVertexAttrib3svNV;
PFNGLVERTEXATTRIB4DNVPROC pglVertexAttrib4dNV=_Lazy_glVertexAttrib4dNV;
PFNGLVERTEXATTRIB4DVNVPROC pglVertexAttrib4dvNV=_Lazy_glVertexAttrib4dvNV;
PFNGLVERTEXATTRIB4FNVPROC pglVertexAttrib4fNV=_Lazy_glVertexAttrib4fNV;
PFNGLVERTEXATTRIB4FVNVPROC pglVertexAttrib4fvNV=_Lazy_glVertexAttrib4fvNV;
PFNGLVERTEXATTRIB4SNVPROC pglVertexAttrib4sNV=_Lazy_glVertexAttrib4sNV;
PFNGLVERTEXATTRIB4SVNVPROC pglVertexAttrib4svNV=_Lazy_glVertexAttrib4svNV;
PFNGLVERTEXATTRIB4UBNVPROC pglVertexAttrib4ubNV=_Lazy_glVertexAttrib4ubNV;
PFNGLVERTEXATTRIB4UBVNVPROC pglVertexAttrib4ubvNV=_Lazy_glVertexAttrib4ubvNV;
PFNGLVERTEXATTRIBS1DVNVPROC pglVertexAttribs1dvNV=_Lazy_glVertexAttribs1dvNV;
PFNGLVERTEXATTRIBS1FVNVPROC pglVertexAttribs1fvNV=_Lazy_glVertexAttribs1fvNV;
PFNGLVERTEXATTRIBS1SVNVPROC pglVertexAttribs1svNV=_Lazy_glVertexAttribs1svNV;
PFNGLVERTEXATTRIBS2DVNVPROC pglVertexAttribs2dvNV=_Lazy_glVertexAttribs2dvNV;
PFNGLVERTEXATTRIBS2FVNVPROC pglVertexAttribs2fvNV=_Lazy_glVertexAttribs2fvNV;
PFNGLVERTEXATTRIBS2SVNVPROC pglVertexAttribs2svNV=_Lazy_glVertexAttribs2svNV;
PFNGLVERTEXATTRIBS3DVNVPROC pglVertexAttribs3dvNV=_Lazy_glVertexAttribs3dvNV;
PFNGLVERTEXATTRIBS3FVNVPROC pglVertexAttribs3fvNV=_Lazy_glVertexAttribs3fvNV;
PFNGLVERTEXATTRIBS3SVNVPROC pglVertexAttribs3svNV=_Lazy_glVertexAttribs3svNV;
PFNGLVERTEXATTRIBS4DVNVPROC pglVertexAttribs4dvNV=_Lazy_glVertexAttribs4dvNV;
PFNGLVERTEXATTRIBS4FVNVPROC pglVertexAttribs4fvNV=_Lazy_glVertexAttribs4fvNV;
PFNGLVERTEXATTRIBS4SVNVPROC pglVertexAttribs4svNV=_Lazy_glVertexAttribs4svNV;
PFNGLVERTEXATTRIBS4UBVNVPROC pglVertexAttribs4ubvNV=_Lazy_glVertexAttribs4ubvNV;
#endif 

/* GL_SGIX_texture_coordinate_clamp */

#ifdef __GLEE_GL_SGIX_texture_coordinate_clamp
#endif 

/* GL_SGIX_scalebias_hint */

#ifdef __GLEE_GL_SGIX_scalebias_hint
#endif 

/* GL_OML_interlace */

#ifdef __GLEE_GL_OML_interlace
#endif 

/* GL_OML_subsample */

#ifdef __GLEE_GL_OML_subsample
#endif 

/* GL_OML_resample */

#ifdef __GLEE_GL_OML_resample
#endif 

/* GL_NV_copy_depth_to_color */

#ifdef __GLEE_GL_NV_copy_depth_to_color
#endif 

/* GL_ATI_envmap_bumpmap */

#ifdef __GLEE_GL_ATI_envmap_bumpmap
void __stdcall _Lazy_glTexBumpParameterivATI(GLenum pname, const GLint * param)           {if (GLeeInit()) glTexBumpParameterivATI(pname, param);}
void __stdcall _Lazy_glTexBumpParameterfvATI(GLenum pname, const GLfloat * param)         {if (GLeeInit()) glTexBumpParameterfvATI(pname, param);}
void __stdcall _Lazy_glGetTexBumpParameterivATI(GLenum pname, GLint * param)              {if (GLeeInit()) glGetTexBumpParameterivATI(pname, param);}
void __stdcall _Lazy_glGetTexBumpParameterfvATI(GLenum pname, GLfloat * param)            {if (GLeeInit()) glGetTexBumpParameterfvATI(pname, param);}
PFNGLTEXBUMPPARAMETERIVATIPROC pglTexBumpParameterivATI=_Lazy_glTexBumpParameterivATI;
PFNGLTEXBUMPPARAMETERFVATIPROC pglTexBumpParameterfvATI=_Lazy_glTexBumpParameterfvATI;
PFNGLGETTEXBUMPPARAMETERIVATIPROC pglGetTexBumpParameterivATI=_Lazy_glGetTexBumpParameterivATI;
PFNGLGETTEXBUMPPARAMETERFVATIPROC pglGetTexBumpParameterfvATI=_Lazy_glGetTexBumpParameterfvATI;
#endif 

/* GL_ATI_fragment_shader */

#ifdef __GLEE_GL_ATI_fragment_shader
GLuint __stdcall _Lazy_glGenFragmentShadersATI(GLuint range)                              {if (GLeeInit()) return glGenFragmentShadersATI(range); return (GLuint)0;}
void __stdcall _Lazy_glBindFragmentShaderATI(GLuint id)                                   {if (GLeeInit()) glBindFragmentShaderATI(id);}
void __stdcall _Lazy_glDeleteFragmentShaderATI(GLuint id)                                 {if (GLeeInit()) glDeleteFragmentShaderATI(id);}
void __stdcall _Lazy_glBeginFragmentShaderATI(void)                                       {if (GLeeInit()) glBeginFragmentShaderATI();}
void __stdcall _Lazy_glEndFragmentShaderATI(void)                                         {if (GLeeInit()) glEndFragmentShaderATI();}
void __stdcall _Lazy_glPassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle)          {if (GLeeInit()) glPassTexCoordATI(dst, coord, swizzle);}
void __stdcall _Lazy_glSampleMapATI(GLuint dst, GLuint interp, GLenum swizzle)            {if (GLeeInit()) glSampleMapATI(dst, interp, swizzle);}
void __stdcall _Lazy_glColorFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod)  {if (GLeeInit()) glColorFragmentOp1ATI(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod);}
void __stdcall _Lazy_glColorFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod)  {if (GLeeInit()) glColorFragmentOp2ATI(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod);}
void __stdcall _Lazy_glColorFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod)  {if (GLeeInit()) glColorFragmentOp3ATI(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod);}
void __stdcall _Lazy_glAlphaFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod)  {if (GLeeInit()) glAlphaFragmentOp1ATI(op, dst, dstMod, arg1, arg1Rep, arg1Mod);}
void __stdcall _Lazy_glAlphaFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod)  {if (GLeeInit()) glAlphaFragmentOp2ATI(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod);}
void __stdcall _Lazy_glAlphaFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod)  {if (GLeeInit()) glAlphaFragmentOp3ATI(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod);}
void __stdcall _Lazy_glSetFragmentShaderConstantATI(GLuint dst, const GLfloat * value)    {if (GLeeInit()) glSetFragmentShaderConstantATI(dst, value);}
PFNGLGENFRAGMENTSHADERSATIPROC pglGenFragmentShadersATI=_Lazy_glGenFragmentShadersATI;
PFNGLBINDFRAGMENTSHADERATIPROC pglBindFragmentShaderATI=_Lazy_glBindFragmentShaderATI;
PFNGLDELETEFRAGMENTSHADERATIPROC pglDeleteFragmentShaderATI=_Lazy_glDeleteFragmentShaderATI;
PFNGLBEGINFRAGMENTSHADERATIPROC pglBeginFragmentShaderATI=_Lazy_glBeginFragmentShaderATI;
PFNGLENDFRAGMENTSHADERATIPROC pglEndFragmentShaderATI=_Lazy_glEndFragmentShaderATI;
PFNGLPASSTEXCOORDATIPROC pglPassTexCoordATI=_Lazy_glPassTexCoordATI;
PFNGLSAMPLEMAPATIPROC pglSampleMapATI=_Lazy_glSampleMapATI;
PFNGLCOLORFRAGMENTOP1ATIPROC pglColorFragmentOp1ATI=_Lazy_glColorFragmentOp1ATI;
PFNGLCOLORFRAGMENTOP2ATIPROC pglColorFragmentOp2ATI=_Lazy_glColorFragmentOp2ATI;
PFNGLCOLORFRAGMENTOP3ATIPROC pglColorFragmentOp3ATI=_Lazy_glColorFragmentOp3ATI;
PFNGLALPHAFRAGMENTOP1ATIPROC pglAlphaFragmentOp1ATI=_Lazy_glAlphaFragmentOp1ATI;
PFNGLALPHAFRAGMENTOP2ATIPROC pglAlphaFragmentOp2ATI=_Lazy_glAlphaFragmentOp2ATI;
PFNGLALPHAFRAGMENTOP3ATIPROC pglAlphaFragmentOp3ATI=_Lazy_glAlphaFragmentOp3ATI;
PFNGLSETFRAGMENTSHADERCONSTANTATIPROC pglSetFragmentShaderConstantATI=_Lazy_glSetFragmentShaderConstantATI;
#endif 

/* GL_ATI_pn_triangles */

#ifdef __GLEE_GL_ATI_pn_triangles
void __stdcall _Lazy_glPNTrianglesiATI(GLenum pname, GLint param)                         {if (GLeeInit()) glPNTrianglesiATI(pname, param);}
void __stdcall _Lazy_glPNTrianglesfATI(GLenum pname, GLfloat param)                       {if (GLeeInit()) glPNTrianglesfATI(pname, param);}
PFNGLPNTRIANGLESIATIPROC pglPNTrianglesiATI=_Lazy_glPNTrianglesiATI;
PFNGLPNTRIANGLESFATIPROC pglPNTrianglesfATI=_Lazy_glPNTrianglesfATI;
#endif 

/* GL_ATI_vertex_array_object */

#ifdef __GLEE_GL_ATI_vertex_array_object
GLuint __stdcall _Lazy_glNewObjectBufferATI(GLsizei size, const GLvoid * pointer, GLenum usage)  {if (GLeeInit()) return glNewObjectBufferATI(size, pointer, usage); return (GLuint)0;}
GLboolean __stdcall _Lazy_glIsObjectBufferATI(GLuint buffer)                              {if (GLeeInit()) return glIsObjectBufferATI(buffer); return (GLboolean)0;}
void __stdcall _Lazy_glUpdateObjectBufferATI(GLuint buffer, GLuint offset, GLsizei size, const GLvoid * pointer, GLenum preserve)  {if (GLeeInit()) glUpdateObjectBufferATI(buffer, offset, size, pointer, preserve);}
void __stdcall _Lazy_glGetObjectBufferfvATI(GLuint buffer, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetObjectBufferfvATI(buffer, pname, params);}
void __stdcall _Lazy_glGetObjectBufferivATI(GLuint buffer, GLenum pname, GLint * params)  {if (GLeeInit()) glGetObjectBufferivATI(buffer, pname, params);}
void __stdcall _Lazy_glFreeObjectBufferATI(GLuint buffer)                                 {if (GLeeInit()) glFreeObjectBufferATI(buffer);}
void __stdcall _Lazy_glArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset)  {if (GLeeInit()) glArrayObjectATI(array, size, type, stride, buffer, offset);}
void __stdcall _Lazy_glGetArrayObjectfvATI(GLenum array, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetArrayObjectfvATI(array, pname, params);}
void __stdcall _Lazy_glGetArrayObjectivATI(GLenum array, GLenum pname, GLint * params)    {if (GLeeInit()) glGetArrayObjectivATI(array, pname, params);}
void __stdcall _Lazy_glVariantArrayObjectATI(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset)  {if (GLeeInit()) glVariantArrayObjectATI(id, type, stride, buffer, offset);}
void __stdcall _Lazy_glGetVariantArrayObjectfvATI(GLuint id, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetVariantArrayObjectfvATI(id, pname, params);}
void __stdcall _Lazy_glGetVariantArrayObjectivATI(GLuint id, GLenum pname, GLint * params)  {if (GLeeInit()) glGetVariantArrayObjectivATI(id, pname, params);}
PFNGLNEWOBJECTBUFFERATIPROC pglNewObjectBufferATI=_Lazy_glNewObjectBufferATI;
PFNGLISOBJECTBUFFERATIPROC pglIsObjectBufferATI=_Lazy_glIsObjectBufferATI;
PFNGLUPDATEOBJECTBUFFERATIPROC pglUpdateObjectBufferATI=_Lazy_glUpdateObjectBufferATI;
PFNGLGETOBJECTBUFFERFVATIPROC pglGetObjectBufferfvATI=_Lazy_glGetObjectBufferfvATI;
PFNGLGETOBJECTBUFFERIVATIPROC pglGetObjectBufferivATI=_Lazy_glGetObjectBufferivATI;
PFNGLFREEOBJECTBUFFERATIPROC pglFreeObjectBufferATI=_Lazy_glFreeObjectBufferATI;
PFNGLARRAYOBJECTATIPROC pglArrayObjectATI=_Lazy_glArrayObjectATI;
PFNGLGETARRAYOBJECTFVATIPROC pglGetArrayObjectfvATI=_Lazy_glGetArrayObjectfvATI;
PFNGLGETARRAYOBJECTIVATIPROC pglGetArrayObjectivATI=_Lazy_glGetArrayObjectivATI;
PFNGLVARIANTARRAYOBJECTATIPROC pglVariantArrayObjectATI=_Lazy_glVariantArrayObjectATI;
PFNGLGETVARIANTARRAYOBJECTFVATIPROC pglGetVariantArrayObjectfvATI=_Lazy_glGetVariantArrayObjectfvATI;
PFNGLGETVARIANTARRAYOBJECTIVATIPROC pglGetVariantArrayObjectivATI=_Lazy_glGetVariantArrayObjectivATI;
#endif 

/* GL_EXT_vertex_shader */

#ifdef __GLEE_GL_EXT_vertex_shader
void __stdcall _Lazy_glBeginVertexShaderEXT(void)                                         {if (GLeeInit()) glBeginVertexShaderEXT();}
void __stdcall _Lazy_glEndVertexShaderEXT(void)                                           {if (GLeeInit()) glEndVertexShaderEXT();}
void __stdcall _Lazy_glBindVertexShaderEXT(GLuint id)                                     {if (GLeeInit()) glBindVertexShaderEXT(id);}
GLuint __stdcall _Lazy_glGenVertexShadersEXT(GLuint range)                                {if (GLeeInit()) return glGenVertexShadersEXT(range); return (GLuint)0;}
void __stdcall _Lazy_glDeleteVertexShaderEXT(GLuint id)                                   {if (GLeeInit()) glDeleteVertexShaderEXT(id);}
void __stdcall _Lazy_glShaderOp1EXT(GLenum op, GLuint res, GLuint arg1)                   {if (GLeeInit()) glShaderOp1EXT(op, res, arg1);}
void __stdcall _Lazy_glShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2)      {if (GLeeInit()) glShaderOp2EXT(op, res, arg1, arg2);}
void __stdcall _Lazy_glShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3)  {if (GLeeInit()) glShaderOp3EXT(op, res, arg1, arg2, arg3);}
void __stdcall _Lazy_glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW)  {if (GLeeInit()) glSwizzleEXT(res, in, outX, outY, outZ, outW);}
void __stdcall _Lazy_glWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW)  {if (GLeeInit()) glWriteMaskEXT(res, in, outX, outY, outZ, outW);}
void __stdcall _Lazy_glInsertComponentEXT(GLuint res, GLuint src, GLuint num)             {if (GLeeInit()) glInsertComponentEXT(res, src, num);}
void __stdcall _Lazy_glExtractComponentEXT(GLuint res, GLuint src, GLuint num)            {if (GLeeInit()) glExtractComponentEXT(res, src, num);}
GLuint __stdcall _Lazy_glGenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components)  {if (GLeeInit()) return glGenSymbolsEXT(datatype, storagetype, range, components); return (GLuint)0;}
void __stdcall _Lazy_glSetInvariantEXT(GLuint id, GLenum type, const GLvoid * addr)       {if (GLeeInit()) glSetInvariantEXT(id, type, addr);}
void __stdcall _Lazy_glSetLocalConstantEXT(GLuint id, GLenum type, const GLvoid * addr)   {if (GLeeInit()) glSetLocalConstantEXT(id, type, addr);}
void __stdcall _Lazy_glVariantbvEXT(GLuint id, const GLbyte * addr)                       {if (GLeeInit()) glVariantbvEXT(id, addr);}
void __stdcall _Lazy_glVariantsvEXT(GLuint id, const GLshort * addr)                      {if (GLeeInit()) glVariantsvEXT(id, addr);}
void __stdcall _Lazy_glVariantivEXT(GLuint id, const GLint * addr)                        {if (GLeeInit()) glVariantivEXT(id, addr);}
void __stdcall _Lazy_glVariantfvEXT(GLuint id, const GLfloat * addr)                      {if (GLeeInit()) glVariantfvEXT(id, addr);}
void __stdcall _Lazy_glVariantdvEXT(GLuint id, const GLdouble * addr)                     {if (GLeeInit()) glVariantdvEXT(id, addr);}
void __stdcall _Lazy_glVariantubvEXT(GLuint id, const GLubyte * addr)                     {if (GLeeInit()) glVariantubvEXT(id, addr);}
void __stdcall _Lazy_glVariantusvEXT(GLuint id, const GLushort * addr)                    {if (GLeeInit()) glVariantusvEXT(id, addr);}
void __stdcall _Lazy_glVariantuivEXT(GLuint id, const GLuint * addr)                      {if (GLeeInit()) glVariantuivEXT(id, addr);}
void __stdcall _Lazy_glVariantPointerEXT(GLuint id, GLenum type, GLuint stride, const GLvoid * addr)  {if (GLeeInit()) glVariantPointerEXT(id, type, stride, addr);}
void __stdcall _Lazy_glEnableVariantClientStateEXT(GLuint id)                             {if (GLeeInit()) glEnableVariantClientStateEXT(id);}
void __stdcall _Lazy_glDisableVariantClientStateEXT(GLuint id)                            {if (GLeeInit()) glDisableVariantClientStateEXT(id);}
GLuint __stdcall _Lazy_glBindLightParameterEXT(GLenum light, GLenum value)                {if (GLeeInit()) return glBindLightParameterEXT(light, value); return (GLuint)0;}
GLuint __stdcall _Lazy_glBindMaterialParameterEXT(GLenum face, GLenum value)              {if (GLeeInit()) return glBindMaterialParameterEXT(face, value); return (GLuint)0;}
GLuint __stdcall _Lazy_glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value)  {if (GLeeInit()) return glBindTexGenParameterEXT(unit, coord, value); return (GLuint)0;}
GLuint __stdcall _Lazy_glBindTextureUnitParameterEXT(GLenum unit, GLenum value)           {if (GLeeInit()) return glBindTextureUnitParameterEXT(unit, value); return (GLuint)0;}
GLuint __stdcall _Lazy_glBindParameterEXT(GLenum value)                                   {if (GLeeInit()) return glBindParameterEXT(value); return (GLuint)0;}
GLboolean __stdcall _Lazy_glIsVariantEnabledEXT(GLuint id, GLenum cap)                    {if (GLeeInit()) return glIsVariantEnabledEXT(id, cap); return (GLboolean)0;}
void __stdcall _Lazy_glGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean * data)   {if (GLeeInit()) glGetVariantBooleanvEXT(id, value, data);}
void __stdcall _Lazy_glGetVariantIntegervEXT(GLuint id, GLenum value, GLint * data)       {if (GLeeInit()) glGetVariantIntegervEXT(id, value, data);}
void __stdcall _Lazy_glGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat * data)       {if (GLeeInit()) glGetVariantFloatvEXT(id, value, data);}
void __stdcall _Lazy_glGetVariantPointervEXT(GLuint id, GLenum value, GLvoid* * data)     {if (GLeeInit()) glGetVariantPointervEXT(id, value, data);}
void __stdcall _Lazy_glGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean * data)  {if (GLeeInit()) glGetInvariantBooleanvEXT(id, value, data);}
void __stdcall _Lazy_glGetInvariantIntegervEXT(GLuint id, GLenum value, GLint * data)     {if (GLeeInit()) glGetInvariantIntegervEXT(id, value, data);}
void __stdcall _Lazy_glGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat * data)     {if (GLeeInit()) glGetInvariantFloatvEXT(id, value, data);}
void __stdcall _Lazy_glGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean * data)  {if (GLeeInit()) glGetLocalConstantBooleanvEXT(id, value, data);}
void __stdcall _Lazy_glGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint * data)  {if (GLeeInit()) glGetLocalConstantIntegervEXT(id, value, data);}
void __stdcall _Lazy_glGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat * data)  {if (GLeeInit()) glGetLocalConstantFloatvEXT(id, value, data);}
PFNGLBEGINVERTEXSHADEREXTPROC pglBeginVertexShaderEXT=_Lazy_glBeginVertexShaderEXT;
PFNGLENDVERTEXSHADEREXTPROC pglEndVertexShaderEXT=_Lazy_glEndVertexShaderEXT;
PFNGLBINDVERTEXSHADEREXTPROC pglBindVertexShaderEXT=_Lazy_glBindVertexShaderEXT;
PFNGLGENVERTEXSHADERSEXTPROC pglGenVertexShadersEXT=_Lazy_glGenVertexShadersEXT;
PFNGLDELETEVERTEXSHADEREXTPROC pglDeleteVertexShaderEXT=_Lazy_glDeleteVertexShaderEXT;
PFNGLSHADEROP1EXTPROC pglShaderOp1EXT=_Lazy_glShaderOp1EXT;
PFNGLSHADEROP2EXTPROC pglShaderOp2EXT=_Lazy_glShaderOp2EXT;
PFNGLSHADEROP3EXTPROC pglShaderOp3EXT=_Lazy_glShaderOp3EXT;
PFNGLSWIZZLEEXTPROC pglSwizzleEXT=_Lazy_glSwizzleEXT;
PFNGLWRITEMASKEXTPROC pglWriteMaskEXT=_Lazy_glWriteMaskEXT;
PFNGLINSERTCOMPONENTEXTPROC pglInsertComponentEXT=_Lazy_glInsertComponentEXT;
PFNGLEXTRACTCOMPONENTEXTPROC pglExtractComponentEXT=_Lazy_glExtractComponentEXT;
PFNGLGENSYMBOLSEXTPROC pglGenSymbolsEXT=_Lazy_glGenSymbolsEXT;
PFNGLSETINVARIANTEXTPROC pglSetInvariantEXT=_Lazy_glSetInvariantEXT;
PFNGLSETLOCALCONSTANTEXTPROC pglSetLocalConstantEXT=_Lazy_glSetLocalConstantEXT;
PFNGLVARIANTBVEXTPROC pglVariantbvEXT=_Lazy_glVariantbvEXT;
PFNGLVARIANTSVEXTPROC pglVariantsvEXT=_Lazy_glVariantsvEXT;
PFNGLVARIANTIVEXTPROC pglVariantivEXT=_Lazy_glVariantivEXT;
PFNGLVARIANTFVEXTPROC pglVariantfvEXT=_Lazy_glVariantfvEXT;
PFNGLVARIANTDVEXTPROC pglVariantdvEXT=_Lazy_glVariantdvEXT;
PFNGLVARIANTUBVEXTPROC pglVariantubvEXT=_Lazy_glVariantubvEXT;
PFNGLVARIANTUSVEXTPROC pglVariantusvEXT=_Lazy_glVariantusvEXT;
PFNGLVARIANTUIVEXTPROC pglVariantuivEXT=_Lazy_glVariantuivEXT;
PFNGLVARIANTPOINTEREXTPROC pglVariantPointerEXT=_Lazy_glVariantPointerEXT;
PFNGLENABLEVARIANTCLIENTSTATEEXTPROC pglEnableVariantClientStateEXT=_Lazy_glEnableVariantClientStateEXT;
PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC pglDisableVariantClientStateEXT=_Lazy_glDisableVariantClientStateEXT;
PFNGLBINDLIGHTPARAMETEREXTPROC pglBindLightParameterEXT=_Lazy_glBindLightParameterEXT;
PFNGLBINDMATERIALPARAMETEREXTPROC pglBindMaterialParameterEXT=_Lazy_glBindMaterialParameterEXT;
PFNGLBINDTEXGENPARAMETEREXTPROC pglBindTexGenParameterEXT=_Lazy_glBindTexGenParameterEXT;
PFNGLBINDTEXTUREUNITPARAMETEREXTPROC pglBindTextureUnitParameterEXT=_Lazy_glBindTextureUnitParameterEXT;
PFNGLBINDPARAMETEREXTPROC pglBindParameterEXT=_Lazy_glBindParameterEXT;
PFNGLISVARIANTENABLEDEXTPROC pglIsVariantEnabledEXT=_Lazy_glIsVariantEnabledEXT;
PFNGLGETVARIANTBOOLEANVEXTPROC pglGetVariantBooleanvEXT=_Lazy_glGetVariantBooleanvEXT;
PFNGLGETVARIANTINTEGERVEXTPROC pglGetVariantIntegervEXT=_Lazy_glGetVariantIntegervEXT;
PFNGLGETVARIANTFLOATVEXTPROC pglGetVariantFloatvEXT=_Lazy_glGetVariantFloatvEXT;
PFNGLGETVARIANTPOINTERVEXTPROC pglGetVariantPointervEXT=_Lazy_glGetVariantPointervEXT;
PFNGLGETINVARIANTBOOLEANVEXTPROC pglGetInvariantBooleanvEXT=_Lazy_glGetInvariantBooleanvEXT;
PFNGLGETINVARIANTINTEGERVEXTPROC pglGetInvariantIntegervEXT=_Lazy_glGetInvariantIntegervEXT;
PFNGLGETINVARIANTFLOATVEXTPROC pglGetInvariantFloatvEXT=_Lazy_glGetInvariantFloatvEXT;
PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC pglGetLocalConstantBooleanvEXT=_Lazy_glGetLocalConstantBooleanvEXT;
PFNGLGETLOCALCONSTANTINTEGERVEXTPROC pglGetLocalConstantIntegervEXT=_Lazy_glGetLocalConstantIntegervEXT;
PFNGLGETLOCALCONSTANTFLOATVEXTPROC pglGetLocalConstantFloatvEXT=_Lazy_glGetLocalConstantFloatvEXT;
#endif 

/* GL_ATI_vertex_streams */

#ifdef __GLEE_GL_ATI_vertex_streams
void __stdcall _Lazy_glVertexStream1sATI(GLenum stream, GLshort x)                        {if (GLeeInit()) glVertexStream1sATI(stream, x);}
void __stdcall _Lazy_glVertexStream1svATI(GLenum stream, const GLshort * coords)          {if (GLeeInit()) glVertexStream1svATI(stream, coords);}
void __stdcall _Lazy_glVertexStream1iATI(GLenum stream, GLint x)                          {if (GLeeInit()) glVertexStream1iATI(stream, x);}
void __stdcall _Lazy_glVertexStream1ivATI(GLenum stream, const GLint * coords)            {if (GLeeInit()) glVertexStream1ivATI(stream, coords);}
void __stdcall _Lazy_glVertexStream1fATI(GLenum stream, GLfloat x)                        {if (GLeeInit()) glVertexStream1fATI(stream, x);}
void __stdcall _Lazy_glVertexStream1fvATI(GLenum stream, const GLfloat * coords)          {if (GLeeInit()) glVertexStream1fvATI(stream, coords);}
void __stdcall _Lazy_glVertexStream1dATI(GLenum stream, GLdouble x)                       {if (GLeeInit()) glVertexStream1dATI(stream, x);}
void __stdcall _Lazy_glVertexStream1dvATI(GLenum stream, const GLdouble * coords)         {if (GLeeInit()) glVertexStream1dvATI(stream, coords);}
void __stdcall _Lazy_glVertexStream2sATI(GLenum stream, GLshort x, GLshort y)             {if (GLeeInit()) glVertexStream2sATI(stream, x, y);}
void __stdcall _Lazy_glVertexStream2svATI(GLenum stream, const GLshort * coords)          {if (GLeeInit()) glVertexStream2svATI(stream, coords);}
void __stdcall _Lazy_glVertexStream2iATI(GLenum stream, GLint x, GLint y)                 {if (GLeeInit()) glVertexStream2iATI(stream, x, y);}
void __stdcall _Lazy_glVertexStream2ivATI(GLenum stream, const GLint * coords)            {if (GLeeInit()) glVertexStream2ivATI(stream, coords);}
void __stdcall _Lazy_glVertexStream2fATI(GLenum stream, GLfloat x, GLfloat y)             {if (GLeeInit()) glVertexStream2fATI(stream, x, y);}
void __stdcall _Lazy_glVertexStream2fvATI(GLenum stream, const GLfloat * coords)          {if (GLeeInit()) glVertexStream2fvATI(stream, coords);}
void __stdcall _Lazy_glVertexStream2dATI(GLenum stream, GLdouble x, GLdouble y)           {if (GLeeInit()) glVertexStream2dATI(stream, x, y);}
void __stdcall _Lazy_glVertexStream2dvATI(GLenum stream, const GLdouble * coords)         {if (GLeeInit()) glVertexStream2dvATI(stream, coords);}
void __stdcall _Lazy_glVertexStream3sATI(GLenum stream, GLshort x, GLshort y, GLshort z)  {if (GLeeInit()) glVertexStream3sATI(stream, x, y, z);}
void __stdcall _Lazy_glVertexStream3svATI(GLenum stream, const GLshort * coords)          {if (GLeeInit()) glVertexStream3svATI(stream, coords);}
void __stdcall _Lazy_glVertexStream3iATI(GLenum stream, GLint x, GLint y, GLint z)        {if (GLeeInit()) glVertexStream3iATI(stream, x, y, z);}
void __stdcall _Lazy_glVertexStream3ivATI(GLenum stream, const GLint * coords)            {if (GLeeInit()) glVertexStream3ivATI(stream, coords);}
void __stdcall _Lazy_glVertexStream3fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z)  {if (GLeeInit()) glVertexStream3fATI(stream, x, y, z);}
void __stdcall _Lazy_glVertexStream3fvATI(GLenum stream, const GLfloat * coords)          {if (GLeeInit()) glVertexStream3fvATI(stream, coords);}
void __stdcall _Lazy_glVertexStream3dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z)  {if (GLeeInit()) glVertexStream3dATI(stream, x, y, z);}
void __stdcall _Lazy_glVertexStream3dvATI(GLenum stream, const GLdouble * coords)         {if (GLeeInit()) glVertexStream3dvATI(stream, coords);}
void __stdcall _Lazy_glVertexStream4sATI(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w)  {if (GLeeInit()) glVertexStream4sATI(stream, x, y, z, w);}
void __stdcall _Lazy_glVertexStream4svATI(GLenum stream, const GLshort * coords)          {if (GLeeInit()) glVertexStream4svATI(stream, coords);}
void __stdcall _Lazy_glVertexStream4iATI(GLenum stream, GLint x, GLint y, GLint z, GLint w)  {if (GLeeInit()) glVertexStream4iATI(stream, x, y, z, w);}
void __stdcall _Lazy_glVertexStream4ivATI(GLenum stream, const GLint * coords)            {if (GLeeInit()) glVertexStream4ivATI(stream, coords);}
void __stdcall _Lazy_glVertexStream4fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w)  {if (GLeeInit()) glVertexStream4fATI(stream, x, y, z, w);}
void __stdcall _Lazy_glVertexStream4fvATI(GLenum stream, const GLfloat * coords)          {if (GLeeInit()) glVertexStream4fvATI(stream, coords);}
void __stdcall _Lazy_glVertexStream4dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w)  {if (GLeeInit()) glVertexStream4dATI(stream, x, y, z, w);}
void __stdcall _Lazy_glVertexStream4dvATI(GLenum stream, const GLdouble * coords)         {if (GLeeInit()) glVertexStream4dvATI(stream, coords);}
void __stdcall _Lazy_glNormalStream3bATI(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz)  {if (GLeeInit()) glNormalStream3bATI(stream, nx, ny, nz);}
void __stdcall _Lazy_glNormalStream3bvATI(GLenum stream, const GLbyte * coords)           {if (GLeeInit()) glNormalStream3bvATI(stream, coords);}
void __stdcall _Lazy_glNormalStream3sATI(GLenum stream, GLshort nx, GLshort ny, GLshort nz)  {if (GLeeInit()) glNormalStream3sATI(stream, nx, ny, nz);}
void __stdcall _Lazy_glNormalStream3svATI(GLenum stream, const GLshort * coords)          {if (GLeeInit()) glNormalStream3svATI(stream, coords);}
void __stdcall _Lazy_glNormalStream3iATI(GLenum stream, GLint nx, GLint ny, GLint nz)     {if (GLeeInit()) glNormalStream3iATI(stream, nx, ny, nz);}
void __stdcall _Lazy_glNormalStream3ivATI(GLenum stream, const GLint * coords)            {if (GLeeInit()) glNormalStream3ivATI(stream, coords);}
void __stdcall _Lazy_glNormalStream3fATI(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz)  {if (GLeeInit()) glNormalStream3fATI(stream, nx, ny, nz);}
void __stdcall _Lazy_glNormalStream3fvATI(GLenum stream, const GLfloat * coords)          {if (GLeeInit()) glNormalStream3fvATI(stream, coords);}
void __stdcall _Lazy_glNormalStream3dATI(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz)  {if (GLeeInit()) glNormalStream3dATI(stream, nx, ny, nz);}
void __stdcall _Lazy_glNormalStream3dvATI(GLenum stream, const GLdouble * coords)         {if (GLeeInit()) glNormalStream3dvATI(stream, coords);}
void __stdcall _Lazy_glClientActiveVertexStreamATI(GLenum stream)                         {if (GLeeInit()) glClientActiveVertexStreamATI(stream);}
void __stdcall _Lazy_glVertexBlendEnviATI(GLenum pname, GLint param)                      {if (GLeeInit()) glVertexBlendEnviATI(pname, param);}
void __stdcall _Lazy_glVertexBlendEnvfATI(GLenum pname, GLfloat param)                    {if (GLeeInit()) glVertexBlendEnvfATI(pname, param);}
PFNGLVERTEXSTREAM1SATIPROC pglVertexStream1sATI=_Lazy_glVertexStream1sATI;
PFNGLVERTEXSTREAM1SVATIPROC pglVertexStream1svATI=_Lazy_glVertexStream1svATI;
PFNGLVERTEXSTREAM1IATIPROC pglVertexStream1iATI=_Lazy_glVertexStream1iATI;
PFNGLVERTEXSTREAM1IVATIPROC pglVertexStream1ivATI=_Lazy_glVertexStream1ivATI;
PFNGLVERTEXSTREAM1FATIPROC pglVertexStream1fATI=_Lazy_glVertexStream1fATI;
PFNGLVERTEXSTREAM1FVATIPROC pglVertexStream1fvATI=_Lazy_glVertexStream1fvATI;
PFNGLVERTEXSTREAM1DATIPROC pglVertexStream1dATI=_Lazy_glVertexStream1dATI;
PFNGLVERTEXSTREAM1DVATIPROC pglVertexStream1dvATI=_Lazy_glVertexStream1dvATI;
PFNGLVERTEXSTREAM2SATIPROC pglVertexStream2sATI=_Lazy_glVertexStream2sATI;
PFNGLVERTEXSTREAM2SVATIPROC pglVertexStream2svATI=_Lazy_glVertexStream2svATI;
PFNGLVERTEXSTREAM2IATIPROC pglVertexStream2iATI=_Lazy_glVertexStream2iATI;
PFNGLVERTEXSTREAM2IVATIPROC pglVertexStream2ivATI=_Lazy_glVertexStream2ivATI;
PFNGLVERTEXSTREAM2FATIPROC pglVertexStream2fATI=_Lazy_glVertexStream2fATI;
PFNGLVERTEXSTREAM2FVATIPROC pglVertexStream2fvATI=_Lazy_glVertexStream2fvATI;
PFNGLVERTEXSTREAM2DATIPROC pglVertexStream2dATI=_Lazy_glVertexStream2dATI;
PFNGLVERTEXSTREAM2DVATIPROC pglVertexStream2dvATI=_Lazy_glVertexStream2dvATI;
PFNGLVERTEXSTREAM3SATIPROC pglVertexStream3sATI=_Lazy_glVertexStream3sATI;
PFNGLVERTEXSTREAM3SVATIPROC pglVertexStream3svATI=_Lazy_glVertexStream3svATI;
PFNGLVERTEXSTREAM3IATIPROC pglVertexStream3iATI=_Lazy_glVertexStream3iATI;
PFNGLVERTEXSTREAM3IVATIPROC pglVertexStream3ivATI=_Lazy_glVertexStream3ivATI;
PFNGLVERTEXSTREAM3FATIPROC pglVertexStream3fATI=_Lazy_glVertexStream3fATI;
PFNGLVERTEXSTREAM3FVATIPROC pglVertexStream3fvATI=_Lazy_glVertexStream3fvATI;
PFNGLVERTEXSTREAM3DATIPROC pglVertexStream3dATI=_Lazy_glVertexStream3dATI;
PFNGLVERTEXSTREAM3DVATIPROC pglVertexStream3dvATI=_Lazy_glVertexStream3dvATI;
PFNGLVERTEXSTREAM4SATIPROC pglVertexStream4sATI=_Lazy_glVertexStream4sATI;
PFNGLVERTEXSTREAM4SVATIPROC pglVertexStream4svATI=_Lazy_glVertexStream4svATI;
PFNGLVERTEXSTREAM4IATIPROC pglVertexStream4iATI=_Lazy_glVertexStream4iATI;
PFNGLVERTEXSTREAM4IVATIPROC pglVertexStream4ivATI=_Lazy_glVertexStream4ivATI;
PFNGLVERTEXSTREAM4FATIPROC pglVertexStream4fATI=_Lazy_glVertexStream4fATI;
PFNGLVERTEXSTREAM4FVATIPROC pglVertexStream4fvATI=_Lazy_glVertexStream4fvATI;
PFNGLVERTEXSTREAM4DATIPROC pglVertexStream4dATI=_Lazy_glVertexStream4dATI;
PFNGLVERTEXSTREAM4DVATIPROC pglVertexStream4dvATI=_Lazy_glVertexStream4dvATI;
PFNGLNORMALSTREAM3BATIPROC pglNormalStream3bATI=_Lazy_glNormalStream3bATI;
PFNGLNORMALSTREAM3BVATIPROC pglNormalStream3bvATI=_Lazy_glNormalStream3bvATI;
PFNGLNORMALSTREAM3SATIPROC pglNormalStream3sATI=_Lazy_glNormalStream3sATI;
PFNGLNORMALSTREAM3SVATIPROC pglNormalStream3svATI=_Lazy_glNormalStream3svATI;
PFNGLNORMALSTREAM3IATIPROC pglNormalStream3iATI=_Lazy_glNormalStream3iATI;
PFNGLNORMALSTREAM3IVATIPROC pglNormalStream3ivATI=_Lazy_glNormalStream3ivATI;
PFNGLNORMALSTREAM3FATIPROC pglNormalStream3fATI=_Lazy_glNormalStream3fATI;
PFNGLNORMALSTREAM3FVATIPROC pglNormalStream3fvATI=_Lazy_glNormalStream3fvATI;
PFNGLNORMALSTREAM3DATIPROC pglNormalStream3dATI=_Lazy_glNormalStream3dATI;
PFNGLNORMALSTREAM3DVATIPROC pglNormalStream3dvATI=_Lazy_glNormalStream3dvATI;
PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC pglClientActiveVertexStreamATI=_Lazy_glClientActiveVertexStreamATI;
PFNGLVERTEXBLENDENVIATIPROC pglVertexBlendEnviATI=_Lazy_glVertexBlendEnviATI;
PFNGLVERTEXBLENDENVFATIPROC pglVertexBlendEnvfATI=_Lazy_glVertexBlendEnvfATI;
#endif 

/* GL_ATI_element_array */

#ifdef __GLEE_GL_ATI_element_array
void __stdcall _Lazy_glElementPointerATI(GLenum type, const GLvoid * pointer)             {if (GLeeInit()) glElementPointerATI(type, pointer);}
void __stdcall _Lazy_glDrawElementArrayATI(GLenum mode, GLsizei count)                    {if (GLeeInit()) glDrawElementArrayATI(mode, count);}
void __stdcall _Lazy_glDrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count)  {if (GLeeInit()) glDrawRangeElementArrayATI(mode, start, end, count);}
PFNGLELEMENTPOINTERATIPROC pglElementPointerATI=_Lazy_glElementPointerATI;
PFNGLDRAWELEMENTARRAYATIPROC pglDrawElementArrayATI=_Lazy_glDrawElementArrayATI;
PFNGLDRAWRANGEELEMENTARRAYATIPROC pglDrawRangeElementArrayATI=_Lazy_glDrawRangeElementArrayATI;
#endif 

/* GL_SUN_mesh_array */

#ifdef __GLEE_GL_SUN_mesh_array
void __stdcall _Lazy_glDrawMeshArraysSUN(GLenum mode, GLint first, GLsizei count, GLsizei width)  {if (GLeeInit()) glDrawMeshArraysSUN(mode, first, count, width);}
PFNGLDRAWMESHARRAYSSUNPROC pglDrawMeshArraysSUN=_Lazy_glDrawMeshArraysSUN;
#endif 

/* GL_SUN_slice_accum */

#ifdef __GLEE_GL_SUN_slice_accum
#endif 

/* GL_NV_multisample_filter_hint */

#ifdef __GLEE_GL_NV_multisample_filter_hint
#endif 

/* GL_NV_depth_clamp */

#ifdef __GLEE_GL_NV_depth_clamp
#endif 

/* GL_NV_occlusion_query */

#ifdef __GLEE_GL_NV_occlusion_query
void __stdcall _Lazy_glGenOcclusionQueriesNV(GLsizei n, GLuint * ids)                     {if (GLeeInit()) glGenOcclusionQueriesNV(n, ids);}
void __stdcall _Lazy_glDeleteOcclusionQueriesNV(GLsizei n, const GLuint * ids)            {if (GLeeInit()) glDeleteOcclusionQueriesNV(n, ids);}
GLboolean __stdcall _Lazy_glIsOcclusionQueryNV(GLuint id)                                 {if (GLeeInit()) return glIsOcclusionQueryNV(id); return (GLboolean)0;}
void __stdcall _Lazy_glBeginOcclusionQueryNV(GLuint id)                                   {if (GLeeInit()) glBeginOcclusionQueryNV(id);}
void __stdcall _Lazy_glEndOcclusionQueryNV(void)                                          {if (GLeeInit()) glEndOcclusionQueryNV();}
void __stdcall _Lazy_glGetOcclusionQueryivNV(GLuint id, GLenum pname, GLint * params)     {if (GLeeInit()) glGetOcclusionQueryivNV(id, pname, params);}
void __stdcall _Lazy_glGetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint * params)   {if (GLeeInit()) glGetOcclusionQueryuivNV(id, pname, params);}
PFNGLGENOCCLUSIONQUERIESNVPROC pglGenOcclusionQueriesNV=_Lazy_glGenOcclusionQueriesNV;
PFNGLDELETEOCCLUSIONQUERIESNVPROC pglDeleteOcclusionQueriesNV=_Lazy_glDeleteOcclusionQueriesNV;
PFNGLISOCCLUSIONQUERYNVPROC pglIsOcclusionQueryNV=_Lazy_glIsOcclusionQueryNV;
PFNGLBEGINOCCLUSIONQUERYNVPROC pglBeginOcclusionQueryNV=_Lazy_glBeginOcclusionQueryNV;
PFNGLENDOCCLUSIONQUERYNVPROC pglEndOcclusionQueryNV=_Lazy_glEndOcclusionQueryNV;
PFNGLGETOCCLUSIONQUERYIVNVPROC pglGetOcclusionQueryivNV=_Lazy_glGetOcclusionQueryivNV;
PFNGLGETOCCLUSIONQUERYUIVNVPROC pglGetOcclusionQueryuivNV=_Lazy_glGetOcclusionQueryuivNV;
#endif 

/* GL_NV_point_sprite */

#ifdef __GLEE_GL_NV_point_sprite
void __stdcall _Lazy_glPointParameteriNV(GLenum pname, GLint param)                       {if (GLeeInit()) glPointParameteriNV(pname, param);}
void __stdcall _Lazy_glPointParameterivNV(GLenum pname, const GLint * params)             {if (GLeeInit()) glPointParameterivNV(pname, params);}
PFNGLPOINTPARAMETERINVPROC pglPointParameteriNV=_Lazy_glPointParameteriNV;
PFNGLPOINTPARAMETERIVNVPROC pglPointParameterivNV=_Lazy_glPointParameterivNV;
#endif 

/* GL_NV_texture_shader3 */

#ifdef __GLEE_GL_NV_texture_shader3
#endif 

/* GL_NV_vertex_program1_1 */

#ifdef __GLEE_GL_NV_vertex_program1_1
#endif 

/* GL_EXT_shadow_funcs */

#ifdef __GLEE_GL_EXT_shadow_funcs
#endif 

/* GL_EXT_stencil_two_side */

#ifdef __GLEE_GL_EXT_stencil_two_side
void __stdcall _Lazy_glActiveStencilFaceEXT(GLenum face)                                  {if (GLeeInit()) glActiveStencilFaceEXT(face);}
PFNGLACTIVESTENCILFACEEXTPROC pglActiveStencilFaceEXT=_Lazy_glActiveStencilFaceEXT;
#endif 

/* GL_ATI_text_fragment_shader */

#ifdef __GLEE_GL_ATI_text_fragment_shader
#endif 

/* GL_APPLE_client_storage */

#ifdef __GLEE_GL_APPLE_client_storage
#endif 

/* GL_APPLE_element_array */

#ifdef __GLEE_GL_APPLE_element_array
void __stdcall _Lazy_glElementPointerAPPLE(GLenum type, const GLvoid * pointer)           {if (GLeeInit()) glElementPointerAPPLE(type, pointer);}
void __stdcall _Lazy_glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count)     {if (GLeeInit()) glDrawElementArrayAPPLE(mode, first, count);}
void __stdcall _Lazy_glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count)  {if (GLeeInit()) glDrawRangeElementArrayAPPLE(mode, start, end, first, count);}
void __stdcall _Lazy_glMultiDrawElementArrayAPPLE(GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount)  {if (GLeeInit()) glMultiDrawElementArrayAPPLE(mode, first, count, primcount);}
void __stdcall _Lazy_glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, const GLint * first, const GLsizei * count, GLsizei primcount)  {if (GLeeInit()) glMultiDrawRangeElementArrayAPPLE(mode, start, end, first, count, primcount);}
PFNGLELEMENTPOINTERAPPLEPROC pglElementPointerAPPLE=_Lazy_glElementPointerAPPLE;
PFNGLDRAWELEMENTARRAYAPPLEPROC pglDrawElementArrayAPPLE=_Lazy_glDrawElementArrayAPPLE;
PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC pglDrawRangeElementArrayAPPLE=_Lazy_glDrawRangeElementArrayAPPLE;
PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC pglMultiDrawElementArrayAPPLE=_Lazy_glMultiDrawElementArrayAPPLE;
PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC pglMultiDrawRangeElementArrayAPPLE=_Lazy_glMultiDrawRangeElementArrayAPPLE;
#endif 

/* GL_APPLE_fence */

#ifdef __GLEE_GL_APPLE_fence
void __stdcall _Lazy_glGenFencesAPPLE(GLsizei n, GLuint * fences)                         {if (GLeeInit()) glGenFencesAPPLE(n, fences);}
void __stdcall _Lazy_glDeleteFencesAPPLE(GLsizei n, const GLuint * fences)                {if (GLeeInit()) glDeleteFencesAPPLE(n, fences);}
void __stdcall _Lazy_glSetFenceAPPLE(GLuint fence)                                        {if (GLeeInit()) glSetFenceAPPLE(fence);}
GLboolean __stdcall _Lazy_glIsFenceAPPLE(GLuint fence)                                    {if (GLeeInit()) return glIsFenceAPPLE(fence); return (GLboolean)0;}
GLboolean __stdcall _Lazy_glTestFenceAPPLE(GLuint fence)                                  {if (GLeeInit()) return glTestFenceAPPLE(fence); return (GLboolean)0;}
void __stdcall _Lazy_glFinishFenceAPPLE(GLuint fence)                                     {if (GLeeInit()) glFinishFenceAPPLE(fence);}
GLboolean __stdcall _Lazy_glTestObjectAPPLE(GLenum object, GLuint name)                   {if (GLeeInit()) return glTestObjectAPPLE(object, name); return (GLboolean)0;}
void __stdcall _Lazy_glFinishObjectAPPLE(GLenum object, GLint name)                       {if (GLeeInit()) glFinishObjectAPPLE(object, name);}
PFNGLGENFENCESAPPLEPROC pglGenFencesAPPLE=_Lazy_glGenFencesAPPLE;
PFNGLDELETEFENCESAPPLEPROC pglDeleteFencesAPPLE=_Lazy_glDeleteFencesAPPLE;
PFNGLSETFENCEAPPLEPROC pglSetFenceAPPLE=_Lazy_glSetFenceAPPLE;
PFNGLISFENCEAPPLEPROC pglIsFenceAPPLE=_Lazy_glIsFenceAPPLE;
PFNGLTESTFENCEAPPLEPROC pglTestFenceAPPLE=_Lazy_glTestFenceAPPLE;
PFNGLFINISHFENCEAPPLEPROC pglFinishFenceAPPLE=_Lazy_glFinishFenceAPPLE;
PFNGLTESTOBJECTAPPLEPROC pglTestObjectAPPLE=_Lazy_glTestObjectAPPLE;
PFNGLFINISHOBJECTAPPLEPROC pglFinishObjectAPPLE=_Lazy_glFinishObjectAPPLE;
#endif 

/* GL_APPLE_vertex_array_object */

#ifdef __GLEE_GL_APPLE_vertex_array_object
void __stdcall _Lazy_glBindVertexArrayAPPLE(GLuint array)                                 {if (GLeeInit()) glBindVertexArrayAPPLE(array);}
void __stdcall _Lazy_glDeleteVertexArraysAPPLE(GLsizei n, const GLuint * arrays)          {if (GLeeInit()) glDeleteVertexArraysAPPLE(n, arrays);}
void __stdcall _Lazy_glGenVertexArraysAPPLE(GLsizei n, const GLuint * arrays)             {if (GLeeInit()) glGenVertexArraysAPPLE(n, arrays);}
GLboolean __stdcall _Lazy_glIsVertexArrayAPPLE(GLuint array)                              {if (GLeeInit()) return glIsVertexArrayAPPLE(array); return (GLboolean)0;}
PFNGLBINDVERTEXARRAYAPPLEPROC pglBindVertexArrayAPPLE=_Lazy_glBindVertexArrayAPPLE;
PFNGLDELETEVERTEXARRAYSAPPLEPROC pglDeleteVertexArraysAPPLE=_Lazy_glDeleteVertexArraysAPPLE;
PFNGLGENVERTEXARRAYSAPPLEPROC pglGenVertexArraysAPPLE=_Lazy_glGenVertexArraysAPPLE;
PFNGLISVERTEXARRAYAPPLEPROC pglIsVertexArrayAPPLE=_Lazy_glIsVertexArrayAPPLE;
#endif 

/* GL_APPLE_vertex_array_range */

#ifdef __GLEE_GL_APPLE_vertex_array_range
void __stdcall _Lazy_glVertexArrayRangeAPPLE(GLsizei length, GLvoid * pointer)            {if (GLeeInit()) glVertexArrayRangeAPPLE(length, pointer);}
void __stdcall _Lazy_glFlushVertexArrayRangeAPPLE(GLsizei length, GLvoid * pointer)       {if (GLeeInit()) glFlushVertexArrayRangeAPPLE(length, pointer);}
void __stdcall _Lazy_glVertexArrayParameteriAPPLE(GLenum pname, GLint param)              {if (GLeeInit()) glVertexArrayParameteriAPPLE(pname, param);}
PFNGLVERTEXARRAYRANGEAPPLEPROC pglVertexArrayRangeAPPLE=_Lazy_glVertexArrayRangeAPPLE;
PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC pglFlushVertexArrayRangeAPPLE=_Lazy_glFlushVertexArrayRangeAPPLE;
PFNGLVERTEXARRAYPARAMETERIAPPLEPROC pglVertexArrayParameteriAPPLE=_Lazy_glVertexArrayParameteriAPPLE;
#endif 

/* GL_APPLE_ycbcr_422 */

#ifdef __GLEE_GL_APPLE_ycbcr_422
#endif 

/* GL_S3_s3tc */

#ifdef __GLEE_GL_S3_s3tc
#endif 

/* GL_ATI_draw_buffers */

#ifdef __GLEE_GL_ATI_draw_buffers
void __stdcall _Lazy_glDrawBuffersATI(GLsizei n, const GLenum * bufs)                     {if (GLeeInit()) glDrawBuffersATI(n, bufs);}
PFNGLDRAWBUFFERSATIPROC pglDrawBuffersATI=_Lazy_glDrawBuffersATI;
#endif 

/* GL_ATI_pixel_format_float */

#ifdef __GLEE_GL_ATI_pixel_format_float
#endif 

/* GL_ATI_texture_env_combine3 */

#ifdef __GLEE_GL_ATI_texture_env_combine3
#endif 

/* GL_ATI_texture_float */

#ifdef __GLEE_GL_ATI_texture_float
#endif 

/* GL_NV_float_buffer */

#ifdef __GLEE_GL_NV_float_buffer
#endif 

/* GL_NV_fragment_program */

#ifdef __GLEE_GL_NV_fragment_program
void __stdcall _Lazy_glProgramNamedParameter4fNV(GLuint id, GLsizei len, const GLubyte * name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)  {if (GLeeInit()) glProgramNamedParameter4fNV(id, len, name, x, y, z, w);}
void __stdcall _Lazy_glProgramNamedParameter4dNV(GLuint id, GLsizei len, const GLubyte * name, GLdouble x, GLdouble y, GLdouble z, GLdouble w)  {if (GLeeInit()) glProgramNamedParameter4dNV(id, len, name, x, y, z, w);}
void __stdcall _Lazy_glProgramNamedParameter4fvNV(GLuint id, GLsizei len, const GLubyte * name, const GLfloat * v)  {if (GLeeInit()) glProgramNamedParameter4fvNV(id, len, name, v);}
void __stdcall _Lazy_glProgramNamedParameter4dvNV(GLuint id, GLsizei len, const GLubyte * name, const GLdouble * v)  {if (GLeeInit()) glProgramNamedParameter4dvNV(id, len, name, v);}
void __stdcall _Lazy_glGetProgramNamedParameterfvNV(GLuint id, GLsizei len, const GLubyte * name, GLfloat * params)  {if (GLeeInit()) glGetProgramNamedParameterfvNV(id, len, name, params);}
void __stdcall _Lazy_glGetProgramNamedParameterdvNV(GLuint id, GLsizei len, const GLubyte * name, GLdouble * params)  {if (GLeeInit()) glGetProgramNamedParameterdvNV(id, len, name, params);}
PFNGLPROGRAMNAMEDPARAMETER4FNVPROC pglProgramNamedParameter4fNV=_Lazy_glProgramNamedParameter4fNV;
PFNGLPROGRAMNAMEDPARAMETER4DNVPROC pglProgramNamedParameter4dNV=_Lazy_glProgramNamedParameter4dNV;
PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC pglProgramNamedParameter4fvNV=_Lazy_glProgramNamedParameter4fvNV;
PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC pglProgramNamedParameter4dvNV=_Lazy_glProgramNamedParameter4dvNV;
PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC pglGetProgramNamedParameterfvNV=_Lazy_glGetProgramNamedParameterfvNV;
PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC pglGetProgramNamedParameterdvNV=_Lazy_glGetProgramNamedParameterdvNV;
#endif 

/* GL_NV_half_float */

#ifdef __GLEE_GL_NV_half_float
void __stdcall _Lazy_glVertex2hNV(GLhalfNV x, GLhalfNV y)                                 {if (GLeeInit()) glVertex2hNV(x, y);}
void __stdcall _Lazy_glVertex2hvNV(const GLhalfNV * v)                                    {if (GLeeInit()) glVertex2hvNV(v);}
void __stdcall _Lazy_glVertex3hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z)                     {if (GLeeInit()) glVertex3hNV(x, y, z);}
void __stdcall _Lazy_glVertex3hvNV(const GLhalfNV * v)                                    {if (GLeeInit()) glVertex3hvNV(v);}
void __stdcall _Lazy_glVertex4hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w)         {if (GLeeInit()) glVertex4hNV(x, y, z, w);}
void __stdcall _Lazy_glVertex4hvNV(const GLhalfNV * v)                                    {if (GLeeInit()) glVertex4hvNV(v);}
void __stdcall _Lazy_glNormal3hNV(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz)                  {if (GLeeInit()) glNormal3hNV(nx, ny, nz);}
void __stdcall _Lazy_glNormal3hvNV(const GLhalfNV * v)                                    {if (GLeeInit()) glNormal3hvNV(v);}
void __stdcall _Lazy_glColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue)             {if (GLeeInit()) glColor3hNV(red, green, blue);}
void __stdcall _Lazy_glColor3hvNV(const GLhalfNV * v)                                     {if (GLeeInit()) glColor3hvNV(v);}
void __stdcall _Lazy_glColor4hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha)  {if (GLeeInit()) glColor4hNV(red, green, blue, alpha);}
void __stdcall _Lazy_glColor4hvNV(const GLhalfNV * v)                                     {if (GLeeInit()) glColor4hvNV(v);}
void __stdcall _Lazy_glTexCoord1hNV(GLhalfNV s)                                           {if (GLeeInit()) glTexCoord1hNV(s);}
void __stdcall _Lazy_glTexCoord1hvNV(const GLhalfNV * v)                                  {if (GLeeInit()) glTexCoord1hvNV(v);}
void __stdcall _Lazy_glTexCoord2hNV(GLhalfNV s, GLhalfNV t)                               {if (GLeeInit()) glTexCoord2hNV(s, t);}
void __stdcall _Lazy_glTexCoord2hvNV(const GLhalfNV * v)                                  {if (GLeeInit()) glTexCoord2hvNV(v);}
void __stdcall _Lazy_glTexCoord3hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r)                   {if (GLeeInit()) glTexCoord3hNV(s, t, r);}
void __stdcall _Lazy_glTexCoord3hvNV(const GLhalfNV * v)                                  {if (GLeeInit()) glTexCoord3hvNV(v);}
void __stdcall _Lazy_glTexCoord4hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q)       {if (GLeeInit()) glTexCoord4hNV(s, t, r, q);}
void __stdcall _Lazy_glTexCoord4hvNV(const GLhalfNV * v)                                  {if (GLeeInit()) glTexCoord4hvNV(v);}
void __stdcall _Lazy_glMultiTexCoord1hNV(GLenum target, GLhalfNV s)                       {if (GLeeInit()) glMultiTexCoord1hNV(target, s);}
void __stdcall _Lazy_glMultiTexCoord1hvNV(GLenum target, const GLhalfNV * v)              {if (GLeeInit()) glMultiTexCoord1hvNV(target, v);}
void __stdcall _Lazy_glMultiTexCoord2hNV(GLenum target, GLhalfNV s, GLhalfNV t)           {if (GLeeInit()) glMultiTexCoord2hNV(target, s, t);}
void __stdcall _Lazy_glMultiTexCoord2hvNV(GLenum target, const GLhalfNV * v)              {if (GLeeInit()) glMultiTexCoord2hvNV(target, v);}
void __stdcall _Lazy_glMultiTexCoord3hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r)  {if (GLeeInit()) glMultiTexCoord3hNV(target, s, t, r);}
void __stdcall _Lazy_glMultiTexCoord3hvNV(GLenum target, const GLhalfNV * v)              {if (GLeeInit()) glMultiTexCoord3hvNV(target, v);}
void __stdcall _Lazy_glMultiTexCoord4hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q)  {if (GLeeInit()) glMultiTexCoord4hNV(target, s, t, r, q);}
void __stdcall _Lazy_glMultiTexCoord4hvNV(GLenum target, const GLhalfNV * v)              {if (GLeeInit()) glMultiTexCoord4hvNV(target, v);}
void __stdcall _Lazy_glFogCoordhNV(GLhalfNV fog)                                          {if (GLeeInit()) glFogCoordhNV(fog);}
void __stdcall _Lazy_glFogCoordhvNV(const GLhalfNV * fog)                                 {if (GLeeInit()) glFogCoordhvNV(fog);}
void __stdcall _Lazy_glSecondaryColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue)    {if (GLeeInit()) glSecondaryColor3hNV(red, green, blue);}
void __stdcall _Lazy_glSecondaryColor3hvNV(const GLhalfNV * v)                            {if (GLeeInit()) glSecondaryColor3hvNV(v);}
void __stdcall _Lazy_glVertexWeighthNV(GLhalfNV weight)                                   {if (GLeeInit()) glVertexWeighthNV(weight);}
void __stdcall _Lazy_glVertexWeighthvNV(const GLhalfNV * weight)                          {if (GLeeInit()) glVertexWeighthvNV(weight);}
void __stdcall _Lazy_glVertexAttrib1hNV(GLuint index, GLhalfNV x)                         {if (GLeeInit()) glVertexAttrib1hNV(index, x);}
void __stdcall _Lazy_glVertexAttrib1hvNV(GLuint index, const GLhalfNV * v)                {if (GLeeInit()) glVertexAttrib1hvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib2hNV(GLuint index, GLhalfNV x, GLhalfNV y)             {if (GLeeInit()) glVertexAttrib2hNV(index, x, y);}
void __stdcall _Lazy_glVertexAttrib2hvNV(GLuint index, const GLhalfNV * v)                {if (GLeeInit()) glVertexAttrib2hvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib3hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z)  {if (GLeeInit()) glVertexAttrib3hNV(index, x, y, z);}
void __stdcall _Lazy_glVertexAttrib3hvNV(GLuint index, const GLhalfNV * v)                {if (GLeeInit()) glVertexAttrib3hvNV(index, v);}
void __stdcall _Lazy_glVertexAttrib4hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w)  {if (GLeeInit()) glVertexAttrib4hNV(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttrib4hvNV(GLuint index, const GLhalfNV * v)                {if (GLeeInit()) glVertexAttrib4hvNV(index, v);}
void __stdcall _Lazy_glVertexAttribs1hvNV(GLuint index, GLsizei n, const GLhalfNV * v)    {if (GLeeInit()) glVertexAttribs1hvNV(index, n, v);}
void __stdcall _Lazy_glVertexAttribs2hvNV(GLuint index, GLsizei n, const GLhalfNV * v)    {if (GLeeInit()) glVertexAttribs2hvNV(index, n, v);}
void __stdcall _Lazy_glVertexAttribs3hvNV(GLuint index, GLsizei n, const GLhalfNV * v)    {if (GLeeInit()) glVertexAttribs3hvNV(index, n, v);}
void __stdcall _Lazy_glVertexAttribs4hvNV(GLuint index, GLsizei n, const GLhalfNV * v)    {if (GLeeInit()) glVertexAttribs4hvNV(index, n, v);}
PFNGLVERTEX2HNVPROC pglVertex2hNV=_Lazy_glVertex2hNV;
PFNGLVERTEX2HVNVPROC pglVertex2hvNV=_Lazy_glVertex2hvNV;
PFNGLVERTEX3HNVPROC pglVertex3hNV=_Lazy_glVertex3hNV;
PFNGLVERTEX3HVNVPROC pglVertex3hvNV=_Lazy_glVertex3hvNV;
PFNGLVERTEX4HNVPROC pglVertex4hNV=_Lazy_glVertex4hNV;
PFNGLVERTEX4HVNVPROC pglVertex4hvNV=_Lazy_glVertex4hvNV;
PFNGLNORMAL3HNVPROC pglNormal3hNV=_Lazy_glNormal3hNV;
PFNGLNORMAL3HVNVPROC pglNormal3hvNV=_Lazy_glNormal3hvNV;
PFNGLCOLOR3HNVPROC pglColor3hNV=_Lazy_glColor3hNV;
PFNGLCOLOR3HVNVPROC pglColor3hvNV=_Lazy_glColor3hvNV;
PFNGLCOLOR4HNVPROC pglColor4hNV=_Lazy_glColor4hNV;
PFNGLCOLOR4HVNVPROC pglColor4hvNV=_Lazy_glColor4hvNV;
PFNGLTEXCOORD1HNVPROC pglTexCoord1hNV=_Lazy_glTexCoord1hNV;
PFNGLTEXCOORD1HVNVPROC pglTexCoord1hvNV=_Lazy_glTexCoord1hvNV;
PFNGLTEXCOORD2HNVPROC pglTexCoord2hNV=_Lazy_glTexCoord2hNV;
PFNGLTEXCOORD2HVNVPROC pglTexCoord2hvNV=_Lazy_glTexCoord2hvNV;
PFNGLTEXCOORD3HNVPROC pglTexCoord3hNV=_Lazy_glTexCoord3hNV;
PFNGLTEXCOORD3HVNVPROC pglTexCoord3hvNV=_Lazy_glTexCoord3hvNV;
PFNGLTEXCOORD4HNVPROC pglTexCoord4hNV=_Lazy_glTexCoord4hNV;
PFNGLTEXCOORD4HVNVPROC pglTexCoord4hvNV=_Lazy_glTexCoord4hvNV;
PFNGLMULTITEXCOORD1HNVPROC pglMultiTexCoord1hNV=_Lazy_glMultiTexCoord1hNV;
PFNGLMULTITEXCOORD1HVNVPROC pglMultiTexCoord1hvNV=_Lazy_glMultiTexCoord1hvNV;
PFNGLMULTITEXCOORD2HNVPROC pglMultiTexCoord2hNV=_Lazy_glMultiTexCoord2hNV;
PFNGLMULTITEXCOORD2HVNVPROC pglMultiTexCoord2hvNV=_Lazy_glMultiTexCoord2hvNV;
PFNGLMULTITEXCOORD3HNVPROC pglMultiTexCoord3hNV=_Lazy_glMultiTexCoord3hNV;
PFNGLMULTITEXCOORD3HVNVPROC pglMultiTexCoord3hvNV=_Lazy_glMultiTexCoord3hvNV;
PFNGLMULTITEXCOORD4HNVPROC pglMultiTexCoord4hNV=_Lazy_glMultiTexCoord4hNV;
PFNGLMULTITEXCOORD4HVNVPROC pglMultiTexCoord4hvNV=_Lazy_glMultiTexCoord4hvNV;
PFNGLFOGCOORDHNVPROC pglFogCoordhNV=_Lazy_glFogCoordhNV;
PFNGLFOGCOORDHVNVPROC pglFogCoordhvNV=_Lazy_glFogCoordhvNV;
PFNGLSECONDARYCOLOR3HNVPROC pglSecondaryColor3hNV=_Lazy_glSecondaryColor3hNV;
PFNGLSECONDARYCOLOR3HVNVPROC pglSecondaryColor3hvNV=_Lazy_glSecondaryColor3hvNV;
PFNGLVERTEXWEIGHTHNVPROC pglVertexWeighthNV=_Lazy_glVertexWeighthNV;
PFNGLVERTEXWEIGHTHVNVPROC pglVertexWeighthvNV=_Lazy_glVertexWeighthvNV;
PFNGLVERTEXATTRIB1HNVPROC pglVertexAttrib1hNV=_Lazy_glVertexAttrib1hNV;
PFNGLVERTEXATTRIB1HVNVPROC pglVertexAttrib1hvNV=_Lazy_glVertexAttrib1hvNV;
PFNGLVERTEXATTRIB2HNVPROC pglVertexAttrib2hNV=_Lazy_glVertexAttrib2hNV;
PFNGLVERTEXATTRIB2HVNVPROC pglVertexAttrib2hvNV=_Lazy_glVertexAttrib2hvNV;
PFNGLVERTEXATTRIB3HNVPROC pglVertexAttrib3hNV=_Lazy_glVertexAttrib3hNV;
PFNGLVERTEXATTRIB3HVNVPROC pglVertexAttrib3hvNV=_Lazy_glVertexAttrib3hvNV;
PFNGLVERTEXATTRIB4HNVPROC pglVertexAttrib4hNV=_Lazy_glVertexAttrib4hNV;
PFNGLVERTEXATTRIB4HVNVPROC pglVertexAttrib4hvNV=_Lazy_glVertexAttrib4hvNV;
PFNGLVERTEXATTRIBS1HVNVPROC pglVertexAttribs1hvNV=_Lazy_glVertexAttribs1hvNV;
PFNGLVERTEXATTRIBS2HVNVPROC pglVertexAttribs2hvNV=_Lazy_glVertexAttribs2hvNV;
PFNGLVERTEXATTRIBS3HVNVPROC pglVertexAttribs3hvNV=_Lazy_glVertexAttribs3hvNV;
PFNGLVERTEXATTRIBS4HVNVPROC pglVertexAttribs4hvNV=_Lazy_glVertexAttribs4hvNV;
#endif 

/* GL_NV_pixel_data_range */

#ifdef __GLEE_GL_NV_pixel_data_range
void __stdcall _Lazy_glPixelDataRangeNV(GLenum target, GLsizei length, GLvoid * pointer)  {if (GLeeInit()) glPixelDataRangeNV(target, length, pointer);}
void __stdcall _Lazy_glFlushPixelDataRangeNV(GLenum target)                               {if (GLeeInit()) glFlushPixelDataRangeNV(target);}
PFNGLPIXELDATARANGENVPROC pglPixelDataRangeNV=_Lazy_glPixelDataRangeNV;
PFNGLFLUSHPIXELDATARANGENVPROC pglFlushPixelDataRangeNV=_Lazy_glFlushPixelDataRangeNV;
#endif 

/* GL_NV_primitive_restart */

#ifdef __GLEE_GL_NV_primitive_restart
void __stdcall _Lazy_glPrimitiveRestartNV(void)                                           {if (GLeeInit()) glPrimitiveRestartNV();}
void __stdcall _Lazy_glPrimitiveRestartIndexNV(GLuint index)                              {if (GLeeInit()) glPrimitiveRestartIndexNV(index);}
PFNGLPRIMITIVERESTARTNVPROC pglPrimitiveRestartNV=_Lazy_glPrimitiveRestartNV;
PFNGLPRIMITIVERESTARTINDEXNVPROC pglPrimitiveRestartIndexNV=_Lazy_glPrimitiveRestartIndexNV;
#endif 

/* GL_NV_texture_expand_normal */

#ifdef __GLEE_GL_NV_texture_expand_normal
#endif 

/* GL_NV_vertex_program2 */

#ifdef __GLEE_GL_NV_vertex_program2
#endif 

/* GL_ATI_map_object_buffer */

#ifdef __GLEE_GL_ATI_map_object_buffer
GLvoid* __stdcall _Lazy_glMapObjectBufferATI(GLuint buffer)                               {if (GLeeInit()) return glMapObjectBufferATI(buffer); return (GLvoid*)0;}
void __stdcall _Lazy_glUnmapObjectBufferATI(GLuint buffer)                                {if (GLeeInit()) glUnmapObjectBufferATI(buffer);}
PFNGLMAPOBJECTBUFFERATIPROC pglMapObjectBufferATI=_Lazy_glMapObjectBufferATI;
PFNGLUNMAPOBJECTBUFFERATIPROC pglUnmapObjectBufferATI=_Lazy_glUnmapObjectBufferATI;
#endif 

/* GL_ATI_separate_stencil */

#ifdef __GLEE_GL_ATI_separate_stencil
void __stdcall _Lazy_glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)  {if (GLeeInit()) glStencilOpSeparateATI(face, sfail, dpfail, dppass);}
void __stdcall _Lazy_glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask)  {if (GLeeInit()) glStencilFuncSeparateATI(frontfunc, backfunc, ref, mask);}
PFNGLSTENCILOPSEPARATEATIPROC pglStencilOpSeparateATI=_Lazy_glStencilOpSeparateATI;
PFNGLSTENCILFUNCSEPARATEATIPROC pglStencilFuncSeparateATI=_Lazy_glStencilFuncSeparateATI;
#endif 

/* GL_ATI_vertex_attrib_array_object */

#ifdef __GLEE_GL_ATI_vertex_attrib_array_object
void __stdcall _Lazy_glVertexAttribArrayObjectATI(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset)  {if (GLeeInit()) glVertexAttribArrayObjectATI(index, size, type, normalized, stride, buffer, offset);}
void __stdcall _Lazy_glGetVertexAttribArrayObjectfvATI(GLuint index, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetVertexAttribArrayObjectfvATI(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribArrayObjectivATI(GLuint index, GLenum pname, GLint * params)  {if (GLeeInit()) glGetVertexAttribArrayObjectivATI(index, pname, params);}
PFNGLVERTEXATTRIBARRAYOBJECTATIPROC pglVertexAttribArrayObjectATI=_Lazy_glVertexAttribArrayObjectATI;
PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC pglGetVertexAttribArrayObjectfvATI=_Lazy_glGetVertexAttribArrayObjectfvATI;
PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC pglGetVertexAttribArrayObjectivATI=_Lazy_glGetVertexAttribArrayObjectivATI;
#endif 

/* GL_OES_read_format */

#ifdef __GLEE_GL_OES_read_format
#endif 

/* GL_EXT_depth_bounds_test */

#ifdef __GLEE_GL_EXT_depth_bounds_test
void __stdcall _Lazy_glDepthBoundsEXT(GLclampd zmin, GLclampd zmax)                       {if (GLeeInit()) glDepthBoundsEXT(zmin, zmax);}
PFNGLDEPTHBOUNDSEXTPROC pglDepthBoundsEXT=_Lazy_glDepthBoundsEXT;
#endif 

/* GL_EXT_texture_mirror_clamp */

#ifdef __GLEE_GL_EXT_texture_mirror_clamp
#endif 

/* GL_EXT_blend_equation_separate */

#ifdef __GLEE_GL_EXT_blend_equation_separate
void __stdcall _Lazy_glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha)         {if (GLeeInit()) glBlendEquationSeparateEXT(modeRGB, modeAlpha);}
PFNGLBLENDEQUATIONSEPARATEEXTPROC pglBlendEquationSeparateEXT=_Lazy_glBlendEquationSeparateEXT;
#endif 

/* GL_MESA_pack_invert */

#ifdef __GLEE_GL_MESA_pack_invert
#endif 

/* GL_MESA_ycbcr_texture */

#ifdef __GLEE_GL_MESA_ycbcr_texture
#endif 

/* GL_EXT_pixel_buffer_object */

#ifdef __GLEE_GL_EXT_pixel_buffer_object
#endif 

/* GL_NV_fragment_program_option */

#ifdef __GLEE_GL_NV_fragment_program_option
#endif 

/* GL_NV_fragment_program2 */

#ifdef __GLEE_GL_NV_fragment_program2
#endif 

/* GL_NV_vertex_program2_option */

#ifdef __GLEE_GL_NV_vertex_program2_option
#endif 

/* GL_NV_vertex_program3 */

#ifdef __GLEE_GL_NV_vertex_program3
#endif 

/* GL_EXT_framebuffer_object */

#ifdef __GLEE_GL_EXT_framebuffer_object
GLboolean __stdcall _Lazy_glIsRenderbufferEXT(GLuint renderbuffer)                        {if (GLeeInit()) return glIsRenderbufferEXT(renderbuffer); return (GLboolean)0;}
void __stdcall _Lazy_glBindRenderbufferEXT(GLenum target, GLuint renderbuffer)            {if (GLeeInit()) glBindRenderbufferEXT(target, renderbuffer);}
void __stdcall _Lazy_glDeleteRenderbuffersEXT(GLsizei n, const GLuint * renderbuffers)    {if (GLeeInit()) glDeleteRenderbuffersEXT(n, renderbuffers);}
void __stdcall _Lazy_glGenRenderbuffersEXT(GLsizei n, GLuint * renderbuffers)             {if (GLeeInit()) glGenRenderbuffersEXT(n, renderbuffers);}
void __stdcall _Lazy_glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)  {if (GLeeInit()) glRenderbufferStorageEXT(target, internalformat, width, height);}
void __stdcall _Lazy_glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetRenderbufferParameterivEXT(target, pname, params);}
GLboolean __stdcall _Lazy_glIsFramebufferEXT(GLuint framebuffer)                          {if (GLeeInit()) return glIsFramebufferEXT(framebuffer); return (GLboolean)0;}
void __stdcall _Lazy_glBindFramebufferEXT(GLenum target, GLuint framebuffer)              {if (GLeeInit()) glBindFramebufferEXT(target, framebuffer);}
void __stdcall _Lazy_glDeleteFramebuffersEXT(GLsizei n, const GLuint * framebuffers)      {if (GLeeInit()) glDeleteFramebuffersEXT(n, framebuffers);}
void __stdcall _Lazy_glGenFramebuffersEXT(GLsizei n, GLuint * framebuffers)               {if (GLeeInit()) glGenFramebuffersEXT(n, framebuffers);}
GLenum __stdcall _Lazy_glCheckFramebufferStatusEXT(GLenum target)                         {if (GLeeInit()) return glCheckFramebufferStatusEXT(target); return (GLenum)0;}
void __stdcall _Lazy_glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)  {if (GLeeInit()) glFramebufferTexture1DEXT(target, attachment, textarget, texture, level);}
void __stdcall _Lazy_glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)  {if (GLeeInit()) glFramebufferTexture2DEXT(target, attachment, textarget, texture, level);}
void __stdcall _Lazy_glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)  {if (GLeeInit()) glFramebufferTexture3DEXT(target, attachment, textarget, texture, level, zoffset);}
void __stdcall _Lazy_glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)  {if (GLeeInit()) glFramebufferRenderbufferEXT(target, attachment, renderbuffertarget, renderbuffer);}
void __stdcall _Lazy_glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint * params)  {if (GLeeInit()) glGetFramebufferAttachmentParameterivEXT(target, attachment, pname, params);}
void __stdcall _Lazy_glGenerateMipmapEXT(GLenum target)                                   {if (GLeeInit()) glGenerateMipmapEXT(target);}
PFNGLISRENDERBUFFEREXTPROC pglIsRenderbufferEXT=_Lazy_glIsRenderbufferEXT;
PFNGLBINDRENDERBUFFEREXTPROC pglBindRenderbufferEXT=_Lazy_glBindRenderbufferEXT;
PFNGLDELETERENDERBUFFERSEXTPROC pglDeleteRenderbuffersEXT=_Lazy_glDeleteRenderbuffersEXT;
PFNGLGENRENDERBUFFERSEXTPROC pglGenRenderbuffersEXT=_Lazy_glGenRenderbuffersEXT;
PFNGLRENDERBUFFERSTORAGEEXTPROC pglRenderbufferStorageEXT=_Lazy_glRenderbufferStorageEXT;
PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC pglGetRenderbufferParameterivEXT=_Lazy_glGetRenderbufferParameterivEXT;
PFNGLISFRAMEBUFFEREXTPROC pglIsFramebufferEXT=_Lazy_glIsFramebufferEXT;
PFNGLBINDFRAMEBUFFEREXTPROC pglBindFramebufferEXT=_Lazy_glBindFramebufferEXT;
PFNGLDELETEFRAMEBUFFERSEXTPROC pglDeleteFramebuffersEXT=_Lazy_glDeleteFramebuffersEXT;
PFNGLGENFRAMEBUFFERSEXTPROC pglGenFramebuffersEXT=_Lazy_glGenFramebuffersEXT;
PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC pglCheckFramebufferStatusEXT=_Lazy_glCheckFramebufferStatusEXT;
PFNGLFRAMEBUFFERTEXTURE1DEXTPROC pglFramebufferTexture1DEXT=_Lazy_glFramebufferTexture1DEXT;
PFNGLFRAMEBUFFERTEXTURE2DEXTPROC pglFramebufferTexture2DEXT=_Lazy_glFramebufferTexture2DEXT;
PFNGLFRAMEBUFFERTEXTURE3DEXTPROC pglFramebufferTexture3DEXT=_Lazy_glFramebufferTexture3DEXT;
PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC pglFramebufferRenderbufferEXT=_Lazy_glFramebufferRenderbufferEXT;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC pglGetFramebufferAttachmentParameterivEXT=_Lazy_glGetFramebufferAttachmentParameterivEXT;
PFNGLGENERATEMIPMAPEXTPROC pglGenerateMipmapEXT=_Lazy_glGenerateMipmapEXT;
#endif 

/* GL_GREMEDY_string_marker */

#ifdef __GLEE_GL_GREMEDY_string_marker
void __stdcall _Lazy_glStringMarkerGREMEDY(GLsizei len, const GLvoid * string)            {if (GLeeInit()) glStringMarkerGREMEDY(len, string);}
PFNGLSTRINGMARKERGREMEDYPROC pglStringMarkerGREMEDY=_Lazy_glStringMarkerGREMEDY;
#endif 

/* GL_EXT_Cg_shader */

#ifdef __GLEE_GL_EXT_Cg_shader
#endif 

/* GL_EXT_timer_query */

#ifdef __GLEE_GL_EXT_timer_query
void __stdcall _Lazy_glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64EXT * params)  {if (GLeeInit()) glGetQueryObjecti64vEXT(id, pname, params);}
void __stdcall _Lazy_glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64EXT * params)  {if (GLeeInit()) glGetQueryObjectui64vEXT(id, pname, params);}
PFNGLGETQUERYOBJECTI64VEXTPROC pglGetQueryObjecti64vEXT=_Lazy_glGetQueryObjecti64vEXT;
PFNGLGETQUERYOBJECTUI64VEXTPROC pglGetQueryObjectui64vEXT=_Lazy_glGetQueryObjectui64vEXT;
#endif 

/* GL_EXT_texture_buffer_object */

#ifdef __GLEE_GL_EXT_texture_buffer_object
void __stdcall _Lazy_glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer)  {if (GLeeInit()) glTexBufferEXT(target, internalformat, buffer);}
PFNGLTEXBUFFEREXTPROC pglTexBufferEXT=_Lazy_glTexBufferEXT;
#endif 

/* GL_EXT_gpu_shader4 */

#ifdef __GLEE_GL_EXT_gpu_shader4
void __stdcall _Lazy_glGetUniformuivEXT(GLuint program, GLint location, GLuint * params)  {if (GLeeInit()) glGetUniformuivEXT(program, location, params);}
void __stdcall _Lazy_glBindFragDataLocationEXT(GLuint program, GLuint color, const GLchar * name)  {if (GLeeInit()) glBindFragDataLocationEXT(program, color, name);}
GLint __stdcall _Lazy_glGetFragDataLocationEXT(GLuint program, const GLchar * name)       {if (GLeeInit()) return glGetFragDataLocationEXT(program, name); return (GLint)0;}
void __stdcall _Lazy_glUniform1uiEXT(GLint location, GLuint v0)                           {if (GLeeInit()) glUniform1uiEXT(location, v0);}
void __stdcall _Lazy_glUniform2uiEXT(GLint location, GLuint v0, GLuint v1)                {if (GLeeInit()) glUniform2uiEXT(location, v0, v1);}
void __stdcall _Lazy_glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2)     {if (GLeeInit()) glUniform3uiEXT(location, v0, v1, v2);}
void __stdcall _Lazy_glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)  {if (GLeeInit()) glUniform4uiEXT(location, v0, v1, v2, v3);}
void __stdcall _Lazy_glUniform1uivEXT(GLint location, GLsizei count, const GLuint * value)  {if (GLeeInit()) glUniform1uivEXT(location, count, value);}
void __stdcall _Lazy_glUniform2uivEXT(GLint location, GLsizei count, const GLuint * value)  {if (GLeeInit()) glUniform2uivEXT(location, count, value);}
void __stdcall _Lazy_glUniform3uivEXT(GLint location, GLsizei count, const GLuint * value)  {if (GLeeInit()) glUniform3uivEXT(location, count, value);}
void __stdcall _Lazy_glUniform4uivEXT(GLint location, GLsizei count, const GLuint * value)  {if (GLeeInit()) glUniform4uivEXT(location, count, value);}
void __stdcall _Lazy_glVertexAttribI1iEXT(GLuint index, GLint x)                          {if (GLeeInit()) glVertexAttribI1iEXT(index, x);}
void __stdcall _Lazy_glVertexAttribI2iEXT(GLuint index, GLint x, GLint y)                 {if (GLeeInit()) glVertexAttribI2iEXT(index, x, y);}
void __stdcall _Lazy_glVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z)        {if (GLeeInit()) glVertexAttribI3iEXT(index, x, y, z);}
void __stdcall _Lazy_glVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w)  {if (GLeeInit()) glVertexAttribI4iEXT(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttribI1uiEXT(GLuint index, GLuint x)                        {if (GLeeInit()) glVertexAttribI1uiEXT(index, x);}
void __stdcall _Lazy_glVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y)              {if (GLeeInit()) glVertexAttribI2uiEXT(index, x, y);}
void __stdcall _Lazy_glVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z)    {if (GLeeInit()) glVertexAttribI3uiEXT(index, x, y, z);}
void __stdcall _Lazy_glVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)  {if (GLeeInit()) glVertexAttribI4uiEXT(index, x, y, z, w);}
void __stdcall _Lazy_glVertexAttribI1ivEXT(GLuint index, const GLint * v)                 {if (GLeeInit()) glVertexAttribI1ivEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI2ivEXT(GLuint index, const GLint * v)                 {if (GLeeInit()) glVertexAttribI2ivEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI3ivEXT(GLuint index, const GLint * v)                 {if (GLeeInit()) glVertexAttribI3ivEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI4ivEXT(GLuint index, const GLint * v)                 {if (GLeeInit()) glVertexAttribI4ivEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI1uivEXT(GLuint index, const GLuint * v)               {if (GLeeInit()) glVertexAttribI1uivEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI2uivEXT(GLuint index, const GLuint * v)               {if (GLeeInit()) glVertexAttribI2uivEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI3uivEXT(GLuint index, const GLuint * v)               {if (GLeeInit()) glVertexAttribI3uivEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI4uivEXT(GLuint index, const GLuint * v)               {if (GLeeInit()) glVertexAttribI4uivEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI4bvEXT(GLuint index, const GLbyte * v)                {if (GLeeInit()) glVertexAttribI4bvEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI4svEXT(GLuint index, const GLshort * v)               {if (GLeeInit()) glVertexAttribI4svEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI4ubvEXT(GLuint index, const GLubyte * v)              {if (GLeeInit()) glVertexAttribI4ubvEXT(index, v);}
void __stdcall _Lazy_glVertexAttribI4usvEXT(GLuint index, const GLushort * v)             {if (GLeeInit()) glVertexAttribI4usvEXT(index, v);}
void __stdcall _Lazy_glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)  {if (GLeeInit()) glVertexAttribIPointerEXT(index, size, type, stride, pointer);}
void __stdcall _Lazy_glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint * params)  {if (GLeeInit()) glGetVertexAttribIivEXT(index, pname, params);}
void __stdcall _Lazy_glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint * params)  {if (GLeeInit()) glGetVertexAttribIuivEXT(index, pname, params);}
PFNGLGETUNIFORMUIVEXTPROC pglGetUniformuivEXT=_Lazy_glGetUniformuivEXT;
PFNGLBINDFRAGDATALOCATIONEXTPROC pglBindFragDataLocationEXT=_Lazy_glBindFragDataLocationEXT;
PFNGLGETFRAGDATALOCATIONEXTPROC pglGetFragDataLocationEXT=_Lazy_glGetFragDataLocationEXT;
PFNGLUNIFORM1UIEXTPROC pglUniform1uiEXT=_Lazy_glUniform1uiEXT;
PFNGLUNIFORM2UIEXTPROC pglUniform2uiEXT=_Lazy_glUniform2uiEXT;
PFNGLUNIFORM3UIEXTPROC pglUniform3uiEXT=_Lazy_glUniform3uiEXT;
PFNGLUNIFORM4UIEXTPROC pglUniform4uiEXT=_Lazy_glUniform4uiEXT;
PFNGLUNIFORM1UIVEXTPROC pglUniform1uivEXT=_Lazy_glUniform1uivEXT;
PFNGLUNIFORM2UIVEXTPROC pglUniform2uivEXT=_Lazy_glUniform2uivEXT;
PFNGLUNIFORM3UIVEXTPROC pglUniform3uivEXT=_Lazy_glUniform3uivEXT;
PFNGLUNIFORM4UIVEXTPROC pglUniform4uivEXT=_Lazy_glUniform4uivEXT;
PFNGLVERTEXATTRIBI1IEXTPROC pglVertexAttribI1iEXT=_Lazy_glVertexAttribI1iEXT;
PFNGLVERTEXATTRIBI2IEXTPROC pglVertexAttribI2iEXT=_Lazy_glVertexAttribI2iEXT;
PFNGLVERTEXATTRIBI3IEXTPROC pglVertexAttribI3iEXT=_Lazy_glVertexAttribI3iEXT;
PFNGLVERTEXATTRIBI4IEXTPROC pglVertexAttribI4iEXT=_Lazy_glVertexAttribI4iEXT;
PFNGLVERTEXATTRIBI1UIEXTPROC pglVertexAttribI1uiEXT=_Lazy_glVertexAttribI1uiEXT;
PFNGLVERTEXATTRIBI2UIEXTPROC pglVertexAttribI2uiEXT=_Lazy_glVertexAttribI2uiEXT;
PFNGLVERTEXATTRIBI3UIEXTPROC pglVertexAttribI3uiEXT=_Lazy_glVertexAttribI3uiEXT;
PFNGLVERTEXATTRIBI4UIEXTPROC pglVertexAttribI4uiEXT=_Lazy_glVertexAttribI4uiEXT;
PFNGLVERTEXATTRIBI1IVEXTPROC pglVertexAttribI1ivEXT=_Lazy_glVertexAttribI1ivEXT;
PFNGLVERTEXATTRIBI2IVEXTPROC pglVertexAttribI2ivEXT=_Lazy_glVertexAttribI2ivEXT;
PFNGLVERTEXATTRIBI3IVEXTPROC pglVertexAttribI3ivEXT=_Lazy_glVertexAttribI3ivEXT;
PFNGLVERTEXATTRIBI4IVEXTPROC pglVertexAttribI4ivEXT=_Lazy_glVertexAttribI4ivEXT;
PFNGLVERTEXATTRIBI1UIVEXTPROC pglVertexAttribI1uivEXT=_Lazy_glVertexAttribI1uivEXT;
PFNGLVERTEXATTRIBI2UIVEXTPROC pglVertexAttribI2uivEXT=_Lazy_glVertexAttribI2uivEXT;
PFNGLVERTEXATTRIBI3UIVEXTPROC pglVertexAttribI3uivEXT=_Lazy_glVertexAttribI3uivEXT;
PFNGLVERTEXATTRIBI4UIVEXTPROC pglVertexAttribI4uivEXT=_Lazy_glVertexAttribI4uivEXT;
PFNGLVERTEXATTRIBI4BVEXTPROC pglVertexAttribI4bvEXT=_Lazy_glVertexAttribI4bvEXT;
PFNGLVERTEXATTRIBI4SVEXTPROC pglVertexAttribI4svEXT=_Lazy_glVertexAttribI4svEXT;
PFNGLVERTEXATTRIBI4UBVEXTPROC pglVertexAttribI4ubvEXT=_Lazy_glVertexAttribI4ubvEXT;
PFNGLVERTEXATTRIBI4USVEXTPROC pglVertexAttribI4usvEXT=_Lazy_glVertexAttribI4usvEXT;
PFNGLVERTEXATTRIBIPOINTEREXTPROC pglVertexAttribIPointerEXT=_Lazy_glVertexAttribIPointerEXT;
PFNGLGETVERTEXATTRIBIIVEXTPROC pglGetVertexAttribIivEXT=_Lazy_glGetVertexAttribIivEXT;
PFNGLGETVERTEXATTRIBIUIVEXTPROC pglGetVertexAttribIuivEXT=_Lazy_glGetVertexAttribIuivEXT;
#endif 

/* GL_EXT_geometry_shader4 */

#ifdef __GLEE_GL_EXT_geometry_shader4
void __stdcall _Lazy_glProgramParameteriEXT(GLuint program, GLenum pname, GLint value)    {if (GLeeInit()) glProgramParameteriEXT(program, pname, value);}
void __stdcall _Lazy_glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level)  {if (GLeeInit()) glFramebufferTextureEXT(target, attachment, texture, level);}
void __stdcall _Lazy_glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)  {if (GLeeInit()) glFramebufferTextureLayerEXT(target, attachment, texture, level, layer);}
void __stdcall _Lazy_glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face)  {if (GLeeInit()) glFramebufferTextureFaceEXT(target, attachment, texture, level, face);}
PFNGLPROGRAMPARAMETERIEXTPROC pglProgramParameteriEXT=_Lazy_glProgramParameteriEXT;
PFNGLFRAMEBUFFERTEXTUREEXTPROC pglFramebufferTextureEXT=_Lazy_glFramebufferTextureEXT;
PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC pglFramebufferTextureLayerEXT=_Lazy_glFramebufferTextureLayerEXT;
PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC pglFramebufferTextureFaceEXT=_Lazy_glFramebufferTextureFaceEXT;
#endif 

/* GL_EXT_bindable_uniform */

#ifdef __GLEE_GL_EXT_bindable_uniform
void __stdcall _Lazy_glUniformBufferEXT(GLuint program, GLint location, GLuint buffer)    {if (GLeeInit()) glUniformBufferEXT(program, location, buffer);}
GLint __stdcall _Lazy_glGetUniformBufferSizeEXT(GLuint program, GLint location)           {if (GLeeInit()) return glGetUniformBufferSizeEXT(program, location); return (GLint)0;}
GLintptr __stdcall _Lazy_glGetUniformOffsetEXT(GLuint program, GLint location)            {if (GLeeInit()) return glGetUniformOffsetEXT(program, location); return (GLintptr)0;}
PFNGLUNIFORMBUFFEREXTPROC pglUniformBufferEXT=_Lazy_glUniformBufferEXT;
PFNGLGETUNIFORMBUFFERSIZEEXTPROC pglGetUniformBufferSizeEXT=_Lazy_glGetUniformBufferSizeEXT;
PFNGLGETUNIFORMOFFSETEXTPROC pglGetUniformOffsetEXT=_Lazy_glGetUniformOffsetEXT;
#endif 

/* GL_EXT_framebuffer_sRGB */

#ifdef __GLEE_GL_EXT_framebuffer_sRGB
#endif 

/* GL_EXT_texture_shared_exponent */

#ifdef __GLEE_GL_EXT_texture_shared_exponent
#endif 

/* GL_EXT_packed_float */

#ifdef __GLEE_GL_EXT_packed_float
#endif 

/* GL_EXT_texture_array */

#ifdef __GLEE_GL_EXT_texture_array
#endif 

/* GL_EXT_texture_integer */

#ifdef __GLEE_GL_EXT_texture_integer
void __stdcall _Lazy_glTexParameterIivEXT(GLenum target, GLenum pname, const GLint * params)  {if (GLeeInit()) glTexParameterIivEXT(target, pname, params);}
void __stdcall _Lazy_glTexParameterIuivEXT(GLenum target, GLenum pname, const GLuint * params)  {if (GLeeInit()) glTexParameterIuivEXT(target, pname, params);}
void __stdcall _Lazy_glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint * params)  {if (GLeeInit()) glGetTexParameterIivEXT(target, pname, params);}
void __stdcall _Lazy_glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint * params)  {if (GLeeInit()) glGetTexParameterIuivEXT(target, pname, params);}
void __stdcall _Lazy_glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha)   {if (GLeeInit()) glClearColorIiEXT(red, green, blue, alpha);}
void __stdcall _Lazy_glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha)  {if (GLeeInit()) glClearColorIuiEXT(red, green, blue, alpha);}
PFNGLTEXPARAMETERIIVEXTPROC pglTexParameterIivEXT=_Lazy_glTexParameterIivEXT;
PFNGLTEXPARAMETERIUIVEXTPROC pglTexParameterIuivEXT=_Lazy_glTexParameterIuivEXT;
PFNGLGETTEXPARAMETERIIVEXTPROC pglGetTexParameterIivEXT=_Lazy_glGetTexParameterIivEXT;
PFNGLGETTEXPARAMETERIUIVEXTPROC pglGetTexParameterIuivEXT=_Lazy_glGetTexParameterIuivEXT;
PFNGLCLEARCOLORIIEXTPROC pglClearColorIiEXT=_Lazy_glClearColorIiEXT;
PFNGLCLEARCOLORIUIEXTPROC pglClearColorIuiEXT=_Lazy_glClearColorIuiEXT;
#endif 

/* GL_NV_depth_buffer_float */

#ifdef __GLEE_GL_NV_depth_buffer_float
void __stdcall _Lazy_glDepthRangedNV(GLdouble zNear, GLdouble zFar)                       {if (GLeeInit()) glDepthRangedNV(zNear, zFar);}
void __stdcall _Lazy_glClearDepthdNV(GLdouble depth)                                      {if (GLeeInit()) glClearDepthdNV(depth);}
void __stdcall _Lazy_glDepthBoundsdNV(GLdouble zmin, GLdouble zmax)                       {if (GLeeInit()) glDepthBoundsdNV(zmin, zmax);}
PFNGLDEPTHRANGEDNVPROC pglDepthRangedNV=_Lazy_glDepthRangedNV;
PFNGLCLEARDEPTHDNVPROC pglClearDepthdNV=_Lazy_glClearDepthdNV;
PFNGLDEPTHBOUNDSDNVPROC pglDepthBoundsdNV=_Lazy_glDepthBoundsdNV;
#endif 

/* GL_EXT_texture_compression_latc */

#ifdef __GLEE_GL_EXT_texture_compression_latc
#endif 

/* GL_NV_transform_feedback */

#ifdef __GLEE_GL_NV_transform_feedback
void __stdcall _Lazy_glBeginTransformFeedbackNV(GLenum primitiveMode)                     {if (GLeeInit()) glBeginTransformFeedbackNV(primitiveMode);}
void __stdcall _Lazy_glEndTransformFeedbackNV(void)                                       {if (GLeeInit()) glEndTransformFeedbackNV();}
void __stdcall _Lazy_glTransformFeedbackAttribsNV(GLuint count, const GLint * attribs, GLenum bufferMode)  {if (GLeeInit()) glTransformFeedbackAttribsNV(count, attribs, bufferMode);}
void __stdcall _Lazy_glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)  {if (GLeeInit()) glBindBufferRangeNV(target, index, buffer, offset, size);}
void __stdcall _Lazy_glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset)  {if (GLeeInit()) glBindBufferOffsetNV(target, index, buffer, offset);}
void __stdcall _Lazy_glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer)       {if (GLeeInit()) glBindBufferBaseNV(target, index, buffer);}
void __stdcall _Lazy_glTransformFeedbackVaryingsNV(GLuint program, GLsizei count, const GLint * locations, GLenum bufferMode)  {if (GLeeInit()) glTransformFeedbackVaryingsNV(program, count, locations, bufferMode);}
void __stdcall _Lazy_glActiveVaryingNV(GLuint program, const GLchar * name)               {if (GLeeInit()) glActiveVaryingNV(program, name);}
GLint __stdcall _Lazy_glGetVaryingLocationNV(GLuint program, const GLchar * name)         {if (GLeeInit()) return glGetVaryingLocationNV(program, name); return (GLint)0;}
void __stdcall _Lazy_glGetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name)  {if (GLeeInit()) glGetActiveVaryingNV(program, index, bufSize, length, size, type, name);}
void __stdcall _Lazy_glGetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint * location)  {if (GLeeInit()) glGetTransformFeedbackVaryingNV(program, index, location);}
PFNGLBEGINTRANSFORMFEEDBACKNVPROC pglBeginTransformFeedbackNV=_Lazy_glBeginTransformFeedbackNV;
PFNGLENDTRANSFORMFEEDBACKNVPROC pglEndTransformFeedbackNV=_Lazy_glEndTransformFeedbackNV;
PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC pglTransformFeedbackAttribsNV=_Lazy_glTransformFeedbackAttribsNV;
PFNGLBINDBUFFERRANGENVPROC pglBindBufferRangeNV=_Lazy_glBindBufferRangeNV;
PFNGLBINDBUFFEROFFSETNVPROC pglBindBufferOffsetNV=_Lazy_glBindBufferOffsetNV;
PFNGLBINDBUFFERBASENVPROC pglBindBufferBaseNV=_Lazy_glBindBufferBaseNV;
PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC pglTransformFeedbackVaryingsNV=_Lazy_glTransformFeedbackVaryingsNV;
PFNGLACTIVEVARYINGNVPROC pglActiveVaryingNV=_Lazy_glActiveVaryingNV;
PFNGLGETVARYINGLOCATIONNVPROC pglGetVaryingLocationNV=_Lazy_glGetVaryingLocationNV;
PFNGLGETACTIVEVARYINGNVPROC pglGetActiveVaryingNV=_Lazy_glGetActiveVaryingNV;
PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC pglGetTransformFeedbackVaryingNV=_Lazy_glGetTransformFeedbackVaryingNV;
#endif 

/* GL_NV_geometry_program4 */

#ifdef __GLEE_GL_NV_geometry_program4
void __stdcall _Lazy_glProgramVertexLimitNV(GLenum target, GLint limit)                   {if (GLeeInit()) glProgramVertexLimitNV(target, limit);}
PFNGLPROGRAMVERTEXLIMITNVPROC pglProgramVertexLimitNV=_Lazy_glProgramVertexLimitNV;
#endif 

/* GL_NV_gpu_program4 */

#ifdef __GLEE_GL_NV_gpu_program4
void __stdcall _Lazy_glProgramLocalParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w)  {if (GLeeInit()) glProgramLocalParameterI4iNV(target, index, x, y, z, w);}
void __stdcall _Lazy_glProgramLocalParameterI4ivNV(GLenum target, GLuint index, const GLint * params)  {if (GLeeInit()) glProgramLocalParameterI4ivNV(target, index, params);}
void __stdcall _Lazy_glProgramLocalParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint * params)  {if (GLeeInit()) glProgramLocalParametersI4ivNV(target, index, count, params);}
void __stdcall _Lazy_glProgramLocalParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)  {if (GLeeInit()) glProgramLocalParameterI4uiNV(target, index, x, y, z, w);}
void __stdcall _Lazy_glProgramLocalParameterI4uivNV(GLenum target, GLuint index, const GLuint * params)  {if (GLeeInit()) glProgramLocalParameterI4uivNV(target, index, params);}
void __stdcall _Lazy_glProgramLocalParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint * params)  {if (GLeeInit()) glProgramLocalParametersI4uivNV(target, index, count, params);}
void __stdcall _Lazy_glProgramEnvParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w)  {if (GLeeInit()) glProgramEnvParameterI4iNV(target, index, x, y, z, w);}
void __stdcall _Lazy_glProgramEnvParameterI4ivNV(GLenum target, GLuint index, const GLint * params)  {if (GLeeInit()) glProgramEnvParameterI4ivNV(target, index, params);}
void __stdcall _Lazy_glProgramEnvParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint * params)  {if (GLeeInit()) glProgramEnvParametersI4ivNV(target, index, count, params);}
void __stdcall _Lazy_glProgramEnvParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)  {if (GLeeInit()) glProgramEnvParameterI4uiNV(target, index, x, y, z, w);}
void __stdcall _Lazy_glProgramEnvParameterI4uivNV(GLenum target, GLuint index, const GLuint * params)  {if (GLeeInit()) glProgramEnvParameterI4uivNV(target, index, params);}
void __stdcall _Lazy_glProgramEnvParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint * params)  {if (GLeeInit()) glProgramEnvParametersI4uivNV(target, index, count, params);}
void __stdcall _Lazy_glGetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint * params)  {if (GLeeInit()) glGetProgramLocalParameterIivNV(target, index, params);}
void __stdcall _Lazy_glGetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint * params)  {if (GLeeInit()) glGetProgramLocalParameterIuivNV(target, index, params);}
void __stdcall _Lazy_glGetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint * params)  {if (GLeeInit()) glGetProgramEnvParameterIivNV(target, index, params);}
void __stdcall _Lazy_glGetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint * params)  {if (GLeeInit()) glGetProgramEnvParameterIuivNV(target, index, params);}
PFNGLPROGRAMLOCALPARAMETERI4INVPROC pglProgramLocalParameterI4iNV=_Lazy_glProgramLocalParameterI4iNV;
PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC pglProgramLocalParameterI4ivNV=_Lazy_glProgramLocalParameterI4ivNV;
PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC pglProgramLocalParametersI4ivNV=_Lazy_glProgramLocalParametersI4ivNV;
PFNGLPROGRAMLOCALPARAMETERI4UINVPROC pglProgramLocalParameterI4uiNV=_Lazy_glProgramLocalParameterI4uiNV;
PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC pglProgramLocalParameterI4uivNV=_Lazy_glProgramLocalParameterI4uivNV;
PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC pglProgramLocalParametersI4uivNV=_Lazy_glProgramLocalParametersI4uivNV;
PFNGLPROGRAMENVPARAMETERI4INVPROC pglProgramEnvParameterI4iNV=_Lazy_glProgramEnvParameterI4iNV;
PFNGLPROGRAMENVPARAMETERI4IVNVPROC pglProgramEnvParameterI4ivNV=_Lazy_glProgramEnvParameterI4ivNV;
PFNGLPROGRAMENVPARAMETERSI4IVNVPROC pglProgramEnvParametersI4ivNV=_Lazy_glProgramEnvParametersI4ivNV;
PFNGLPROGRAMENVPARAMETERI4UINVPROC pglProgramEnvParameterI4uiNV=_Lazy_glProgramEnvParameterI4uiNV;
PFNGLPROGRAMENVPARAMETERI4UIVNVPROC pglProgramEnvParameterI4uivNV=_Lazy_glProgramEnvParameterI4uivNV;
PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC pglProgramEnvParametersI4uivNV=_Lazy_glProgramEnvParametersI4uivNV;
PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC pglGetProgramLocalParameterIivNV=_Lazy_glGetProgramLocalParameterIivNV;
PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC pglGetProgramLocalParameterIuivNV=_Lazy_glGetProgramLocalParameterIuivNV;
PFNGLGETPROGRAMENVPARAMETERIIVNVPROC pglGetProgramEnvParameterIivNV=_Lazy_glGetProgramEnvParameterIivNV;
PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC pglGetProgramEnvParameterIuivNV=_Lazy_glGetProgramEnvParameterIuivNV;
#endif 

/* GL_NV_framebuffer_multisample_coverage */

#ifdef __GLEE_GL_NV_framebuffer_multisample_coverage
void __stdcall _Lazy_glRenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height)  {if (GLeeInit()) glRenderbufferStorageMultisampleCoverageNV(target, coverageSamples, colorSamples, internalformat, width, height);}
PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC pglRenderbufferStorageMultisampleCoverageNV=_Lazy_glRenderbufferStorageMultisampleCoverageNV;
#endif 

/* GL_EXT_framebuffer_multisample */

#ifdef __GLEE_GL_EXT_framebuffer_multisample
void __stdcall _Lazy_glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)  {if (GLeeInit()) glRenderbufferStorageMultisampleEXT(target, samples, internalformat, width, height);}
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC pglRenderbufferStorageMultisampleEXT=_Lazy_glRenderbufferStorageMultisampleEXT;
#endif 

/* GL_EXT_framebuffer_blit */

#ifdef __GLEE_GL_EXT_framebuffer_blit
void __stdcall _Lazy_glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)  {if (GLeeInit()) glBlitFramebufferEXT(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);}
PFNGLBLITFRAMEBUFFEREXTPROC pglBlitFramebufferEXT=_Lazy_glBlitFramebufferEXT;
#endif 

/* GL_EXT_texture_compression_rgtc */

#ifdef __GLEE_GL_EXT_texture_compression_rgtc
#endif 

/* GL_EXT_color_matrix */

#ifdef __GLEE_GL_EXT_color_matrix
#endif 

/* GL_SGIX_texture_select */

#ifdef __GLEE_GL_SGIX_texture_select
#endif 

/* GL_INGR_blend_func_separate */

#ifdef __GLEE_GL_INGR_blend_func_separate
void __stdcall _Lazy_glBlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)  {if (GLeeInit()) glBlendFuncSeparateINGR(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);}
PFNGLBLENDFUNCSEPARATEINGRPROC pglBlendFuncSeparateINGR=_Lazy_glBlendFuncSeparateINGR;
#endif 

/* GL_SGIX_depth_pass_instrument */

#ifdef __GLEE_GL_SGIX_depth_pass_instrument
#endif 

/* GL_SGIX_igloo_interface */

#ifdef __GLEE_GL_SGIX_igloo_interface
void __stdcall _Lazy_glIglooInterfaceSGIX(GLenum pname, const GLvoid * params)            {if (GLeeInit()) glIglooInterfaceSGIX(pname, params);}
PFNGLIGLOOINTERFACESGIXPROC pglIglooInterfaceSGIX=_Lazy_glIglooInterfaceSGIX;
#endif 

/* GL_EXT_draw_buffers2 */

#ifdef __GLEE_GL_EXT_draw_buffers2
void __stdcall _Lazy_glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)  {if (GLeeInit()) glColorMaskIndexedEXT(index, r, g, b, a);}
void __stdcall _Lazy_glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean * data)  {if (GLeeInit()) glGetBooleanIndexedvEXT(target, index, data);}
void __stdcall _Lazy_glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint * data)   {if (GLeeInit()) glGetIntegerIndexedvEXT(target, index, data);}
void __stdcall _Lazy_glEnableIndexedEXT(GLenum target, GLuint index)                      {if (GLeeInit()) glEnableIndexedEXT(target, index);}
void __stdcall _Lazy_glDisableIndexedEXT(GLenum target, GLuint index)                     {if (GLeeInit()) glDisableIndexedEXT(target, index);}
GLboolean __stdcall _Lazy_glIsEnabledIndexedEXT(GLenum target, GLuint index)              {if (GLeeInit()) return glIsEnabledIndexedEXT(target, index); return (GLboolean)0;}
PFNGLCOLORMASKINDEXEDEXTPROC pglColorMaskIndexedEXT=_Lazy_glColorMaskIndexedEXT;
PFNGLGETBOOLEANINDEXEDVEXTPROC pglGetBooleanIndexedvEXT=_Lazy_glGetBooleanIndexedvEXT;
PFNGLGETINTEGERINDEXEDVEXTPROC pglGetIntegerIndexedvEXT=_Lazy_glGetIntegerIndexedvEXT;
PFNGLENABLEINDEXEDEXTPROC pglEnableIndexedEXT=_Lazy_glEnableIndexedEXT;
PFNGLDISABLEINDEXEDEXTPROC pglDisableIndexedEXT=_Lazy_glDisableIndexedEXT;
PFNGLISENABLEDINDEXEDEXTPROC pglIsEnabledIndexedEXT=_Lazy_glIsEnabledIndexedEXT;
#endif 

/* GL_NV_parameter_buffer_object */

#ifdef __GLEE_GL_NV_parameter_buffer_object
void __stdcall _Lazy_glProgramBufferParametersfvNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat * params)  {if (GLeeInit()) glProgramBufferParametersfvNV(target, buffer, index, count, params);}
void __stdcall _Lazy_glProgramBufferParametersIivNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint * params)  {if (GLeeInit()) glProgramBufferParametersIivNV(target, buffer, index, count, params);}
void __stdcall _Lazy_glProgramBufferParametersIuivNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint * params)  {if (GLeeInit()) glProgramBufferParametersIuivNV(target, buffer, index, count, params);}
PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC pglProgramBufferParametersfvNV=_Lazy_glProgramBufferParametersfvNV;
PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC pglProgramBufferParametersIivNV=_Lazy_glProgramBufferParametersIivNV;
PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC pglProgramBufferParametersIuivNV=_Lazy_glProgramBufferParametersIuivNV;
#endif 

/* GL_EXT_draw_instanced */

#ifdef __GLEE_GL_EXT_draw_instanced
void __stdcall _Lazy_glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount)  {if (GLeeInit()) glDrawArraysInstancedEXT(mode, start, count, primcount);}
void __stdcall _Lazy_glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount)  {if (GLeeInit()) glDrawElementsInstancedEXT(mode, count, type, indices, primcount);}
PFNGLDRAWARRAYSINSTANCEDEXTPROC pglDrawArraysInstancedEXT=_Lazy_glDrawArraysInstancedEXT;
PFNGLDRAWELEMENTSINSTANCEDEXTPROC pglDrawElementsInstancedEXT=_Lazy_glDrawElementsInstancedEXT;
#endif 

/* GL_EXT_fragment_lighting */

#ifdef __GLEE_GL_EXT_fragment_lighting
GLvoid __stdcall _Lazy_glFragmentLightModeliEXT(GLenum pname, GLint param)                {if (GLeeInit()) glFragmentLightModeliEXT(pname, param);}
GLvoid __stdcall _Lazy_glFragmentLightModelfEXT(GLenum pname, GLfloat param)              {if (GLeeInit()) glFragmentLightModelfEXT(pname, param);}
GLvoid __stdcall _Lazy_glFragmentLightModelivEXT(GLenum pname, GLint * params)            {if (GLeeInit()) glFragmentLightModelivEXT(pname, params);}
GLvoid __stdcall _Lazy_glFragmentLightModelfvEXT(GLenum pname, GLfloat * params)          {if (GLeeInit()) glFragmentLightModelfvEXT(pname, params);}
GLvoid __stdcall _Lazy_glFragmentLightiEXT(GLenum light, GLenum pname, GLint param)       {if (GLeeInit()) glFragmentLightiEXT(light, pname, param);}
GLvoid __stdcall _Lazy_glFragmentLightfEXT(GLenum light, GLenum pname, GLfloat param)     {if (GLeeInit()) glFragmentLightfEXT(light, pname, param);}
GLvoid __stdcall _Lazy_glFragmentLightivEXT(GLenum light, GLenum pname, GLint * params)   {if (GLeeInit()) glFragmentLightivEXT(light, pname, params);}
GLvoid __stdcall _Lazy_glFragmentLightfvEXT(GLenum light, GLenum pname, GLfloat * params)  {if (GLeeInit()) glFragmentLightfvEXT(light, pname, params);}
GLvoid __stdcall _Lazy_glGetFragmentLightivEXT(GLenum light, GLenum pname, GLint * params)  {if (GLeeInit()) glGetFragmentLightivEXT(light, pname, params);}
GLvoid __stdcall _Lazy_glGetFragmentLightfvEXT(GLenum light, GLenum pname, GLfloat * params)  {if (GLeeInit()) glGetFragmentLightfvEXT(light, pname, params);}
GLvoid __stdcall _Lazy_glFragmentMaterialfEXT(GLenum face, GLenum pname, const GLfloat param)  {if (GLeeInit()) glFragmentMaterialfEXT(face, pname, param);}
GLvoid __stdcall _Lazy_glFragmentMaterialiEXT(GLenum face, GLenum pname, const GLint param)  {if (GLeeInit()) glFragmentMaterialiEXT(face, pname, param);}
GLvoid __stdcall _Lazy_glFragmentMaterialfvEXT(GLenum face, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glFragmentMaterialfvEXT(face, pname, params);}
GLvoid __stdcall _Lazy_glFragmentMaterialivEXT(GLenum face, GLenum pname, const GLint * params)  {if (GLeeInit()) glFragmentMaterialivEXT(face, pname, params);}
GLvoid __stdcall _Lazy_glFragmentColorMaterialEXT(GLenum face, GLenum mode)               {if (GLeeInit()) glFragmentColorMaterialEXT(face, mode);}
GLvoid __stdcall _Lazy_glGetFragmentMaterialfvEXT(GLenum face, GLenum pname, const GLfloat * params)  {if (GLeeInit()) glGetFragmentMaterialfvEXT(face, pname, params);}
GLvoid __stdcall _Lazy_glGetFragmentMaterialivEXT(GLenum face, GLenum pname, const GLint * params)  {if (GLeeInit()) glGetFragmentMaterialivEXT(face, pname, params);}
GLvoid __stdcall _Lazy_glLightEnviEXT(GLenum pname, GLint param)                          {if (GLeeInit()) glLightEnviEXT(pname, param);}
PFNGLFRAGMENTLIGHTMODELIEXTPROC pglFragmentLightModeliEXT=_Lazy_glFragmentLightModeliEXT;
PFNGLFRAGMENTLIGHTMODELFEXTPROC pglFragmentLightModelfEXT=_Lazy_glFragmentLightModelfEXT;
PFNGLFRAGMENTLIGHTMODELIVEXTPROC pglFragmentLightModelivEXT=_Lazy_glFragmentLightModelivEXT;
PFNGLFRAGMENTLIGHTMODELFVEXTPROC pglFragmentLightModelfvEXT=_Lazy_glFragmentLightModelfvEXT;
PFNGLFRAGMENTLIGHTIEXTPROC pglFragmentLightiEXT=_Lazy_glFragmentLightiEXT;
PFNGLFRAGMENTLIGHTFEXTPROC pglFragmentLightfEXT=_Lazy_glFragmentLightfEXT;
PFNGLFRAGMENTLIGHTIVEXTPROC pglFragmentLightivEXT=_Lazy_glFragmentLightivEXT;
PFNGLFRAGMENTLIGHTFVEXTPROC pglFragmentLightfvEXT=_Lazy_glFragmentLightfvEXT;
PFNGLGETFRAGMENTLIGHTIVEXTPROC pglGetFragmentLightivEXT=_Lazy_glGetFragmentLightivEXT;
PFNGLGETFRAGMENTLIGHTFVEXTPROC pglGetFragmentLightfvEXT=_Lazy_glGetFragmentLightfvEXT;
PFNGLFRAGMENTMATERIALFEXTPROC pglFragmentMaterialfEXT=_Lazy_glFragmentMaterialfEXT;
PFNGLFRAGMENTMATERIALIEXTPROC pglFragmentMaterialiEXT=_Lazy_glFragmentMaterialiEXT;
PFNGLFRAGMENTMATERIALFVEXTPROC pglFragmentMaterialfvEXT=_Lazy_glFragmentMaterialfvEXT;
PFNGLFRAGMENTMATERIALIVEXTPROC pglFragmentMaterialivEXT=_Lazy_glFragmentMaterialivEXT;
PFNGLFRAGMENTCOLORMATERIALEXTPROC pglFragmentColorMaterialEXT=_Lazy_glFragmentColorMaterialEXT;
PFNGLGETFRAGMENTMATERIALFVEXTPROC pglGetFragmentMaterialfvEXT=_Lazy_glGetFragmentMaterialfvEXT;
PFNGLGETFRAGMENTMATERIALIVEXTPROC pglGetFragmentMaterialivEXT=_Lazy_glGetFragmentMaterialivEXT;
PFNGLLIGHTENVIEXTPROC pglLightEnviEXT=_Lazy_glLightEnviEXT;
#endif 

/* GL_EXT_packed_depth_stencil */

#ifdef __GLEE_GL_EXT_packed_depth_stencil
#endif 

/* GL_EXT_scene_marker */

#ifdef __GLEE_GL_EXT_scene_marker
GLvoid __stdcall _Lazy_glBeginSceneEXT(void)                                              {if (GLeeInit()) glBeginSceneEXT();}
GLvoid __stdcall _Lazy_glEndSceneEXT(void)                                                {if (GLeeInit()) glEndSceneEXT();}
PFNGLBEGINSCENEEXTPROC pglBeginSceneEXT=_Lazy_glBeginSceneEXT;
PFNGLENDSCENEEXTPROC pglEndSceneEXT=_Lazy_glEndSceneEXT;
#endif 

/* GL_EXT_stencil_clear_tag */

#ifdef __GLEE_GL_EXT_stencil_clear_tag
#endif 

/* GL_EXT_texture_compression_dxt1 */

#ifdef __GLEE_GL_EXT_texture_compression_dxt1
#endif 

/* GL_EXT_texture_env */

#ifdef __GLEE_GL_EXT_texture_env
#endif 

/* GL_EXT_texture_sRGB */

#ifdef __GLEE_GL_EXT_texture_sRGB
#endif 

/* GL_IBM_static_data */

#ifdef __GLEE_GL_IBM_static_data
#endif 

/* GL_MESAX_texture_stack */

#ifdef __GLEE_GL_MESAX_texture_stack
#endif 

/* GL_OES_byte_coordinates */

#ifdef __GLEE_GL_OES_byte_coordinates
#endif 

/* GL_OES_compressed_paletted_texture */

#ifdef __GLEE_GL_OES_compressed_paletted_texture
#endif 

/* GL_OES_single_precision */

#ifdef __GLEE_GL_OES_single_precision
GLvoid __stdcall _Lazy_glDepthRangefOES(GLclampf n, GLclampf f)                           {if (GLeeInit()) glDepthRangefOES(n, f);}
GLvoid __stdcall _Lazy_glFrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f)  {if (GLeeInit()) glFrustumfOES(l, r, b, t, n, f);}
GLvoid __stdcall _Lazy_glOrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f)  {if (GLeeInit()) glOrthofOES(l, r, b, t, n, f);}
GLvoid __stdcall _Lazy_glClipPlanefOES(GLenum plane, const GLfloat* equation)             {if (GLeeInit()) glClipPlanefOES(plane, equation);}
GLvoid __stdcall _Lazy_glGetClipPlanefOES(GLenum plane, GLfloat* equation)                {if (GLeeInit()) glGetClipPlanefOES(plane, equation);}
GLvoid __stdcall _Lazy_glClearDepthfOES(GLclampd depth)                                   {if (GLeeInit()) glClearDepthfOES(depth);}
PFNGLDEPTHRANGEFOESPROC pglDepthRangefOES=_Lazy_glDepthRangefOES;
PFNGLFRUSTUMFOESPROC pglFrustumfOES=_Lazy_glFrustumfOES;
PFNGLORTHOFOESPROC pglOrthofOES=_Lazy_glOrthofOES;
PFNGLCLIPPLANEFOESPROC pglClipPlanefOES=_Lazy_glClipPlanefOES;
PFNGLGETCLIPPLANEFOESPROC pglGetClipPlanefOES=_Lazy_glGetClipPlanefOES;
PFNGLCLEARDEPTHFOESPROC pglClearDepthfOES=_Lazy_glClearDepthfOES;
#endif 

/* GL_SGIX_pixel_texture_bits */

#ifdef __GLEE_GL_SGIX_pixel_texture_bits
#endif 

/* GL_SGIX_texture_range */

#ifdef __GLEE_GL_SGIX_texture_range
#endif 

/* WGL */

#ifdef WIN32

/* Extension querying variables */

GLboolean _GLEE_WGL_ARB_buffer_region = GL_FALSE;
GLboolean _GLEE_WGL_ARB_multisample = GL_FALSE;
GLboolean _GLEE_WGL_ARB_extensions_string = GL_FALSE;
GLboolean _GLEE_WGL_ARB_pixel_format = GL_FALSE;
GLboolean _GLEE_WGL_ARB_make_current_read = GL_FALSE;
GLboolean _GLEE_WGL_ARB_pbuffer = GL_FALSE;
GLboolean _GLEE_WGL_ARB_render_texture = GL_FALSE;
GLboolean _GLEE_WGL_ARB_pixel_format_float = GL_FALSE;
GLboolean _GLEE_WGL_EXT_make_current_read = GL_FALSE;
GLboolean _GLEE_WGL_EXT_pixel_format = GL_FALSE;
GLboolean _GLEE_WGL_EXT_pbuffer = GL_FALSE;
GLboolean _GLEE_WGL_EXT_depth_float = GL_FALSE;
GLboolean _GLEE_WGL_3DFX_multisample = GL_FALSE;
GLboolean _GLEE_WGL_EXT_multisample = GL_FALSE;
GLboolean _GLEE_WGL_I3D_digital_video_control = GL_FALSE;
GLboolean _GLEE_WGL_I3D_gamma = GL_FALSE;
GLboolean _GLEE_WGL_I3D_genlock = GL_FALSE;
GLboolean _GLEE_WGL_I3D_image_buffer = GL_FALSE;
GLboolean _GLEE_WGL_I3D_swap_frame_lock = GL_FALSE;
GLboolean _GLEE_WGL_NV_render_depth_texture = GL_FALSE;
GLboolean _GLEE_WGL_NV_render_texture_rectangle = GL_FALSE;
GLboolean _GLEE_WGL_ATI_pixel_format_float = GL_FALSE;
GLboolean _GLEE_WGL_NV_float_buffer = GL_FALSE;
GLboolean _GLEE_WGL_EXT_display_color_table = GL_FALSE;
GLboolean _GLEE_WGL_EXT_extensions_string = GL_FALSE;
GLboolean _GLEE_WGL_EXT_swap_control = GL_FALSE;
GLboolean _GLEE_WGL_NV_vertex_array_range = GL_FALSE;
GLboolean _GLEE_WGL_OML_sync_control = GL_FALSE;
GLboolean _GLEE_WGL_I3D_swap_frame_usage = GL_FALSE;
GLboolean _GLEE_WGL_3DL_stereo_control = GL_FALSE;

/*  WGL Extension names */

char __GLeeWGLExtensionNames[30][32]={
    "WGL_ARB_buffer_region",
    "WGL_ARB_multisample",
    "WGL_ARB_extensions_string",
    "WGL_ARB_pixel_format",
    "WGL_ARB_make_current_read",
    "WGL_ARB_pbuffer",
    "WGL_ARB_render_texture",
    "WGL_ARB_pixel_format_float",
    "WGL_EXT_make_current_read",
    "WGL_EXT_pixel_format",
    "WGL_EXT_pbuffer",
    "WGL_EXT_depth_float",
    "WGL_3DFX_multisample",
    "WGL_EXT_multisample",
    "WGL_I3D_digital_video_control",
    "WGL_I3D_gamma",
    "WGL_I3D_genlock",
    "WGL_I3D_image_buffer",
    "WGL_I3D_swap_frame_lock",
    "WGL_NV_render_depth_texture",
    "WGL_NV_render_texture_rectangle",
    "WGL_ATI_pixel_format_float",
    "WGL_NV_float_buffer",
    "WGL_EXT_display_color_table",
    "WGL_EXT_extensions_string",
    "WGL_EXT_swap_control",
    "WGL_NV_vertex_array_range",
    "WGL_OML_sync_control",
    "WGL_I3D_swap_frame_usage",
    "WGL_3DL_stereo_control"
};
int __GLeeWGLNumExtensions=30;

/* WGL_ARB_buffer_region */

#ifdef __GLEE_WGL_ARB_buffer_region
HANDLE __stdcall _Lazy_wglCreateBufferRegionARB(HDC hDC, int iLayerPlane, UINT uType)     {if (GLeeInit()) return wglCreateBufferRegionARB(hDC, iLayerPlane, uType); return (HANDLE)0;}
VOID __stdcall _Lazy_wglDeleteBufferRegionARB(HANDLE hRegion)                             {if (GLeeInit()) wglDeleteBufferRegionARB(hRegion);}
BOOL __stdcall _Lazy_wglSaveBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height)  {if (GLeeInit()) return wglSaveBufferRegionARB(hRegion, x, y, width, height); return (BOOL)0;}
BOOL __stdcall _Lazy_wglRestoreBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc)  {if (GLeeInit()) return wglRestoreBufferRegionARB(hRegion, x, y, width, height, xSrc, ySrc); return (BOOL)0;}
PFNWGLCREATEBUFFERREGIONARBPROC pwglCreateBufferRegionARB=_Lazy_wglCreateBufferRegionARB;
PFNWGLDELETEBUFFERREGIONARBPROC pwglDeleteBufferRegionARB=_Lazy_wglDeleteBufferRegionARB;
PFNWGLSAVEBUFFERREGIONARBPROC pwglSaveBufferRegionARB=_Lazy_wglSaveBufferRegionARB;
PFNWGLRESTOREBUFFERREGIONARBPROC pwglRestoreBufferRegionARB=_Lazy_wglRestoreBufferRegionARB;
#endif 

/* WGL_ARB_multisample */

#ifdef __GLEE_WGL_ARB_multisample
#endif 

/* WGL_ARB_extensions_string */

#ifdef __GLEE_WGL_ARB_extensions_string
const char * __stdcall _Lazy_wglGetExtensionsStringARB(HDC hdc)                           {if (GLeeInit()) return wglGetExtensionsStringARB(hdc); return (const char *)0;}
PFNWGLGETEXTENSIONSSTRINGARBPROC pwglGetExtensionsStringARB=_Lazy_wglGetExtensionsStringARB;
#endif 

/* WGL_ARB_pixel_format */

#ifdef __GLEE_WGL_ARB_pixel_format
BOOL __stdcall _Lazy_wglGetPixelFormatAttribivARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues)  {if (GLeeInit()) return wglGetPixelFormatAttribivARB(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGetPixelFormatAttribfvARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues)  {if (GLeeInit()) return wglGetPixelFormatAttribfvARB(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues); return (BOOL)0;}
BOOL __stdcall _Lazy_wglChoosePixelFormatARB(HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats)  {if (GLeeInit()) return wglChoosePixelFormatARB(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats); return (BOOL)0;}
PFNWGLGETPIXELFORMATATTRIBIVARBPROC pwglGetPixelFormatAttribivARB=_Lazy_wglGetPixelFormatAttribivARB;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC pwglGetPixelFormatAttribfvARB=_Lazy_wglGetPixelFormatAttribfvARB;
PFNWGLCHOOSEPIXELFORMATARBPROC pwglChoosePixelFormatARB=_Lazy_wglChoosePixelFormatARB;
#endif 

/* WGL_ARB_make_current_read */

#ifdef __GLEE_WGL_ARB_make_current_read
BOOL __stdcall _Lazy_wglMakeContextCurrentARB(HDC hDrawDC, HDC hReadDC, HGLRC hglrc)      {if (GLeeInit()) return wglMakeContextCurrentARB(hDrawDC, hReadDC, hglrc); return (BOOL)0;}
HDC __stdcall _Lazy_wglGetCurrentReadDCARB(void)                                          {if (GLeeInit()) return wglGetCurrentReadDCARB(); return (HDC)0;}
PFNWGLMAKECONTEXTCURRENTARBPROC pwglMakeContextCurrentARB=_Lazy_wglMakeContextCurrentARB;
PFNWGLGETCURRENTREADDCARBPROC pwglGetCurrentReadDCARB=_Lazy_wglGetCurrentReadDCARB;
#endif 

/* WGL_ARB_pbuffer */

#ifdef __GLEE_WGL_ARB_pbuffer
HPBUFFERARB __stdcall _Lazy_wglCreatePbufferARB(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList)  {if (GLeeInit()) return wglCreatePbufferARB(hDC, iPixelFormat, iWidth, iHeight, piAttribList); return (HPBUFFERARB)0;}
HDC __stdcall _Lazy_wglGetPbufferDCARB(HPBUFFERARB hPbuffer)                              {if (GLeeInit()) return wglGetPbufferDCARB(hPbuffer); return (HDC)0;}
int __stdcall _Lazy_wglReleasePbufferDCARB(HPBUFFERARB hPbuffer, HDC hDC)                 {if (GLeeInit()) return wglReleasePbufferDCARB(hPbuffer, hDC); return (int)0;}
BOOL __stdcall _Lazy_wglDestroyPbufferARB(HPBUFFERARB hPbuffer)                           {if (GLeeInit()) return wglDestroyPbufferARB(hPbuffer); return (BOOL)0;}
BOOL __stdcall _Lazy_wglQueryPbufferARB(HPBUFFERARB hPbuffer, int iAttribute, int * piValue)  {if (GLeeInit()) return wglQueryPbufferARB(hPbuffer, iAttribute, piValue); return (BOOL)0;}
PFNWGLCREATEPBUFFERARBPROC pwglCreatePbufferARB=_Lazy_wglCreatePbufferARB;
PFNWGLGETPBUFFERDCARBPROC pwglGetPbufferDCARB=_Lazy_wglGetPbufferDCARB;
PFNWGLRELEASEPBUFFERDCARBPROC pwglReleasePbufferDCARB=_Lazy_wglReleasePbufferDCARB;
PFNWGLDESTROYPBUFFERARBPROC pwglDestroyPbufferARB=_Lazy_wglDestroyPbufferARB;
PFNWGLQUERYPBUFFERARBPROC pwglQueryPbufferARB=_Lazy_wglQueryPbufferARB;
#endif 

/* WGL_ARB_render_texture */

#ifdef __GLEE_WGL_ARB_render_texture
BOOL __stdcall _Lazy_wglBindTexImageARB(HPBUFFERARB hPbuffer, int iBuffer)                {if (GLeeInit()) return wglBindTexImageARB(hPbuffer, iBuffer); return (BOOL)0;}
BOOL __stdcall _Lazy_wglReleaseTexImageARB(HPBUFFERARB hPbuffer, int iBuffer)             {if (GLeeInit()) return wglReleaseTexImageARB(hPbuffer, iBuffer); return (BOOL)0;}
BOOL __stdcall _Lazy_wglSetPbufferAttribARB(HPBUFFERARB hPbuffer, const int * piAttribList)  {if (GLeeInit()) return wglSetPbufferAttribARB(hPbuffer, piAttribList); return (BOOL)0;}
PFNWGLBINDTEXIMAGEARBPROC pwglBindTexImageARB=_Lazy_wglBindTexImageARB;
PFNWGLRELEASETEXIMAGEARBPROC pwglReleaseTexImageARB=_Lazy_wglReleaseTexImageARB;
PFNWGLSETPBUFFERATTRIBARBPROC pwglSetPbufferAttribARB=_Lazy_wglSetPbufferAttribARB;
#endif 

/* WGL_ARB_pixel_format_float */

#ifdef __GLEE_WGL_ARB_pixel_format_float
#endif 

/* WGL_EXT_make_current_read */

#ifdef __GLEE_WGL_EXT_make_current_read
BOOL __stdcall _Lazy_wglMakeContextCurrentEXT(HDC hDrawDC, HDC hReadDC, HGLRC hglrc)      {if (GLeeInit()) return wglMakeContextCurrentEXT(hDrawDC, hReadDC, hglrc); return (BOOL)0;}
HDC __stdcall _Lazy_wglGetCurrentReadDCEXT(void)                                          {if (GLeeInit()) return wglGetCurrentReadDCEXT(); return (HDC)0;}
PFNWGLMAKECONTEXTCURRENTEXTPROC pwglMakeContextCurrentEXT=_Lazy_wglMakeContextCurrentEXT;
PFNWGLGETCURRENTREADDCEXTPROC pwglGetCurrentReadDCEXT=_Lazy_wglGetCurrentReadDCEXT;
#endif 

/* WGL_EXT_pixel_format */

#ifdef __GLEE_WGL_EXT_pixel_format
BOOL __stdcall _Lazy_wglGetPixelFormatAttribivEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, int * piValues)  {if (GLeeInit()) return wglGetPixelFormatAttribivEXT(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGetPixelFormatAttribfvEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, FLOAT * pfValues)  {if (GLeeInit()) return wglGetPixelFormatAttribfvEXT(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues); return (BOOL)0;}
BOOL __stdcall _Lazy_wglChoosePixelFormatEXT(HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats)  {if (GLeeInit()) return wglChoosePixelFormatEXT(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats); return (BOOL)0;}
PFNWGLGETPIXELFORMATATTRIBIVEXTPROC pwglGetPixelFormatAttribivEXT=_Lazy_wglGetPixelFormatAttribivEXT;
PFNWGLGETPIXELFORMATATTRIBFVEXTPROC pwglGetPixelFormatAttribfvEXT=_Lazy_wglGetPixelFormatAttribfvEXT;
PFNWGLCHOOSEPIXELFORMATEXTPROC pwglChoosePixelFormatEXT=_Lazy_wglChoosePixelFormatEXT;
#endif 

/* WGL_EXT_pbuffer */

#ifdef __GLEE_WGL_EXT_pbuffer
HPBUFFEREXT __stdcall _Lazy_wglCreatePbufferEXT(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList)  {if (GLeeInit()) return wglCreatePbufferEXT(hDC, iPixelFormat, iWidth, iHeight, piAttribList); return (HPBUFFEREXT)0;}
HDC __stdcall _Lazy_wglGetPbufferDCEXT(HPBUFFEREXT hPbuffer)                              {if (GLeeInit()) return wglGetPbufferDCEXT(hPbuffer); return (HDC)0;}
int __stdcall _Lazy_wglReleasePbufferDCEXT(HPBUFFEREXT hPbuffer, HDC hDC)                 {if (GLeeInit()) return wglReleasePbufferDCEXT(hPbuffer, hDC); return (int)0;}
BOOL __stdcall _Lazy_wglDestroyPbufferEXT(HPBUFFEREXT hPbuffer)                           {if (GLeeInit()) return wglDestroyPbufferEXT(hPbuffer); return (BOOL)0;}
BOOL __stdcall _Lazy_wglQueryPbufferEXT(HPBUFFEREXT hPbuffer, int iAttribute, int * piValue)  {if (GLeeInit()) return wglQueryPbufferEXT(hPbuffer, iAttribute, piValue); return (BOOL)0;}
PFNWGLCREATEPBUFFEREXTPROC pwglCreatePbufferEXT=_Lazy_wglCreatePbufferEXT;
PFNWGLGETPBUFFERDCEXTPROC pwglGetPbufferDCEXT=_Lazy_wglGetPbufferDCEXT;
PFNWGLRELEASEPBUFFERDCEXTPROC pwglReleasePbufferDCEXT=_Lazy_wglReleasePbufferDCEXT;
PFNWGLDESTROYPBUFFEREXTPROC pwglDestroyPbufferEXT=_Lazy_wglDestroyPbufferEXT;
PFNWGLQUERYPBUFFEREXTPROC pwglQueryPbufferEXT=_Lazy_wglQueryPbufferEXT;
#endif 

/* WGL_EXT_depth_float */

#ifdef __GLEE_WGL_EXT_depth_float
#endif 

/* WGL_3DFX_multisample */

#ifdef __GLEE_WGL_3DFX_multisample
#endif 

/* WGL_EXT_multisample */

#ifdef __GLEE_WGL_EXT_multisample
#endif 

/* WGL_I3D_digital_video_control */

#ifdef __GLEE_WGL_I3D_digital_video_control
BOOL __stdcall _Lazy_wglGetDigitalVideoParametersI3D(HDC hDC, int iAttribute, int * piValue)  {if (GLeeInit()) return wglGetDigitalVideoParametersI3D(hDC, iAttribute, piValue); return (BOOL)0;}
BOOL __stdcall _Lazy_wglSetDigitalVideoParametersI3D(HDC hDC, int iAttribute, const int * piValue)  {if (GLeeInit()) return wglSetDigitalVideoParametersI3D(hDC, iAttribute, piValue); return (BOOL)0;}
PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC pwglGetDigitalVideoParametersI3D=_Lazy_wglGetDigitalVideoParametersI3D;
PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC pwglSetDigitalVideoParametersI3D=_Lazy_wglSetDigitalVideoParametersI3D;
#endif 

/* WGL_I3D_gamma */

#ifdef __GLEE_WGL_I3D_gamma
BOOL __stdcall _Lazy_wglGetGammaTableParametersI3D(HDC hDC, int iAttribute, int * piValue)  {if (GLeeInit()) return wglGetGammaTableParametersI3D(hDC, iAttribute, piValue); return (BOOL)0;}
BOOL __stdcall _Lazy_wglSetGammaTableParametersI3D(HDC hDC, int iAttribute, const int * piValue)  {if (GLeeInit()) return wglSetGammaTableParametersI3D(hDC, iAttribute, piValue); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGetGammaTableI3D(HDC hDC, int iEntries, USHORT * puRed, USHORT * puGreen, USHORT * puBlue)  {if (GLeeInit()) return wglGetGammaTableI3D(hDC, iEntries, puRed, puGreen, puBlue); return (BOOL)0;}
BOOL __stdcall _Lazy_wglSetGammaTableI3D(HDC hDC, int iEntries, const USHORT * puRed, const USHORT * puGreen, const USHORT * puBlue)  {if (GLeeInit()) return wglSetGammaTableI3D(hDC, iEntries, puRed, puGreen, puBlue); return (BOOL)0;}
PFNWGLGETGAMMATABLEPARAMETERSI3DPROC pwglGetGammaTableParametersI3D=_Lazy_wglGetGammaTableParametersI3D;
PFNWGLSETGAMMATABLEPARAMETERSI3DPROC pwglSetGammaTableParametersI3D=_Lazy_wglSetGammaTableParametersI3D;
PFNWGLGETGAMMATABLEI3DPROC pwglGetGammaTableI3D=_Lazy_wglGetGammaTableI3D;
PFNWGLSETGAMMATABLEI3DPROC pwglSetGammaTableI3D=_Lazy_wglSetGammaTableI3D;
#endif 

/* WGL_I3D_genlock */

#ifdef __GLEE_WGL_I3D_genlock
BOOL __stdcall _Lazy_wglEnableGenlockI3D(HDC hDC)                                         {if (GLeeInit()) return wglEnableGenlockI3D(hDC); return (BOOL)0;}
BOOL __stdcall _Lazy_wglDisableGenlockI3D(HDC hDC)                                        {if (GLeeInit()) return wglDisableGenlockI3D(hDC); return (BOOL)0;}
BOOL __stdcall _Lazy_wglIsEnabledGenlockI3D(HDC hDC, BOOL * pFlag)                        {if (GLeeInit()) return wglIsEnabledGenlockI3D(hDC, pFlag); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGenlockSourceI3D(HDC hDC, UINT uSource)                           {if (GLeeInit()) return wglGenlockSourceI3D(hDC, uSource); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGetGenlockSourceI3D(HDC hDC, UINT * uSource)                      {if (GLeeInit()) return wglGetGenlockSourceI3D(hDC, uSource); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGenlockSourceEdgeI3D(HDC hDC, UINT uEdge)                         {if (GLeeInit()) return wglGenlockSourceEdgeI3D(hDC, uEdge); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGetGenlockSourceEdgeI3D(HDC hDC, UINT * uEdge)                    {if (GLeeInit()) return wglGetGenlockSourceEdgeI3D(hDC, uEdge); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGenlockSampleRateI3D(HDC hDC, UINT uRate)                         {if (GLeeInit()) return wglGenlockSampleRateI3D(hDC, uRate); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGetGenlockSampleRateI3D(HDC hDC, UINT * uRate)                    {if (GLeeInit()) return wglGetGenlockSampleRateI3D(hDC, uRate); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGenlockSourceDelayI3D(HDC hDC, UINT uDelay)                       {if (GLeeInit()) return wglGenlockSourceDelayI3D(hDC, uDelay); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGetGenlockSourceDelayI3D(HDC hDC, UINT * uDelay)                  {if (GLeeInit()) return wglGetGenlockSourceDelayI3D(hDC, uDelay); return (BOOL)0;}
BOOL __stdcall _Lazy_wglQueryGenlockMaxSourceDelayI3D(HDC hDC, UINT * uMaxLineDelay, UINT * uMaxPixelDelay)  {if (GLeeInit()) return wglQueryGenlockMaxSourceDelayI3D(hDC, uMaxLineDelay, uMaxPixelDelay); return (BOOL)0;}
PFNWGLENABLEGENLOCKI3DPROC pwglEnableGenlockI3D=_Lazy_wglEnableGenlockI3D;
PFNWGLDISABLEGENLOCKI3DPROC pwglDisableGenlockI3D=_Lazy_wglDisableGenlockI3D;
PFNWGLISENABLEDGENLOCKI3DPROC pwglIsEnabledGenlockI3D=_Lazy_wglIsEnabledGenlockI3D;
PFNWGLGENLOCKSOURCEI3DPROC pwglGenlockSourceI3D=_Lazy_wglGenlockSourceI3D;
PFNWGLGETGENLOCKSOURCEI3DPROC pwglGetGenlockSourceI3D=_Lazy_wglGetGenlockSourceI3D;
PFNWGLGENLOCKSOURCEEDGEI3DPROC pwglGenlockSourceEdgeI3D=_Lazy_wglGenlockSourceEdgeI3D;
PFNWGLGETGENLOCKSOURCEEDGEI3DPROC pwglGetGenlockSourceEdgeI3D=_Lazy_wglGetGenlockSourceEdgeI3D;
PFNWGLGENLOCKSAMPLERATEI3DPROC pwglGenlockSampleRateI3D=_Lazy_wglGenlockSampleRateI3D;
PFNWGLGETGENLOCKSAMPLERATEI3DPROC pwglGetGenlockSampleRateI3D=_Lazy_wglGetGenlockSampleRateI3D;
PFNWGLGENLOCKSOURCEDELAYI3DPROC pwglGenlockSourceDelayI3D=_Lazy_wglGenlockSourceDelayI3D;
PFNWGLGETGENLOCKSOURCEDELAYI3DPROC pwglGetGenlockSourceDelayI3D=_Lazy_wglGetGenlockSourceDelayI3D;
PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC pwglQueryGenlockMaxSourceDelayI3D=_Lazy_wglQueryGenlockMaxSourceDelayI3D;
#endif 

/* WGL_I3D_image_buffer */

#ifdef __GLEE_WGL_I3D_image_buffer
LPVOID __stdcall _Lazy_wglCreateImageBufferI3D(HDC hDC, DWORD dwSize, UINT uFlags)        {if (GLeeInit()) return wglCreateImageBufferI3D(hDC, dwSize, uFlags); return (LPVOID)0;}
BOOL __stdcall _Lazy_wglDestroyImageBufferI3D(HDC hDC, LPVOID pAddress)                   {if (GLeeInit()) return wglDestroyImageBufferI3D(hDC, pAddress); return (BOOL)0;}
BOOL __stdcall _Lazy_wglAssociateImageBufferEventsI3D(HDC hDC, const HANDLE * pEvent, const LPVOID * pAddress, const DWORD * pSize, UINT count)  {if (GLeeInit()) return wglAssociateImageBufferEventsI3D(hDC, pEvent, pAddress, pSize, count); return (BOOL)0;}
BOOL __stdcall _Lazy_wglReleaseImageBufferEventsI3D(HDC hDC, const LPVOID * pAddress, UINT count)  {if (GLeeInit()) return wglReleaseImageBufferEventsI3D(hDC, pAddress, count); return (BOOL)0;}
PFNWGLCREATEIMAGEBUFFERI3DPROC pwglCreateImageBufferI3D=_Lazy_wglCreateImageBufferI3D;
PFNWGLDESTROYIMAGEBUFFERI3DPROC pwglDestroyImageBufferI3D=_Lazy_wglDestroyImageBufferI3D;
PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC pwglAssociateImageBufferEventsI3D=_Lazy_wglAssociateImageBufferEventsI3D;
PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC pwglReleaseImageBufferEventsI3D=_Lazy_wglReleaseImageBufferEventsI3D;
#endif 

/* WGL_I3D_swap_frame_lock */

#ifdef __GLEE_WGL_I3D_swap_frame_lock
BOOL __stdcall _Lazy_wglEnableFrameLockI3D(void)                                          {if (GLeeInit()) return wglEnableFrameLockI3D(); return (BOOL)0;}
BOOL __stdcall _Lazy_wglDisableFrameLockI3D(void)                                         {if (GLeeInit()) return wglDisableFrameLockI3D(); return (BOOL)0;}
BOOL __stdcall _Lazy_wglIsEnabledFrameLockI3D(BOOL * pFlag)                               {if (GLeeInit()) return wglIsEnabledFrameLockI3D(pFlag); return (BOOL)0;}
BOOL __stdcall _Lazy_wglQueryFrameLockMasterI3D(BOOL * pFlag)                             {if (GLeeInit()) return wglQueryFrameLockMasterI3D(pFlag); return (BOOL)0;}
PFNWGLENABLEFRAMELOCKI3DPROC pwglEnableFrameLockI3D=_Lazy_wglEnableFrameLockI3D;
PFNWGLDISABLEFRAMELOCKI3DPROC pwglDisableFrameLockI3D=_Lazy_wglDisableFrameLockI3D;
PFNWGLISENABLEDFRAMELOCKI3DPROC pwglIsEnabledFrameLockI3D=_Lazy_wglIsEnabledFrameLockI3D;
PFNWGLQUERYFRAMELOCKMASTERI3DPROC pwglQueryFrameLockMasterI3D=_Lazy_wglQueryFrameLockMasterI3D;
#endif 

/* WGL_NV_render_depth_texture */

#ifdef __GLEE_WGL_NV_render_depth_texture
#endif 

/* WGL_NV_render_texture_rectangle */

#ifdef __GLEE_WGL_NV_render_texture_rectangle
#endif 

/* WGL_ATI_pixel_format_float */

#ifdef __GLEE_WGL_ATI_pixel_format_float
#endif 

/* WGL_NV_float_buffer */

#ifdef __GLEE_WGL_NV_float_buffer
#endif 

/* WGL_EXT_display_color_table */

#ifdef __GLEE_WGL_EXT_display_color_table
GLboolean __stdcall _Lazy_wglCreateDisplayColorTableEXT(GLushort id)                      {if (GLeeInit()) return wglCreateDisplayColorTableEXT(id); return (GLboolean)0;}
GLboolean __stdcall _Lazy_wglLoadDisplayColorTableEXT(const GLushort * table, GLuint length)  {if (GLeeInit()) return wglLoadDisplayColorTableEXT(table, length); return (GLboolean)0;}
GLboolean __stdcall _Lazy_wglBindDisplayColorTableEXT(GLushort id)                        {if (GLeeInit()) return wglBindDisplayColorTableEXT(id); return (GLboolean)0;}
VOID __stdcall _Lazy_wglDestroyDisplayColorTableEXT(GLushort id)                          {if (GLeeInit()) wglDestroyDisplayColorTableEXT(id);}
PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC pwglCreateDisplayColorTableEXT=_Lazy_wglCreateDisplayColorTableEXT;
PFNWGLLOADDISPLAYCOLORTABLEEXTPROC pwglLoadDisplayColorTableEXT=_Lazy_wglLoadDisplayColorTableEXT;
PFNWGLBINDDISPLAYCOLORTABLEEXTPROC pwglBindDisplayColorTableEXT=_Lazy_wglBindDisplayColorTableEXT;
PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC pwglDestroyDisplayColorTableEXT=_Lazy_wglDestroyDisplayColorTableEXT;
#endif 

/* WGL_EXT_extensions_string */

#ifdef __GLEE_WGL_EXT_extensions_string
const char * __stdcall _Lazy_wglGetExtensionsStringEXT(void)                              {if (GLeeInit()) return wglGetExtensionsStringEXT(); return (const char *)0;}
PFNWGLGETEXTENSIONSSTRINGEXTPROC pwglGetExtensionsStringEXT=_Lazy_wglGetExtensionsStringEXT;
#endif 

/* WGL_EXT_swap_control */

#ifdef __GLEE_WGL_EXT_swap_control
BOOL __stdcall _Lazy_wglSwapIntervalEXT(int interval)                                     {if (GLeeInit()) return wglSwapIntervalEXT(interval); return (BOOL)0;}
int __stdcall _Lazy_wglGetSwapIntervalEXT(void)                                           {if (GLeeInit()) return wglGetSwapIntervalEXT(); return (int)0;}
PFNWGLSWAPINTERVALEXTPROC pwglSwapIntervalEXT=_Lazy_wglSwapIntervalEXT;
PFNWGLGETSWAPINTERVALEXTPROC pwglGetSwapIntervalEXT=_Lazy_wglGetSwapIntervalEXT;
#endif 

/* WGL_NV_vertex_array_range */

#ifdef __GLEE_WGL_NV_vertex_array_range
void* __stdcall _Lazy_wglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority)  {if (GLeeInit()) return wglAllocateMemoryNV(size, readfreq, writefreq, priority); return (void*)0;}
void __stdcall _Lazy_wglFreeMemoryNV(void * pointer)                                      {if (GLeeInit()) wglFreeMemoryNV(pointer);}
PFNWGLALLOCATEMEMORYNVPROC pwglAllocateMemoryNV=_Lazy_wglAllocateMemoryNV;
PFNWGLFREEMEMORYNVPROC pwglFreeMemoryNV=_Lazy_wglFreeMemoryNV;
#endif 

/* WGL_OML_sync_control */

#ifdef __GLEE_WGL_OML_sync_control
BOOL __stdcall _Lazy_wglGetSyncValuesOML(HDC hdc, INT64 * ust, INT64 * msc, INT64 * sbc)  {if (GLeeInit()) return wglGetSyncValuesOML(hdc, ust, msc, sbc); return (BOOL)0;}
BOOL __stdcall _Lazy_wglGetMscRateOML(HDC hdc, INT32 * numerator, INT32 * denominator)    {if (GLeeInit()) return wglGetMscRateOML(hdc, numerator, denominator); return (BOOL)0;}
INT64 __stdcall _Lazy_wglSwapBuffersMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder)  {if (GLeeInit()) return wglSwapBuffersMscOML(hdc, target_msc, divisor, remainder); return (INT64)0;}
INT64 __stdcall _Lazy_wglSwapLayerBuffersMscOML(HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder)  {if (GLeeInit()) return wglSwapLayerBuffersMscOML(hdc, fuPlanes, target_msc, divisor, remainder); return (INT64)0;}
BOOL __stdcall _Lazy_wglWaitForMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 * ust, INT64 * msc, INT64 * sbc)  {if (GLeeInit()) return wglWaitForMscOML(hdc, target_msc, divisor, remainder, ust, msc, sbc); return (BOOL)0;}
BOOL __stdcall _Lazy_wglWaitForSbcOML(HDC hdc, INT64 target_sbc, INT64 * ust, INT64 * msc, INT64 * sbc)  {if (GLeeInit()) return wglWaitForSbcOML(hdc, target_sbc, ust, msc, sbc); return (BOOL)0;}
PFNWGLGETSYNCVALUESOMLPROC pwglGetSyncValuesOML=_Lazy_wglGetSyncValuesOML;
PFNWGLGETMSCRATEOMLPROC pwglGetMscRateOML=_Lazy_wglGetMscRateOML;
PFNWGLSWAPBUFFERSMSCOMLPROC pwglSwapBuffersMscOML=_Lazy_wglSwapBuffersMscOML;
PFNWGLSWAPLAYERBUFFERSMSCOMLPROC pwglSwapLayerBuffersMscOML=_Lazy_wglSwapLayerBuffersMscOML;
PFNWGLWAITFORMSCOMLPROC pwglWaitForMscOML=_Lazy_wglWaitForMscOML;
PFNWGLWAITFORSBCOMLPROC pwglWaitForSbcOML=_Lazy_wglWaitForSbcOML;
#endif 

/* WGL_I3D_swap_frame_usage */

#ifdef __GLEE_WGL_I3D_swap_frame_usage
BOOL __stdcall _Lazy_wglGetFrameUsageI3D(float * pUsage)                                  {if (GLeeInit()) return wglGetFrameUsageI3D(pUsage); return (BOOL)0;}
BOOL __stdcall _Lazy_wglBeginFrameTrackingI3D(void)                                       {if (GLeeInit()) return wglBeginFrameTrackingI3D(); return (BOOL)0;}
BOOL __stdcall _Lazy_wglEndFrameTrackingI3D(void)                                         {if (GLeeInit()) return wglEndFrameTrackingI3D(); return (BOOL)0;}
BOOL __stdcall _Lazy_wglQueryFrameTrackingI3D(DWORD * pFrameCount, DWORD * pMissedFrames, float * pLastMissedUsage)  {if (GLeeInit()) return wglQueryFrameTrackingI3D(pFrameCount, pMissedFrames, pLastMissedUsage); return (BOOL)0;}
PFNWGLGETFRAMEUSAGEI3DPROC pwglGetFrameUsageI3D=_Lazy_wglGetFrameUsageI3D;
PFNWGLBEGINFRAMETRACKINGI3DPROC pwglBeginFrameTrackingI3D=_Lazy_wglBeginFrameTrackingI3D;
PFNWGLENDFRAMETRACKINGI3DPROC pwglEndFrameTrackingI3D=_Lazy_wglEndFrameTrackingI3D;
PFNWGLQUERYFRAMETRACKINGI3DPROC pwglQueryFrameTrackingI3D=_Lazy_wglQueryFrameTrackingI3D;
#endif 

/* WGL_3DL_stereo_control */

#ifdef __GLEE_WGL_3DL_stereo_control
BOOL __stdcall _Lazy_wglSetStereoEmitterState3DL(HDC hDC, UINT uState)                    {if (GLeeInit()) return wglSetStereoEmitterState3DL(hDC, uState); return (BOOL)0;}
PFNWGLSETSTEREOEMITTERSTATE3DLPROC pwglSetStereoEmitterState3DL=_Lazy_wglSetStereoEmitterState3DL;
#endif 
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else /* GLX */

/* Extension querying variables */

GLboolean _GLEE_GLX_VERSION_1_3 = GL_FALSE;
GLboolean _GLEE_GLX_VERSION_1_4 = GL_FALSE;
GLboolean _GLEE_GLX_ARB_multisample = GL_FALSE;
GLboolean _GLEE_GLX_ARB_fbconfig_float = GL_FALSE;
GLboolean _GLEE_GLX_SGIS_multisample = GL_FALSE;
GLboolean _GLEE_GLX_EXT_visual_info = GL_FALSE;
GLboolean _GLEE_GLX_SGI_swap_control = GL_FALSE;
GLboolean _GLEE_GLX_SGI_video_sync = GL_FALSE;
GLboolean _GLEE_GLX_SGI_make_current_read = GL_FALSE;
GLboolean _GLEE_GLX_EXT_visual_rating = GL_FALSE;
GLboolean _GLEE_GLX_EXT_import_context = GL_FALSE;
GLboolean _GLEE_GLX_SGIX_fbconfig = GL_FALSE;
GLboolean _GLEE_GLX_SGIX_pbuffer = GL_FALSE;
GLboolean _GLEE_GLX_SGI_cushion = GL_FALSE;
GLboolean _GLEE_GLX_SGIX_video_resize = GL_FALSE;
GLboolean _GLEE_GLX_SGIX_swap_group = GL_FALSE;
GLboolean _GLEE_GLX_SGIX_swap_barrier = GL_FALSE;
GLboolean _GLEE_GLX_SGIS_blended_overlay = GL_FALSE;
GLboolean _GLEE_GLX_SGIS_shared_multisample = GL_FALSE;
GLboolean _GLEE_GLX_SUN_get_transparent_index = GL_FALSE;
GLboolean _GLEE_GLX_3DFX_multisample = GL_FALSE;
GLboolean _GLEE_GLX_MESA_copy_sub_buffer = GL_FALSE;
GLboolean _GLEE_GLX_MESA_pixmap_colormap = GL_FALSE;
GLboolean _GLEE_GLX_MESA_release_buffers = GL_FALSE;
GLboolean _GLEE_GLX_MESA_set_3dfx_mode = GL_FALSE;
GLboolean _GLEE_GLX_SGIX_visual_select_group = GL_FALSE;
GLboolean _GLEE_GLX_OML_swap_method = GL_FALSE;
GLboolean _GLEE_GLX_OML_sync_control = GL_FALSE;
GLboolean _GLEE_GLX_NV_float_buffer = GL_FALSE;
GLboolean _GLEE_GLX_SGIX_hyperpipe = GL_FALSE;
GLboolean _GLEE_GLX_MESA_agp_offset = GL_FALSE;
GLboolean _GLEE_GLX_EXT_scene_marker = GL_FALSE;

/*  GLX Extension names */

char __GLeeGLXExtensionNames[32][30]={
    "GLX_VERSION_1_3",
    "GLX_VERSION_1_4",
    "GLX_ARB_multisample",
    "GLX_ARB_fbconfig_float",
    "GLX_SGIS_multisample",
    "GLX_EXT_visual_info",
    "GLX_SGI_swap_control",
    "GLX_SGI_video_sync",
    "GLX_SGI_make_current_read",
    "GLX_EXT_visual_rating",
    "GLX_EXT_import_context",
    "GLX_SGIX_fbconfig",
    "GLX_SGIX_pbuffer",
    "GLX_SGI_cushion",
    "GLX_SGIX_video_resize",
    "GLX_SGIX_swap_group",
    "GLX_SGIX_swap_barrier",
    "GLX_SGIS_blended_overlay",
    "GLX_SGIS_shared_multisample",
    "GLX_SUN_get_transparent_index",
    "GLX_3DFX_multisample",
    "GLX_MESA_copy_sub_buffer",
    "GLX_MESA_pixmap_colormap",
    "GLX_MESA_release_buffers",
    "GLX_MESA_set_3dfx_mode",
    "GLX_SGIX_visual_select_group",
    "GLX_OML_swap_method",
    "GLX_OML_sync_control",
    "GLX_NV_float_buffer",
    "GLX_SGIX_hyperpipe",
    "GLX_MESA_agp_offset",
    "GLX_EXT_scene_marker"
};
int __GLeeGLXNumExtensions=32;

/* GLX_VERSION_1_3 */

#ifdef __GLEE_GLX_VERSION_1_3
GLXFBConfig * __stdcall _Lazy_glXGetFBConfigs(Display * dpy, int screen, int * nelements)  {if (GLeeInit()) return glXGetFBConfigs(dpy, screen, nelements); return (GLXFBConfig *)0;}
GLXFBConfig * __stdcall _Lazy_glXChooseFBConfig(Display * dpy, int screen, const int * attrib_list, int * nelements)  {if (GLeeInit()) return glXChooseFBConfig(dpy, screen, attrib_list, nelements); return (GLXFBConfig *)0;}
int __stdcall _Lazy_glXGetFBConfigAttrib(Display * dpy, GLXFBConfig config, int attribute, int * value)  {if (GLeeInit()) return glXGetFBConfigAttrib(dpy, config, attribute, value); return (int)0;}
XVisualInfo * __stdcall _Lazy_glXGetVisualFromFBConfig(Display * dpy, GLXFBConfig config)  {if (GLeeInit()) return glXGetVisualFromFBConfig(dpy, config); return (XVisualInfo *)0;}
GLXWindow __stdcall _Lazy_glXCreateWindow(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list)  {if (GLeeInit()) return glXCreateWindow(dpy, config, win, attrib_list); return (GLXWindow)0;}
void __stdcall _Lazy_glXDestroyWindow(Display * dpy, GLXWindow win)                       {if (GLeeInit()) glXDestroyWindow(dpy, win);}
GLXPixmap __stdcall _Lazy_glXCreatePixmap(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list)  {if (GLeeInit()) return glXCreatePixmap(dpy, config, pixmap, attrib_list); return (GLXPixmap)0;}
void __stdcall _Lazy_glXDestroyPixmap(Display * dpy, GLXPixmap pixmap)                    {if (GLeeInit()) glXDestroyPixmap(dpy, pixmap);}
GLXPbuffer __stdcall _Lazy_glXCreatePbuffer(Display * dpy, GLXFBConfig config, const int * attrib_list)  {if (GLeeInit()) return glXCreatePbuffer(dpy, config, attrib_list); return (GLXPbuffer)0;}
void __stdcall _Lazy_glXDestroyPbuffer(Display * dpy, GLXPbuffer pbuf)                    {if (GLeeInit()) glXDestroyPbuffer(dpy, pbuf);}
void __stdcall _Lazy_glXQueryDrawable(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value)  {if (GLeeInit()) glXQueryDrawable(dpy, draw, attribute, value);}
GLXContext __stdcall _Lazy_glXCreateNewContext(Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct)  {if (GLeeInit()) return glXCreateNewContext(dpy, config, render_type, share_list, direct); return (GLXContext)0;}
Bool __stdcall _Lazy_glXMakeContextCurrent(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx)  {if (GLeeInit()) return glXMakeContextCurrent(dpy, draw, read, ctx); return (Bool)0;}
GLXDrawable __stdcall _Lazy_glXGetCurrentReadDrawable(void)                               {if (GLeeInit()) return glXGetCurrentReadDrawable(); return (GLXDrawable)0;}
Display * __stdcall _Lazy_glXGetCurrentDisplay(void)                                      {if (GLeeInit()) return glXGetCurrentDisplay(); return (Display *)0;}
int __stdcall _Lazy_glXQueryContext(Display * dpy, GLXContext ctx, int attribute, int * value)  {if (GLeeInit()) return glXQueryContext(dpy, ctx, attribute, value); return (int)0;}
void __stdcall _Lazy_glXSelectEvent(Display * dpy, GLXDrawable draw, unsigned long event_mask)  {if (GLeeInit()) glXSelectEvent(dpy, draw, event_mask);}
void __stdcall _Lazy_glXGetSelectedEvent(Display * dpy, GLXDrawable draw, unsigned long * event_mask)  {if (GLeeInit()) glXGetSelectedEvent(dpy, draw, event_mask);}
PFNGLXGETFBCONFIGSPROC pglXGetFBConfigs=_Lazy_glXGetFBConfigs;
PFNGLXCHOOSEFBCONFIGPROC pglXChooseFBConfig=_Lazy_glXChooseFBConfig;
PFNGLXGETFBCONFIGATTRIBPROC pglXGetFBConfigAttrib=_Lazy_glXGetFBConfigAttrib;
PFNGLXGETVISUALFROMFBCONFIGPROC pglXGetVisualFromFBConfig=_Lazy_glXGetVisualFromFBConfig;
PFNGLXCREATEWINDOWPROC pglXCreateWindow=_Lazy_glXCreateWindow;
PFNGLXDESTROYWINDOWPROC pglXDestroyWindow=_Lazy_glXDestroyWindow;
PFNGLXCREATEPIXMAPPROC pglXCreatePixmap=_Lazy_glXCreatePixmap;
PFNGLXDESTROYPIXMAPPROC pglXDestroyPixmap=_Lazy_glXDestroyPixmap;
PFNGLXCREATEPBUFFERPROC pglXCreatePbuffer=_Lazy_glXCreatePbuffer;
PFNGLXDESTROYPBUFFERPROC pglXDestroyPbuffer=_Lazy_glXDestroyPbuffer;
PFNGLXQUERYDRAWABLEPROC pglXQueryDrawable=_Lazy_glXQueryDrawable;
PFNGLXCREATENEWCONTEXTPROC pglXCreateNewContext=_Lazy_glXCreateNewContext;
PFNGLXMAKECONTEXTCURRENTPROC pglXMakeContextCurrent=_Lazy_glXMakeContextCurrent;
PFNGLXGETCURRENTREADDRAWABLEPROC pglXGetCurrentReadDrawable=_Lazy_glXGetCurrentReadDrawable;
PFNGLXGETCURRENTDISPLAYPROC pglXGetCurrentDisplay=_Lazy_glXGetCurrentDisplay;
PFNGLXQUERYCONTEXTPROC pglXQueryContext=_Lazy_glXQueryContext;
PFNGLXSELECTEVENTPROC pglXSelectEvent=_Lazy_glXSelectEvent;
PFNGLXGETSELECTEDEVENTPROC pglXGetSelectedEvent=_Lazy_glXGetSelectedEvent;
#endif 

/* GLX_VERSION_1_4 */

#ifdef __GLEE_GLX_VERSION_1_4
__GLXextFuncPtr __stdcall _Lazy_glXGetProcAddress(const GLubyte * procName)               {if (GLeeInit()) return glXGetProcAddress(procName); return (__GLXextFuncPtr)0;}
PFNGLXGETPROCADDRESSPROC pglXGetProcAddress=_Lazy_glXGetProcAddress;
#endif 

/* GLX_ARB_multisample */

#ifdef __GLEE_GLX_ARB_multisample
#endif 

/* GLX_ARB_fbconfig_float */

#ifdef __GLEE_GLX_ARB_fbconfig_float
#endif 

/* GLX_SGIS_multisample */

#ifdef __GLEE_GLX_SGIS_multisample
#endif 

/* GLX_EXT_visual_info */

#ifdef __GLEE_GLX_EXT_visual_info
#endif 

/* GLX_SGI_swap_control */

#ifdef __GLEE_GLX_SGI_swap_control
int __stdcall _Lazy_glXSwapIntervalSGI(int interval)                                      {if (GLeeInit()) return glXSwapIntervalSGI(interval); return (int)0;}
PFNGLXSWAPINTERVALSGIPROC pglXSwapIntervalSGI=_Lazy_glXSwapIntervalSGI;
#endif 

/* GLX_SGI_video_sync */

#ifdef __GLEE_GLX_SGI_video_sync
int __stdcall _Lazy_glXGetVideoSyncSGI(unsigned int * count)                              {if (GLeeInit()) return glXGetVideoSyncSGI(count); return (int)0;}
int __stdcall _Lazy_glXWaitVideoSyncSGI(int divisor, int remainder, unsigned int * count)  {if (GLeeInit()) return glXWaitVideoSyncSGI(divisor, remainder, count); return (int)0;}
PFNGLXGETVIDEOSYNCSGIPROC pglXGetVideoSyncSGI=_Lazy_glXGetVideoSyncSGI;
PFNGLXWAITVIDEOSYNCSGIPROC pglXWaitVideoSyncSGI=_Lazy_glXWaitVideoSyncSGI;
#endif 

/* GLX_SGI_make_current_read */

#ifdef __GLEE_GLX_SGI_make_current_read
Bool __stdcall _Lazy_glXMakeCurrentReadSGI(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx)  {if (GLeeInit()) return glXMakeCurrentReadSGI(dpy, draw, read, ctx); return (Bool)0;}
GLXDrawable __stdcall _Lazy_glXGetCurrentReadDrawableSGI(void)                            {if (GLeeInit()) return glXGetCurrentReadDrawableSGI(); return (GLXDrawable)0;}
PFNGLXMAKECURRENTREADSGIPROC pglXMakeCurrentReadSGI=_Lazy_glXMakeCurrentReadSGI;
PFNGLXGETCURRENTREADDRAWABLESGIPROC pglXGetCurrentReadDrawableSGI=_Lazy_glXGetCurrentReadDrawableSGI;
#endif 

/* GLX_EXT_visual_rating */

#ifdef __GLEE_GLX_EXT_visual_rating
#endif 

/* GLX_EXT_import_context */

#ifdef __GLEE_GLX_EXT_import_context
Display * __stdcall _Lazy_glXGetCurrentDisplayEXT(void)                                   {if (GLeeInit()) return glXGetCurrentDisplayEXT(); return (Display *)0;}
int __stdcall _Lazy_glXQueryContextInfoEXT(Display * dpy, GLXContext context, int attribute, int * value)  {if (GLeeInit()) return glXQueryContextInfoEXT(dpy, context, attribute, value); return (int)0;}
GLXContextID __stdcall _Lazy_glXGetContextIDEXT(const GLXContext context)                 {if (GLeeInit()) return glXGetContextIDEXT(context); return (GLXContextID)0;}
GLXContext __stdcall _Lazy_glXImportContextEXT(Display * dpy, GLXContextID contextID)     {if (GLeeInit()) return glXImportContextEXT(dpy, contextID); return (GLXContext)0;}
void __stdcall _Lazy_glXFreeContextEXT(Display * dpy, GLXContext context)                 {if (GLeeInit()) glXFreeContextEXT(dpy, context);}
PFNGLXGETCURRENTDISPLAYEXTPROC pglXGetCurrentDisplayEXT=_Lazy_glXGetCurrentDisplayEXT;
PFNGLXQUERYCONTEXTINFOEXTPROC pglXQueryContextInfoEXT=_Lazy_glXQueryContextInfoEXT;
PFNGLXGETCONTEXTIDEXTPROC pglXGetContextIDEXT=_Lazy_glXGetContextIDEXT;
PFNGLXIMPORTCONTEXTEXTPROC pglXImportContextEXT=_Lazy_glXImportContextEXT;
PFNGLXFREECONTEXTEXTPROC pglXFreeContextEXT=_Lazy_glXFreeContextEXT;
#endif 

/* GLX_SGIX_fbconfig */

#ifdef __GLEE_GLX_SGIX_fbconfig
int __stdcall _Lazy_glXGetFBConfigAttribSGIX(Display * dpy, GLXFBConfigSGIX config, int attribute, int * value)  {if (GLeeInit()) return glXGetFBConfigAttribSGIX(dpy, config, attribute, value); return (int)0;}
GLXFBConfigSGIX * __stdcall _Lazy_glXChooseFBConfigSGIX(Display * dpy, int screen, int * attrib_list, int * nelements)  {if (GLeeInit()) return glXChooseFBConfigSGIX(dpy, screen, attrib_list, nelements); return (GLXFBConfigSGIX *)0;}
GLXPixmap __stdcall _Lazy_glXCreateGLXPixmapWithConfigSGIX(Display * dpy, GLXFBConfigSGIX config, Pixmap pixmap)  {if (GLeeInit()) return glXCreateGLXPixmapWithConfigSGIX(dpy, config, pixmap); return (GLXPixmap)0;}
GLXContext __stdcall _Lazy_glXCreateContextWithConfigSGIX(Display * dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct)  {if (GLeeInit()) return glXCreateContextWithConfigSGIX(dpy, config, render_type, share_list, direct); return (GLXContext)0;}
XVisualInfo * __stdcall _Lazy_glXGetVisualFromFBConfigSGIX(Display * dpy, GLXFBConfigSGIX config)  {if (GLeeInit()) return glXGetVisualFromFBConfigSGIX(dpy, config); return (XVisualInfo *)0;}
GLXFBConfigSGIX __stdcall _Lazy_glXGetFBConfigFromVisualSGIX(Display * dpy, XVisualInfo * vis)  {if (GLeeInit()) return glXGetFBConfigFromVisualSGIX(dpy, vis); return (GLXFBConfigSGIX)0;}
PFNGLXGETFBCONFIGATTRIBSGIXPROC pglXGetFBConfigAttribSGIX=_Lazy_glXGetFBConfigAttribSGIX;
PFNGLXCHOOSEFBCONFIGSGIXPROC pglXChooseFBConfigSGIX=_Lazy_glXChooseFBConfigSGIX;
PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC pglXCreateGLXPixmapWithConfigSGIX=_Lazy_glXCreateGLXPixmapWithConfigSGIX;
PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC pglXCreateContextWithConfigSGIX=_Lazy_glXCreateContextWithConfigSGIX;
PFNGLXGETVISUALFROMFBCONFIGSGIXPROC pglXGetVisualFromFBConfigSGIX=_Lazy_glXGetVisualFromFBConfigSGIX;
PFNGLXGETFBCONFIGFROMVISUALSGIXPROC pglXGetFBConfigFromVisualSGIX=_Lazy_glXGetFBConfigFromVisualSGIX;
#endif 

/* GLX_SGIX_pbuffer */

#ifdef __GLEE_GLX_SGIX_pbuffer
GLXPbufferSGIX __stdcall _Lazy_glXCreateGLXPbufferSGIX(Display * dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int * attrib_list)  {if (GLeeInit()) return glXCreateGLXPbufferSGIX(dpy, config, width, height, attrib_list); return (GLXPbufferSGIX)0;}
void __stdcall _Lazy_glXDestroyGLXPbufferSGIX(Display * dpy, GLXPbufferSGIX pbuf)         {if (GLeeInit()) glXDestroyGLXPbufferSGIX(dpy, pbuf);}
int __stdcall _Lazy_glXQueryGLXPbufferSGIX(Display * dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int * value)  {if (GLeeInit()) return glXQueryGLXPbufferSGIX(dpy, pbuf, attribute, value); return (int)0;}
void __stdcall _Lazy_glXSelectEventSGIX(Display * dpy, GLXDrawable drawable, unsigned long mask)  {if (GLeeInit()) glXSelectEventSGIX(dpy, drawable, mask);}
void __stdcall _Lazy_glXGetSelectedEventSGIX(Display * dpy, GLXDrawable drawable, unsigned long * mask)  {if (GLeeInit()) glXGetSelectedEventSGIX(dpy, drawable, mask);}
PFNGLXCREATEGLXPBUFFERSGIXPROC pglXCreateGLXPbufferSGIX=_Lazy_glXCreateGLXPbufferSGIX;
PFNGLXDESTROYGLXPBUFFERSGIXPROC pglXDestroyGLXPbufferSGIX=_Lazy_glXDestroyGLXPbufferSGIX;
PFNGLXQUERYGLXPBUFFERSGIXPROC pglXQueryGLXPbufferSGIX=_Lazy_glXQueryGLXPbufferSGIX;
PFNGLXSELECTEVENTSGIXPROC pglXSelectEventSGIX=_Lazy_glXSelectEventSGIX;
PFNGLXGETSELECTEDEVENTSGIXPROC pglXGetSelectedEventSGIX=_Lazy_glXGetSelectedEventSGIX;
#endif 

/* GLX_SGI_cushion */

#ifdef __GLEE_GLX_SGI_cushion
void __stdcall _Lazy_glXCushionSGI(Display * dpy, Window window, float cushion)           {if (GLeeInit()) glXCushionSGI(dpy, window, cushion);}
PFNGLXCUSHIONSGIPROC pglXCushionSGI=_Lazy_glXCushionSGI;
#endif 

/* GLX_SGIX_video_resize */

#ifdef __GLEE_GLX_SGIX_video_resize
int __stdcall _Lazy_glXBindChannelToWindowSGIX(Display * display, int screen, int channel, Window window)  {if (GLeeInit()) return glXBindChannelToWindowSGIX(display, screen, channel, window); return (int)0;}
int __stdcall _Lazy_glXChannelRectSGIX(Display * display, int screen, int channel, int x, int y, int w, int h)  {if (GLeeInit()) return glXChannelRectSGIX(display, screen, channel, x, y, w, h); return (int)0;}
int __stdcall _Lazy_glXQueryChannelRectSGIX(Display * display, int screen, int channel, int * dx, int * dy, int * dw, int * dh)  {if (GLeeInit()) return glXQueryChannelRectSGIX(display, screen, channel, dx, dy, dw, dh); return (int)0;}
int __stdcall _Lazy_glXQueryChannelDeltasSGIX(Display * display, int screen, int channel, int * x, int * y, int * w, int * h)  {if (GLeeInit()) return glXQueryChannelDeltasSGIX(display, screen, channel, x, y, w, h); return (int)0;}
int __stdcall _Lazy_glXChannelRectSyncSGIX(Display * display, int screen, int channel, GLenum synctype)  {if (GLeeInit()) return glXChannelRectSyncSGIX(display, screen, channel, synctype); return (int)0;}
PFNGLXBINDCHANNELTOWINDOWSGIXPROC pglXBindChannelToWindowSGIX=_Lazy_glXBindChannelToWindowSGIX;
PFNGLXCHANNELRECTSGIXPROC pglXChannelRectSGIX=_Lazy_glXChannelRectSGIX;
PFNGLXQUERYCHANNELRECTSGIXPROC pglXQueryChannelRectSGIX=_Lazy_glXQueryChannelRectSGIX;
PFNGLXQUERYCHANNELDELTASSGIXPROC pglXQueryChannelDeltasSGIX=_Lazy_glXQueryChannelDeltasSGIX;
PFNGLXCHANNELRECTSYNCSGIXPROC pglXChannelRectSyncSGIX=_Lazy_glXChannelRectSyncSGIX;
#endif 

/* GLX_SGIX_swap_group */

#ifdef __GLEE_GLX_SGIX_swap_group
void __stdcall _Lazy_glXJoinSwapGroupSGIX(Display * dpy, GLXDrawable drawable, GLXDrawable member)  {if (GLeeInit()) glXJoinSwapGroupSGIX(dpy, drawable, member);}
PFNGLXJOINSWAPGROUPSGIXPROC pglXJoinSwapGroupSGIX=_Lazy_glXJoinSwapGroupSGIX;
#endif 

/* GLX_SGIX_swap_barrier */

#ifdef __GLEE_GLX_SGIX_swap_barrier
void __stdcall _Lazy_glXBindSwapBarrierSGIX(Display * dpy, GLXDrawable drawable, int barrier)  {if (GLeeInit()) glXBindSwapBarrierSGIX(dpy, drawable, barrier);}
Bool __stdcall _Lazy_glXQueryMaxSwapBarriersSGIX(Display * dpy, int screen, int * max)    {if (GLeeInit()) return glXQueryMaxSwapBarriersSGIX(dpy, screen, max); return (Bool)0;}
PFNGLXBINDSWAPBARRIERSGIXPROC pglXBindSwapBarrierSGIX=_Lazy_glXBindSwapBarrierSGIX;
PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC pglXQueryMaxSwapBarriersSGIX=_Lazy_glXQueryMaxSwapBarriersSGIX;
#endif 

/* GLX_SGIS_blended_overlay */

#ifdef __GLEE_GLX_SGIS_blended_overlay
#endif 

/* GLX_SGIS_shared_multisample */

#ifdef __GLEE_GLX_SGIS_shared_multisample
#endif 

/* GLX_SUN_get_transparent_index */

#ifdef __GLEE_GLX_SUN_get_transparent_index
Status __stdcall _Lazy_glXGetTransparentIndexSUN(Display * dpy, Window overlay, Window underlay, long * pTransparentIndex)  {if (GLeeInit()) return glXGetTransparentIndexSUN(dpy, overlay, underlay, pTransparentIndex); return (Status)0;}
PFNGLXGETTRANSPARENTINDEXSUNPROC pglXGetTransparentIndexSUN=_Lazy_glXGetTransparentIndexSUN;
#endif 

/* GLX_3DFX_multisample */

#ifdef __GLEE_GLX_3DFX_multisample
#endif 

/* GLX_MESA_copy_sub_buffer */

#ifdef __GLEE_GLX_MESA_copy_sub_buffer
void __stdcall _Lazy_glXCopySubBufferMESA(Display * dpy, GLXDrawable drawable, int x, int y, int width, int height)  {if (GLeeInit()) glXCopySubBufferMESA(dpy, drawable, x, y, width, height);}
PFNGLXCOPYSUBBUFFERMESAPROC pglXCopySubBufferMESA=_Lazy_glXCopySubBufferMESA;
#endif 

/* GLX_MESA_pixmap_colormap */

#ifdef __GLEE_GLX_MESA_pixmap_colormap
GLXPixmap __stdcall _Lazy_glXCreateGLXPixmapMESA(Display * dpy, XVisualInfo * visual, Pixmap pixmap, Colormap cmap)  {if (GLeeInit()) return glXCreateGLXPixmapMESA(dpy, visual, pixmap, cmap); return (GLXPixmap)0;}
PFNGLXCREATEGLXPIXMAPMESAPROC pglXCreateGLXPixmapMESA=_Lazy_glXCreateGLXPixmapMESA;
#endif 

/* GLX_MESA_release_buffers */

#ifdef __GLEE_GLX_MESA_release_buffers
Bool __stdcall _Lazy_glXReleaseBuffersMESA(Display * dpy, GLXDrawable drawable)           {if (GLeeInit()) return glXReleaseBuffersMESA(dpy, drawable); return (Bool)0;}
PFNGLXRELEASEBUFFERSMESAPROC pglXReleaseBuffersMESA=_Lazy_glXReleaseBuffersMESA;
#endif 

/* GLX_MESA_set_3dfx_mode */

#ifdef __GLEE_GLX_MESA_set_3dfx_mode
Bool __stdcall _Lazy_glXSet3DfxModeMESA(int mode)                                         {if (GLeeInit()) return glXSet3DfxModeMESA(mode); return (Bool)0;}
PFNGLXSET3DFXMODEMESAPROC pglXSet3DfxModeMESA=_Lazy_glXSet3DfxModeMESA;
#endif 

/* GLX_SGIX_visual_select_group */

#ifdef __GLEE_GLX_SGIX_visual_select_group
#endif 

/* GLX_OML_swap_method */

#ifdef __GLEE_GLX_OML_swap_method
#endif 

/* GLX_OML_sync_control */

#ifdef __GLEE_GLX_OML_sync_control
Bool __stdcall _Lazy_glXGetSyncValuesOML(Display * dpy, GLXDrawable drawable, int64_t * ust, int64_t * msc, int64_t * sbc)  {if (GLeeInit()) return glXGetSyncValuesOML(dpy, drawable, ust, msc, sbc); return (Bool)0;}
Bool __stdcall _Lazy_glXGetMscRateOML(Display * dpy, GLXDrawable drawable, int32_t * numerator, int32_t * denominator)  {if (GLeeInit()) return glXGetMscRateOML(dpy, drawable, numerator, denominator); return (Bool)0;}
int64_t __stdcall _Lazy_glXSwapBuffersMscOML(Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder)  {if (GLeeInit()) return glXSwapBuffersMscOML(dpy, drawable, target_msc, divisor, remainder); return (int64_t)0;}
Bool __stdcall _Lazy_glXWaitForMscOML(Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t * ust, int64_t * msc, int64_t * sbc)  {if (GLeeInit()) return glXWaitForMscOML(dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc); return (Bool)0;}
Bool __stdcall _Lazy_glXWaitForSbcOML(Display * dpy, GLXDrawable drawable, int64_t target_sbc, int64_t * ust, int64_t * msc, int64_t * sbc)  {if (GLeeInit()) return glXWaitForSbcOML(dpy, drawable, target_sbc, ust, msc, sbc); return (Bool)0;}
PFNGLXGETSYNCVALUESOMLPROC pglXGetSyncValuesOML=_Lazy_glXGetSyncValuesOML;
PFNGLXGETMSCRATEOMLPROC pglXGetMscRateOML=_Lazy_glXGetMscRateOML;
PFNGLXSWAPBUFFERSMSCOMLPROC pglXSwapBuffersMscOML=_Lazy_glXSwapBuffersMscOML;
PFNGLXWAITFORMSCOMLPROC pglXWaitForMscOML=_Lazy_glXWaitForMscOML;
PFNGLXWAITFORSBCOMLPROC pglXWaitForSbcOML=_Lazy_glXWaitForSbcOML;
#endif 

/* GLX_NV_float_buffer */

#ifdef __GLEE_GLX_NV_float_buffer
#endif 

/* GLX_SGIX_hyperpipe */

#ifdef __GLEE_GLX_SGIX_hyperpipe
GLXHyperpipeNetworkSGIX * __stdcall _Lazy_glXQueryHyperpipeNetworkSGIX(Display * dpy, int * npipes)  {if (GLeeInit()) return glXQueryHyperpipeNetworkSGIX(dpy, npipes); return (GLXHyperpipeNetworkSGIX *)0;}
int __stdcall _Lazy_glXHyperpipeConfigSGIX(Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX * cfg, int * hpId)  {if (GLeeInit()) return glXHyperpipeConfigSGIX(dpy, networkId, npipes, cfg, hpId); return (int)0;}
GLXHyperpipeConfigSGIX * __stdcall _Lazy_glXQueryHyperpipeConfigSGIX(Display * dpy, int hpId, int * npipes)  {if (GLeeInit()) return glXQueryHyperpipeConfigSGIX(dpy, hpId, npipes); return (GLXHyperpipeConfigSGIX *)0;}
int __stdcall _Lazy_glXDestroyHyperpipeConfigSGIX(Display * dpy, int hpId)                {if (GLeeInit()) return glXDestroyHyperpipeConfigSGIX(dpy, hpId); return (int)0;}
int __stdcall _Lazy_glXBindHyperpipeSGIX(Display * dpy, int hpId)                         {if (GLeeInit()) return glXBindHyperpipeSGIX(dpy, hpId); return (int)0;}
int __stdcall _Lazy_glXQueryHyperpipeBestAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, void * attribList, void * returnAttribList)  {if (GLeeInit()) return glXQueryHyperpipeBestAttribSGIX(dpy, timeSlice, attrib, size, attribList, returnAttribList); return (int)0;}
int __stdcall _Lazy_glXHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, void * attribList)  {if (GLeeInit()) return glXHyperpipeAttribSGIX(dpy, timeSlice, attrib, size, attribList); return (int)0;}
int __stdcall _Lazy_glXQueryHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, void * returnAttribList)  {if (GLeeInit()) return glXQueryHyperpipeAttribSGIX(dpy, timeSlice, attrib, size, returnAttribList); return (int)0;}
PFNGLXQUERYHYPERPIPENETWORKSGIXPROC pglXQueryHyperpipeNetworkSGIX=_Lazy_glXQueryHyperpipeNetworkSGIX;
PFNGLXHYPERPIPECONFIGSGIXPROC pglXHyperpipeConfigSGIX=_Lazy_glXHyperpipeConfigSGIX;
PFNGLXQUERYHYPERPIPECONFIGSGIXPROC pglXQueryHyperpipeConfigSGIX=_Lazy_glXQueryHyperpipeConfigSGIX;
PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC pglXDestroyHyperpipeConfigSGIX=_Lazy_glXDestroyHyperpipeConfigSGIX;
PFNGLXBINDHYPERPIPESGIXPROC pglXBindHyperpipeSGIX=_Lazy_glXBindHyperpipeSGIX;
PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC pglXQueryHyperpipeBestAttribSGIX=_Lazy_glXQueryHyperpipeBestAttribSGIX;
PFNGLXHYPERPIPEATTRIBSGIXPROC pglXHyperpipeAttribSGIX=_Lazy_glXHyperpipeAttribSGIX;
PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC pglXQueryHyperpipeAttribSGIX=_Lazy_glXQueryHyperpipeAttribSGIX;
#endif 

/* GLX_MESA_agp_offset */

#ifdef __GLEE_GLX_MESA_agp_offset
unsigned int __stdcall _Lazy_glXGetAGPOffsetMESA(const void * pointer)                    {if (GLeeInit()) return glXGetAGPOffsetMESA(pointer); return (unsigned int)0;}
PFNGLXGETAGPOFFSETMESAPROC pglXGetAGPOffsetMESA=_Lazy_glXGetAGPOffsetMESA;
#endif 

/* GLX_EXT_scene_marker */

#ifdef __GLEE_GLX_EXT_scene_marker
#endif 
#endif /* end GLX */
/*****************************************************************
* Extension link functions
*****************************************************************/

GLuint __GLeeLink_GL_VERSION_1_2(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_VERSION_1_2
    if ((pglBlendColor = (PFNGLBLENDCOLORPROC) __GLeeGetProcAddress("glBlendColor"))!=0) nLinked++;
    if ((pglBlendEquation = (PFNGLBLENDEQUATIONPROC) __GLeeGetProcAddress("glBlendEquation"))!=0) nLinked++;
    if ((pglDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC) __GLeeGetProcAddress("glDrawRangeElements"))!=0) nLinked++;
    if ((pglColorTable = (PFNGLCOLORTABLEPROC) __GLeeGetProcAddress("glColorTable"))!=0) nLinked++;
    if ((pglColorTableParameterfv = (PFNGLCOLORTABLEPARAMETERFVPROC) __GLeeGetProcAddress("glColorTableParameterfv"))!=0) nLinked++;
    if ((pglColorTableParameteriv = (PFNGLCOLORTABLEPARAMETERIVPROC) __GLeeGetProcAddress("glColorTableParameteriv"))!=0) nLinked++;
    if ((pglCopyColorTable = (PFNGLCOPYCOLORTABLEPROC) __GLeeGetProcAddress("glCopyColorTable"))!=0) nLinked++;
    if ((pglGetColorTable = (PFNGLGETCOLORTABLEPROC) __GLeeGetProcAddress("glGetColorTable"))!=0) nLinked++;
    if ((pglGetColorTableParameterfv = (PFNGLGETCOLORTABLEPARAMETERFVPROC) __GLeeGetProcAddress("glGetColorTableParameterfv"))!=0) nLinked++;
    if ((pglGetColorTableParameteriv = (PFNGLGETCOLORTABLEPARAMETERIVPROC) __GLeeGetProcAddress("glGetColorTableParameteriv"))!=0) nLinked++;
    if ((pglColorSubTable = (PFNGLCOLORSUBTABLEPROC) __GLeeGetProcAddress("glColorSubTable"))!=0) nLinked++;
    if ((pglCopyColorSubTable = (PFNGLCOPYCOLORSUBTABLEPROC) __GLeeGetProcAddress("glCopyColorSubTable"))!=0) nLinked++;
    if ((pglConvolutionFilter1D = (PFNGLCONVOLUTIONFILTER1DPROC) __GLeeGetProcAddress("glConvolutionFilter1D"))!=0) nLinked++;
    if ((pglConvolutionFilter2D = (PFNGLCONVOLUTIONFILTER2DPROC) __GLeeGetProcAddress("glConvolutionFilter2D"))!=0) nLinked++;
    if ((pglConvolutionParameterf = (PFNGLCONVOLUTIONPARAMETERFPROC) __GLeeGetProcAddress("glConvolutionParameterf"))!=0) nLinked++;
    if ((pglConvolutionParameterfv = (PFNGLCONVOLUTIONPARAMETERFVPROC) __GLeeGetProcAddress("glConvolutionParameterfv"))!=0) nLinked++;
    if ((pglConvolutionParameteri = (PFNGLCONVOLUTIONPARAMETERIPROC) __GLeeGetProcAddress("glConvolutionParameteri"))!=0) nLinked++;
    if ((pglConvolutionParameteriv = (PFNGLCONVOLUTIONPARAMETERIVPROC) __GLeeGetProcAddress("glConvolutionParameteriv"))!=0) nLinked++;
    if ((pglCopyConvolutionFilter1D = (PFNGLCOPYCONVOLUTIONFILTER1DPROC) __GLeeGetProcAddress("glCopyConvolutionFilter1D"))!=0) nLinked++;
    if ((pglCopyConvolutionFilter2D = (PFNGLCOPYCONVOLUTIONFILTER2DPROC) __GLeeGetProcAddress("glCopyConvolutionFilter2D"))!=0) nLinked++;
    if ((pglGetConvolutionFilter = (PFNGLGETCONVOLUTIONFILTERPROC) __GLeeGetProcAddress("glGetConvolutionFilter"))!=0) nLinked++;
    if ((pglGetConvolutionParameterfv = (PFNGLGETCONVOLUTIONPARAMETERFVPROC) __GLeeGetProcAddress("glGetConvolutionParameterfv"))!=0) nLinked++;
    if ((pglGetConvolutionParameteriv = (PFNGLGETCONVOLUTIONPARAMETERIVPROC) __GLeeGetProcAddress("glGetConvolutionParameteriv"))!=0) nLinked++;
    if ((pglGetSeparableFilter = (PFNGLGETSEPARABLEFILTERPROC) __GLeeGetProcAddress("glGetSeparableFilter"))!=0) nLinked++;
    if ((pglSeparableFilter2D = (PFNGLSEPARABLEFILTER2DPROC) __GLeeGetProcAddress("glSeparableFilter2D"))!=0) nLinked++;
    if ((pglGetHistogram = (PFNGLGETHISTOGRAMPROC) __GLeeGetProcAddress("glGetHistogram"))!=0) nLinked++;
    if ((pglGetHistogramParameterfv = (PFNGLGETHISTOGRAMPARAMETERFVPROC) __GLeeGetProcAddress("glGetHistogramParameterfv"))!=0) nLinked++;
    if ((pglGetHistogramParameteriv = (PFNGLGETHISTOGRAMPARAMETERIVPROC) __GLeeGetProcAddress("glGetHistogramParameteriv"))!=0) nLinked++;
    if ((pglGetMinmax = (PFNGLGETMINMAXPROC) __GLeeGetProcAddress("glGetMinmax"))!=0) nLinked++;
    if ((pglGetMinmaxParameterfv = (PFNGLGETMINMAXPARAMETERFVPROC) __GLeeGetProcAddress("glGetMinmaxParameterfv"))!=0) nLinked++;
    if ((pglGetMinmaxParameteriv = (PFNGLGETMINMAXPARAMETERIVPROC) __GLeeGetProcAddress("glGetMinmaxParameteriv"))!=0) nLinked++;
    if ((pglHistogram = (PFNGLHISTOGRAMPROC) __GLeeGetProcAddress("glHistogram"))!=0) nLinked++;
    if ((pglMinmax = (PFNGLMINMAXPROC) __GLeeGetProcAddress("glMinmax"))!=0) nLinked++;
    if ((pglResetHistogram = (PFNGLRESETHISTOGRAMPROC) __GLeeGetProcAddress("glResetHistogram"))!=0) nLinked++;
    if ((pglResetMinmax = (PFNGLRESETMINMAXPROC) __GLeeGetProcAddress("glResetMinmax"))!=0) nLinked++;
    if ((pglTexImage3D = (PFNGLTEXIMAGE3DPROC) __GLeeGetProcAddress("glTexImage3D"))!=0) nLinked++;
    if ((pglTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC) __GLeeGetProcAddress("glTexSubImage3D"))!=0) nLinked++;
    if ((pglCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC) __GLeeGetProcAddress("glCopyTexSubImage3D"))!=0) nLinked++;
#endif
    if (nLinked==38) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_imaging(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_VERSION_1_3(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_VERSION_1_3
    if ((pglActiveTexture = (PFNGLACTIVETEXTUREPROC) __GLeeGetProcAddress("glActiveTexture"))!=0) nLinked++;
    if ((pglClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC) __GLeeGetProcAddress("glClientActiveTexture"))!=0) nLinked++;
    if ((pglMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC) __GLeeGetProcAddress("glMultiTexCoord1d"))!=0) nLinked++;
    if ((pglMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC) __GLeeGetProcAddress("glMultiTexCoord1dv"))!=0) nLinked++;
    if ((pglMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC) __GLeeGetProcAddress("glMultiTexCoord1f"))!=0) nLinked++;
    if ((pglMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC) __GLeeGetProcAddress("glMultiTexCoord1fv"))!=0) nLinked++;
    if ((pglMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC) __GLeeGetProcAddress("glMultiTexCoord1i"))!=0) nLinked++;
    if ((pglMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC) __GLeeGetProcAddress("glMultiTexCoord1iv"))!=0) nLinked++;
    if ((pglMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC) __GLeeGetProcAddress("glMultiTexCoord1s"))!=0) nLinked++;
    if ((pglMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC) __GLeeGetProcAddress("glMultiTexCoord1sv"))!=0) nLinked++;
    if ((pglMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC) __GLeeGetProcAddress("glMultiTexCoord2d"))!=0) nLinked++;
    if ((pglMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC) __GLeeGetProcAddress("glMultiTexCoord2dv"))!=0) nLinked++;
    if ((pglMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC) __GLeeGetProcAddress("glMultiTexCoord2f"))!=0) nLinked++;
    if ((pglMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC) __GLeeGetProcAddress("glMultiTexCoord2fv"))!=0) nLinked++;
    if ((pglMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC) __GLeeGetProcAddress("glMultiTexCoord2i"))!=0) nLinked++;
    if ((pglMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC) __GLeeGetProcAddress("glMultiTexCoord2iv"))!=0) nLinked++;
    if ((pglMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC) __GLeeGetProcAddress("glMultiTexCoord2s"))!=0) nLinked++;
    if ((pglMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC) __GLeeGetProcAddress("glMultiTexCoord2sv"))!=0) nLinked++;
    if ((pglMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC) __GLeeGetProcAddress("glMultiTexCoord3d"))!=0) nLinked++;
    if ((pglMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC) __GLeeGetProcAddress("glMultiTexCoord3dv"))!=0) nLinked++;
    if ((pglMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC) __GLeeGetProcAddress("glMultiTexCoord3f"))!=0) nLinked++;
    if ((pglMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC) __GLeeGetProcAddress("glMultiTexCoord3fv"))!=0) nLinked++;
    if ((pglMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC) __GLeeGetProcAddress("glMultiTexCoord3i"))!=0) nLinked++;
    if ((pglMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC) __GLeeGetProcAddress("glMultiTexCoord3iv"))!=0) nLinked++;
    if ((pglMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC) __GLeeGetProcAddress("glMultiTexCoord3s"))!=0) nLinked++;
    if ((pglMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC) __GLeeGetProcAddress("glMultiTexCoord3sv"))!=0) nLinked++;
    if ((pglMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC) __GLeeGetProcAddress("glMultiTexCoord4d"))!=0) nLinked++;
    if ((pglMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC) __GLeeGetProcAddress("glMultiTexCoord4dv"))!=0) nLinked++;
    if ((pglMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC) __GLeeGetProcAddress("glMultiTexCoord4f"))!=0) nLinked++;
    if ((pglMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC) __GLeeGetProcAddress("glMultiTexCoord4fv"))!=0) nLinked++;
    if ((pglMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC) __GLeeGetProcAddress("glMultiTexCoord4i"))!=0) nLinked++;
    if ((pglMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC) __GLeeGetProcAddress("glMultiTexCoord4iv"))!=0) nLinked++;
    if ((pglMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC) __GLeeGetProcAddress("glMultiTexCoord4s"))!=0) nLinked++;
    if ((pglMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC) __GLeeGetProcAddress("glMultiTexCoord4sv"))!=0) nLinked++;
    if ((pglLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC) __GLeeGetProcAddress("glLoadTransposeMatrixf"))!=0) nLinked++;
    if ((pglLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC) __GLeeGetProcAddress("glLoadTransposeMatrixd"))!=0) nLinked++;
    if ((pglMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC) __GLeeGetProcAddress("glMultTransposeMatrixf"))!=0) nLinked++;
    if ((pglMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC) __GLeeGetProcAddress("glMultTransposeMatrixd"))!=0) nLinked++;
    if ((pglSampleCoverage = (PFNGLSAMPLECOVERAGEPROC) __GLeeGetProcAddress("glSampleCoverage"))!=0) nLinked++;
    if ((pglCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC) __GLeeGetProcAddress("glCompressedTexImage3D"))!=0) nLinked++;
    if ((pglCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC) __GLeeGetProcAddress("glCompressedTexImage2D"))!=0) nLinked++;
    if ((pglCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC) __GLeeGetProcAddress("glCompressedTexImage1D"))!=0) nLinked++;
    if ((pglCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) __GLeeGetProcAddress("glCompressedTexSubImage3D"))!=0) nLinked++;
    if ((pglCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) __GLeeGetProcAddress("glCompressedTexSubImage2D"))!=0) nLinked++;
    if ((pglCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) __GLeeGetProcAddress("glCompressedTexSubImage1D"))!=0) nLinked++;
    if ((pglGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC) __GLeeGetProcAddress("glGetCompressedTexImage"))!=0) nLinked++;
#endif
    if (nLinked==46) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_VERSION_1_4(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_VERSION_1_4
    if ((pglBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) __GLeeGetProcAddress("glBlendFuncSeparate"))!=0) nLinked++;
    if ((pglFogCoordf = (PFNGLFOGCOORDFPROC) __GLeeGetProcAddress("glFogCoordf"))!=0) nLinked++;
    if ((pglFogCoordfv = (PFNGLFOGCOORDFVPROC) __GLeeGetProcAddress("glFogCoordfv"))!=0) nLinked++;
    if ((pglFogCoordd = (PFNGLFOGCOORDDPROC) __GLeeGetProcAddress("glFogCoordd"))!=0) nLinked++;
    if ((pglFogCoorddv = (PFNGLFOGCOORDDVPROC) __GLeeGetProcAddress("glFogCoorddv"))!=0) nLinked++;
    if ((pglFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC) __GLeeGetProcAddress("glFogCoordPointer"))!=0) nLinked++;
    if ((pglMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC) __GLeeGetProcAddress("glMultiDrawArrays"))!=0) nLinked++;
    if ((pglMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC) __GLeeGetProcAddress("glMultiDrawElements"))!=0) nLinked++;
    if ((pglPointParameterf = (PFNGLPOINTPARAMETERFPROC) __GLeeGetProcAddress("glPointParameterf"))!=0) nLinked++;
    if ((pglPointParameterfv = (PFNGLPOINTPARAMETERFVPROC) __GLeeGetProcAddress("glPointParameterfv"))!=0) nLinked++;
    if ((pglPointParameteri = (PFNGLPOINTPARAMETERIPROC) __GLeeGetProcAddress("glPointParameteri"))!=0) nLinked++;
    if ((pglPointParameteriv = (PFNGLPOINTPARAMETERIVPROC) __GLeeGetProcAddress("glPointParameteriv"))!=0) nLinked++;
    if ((pglSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC) __GLeeGetProcAddress("glSecondaryColor3b"))!=0) nLinked++;
    if ((pglSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC) __GLeeGetProcAddress("glSecondaryColor3bv"))!=0) nLinked++;
    if ((pglSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC) __GLeeGetProcAddress("glSecondaryColor3d"))!=0) nLinked++;
    if ((pglSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC) __GLeeGetProcAddress("glSecondaryColor3dv"))!=0) nLinked++;
    if ((pglSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC) __GLeeGetProcAddress("glSecondaryColor3f"))!=0) nLinked++;
    if ((pglSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC) __GLeeGetProcAddress("glSecondaryColor3fv"))!=0) nLinked++;
    if ((pglSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC) __GLeeGetProcAddress("glSecondaryColor3i"))!=0) nLinked++;
    if ((pglSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC) __GLeeGetProcAddress("glSecondaryColor3iv"))!=0) nLinked++;
    if ((pglSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC) __GLeeGetProcAddress("glSecondaryColor3s"))!=0) nLinked++;
    if ((pglSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC) __GLeeGetProcAddress("glSecondaryColor3sv"))!=0) nLinked++;
    if ((pglSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC) __GLeeGetProcAddress("glSecondaryColor3ub"))!=0) nLinked++;
    if ((pglSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC) __GLeeGetProcAddress("glSecondaryColor3ubv"))!=0) nLinked++;
    if ((pglSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC) __GLeeGetProcAddress("glSecondaryColor3ui"))!=0) nLinked++;
    if ((pglSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC) __GLeeGetProcAddress("glSecondaryColor3uiv"))!=0) nLinked++;
    if ((pglSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC) __GLeeGetProcAddress("glSecondaryColor3us"))!=0) nLinked++;
    if ((pglSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC) __GLeeGetProcAddress("glSecondaryColor3usv"))!=0) nLinked++;
    if ((pglSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC) __GLeeGetProcAddress("glSecondaryColorPointer"))!=0) nLinked++;
    if ((pglWindowPos2d = (PFNGLWINDOWPOS2DPROC) __GLeeGetProcAddress("glWindowPos2d"))!=0) nLinked++;
    if ((pglWindowPos2dv = (PFNGLWINDOWPOS2DVPROC) __GLeeGetProcAddress("glWindowPos2dv"))!=0) nLinked++;
    if ((pglWindowPos2f = (PFNGLWINDOWPOS2FPROC) __GLeeGetProcAddress("glWindowPos2f"))!=0) nLinked++;
    if ((pglWindowPos2fv = (PFNGLWINDOWPOS2FVPROC) __GLeeGetProcAddress("glWindowPos2fv"))!=0) nLinked++;
    if ((pglWindowPos2i = (PFNGLWINDOWPOS2IPROC) __GLeeGetProcAddress("glWindowPos2i"))!=0) nLinked++;
    if ((pglWindowPos2iv = (PFNGLWINDOWPOS2IVPROC) __GLeeGetProcAddress("glWindowPos2iv"))!=0) nLinked++;
    if ((pglWindowPos2s = (PFNGLWINDOWPOS2SPROC) __GLeeGetProcAddress("glWindowPos2s"))!=0) nLinked++;
    if ((pglWindowPos2sv = (PFNGLWINDOWPOS2SVPROC) __GLeeGetProcAddress("glWindowPos2sv"))!=0) nLinked++;
    if ((pglWindowPos3d = (PFNGLWINDOWPOS3DPROC) __GLeeGetProcAddress("glWindowPos3d"))!=0) nLinked++;
    if ((pglWindowPos3dv = (PFNGLWINDOWPOS3DVPROC) __GLeeGetProcAddress("glWindowPos3dv"))!=0) nLinked++;
    if ((pglWindowPos3f = (PFNGLWINDOWPOS3FPROC) __GLeeGetProcAddress("glWindowPos3f"))!=0) nLinked++;
    if ((pglWindowPos3fv = (PFNGLWINDOWPOS3FVPROC) __GLeeGetProcAddress("glWindowPos3fv"))!=0) nLinked++;
    if ((pglWindowPos3i = (PFNGLWINDOWPOS3IPROC) __GLeeGetProcAddress("glWindowPos3i"))!=0) nLinked++;
    if ((pglWindowPos3iv = (PFNGLWINDOWPOS3IVPROC) __GLeeGetProcAddress("glWindowPos3iv"))!=0) nLinked++;
    if ((pglWindowPos3s = (PFNGLWINDOWPOS3SPROC) __GLeeGetProcAddress("glWindowPos3s"))!=0) nLinked++;
    if ((pglWindowPos3sv = (PFNGLWINDOWPOS3SVPROC) __GLeeGetProcAddress("glWindowPos3sv"))!=0) nLinked++;
#endif
    if (nLinked==45) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_VERSION_1_5(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_VERSION_1_5
    if ((pglGenQueries = (PFNGLGENQUERIESPROC) __GLeeGetProcAddress("glGenQueries"))!=0) nLinked++;
    if ((pglDeleteQueries = (PFNGLDELETEQUERIESPROC) __GLeeGetProcAddress("glDeleteQueries"))!=0) nLinked++;
    if ((pglIsQuery = (PFNGLISQUERYPROC) __GLeeGetProcAddress("glIsQuery"))!=0) nLinked++;
    if ((pglBeginQuery = (PFNGLBEGINQUERYPROC) __GLeeGetProcAddress("glBeginQuery"))!=0) nLinked++;
    if ((pglEndQuery = (PFNGLENDQUERYPROC) __GLeeGetProcAddress("glEndQuery"))!=0) nLinked++;
    if ((pglGetQueryiv = (PFNGLGETQUERYIVPROC) __GLeeGetProcAddress("glGetQueryiv"))!=0) nLinked++;
    if ((pglGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC) __GLeeGetProcAddress("glGetQueryObjectiv"))!=0) nLinked++;
    if ((pglGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC) __GLeeGetProcAddress("glGetQueryObjectuiv"))!=0) nLinked++;
    if ((pglBindBuffer = (PFNGLBINDBUFFERPROC) __GLeeGetProcAddress("glBindBuffer"))!=0) nLinked++;
    if ((pglDeleteBuffers = (PFNGLDELETEBUFFERSPROC) __GLeeGetProcAddress("glDeleteBuffers"))!=0) nLinked++;
    if ((pglGenBuffers = (PFNGLGENBUFFERSPROC) __GLeeGetProcAddress("glGenBuffers"))!=0) nLinked++;
    if ((pglIsBuffer = (PFNGLISBUFFERPROC) __GLeeGetProcAddress("glIsBuffer"))!=0) nLinked++;
    if ((pglBufferData = (PFNGLBUFFERDATAPROC) __GLeeGetProcAddress("glBufferData"))!=0) nLinked++;
    if ((pglBufferSubData = (PFNGLBUFFERSUBDATAPROC) __GLeeGetProcAddress("glBufferSubData"))!=0) nLinked++;
    if ((pglGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC) __GLeeGetProcAddress("glGetBufferSubData"))!=0) nLinked++;
    if ((pglMapBuffer = (PFNGLMAPBUFFERPROC) __GLeeGetProcAddress("glMapBuffer"))!=0) nLinked++;
    if ((pglUnmapBuffer = (PFNGLUNMAPBUFFERPROC) __GLeeGetProcAddress("glUnmapBuffer"))!=0) nLinked++;
    if ((pglGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) __GLeeGetProcAddress("glGetBufferParameteriv"))!=0) nLinked++;
    if ((pglGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC) __GLeeGetProcAddress("glGetBufferPointerv"))!=0) nLinked++;
#endif
    if (nLinked==19) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_VERSION_2_0(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_VERSION_2_0
    if ((pglBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC) __GLeeGetProcAddress("glBlendEquationSeparate"))!=0) nLinked++;
    if ((pglDrawBuffers = (PFNGLDRAWBUFFERSPROC) __GLeeGetProcAddress("glDrawBuffers"))!=0) nLinked++;
    if ((pglStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC) __GLeeGetProcAddress("glStencilOpSeparate"))!=0) nLinked++;
    if ((pglStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC) __GLeeGetProcAddress("glStencilFuncSeparate"))!=0) nLinked++;
    if ((pglStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC) __GLeeGetProcAddress("glStencilMaskSeparate"))!=0) nLinked++;
    if ((pglAttachShader = (PFNGLATTACHSHADERPROC) __GLeeGetProcAddress("glAttachShader"))!=0) nLinked++;
    if ((pglBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC) __GLeeGetProcAddress("glBindAttribLocation"))!=0) nLinked++;
    if ((pglCompileShader = (PFNGLCOMPILESHADERPROC) __GLeeGetProcAddress("glCompileShader"))!=0) nLinked++;
    if ((pglCreateProgram = (PFNGLCREATEPROGRAMPROC) __GLeeGetProcAddress("glCreateProgram"))!=0) nLinked++;
    if ((pglCreateShader = (PFNGLCREATESHADERPROC) __GLeeGetProcAddress("glCreateShader"))!=0) nLinked++;
    if ((pglDeleteProgram = (PFNGLDELETEPROGRAMPROC) __GLeeGetProcAddress("glDeleteProgram"))!=0) nLinked++;
    if ((pglDeleteShader = (PFNGLDELETESHADERPROC) __GLeeGetProcAddress("glDeleteShader"))!=0) nLinked++;
    if ((pglDetachShader = (PFNGLDETACHSHADERPROC) __GLeeGetProcAddress("glDetachShader"))!=0) nLinked++;
    if ((pglDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) __GLeeGetProcAddress("glDisableVertexAttribArray"))!=0) nLinked++;
    if ((pglEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC) __GLeeGetProcAddress("glEnableVertexAttribArray"))!=0) nLinked++;
    if ((pglGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC) __GLeeGetProcAddress("glGetActiveAttrib"))!=0) nLinked++;
    if ((pglGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC) __GLeeGetProcAddress("glGetActiveUniform"))!=0) nLinked++;
    if ((pglGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC) __GLeeGetProcAddress("glGetAttachedShaders"))!=0) nLinked++;
    if ((pglGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC) __GLeeGetProcAddress("glGetAttribLocation"))!=0) nLinked++;
    if ((pglGetProgramiv = (PFNGLGETPROGRAMIVPROC) __GLeeGetProcAddress("glGetProgramiv"))!=0) nLinked++;
    if ((pglGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) __GLeeGetProcAddress("glGetProgramInfoLog"))!=0) nLinked++;
    if ((pglGetShaderiv = (PFNGLGETSHADERIVPROC) __GLeeGetProcAddress("glGetShaderiv"))!=0) nLinked++;
    if ((pglGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) __GLeeGetProcAddress("glGetShaderInfoLog"))!=0) nLinked++;
    if ((pglGetShaderSource = (PFNGLGETSHADERSOURCEPROC) __GLeeGetProcAddress("glGetShaderSource"))!=0) nLinked++;
    if ((pglGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) __GLeeGetProcAddress("glGetUniformLocation"))!=0) nLinked++;
    if ((pglGetUniformfv = (PFNGLGETUNIFORMFVPROC) __GLeeGetProcAddress("glGetUniformfv"))!=0) nLinked++;
    if ((pglGetUniformiv = (PFNGLGETUNIFORMIVPROC) __GLeeGetProcAddress("glGetUniformiv"))!=0) nLinked++;
    if ((pglGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC) __GLeeGetProcAddress("glGetVertexAttribdv"))!=0) nLinked++;
    if ((pglGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC) __GLeeGetProcAddress("glGetVertexAttribfv"))!=0) nLinked++;
    if ((pglGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC) __GLeeGetProcAddress("glGetVertexAttribiv"))!=0) nLinked++;
    if ((pglGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC) __GLeeGetProcAddress("glGetVertexAttribPointerv"))!=0) nLinked++;
    if ((pglIsProgram = (PFNGLISPROGRAMPROC) __GLeeGetProcAddress("glIsProgram"))!=0) nLinked++;
    if ((pglIsShader = (PFNGLISSHADERPROC) __GLeeGetProcAddress("glIsShader"))!=0) nLinked++;
    if ((pglLinkProgram = (PFNGLLINKPROGRAMPROC) __GLeeGetProcAddress("glLinkProgram"))!=0) nLinked++;
    if ((pglShaderSource = (PFNGLSHADERSOURCEPROC) __GLeeGetProcAddress("glShaderSource"))!=0) nLinked++;
    if ((pglUseProgram = (PFNGLUSEPROGRAMPROC) __GLeeGetProcAddress("glUseProgram"))!=0) nLinked++;
    if ((pglUniform1f = (PFNGLUNIFORM1FPROC) __GLeeGetProcAddress("glUniform1f"))!=0) nLinked++;
    if ((pglUniform2f = (PFNGLUNIFORM2FPROC) __GLeeGetProcAddress("glUniform2f"))!=0) nLinked++;
    if ((pglUniform3f = (PFNGLUNIFORM3FPROC) __GLeeGetProcAddress("glUniform3f"))!=0) nLinked++;
    if ((pglUniform4f = (PFNGLUNIFORM4FPROC) __GLeeGetProcAddress("glUniform4f"))!=0) nLinked++;
    if ((pglUniform1i = (PFNGLUNIFORM1IPROC) __GLeeGetProcAddress("glUniform1i"))!=0) nLinked++;
    if ((pglUniform2i = (PFNGLUNIFORM2IPROC) __GLeeGetProcAddress("glUniform2i"))!=0) nLinked++;
    if ((pglUniform3i = (PFNGLUNIFORM3IPROC) __GLeeGetProcAddress("glUniform3i"))!=0) nLinked++;
    if ((pglUniform4i = (PFNGLUNIFORM4IPROC) __GLeeGetProcAddress("glUniform4i"))!=0) nLinked++;
    if ((pglUniform1fv = (PFNGLUNIFORM1FVPROC) __GLeeGetProcAddress("glUniform1fv"))!=0) nLinked++;
    if ((pglUniform2fv = (PFNGLUNIFORM2FVPROC) __GLeeGetProcAddress("glUniform2fv"))!=0) nLinked++;
    if ((pglUniform3fv = (PFNGLUNIFORM3FVPROC) __GLeeGetProcAddress("glUniform3fv"))!=0) nLinked++;
    if ((pglUniform4fv = (PFNGLUNIFORM4FVPROC) __GLeeGetProcAddress("glUniform4fv"))!=0) nLinked++;
    if ((pglUniform1iv = (PFNGLUNIFORM1IVPROC) __GLeeGetProcAddress("glUniform1iv"))!=0) nLinked++;
    if ((pglUniform2iv = (PFNGLUNIFORM2IVPROC) __GLeeGetProcAddress("glUniform2iv"))!=0) nLinked++;
    if ((pglUniform3iv = (PFNGLUNIFORM3IVPROC) __GLeeGetProcAddress("glUniform3iv"))!=0) nLinked++;
    if ((pglUniform4iv = (PFNGLUNIFORM4IVPROC) __GLeeGetProcAddress("glUniform4iv"))!=0) nLinked++;
    if ((pglUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC) __GLeeGetProcAddress("glUniformMatrix2fv"))!=0) nLinked++;
    if ((pglUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC) __GLeeGetProcAddress("glUniformMatrix3fv"))!=0) nLinked++;
    if ((pglUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) __GLeeGetProcAddress("glUniformMatrix4fv"))!=0) nLinked++;
    if ((pglValidateProgram = (PFNGLVALIDATEPROGRAMPROC) __GLeeGetProcAddress("glValidateProgram"))!=0) nLinked++;
    if ((pglVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC) __GLeeGetProcAddress("glVertexAttrib1d"))!=0) nLinked++;
    if ((pglVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC) __GLeeGetProcAddress("glVertexAttrib1dv"))!=0) nLinked++;
    if ((pglVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC) __GLeeGetProcAddress("glVertexAttrib1f"))!=0) nLinked++;
    if ((pglVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC) __GLeeGetProcAddress("glVertexAttrib1fv"))!=0) nLinked++;
    if ((pglVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC) __GLeeGetProcAddress("glVertexAttrib1s"))!=0) nLinked++;
    if ((pglVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC) __GLeeGetProcAddress("glVertexAttrib1sv"))!=0) nLinked++;
    if ((pglVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC) __GLeeGetProcAddress("glVertexAttrib2d"))!=0) nLinked++;
    if ((pglVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC) __GLeeGetProcAddress("glVertexAttrib2dv"))!=0) nLinked++;
    if ((pglVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC) __GLeeGetProcAddress("glVertexAttrib2f"))!=0) nLinked++;
    if ((pglVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC) __GLeeGetProcAddress("glVertexAttrib2fv"))!=0) nLinked++;
    if ((pglVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC) __GLeeGetProcAddress("glVertexAttrib2s"))!=0) nLinked++;
    if ((pglVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC) __GLeeGetProcAddress("glVertexAttrib2sv"))!=0) nLinked++;
    if ((pglVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC) __GLeeGetProcAddress("glVertexAttrib3d"))!=0) nLinked++;
    if ((pglVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC) __GLeeGetProcAddress("glVertexAttrib3dv"))!=0) nLinked++;
    if ((pglVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC) __GLeeGetProcAddress("glVertexAttrib3f"))!=0) nLinked++;
    if ((pglVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC) __GLeeGetProcAddress("glVertexAttrib3fv"))!=0) nLinked++;
    if ((pglVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC) __GLeeGetProcAddress("glVertexAttrib3s"))!=0) nLinked++;
    if ((pglVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC) __GLeeGetProcAddress("glVertexAttrib3sv"))!=0) nLinked++;
    if ((pglVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC) __GLeeGetProcAddress("glVertexAttrib4Nbv"))!=0) nLinked++;
    if ((pglVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC) __GLeeGetProcAddress("glVertexAttrib4Niv"))!=0) nLinked++;
    if ((pglVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC) __GLeeGetProcAddress("glVertexAttrib4Nsv"))!=0) nLinked++;
    if ((pglVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC) __GLeeGetProcAddress("glVertexAttrib4Nub"))!=0) nLinked++;
    if ((pglVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC) __GLeeGetProcAddress("glVertexAttrib4Nubv"))!=0) nLinked++;
    if ((pglVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC) __GLeeGetProcAddress("glVertexAttrib4Nuiv"))!=0) nLinked++;
    if ((pglVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC) __GLeeGetProcAddress("glVertexAttrib4Nusv"))!=0) nLinked++;
    if ((pglVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC) __GLeeGetProcAddress("glVertexAttrib4bv"))!=0) nLinked++;
    if ((pglVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC) __GLeeGetProcAddress("glVertexAttrib4d"))!=0) nLinked++;
    if ((pglVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC) __GLeeGetProcAddress("glVertexAttrib4dv"))!=0) nLinked++;
    if ((pglVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC) __GLeeGetProcAddress("glVertexAttrib4f"))!=0) nLinked++;
    if ((pglVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC) __GLeeGetProcAddress("glVertexAttrib4fv"))!=0) nLinked++;
    if ((pglVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC) __GLeeGetProcAddress("glVertexAttrib4iv"))!=0) nLinked++;
    if ((pglVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC) __GLeeGetProcAddress("glVertexAttrib4s"))!=0) nLinked++;
    if ((pglVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC) __GLeeGetProcAddress("glVertexAttrib4sv"))!=0) nLinked++;
    if ((pglVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC) __GLeeGetProcAddress("glVertexAttrib4ubv"))!=0) nLinked++;
    if ((pglVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC) __GLeeGetProcAddress("glVertexAttrib4uiv"))!=0) nLinked++;
    if ((pglVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC) __GLeeGetProcAddress("glVertexAttrib4usv"))!=0) nLinked++;
    if ((pglVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC) __GLeeGetProcAddress("glVertexAttribPointer"))!=0) nLinked++;
#endif
    if (nLinked==93) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_VERSION_2_1(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_VERSION_2_1
    if ((pglUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) __GLeeGetProcAddress("glUniformMatrix2x3fv"))!=0) nLinked++;
    if ((pglUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC) __GLeeGetProcAddress("glUniformMatrix3x2fv"))!=0) nLinked++;
    if ((pglUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC) __GLeeGetProcAddress("glUniformMatrix2x4fv"))!=0) nLinked++;
    if ((pglUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC) __GLeeGetProcAddress("glUniformMatrix4x2fv"))!=0) nLinked++;
    if ((pglUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC) __GLeeGetProcAddress("glUniformMatrix3x4fv"))!=0) nLinked++;
    if ((pglUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC) __GLeeGetProcAddress("glUniformMatrix4x3fv"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_multitexture(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_multitexture
    if ((pglActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC) __GLeeGetProcAddress("glActiveTextureARB"))!=0) nLinked++;
    if ((pglClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC) __GLeeGetProcAddress("glClientActiveTextureARB"))!=0) nLinked++;
    if ((pglMultiTexCoord1dARB = (PFNGLMULTITEXCOORD1DARBPROC) __GLeeGetProcAddress("glMultiTexCoord1dARB"))!=0) nLinked++;
    if ((pglMultiTexCoord1dvARB = (PFNGLMULTITEXCOORD1DVARBPROC) __GLeeGetProcAddress("glMultiTexCoord1dvARB"))!=0) nLinked++;
    if ((pglMultiTexCoord1fARB = (PFNGLMULTITEXCOORD1FARBPROC) __GLeeGetProcAddress("glMultiTexCoord1fARB"))!=0) nLinked++;
    if ((pglMultiTexCoord1fvARB = (PFNGLMULTITEXCOORD1FVARBPROC) __GLeeGetProcAddress("glMultiTexCoord1fvARB"))!=0) nLinked++;
    if ((pglMultiTexCoord1iARB = (PFNGLMULTITEXCOORD1IARBPROC) __GLeeGetProcAddress("glMultiTexCoord1iARB"))!=0) nLinked++;
    if ((pglMultiTexCoord1ivARB = (PFNGLMULTITEXCOORD1IVARBPROC) __GLeeGetProcAddress("glMultiTexCoord1ivARB"))!=0) nLinked++;
    if ((pglMultiTexCoord1sARB = (PFNGLMULTITEXCOORD1SARBPROC) __GLeeGetProcAddress("glMultiTexCoord1sARB"))!=0) nLinked++;
    if ((pglMultiTexCoord1svARB = (PFNGLMULTITEXCOORD1SVARBPROC) __GLeeGetProcAddress("glMultiTexCoord1svARB"))!=0) nLinked++;
    if ((pglMultiTexCoord2dARB = (PFNGLMULTITEXCOORD2DARBPROC) __GLeeGetProcAddress("glMultiTexCoord2dARB"))!=0) nLinked++;
    if ((pglMultiTexCoord2dvARB = (PFNGLMULTITEXCOORD2DVARBPROC) __GLeeGetProcAddress("glMultiTexCoord2dvARB"))!=0) nLinked++;
    if ((pglMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC) __GLeeGetProcAddress("glMultiTexCoord2fARB"))!=0) nLinked++;
    if ((pglMultiTexCoord2fvARB = (PFNGLMULTITEXCOORD2FVARBPROC) __GLeeGetProcAddress("glMultiTexCoord2fvARB"))!=0) nLinked++;
    if ((pglMultiTexCoord2iARB = (PFNGLMULTITEXCOORD2IARBPROC) __GLeeGetProcAddress("glMultiTexCoord2iARB"))!=0) nLinked++;
    if ((pglMultiTexCoord2ivARB = (PFNGLMULTITEXCOORD2IVARBPROC) __GLeeGetProcAddress("glMultiTexCoord2ivARB"))!=0) nLinked++;
    if ((pglMultiTexCoord2sARB = (PFNGLMULTITEXCOORD2SARBPROC) __GLeeGetProcAddress("glMultiTexCoord2sARB"))!=0) nLinked++;
    if ((pglMultiTexCoord2svARB = (PFNGLMULTITEXCOORD2SVARBPROC) __GLeeGetProcAddress("glMultiTexCoord2svARB"))!=0) nLinked++;
    if ((pglMultiTexCoord3dARB = (PFNGLMULTITEXCOORD3DARBPROC) __GLeeGetProcAddress("glMultiTexCoord3dARB"))!=0) nLinked++;
    if ((pglMultiTexCoord3dvARB = (PFNGLMULTITEXCOORD3DVARBPROC) __GLeeGetProcAddress("glMultiTexCoord3dvARB"))!=0) nLinked++;
    if ((pglMultiTexCoord3fARB = (PFNGLMULTITEXCOORD3FARBPROC) __GLeeGetProcAddress("glMultiTexCoord3fARB"))!=0) nLinked++;
    if ((pglMultiTexCoord3fvARB = (PFNGLMULTITEXCOORD3FVARBPROC) __GLeeGetProcAddress("glMultiTexCoord3fvARB"))!=0) nLinked++;
    if ((pglMultiTexCoord3iARB = (PFNGLMULTITEXCOORD3IARBPROC) __GLeeGetProcAddress("glMultiTexCoord3iARB"))!=0) nLinked++;
    if ((pglMultiTexCoord3ivARB = (PFNGLMULTITEXCOORD3IVARBPROC) __GLeeGetProcAddress("glMultiTexCoord3ivARB"))!=0) nLinked++;
    if ((pglMultiTexCoord3sARB = (PFNGLMULTITEXCOORD3SARBPROC) __GLeeGetProcAddress("glMultiTexCoord3sARB"))!=0) nLinked++;
    if ((pglMultiTexCoord3svARB = (PFNGLMULTITEXCOORD3SVARBPROC) __GLeeGetProcAddress("glMultiTexCoord3svARB"))!=0) nLinked++;
    if ((pglMultiTexCoord4dARB = (PFNGLMULTITEXCOORD4DARBPROC) __GLeeGetProcAddress("glMultiTexCoord4dARB"))!=0) nLinked++;
    if ((pglMultiTexCoord4dvARB = (PFNGLMULTITEXCOORD4DVARBPROC) __GLeeGetProcAddress("glMultiTexCoord4dvARB"))!=0) nLinked++;
    if ((pglMultiTexCoord4fARB = (PFNGLMULTITEXCOORD4FARBPROC) __GLeeGetProcAddress("glMultiTexCoord4fARB"))!=0) nLinked++;
    if ((pglMultiTexCoord4fvARB = (PFNGLMULTITEXCOORD4FVARBPROC) __GLeeGetProcAddress("glMultiTexCoord4fvARB"))!=0) nLinked++;
    if ((pglMultiTexCoord4iARB = (PFNGLMULTITEXCOORD4IARBPROC) __GLeeGetProcAddress("glMultiTexCoord4iARB"))!=0) nLinked++;
    if ((pglMultiTexCoord4ivARB = (PFNGLMULTITEXCOORD4IVARBPROC) __GLeeGetProcAddress("glMultiTexCoord4ivARB"))!=0) nLinked++;
    if ((pglMultiTexCoord4sARB = (PFNGLMULTITEXCOORD4SARBPROC) __GLeeGetProcAddress("glMultiTexCoord4sARB"))!=0) nLinked++;
    if ((pglMultiTexCoord4svARB = (PFNGLMULTITEXCOORD4SVARBPROC) __GLeeGetProcAddress("glMultiTexCoord4svARB"))!=0) nLinked++;
#endif
    if (nLinked==34) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_transpose_matrix(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_transpose_matrix
    if ((pglLoadTransposeMatrixfARB = (PFNGLLOADTRANSPOSEMATRIXFARBPROC) __GLeeGetProcAddress("glLoadTransposeMatrixfARB"))!=0) nLinked++;
    if ((pglLoadTransposeMatrixdARB = (PFNGLLOADTRANSPOSEMATRIXDARBPROC) __GLeeGetProcAddress("glLoadTransposeMatrixdARB"))!=0) nLinked++;
    if ((pglMultTransposeMatrixfARB = (PFNGLMULTTRANSPOSEMATRIXFARBPROC) __GLeeGetProcAddress("glMultTransposeMatrixfARB"))!=0) nLinked++;
    if ((pglMultTransposeMatrixdARB = (PFNGLMULTTRANSPOSEMATRIXDARBPROC) __GLeeGetProcAddress("glMultTransposeMatrixdARB"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_multisample(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_multisample
    if ((pglSampleCoverageARB = (PFNGLSAMPLECOVERAGEARBPROC) __GLeeGetProcAddress("glSampleCoverageARB"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_texture_env_add(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_texture_cube_map(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_texture_compression(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_texture_compression
    if ((pglCompressedTexImage3DARB = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC) __GLeeGetProcAddress("glCompressedTexImage3DARB"))!=0) nLinked++;
    if ((pglCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC) __GLeeGetProcAddress("glCompressedTexImage2DARB"))!=0) nLinked++;
    if ((pglCompressedTexImage1DARB = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC) __GLeeGetProcAddress("glCompressedTexImage1DARB"))!=0) nLinked++;
    if ((pglCompressedTexSubImage3DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC) __GLeeGetProcAddress("glCompressedTexSubImage3DARB"))!=0) nLinked++;
    if ((pglCompressedTexSubImage2DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC) __GLeeGetProcAddress("glCompressedTexSubImage2DARB"))!=0) nLinked++;
    if ((pglCompressedTexSubImage1DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC) __GLeeGetProcAddress("glCompressedTexSubImage1DARB"))!=0) nLinked++;
    if ((pglGetCompressedTexImageARB = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC) __GLeeGetProcAddress("glGetCompressedTexImageARB"))!=0) nLinked++;
#endif
    if (nLinked==7) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_texture_border_clamp(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_point_parameters(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_point_parameters
    if ((pglPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC) __GLeeGetProcAddress("glPointParameterfARB"))!=0) nLinked++;
    if ((pglPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC) __GLeeGetProcAddress("glPointParameterfvARB"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_vertex_blend(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_vertex_blend
    if ((pglWeightbvARB = (PFNGLWEIGHTBVARBPROC) __GLeeGetProcAddress("glWeightbvARB"))!=0) nLinked++;
    if ((pglWeightsvARB = (PFNGLWEIGHTSVARBPROC) __GLeeGetProcAddress("glWeightsvARB"))!=0) nLinked++;
    if ((pglWeightivARB = (PFNGLWEIGHTIVARBPROC) __GLeeGetProcAddress("glWeightivARB"))!=0) nLinked++;
    if ((pglWeightfvARB = (PFNGLWEIGHTFVARBPROC) __GLeeGetProcAddress("glWeightfvARB"))!=0) nLinked++;
    if ((pglWeightdvARB = (PFNGLWEIGHTDVARBPROC) __GLeeGetProcAddress("glWeightdvARB"))!=0) nLinked++;
    if ((pglWeightubvARB = (PFNGLWEIGHTUBVARBPROC) __GLeeGetProcAddress("glWeightubvARB"))!=0) nLinked++;
    if ((pglWeightusvARB = (PFNGLWEIGHTUSVARBPROC) __GLeeGetProcAddress("glWeightusvARB"))!=0) nLinked++;
    if ((pglWeightuivARB = (PFNGLWEIGHTUIVARBPROC) __GLeeGetProcAddress("glWeightuivARB"))!=0) nLinked++;
    if ((pglWeightPointerARB = (PFNGLWEIGHTPOINTERARBPROC) __GLeeGetProcAddress("glWeightPointerARB"))!=0) nLinked++;
    if ((pglVertexBlendARB = (PFNGLVERTEXBLENDARBPROC) __GLeeGetProcAddress("glVertexBlendARB"))!=0) nLinked++;
#endif
    if (nLinked==10) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_matrix_palette(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_matrix_palette
    if ((pglCurrentPaletteMatrixARB = (PFNGLCURRENTPALETTEMATRIXARBPROC) __GLeeGetProcAddress("glCurrentPaletteMatrixARB"))!=0) nLinked++;
    if ((pglMatrixIndexubvARB = (PFNGLMATRIXINDEXUBVARBPROC) __GLeeGetProcAddress("glMatrixIndexubvARB"))!=0) nLinked++;
    if ((pglMatrixIndexusvARB = (PFNGLMATRIXINDEXUSVARBPROC) __GLeeGetProcAddress("glMatrixIndexusvARB"))!=0) nLinked++;
    if ((pglMatrixIndexuivARB = (PFNGLMATRIXINDEXUIVARBPROC) __GLeeGetProcAddress("glMatrixIndexuivARB"))!=0) nLinked++;
    if ((pglMatrixIndexPointerARB = (PFNGLMATRIXINDEXPOINTERARBPROC) __GLeeGetProcAddress("glMatrixIndexPointerARB"))!=0) nLinked++;
#endif
    if (nLinked==5) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_texture_env_combine(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_texture_env_crossbar(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_texture_env_dot3(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_texture_mirrored_repeat(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_depth_texture(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_shadow(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_shadow_ambient(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_window_pos(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_window_pos
    if ((pglWindowPos2dARB = (PFNGLWINDOWPOS2DARBPROC) __GLeeGetProcAddress("glWindowPos2dARB"))!=0) nLinked++;
    if ((pglWindowPos2dvARB = (PFNGLWINDOWPOS2DVARBPROC) __GLeeGetProcAddress("glWindowPos2dvARB"))!=0) nLinked++;
    if ((pglWindowPos2fARB = (PFNGLWINDOWPOS2FARBPROC) __GLeeGetProcAddress("glWindowPos2fARB"))!=0) nLinked++;
    if ((pglWindowPos2fvARB = (PFNGLWINDOWPOS2FVARBPROC) __GLeeGetProcAddress("glWindowPos2fvARB"))!=0) nLinked++;
    if ((pglWindowPos2iARB = (PFNGLWINDOWPOS2IARBPROC) __GLeeGetProcAddress("glWindowPos2iARB"))!=0) nLinked++;
    if ((pglWindowPos2ivARB = (PFNGLWINDOWPOS2IVARBPROC) __GLeeGetProcAddress("glWindowPos2ivARB"))!=0) nLinked++;
    if ((pglWindowPos2sARB = (PFNGLWINDOWPOS2SARBPROC) __GLeeGetProcAddress("glWindowPos2sARB"))!=0) nLinked++;
    if ((pglWindowPos2svARB = (PFNGLWINDOWPOS2SVARBPROC) __GLeeGetProcAddress("glWindowPos2svARB"))!=0) nLinked++;
    if ((pglWindowPos3dARB = (PFNGLWINDOWPOS3DARBPROC) __GLeeGetProcAddress("glWindowPos3dARB"))!=0) nLinked++;
    if ((pglWindowPos3dvARB = (PFNGLWINDOWPOS3DVARBPROC) __GLeeGetProcAddress("glWindowPos3dvARB"))!=0) nLinked++;
    if ((pglWindowPos3fARB = (PFNGLWINDOWPOS3FARBPROC) __GLeeGetProcAddress("glWindowPos3fARB"))!=0) nLinked++;
    if ((pglWindowPos3fvARB = (PFNGLWINDOWPOS3FVARBPROC) __GLeeGetProcAddress("glWindowPos3fvARB"))!=0) nLinked++;
    if ((pglWindowPos3iARB = (PFNGLWINDOWPOS3IARBPROC) __GLeeGetProcAddress("glWindowPos3iARB"))!=0) nLinked++;
    if ((pglWindowPos3ivARB = (PFNGLWINDOWPOS3IVARBPROC) __GLeeGetProcAddress("glWindowPos3ivARB"))!=0) nLinked++;
    if ((pglWindowPos3sARB = (PFNGLWINDOWPOS3SARBPROC) __GLeeGetProcAddress("glWindowPos3sARB"))!=0) nLinked++;
    if ((pglWindowPos3svARB = (PFNGLWINDOWPOS3SVARBPROC) __GLeeGetProcAddress("glWindowPos3svARB"))!=0) nLinked++;
#endif
    if (nLinked==16) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_vertex_program(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_vertex_program
    if ((pglVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC) __GLeeGetProcAddress("glVertexAttrib1dARB"))!=0) nLinked++;
    if ((pglVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC) __GLeeGetProcAddress("glVertexAttrib1dvARB"))!=0) nLinked++;
    if ((pglVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC) __GLeeGetProcAddress("glVertexAttrib1fARB"))!=0) nLinked++;
    if ((pglVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC) __GLeeGetProcAddress("glVertexAttrib1fvARB"))!=0) nLinked++;
    if ((pglVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC) __GLeeGetProcAddress("glVertexAttrib1sARB"))!=0) nLinked++;
    if ((pglVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC) __GLeeGetProcAddress("glVertexAttrib1svARB"))!=0) nLinked++;
    if ((pglVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC) __GLeeGetProcAddress("glVertexAttrib2dARB"))!=0) nLinked++;
    if ((pglVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC) __GLeeGetProcAddress("glVertexAttrib2dvARB"))!=0) nLinked++;
    if ((pglVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC) __GLeeGetProcAddress("glVertexAttrib2fARB"))!=0) nLinked++;
    if ((pglVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC) __GLeeGetProcAddress("glVertexAttrib2fvARB"))!=0) nLinked++;
    if ((pglVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC) __GLeeGetProcAddress("glVertexAttrib2sARB"))!=0) nLinked++;
    if ((pglVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC) __GLeeGetProcAddress("glVertexAttrib2svARB"))!=0) nLinked++;
    if ((pglVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC) __GLeeGetProcAddress("glVertexAttrib3dARB"))!=0) nLinked++;
    if ((pglVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC) __GLeeGetProcAddress("glVertexAttrib3dvARB"))!=0) nLinked++;
    if ((pglVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC) __GLeeGetProcAddress("glVertexAttrib3fARB"))!=0) nLinked++;
    if ((pglVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC) __GLeeGetProcAddress("glVertexAttrib3fvARB"))!=0) nLinked++;
    if ((pglVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC) __GLeeGetProcAddress("glVertexAttrib3sARB"))!=0) nLinked++;
    if ((pglVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC) __GLeeGetProcAddress("glVertexAttrib3svARB"))!=0) nLinked++;
    if ((pglVertexAttrib4NbvARB = (PFNGLVERTEXATTRIB4NBVARBPROC) __GLeeGetProcAddress("glVertexAttrib4NbvARB"))!=0) nLinked++;
    if ((pglVertexAttrib4NivARB = (PFNGLVERTEXATTRIB4NIVARBPROC) __GLeeGetProcAddress("glVertexAttrib4NivARB"))!=0) nLinked++;
    if ((pglVertexAttrib4NsvARB = (PFNGLVERTEXATTRIB4NSVARBPROC) __GLeeGetProcAddress("glVertexAttrib4NsvARB"))!=0) nLinked++;
    if ((pglVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC) __GLeeGetProcAddress("glVertexAttrib4NubARB"))!=0) nLinked++;
    if ((pglVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC) __GLeeGetProcAddress("glVertexAttrib4NubvARB"))!=0) nLinked++;
    if ((pglVertexAttrib4NuivARB = (PFNGLVERTEXATTRIB4NUIVARBPROC) __GLeeGetProcAddress("glVertexAttrib4NuivARB"))!=0) nLinked++;
    if ((pglVertexAttrib4NusvARB = (PFNGLVERTEXATTRIB4NUSVARBPROC) __GLeeGetProcAddress("glVertexAttrib4NusvARB"))!=0) nLinked++;
    if ((pglVertexAttrib4bvARB = (PFNGLVERTEXATTRIB4BVARBPROC) __GLeeGetProcAddress("glVertexAttrib4bvARB"))!=0) nLinked++;
    if ((pglVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC) __GLeeGetProcAddress("glVertexAttrib4dARB"))!=0) nLinked++;
    if ((pglVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC) __GLeeGetProcAddress("glVertexAttrib4dvARB"))!=0) nLinked++;
    if ((pglVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC) __GLeeGetProcAddress("glVertexAttrib4fARB"))!=0) nLinked++;
    if ((pglVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC) __GLeeGetProcAddress("glVertexAttrib4fvARB"))!=0) nLinked++;
    if ((pglVertexAttrib4ivARB = (PFNGLVERTEXATTRIB4IVARBPROC) __GLeeGetProcAddress("glVertexAttrib4ivARB"))!=0) nLinked++;
    if ((pglVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC) __GLeeGetProcAddress("glVertexAttrib4sARB"))!=0) nLinked++;
    if ((pglVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC) __GLeeGetProcAddress("glVertexAttrib4svARB"))!=0) nLinked++;
    if ((pglVertexAttrib4ubvARB = (PFNGLVERTEXATTRIB4UBVARBPROC) __GLeeGetProcAddress("glVertexAttrib4ubvARB"))!=0) nLinked++;
    if ((pglVertexAttrib4uivARB = (PFNGLVERTEXATTRIB4UIVARBPROC) __GLeeGetProcAddress("glVertexAttrib4uivARB"))!=0) nLinked++;
    if ((pglVertexAttrib4usvARB = (PFNGLVERTEXATTRIB4USVARBPROC) __GLeeGetProcAddress("glVertexAttrib4usvARB"))!=0) nLinked++;
    if ((pglVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC) __GLeeGetProcAddress("glVertexAttribPointerARB"))!=0) nLinked++;
    if ((pglEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC) __GLeeGetProcAddress("glEnableVertexAttribArrayARB"))!=0) nLinked++;
    if ((pglDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC) __GLeeGetProcAddress("glDisableVertexAttribArrayARB"))!=0) nLinked++;
    if ((pglProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC) __GLeeGetProcAddress("glProgramStringARB"))!=0) nLinked++;
    if ((pglBindProgramARB = (PFNGLBINDPROGRAMARBPROC) __GLeeGetProcAddress("glBindProgramARB"))!=0) nLinked++;
    if ((pglDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC) __GLeeGetProcAddress("glDeleteProgramsARB"))!=0) nLinked++;
    if ((pglGenProgramsARB = (PFNGLGENPROGRAMSARBPROC) __GLeeGetProcAddress("glGenProgramsARB"))!=0) nLinked++;
    if ((pglProgramEnvParameter4dARB = (PFNGLPROGRAMENVPARAMETER4DARBPROC) __GLeeGetProcAddress("glProgramEnvParameter4dARB"))!=0) nLinked++;
    if ((pglProgramEnvParameter4dvARB = (PFNGLPROGRAMENVPARAMETER4DVARBPROC) __GLeeGetProcAddress("glProgramEnvParameter4dvARB"))!=0) nLinked++;
    if ((pglProgramEnvParameter4fARB = (PFNGLPROGRAMENVPARAMETER4FARBPROC) __GLeeGetProcAddress("glProgramEnvParameter4fARB"))!=0) nLinked++;
    if ((pglProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC) __GLeeGetProcAddress("glProgramEnvParameter4fvARB"))!=0) nLinked++;
    if ((pglProgramLocalParameter4dARB = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC) __GLeeGetProcAddress("glProgramLocalParameter4dARB"))!=0) nLinked++;
    if ((pglProgramLocalParameter4dvARB = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC) __GLeeGetProcAddress("glProgramLocalParameter4dvARB"))!=0) nLinked++;
    if ((pglProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC) __GLeeGetProcAddress("glProgramLocalParameter4fARB"))!=0) nLinked++;
    if ((pglProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC) __GLeeGetProcAddress("glProgramLocalParameter4fvARB"))!=0) nLinked++;
    if ((pglGetProgramEnvParameterdvARB = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC) __GLeeGetProcAddress("glGetProgramEnvParameterdvARB"))!=0) nLinked++;
    if ((pglGetProgramEnvParameterfvARB = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC) __GLeeGetProcAddress("glGetProgramEnvParameterfvARB"))!=0) nLinked++;
    if ((pglGetProgramLocalParameterdvARB = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC) __GLeeGetProcAddress("glGetProgramLocalParameterdvARB"))!=0) nLinked++;
    if ((pglGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC) __GLeeGetProcAddress("glGetProgramLocalParameterfvARB"))!=0) nLinked++;
    if ((pglGetProgramivARB = (PFNGLGETPROGRAMIVARBPROC) __GLeeGetProcAddress("glGetProgramivARB"))!=0) nLinked++;
    if ((pglGetProgramStringARB = (PFNGLGETPROGRAMSTRINGARBPROC) __GLeeGetProcAddress("glGetProgramStringARB"))!=0) nLinked++;
    if ((pglGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC) __GLeeGetProcAddress("glGetVertexAttribdvARB"))!=0) nLinked++;
    if ((pglGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC) __GLeeGetProcAddress("glGetVertexAttribfvARB"))!=0) nLinked++;
    if ((pglGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC) __GLeeGetProcAddress("glGetVertexAttribivARB"))!=0) nLinked++;
    if ((pglGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC) __GLeeGetProcAddress("glGetVertexAttribPointervARB"))!=0) nLinked++;
    if ((pglIsProgramARB = (PFNGLISPROGRAMARBPROC) __GLeeGetProcAddress("glIsProgramARB"))!=0) nLinked++;
#endif
    if (nLinked==62) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_fragment_program(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_vertex_buffer_object(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_vertex_buffer_object
    if ((pglBindBufferARB = (PFNGLBINDBUFFERARBPROC) __GLeeGetProcAddress("glBindBufferARB"))!=0) nLinked++;
    if ((pglDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC) __GLeeGetProcAddress("glDeleteBuffersARB"))!=0) nLinked++;
    if ((pglGenBuffersARB = (PFNGLGENBUFFERSARBPROC) __GLeeGetProcAddress("glGenBuffersARB"))!=0) nLinked++;
    if ((pglIsBufferARB = (PFNGLISBUFFERARBPROC) __GLeeGetProcAddress("glIsBufferARB"))!=0) nLinked++;
    if ((pglBufferDataARB = (PFNGLBUFFERDATAARBPROC) __GLeeGetProcAddress("glBufferDataARB"))!=0) nLinked++;
    if ((pglBufferSubDataARB = (PFNGLBUFFERSUBDATAARBPROC) __GLeeGetProcAddress("glBufferSubDataARB"))!=0) nLinked++;
    if ((pglGetBufferSubDataARB = (PFNGLGETBUFFERSUBDATAARBPROC) __GLeeGetProcAddress("glGetBufferSubDataARB"))!=0) nLinked++;
    if ((pglMapBufferARB = (PFNGLMAPBUFFERARBPROC) __GLeeGetProcAddress("glMapBufferARB"))!=0) nLinked++;
    if ((pglUnmapBufferARB = (PFNGLUNMAPBUFFERARBPROC) __GLeeGetProcAddress("glUnmapBufferARB"))!=0) nLinked++;
    if ((pglGetBufferParameterivARB = (PFNGLGETBUFFERPARAMETERIVARBPROC) __GLeeGetProcAddress("glGetBufferParameterivARB"))!=0) nLinked++;
    if ((pglGetBufferPointervARB = (PFNGLGETBUFFERPOINTERVARBPROC) __GLeeGetProcAddress("glGetBufferPointervARB"))!=0) nLinked++;
#endif
    if (nLinked==11) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_occlusion_query(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_occlusion_query
    if ((pglGenQueriesARB = (PFNGLGENQUERIESARBPROC) __GLeeGetProcAddress("glGenQueriesARB"))!=0) nLinked++;
    if ((pglDeleteQueriesARB = (PFNGLDELETEQUERIESARBPROC) __GLeeGetProcAddress("glDeleteQueriesARB"))!=0) nLinked++;
    if ((pglIsQueryARB = (PFNGLISQUERYARBPROC) __GLeeGetProcAddress("glIsQueryARB"))!=0) nLinked++;
    if ((pglBeginQueryARB = (PFNGLBEGINQUERYARBPROC) __GLeeGetProcAddress("glBeginQueryARB"))!=0) nLinked++;
    if ((pglEndQueryARB = (PFNGLENDQUERYARBPROC) __GLeeGetProcAddress("glEndQueryARB"))!=0) nLinked++;
    if ((pglGetQueryivARB = (PFNGLGETQUERYIVARBPROC) __GLeeGetProcAddress("glGetQueryivARB"))!=0) nLinked++;
    if ((pglGetQueryObjectivARB = (PFNGLGETQUERYOBJECTIVARBPROC) __GLeeGetProcAddress("glGetQueryObjectivARB"))!=0) nLinked++;
    if ((pglGetQueryObjectuivARB = (PFNGLGETQUERYOBJECTUIVARBPROC) __GLeeGetProcAddress("glGetQueryObjectuivARB"))!=0) nLinked++;
#endif
    if (nLinked==8) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_shader_objects(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_shader_objects
    if ((pglDeleteObjectARB = (PFNGLDELETEOBJECTARBPROC) __GLeeGetProcAddress("glDeleteObjectARB"))!=0) nLinked++;
    if ((pglGetHandleARB = (PFNGLGETHANDLEARBPROC) __GLeeGetProcAddress("glGetHandleARB"))!=0) nLinked++;
    if ((pglDetachObjectARB = (PFNGLDETACHOBJECTARBPROC) __GLeeGetProcAddress("glDetachObjectARB"))!=0) nLinked++;
    if ((pglCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC) __GLeeGetProcAddress("glCreateShaderObjectARB"))!=0) nLinked++;
    if ((pglShaderSourceARB = (PFNGLSHADERSOURCEARBPROC) __GLeeGetProcAddress("glShaderSourceARB"))!=0) nLinked++;
    if ((pglCompileShaderARB = (PFNGLCOMPILESHADERARBPROC) __GLeeGetProcAddress("glCompileShaderARB"))!=0) nLinked++;
    if ((pglCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC) __GLeeGetProcAddress("glCreateProgramObjectARB"))!=0) nLinked++;
    if ((pglAttachObjectARB = (PFNGLATTACHOBJECTARBPROC) __GLeeGetProcAddress("glAttachObjectARB"))!=0) nLinked++;
    if ((pglLinkProgramARB = (PFNGLLINKPROGRAMARBPROC) __GLeeGetProcAddress("glLinkProgramARB"))!=0) nLinked++;
    if ((pglUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC) __GLeeGetProcAddress("glUseProgramObjectARB"))!=0) nLinked++;
    if ((pglValidateProgramARB = (PFNGLVALIDATEPROGRAMARBPROC) __GLeeGetProcAddress("glValidateProgramARB"))!=0) nLinked++;
    if ((pglUniform1fARB = (PFNGLUNIFORM1FARBPROC) __GLeeGetProcAddress("glUniform1fARB"))!=0) nLinked++;
    if ((pglUniform2fARB = (PFNGLUNIFORM2FARBPROC) __GLeeGetProcAddress("glUniform2fARB"))!=0) nLinked++;
    if ((pglUniform3fARB = (PFNGLUNIFORM3FARBPROC) __GLeeGetProcAddress("glUniform3fARB"))!=0) nLinked++;
    if ((pglUniform4fARB = (PFNGLUNIFORM4FARBPROC) __GLeeGetProcAddress("glUniform4fARB"))!=0) nLinked++;
    if ((pglUniform1iARB = (PFNGLUNIFORM1IARBPROC) __GLeeGetProcAddress("glUniform1iARB"))!=0) nLinked++;
    if ((pglUniform2iARB = (PFNGLUNIFORM2IARBPROC) __GLeeGetProcAddress("glUniform2iARB"))!=0) nLinked++;
    if ((pglUniform3iARB = (PFNGLUNIFORM3IARBPROC) __GLeeGetProcAddress("glUniform3iARB"))!=0) nLinked++;
    if ((pglUniform4iARB = (PFNGLUNIFORM4IARBPROC) __GLeeGetProcAddress("glUniform4iARB"))!=0) nLinked++;
    if ((pglUniform1fvARB = (PFNGLUNIFORM1FVARBPROC) __GLeeGetProcAddress("glUniform1fvARB"))!=0) nLinked++;
    if ((pglUniform2fvARB = (PFNGLUNIFORM2FVARBPROC) __GLeeGetProcAddress("glUniform2fvARB"))!=0) nLinked++;
    if ((pglUniform3fvARB = (PFNGLUNIFORM3FVARBPROC) __GLeeGetProcAddress("glUniform3fvARB"))!=0) nLinked++;
    if ((pglUniform4fvARB = (PFNGLUNIFORM4FVARBPROC) __GLeeGetProcAddress("glUniform4fvARB"))!=0) nLinked++;
    if ((pglUniform1ivARB = (PFNGLUNIFORM1IVARBPROC) __GLeeGetProcAddress("glUniform1ivARB"))!=0) nLinked++;
    if ((pglUniform2ivARB = (PFNGLUNIFORM2IVARBPROC) __GLeeGetProcAddress("glUniform2ivARB"))!=0) nLinked++;
    if ((pglUniform3ivARB = (PFNGLUNIFORM3IVARBPROC) __GLeeGetProcAddress("glUniform3ivARB"))!=0) nLinked++;
    if ((pglUniform4ivARB = (PFNGLUNIFORM4IVARBPROC) __GLeeGetProcAddress("glUniform4ivARB"))!=0) nLinked++;
    if ((pglUniformMatrix2fvARB = (PFNGLUNIFORMMATRIX2FVARBPROC) __GLeeGetProcAddress("glUniformMatrix2fvARB"))!=0) nLinked++;
    if ((pglUniformMatrix3fvARB = (PFNGLUNIFORMMATRIX3FVARBPROC) __GLeeGetProcAddress("glUniformMatrix3fvARB"))!=0) nLinked++;
    if ((pglUniformMatrix4fvARB = (PFNGLUNIFORMMATRIX4FVARBPROC) __GLeeGetProcAddress("glUniformMatrix4fvARB"))!=0) nLinked++;
    if ((pglGetObjectParameterfvARB = (PFNGLGETOBJECTPARAMETERFVARBPROC) __GLeeGetProcAddress("glGetObjectParameterfvARB"))!=0) nLinked++;
    if ((pglGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC) __GLeeGetProcAddress("glGetObjectParameterivARB"))!=0) nLinked++;
    if ((pglGetInfoLogARB = (PFNGLGETINFOLOGARBPROC) __GLeeGetProcAddress("glGetInfoLogARB"))!=0) nLinked++;
    if ((pglGetAttachedObjectsARB = (PFNGLGETATTACHEDOBJECTSARBPROC) __GLeeGetProcAddress("glGetAttachedObjectsARB"))!=0) nLinked++;
    if ((pglGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC) __GLeeGetProcAddress("glGetUniformLocationARB"))!=0) nLinked++;
    if ((pglGetActiveUniformARB = (PFNGLGETACTIVEUNIFORMARBPROC) __GLeeGetProcAddress("glGetActiveUniformARB"))!=0) nLinked++;
    if ((pglGetUniformfvARB = (PFNGLGETUNIFORMFVARBPROC) __GLeeGetProcAddress("glGetUniformfvARB"))!=0) nLinked++;
    if ((pglGetUniformivARB = (PFNGLGETUNIFORMIVARBPROC) __GLeeGetProcAddress("glGetUniformivARB"))!=0) nLinked++;
    if ((pglGetShaderSourceARB = (PFNGLGETSHADERSOURCEARBPROC) __GLeeGetProcAddress("glGetShaderSourceARB"))!=0) nLinked++;
#endif
    if (nLinked==39) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_vertex_shader(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_vertex_shader
    if ((pglBindAttribLocationARB = (PFNGLBINDATTRIBLOCATIONARBPROC) __GLeeGetProcAddress("glBindAttribLocationARB"))!=0) nLinked++;
    if ((pglGetActiveAttribARB = (PFNGLGETACTIVEATTRIBARBPROC) __GLeeGetProcAddress("glGetActiveAttribARB"))!=0) nLinked++;
    if ((pglGetAttribLocationARB = (PFNGLGETATTRIBLOCATIONARBPROC) __GLeeGetProcAddress("glGetAttribLocationARB"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_fragment_shader(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_shading_language_100(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_texture_non_power_of_two(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_point_sprite(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_fragment_program_shadow(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_draw_buffers(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_draw_buffers
    if ((pglDrawBuffersARB = (PFNGLDRAWBUFFERSARBPROC) __GLeeGetProcAddress("glDrawBuffersARB"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_texture_rectangle(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_color_buffer_float(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ARB_color_buffer_float
    if ((pglClampColorARB = (PFNGLCLAMPCOLORARBPROC) __GLeeGetProcAddress("glClampColorARB"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ARB_half_float_pixel(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_texture_float(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ARB_pixel_buffer_object(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_abgr(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_blend_color(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_blend_color
    if ((pglBlendColorEXT = (PFNGLBLENDCOLOREXTPROC) __GLeeGetProcAddress("glBlendColorEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_polygon_offset(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_polygon_offset
    if ((pglPolygonOffsetEXT = (PFNGLPOLYGONOFFSETEXTPROC) __GLeeGetProcAddress("glPolygonOffsetEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_texture(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture3D(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_texture3D
    if ((pglTexImage3DEXT = (PFNGLTEXIMAGE3DEXTPROC) __GLeeGetProcAddress("glTexImage3DEXT"))!=0) nLinked++;
    if ((pglTexSubImage3DEXT = (PFNGLTEXSUBIMAGE3DEXTPROC) __GLeeGetProcAddress("glTexSubImage3DEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIS_texture_filter4(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIS_texture_filter4
    if ((pglGetTexFilterFuncSGIS = (PFNGLGETTEXFILTERFUNCSGISPROC) __GLeeGetProcAddress("glGetTexFilterFuncSGIS"))!=0) nLinked++;
    if ((pglTexFilterFuncSGIS = (PFNGLTEXFILTERFUNCSGISPROC) __GLeeGetProcAddress("glTexFilterFuncSGIS"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_subtexture(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_subtexture
    if ((pglTexSubImage1DEXT = (PFNGLTEXSUBIMAGE1DEXTPROC) __GLeeGetProcAddress("glTexSubImage1DEXT"))!=0) nLinked++;
    if ((pglTexSubImage2DEXT = (PFNGLTEXSUBIMAGE2DEXTPROC) __GLeeGetProcAddress("glTexSubImage2DEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_copy_texture(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_copy_texture
    if ((pglCopyTexImage1DEXT = (PFNGLCOPYTEXIMAGE1DEXTPROC) __GLeeGetProcAddress("glCopyTexImage1DEXT"))!=0) nLinked++;
    if ((pglCopyTexImage2DEXT = (PFNGLCOPYTEXIMAGE2DEXTPROC) __GLeeGetProcAddress("glCopyTexImage2DEXT"))!=0) nLinked++;
    if ((pglCopyTexSubImage1DEXT = (PFNGLCOPYTEXSUBIMAGE1DEXTPROC) __GLeeGetProcAddress("glCopyTexSubImage1DEXT"))!=0) nLinked++;
    if ((pglCopyTexSubImage2DEXT = (PFNGLCOPYTEXSUBIMAGE2DEXTPROC) __GLeeGetProcAddress("glCopyTexSubImage2DEXT"))!=0) nLinked++;
    if ((pglCopyTexSubImage3DEXT = (PFNGLCOPYTEXSUBIMAGE3DEXTPROC) __GLeeGetProcAddress("glCopyTexSubImage3DEXT"))!=0) nLinked++;
#endif
    if (nLinked==5) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_histogram(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_histogram
    if ((pglGetHistogramEXT = (PFNGLGETHISTOGRAMEXTPROC) __GLeeGetProcAddress("glGetHistogramEXT"))!=0) nLinked++;
    if ((pglGetHistogramParameterfvEXT = (PFNGLGETHISTOGRAMPARAMETERFVEXTPROC) __GLeeGetProcAddress("glGetHistogramParameterfvEXT"))!=0) nLinked++;
    if ((pglGetHistogramParameterivEXT = (PFNGLGETHISTOGRAMPARAMETERIVEXTPROC) __GLeeGetProcAddress("glGetHistogramParameterivEXT"))!=0) nLinked++;
    if ((pglGetMinmaxEXT = (PFNGLGETMINMAXEXTPROC) __GLeeGetProcAddress("glGetMinmaxEXT"))!=0) nLinked++;
    if ((pglGetMinmaxParameterfvEXT = (PFNGLGETMINMAXPARAMETERFVEXTPROC) __GLeeGetProcAddress("glGetMinmaxParameterfvEXT"))!=0) nLinked++;
    if ((pglGetMinmaxParameterivEXT = (PFNGLGETMINMAXPARAMETERIVEXTPROC) __GLeeGetProcAddress("glGetMinmaxParameterivEXT"))!=0) nLinked++;
    if ((pglHistogramEXT = (PFNGLHISTOGRAMEXTPROC) __GLeeGetProcAddress("glHistogramEXT"))!=0) nLinked++;
    if ((pglMinmaxEXT = (PFNGLMINMAXEXTPROC) __GLeeGetProcAddress("glMinmaxEXT"))!=0) nLinked++;
    if ((pglResetHistogramEXT = (PFNGLRESETHISTOGRAMEXTPROC) __GLeeGetProcAddress("glResetHistogramEXT"))!=0) nLinked++;
    if ((pglResetMinmaxEXT = (PFNGLRESETMINMAXEXTPROC) __GLeeGetProcAddress("glResetMinmaxEXT"))!=0) nLinked++;
#endif
    if (nLinked==10) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_convolution(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_convolution
    if ((pglConvolutionFilter1DEXT = (PFNGLCONVOLUTIONFILTER1DEXTPROC) __GLeeGetProcAddress("glConvolutionFilter1DEXT"))!=0) nLinked++;
    if ((pglConvolutionFilter2DEXT = (PFNGLCONVOLUTIONFILTER2DEXTPROC) __GLeeGetProcAddress("glConvolutionFilter2DEXT"))!=0) nLinked++;
    if ((pglConvolutionParameterfEXT = (PFNGLCONVOLUTIONPARAMETERFEXTPROC) __GLeeGetProcAddress("glConvolutionParameterfEXT"))!=0) nLinked++;
    if ((pglConvolutionParameterfvEXT = (PFNGLCONVOLUTIONPARAMETERFVEXTPROC) __GLeeGetProcAddress("glConvolutionParameterfvEXT"))!=0) nLinked++;
    if ((pglConvolutionParameteriEXT = (PFNGLCONVOLUTIONPARAMETERIEXTPROC) __GLeeGetProcAddress("glConvolutionParameteriEXT"))!=0) nLinked++;
    if ((pglConvolutionParameterivEXT = (PFNGLCONVOLUTIONPARAMETERIVEXTPROC) __GLeeGetProcAddress("glConvolutionParameterivEXT"))!=0) nLinked++;
    if ((pglCopyConvolutionFilter1DEXT = (PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC) __GLeeGetProcAddress("glCopyConvolutionFilter1DEXT"))!=0) nLinked++;
    if ((pglCopyConvolutionFilter2DEXT = (PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC) __GLeeGetProcAddress("glCopyConvolutionFilter2DEXT"))!=0) nLinked++;
    if ((pglGetConvolutionFilterEXT = (PFNGLGETCONVOLUTIONFILTEREXTPROC) __GLeeGetProcAddress("glGetConvolutionFilterEXT"))!=0) nLinked++;
    if ((pglGetConvolutionParameterfvEXT = (PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC) __GLeeGetProcAddress("glGetConvolutionParameterfvEXT"))!=0) nLinked++;
    if ((pglGetConvolutionParameterivEXT = (PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC) __GLeeGetProcAddress("glGetConvolutionParameterivEXT"))!=0) nLinked++;
    if ((pglGetSeparableFilterEXT = (PFNGLGETSEPARABLEFILTEREXTPROC) __GLeeGetProcAddress("glGetSeparableFilterEXT"))!=0) nLinked++;
    if ((pglSeparableFilter2DEXT = (PFNGLSEPARABLEFILTER2DEXTPROC) __GLeeGetProcAddress("glSeparableFilter2DEXT"))!=0) nLinked++;
#endif
    if (nLinked==13) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGI_color_matrix(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGI_color_table(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGI_color_table
    if ((pglColorTableSGI = (PFNGLCOLORTABLESGIPROC) __GLeeGetProcAddress("glColorTableSGI"))!=0) nLinked++;
    if ((pglColorTableParameterfvSGI = (PFNGLCOLORTABLEPARAMETERFVSGIPROC) __GLeeGetProcAddress("glColorTableParameterfvSGI"))!=0) nLinked++;
    if ((pglColorTableParameterivSGI = (PFNGLCOLORTABLEPARAMETERIVSGIPROC) __GLeeGetProcAddress("glColorTableParameterivSGI"))!=0) nLinked++;
    if ((pglCopyColorTableSGI = (PFNGLCOPYCOLORTABLESGIPROC) __GLeeGetProcAddress("glCopyColorTableSGI"))!=0) nLinked++;
    if ((pglGetColorTableSGI = (PFNGLGETCOLORTABLESGIPROC) __GLeeGetProcAddress("glGetColorTableSGI"))!=0) nLinked++;
    if ((pglGetColorTableParameterfvSGI = (PFNGLGETCOLORTABLEPARAMETERFVSGIPROC) __GLeeGetProcAddress("glGetColorTableParameterfvSGI"))!=0) nLinked++;
    if ((pglGetColorTableParameterivSGI = (PFNGLGETCOLORTABLEPARAMETERIVSGIPROC) __GLeeGetProcAddress("glGetColorTableParameterivSGI"))!=0) nLinked++;
#endif
    if (nLinked==7) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIS_pixel_texture(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIS_pixel_texture
    if ((pglPixelTexGenParameteriSGIS = (PFNGLPIXELTEXGENPARAMETERISGISPROC) __GLeeGetProcAddress("glPixelTexGenParameteriSGIS"))!=0) nLinked++;
    if ((pglPixelTexGenParameterivSGIS = (PFNGLPIXELTEXGENPARAMETERIVSGISPROC) __GLeeGetProcAddress("glPixelTexGenParameterivSGIS"))!=0) nLinked++;
    if ((pglPixelTexGenParameterfSGIS = (PFNGLPIXELTEXGENPARAMETERFSGISPROC) __GLeeGetProcAddress("glPixelTexGenParameterfSGIS"))!=0) nLinked++;
    if ((pglPixelTexGenParameterfvSGIS = (PFNGLPIXELTEXGENPARAMETERFVSGISPROC) __GLeeGetProcAddress("glPixelTexGenParameterfvSGIS"))!=0) nLinked++;
    if ((pglGetPixelTexGenParameterivSGIS = (PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC) __GLeeGetProcAddress("glGetPixelTexGenParameterivSGIS"))!=0) nLinked++;
    if ((pglGetPixelTexGenParameterfvSGIS = (PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC) __GLeeGetProcAddress("glGetPixelTexGenParameterfvSGIS"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_pixel_texture(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_pixel_texture
    if ((pglPixelTexGenSGIX = (PFNGLPIXELTEXGENSGIXPROC) __GLeeGetProcAddress("glPixelTexGenSGIX"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIS_texture4D(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIS_texture4D
    if ((pglTexImage4DSGIS = (PFNGLTEXIMAGE4DSGISPROC) __GLeeGetProcAddress("glTexImage4DSGIS"))!=0) nLinked++;
    if ((pglTexSubImage4DSGIS = (PFNGLTEXSUBIMAGE4DSGISPROC) __GLeeGetProcAddress("glTexSubImage4DSGIS"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGI_texture_color_table(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_cmyka(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_object(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_texture_object
    if ((pglAreTexturesResidentEXT = (PFNGLARETEXTURESRESIDENTEXTPROC) __GLeeGetProcAddress("glAreTexturesResidentEXT"))!=0) nLinked++;
    if ((pglBindTextureEXT = (PFNGLBINDTEXTUREEXTPROC) __GLeeGetProcAddress("glBindTextureEXT"))!=0) nLinked++;
    if ((pglDeleteTexturesEXT = (PFNGLDELETETEXTURESEXTPROC) __GLeeGetProcAddress("glDeleteTexturesEXT"))!=0) nLinked++;
    if ((pglGenTexturesEXT = (PFNGLGENTEXTURESEXTPROC) __GLeeGetProcAddress("glGenTexturesEXT"))!=0) nLinked++;
    if ((pglIsTextureEXT = (PFNGLISTEXTUREEXTPROC) __GLeeGetProcAddress("glIsTextureEXT"))!=0) nLinked++;
    if ((pglPrioritizeTexturesEXT = (PFNGLPRIORITIZETEXTURESEXTPROC) __GLeeGetProcAddress("glPrioritizeTexturesEXT"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIS_detail_texture(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIS_detail_texture
    if ((pglDetailTexFuncSGIS = (PFNGLDETAILTEXFUNCSGISPROC) __GLeeGetProcAddress("glDetailTexFuncSGIS"))!=0) nLinked++;
    if ((pglGetDetailTexFuncSGIS = (PFNGLGETDETAILTEXFUNCSGISPROC) __GLeeGetProcAddress("glGetDetailTexFuncSGIS"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIS_sharpen_texture(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIS_sharpen_texture
    if ((pglSharpenTexFuncSGIS = (PFNGLSHARPENTEXFUNCSGISPROC) __GLeeGetProcAddress("glSharpenTexFuncSGIS"))!=0) nLinked++;
    if ((pglGetSharpenTexFuncSGIS = (PFNGLGETSHARPENTEXFUNCSGISPROC) __GLeeGetProcAddress("glGetSharpenTexFuncSGIS"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_packed_pixels(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIS_texture_lod(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIS_multisample(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIS_multisample
    if ((pglSampleMaskSGIS = (PFNGLSAMPLEMASKSGISPROC) __GLeeGetProcAddress("glSampleMaskSGIS"))!=0) nLinked++;
    if ((pglSamplePatternSGIS = (PFNGLSAMPLEPATTERNSGISPROC) __GLeeGetProcAddress("glSamplePatternSGIS"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_rescale_normal(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_vertex_array(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_vertex_array
    if ((pglArrayElementEXT = (PFNGLARRAYELEMENTEXTPROC) __GLeeGetProcAddress("glArrayElementEXT"))!=0) nLinked++;
    if ((pglColorPointerEXT = (PFNGLCOLORPOINTEREXTPROC) __GLeeGetProcAddress("glColorPointerEXT"))!=0) nLinked++;
    if ((pglDrawArraysEXT = (PFNGLDRAWARRAYSEXTPROC) __GLeeGetProcAddress("glDrawArraysEXT"))!=0) nLinked++;
    if ((pglEdgeFlagPointerEXT = (PFNGLEDGEFLAGPOINTEREXTPROC) __GLeeGetProcAddress("glEdgeFlagPointerEXT"))!=0) nLinked++;
    if ((pglGetPointervEXT = (PFNGLGETPOINTERVEXTPROC) __GLeeGetProcAddress("glGetPointervEXT"))!=0) nLinked++;
    if ((pglIndexPointerEXT = (PFNGLINDEXPOINTEREXTPROC) __GLeeGetProcAddress("glIndexPointerEXT"))!=0) nLinked++;
    if ((pglNormalPointerEXT = (PFNGLNORMALPOINTEREXTPROC) __GLeeGetProcAddress("glNormalPointerEXT"))!=0) nLinked++;
    if ((pglTexCoordPointerEXT = (PFNGLTEXCOORDPOINTEREXTPROC) __GLeeGetProcAddress("glTexCoordPointerEXT"))!=0) nLinked++;
    if ((pglVertexPointerEXT = (PFNGLVERTEXPOINTEREXTPROC) __GLeeGetProcAddress("glVertexPointerEXT"))!=0) nLinked++;
#endif
    if (nLinked==9) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_misc_attribute(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIS_generate_mipmap(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_clipmap(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_shadow(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIS_texture_edge_clamp(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIS_texture_border_clamp(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_blend_minmax(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_blend_minmax
    if ((pglBlendEquationEXT = (PFNGLBLENDEQUATIONEXTPROC) __GLeeGetProcAddress("glBlendEquationEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_blend_subtract(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_blend_logic_op(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_interlace(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_pixel_tiles(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIS_texture_select(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_sprite(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_sprite
    if ((pglSpriteParameterfSGIX = (PFNGLSPRITEPARAMETERFSGIXPROC) __GLeeGetProcAddress("glSpriteParameterfSGIX"))!=0) nLinked++;
    if ((pglSpriteParameterfvSGIX = (PFNGLSPRITEPARAMETERFVSGIXPROC) __GLeeGetProcAddress("glSpriteParameterfvSGIX"))!=0) nLinked++;
    if ((pglSpriteParameteriSGIX = (PFNGLSPRITEPARAMETERISGIXPROC) __GLeeGetProcAddress("glSpriteParameteriSGIX"))!=0) nLinked++;
    if ((pglSpriteParameterivSGIX = (PFNGLSPRITEPARAMETERIVSGIXPROC) __GLeeGetProcAddress("glSpriteParameterivSGIX"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_texture_multi_buffer(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_point_parameters(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_point_parameters
    if ((pglPointParameterfEXT = (PFNGLPOINTPARAMETERFEXTPROC) __GLeeGetProcAddress("glPointParameterfEXT"))!=0) nLinked++;
    if ((pglPointParameterfvEXT = (PFNGLPOINTPARAMETERFVEXTPROC) __GLeeGetProcAddress("glPointParameterfvEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIS_point_parameters(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIS_point_parameters
    if ((pglPointParameterfSGIS = (PFNGLPOINTPARAMETERFSGISPROC) __GLeeGetProcAddress("glPointParameterfSGIS"))!=0) nLinked++;
    if ((pglPointParameterfvSGIS = (PFNGLPOINTPARAMETERFVSGISPROC) __GLeeGetProcAddress("glPointParameterfvSGIS"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_instruments(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_instruments
    if ((pglGetInstrumentsSGIX = (PFNGLGETINSTRUMENTSSGIXPROC) __GLeeGetProcAddress("glGetInstrumentsSGIX"))!=0) nLinked++;
    if ((pglInstrumentsBufferSGIX = (PFNGLINSTRUMENTSBUFFERSGIXPROC) __GLeeGetProcAddress("glInstrumentsBufferSGIX"))!=0) nLinked++;
    if ((pglPollInstrumentsSGIX = (PFNGLPOLLINSTRUMENTSSGIXPROC) __GLeeGetProcAddress("glPollInstrumentsSGIX"))!=0) nLinked++;
    if ((pglReadInstrumentsSGIX = (PFNGLREADINSTRUMENTSSGIXPROC) __GLeeGetProcAddress("glReadInstrumentsSGIX"))!=0) nLinked++;
    if ((pglStartInstrumentsSGIX = (PFNGLSTARTINSTRUMENTSSGIXPROC) __GLeeGetProcAddress("glStartInstrumentsSGIX"))!=0) nLinked++;
    if ((pglStopInstrumentsSGIX = (PFNGLSTOPINSTRUMENTSSGIXPROC) __GLeeGetProcAddress("glStopInstrumentsSGIX"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_texture_scale_bias(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_framezoom(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_framezoom
    if ((pglFrameZoomSGIX = (PFNGLFRAMEZOOMSGIXPROC) __GLeeGetProcAddress("glFrameZoomSGIX"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_tag_sample_buffer(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_tag_sample_buffer
    if ((pglTagSampleBufferSGIX = (PFNGLTAGSAMPLEBUFFERSGIXPROC) __GLeeGetProcAddress("glTagSampleBufferSGIX"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_FfdMaskSGIX(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_polynomial_ffd(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_polynomial_ffd
    if ((pglDeformationMap3dSGIX = (PFNGLDEFORMATIONMAP3DSGIXPROC) __GLeeGetProcAddress("glDeformationMap3dSGIX"))!=0) nLinked++;
    if ((pglDeformationMap3fSGIX = (PFNGLDEFORMATIONMAP3FSGIXPROC) __GLeeGetProcAddress("glDeformationMap3fSGIX"))!=0) nLinked++;
    if ((pglDeformSGIX = (PFNGLDEFORMSGIXPROC) __GLeeGetProcAddress("glDeformSGIX"))!=0) nLinked++;
    if ((pglLoadIdentityDeformationMapSGIX = (PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC) __GLeeGetProcAddress("glLoadIdentityDeformationMapSGIX"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_reference_plane(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_reference_plane
    if ((pglReferencePlaneSGIX = (PFNGLREFERENCEPLANESGIXPROC) __GLeeGetProcAddress("glReferencePlaneSGIX"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_flush_raster(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_flush_raster
    if ((pglFlushRasterSGIX = (PFNGLFLUSHRASTERSGIXPROC) __GLeeGetProcAddress("glFlushRasterSGIX"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_depth_texture(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIS_fog_function(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIS_fog_function
    if ((pglFogFuncSGIS = (PFNGLFOGFUNCSGISPROC) __GLeeGetProcAddress("glFogFuncSGIS"))!=0) nLinked++;
    if ((pglGetFogFuncSGIS = (PFNGLGETFOGFUNCSGISPROC) __GLeeGetProcAddress("glGetFogFuncSGIS"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_fog_offset(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_HP_image_transform(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_HP_image_transform
    if ((pglImageTransformParameteriHP = (PFNGLIMAGETRANSFORMPARAMETERIHPPROC) __GLeeGetProcAddress("glImageTransformParameteriHP"))!=0) nLinked++;
    if ((pglImageTransformParameterfHP = (PFNGLIMAGETRANSFORMPARAMETERFHPPROC) __GLeeGetProcAddress("glImageTransformParameterfHP"))!=0) nLinked++;
    if ((pglImageTransformParameterivHP = (PFNGLIMAGETRANSFORMPARAMETERIVHPPROC) __GLeeGetProcAddress("glImageTransformParameterivHP"))!=0) nLinked++;
    if ((pglImageTransformParameterfvHP = (PFNGLIMAGETRANSFORMPARAMETERFVHPPROC) __GLeeGetProcAddress("glImageTransformParameterfvHP"))!=0) nLinked++;
    if ((pglGetImageTransformParameterivHP = (PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC) __GLeeGetProcAddress("glGetImageTransformParameterivHP"))!=0) nLinked++;
    if ((pglGetImageTransformParameterfvHP = (PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC) __GLeeGetProcAddress("glGetImageTransformParameterfvHP"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_HP_convolution_border_modes(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_INGR_palette_buffer(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_texture_add_env(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_color_subtable(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_color_subtable
    if ((pglColorSubTableEXT = (PFNGLCOLORSUBTABLEEXTPROC) __GLeeGetProcAddress("glColorSubTableEXT"))!=0) nLinked++;
    if ((pglCopyColorSubTableEXT = (PFNGLCOPYCOLORSUBTABLEEXTPROC) __GLeeGetProcAddress("glCopyColorSubTableEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_PGI_vertex_hints(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_PGI_misc_hints(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_PGI_misc_hints
    if ((pglHintPGI = (PFNGLHINTPGIPROC) __GLeeGetProcAddress("glHintPGI"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_paletted_texture(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_paletted_texture
    if ((pglColorTableEXT = (PFNGLCOLORTABLEEXTPROC) __GLeeGetProcAddress("glColorTableEXT"))!=0) nLinked++;
    if ((pglGetColorTableEXT = (PFNGLGETCOLORTABLEEXTPROC) __GLeeGetProcAddress("glGetColorTableEXT"))!=0) nLinked++;
    if ((pglGetColorTableParameterivEXT = (PFNGLGETCOLORTABLEPARAMETERIVEXTPROC) __GLeeGetProcAddress("glGetColorTableParameterivEXT"))!=0) nLinked++;
    if ((pglGetColorTableParameterfvEXT = (PFNGLGETCOLORTABLEPARAMETERFVEXTPROC) __GLeeGetProcAddress("glGetColorTableParameterfvEXT"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_clip_volume_hint(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_list_priority(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_list_priority
    if ((pglGetListParameterfvSGIX = (PFNGLGETLISTPARAMETERFVSGIXPROC) __GLeeGetProcAddress("glGetListParameterfvSGIX"))!=0) nLinked++;
    if ((pglGetListParameterivSGIX = (PFNGLGETLISTPARAMETERIVSGIXPROC) __GLeeGetProcAddress("glGetListParameterivSGIX"))!=0) nLinked++;
    if ((pglListParameterfSGIX = (PFNGLLISTPARAMETERFSGIXPROC) __GLeeGetProcAddress("glListParameterfSGIX"))!=0) nLinked++;
    if ((pglListParameterfvSGIX = (PFNGLLISTPARAMETERFVSGIXPROC) __GLeeGetProcAddress("glListParameterfvSGIX"))!=0) nLinked++;
    if ((pglListParameteriSGIX = (PFNGLLISTPARAMETERISGIXPROC) __GLeeGetProcAddress("glListParameteriSGIX"))!=0) nLinked++;
    if ((pglListParameterivSGIX = (PFNGLLISTPARAMETERIVSGIXPROC) __GLeeGetProcAddress("glListParameterivSGIX"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_ir_instrument1(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_calligraphic_fragment(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_texture_lod_bias(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_shadow_ambient(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_index_texture(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_index_material(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_index_material
    if ((pglIndexMaterialEXT = (PFNGLINDEXMATERIALEXTPROC) __GLeeGetProcAddress("glIndexMaterialEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_index_func(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_index_func
    if ((pglIndexFuncEXT = (PFNGLINDEXFUNCEXTPROC) __GLeeGetProcAddress("glIndexFuncEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_index_array_formats(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_compiled_vertex_array(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_compiled_vertex_array
    if ((pglLockArraysEXT = (PFNGLLOCKARRAYSEXTPROC) __GLeeGetProcAddress("glLockArraysEXT"))!=0) nLinked++;
    if ((pglUnlockArraysEXT = (PFNGLUNLOCKARRAYSEXTPROC) __GLeeGetProcAddress("glUnlockArraysEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_cull_vertex(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_cull_vertex
    if ((pglCullParameterdvEXT = (PFNGLCULLPARAMETERDVEXTPROC) __GLeeGetProcAddress("glCullParameterdvEXT"))!=0) nLinked++;
    if ((pglCullParameterfvEXT = (PFNGLCULLPARAMETERFVEXTPROC) __GLeeGetProcAddress("glCullParameterfvEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_ycrcb(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_fragment_lighting(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_fragment_lighting
    if ((pglFragmentColorMaterialSGIX = (PFNGLFRAGMENTCOLORMATERIALSGIXPROC) __GLeeGetProcAddress("glFragmentColorMaterialSGIX"))!=0) nLinked++;
    if ((pglFragmentLightfSGIX = (PFNGLFRAGMENTLIGHTFSGIXPROC) __GLeeGetProcAddress("glFragmentLightfSGIX"))!=0) nLinked++;
    if ((pglFragmentLightfvSGIX = (PFNGLFRAGMENTLIGHTFVSGIXPROC) __GLeeGetProcAddress("glFragmentLightfvSGIX"))!=0) nLinked++;
    if ((pglFragmentLightiSGIX = (PFNGLFRAGMENTLIGHTISGIXPROC) __GLeeGetProcAddress("glFragmentLightiSGIX"))!=0) nLinked++;
    if ((pglFragmentLightivSGIX = (PFNGLFRAGMENTLIGHTIVSGIXPROC) __GLeeGetProcAddress("glFragmentLightivSGIX"))!=0) nLinked++;
    if ((pglFragmentLightModelfSGIX = (PFNGLFRAGMENTLIGHTMODELFSGIXPROC) __GLeeGetProcAddress("glFragmentLightModelfSGIX"))!=0) nLinked++;
    if ((pglFragmentLightModelfvSGIX = (PFNGLFRAGMENTLIGHTMODELFVSGIXPROC) __GLeeGetProcAddress("glFragmentLightModelfvSGIX"))!=0) nLinked++;
    if ((pglFragmentLightModeliSGIX = (PFNGLFRAGMENTLIGHTMODELISGIXPROC) __GLeeGetProcAddress("glFragmentLightModeliSGIX"))!=0) nLinked++;
    if ((pglFragmentLightModelivSGIX = (PFNGLFRAGMENTLIGHTMODELIVSGIXPROC) __GLeeGetProcAddress("glFragmentLightModelivSGIX"))!=0) nLinked++;
    if ((pglFragmentMaterialfSGIX = (PFNGLFRAGMENTMATERIALFSGIXPROC) __GLeeGetProcAddress("glFragmentMaterialfSGIX"))!=0) nLinked++;
    if ((pglFragmentMaterialfvSGIX = (PFNGLFRAGMENTMATERIALFVSGIXPROC) __GLeeGetProcAddress("glFragmentMaterialfvSGIX"))!=0) nLinked++;
    if ((pglFragmentMaterialiSGIX = (PFNGLFRAGMENTMATERIALISGIXPROC) __GLeeGetProcAddress("glFragmentMaterialiSGIX"))!=0) nLinked++;
    if ((pglFragmentMaterialivSGIX = (PFNGLFRAGMENTMATERIALIVSGIXPROC) __GLeeGetProcAddress("glFragmentMaterialivSGIX"))!=0) nLinked++;
    if ((pglGetFragmentLightfvSGIX = (PFNGLGETFRAGMENTLIGHTFVSGIXPROC) __GLeeGetProcAddress("glGetFragmentLightfvSGIX"))!=0) nLinked++;
    if ((pglGetFragmentLightivSGIX = (PFNGLGETFRAGMENTLIGHTIVSGIXPROC) __GLeeGetProcAddress("glGetFragmentLightivSGIX"))!=0) nLinked++;
    if ((pglGetFragmentMaterialfvSGIX = (PFNGLGETFRAGMENTMATERIALFVSGIXPROC) __GLeeGetProcAddress("glGetFragmentMaterialfvSGIX"))!=0) nLinked++;
    if ((pglGetFragmentMaterialivSGIX = (PFNGLGETFRAGMENTMATERIALIVSGIXPROC) __GLeeGetProcAddress("glGetFragmentMaterialivSGIX"))!=0) nLinked++;
    if ((pglLightEnviSGIX = (PFNGLLIGHTENVISGIXPROC) __GLeeGetProcAddress("glLightEnviSGIX"))!=0) nLinked++;
#endif
    if (nLinked==18) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_IBM_rasterpos_clip(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_HP_texture_lighting(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_draw_range_elements(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_draw_range_elements
    if ((pglDrawRangeElementsEXT = (PFNGLDRAWRANGEELEMENTSEXTPROC) __GLeeGetProcAddress("glDrawRangeElementsEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_WIN_phong_shading(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_WIN_specular_fog(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_light_texture(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_light_texture
    if ((pglApplyTextureEXT = (PFNGLAPPLYTEXTUREEXTPROC) __GLeeGetProcAddress("glApplyTextureEXT"))!=0) nLinked++;
    if ((pglTextureLightEXT = (PFNGLTEXTURELIGHTEXTPROC) __GLeeGetProcAddress("glTextureLightEXT"))!=0) nLinked++;
    if ((pglTextureMaterialEXT = (PFNGLTEXTUREMATERIALEXTPROC) __GLeeGetProcAddress("glTextureMaterialEXT"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_blend_alpha_minmax(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_impact_pixel_texture(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_bgra(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_async(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_async
    if ((pglAsyncMarkerSGIX = (PFNGLASYNCMARKERSGIXPROC) __GLeeGetProcAddress("glAsyncMarkerSGIX"))!=0) nLinked++;
    if ((pglFinishAsyncSGIX = (PFNGLFINISHASYNCSGIXPROC) __GLeeGetProcAddress("glFinishAsyncSGIX"))!=0) nLinked++;
    if ((pglPollAsyncSGIX = (PFNGLPOLLASYNCSGIXPROC) __GLeeGetProcAddress("glPollAsyncSGIX"))!=0) nLinked++;
    if ((pglGenAsyncMarkersSGIX = (PFNGLGENASYNCMARKERSSGIXPROC) __GLeeGetProcAddress("glGenAsyncMarkersSGIX"))!=0) nLinked++;
    if ((pglDeleteAsyncMarkersSGIX = (PFNGLDELETEASYNCMARKERSSGIXPROC) __GLeeGetProcAddress("glDeleteAsyncMarkersSGIX"))!=0) nLinked++;
    if ((pglIsAsyncMarkerSGIX = (PFNGLISASYNCMARKERSGIXPROC) __GLeeGetProcAddress("glIsAsyncMarkerSGIX"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_async_pixel(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_async_histogram(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_INTEL_texture_scissor(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_INTEL_parallel_arrays(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_INTEL_parallel_arrays
    if ((pglVertexPointervINTEL = (PFNGLVERTEXPOINTERVINTELPROC) __GLeeGetProcAddress("glVertexPointervINTEL"))!=0) nLinked++;
    if ((pglNormalPointervINTEL = (PFNGLNORMALPOINTERVINTELPROC) __GLeeGetProcAddress("glNormalPointervINTEL"))!=0) nLinked++;
    if ((pglColorPointervINTEL = (PFNGLCOLORPOINTERVINTELPROC) __GLeeGetProcAddress("glColorPointervINTEL"))!=0) nLinked++;
    if ((pglTexCoordPointervINTEL = (PFNGLTEXCOORDPOINTERVINTELPROC) __GLeeGetProcAddress("glTexCoordPointervINTEL"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_HP_occlusion_test(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_pixel_transform(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_pixel_transform
    if ((pglPixelTransformParameteriEXT = (PFNGLPIXELTRANSFORMPARAMETERIEXTPROC) __GLeeGetProcAddress("glPixelTransformParameteriEXT"))!=0) nLinked++;
    if ((pglPixelTransformParameterfEXT = (PFNGLPIXELTRANSFORMPARAMETERFEXTPROC) __GLeeGetProcAddress("glPixelTransformParameterfEXT"))!=0) nLinked++;
    if ((pglPixelTransformParameterivEXT = (PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC) __GLeeGetProcAddress("glPixelTransformParameterivEXT"))!=0) nLinked++;
    if ((pglPixelTransformParameterfvEXT = (PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC) __GLeeGetProcAddress("glPixelTransformParameterfvEXT"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_pixel_transform_color_table(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_shared_texture_palette(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_separate_specular_color(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_secondary_color(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_secondary_color
    if ((pglSecondaryColor3bEXT = (PFNGLSECONDARYCOLOR3BEXTPROC) __GLeeGetProcAddress("glSecondaryColor3bEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3bvEXT = (PFNGLSECONDARYCOLOR3BVEXTPROC) __GLeeGetProcAddress("glSecondaryColor3bvEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3dEXT = (PFNGLSECONDARYCOLOR3DEXTPROC) __GLeeGetProcAddress("glSecondaryColor3dEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3dvEXT = (PFNGLSECONDARYCOLOR3DVEXTPROC) __GLeeGetProcAddress("glSecondaryColor3dvEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3fEXT = (PFNGLSECONDARYCOLOR3FEXTPROC) __GLeeGetProcAddress("glSecondaryColor3fEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3fvEXT = (PFNGLSECONDARYCOLOR3FVEXTPROC) __GLeeGetProcAddress("glSecondaryColor3fvEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3iEXT = (PFNGLSECONDARYCOLOR3IEXTPROC) __GLeeGetProcAddress("glSecondaryColor3iEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3ivEXT = (PFNGLSECONDARYCOLOR3IVEXTPROC) __GLeeGetProcAddress("glSecondaryColor3ivEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3sEXT = (PFNGLSECONDARYCOLOR3SEXTPROC) __GLeeGetProcAddress("glSecondaryColor3sEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3svEXT = (PFNGLSECONDARYCOLOR3SVEXTPROC) __GLeeGetProcAddress("glSecondaryColor3svEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3ubEXT = (PFNGLSECONDARYCOLOR3UBEXTPROC) __GLeeGetProcAddress("glSecondaryColor3ubEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3ubvEXT = (PFNGLSECONDARYCOLOR3UBVEXTPROC) __GLeeGetProcAddress("glSecondaryColor3ubvEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3uiEXT = (PFNGLSECONDARYCOLOR3UIEXTPROC) __GLeeGetProcAddress("glSecondaryColor3uiEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3uivEXT = (PFNGLSECONDARYCOLOR3UIVEXTPROC) __GLeeGetProcAddress("glSecondaryColor3uivEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3usEXT = (PFNGLSECONDARYCOLOR3USEXTPROC) __GLeeGetProcAddress("glSecondaryColor3usEXT"))!=0) nLinked++;
    if ((pglSecondaryColor3usvEXT = (PFNGLSECONDARYCOLOR3USVEXTPROC) __GLeeGetProcAddress("glSecondaryColor3usvEXT"))!=0) nLinked++;
    if ((pglSecondaryColorPointerEXT = (PFNGLSECONDARYCOLORPOINTEREXTPROC) __GLeeGetProcAddress("glSecondaryColorPointerEXT"))!=0) nLinked++;
#endif
    if (nLinked==17) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_texture_perturb_normal(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_texture_perturb_normal
    if ((pglTextureNormalEXT = (PFNGLTEXTURENORMALEXTPROC) __GLeeGetProcAddress("glTextureNormalEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_multi_draw_arrays(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_multi_draw_arrays
    if ((pglMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYSEXTPROC) __GLeeGetProcAddress("glMultiDrawArraysEXT"))!=0) nLinked++;
    if ((pglMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTSEXTPROC) __GLeeGetProcAddress("glMultiDrawElementsEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_fog_coord(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_fog_coord
    if ((pglFogCoordfEXT = (PFNGLFOGCOORDFEXTPROC) __GLeeGetProcAddress("glFogCoordfEXT"))!=0) nLinked++;
    if ((pglFogCoordfvEXT = (PFNGLFOGCOORDFVEXTPROC) __GLeeGetProcAddress("glFogCoordfvEXT"))!=0) nLinked++;
    if ((pglFogCoorddEXT = (PFNGLFOGCOORDDEXTPROC) __GLeeGetProcAddress("glFogCoorddEXT"))!=0) nLinked++;
    if ((pglFogCoorddvEXT = (PFNGLFOGCOORDDVEXTPROC) __GLeeGetProcAddress("glFogCoorddvEXT"))!=0) nLinked++;
    if ((pglFogCoordPointerEXT = (PFNGLFOGCOORDPOINTEREXTPROC) __GLeeGetProcAddress("glFogCoordPointerEXT"))!=0) nLinked++;
#endif
    if (nLinked==5) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_REND_screen_coordinates(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_coordinate_frame(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_coordinate_frame
    if ((pglTangent3bEXT = (PFNGLTANGENT3BEXTPROC) __GLeeGetProcAddress("glTangent3bEXT"))!=0) nLinked++;
    if ((pglTangent3bvEXT = (PFNGLTANGENT3BVEXTPROC) __GLeeGetProcAddress("glTangent3bvEXT"))!=0) nLinked++;
    if ((pglTangent3dEXT = (PFNGLTANGENT3DEXTPROC) __GLeeGetProcAddress("glTangent3dEXT"))!=0) nLinked++;
    if ((pglTangent3dvEXT = (PFNGLTANGENT3DVEXTPROC) __GLeeGetProcAddress("glTangent3dvEXT"))!=0) nLinked++;
    if ((pglTangent3fEXT = (PFNGLTANGENT3FEXTPROC) __GLeeGetProcAddress("glTangent3fEXT"))!=0) nLinked++;
    if ((pglTangent3fvEXT = (PFNGLTANGENT3FVEXTPROC) __GLeeGetProcAddress("glTangent3fvEXT"))!=0) nLinked++;
    if ((pglTangent3iEXT = (PFNGLTANGENT3IEXTPROC) __GLeeGetProcAddress("glTangent3iEXT"))!=0) nLinked++;
    if ((pglTangent3ivEXT = (PFNGLTANGENT3IVEXTPROC) __GLeeGetProcAddress("glTangent3ivEXT"))!=0) nLinked++;
    if ((pglTangent3sEXT = (PFNGLTANGENT3SEXTPROC) __GLeeGetProcAddress("glTangent3sEXT"))!=0) nLinked++;
    if ((pglTangent3svEXT = (PFNGLTANGENT3SVEXTPROC) __GLeeGetProcAddress("glTangent3svEXT"))!=0) nLinked++;
    if ((pglBinormal3bEXT = (PFNGLBINORMAL3BEXTPROC) __GLeeGetProcAddress("glBinormal3bEXT"))!=0) nLinked++;
    if ((pglBinormal3bvEXT = (PFNGLBINORMAL3BVEXTPROC) __GLeeGetProcAddress("glBinormal3bvEXT"))!=0) nLinked++;
    if ((pglBinormal3dEXT = (PFNGLBINORMAL3DEXTPROC) __GLeeGetProcAddress("glBinormal3dEXT"))!=0) nLinked++;
    if ((pglBinormal3dvEXT = (PFNGLBINORMAL3DVEXTPROC) __GLeeGetProcAddress("glBinormal3dvEXT"))!=0) nLinked++;
    if ((pglBinormal3fEXT = (PFNGLBINORMAL3FEXTPROC) __GLeeGetProcAddress("glBinormal3fEXT"))!=0) nLinked++;
    if ((pglBinormal3fvEXT = (PFNGLBINORMAL3FVEXTPROC) __GLeeGetProcAddress("glBinormal3fvEXT"))!=0) nLinked++;
    if ((pglBinormal3iEXT = (PFNGLBINORMAL3IEXTPROC) __GLeeGetProcAddress("glBinormal3iEXT"))!=0) nLinked++;
    if ((pglBinormal3ivEXT = (PFNGLBINORMAL3IVEXTPROC) __GLeeGetProcAddress("glBinormal3ivEXT"))!=0) nLinked++;
    if ((pglBinormal3sEXT = (PFNGLBINORMAL3SEXTPROC) __GLeeGetProcAddress("glBinormal3sEXT"))!=0) nLinked++;
    if ((pglBinormal3svEXT = (PFNGLBINORMAL3SVEXTPROC) __GLeeGetProcAddress("glBinormal3svEXT"))!=0) nLinked++;
    if ((pglTangentPointerEXT = (PFNGLTANGENTPOINTEREXTPROC) __GLeeGetProcAddress("glTangentPointerEXT"))!=0) nLinked++;
    if ((pglBinormalPointerEXT = (PFNGLBINORMALPOINTEREXTPROC) __GLeeGetProcAddress("glBinormalPointerEXT"))!=0) nLinked++;
#endif
    if (nLinked==22) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_texture_env_combine(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_APPLE_specular_vector(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_APPLE_transform_hint(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_fog_scale(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SUNX_constant_data(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SUNX_constant_data
    if ((pglFinishTextureSUNX = (PFNGLFINISHTEXTURESUNXPROC) __GLeeGetProcAddress("glFinishTextureSUNX"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SUN_global_alpha(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SUN_global_alpha
    if ((pglGlobalAlphaFactorbSUN = (PFNGLGLOBALALPHAFACTORBSUNPROC) __GLeeGetProcAddress("glGlobalAlphaFactorbSUN"))!=0) nLinked++;
    if ((pglGlobalAlphaFactorsSUN = (PFNGLGLOBALALPHAFACTORSSUNPROC) __GLeeGetProcAddress("glGlobalAlphaFactorsSUN"))!=0) nLinked++;
    if ((pglGlobalAlphaFactoriSUN = (PFNGLGLOBALALPHAFACTORISUNPROC) __GLeeGetProcAddress("glGlobalAlphaFactoriSUN"))!=0) nLinked++;
    if ((pglGlobalAlphaFactorfSUN = (PFNGLGLOBALALPHAFACTORFSUNPROC) __GLeeGetProcAddress("glGlobalAlphaFactorfSUN"))!=0) nLinked++;
    if ((pglGlobalAlphaFactordSUN = (PFNGLGLOBALALPHAFACTORDSUNPROC) __GLeeGetProcAddress("glGlobalAlphaFactordSUN"))!=0) nLinked++;
    if ((pglGlobalAlphaFactorubSUN = (PFNGLGLOBALALPHAFACTORUBSUNPROC) __GLeeGetProcAddress("glGlobalAlphaFactorubSUN"))!=0) nLinked++;
    if ((pglGlobalAlphaFactorusSUN = (PFNGLGLOBALALPHAFACTORUSSUNPROC) __GLeeGetProcAddress("glGlobalAlphaFactorusSUN"))!=0) nLinked++;
    if ((pglGlobalAlphaFactoruiSUN = (PFNGLGLOBALALPHAFACTORUISUNPROC) __GLeeGetProcAddress("glGlobalAlphaFactoruiSUN"))!=0) nLinked++;
#endif
    if (nLinked==8) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SUN_triangle_list(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SUN_triangle_list
    if ((pglReplacementCodeuiSUN = (PFNGLREPLACEMENTCODEUISUNPROC) __GLeeGetProcAddress("glReplacementCodeuiSUN"))!=0) nLinked++;
    if ((pglReplacementCodeusSUN = (PFNGLREPLACEMENTCODEUSSUNPROC) __GLeeGetProcAddress("glReplacementCodeusSUN"))!=0) nLinked++;
    if ((pglReplacementCodeubSUN = (PFNGLREPLACEMENTCODEUBSUNPROC) __GLeeGetProcAddress("glReplacementCodeubSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuivSUN = (PFNGLREPLACEMENTCODEUIVSUNPROC) __GLeeGetProcAddress("glReplacementCodeuivSUN"))!=0) nLinked++;
    if ((pglReplacementCodeusvSUN = (PFNGLREPLACEMENTCODEUSVSUNPROC) __GLeeGetProcAddress("glReplacementCodeusvSUN"))!=0) nLinked++;
    if ((pglReplacementCodeubvSUN = (PFNGLREPLACEMENTCODEUBVSUNPROC) __GLeeGetProcAddress("glReplacementCodeubvSUN"))!=0) nLinked++;
    if ((pglReplacementCodePointerSUN = (PFNGLREPLACEMENTCODEPOINTERSUNPROC) __GLeeGetProcAddress("glReplacementCodePointerSUN"))!=0) nLinked++;
#endif
    if (nLinked==7) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SUN_vertex(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SUN_vertex
    if ((pglColor4ubVertex2fSUN = (PFNGLCOLOR4UBVERTEX2FSUNPROC) __GLeeGetProcAddress("glColor4ubVertex2fSUN"))!=0) nLinked++;
    if ((pglColor4ubVertex2fvSUN = (PFNGLCOLOR4UBVERTEX2FVSUNPROC) __GLeeGetProcAddress("glColor4ubVertex2fvSUN"))!=0) nLinked++;
    if ((pglColor4ubVertex3fSUN = (PFNGLCOLOR4UBVERTEX3FSUNPROC) __GLeeGetProcAddress("glColor4ubVertex3fSUN"))!=0) nLinked++;
    if ((pglColor4ubVertex3fvSUN = (PFNGLCOLOR4UBVERTEX3FVSUNPROC) __GLeeGetProcAddress("glColor4ubVertex3fvSUN"))!=0) nLinked++;
    if ((pglColor3fVertex3fSUN = (PFNGLCOLOR3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glColor3fVertex3fSUN"))!=0) nLinked++;
    if ((pglColor3fVertex3fvSUN = (PFNGLCOLOR3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glColor3fVertex3fvSUN"))!=0) nLinked++;
    if ((pglNormal3fVertex3fSUN = (PFNGLNORMAL3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glNormal3fVertex3fSUN"))!=0) nLinked++;
    if ((pglNormal3fVertex3fvSUN = (PFNGLNORMAL3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glNormal3fVertex3fvSUN"))!=0) nLinked++;
    if ((pglColor4fNormal3fVertex3fSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glColor4fNormal3fVertex3fSUN"))!=0) nLinked++;
    if ((pglColor4fNormal3fVertex3fvSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glColor4fNormal3fVertex3fvSUN"))!=0) nLinked++;
    if ((pglTexCoord2fVertex3fSUN = (PFNGLTEXCOORD2FVERTEX3FSUNPROC) __GLeeGetProcAddress("glTexCoord2fVertex3fSUN"))!=0) nLinked++;
    if ((pglTexCoord2fVertex3fvSUN = (PFNGLTEXCOORD2FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glTexCoord2fVertex3fvSUN"))!=0) nLinked++;
    if ((pglTexCoord4fVertex4fSUN = (PFNGLTEXCOORD4FVERTEX4FSUNPROC) __GLeeGetProcAddress("glTexCoord4fVertex4fSUN"))!=0) nLinked++;
    if ((pglTexCoord4fVertex4fvSUN = (PFNGLTEXCOORD4FVERTEX4FVSUNPROC) __GLeeGetProcAddress("glTexCoord4fVertex4fvSUN"))!=0) nLinked++;
    if ((pglTexCoord2fColor4ubVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC) __GLeeGetProcAddress("glTexCoord2fColor4ubVertex3fSUN"))!=0) nLinked++;
    if ((pglTexCoord2fColor4ubVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC) __GLeeGetProcAddress("glTexCoord2fColor4ubVertex3fvSUN"))!=0) nLinked++;
    if ((pglTexCoord2fColor3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glTexCoord2fColor3fVertex3fSUN"))!=0) nLinked++;
    if ((pglTexCoord2fColor3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glTexCoord2fColor3fVertex3fvSUN"))!=0) nLinked++;
    if ((pglTexCoord2fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glTexCoord2fNormal3fVertex3fSUN"))!=0) nLinked++;
    if ((pglTexCoord2fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glTexCoord2fNormal3fVertex3fvSUN"))!=0) nLinked++;
    if ((pglTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fSUN"))!=0) nLinked++;
    if ((pglTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fvSUN"))!=0) nLinked++;
    if ((pglTexCoord4fColor4fNormal3fVertex4fSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC) __GLeeGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fSUN"))!=0) nLinked++;
    if ((pglTexCoord4fColor4fNormal3fVertex4fvSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC) __GLeeGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fvSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiVertex3fSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiVertex3fSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiVertex3fvSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiVertex3fvSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiColor4ubVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiColor4ubVertex3fSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiColor4ubVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiColor4ubVertex3fvSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiColor3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiColor3fVertex3fSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiColor3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiColor3fVertex3fvSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiNormal3fVertex3fSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiNormal3fVertex3fvSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fvSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiTexCoord2fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiTexCoord2fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fvSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN"))!=0) nLinked++;
    if ((pglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) __GLeeGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN"))!=0) nLinked++;
#endif
    if (nLinked==40) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_blend_func_separate(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_blend_func_separate
    if ((pglBlendFuncSeparateEXT = (PFNGLBLENDFUNCSEPARATEEXTPROC) __GLeeGetProcAddress("glBlendFuncSeparateEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_INGR_color_clamp(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_INGR_interlace_read(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_stencil_wrap(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_422_pixels(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_texgen_reflection(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_cube_map(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SUN_convolution_border_modes(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_env_add(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_lod_bias(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_filter_anisotropic(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_vertex_weighting(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_vertex_weighting
    if ((pglVertexWeightfEXT = (PFNGLVERTEXWEIGHTFEXTPROC) __GLeeGetProcAddress("glVertexWeightfEXT"))!=0) nLinked++;
    if ((pglVertexWeightfvEXT = (PFNGLVERTEXWEIGHTFVEXTPROC) __GLeeGetProcAddress("glVertexWeightfvEXT"))!=0) nLinked++;
    if ((pglVertexWeightPointerEXT = (PFNGLVERTEXWEIGHTPOINTEREXTPROC) __GLeeGetProcAddress("glVertexWeightPointerEXT"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_light_max_exponent(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_vertex_array_range(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_vertex_array_range
    if ((pglFlushVertexArrayRangeNV = (PFNGLFLUSHVERTEXARRAYRANGENVPROC) __GLeeGetProcAddress("glFlushVertexArrayRangeNV"))!=0) nLinked++;
    if ((pglVertexArrayRangeNV = (PFNGLVERTEXARRAYRANGENVPROC) __GLeeGetProcAddress("glVertexArrayRangeNV"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_register_combiners(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_register_combiners
    if ((pglCombinerParameterfvNV = (PFNGLCOMBINERPARAMETERFVNVPROC) __GLeeGetProcAddress("glCombinerParameterfvNV"))!=0) nLinked++;
    if ((pglCombinerParameterfNV = (PFNGLCOMBINERPARAMETERFNVPROC) __GLeeGetProcAddress("glCombinerParameterfNV"))!=0) nLinked++;
    if ((pglCombinerParameterivNV = (PFNGLCOMBINERPARAMETERIVNVPROC) __GLeeGetProcAddress("glCombinerParameterivNV"))!=0) nLinked++;
    if ((pglCombinerParameteriNV = (PFNGLCOMBINERPARAMETERINVPROC) __GLeeGetProcAddress("glCombinerParameteriNV"))!=0) nLinked++;
    if ((pglCombinerInputNV = (PFNGLCOMBINERINPUTNVPROC) __GLeeGetProcAddress("glCombinerInputNV"))!=0) nLinked++;
    if ((pglCombinerOutputNV = (PFNGLCOMBINEROUTPUTNVPROC) __GLeeGetProcAddress("glCombinerOutputNV"))!=0) nLinked++;
    if ((pglFinalCombinerInputNV = (PFNGLFINALCOMBINERINPUTNVPROC) __GLeeGetProcAddress("glFinalCombinerInputNV"))!=0) nLinked++;
    if ((pglGetCombinerInputParameterfvNV = (PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC) __GLeeGetProcAddress("glGetCombinerInputParameterfvNV"))!=0) nLinked++;
    if ((pglGetCombinerInputParameterivNV = (PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC) __GLeeGetProcAddress("glGetCombinerInputParameterivNV"))!=0) nLinked++;
    if ((pglGetCombinerOutputParameterfvNV = (PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC) __GLeeGetProcAddress("glGetCombinerOutputParameterfvNV"))!=0) nLinked++;
    if ((pglGetCombinerOutputParameterivNV = (PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC) __GLeeGetProcAddress("glGetCombinerOutputParameterivNV"))!=0) nLinked++;
    if ((pglGetFinalCombinerInputParameterfvNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC) __GLeeGetProcAddress("glGetFinalCombinerInputParameterfvNV"))!=0) nLinked++;
    if ((pglGetFinalCombinerInputParameterivNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC) __GLeeGetProcAddress("glGetFinalCombinerInputParameterivNV"))!=0) nLinked++;
#endif
    if (nLinked==13) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_fog_distance(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_texgen_emboss(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_blend_square(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_texture_env_combine4(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_MESA_resize_buffers(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_MESA_resize_buffers
    if ((pglResizeBuffersMESA = (PFNGLRESIZEBUFFERSMESAPROC) __GLeeGetProcAddress("glResizeBuffersMESA"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_MESA_window_pos(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_MESA_window_pos
    if ((pglWindowPos2dMESA = (PFNGLWINDOWPOS2DMESAPROC) __GLeeGetProcAddress("glWindowPos2dMESA"))!=0) nLinked++;
    if ((pglWindowPos2dvMESA = (PFNGLWINDOWPOS2DVMESAPROC) __GLeeGetProcAddress("glWindowPos2dvMESA"))!=0) nLinked++;
    if ((pglWindowPos2fMESA = (PFNGLWINDOWPOS2FMESAPROC) __GLeeGetProcAddress("glWindowPos2fMESA"))!=0) nLinked++;
    if ((pglWindowPos2fvMESA = (PFNGLWINDOWPOS2FVMESAPROC) __GLeeGetProcAddress("glWindowPos2fvMESA"))!=0) nLinked++;
    if ((pglWindowPos2iMESA = (PFNGLWINDOWPOS2IMESAPROC) __GLeeGetProcAddress("glWindowPos2iMESA"))!=0) nLinked++;
    if ((pglWindowPos2ivMESA = (PFNGLWINDOWPOS2IVMESAPROC) __GLeeGetProcAddress("glWindowPos2ivMESA"))!=0) nLinked++;
    if ((pglWindowPos2sMESA = (PFNGLWINDOWPOS2SMESAPROC) __GLeeGetProcAddress("glWindowPos2sMESA"))!=0) nLinked++;
    if ((pglWindowPos2svMESA = (PFNGLWINDOWPOS2SVMESAPROC) __GLeeGetProcAddress("glWindowPos2svMESA"))!=0) nLinked++;
    if ((pglWindowPos3dMESA = (PFNGLWINDOWPOS3DMESAPROC) __GLeeGetProcAddress("glWindowPos3dMESA"))!=0) nLinked++;
    if ((pglWindowPos3dvMESA = (PFNGLWINDOWPOS3DVMESAPROC) __GLeeGetProcAddress("glWindowPos3dvMESA"))!=0) nLinked++;
    if ((pglWindowPos3fMESA = (PFNGLWINDOWPOS3FMESAPROC) __GLeeGetProcAddress("glWindowPos3fMESA"))!=0) nLinked++;
    if ((pglWindowPos3fvMESA = (PFNGLWINDOWPOS3FVMESAPROC) __GLeeGetProcAddress("glWindowPos3fvMESA"))!=0) nLinked++;
    if ((pglWindowPos3iMESA = (PFNGLWINDOWPOS3IMESAPROC) __GLeeGetProcAddress("glWindowPos3iMESA"))!=0) nLinked++;
    if ((pglWindowPos3ivMESA = (PFNGLWINDOWPOS3IVMESAPROC) __GLeeGetProcAddress("glWindowPos3ivMESA"))!=0) nLinked++;
    if ((pglWindowPos3sMESA = (PFNGLWINDOWPOS3SMESAPROC) __GLeeGetProcAddress("glWindowPos3sMESA"))!=0) nLinked++;
    if ((pglWindowPos3svMESA = (PFNGLWINDOWPOS3SVMESAPROC) __GLeeGetProcAddress("glWindowPos3svMESA"))!=0) nLinked++;
    if ((pglWindowPos4dMESA = (PFNGLWINDOWPOS4DMESAPROC) __GLeeGetProcAddress("glWindowPos4dMESA"))!=0) nLinked++;
    if ((pglWindowPos4dvMESA = (PFNGLWINDOWPOS4DVMESAPROC) __GLeeGetProcAddress("glWindowPos4dvMESA"))!=0) nLinked++;
    if ((pglWindowPos4fMESA = (PFNGLWINDOWPOS4FMESAPROC) __GLeeGetProcAddress("glWindowPos4fMESA"))!=0) nLinked++;
    if ((pglWindowPos4fvMESA = (PFNGLWINDOWPOS4FVMESAPROC) __GLeeGetProcAddress("glWindowPos4fvMESA"))!=0) nLinked++;
    if ((pglWindowPos4iMESA = (PFNGLWINDOWPOS4IMESAPROC) __GLeeGetProcAddress("glWindowPos4iMESA"))!=0) nLinked++;
    if ((pglWindowPos4ivMESA = (PFNGLWINDOWPOS4IVMESAPROC) __GLeeGetProcAddress("glWindowPos4ivMESA"))!=0) nLinked++;
    if ((pglWindowPos4sMESA = (PFNGLWINDOWPOS4SMESAPROC) __GLeeGetProcAddress("glWindowPos4sMESA"))!=0) nLinked++;
    if ((pglWindowPos4svMESA = (PFNGLWINDOWPOS4SVMESAPROC) __GLeeGetProcAddress("glWindowPos4svMESA"))!=0) nLinked++;
#endif
    if (nLinked==24) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_texture_compression_s3tc(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_IBM_cull_vertex(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_IBM_multimode_draw_arrays(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_IBM_multimode_draw_arrays
    if ((pglMultiModeDrawArraysIBM = (PFNGLMULTIMODEDRAWARRAYSIBMPROC) __GLeeGetProcAddress("glMultiModeDrawArraysIBM"))!=0) nLinked++;
    if ((pglMultiModeDrawElementsIBM = (PFNGLMULTIMODEDRAWELEMENTSIBMPROC) __GLeeGetProcAddress("glMultiModeDrawElementsIBM"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_IBM_vertex_array_lists(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_IBM_vertex_array_lists
    if ((pglColorPointerListIBM = (PFNGLCOLORPOINTERLISTIBMPROC) __GLeeGetProcAddress("glColorPointerListIBM"))!=0) nLinked++;
    if ((pglSecondaryColorPointerListIBM = (PFNGLSECONDARYCOLORPOINTERLISTIBMPROC) __GLeeGetProcAddress("glSecondaryColorPointerListIBM"))!=0) nLinked++;
    if ((pglEdgeFlagPointerListIBM = (PFNGLEDGEFLAGPOINTERLISTIBMPROC) __GLeeGetProcAddress("glEdgeFlagPointerListIBM"))!=0) nLinked++;
    if ((pglFogCoordPointerListIBM = (PFNGLFOGCOORDPOINTERLISTIBMPROC) __GLeeGetProcAddress("glFogCoordPointerListIBM"))!=0) nLinked++;
    if ((pglIndexPointerListIBM = (PFNGLINDEXPOINTERLISTIBMPROC) __GLeeGetProcAddress("glIndexPointerListIBM"))!=0) nLinked++;
    if ((pglNormalPointerListIBM = (PFNGLNORMALPOINTERLISTIBMPROC) __GLeeGetProcAddress("glNormalPointerListIBM"))!=0) nLinked++;
    if ((pglTexCoordPointerListIBM = (PFNGLTEXCOORDPOINTERLISTIBMPROC) __GLeeGetProcAddress("glTexCoordPointerListIBM"))!=0) nLinked++;
    if ((pglVertexPointerListIBM = (PFNGLVERTEXPOINTERLISTIBMPROC) __GLeeGetProcAddress("glVertexPointerListIBM"))!=0) nLinked++;
#endif
    if (nLinked==8) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_subsample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_ycrcb_subsample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_ycrcba(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGI_depth_pass_instrument(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_3DFX_texture_compression_FXT1(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_3DFX_multisample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_3DFX_tbuffer(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_3DFX_tbuffer
    if ((pglTbufferMask3DFX = (PFNGLTBUFFERMASK3DFXPROC) __GLeeGetProcAddress("glTbufferMask3DFX"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_multisample(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_multisample
    if ((pglSampleMaskEXT = (PFNGLSAMPLEMASKEXTPROC) __GLeeGetProcAddress("glSampleMaskEXT"))!=0) nLinked++;
    if ((pglSamplePatternEXT = (PFNGLSAMPLEPATTERNEXTPROC) __GLeeGetProcAddress("glSamplePatternEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_vertex_preclip(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_convolution_accuracy(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_resample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIS_point_line_texgen(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIS_texture_color_mask(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIS_texture_color_mask
    if ((pglTextureColorMaskSGIS = (PFNGLTEXTURECOLORMASKSGISPROC) __GLeeGetProcAddress("glTextureColorMaskSGIS"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_texture_env_dot3(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ATI_texture_mirror_once(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_fence(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_fence
    if ((pglDeleteFencesNV = (PFNGLDELETEFENCESNVPROC) __GLeeGetProcAddress("glDeleteFencesNV"))!=0) nLinked++;
    if ((pglGenFencesNV = (PFNGLGENFENCESNVPROC) __GLeeGetProcAddress("glGenFencesNV"))!=0) nLinked++;
    if ((pglIsFenceNV = (PFNGLISFENCENVPROC) __GLeeGetProcAddress("glIsFenceNV"))!=0) nLinked++;
    if ((pglTestFenceNV = (PFNGLTESTFENCENVPROC) __GLeeGetProcAddress("glTestFenceNV"))!=0) nLinked++;
    if ((pglGetFenceivNV = (PFNGLGETFENCEIVNVPROC) __GLeeGetProcAddress("glGetFenceivNV"))!=0) nLinked++;
    if ((pglFinishFenceNV = (PFNGLFINISHFENCENVPROC) __GLeeGetProcAddress("glFinishFenceNV"))!=0) nLinked++;
    if ((pglSetFenceNV = (PFNGLSETFENCENVPROC) __GLeeGetProcAddress("glSetFenceNV"))!=0) nLinked++;
#endif
    if (nLinked==7) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_IBM_texture_mirrored_repeat(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_evaluators(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_evaluators
    if ((pglMapControlPointsNV = (PFNGLMAPCONTROLPOINTSNVPROC) __GLeeGetProcAddress("glMapControlPointsNV"))!=0) nLinked++;
    if ((pglMapParameterivNV = (PFNGLMAPPARAMETERIVNVPROC) __GLeeGetProcAddress("glMapParameterivNV"))!=0) nLinked++;
    if ((pglMapParameterfvNV = (PFNGLMAPPARAMETERFVNVPROC) __GLeeGetProcAddress("glMapParameterfvNV"))!=0) nLinked++;
    if ((pglGetMapControlPointsNV = (PFNGLGETMAPCONTROLPOINTSNVPROC) __GLeeGetProcAddress("glGetMapControlPointsNV"))!=0) nLinked++;
    if ((pglGetMapParameterivNV = (PFNGLGETMAPPARAMETERIVNVPROC) __GLeeGetProcAddress("glGetMapParameterivNV"))!=0) nLinked++;
    if ((pglGetMapParameterfvNV = (PFNGLGETMAPPARAMETERFVNVPROC) __GLeeGetProcAddress("glGetMapParameterfvNV"))!=0) nLinked++;
    if ((pglGetMapAttribParameterivNV = (PFNGLGETMAPATTRIBPARAMETERIVNVPROC) __GLeeGetProcAddress("glGetMapAttribParameterivNV"))!=0) nLinked++;
    if ((pglGetMapAttribParameterfvNV = (PFNGLGETMAPATTRIBPARAMETERFVNVPROC) __GLeeGetProcAddress("glGetMapAttribParameterfvNV"))!=0) nLinked++;
    if ((pglEvalMapsNV = (PFNGLEVALMAPSNVPROC) __GLeeGetProcAddress("glEvalMapsNV"))!=0) nLinked++;
#endif
    if (nLinked==9) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_packed_depth_stencil(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_register_combiners2(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_register_combiners2
    if ((pglCombinerStageParameterfvNV = (PFNGLCOMBINERSTAGEPARAMETERFVNVPROC) __GLeeGetProcAddress("glCombinerStageParameterfvNV"))!=0) nLinked++;
    if ((pglGetCombinerStageParameterfvNV = (PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC) __GLeeGetProcAddress("glGetCombinerStageParameterfvNV"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_texture_compression_vtc(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_texture_rectangle(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_texture_shader(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_texture_shader2(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_vertex_array_range2(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_vertex_program(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_vertex_program
    if ((pglAreProgramsResidentNV = (PFNGLAREPROGRAMSRESIDENTNVPROC) __GLeeGetProcAddress("glAreProgramsResidentNV"))!=0) nLinked++;
    if ((pglBindProgramNV = (PFNGLBINDPROGRAMNVPROC) __GLeeGetProcAddress("glBindProgramNV"))!=0) nLinked++;
    if ((pglDeleteProgramsNV = (PFNGLDELETEPROGRAMSNVPROC) __GLeeGetProcAddress("glDeleteProgramsNV"))!=0) nLinked++;
    if ((pglExecuteProgramNV = (PFNGLEXECUTEPROGRAMNVPROC) __GLeeGetProcAddress("glExecuteProgramNV"))!=0) nLinked++;
    if ((pglGenProgramsNV = (PFNGLGENPROGRAMSNVPROC) __GLeeGetProcAddress("glGenProgramsNV"))!=0) nLinked++;
    if ((pglGetProgramParameterdvNV = (PFNGLGETPROGRAMPARAMETERDVNVPROC) __GLeeGetProcAddress("glGetProgramParameterdvNV"))!=0) nLinked++;
    if ((pglGetProgramParameterfvNV = (PFNGLGETPROGRAMPARAMETERFVNVPROC) __GLeeGetProcAddress("glGetProgramParameterfvNV"))!=0) nLinked++;
    if ((pglGetProgramivNV = (PFNGLGETPROGRAMIVNVPROC) __GLeeGetProcAddress("glGetProgramivNV"))!=0) nLinked++;
    if ((pglGetProgramStringNV = (PFNGLGETPROGRAMSTRINGNVPROC) __GLeeGetProcAddress("glGetProgramStringNV"))!=0) nLinked++;
    if ((pglGetTrackMatrixivNV = (PFNGLGETTRACKMATRIXIVNVPROC) __GLeeGetProcAddress("glGetTrackMatrixivNV"))!=0) nLinked++;
    if ((pglGetVertexAttribdvNV = (PFNGLGETVERTEXATTRIBDVNVPROC) __GLeeGetProcAddress("glGetVertexAttribdvNV"))!=0) nLinked++;
    if ((pglGetVertexAttribfvNV = (PFNGLGETVERTEXATTRIBFVNVPROC) __GLeeGetProcAddress("glGetVertexAttribfvNV"))!=0) nLinked++;
    if ((pglGetVertexAttribivNV = (PFNGLGETVERTEXATTRIBIVNVPROC) __GLeeGetProcAddress("glGetVertexAttribivNV"))!=0) nLinked++;
    if ((pglGetVertexAttribPointervNV = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC) __GLeeGetProcAddress("glGetVertexAttribPointervNV"))!=0) nLinked++;
    if ((pglIsProgramNV = (PFNGLISPROGRAMNVPROC) __GLeeGetProcAddress("glIsProgramNV"))!=0) nLinked++;
    if ((pglLoadProgramNV = (PFNGLLOADPROGRAMNVPROC) __GLeeGetProcAddress("glLoadProgramNV"))!=0) nLinked++;
    if ((pglProgramParameter4dNV = (PFNGLPROGRAMPARAMETER4DNVPROC) __GLeeGetProcAddress("glProgramParameter4dNV"))!=0) nLinked++;
    if ((pglProgramParameter4dvNV = (PFNGLPROGRAMPARAMETER4DVNVPROC) __GLeeGetProcAddress("glProgramParameter4dvNV"))!=0) nLinked++;
    if ((pglProgramParameter4fNV = (PFNGLPROGRAMPARAMETER4FNVPROC) __GLeeGetProcAddress("glProgramParameter4fNV"))!=0) nLinked++;
    if ((pglProgramParameter4fvNV = (PFNGLPROGRAMPARAMETER4FVNVPROC) __GLeeGetProcAddress("glProgramParameter4fvNV"))!=0) nLinked++;
    if ((pglProgramParameters4dvNV = (PFNGLPROGRAMPARAMETERS4DVNVPROC) __GLeeGetProcAddress("glProgramParameters4dvNV"))!=0) nLinked++;
    if ((pglProgramParameters4fvNV = (PFNGLPROGRAMPARAMETERS4FVNVPROC) __GLeeGetProcAddress("glProgramParameters4fvNV"))!=0) nLinked++;
    if ((pglRequestResidentProgramsNV = (PFNGLREQUESTRESIDENTPROGRAMSNVPROC) __GLeeGetProcAddress("glRequestResidentProgramsNV"))!=0) nLinked++;
    if ((pglTrackMatrixNV = (PFNGLTRACKMATRIXNVPROC) __GLeeGetProcAddress("glTrackMatrixNV"))!=0) nLinked++;
    if ((pglVertexAttribPointerNV = (PFNGLVERTEXATTRIBPOINTERNVPROC) __GLeeGetProcAddress("glVertexAttribPointerNV"))!=0) nLinked++;
    if ((pglVertexAttrib1dNV = (PFNGLVERTEXATTRIB1DNVPROC) __GLeeGetProcAddress("glVertexAttrib1dNV"))!=0) nLinked++;
    if ((pglVertexAttrib1dvNV = (PFNGLVERTEXATTRIB1DVNVPROC) __GLeeGetProcAddress("glVertexAttrib1dvNV"))!=0) nLinked++;
    if ((pglVertexAttrib1fNV = (PFNGLVERTEXATTRIB1FNVPROC) __GLeeGetProcAddress("glVertexAttrib1fNV"))!=0) nLinked++;
    if ((pglVertexAttrib1fvNV = (PFNGLVERTEXATTRIB1FVNVPROC) __GLeeGetProcAddress("glVertexAttrib1fvNV"))!=0) nLinked++;
    if ((pglVertexAttrib1sNV = (PFNGLVERTEXATTRIB1SNVPROC) __GLeeGetProcAddress("glVertexAttrib1sNV"))!=0) nLinked++;
    if ((pglVertexAttrib1svNV = (PFNGLVERTEXATTRIB1SVNVPROC) __GLeeGetProcAddress("glVertexAttrib1svNV"))!=0) nLinked++;
    if ((pglVertexAttrib2dNV = (PFNGLVERTEXATTRIB2DNVPROC) __GLeeGetProcAddress("glVertexAttrib2dNV"))!=0) nLinked++;
    if ((pglVertexAttrib2dvNV = (PFNGLVERTEXATTRIB2DVNVPROC) __GLeeGetProcAddress("glVertexAttrib2dvNV"))!=0) nLinked++;
    if ((pglVertexAttrib2fNV = (PFNGLVERTEXATTRIB2FNVPROC) __GLeeGetProcAddress("glVertexAttrib2fNV"))!=0) nLinked++;
    if ((pglVertexAttrib2fvNV = (PFNGLVERTEXATTRIB2FVNVPROC) __GLeeGetProcAddress("glVertexAttrib2fvNV"))!=0) nLinked++;
    if ((pglVertexAttrib2sNV = (PFNGLVERTEXATTRIB2SNVPROC) __GLeeGetProcAddress("glVertexAttrib2sNV"))!=0) nLinked++;
    if ((pglVertexAttrib2svNV = (PFNGLVERTEXATTRIB2SVNVPROC) __GLeeGetProcAddress("glVertexAttrib2svNV"))!=0) nLinked++;
    if ((pglVertexAttrib3dNV = (PFNGLVERTEXATTRIB3DNVPROC) __GLeeGetProcAddress("glVertexAttrib3dNV"))!=0) nLinked++;
    if ((pglVertexAttrib3dvNV = (PFNGLVERTEXATTRIB3DVNVPROC) __GLeeGetProcAddress("glVertexAttrib3dvNV"))!=0) nLinked++;
    if ((pglVertexAttrib3fNV = (PFNGLVERTEXATTRIB3FNVPROC) __GLeeGetProcAddress("glVertexAttrib3fNV"))!=0) nLinked++;
    if ((pglVertexAttrib3fvNV = (PFNGLVERTEXATTRIB3FVNVPROC) __GLeeGetProcAddress("glVertexAttrib3fvNV"))!=0) nLinked++;
    if ((pglVertexAttrib3sNV = (PFNGLVERTEXATTRIB3SNVPROC) __GLeeGetProcAddress("glVertexAttrib3sNV"))!=0) nLinked++;
    if ((pglVertexAttrib3svNV = (PFNGLVERTEXATTRIB3SVNVPROC) __GLeeGetProcAddress("glVertexAttrib3svNV"))!=0) nLinked++;
    if ((pglVertexAttrib4dNV = (PFNGLVERTEXATTRIB4DNVPROC) __GLeeGetProcAddress("glVertexAttrib4dNV"))!=0) nLinked++;
    if ((pglVertexAttrib4dvNV = (PFNGLVERTEXATTRIB4DVNVPROC) __GLeeGetProcAddress("glVertexAttrib4dvNV"))!=0) nLinked++;
    if ((pglVertexAttrib4fNV = (PFNGLVERTEXATTRIB4FNVPROC) __GLeeGetProcAddress("glVertexAttrib4fNV"))!=0) nLinked++;
    if ((pglVertexAttrib4fvNV = (PFNGLVERTEXATTRIB4FVNVPROC) __GLeeGetProcAddress("glVertexAttrib4fvNV"))!=0) nLinked++;
    if ((pglVertexAttrib4sNV = (PFNGLVERTEXATTRIB4SNVPROC) __GLeeGetProcAddress("glVertexAttrib4sNV"))!=0) nLinked++;
    if ((pglVertexAttrib4svNV = (PFNGLVERTEXATTRIB4SVNVPROC) __GLeeGetProcAddress("glVertexAttrib4svNV"))!=0) nLinked++;
    if ((pglVertexAttrib4ubNV = (PFNGLVERTEXATTRIB4UBNVPROC) __GLeeGetProcAddress("glVertexAttrib4ubNV"))!=0) nLinked++;
    if ((pglVertexAttrib4ubvNV = (PFNGLVERTEXATTRIB4UBVNVPROC) __GLeeGetProcAddress("glVertexAttrib4ubvNV"))!=0) nLinked++;
    if ((pglVertexAttribs1dvNV = (PFNGLVERTEXATTRIBS1DVNVPROC) __GLeeGetProcAddress("glVertexAttribs1dvNV"))!=0) nLinked++;
    if ((pglVertexAttribs1fvNV = (PFNGLVERTEXATTRIBS1FVNVPROC) __GLeeGetProcAddress("glVertexAttribs1fvNV"))!=0) nLinked++;
    if ((pglVertexAttribs1svNV = (PFNGLVERTEXATTRIBS1SVNVPROC) __GLeeGetProcAddress("glVertexAttribs1svNV"))!=0) nLinked++;
    if ((pglVertexAttribs2dvNV = (PFNGLVERTEXATTRIBS2DVNVPROC) __GLeeGetProcAddress("glVertexAttribs2dvNV"))!=0) nLinked++;
    if ((pglVertexAttribs2fvNV = (PFNGLVERTEXATTRIBS2FVNVPROC) __GLeeGetProcAddress("glVertexAttribs2fvNV"))!=0) nLinked++;
    if ((pglVertexAttribs2svNV = (PFNGLVERTEXATTRIBS2SVNVPROC) __GLeeGetProcAddress("glVertexAttribs2svNV"))!=0) nLinked++;
    if ((pglVertexAttribs3dvNV = (PFNGLVERTEXATTRIBS3DVNVPROC) __GLeeGetProcAddress("glVertexAttribs3dvNV"))!=0) nLinked++;
    if ((pglVertexAttribs3fvNV = (PFNGLVERTEXATTRIBS3FVNVPROC) __GLeeGetProcAddress("glVertexAttribs3fvNV"))!=0) nLinked++;
    if ((pglVertexAttribs3svNV = (PFNGLVERTEXATTRIBS3SVNVPROC) __GLeeGetProcAddress("glVertexAttribs3svNV"))!=0) nLinked++;
    if ((pglVertexAttribs4dvNV = (PFNGLVERTEXATTRIBS4DVNVPROC) __GLeeGetProcAddress("glVertexAttribs4dvNV"))!=0) nLinked++;
    if ((pglVertexAttribs4fvNV = (PFNGLVERTEXATTRIBS4FVNVPROC) __GLeeGetProcAddress("glVertexAttribs4fvNV"))!=0) nLinked++;
    if ((pglVertexAttribs4svNV = (PFNGLVERTEXATTRIBS4SVNVPROC) __GLeeGetProcAddress("glVertexAttribs4svNV"))!=0) nLinked++;
    if ((pglVertexAttribs4ubvNV = (PFNGLVERTEXATTRIBS4UBVNVPROC) __GLeeGetProcAddress("glVertexAttribs4ubvNV"))!=0) nLinked++;
#endif
    if (nLinked==64) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_texture_coordinate_clamp(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_scalebias_hint(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_OML_interlace(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_OML_subsample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_OML_resample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_copy_depth_to_color(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ATI_envmap_bumpmap(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ATI_envmap_bumpmap
    if ((pglTexBumpParameterivATI = (PFNGLTEXBUMPPARAMETERIVATIPROC) __GLeeGetProcAddress("glTexBumpParameterivATI"))!=0) nLinked++;
    if ((pglTexBumpParameterfvATI = (PFNGLTEXBUMPPARAMETERFVATIPROC) __GLeeGetProcAddress("glTexBumpParameterfvATI"))!=0) nLinked++;
    if ((pglGetTexBumpParameterivATI = (PFNGLGETTEXBUMPPARAMETERIVATIPROC) __GLeeGetProcAddress("glGetTexBumpParameterivATI"))!=0) nLinked++;
    if ((pglGetTexBumpParameterfvATI = (PFNGLGETTEXBUMPPARAMETERFVATIPROC) __GLeeGetProcAddress("glGetTexBumpParameterfvATI"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ATI_fragment_shader(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ATI_fragment_shader
    if ((pglGenFragmentShadersATI = (PFNGLGENFRAGMENTSHADERSATIPROC) __GLeeGetProcAddress("glGenFragmentShadersATI"))!=0) nLinked++;
    if ((pglBindFragmentShaderATI = (PFNGLBINDFRAGMENTSHADERATIPROC) __GLeeGetProcAddress("glBindFragmentShaderATI"))!=0) nLinked++;
    if ((pglDeleteFragmentShaderATI = (PFNGLDELETEFRAGMENTSHADERATIPROC) __GLeeGetProcAddress("glDeleteFragmentShaderATI"))!=0) nLinked++;
    if ((pglBeginFragmentShaderATI = (PFNGLBEGINFRAGMENTSHADERATIPROC) __GLeeGetProcAddress("glBeginFragmentShaderATI"))!=0) nLinked++;
    if ((pglEndFragmentShaderATI = (PFNGLENDFRAGMENTSHADERATIPROC) __GLeeGetProcAddress("glEndFragmentShaderATI"))!=0) nLinked++;
    if ((pglPassTexCoordATI = (PFNGLPASSTEXCOORDATIPROC) __GLeeGetProcAddress("glPassTexCoordATI"))!=0) nLinked++;
    if ((pglSampleMapATI = (PFNGLSAMPLEMAPATIPROC) __GLeeGetProcAddress("glSampleMapATI"))!=0) nLinked++;
    if ((pglColorFragmentOp1ATI = (PFNGLCOLORFRAGMENTOP1ATIPROC) __GLeeGetProcAddress("glColorFragmentOp1ATI"))!=0) nLinked++;
    if ((pglColorFragmentOp2ATI = (PFNGLCOLORFRAGMENTOP2ATIPROC) __GLeeGetProcAddress("glColorFragmentOp2ATI"))!=0) nLinked++;
    if ((pglColorFragmentOp3ATI = (PFNGLCOLORFRAGMENTOP3ATIPROC) __GLeeGetProcAddress("glColorFragmentOp3ATI"))!=0) nLinked++;
    if ((pglAlphaFragmentOp1ATI = (PFNGLALPHAFRAGMENTOP1ATIPROC) __GLeeGetProcAddress("glAlphaFragmentOp1ATI"))!=0) nLinked++;
    if ((pglAlphaFragmentOp2ATI = (PFNGLALPHAFRAGMENTOP2ATIPROC) __GLeeGetProcAddress("glAlphaFragmentOp2ATI"))!=0) nLinked++;
    if ((pglAlphaFragmentOp3ATI = (PFNGLALPHAFRAGMENTOP3ATIPROC) __GLeeGetProcAddress("glAlphaFragmentOp3ATI"))!=0) nLinked++;
    if ((pglSetFragmentShaderConstantATI = (PFNGLSETFRAGMENTSHADERCONSTANTATIPROC) __GLeeGetProcAddress("glSetFragmentShaderConstantATI"))!=0) nLinked++;
#endif
    if (nLinked==14) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ATI_pn_triangles(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ATI_pn_triangles
    if ((pglPNTrianglesiATI = (PFNGLPNTRIANGLESIATIPROC) __GLeeGetProcAddress("glPNTrianglesiATI"))!=0) nLinked++;
    if ((pglPNTrianglesfATI = (PFNGLPNTRIANGLESFATIPROC) __GLeeGetProcAddress("glPNTrianglesfATI"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ATI_vertex_array_object(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ATI_vertex_array_object
    if ((pglNewObjectBufferATI = (PFNGLNEWOBJECTBUFFERATIPROC) __GLeeGetProcAddress("glNewObjectBufferATI"))!=0) nLinked++;
    if ((pglIsObjectBufferATI = (PFNGLISOBJECTBUFFERATIPROC) __GLeeGetProcAddress("glIsObjectBufferATI"))!=0) nLinked++;
    if ((pglUpdateObjectBufferATI = (PFNGLUPDATEOBJECTBUFFERATIPROC) __GLeeGetProcAddress("glUpdateObjectBufferATI"))!=0) nLinked++;
    if ((pglGetObjectBufferfvATI = (PFNGLGETOBJECTBUFFERFVATIPROC) __GLeeGetProcAddress("glGetObjectBufferfvATI"))!=0) nLinked++;
    if ((pglGetObjectBufferivATI = (PFNGLGETOBJECTBUFFERIVATIPROC) __GLeeGetProcAddress("glGetObjectBufferivATI"))!=0) nLinked++;
    if ((pglFreeObjectBufferATI = (PFNGLFREEOBJECTBUFFERATIPROC) __GLeeGetProcAddress("glFreeObjectBufferATI"))!=0) nLinked++;
    if ((pglArrayObjectATI = (PFNGLARRAYOBJECTATIPROC) __GLeeGetProcAddress("glArrayObjectATI"))!=0) nLinked++;
    if ((pglGetArrayObjectfvATI = (PFNGLGETARRAYOBJECTFVATIPROC) __GLeeGetProcAddress("glGetArrayObjectfvATI"))!=0) nLinked++;
    if ((pglGetArrayObjectivATI = (PFNGLGETARRAYOBJECTIVATIPROC) __GLeeGetProcAddress("glGetArrayObjectivATI"))!=0) nLinked++;
    if ((pglVariantArrayObjectATI = (PFNGLVARIANTARRAYOBJECTATIPROC) __GLeeGetProcAddress("glVariantArrayObjectATI"))!=0) nLinked++;
    if ((pglGetVariantArrayObjectfvATI = (PFNGLGETVARIANTARRAYOBJECTFVATIPROC) __GLeeGetProcAddress("glGetVariantArrayObjectfvATI"))!=0) nLinked++;
    if ((pglGetVariantArrayObjectivATI = (PFNGLGETVARIANTARRAYOBJECTIVATIPROC) __GLeeGetProcAddress("glGetVariantArrayObjectivATI"))!=0) nLinked++;
#endif
    if (nLinked==12) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_vertex_shader(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_vertex_shader
    if ((pglBeginVertexShaderEXT = (PFNGLBEGINVERTEXSHADEREXTPROC) __GLeeGetProcAddress("glBeginVertexShaderEXT"))!=0) nLinked++;
    if ((pglEndVertexShaderEXT = (PFNGLENDVERTEXSHADEREXTPROC) __GLeeGetProcAddress("glEndVertexShaderEXT"))!=0) nLinked++;
    if ((pglBindVertexShaderEXT = (PFNGLBINDVERTEXSHADEREXTPROC) __GLeeGetProcAddress("glBindVertexShaderEXT"))!=0) nLinked++;
    if ((pglGenVertexShadersEXT = (PFNGLGENVERTEXSHADERSEXTPROC) __GLeeGetProcAddress("glGenVertexShadersEXT"))!=0) nLinked++;
    if ((pglDeleteVertexShaderEXT = (PFNGLDELETEVERTEXSHADEREXTPROC) __GLeeGetProcAddress("glDeleteVertexShaderEXT"))!=0) nLinked++;
    if ((pglShaderOp1EXT = (PFNGLSHADEROP1EXTPROC) __GLeeGetProcAddress("glShaderOp1EXT"))!=0) nLinked++;
    if ((pglShaderOp2EXT = (PFNGLSHADEROP2EXTPROC) __GLeeGetProcAddress("glShaderOp2EXT"))!=0) nLinked++;
    if ((pglShaderOp3EXT = (PFNGLSHADEROP3EXTPROC) __GLeeGetProcAddress("glShaderOp3EXT"))!=0) nLinked++;
    if ((pglSwizzleEXT = (PFNGLSWIZZLEEXTPROC) __GLeeGetProcAddress("glSwizzleEXT"))!=0) nLinked++;
    if ((pglWriteMaskEXT = (PFNGLWRITEMASKEXTPROC) __GLeeGetProcAddress("glWriteMaskEXT"))!=0) nLinked++;
    if ((pglInsertComponentEXT = (PFNGLINSERTCOMPONENTEXTPROC) __GLeeGetProcAddress("glInsertComponentEXT"))!=0) nLinked++;
    if ((pglExtractComponentEXT = (PFNGLEXTRACTCOMPONENTEXTPROC) __GLeeGetProcAddress("glExtractComponentEXT"))!=0) nLinked++;
    if ((pglGenSymbolsEXT = (PFNGLGENSYMBOLSEXTPROC) __GLeeGetProcAddress("glGenSymbolsEXT"))!=0) nLinked++;
    if ((pglSetInvariantEXT = (PFNGLSETINVARIANTEXTPROC) __GLeeGetProcAddress("glSetInvariantEXT"))!=0) nLinked++;
    if ((pglSetLocalConstantEXT = (PFNGLSETLOCALCONSTANTEXTPROC) __GLeeGetProcAddress("glSetLocalConstantEXT"))!=0) nLinked++;
    if ((pglVariantbvEXT = (PFNGLVARIANTBVEXTPROC) __GLeeGetProcAddress("glVariantbvEXT"))!=0) nLinked++;
    if ((pglVariantsvEXT = (PFNGLVARIANTSVEXTPROC) __GLeeGetProcAddress("glVariantsvEXT"))!=0) nLinked++;
    if ((pglVariantivEXT = (PFNGLVARIANTIVEXTPROC) __GLeeGetProcAddress("glVariantivEXT"))!=0) nLinked++;
    if ((pglVariantfvEXT = (PFNGLVARIANTFVEXTPROC) __GLeeGetProcAddress("glVariantfvEXT"))!=0) nLinked++;
    if ((pglVariantdvEXT = (PFNGLVARIANTDVEXTPROC) __GLeeGetProcAddress("glVariantdvEXT"))!=0) nLinked++;
    if ((pglVariantubvEXT = (PFNGLVARIANTUBVEXTPROC) __GLeeGetProcAddress("glVariantubvEXT"))!=0) nLinked++;
    if ((pglVariantusvEXT = (PFNGLVARIANTUSVEXTPROC) __GLeeGetProcAddress("glVariantusvEXT"))!=0) nLinked++;
    if ((pglVariantuivEXT = (PFNGLVARIANTUIVEXTPROC) __GLeeGetProcAddress("glVariantuivEXT"))!=0) nLinked++;
    if ((pglVariantPointerEXT = (PFNGLVARIANTPOINTEREXTPROC) __GLeeGetProcAddress("glVariantPointerEXT"))!=0) nLinked++;
    if ((pglEnableVariantClientStateEXT = (PFNGLENABLEVARIANTCLIENTSTATEEXTPROC) __GLeeGetProcAddress("glEnableVariantClientStateEXT"))!=0) nLinked++;
    if ((pglDisableVariantClientStateEXT = (PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC) __GLeeGetProcAddress("glDisableVariantClientStateEXT"))!=0) nLinked++;
    if ((pglBindLightParameterEXT = (PFNGLBINDLIGHTPARAMETEREXTPROC) __GLeeGetProcAddress("glBindLightParameterEXT"))!=0) nLinked++;
    if ((pglBindMaterialParameterEXT = (PFNGLBINDMATERIALPARAMETEREXTPROC) __GLeeGetProcAddress("glBindMaterialParameterEXT"))!=0) nLinked++;
    if ((pglBindTexGenParameterEXT = (PFNGLBINDTEXGENPARAMETEREXTPROC) __GLeeGetProcAddress("glBindTexGenParameterEXT"))!=0) nLinked++;
    if ((pglBindTextureUnitParameterEXT = (PFNGLBINDTEXTUREUNITPARAMETEREXTPROC) __GLeeGetProcAddress("glBindTextureUnitParameterEXT"))!=0) nLinked++;
    if ((pglBindParameterEXT = (PFNGLBINDPARAMETEREXTPROC) __GLeeGetProcAddress("glBindParameterEXT"))!=0) nLinked++;
    if ((pglIsVariantEnabledEXT = (PFNGLISVARIANTENABLEDEXTPROC) __GLeeGetProcAddress("glIsVariantEnabledEXT"))!=0) nLinked++;
    if ((pglGetVariantBooleanvEXT = (PFNGLGETVARIANTBOOLEANVEXTPROC) __GLeeGetProcAddress("glGetVariantBooleanvEXT"))!=0) nLinked++;
    if ((pglGetVariantIntegervEXT = (PFNGLGETVARIANTINTEGERVEXTPROC) __GLeeGetProcAddress("glGetVariantIntegervEXT"))!=0) nLinked++;
    if ((pglGetVariantFloatvEXT = (PFNGLGETVARIANTFLOATVEXTPROC) __GLeeGetProcAddress("glGetVariantFloatvEXT"))!=0) nLinked++;
    if ((pglGetVariantPointervEXT = (PFNGLGETVARIANTPOINTERVEXTPROC) __GLeeGetProcAddress("glGetVariantPointervEXT"))!=0) nLinked++;
    if ((pglGetInvariantBooleanvEXT = (PFNGLGETINVARIANTBOOLEANVEXTPROC) __GLeeGetProcAddress("glGetInvariantBooleanvEXT"))!=0) nLinked++;
    if ((pglGetInvariantIntegervEXT = (PFNGLGETINVARIANTINTEGERVEXTPROC) __GLeeGetProcAddress("glGetInvariantIntegervEXT"))!=0) nLinked++;
    if ((pglGetInvariantFloatvEXT = (PFNGLGETINVARIANTFLOATVEXTPROC) __GLeeGetProcAddress("glGetInvariantFloatvEXT"))!=0) nLinked++;
    if ((pglGetLocalConstantBooleanvEXT = (PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC) __GLeeGetProcAddress("glGetLocalConstantBooleanvEXT"))!=0) nLinked++;
    if ((pglGetLocalConstantIntegervEXT = (PFNGLGETLOCALCONSTANTINTEGERVEXTPROC) __GLeeGetProcAddress("glGetLocalConstantIntegervEXT"))!=0) nLinked++;
    if ((pglGetLocalConstantFloatvEXT = (PFNGLGETLOCALCONSTANTFLOATVEXTPROC) __GLeeGetProcAddress("glGetLocalConstantFloatvEXT"))!=0) nLinked++;
#endif
    if (nLinked==42) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ATI_vertex_streams(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ATI_vertex_streams
    if ((pglVertexStream1sATI = (PFNGLVERTEXSTREAM1SATIPROC) __GLeeGetProcAddress("glVertexStream1sATI"))!=0) nLinked++;
    if ((pglVertexStream1svATI = (PFNGLVERTEXSTREAM1SVATIPROC) __GLeeGetProcAddress("glVertexStream1svATI"))!=0) nLinked++;
    if ((pglVertexStream1iATI = (PFNGLVERTEXSTREAM1IATIPROC) __GLeeGetProcAddress("glVertexStream1iATI"))!=0) nLinked++;
    if ((pglVertexStream1ivATI = (PFNGLVERTEXSTREAM1IVATIPROC) __GLeeGetProcAddress("glVertexStream1ivATI"))!=0) nLinked++;
    if ((pglVertexStream1fATI = (PFNGLVERTEXSTREAM1FATIPROC) __GLeeGetProcAddress("glVertexStream1fATI"))!=0) nLinked++;
    if ((pglVertexStream1fvATI = (PFNGLVERTEXSTREAM1FVATIPROC) __GLeeGetProcAddress("glVertexStream1fvATI"))!=0) nLinked++;
    if ((pglVertexStream1dATI = (PFNGLVERTEXSTREAM1DATIPROC) __GLeeGetProcAddress("glVertexStream1dATI"))!=0) nLinked++;
    if ((pglVertexStream1dvATI = (PFNGLVERTEXSTREAM1DVATIPROC) __GLeeGetProcAddress("glVertexStream1dvATI"))!=0) nLinked++;
    if ((pglVertexStream2sATI = (PFNGLVERTEXSTREAM2SATIPROC) __GLeeGetProcAddress("glVertexStream2sATI"))!=0) nLinked++;
    if ((pglVertexStream2svATI = (PFNGLVERTEXSTREAM2SVATIPROC) __GLeeGetProcAddress("glVertexStream2svATI"))!=0) nLinked++;
    if ((pglVertexStream2iATI = (PFNGLVERTEXSTREAM2IATIPROC) __GLeeGetProcAddress("glVertexStream2iATI"))!=0) nLinked++;
    if ((pglVertexStream2ivATI = (PFNGLVERTEXSTREAM2IVATIPROC) __GLeeGetProcAddress("glVertexStream2ivATI"))!=0) nLinked++;
    if ((pglVertexStream2fATI = (PFNGLVERTEXSTREAM2FATIPROC) __GLeeGetProcAddress("glVertexStream2fATI"))!=0) nLinked++;
    if ((pglVertexStream2fvATI = (PFNGLVERTEXSTREAM2FVATIPROC) __GLeeGetProcAddress("glVertexStream2fvATI"))!=0) nLinked++;
    if ((pglVertexStream2dATI = (PFNGLVERTEXSTREAM2DATIPROC) __GLeeGetProcAddress("glVertexStream2dATI"))!=0) nLinked++;
    if ((pglVertexStream2dvATI = (PFNGLVERTEXSTREAM2DVATIPROC) __GLeeGetProcAddress("glVertexStream2dvATI"))!=0) nLinked++;
    if ((pglVertexStream3sATI = (PFNGLVERTEXSTREAM3SATIPROC) __GLeeGetProcAddress("glVertexStream3sATI"))!=0) nLinked++;
    if ((pglVertexStream3svATI = (PFNGLVERTEXSTREAM3SVATIPROC) __GLeeGetProcAddress("glVertexStream3svATI"))!=0) nLinked++;
    if ((pglVertexStream3iATI = (PFNGLVERTEXSTREAM3IATIPROC) __GLeeGetProcAddress("glVertexStream3iATI"))!=0) nLinked++;
    if ((pglVertexStream3ivATI = (PFNGLVERTEXSTREAM3IVATIPROC) __GLeeGetProcAddress("glVertexStream3ivATI"))!=0) nLinked++;
    if ((pglVertexStream3fATI = (PFNGLVERTEXSTREAM3FATIPROC) __GLeeGetProcAddress("glVertexStream3fATI"))!=0) nLinked++;
    if ((pglVertexStream3fvATI = (PFNGLVERTEXSTREAM3FVATIPROC) __GLeeGetProcAddress("glVertexStream3fvATI"))!=0) nLinked++;
    if ((pglVertexStream3dATI = (PFNGLVERTEXSTREAM3DATIPROC) __GLeeGetProcAddress("glVertexStream3dATI"))!=0) nLinked++;
    if ((pglVertexStream3dvATI = (PFNGLVERTEXSTREAM3DVATIPROC) __GLeeGetProcAddress("glVertexStream3dvATI"))!=0) nLinked++;
    if ((pglVertexStream4sATI = (PFNGLVERTEXSTREAM4SATIPROC) __GLeeGetProcAddress("glVertexStream4sATI"))!=0) nLinked++;
    if ((pglVertexStream4svATI = (PFNGLVERTEXSTREAM4SVATIPROC) __GLeeGetProcAddress("glVertexStream4svATI"))!=0) nLinked++;
    if ((pglVertexStream4iATI = (PFNGLVERTEXSTREAM4IATIPROC) __GLeeGetProcAddress("glVertexStream4iATI"))!=0) nLinked++;
    if ((pglVertexStream4ivATI = (PFNGLVERTEXSTREAM4IVATIPROC) __GLeeGetProcAddress("glVertexStream4ivATI"))!=0) nLinked++;
    if ((pglVertexStream4fATI = (PFNGLVERTEXSTREAM4FATIPROC) __GLeeGetProcAddress("glVertexStream4fATI"))!=0) nLinked++;
    if ((pglVertexStream4fvATI = (PFNGLVERTEXSTREAM4FVATIPROC) __GLeeGetProcAddress("glVertexStream4fvATI"))!=0) nLinked++;
    if ((pglVertexStream4dATI = (PFNGLVERTEXSTREAM4DATIPROC) __GLeeGetProcAddress("glVertexStream4dATI"))!=0) nLinked++;
    if ((pglVertexStream4dvATI = (PFNGLVERTEXSTREAM4DVATIPROC) __GLeeGetProcAddress("glVertexStream4dvATI"))!=0) nLinked++;
    if ((pglNormalStream3bATI = (PFNGLNORMALSTREAM3BATIPROC) __GLeeGetProcAddress("glNormalStream3bATI"))!=0) nLinked++;
    if ((pglNormalStream3bvATI = (PFNGLNORMALSTREAM3BVATIPROC) __GLeeGetProcAddress("glNormalStream3bvATI"))!=0) nLinked++;
    if ((pglNormalStream3sATI = (PFNGLNORMALSTREAM3SATIPROC) __GLeeGetProcAddress("glNormalStream3sATI"))!=0) nLinked++;
    if ((pglNormalStream3svATI = (PFNGLNORMALSTREAM3SVATIPROC) __GLeeGetProcAddress("glNormalStream3svATI"))!=0) nLinked++;
    if ((pglNormalStream3iATI = (PFNGLNORMALSTREAM3IATIPROC) __GLeeGetProcAddress("glNormalStream3iATI"))!=0) nLinked++;
    if ((pglNormalStream3ivATI = (PFNGLNORMALSTREAM3IVATIPROC) __GLeeGetProcAddress("glNormalStream3ivATI"))!=0) nLinked++;
    if ((pglNormalStream3fATI = (PFNGLNORMALSTREAM3FATIPROC) __GLeeGetProcAddress("glNormalStream3fATI"))!=0) nLinked++;
    if ((pglNormalStream3fvATI = (PFNGLNORMALSTREAM3FVATIPROC) __GLeeGetProcAddress("glNormalStream3fvATI"))!=0) nLinked++;
    if ((pglNormalStream3dATI = (PFNGLNORMALSTREAM3DATIPROC) __GLeeGetProcAddress("glNormalStream3dATI"))!=0) nLinked++;
    if ((pglNormalStream3dvATI = (PFNGLNORMALSTREAM3DVATIPROC) __GLeeGetProcAddress("glNormalStream3dvATI"))!=0) nLinked++;
    if ((pglClientActiveVertexStreamATI = (PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC) __GLeeGetProcAddress("glClientActiveVertexStreamATI"))!=0) nLinked++;
    if ((pglVertexBlendEnviATI = (PFNGLVERTEXBLENDENVIATIPROC) __GLeeGetProcAddress("glVertexBlendEnviATI"))!=0) nLinked++;
    if ((pglVertexBlendEnvfATI = (PFNGLVERTEXBLENDENVFATIPROC) __GLeeGetProcAddress("glVertexBlendEnvfATI"))!=0) nLinked++;
#endif
    if (nLinked==45) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ATI_element_array(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ATI_element_array
    if ((pglElementPointerATI = (PFNGLELEMENTPOINTERATIPROC) __GLeeGetProcAddress("glElementPointerATI"))!=0) nLinked++;
    if ((pglDrawElementArrayATI = (PFNGLDRAWELEMENTARRAYATIPROC) __GLeeGetProcAddress("glDrawElementArrayATI"))!=0) nLinked++;
    if ((pglDrawRangeElementArrayATI = (PFNGLDRAWRANGEELEMENTARRAYATIPROC) __GLeeGetProcAddress("glDrawRangeElementArrayATI"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SUN_mesh_array(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SUN_mesh_array
    if ((pglDrawMeshArraysSUN = (PFNGLDRAWMESHARRAYSSUNPROC) __GLeeGetProcAddress("glDrawMeshArraysSUN"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SUN_slice_accum(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_multisample_filter_hint(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_depth_clamp(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_occlusion_query(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_occlusion_query
    if ((pglGenOcclusionQueriesNV = (PFNGLGENOCCLUSIONQUERIESNVPROC) __GLeeGetProcAddress("glGenOcclusionQueriesNV"))!=0) nLinked++;
    if ((pglDeleteOcclusionQueriesNV = (PFNGLDELETEOCCLUSIONQUERIESNVPROC) __GLeeGetProcAddress("glDeleteOcclusionQueriesNV"))!=0) nLinked++;
    if ((pglIsOcclusionQueryNV = (PFNGLISOCCLUSIONQUERYNVPROC) __GLeeGetProcAddress("glIsOcclusionQueryNV"))!=0) nLinked++;
    if ((pglBeginOcclusionQueryNV = (PFNGLBEGINOCCLUSIONQUERYNVPROC) __GLeeGetProcAddress("glBeginOcclusionQueryNV"))!=0) nLinked++;
    if ((pglEndOcclusionQueryNV = (PFNGLENDOCCLUSIONQUERYNVPROC) __GLeeGetProcAddress("glEndOcclusionQueryNV"))!=0) nLinked++;
    if ((pglGetOcclusionQueryivNV = (PFNGLGETOCCLUSIONQUERYIVNVPROC) __GLeeGetProcAddress("glGetOcclusionQueryivNV"))!=0) nLinked++;
    if ((pglGetOcclusionQueryuivNV = (PFNGLGETOCCLUSIONQUERYUIVNVPROC) __GLeeGetProcAddress("glGetOcclusionQueryuivNV"))!=0) nLinked++;
#endif
    if (nLinked==7) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_point_sprite(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_point_sprite
    if ((pglPointParameteriNV = (PFNGLPOINTPARAMETERINVPROC) __GLeeGetProcAddress("glPointParameteriNV"))!=0) nLinked++;
    if ((pglPointParameterivNV = (PFNGLPOINTPARAMETERIVNVPROC) __GLeeGetProcAddress("glPointParameterivNV"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_texture_shader3(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_vertex_program1_1(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_shadow_funcs(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_stencil_two_side(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_stencil_two_side
    if ((pglActiveStencilFaceEXT = (PFNGLACTIVESTENCILFACEEXTPROC) __GLeeGetProcAddress("glActiveStencilFaceEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ATI_text_fragment_shader(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_APPLE_client_storage(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_APPLE_element_array(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_APPLE_element_array
    if ((pglElementPointerAPPLE = (PFNGLELEMENTPOINTERAPPLEPROC) __GLeeGetProcAddress("glElementPointerAPPLE"))!=0) nLinked++;
    if ((pglDrawElementArrayAPPLE = (PFNGLDRAWELEMENTARRAYAPPLEPROC) __GLeeGetProcAddress("glDrawElementArrayAPPLE"))!=0) nLinked++;
    if ((pglDrawRangeElementArrayAPPLE = (PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC) __GLeeGetProcAddress("glDrawRangeElementArrayAPPLE"))!=0) nLinked++;
    if ((pglMultiDrawElementArrayAPPLE = (PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC) __GLeeGetProcAddress("glMultiDrawElementArrayAPPLE"))!=0) nLinked++;
    if ((pglMultiDrawRangeElementArrayAPPLE = (PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC) __GLeeGetProcAddress("glMultiDrawRangeElementArrayAPPLE"))!=0) nLinked++;
#endif
    if (nLinked==5) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_APPLE_fence(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_APPLE_fence
    if ((pglGenFencesAPPLE = (PFNGLGENFENCESAPPLEPROC) __GLeeGetProcAddress("glGenFencesAPPLE"))!=0) nLinked++;
    if ((pglDeleteFencesAPPLE = (PFNGLDELETEFENCESAPPLEPROC) __GLeeGetProcAddress("glDeleteFencesAPPLE"))!=0) nLinked++;
    if ((pglSetFenceAPPLE = (PFNGLSETFENCEAPPLEPROC) __GLeeGetProcAddress("glSetFenceAPPLE"))!=0) nLinked++;
    if ((pglIsFenceAPPLE = (PFNGLISFENCEAPPLEPROC) __GLeeGetProcAddress("glIsFenceAPPLE"))!=0) nLinked++;
    if ((pglTestFenceAPPLE = (PFNGLTESTFENCEAPPLEPROC) __GLeeGetProcAddress("glTestFenceAPPLE"))!=0) nLinked++;
    if ((pglFinishFenceAPPLE = (PFNGLFINISHFENCEAPPLEPROC) __GLeeGetProcAddress("glFinishFenceAPPLE"))!=0) nLinked++;
    if ((pglTestObjectAPPLE = (PFNGLTESTOBJECTAPPLEPROC) __GLeeGetProcAddress("glTestObjectAPPLE"))!=0) nLinked++;
    if ((pglFinishObjectAPPLE = (PFNGLFINISHOBJECTAPPLEPROC) __GLeeGetProcAddress("glFinishObjectAPPLE"))!=0) nLinked++;
#endif
    if (nLinked==8) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_APPLE_vertex_array_object(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_APPLE_vertex_array_object
    if ((pglBindVertexArrayAPPLE = (PFNGLBINDVERTEXARRAYAPPLEPROC) __GLeeGetProcAddress("glBindVertexArrayAPPLE"))!=0) nLinked++;
    if ((pglDeleteVertexArraysAPPLE = (PFNGLDELETEVERTEXARRAYSAPPLEPROC) __GLeeGetProcAddress("glDeleteVertexArraysAPPLE"))!=0) nLinked++;
    if ((pglGenVertexArraysAPPLE = (PFNGLGENVERTEXARRAYSAPPLEPROC) __GLeeGetProcAddress("glGenVertexArraysAPPLE"))!=0) nLinked++;
    if ((pglIsVertexArrayAPPLE = (PFNGLISVERTEXARRAYAPPLEPROC) __GLeeGetProcAddress("glIsVertexArrayAPPLE"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_APPLE_vertex_array_range(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_APPLE_vertex_array_range
    if ((pglVertexArrayRangeAPPLE = (PFNGLVERTEXARRAYRANGEAPPLEPROC) __GLeeGetProcAddress("glVertexArrayRangeAPPLE"))!=0) nLinked++;
    if ((pglFlushVertexArrayRangeAPPLE = (PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC) __GLeeGetProcAddress("glFlushVertexArrayRangeAPPLE"))!=0) nLinked++;
    if ((pglVertexArrayParameteriAPPLE = (PFNGLVERTEXARRAYPARAMETERIAPPLEPROC) __GLeeGetProcAddress("glVertexArrayParameteriAPPLE"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_APPLE_ycbcr_422(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_S3_s3tc(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ATI_draw_buffers(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ATI_draw_buffers
    if ((pglDrawBuffersATI = (PFNGLDRAWBUFFERSATIPROC) __GLeeGetProcAddress("glDrawBuffersATI"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ATI_pixel_format_float(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ATI_texture_env_combine3(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ATI_texture_float(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_float_buffer(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_fragment_program(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_fragment_program
    if ((pglProgramNamedParameter4fNV = (PFNGLPROGRAMNAMEDPARAMETER4FNVPROC) __GLeeGetProcAddress("glProgramNamedParameter4fNV"))!=0) nLinked++;
    if ((pglProgramNamedParameter4dNV = (PFNGLPROGRAMNAMEDPARAMETER4DNVPROC) __GLeeGetProcAddress("glProgramNamedParameter4dNV"))!=0) nLinked++;
    if ((pglProgramNamedParameter4fvNV = (PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC) __GLeeGetProcAddress("glProgramNamedParameter4fvNV"))!=0) nLinked++;
    if ((pglProgramNamedParameter4dvNV = (PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC) __GLeeGetProcAddress("glProgramNamedParameter4dvNV"))!=0) nLinked++;
    if ((pglGetProgramNamedParameterfvNV = (PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC) __GLeeGetProcAddress("glGetProgramNamedParameterfvNV"))!=0) nLinked++;
    if ((pglGetProgramNamedParameterdvNV = (PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC) __GLeeGetProcAddress("glGetProgramNamedParameterdvNV"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_half_float(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_half_float
    if ((pglVertex2hNV = (PFNGLVERTEX2HNVPROC) __GLeeGetProcAddress("glVertex2hNV"))!=0) nLinked++;
    if ((pglVertex2hvNV = (PFNGLVERTEX2HVNVPROC) __GLeeGetProcAddress("glVertex2hvNV"))!=0) nLinked++;
    if ((pglVertex3hNV = (PFNGLVERTEX3HNVPROC) __GLeeGetProcAddress("glVertex3hNV"))!=0) nLinked++;
    if ((pglVertex3hvNV = (PFNGLVERTEX3HVNVPROC) __GLeeGetProcAddress("glVertex3hvNV"))!=0) nLinked++;
    if ((pglVertex4hNV = (PFNGLVERTEX4HNVPROC) __GLeeGetProcAddress("glVertex4hNV"))!=0) nLinked++;
    if ((pglVertex4hvNV = (PFNGLVERTEX4HVNVPROC) __GLeeGetProcAddress("glVertex4hvNV"))!=0) nLinked++;
    if ((pglNormal3hNV = (PFNGLNORMAL3HNVPROC) __GLeeGetProcAddress("glNormal3hNV"))!=0) nLinked++;
    if ((pglNormal3hvNV = (PFNGLNORMAL3HVNVPROC) __GLeeGetProcAddress("glNormal3hvNV"))!=0) nLinked++;
    if ((pglColor3hNV = (PFNGLCOLOR3HNVPROC) __GLeeGetProcAddress("glColor3hNV"))!=0) nLinked++;
    if ((pglColor3hvNV = (PFNGLCOLOR3HVNVPROC) __GLeeGetProcAddress("glColor3hvNV"))!=0) nLinked++;
    if ((pglColor4hNV = (PFNGLCOLOR4HNVPROC) __GLeeGetProcAddress("glColor4hNV"))!=0) nLinked++;
    if ((pglColor4hvNV = (PFNGLCOLOR4HVNVPROC) __GLeeGetProcAddress("glColor4hvNV"))!=0) nLinked++;
    if ((pglTexCoord1hNV = (PFNGLTEXCOORD1HNVPROC) __GLeeGetProcAddress("glTexCoord1hNV"))!=0) nLinked++;
    if ((pglTexCoord1hvNV = (PFNGLTEXCOORD1HVNVPROC) __GLeeGetProcAddress("glTexCoord1hvNV"))!=0) nLinked++;
    if ((pglTexCoord2hNV = (PFNGLTEXCOORD2HNVPROC) __GLeeGetProcAddress("glTexCoord2hNV"))!=0) nLinked++;
    if ((pglTexCoord2hvNV = (PFNGLTEXCOORD2HVNVPROC) __GLeeGetProcAddress("glTexCoord2hvNV"))!=0) nLinked++;
    if ((pglTexCoord3hNV = (PFNGLTEXCOORD3HNVPROC) __GLeeGetProcAddress("glTexCoord3hNV"))!=0) nLinked++;
    if ((pglTexCoord3hvNV = (PFNGLTEXCOORD3HVNVPROC) __GLeeGetProcAddress("glTexCoord3hvNV"))!=0) nLinked++;
    if ((pglTexCoord4hNV = (PFNGLTEXCOORD4HNVPROC) __GLeeGetProcAddress("glTexCoord4hNV"))!=0) nLinked++;
    if ((pglTexCoord4hvNV = (PFNGLTEXCOORD4HVNVPROC) __GLeeGetProcAddress("glTexCoord4hvNV"))!=0) nLinked++;
    if ((pglMultiTexCoord1hNV = (PFNGLMULTITEXCOORD1HNVPROC) __GLeeGetProcAddress("glMultiTexCoord1hNV"))!=0) nLinked++;
    if ((pglMultiTexCoord1hvNV = (PFNGLMULTITEXCOORD1HVNVPROC) __GLeeGetProcAddress("glMultiTexCoord1hvNV"))!=0) nLinked++;
    if ((pglMultiTexCoord2hNV = (PFNGLMULTITEXCOORD2HNVPROC) __GLeeGetProcAddress("glMultiTexCoord2hNV"))!=0) nLinked++;
    if ((pglMultiTexCoord2hvNV = (PFNGLMULTITEXCOORD2HVNVPROC) __GLeeGetProcAddress("glMultiTexCoord2hvNV"))!=0) nLinked++;
    if ((pglMultiTexCoord3hNV = (PFNGLMULTITEXCOORD3HNVPROC) __GLeeGetProcAddress("glMultiTexCoord3hNV"))!=0) nLinked++;
    if ((pglMultiTexCoord3hvNV = (PFNGLMULTITEXCOORD3HVNVPROC) __GLeeGetProcAddress("glMultiTexCoord3hvNV"))!=0) nLinked++;
    if ((pglMultiTexCoord4hNV = (PFNGLMULTITEXCOORD4HNVPROC) __GLeeGetProcAddress("glMultiTexCoord4hNV"))!=0) nLinked++;
    if ((pglMultiTexCoord4hvNV = (PFNGLMULTITEXCOORD4HVNVPROC) __GLeeGetProcAddress("glMultiTexCoord4hvNV"))!=0) nLinked++;
    if ((pglFogCoordhNV = (PFNGLFOGCOORDHNVPROC) __GLeeGetProcAddress("glFogCoordhNV"))!=0) nLinked++;
    if ((pglFogCoordhvNV = (PFNGLFOGCOORDHVNVPROC) __GLeeGetProcAddress("glFogCoordhvNV"))!=0) nLinked++;
    if ((pglSecondaryColor3hNV = (PFNGLSECONDARYCOLOR3HNVPROC) __GLeeGetProcAddress("glSecondaryColor3hNV"))!=0) nLinked++;
    if ((pglSecondaryColor3hvNV = (PFNGLSECONDARYCOLOR3HVNVPROC) __GLeeGetProcAddress("glSecondaryColor3hvNV"))!=0) nLinked++;
    if ((pglVertexWeighthNV = (PFNGLVERTEXWEIGHTHNVPROC) __GLeeGetProcAddress("glVertexWeighthNV"))!=0) nLinked++;
    if ((pglVertexWeighthvNV = (PFNGLVERTEXWEIGHTHVNVPROC) __GLeeGetProcAddress("glVertexWeighthvNV"))!=0) nLinked++;
    if ((pglVertexAttrib1hNV = (PFNGLVERTEXATTRIB1HNVPROC) __GLeeGetProcAddress("glVertexAttrib1hNV"))!=0) nLinked++;
    if ((pglVertexAttrib1hvNV = (PFNGLVERTEXATTRIB1HVNVPROC) __GLeeGetProcAddress("glVertexAttrib1hvNV"))!=0) nLinked++;
    if ((pglVertexAttrib2hNV = (PFNGLVERTEXATTRIB2HNVPROC) __GLeeGetProcAddress("glVertexAttrib2hNV"))!=0) nLinked++;
    if ((pglVertexAttrib2hvNV = (PFNGLVERTEXATTRIB2HVNVPROC) __GLeeGetProcAddress("glVertexAttrib2hvNV"))!=0) nLinked++;
    if ((pglVertexAttrib3hNV = (PFNGLVERTEXATTRIB3HNVPROC) __GLeeGetProcAddress("glVertexAttrib3hNV"))!=0) nLinked++;
    if ((pglVertexAttrib3hvNV = (PFNGLVERTEXATTRIB3HVNVPROC) __GLeeGetProcAddress("glVertexAttrib3hvNV"))!=0) nLinked++;
    if ((pglVertexAttrib4hNV = (PFNGLVERTEXATTRIB4HNVPROC) __GLeeGetProcAddress("glVertexAttrib4hNV"))!=0) nLinked++;
    if ((pglVertexAttrib4hvNV = (PFNGLVERTEXATTRIB4HVNVPROC) __GLeeGetProcAddress("glVertexAttrib4hvNV"))!=0) nLinked++;
    if ((pglVertexAttribs1hvNV = (PFNGLVERTEXATTRIBS1HVNVPROC) __GLeeGetProcAddress("glVertexAttribs1hvNV"))!=0) nLinked++;
    if ((pglVertexAttribs2hvNV = (PFNGLVERTEXATTRIBS2HVNVPROC) __GLeeGetProcAddress("glVertexAttribs2hvNV"))!=0) nLinked++;
    if ((pglVertexAttribs3hvNV = (PFNGLVERTEXATTRIBS3HVNVPROC) __GLeeGetProcAddress("glVertexAttribs3hvNV"))!=0) nLinked++;
    if ((pglVertexAttribs4hvNV = (PFNGLVERTEXATTRIBS4HVNVPROC) __GLeeGetProcAddress("glVertexAttribs4hvNV"))!=0) nLinked++;
#endif
    if (nLinked==46) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_pixel_data_range(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_pixel_data_range
    if ((pglPixelDataRangeNV = (PFNGLPIXELDATARANGENVPROC) __GLeeGetProcAddress("glPixelDataRangeNV"))!=0) nLinked++;
    if ((pglFlushPixelDataRangeNV = (PFNGLFLUSHPIXELDATARANGENVPROC) __GLeeGetProcAddress("glFlushPixelDataRangeNV"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_primitive_restart(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_primitive_restart
    if ((pglPrimitiveRestartNV = (PFNGLPRIMITIVERESTARTNVPROC) __GLeeGetProcAddress("glPrimitiveRestartNV"))!=0) nLinked++;
    if ((pglPrimitiveRestartIndexNV = (PFNGLPRIMITIVERESTARTINDEXNVPROC) __GLeeGetProcAddress("glPrimitiveRestartIndexNV"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_texture_expand_normal(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_vertex_program2(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_ATI_map_object_buffer(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ATI_map_object_buffer
    if ((pglMapObjectBufferATI = (PFNGLMAPOBJECTBUFFERATIPROC) __GLeeGetProcAddress("glMapObjectBufferATI"))!=0) nLinked++;
    if ((pglUnmapObjectBufferATI = (PFNGLUNMAPOBJECTBUFFERATIPROC) __GLeeGetProcAddress("glUnmapObjectBufferATI"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ATI_separate_stencil(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ATI_separate_stencil
    if ((pglStencilOpSeparateATI = (PFNGLSTENCILOPSEPARATEATIPROC) __GLeeGetProcAddress("glStencilOpSeparateATI"))!=0) nLinked++;
    if ((pglStencilFuncSeparateATI = (PFNGLSTENCILFUNCSEPARATEATIPROC) __GLeeGetProcAddress("glStencilFuncSeparateATI"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_ATI_vertex_attrib_array_object(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_ATI_vertex_attrib_array_object
    if ((pglVertexAttribArrayObjectATI = (PFNGLVERTEXATTRIBARRAYOBJECTATIPROC) __GLeeGetProcAddress("glVertexAttribArrayObjectATI"))!=0) nLinked++;
    if ((pglGetVertexAttribArrayObjectfvATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC) __GLeeGetProcAddress("glGetVertexAttribArrayObjectfvATI"))!=0) nLinked++;
    if ((pglGetVertexAttribArrayObjectivATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC) __GLeeGetProcAddress("glGetVertexAttribArrayObjectivATI"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_OES_read_format(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_depth_bounds_test(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_depth_bounds_test
    if ((pglDepthBoundsEXT = (PFNGLDEPTHBOUNDSEXTPROC) __GLeeGetProcAddress("glDepthBoundsEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_texture_mirror_clamp(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_blend_equation_separate(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_blend_equation_separate
    if ((pglBlendEquationSeparateEXT = (PFNGLBLENDEQUATIONSEPARATEEXTPROC) __GLeeGetProcAddress("glBlendEquationSeparateEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_MESA_pack_invert(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_MESA_ycbcr_texture(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_pixel_buffer_object(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_fragment_program_option(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_fragment_program2(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_vertex_program2_option(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_vertex_program3(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_framebuffer_object(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_framebuffer_object
    if ((pglIsRenderbufferEXT = (PFNGLISRENDERBUFFEREXTPROC) __GLeeGetProcAddress("glIsRenderbufferEXT"))!=0) nLinked++;
    if ((pglBindRenderbufferEXT = (PFNGLBINDRENDERBUFFEREXTPROC) __GLeeGetProcAddress("glBindRenderbufferEXT"))!=0) nLinked++;
    if ((pglDeleteRenderbuffersEXT = (PFNGLDELETERENDERBUFFERSEXTPROC) __GLeeGetProcAddress("glDeleteRenderbuffersEXT"))!=0) nLinked++;
    if ((pglGenRenderbuffersEXT = (PFNGLGENRENDERBUFFERSEXTPROC) __GLeeGetProcAddress("glGenRenderbuffersEXT"))!=0) nLinked++;
    if ((pglRenderbufferStorageEXT = (PFNGLRENDERBUFFERSTORAGEEXTPROC) __GLeeGetProcAddress("glRenderbufferStorageEXT"))!=0) nLinked++;
    if ((pglGetRenderbufferParameterivEXT = (PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC) __GLeeGetProcAddress("glGetRenderbufferParameterivEXT"))!=0) nLinked++;
    if ((pglIsFramebufferEXT = (PFNGLISFRAMEBUFFEREXTPROC) __GLeeGetProcAddress("glIsFramebufferEXT"))!=0) nLinked++;
    if ((pglBindFramebufferEXT = (PFNGLBINDFRAMEBUFFEREXTPROC) __GLeeGetProcAddress("glBindFramebufferEXT"))!=0) nLinked++;
    if ((pglDeleteFramebuffersEXT = (PFNGLDELETEFRAMEBUFFERSEXTPROC) __GLeeGetProcAddress("glDeleteFramebuffersEXT"))!=0) nLinked++;
    if ((pglGenFramebuffersEXT = (PFNGLGENFRAMEBUFFERSEXTPROC) __GLeeGetProcAddress("glGenFramebuffersEXT"))!=0) nLinked++;
    if ((pglCheckFramebufferStatusEXT = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC) __GLeeGetProcAddress("glCheckFramebufferStatusEXT"))!=0) nLinked++;
    if ((pglFramebufferTexture1DEXT = (PFNGLFRAMEBUFFERTEXTURE1DEXTPROC) __GLeeGetProcAddress("glFramebufferTexture1DEXT"))!=0) nLinked++;
    if ((pglFramebufferTexture2DEXT = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC) __GLeeGetProcAddress("glFramebufferTexture2DEXT"))!=0) nLinked++;
    if ((pglFramebufferTexture3DEXT = (PFNGLFRAMEBUFFERTEXTURE3DEXTPROC) __GLeeGetProcAddress("glFramebufferTexture3DEXT"))!=0) nLinked++;
    if ((pglFramebufferRenderbufferEXT = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC) __GLeeGetProcAddress("glFramebufferRenderbufferEXT"))!=0) nLinked++;
    if ((pglGetFramebufferAttachmentParameterivEXT = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) __GLeeGetProcAddress("glGetFramebufferAttachmentParameterivEXT"))!=0) nLinked++;
    if ((pglGenerateMipmapEXT = (PFNGLGENERATEMIPMAPEXTPROC) __GLeeGetProcAddress("glGenerateMipmapEXT"))!=0) nLinked++;
#endif
    if (nLinked==17) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_GREMEDY_string_marker(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_GREMEDY_string_marker
    if ((pglStringMarkerGREMEDY = (PFNGLSTRINGMARKERGREMEDYPROC) __GLeeGetProcAddress("glStringMarkerGREMEDY"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_Cg_shader(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_timer_query(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_timer_query
    if ((pglGetQueryObjecti64vEXT = (PFNGLGETQUERYOBJECTI64VEXTPROC) __GLeeGetProcAddress("glGetQueryObjecti64vEXT"))!=0) nLinked++;
    if ((pglGetQueryObjectui64vEXT = (PFNGLGETQUERYOBJECTUI64VEXTPROC) __GLeeGetProcAddress("glGetQueryObjectui64vEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_texture_buffer_object(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_texture_buffer_object
    if ((pglTexBufferEXT = (PFNGLTEXBUFFEREXTPROC) __GLeeGetProcAddress("glTexBufferEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_gpu_shader4(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_gpu_shader4
    if ((pglGetUniformuivEXT = (PFNGLGETUNIFORMUIVEXTPROC) __GLeeGetProcAddress("glGetUniformuivEXT"))!=0) nLinked++;
    if ((pglBindFragDataLocationEXT = (PFNGLBINDFRAGDATALOCATIONEXTPROC) __GLeeGetProcAddress("glBindFragDataLocationEXT"))!=0) nLinked++;
    if ((pglGetFragDataLocationEXT = (PFNGLGETFRAGDATALOCATIONEXTPROC) __GLeeGetProcAddress("glGetFragDataLocationEXT"))!=0) nLinked++;
    if ((pglUniform1uiEXT = (PFNGLUNIFORM1UIEXTPROC) __GLeeGetProcAddress("glUniform1uiEXT"))!=0) nLinked++;
    if ((pglUniform2uiEXT = (PFNGLUNIFORM2UIEXTPROC) __GLeeGetProcAddress("glUniform2uiEXT"))!=0) nLinked++;
    if ((pglUniform3uiEXT = (PFNGLUNIFORM3UIEXTPROC) __GLeeGetProcAddress("glUniform3uiEXT"))!=0) nLinked++;
    if ((pglUniform4uiEXT = (PFNGLUNIFORM4UIEXTPROC) __GLeeGetProcAddress("glUniform4uiEXT"))!=0) nLinked++;
    if ((pglUniform1uivEXT = (PFNGLUNIFORM1UIVEXTPROC) __GLeeGetProcAddress("glUniform1uivEXT"))!=0) nLinked++;
    if ((pglUniform2uivEXT = (PFNGLUNIFORM2UIVEXTPROC) __GLeeGetProcAddress("glUniform2uivEXT"))!=0) nLinked++;
    if ((pglUniform3uivEXT = (PFNGLUNIFORM3UIVEXTPROC) __GLeeGetProcAddress("glUniform3uivEXT"))!=0) nLinked++;
    if ((pglUniform4uivEXT = (PFNGLUNIFORM4UIVEXTPROC) __GLeeGetProcAddress("glUniform4uivEXT"))!=0) nLinked++;
    if ((pglVertexAttribI1iEXT = (PFNGLVERTEXATTRIBI1IEXTPROC) __GLeeGetProcAddress("glVertexAttribI1iEXT"))!=0) nLinked++;
    if ((pglVertexAttribI2iEXT = (PFNGLVERTEXATTRIBI2IEXTPROC) __GLeeGetProcAddress("glVertexAttribI2iEXT"))!=0) nLinked++;
    if ((pglVertexAttribI3iEXT = (PFNGLVERTEXATTRIBI3IEXTPROC) __GLeeGetProcAddress("glVertexAttribI3iEXT"))!=0) nLinked++;
    if ((pglVertexAttribI4iEXT = (PFNGLVERTEXATTRIBI4IEXTPROC) __GLeeGetProcAddress("glVertexAttribI4iEXT"))!=0) nLinked++;
    if ((pglVertexAttribI1uiEXT = (PFNGLVERTEXATTRIBI1UIEXTPROC) __GLeeGetProcAddress("glVertexAttribI1uiEXT"))!=0) nLinked++;
    if ((pglVertexAttribI2uiEXT = (PFNGLVERTEXATTRIBI2UIEXTPROC) __GLeeGetProcAddress("glVertexAttribI2uiEXT"))!=0) nLinked++;
    if ((pglVertexAttribI3uiEXT = (PFNGLVERTEXATTRIBI3UIEXTPROC) __GLeeGetProcAddress("glVertexAttribI3uiEXT"))!=0) nLinked++;
    if ((pglVertexAttribI4uiEXT = (PFNGLVERTEXATTRIBI4UIEXTPROC) __GLeeGetProcAddress("glVertexAttribI4uiEXT"))!=0) nLinked++;
    if ((pglVertexAttribI1ivEXT = (PFNGLVERTEXATTRIBI1IVEXTPROC) __GLeeGetProcAddress("glVertexAttribI1ivEXT"))!=0) nLinked++;
    if ((pglVertexAttribI2ivEXT = (PFNGLVERTEXATTRIBI2IVEXTPROC) __GLeeGetProcAddress("glVertexAttribI2ivEXT"))!=0) nLinked++;
    if ((pglVertexAttribI3ivEXT = (PFNGLVERTEXATTRIBI3IVEXTPROC) __GLeeGetProcAddress("glVertexAttribI3ivEXT"))!=0) nLinked++;
    if ((pglVertexAttribI4ivEXT = (PFNGLVERTEXATTRIBI4IVEXTPROC) __GLeeGetProcAddress("glVertexAttribI4ivEXT"))!=0) nLinked++;
    if ((pglVertexAttribI1uivEXT = (PFNGLVERTEXATTRIBI1UIVEXTPROC) __GLeeGetProcAddress("glVertexAttribI1uivEXT"))!=0) nLinked++;
    if ((pglVertexAttribI2uivEXT = (PFNGLVERTEXATTRIBI2UIVEXTPROC) __GLeeGetProcAddress("glVertexAttribI2uivEXT"))!=0) nLinked++;
    if ((pglVertexAttribI3uivEXT = (PFNGLVERTEXATTRIBI3UIVEXTPROC) __GLeeGetProcAddress("glVertexAttribI3uivEXT"))!=0) nLinked++;
    if ((pglVertexAttribI4uivEXT = (PFNGLVERTEXATTRIBI4UIVEXTPROC) __GLeeGetProcAddress("glVertexAttribI4uivEXT"))!=0) nLinked++;
    if ((pglVertexAttribI4bvEXT = (PFNGLVERTEXATTRIBI4BVEXTPROC) __GLeeGetProcAddress("glVertexAttribI4bvEXT"))!=0) nLinked++;
    if ((pglVertexAttribI4svEXT = (PFNGLVERTEXATTRIBI4SVEXTPROC) __GLeeGetProcAddress("glVertexAttribI4svEXT"))!=0) nLinked++;
    if ((pglVertexAttribI4ubvEXT = (PFNGLVERTEXATTRIBI4UBVEXTPROC) __GLeeGetProcAddress("glVertexAttribI4ubvEXT"))!=0) nLinked++;
    if ((pglVertexAttribI4usvEXT = (PFNGLVERTEXATTRIBI4USVEXTPROC) __GLeeGetProcAddress("glVertexAttribI4usvEXT"))!=0) nLinked++;
    if ((pglVertexAttribIPointerEXT = (PFNGLVERTEXATTRIBIPOINTEREXTPROC) __GLeeGetProcAddress("glVertexAttribIPointerEXT"))!=0) nLinked++;
    if ((pglGetVertexAttribIivEXT = (PFNGLGETVERTEXATTRIBIIVEXTPROC) __GLeeGetProcAddress("glGetVertexAttribIivEXT"))!=0) nLinked++;
    if ((pglGetVertexAttribIuivEXT = (PFNGLGETVERTEXATTRIBIUIVEXTPROC) __GLeeGetProcAddress("glGetVertexAttribIuivEXT"))!=0) nLinked++;
#endif
    if (nLinked==34) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_geometry_shader4(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_geometry_shader4
    if ((pglProgramParameteriEXT = (PFNGLPROGRAMPARAMETERIEXTPROC) __GLeeGetProcAddress("glProgramParameteriEXT"))!=0) nLinked++;
    if ((pglFramebufferTextureEXT = (PFNGLFRAMEBUFFERTEXTUREEXTPROC) __GLeeGetProcAddress("glFramebufferTextureEXT"))!=0) nLinked++;
    if ((pglFramebufferTextureLayerEXT = (PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC) __GLeeGetProcAddress("glFramebufferTextureLayerEXT"))!=0) nLinked++;
    if ((pglFramebufferTextureFaceEXT = (PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC) __GLeeGetProcAddress("glFramebufferTextureFaceEXT"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_bindable_uniform(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_bindable_uniform
    if ((pglUniformBufferEXT = (PFNGLUNIFORMBUFFEREXTPROC) __GLeeGetProcAddress("glUniformBufferEXT"))!=0) nLinked++;
    if ((pglGetUniformBufferSizeEXT = (PFNGLGETUNIFORMBUFFERSIZEEXTPROC) __GLeeGetProcAddress("glGetUniformBufferSizeEXT"))!=0) nLinked++;
    if ((pglGetUniformOffsetEXT = (PFNGLGETUNIFORMOFFSETEXTPROC) __GLeeGetProcAddress("glGetUniformOffsetEXT"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_framebuffer_sRGB(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_shared_exponent(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_packed_float(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_array(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_integer(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_texture_integer
    if ((pglTexParameterIivEXT = (PFNGLTEXPARAMETERIIVEXTPROC) __GLeeGetProcAddress("glTexParameterIivEXT"))!=0) nLinked++;
    if ((pglTexParameterIuivEXT = (PFNGLTEXPARAMETERIUIVEXTPROC) __GLeeGetProcAddress("glTexParameterIuivEXT"))!=0) nLinked++;
    if ((pglGetTexParameterIivEXT = (PFNGLGETTEXPARAMETERIIVEXTPROC) __GLeeGetProcAddress("glGetTexParameterIivEXT"))!=0) nLinked++;
    if ((pglGetTexParameterIuivEXT = (PFNGLGETTEXPARAMETERIUIVEXTPROC) __GLeeGetProcAddress("glGetTexParameterIuivEXT"))!=0) nLinked++;
    if ((pglClearColorIiEXT = (PFNGLCLEARCOLORIIEXTPROC) __GLeeGetProcAddress("glClearColorIiEXT"))!=0) nLinked++;
    if ((pglClearColorIuiEXT = (PFNGLCLEARCOLORIUIEXTPROC) __GLeeGetProcAddress("glClearColorIuiEXT"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_depth_buffer_float(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_depth_buffer_float
    if ((pglDepthRangedNV = (PFNGLDEPTHRANGEDNVPROC) __GLeeGetProcAddress("glDepthRangedNV"))!=0) nLinked++;
    if ((pglClearDepthdNV = (PFNGLCLEARDEPTHDNVPROC) __GLeeGetProcAddress("glClearDepthdNV"))!=0) nLinked++;
    if ((pglDepthBoundsdNV = (PFNGLDEPTHBOUNDSDNVPROC) __GLeeGetProcAddress("glDepthBoundsdNV"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_texture_compression_latc(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_NV_transform_feedback(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_transform_feedback
    if ((pglBeginTransformFeedbackNV = (PFNGLBEGINTRANSFORMFEEDBACKNVPROC) __GLeeGetProcAddress("glBeginTransformFeedbackNV"))!=0) nLinked++;
    if ((pglEndTransformFeedbackNV = (PFNGLENDTRANSFORMFEEDBACKNVPROC) __GLeeGetProcAddress("glEndTransformFeedbackNV"))!=0) nLinked++;
    if ((pglTransformFeedbackAttribsNV = (PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC) __GLeeGetProcAddress("glTransformFeedbackAttribsNV"))!=0) nLinked++;
    if ((pglBindBufferRangeNV = (PFNGLBINDBUFFERRANGENVPROC) __GLeeGetProcAddress("glBindBufferRangeNV"))!=0) nLinked++;
    if ((pglBindBufferOffsetNV = (PFNGLBINDBUFFEROFFSETNVPROC) __GLeeGetProcAddress("glBindBufferOffsetNV"))!=0) nLinked++;
    if ((pglBindBufferBaseNV = (PFNGLBINDBUFFERBASENVPROC) __GLeeGetProcAddress("glBindBufferBaseNV"))!=0) nLinked++;
    if ((pglTransformFeedbackVaryingsNV = (PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC) __GLeeGetProcAddress("glTransformFeedbackVaryingsNV"))!=0) nLinked++;
    if ((pglActiveVaryingNV = (PFNGLACTIVEVARYINGNVPROC) __GLeeGetProcAddress("glActiveVaryingNV"))!=0) nLinked++;
    if ((pglGetVaryingLocationNV = (PFNGLGETVARYINGLOCATIONNVPROC) __GLeeGetProcAddress("glGetVaryingLocationNV"))!=0) nLinked++;
    if ((pglGetActiveVaryingNV = (PFNGLGETACTIVEVARYINGNVPROC) __GLeeGetProcAddress("glGetActiveVaryingNV"))!=0) nLinked++;
    if ((pglGetTransformFeedbackVaryingNV = (PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC) __GLeeGetProcAddress("glGetTransformFeedbackVaryingNV"))!=0) nLinked++;
#endif
    if (nLinked==11) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_geometry_program4(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_geometry_program4
    if ((pglProgramVertexLimitNV = (PFNGLPROGRAMVERTEXLIMITNVPROC) __GLeeGetProcAddress("glProgramVertexLimitNV"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_gpu_program4(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_gpu_program4
    if ((pglProgramLocalParameterI4iNV = (PFNGLPROGRAMLOCALPARAMETERI4INVPROC) __GLeeGetProcAddress("glProgramLocalParameterI4iNV"))!=0) nLinked++;
    if ((pglProgramLocalParameterI4ivNV = (PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC) __GLeeGetProcAddress("glProgramLocalParameterI4ivNV"))!=0) nLinked++;
    if ((pglProgramLocalParametersI4ivNV = (PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC) __GLeeGetProcAddress("glProgramLocalParametersI4ivNV"))!=0) nLinked++;
    if ((pglProgramLocalParameterI4uiNV = (PFNGLPROGRAMLOCALPARAMETERI4UINVPROC) __GLeeGetProcAddress("glProgramLocalParameterI4uiNV"))!=0) nLinked++;
    if ((pglProgramLocalParameterI4uivNV = (PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC) __GLeeGetProcAddress("glProgramLocalParameterI4uivNV"))!=0) nLinked++;
    if ((pglProgramLocalParametersI4uivNV = (PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC) __GLeeGetProcAddress("glProgramLocalParametersI4uivNV"))!=0) nLinked++;
    if ((pglProgramEnvParameterI4iNV = (PFNGLPROGRAMENVPARAMETERI4INVPROC) __GLeeGetProcAddress("glProgramEnvParameterI4iNV"))!=0) nLinked++;
    if ((pglProgramEnvParameterI4ivNV = (PFNGLPROGRAMENVPARAMETERI4IVNVPROC) __GLeeGetProcAddress("glProgramEnvParameterI4ivNV"))!=0) nLinked++;
    if ((pglProgramEnvParametersI4ivNV = (PFNGLPROGRAMENVPARAMETERSI4IVNVPROC) __GLeeGetProcAddress("glProgramEnvParametersI4ivNV"))!=0) nLinked++;
    if ((pglProgramEnvParameterI4uiNV = (PFNGLPROGRAMENVPARAMETERI4UINVPROC) __GLeeGetProcAddress("glProgramEnvParameterI4uiNV"))!=0) nLinked++;
    if ((pglProgramEnvParameterI4uivNV = (PFNGLPROGRAMENVPARAMETERI4UIVNVPROC) __GLeeGetProcAddress("glProgramEnvParameterI4uivNV"))!=0) nLinked++;
    if ((pglProgramEnvParametersI4uivNV = (PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC) __GLeeGetProcAddress("glProgramEnvParametersI4uivNV"))!=0) nLinked++;
    if ((pglGetProgramLocalParameterIivNV = (PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC) __GLeeGetProcAddress("glGetProgramLocalParameterIivNV"))!=0) nLinked++;
    if ((pglGetProgramLocalParameterIuivNV = (PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC) __GLeeGetProcAddress("glGetProgramLocalParameterIuivNV"))!=0) nLinked++;
    if ((pglGetProgramEnvParameterIivNV = (PFNGLGETPROGRAMENVPARAMETERIIVNVPROC) __GLeeGetProcAddress("glGetProgramEnvParameterIivNV"))!=0) nLinked++;
    if ((pglGetProgramEnvParameterIuivNV = (PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC) __GLeeGetProcAddress("glGetProgramEnvParameterIuivNV"))!=0) nLinked++;
#endif
    if (nLinked==16) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_framebuffer_multisample_coverage(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_framebuffer_multisample_coverage
    if ((pglRenderbufferStorageMultisampleCoverageNV = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC) __GLeeGetProcAddress("glRenderbufferStorageMultisampleCoverageNV"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_framebuffer_multisample(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_framebuffer_multisample
    if ((pglRenderbufferStorageMultisampleEXT = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC) __GLeeGetProcAddress("glRenderbufferStorageMultisampleEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_framebuffer_blit(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_framebuffer_blit
    if ((pglBlitFramebufferEXT = (PFNGLBLITFRAMEBUFFEREXTPROC) __GLeeGetProcAddress("glBlitFramebufferEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_texture_compression_rgtc(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_color_matrix(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_texture_select(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_INGR_blend_func_separate(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_INGR_blend_func_separate
    if ((pglBlendFuncSeparateINGR = (PFNGLBLENDFUNCSEPARATEINGRPROC) __GLeeGetProcAddress("glBlendFuncSeparateINGR"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_depth_pass_instrument(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_igloo_interface(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_SGIX_igloo_interface
    if ((pglIglooInterfaceSGIX = (PFNGLIGLOOINTERFACESGIXPROC) __GLeeGetProcAddress("glIglooInterfaceSGIX"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_draw_buffers2(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_draw_buffers2
    if ((pglColorMaskIndexedEXT = (PFNGLCOLORMASKINDEXEDEXTPROC) __GLeeGetProcAddress("glColorMaskIndexedEXT"))!=0) nLinked++;
    if ((pglGetBooleanIndexedvEXT = (PFNGLGETBOOLEANINDEXEDVEXTPROC) __GLeeGetProcAddress("glGetBooleanIndexedvEXT"))!=0) nLinked++;
    if ((pglGetIntegerIndexedvEXT = (PFNGLGETINTEGERINDEXEDVEXTPROC) __GLeeGetProcAddress("glGetIntegerIndexedvEXT"))!=0) nLinked++;
    if ((pglEnableIndexedEXT = (PFNGLENABLEINDEXEDEXTPROC) __GLeeGetProcAddress("glEnableIndexedEXT"))!=0) nLinked++;
    if ((pglDisableIndexedEXT = (PFNGLDISABLEINDEXEDEXTPROC) __GLeeGetProcAddress("glDisableIndexedEXT"))!=0) nLinked++;
    if ((pglIsEnabledIndexedEXT = (PFNGLISENABLEDINDEXEDEXTPROC) __GLeeGetProcAddress("glIsEnabledIndexedEXT"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_NV_parameter_buffer_object(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_NV_parameter_buffer_object
    if ((pglProgramBufferParametersfvNV = (PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC) __GLeeGetProcAddress("glProgramBufferParametersfvNV"))!=0) nLinked++;
    if ((pglProgramBufferParametersIivNV = (PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC) __GLeeGetProcAddress("glProgramBufferParametersIivNV"))!=0) nLinked++;
    if ((pglProgramBufferParametersIuivNV = (PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC) __GLeeGetProcAddress("glProgramBufferParametersIuivNV"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_draw_instanced(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_draw_instanced
    if ((pglDrawArraysInstancedEXT = (PFNGLDRAWARRAYSINSTANCEDEXTPROC) __GLeeGetProcAddress("glDrawArraysInstancedEXT"))!=0) nLinked++;
    if ((pglDrawElementsInstancedEXT = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC) __GLeeGetProcAddress("glDrawElementsInstancedEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_fragment_lighting(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_fragment_lighting
    if ((pglFragmentLightModeliEXT = (PFNGLFRAGMENTLIGHTMODELIEXTPROC) __GLeeGetProcAddress("glFragmentLightModeliEXT"))!=0) nLinked++;
    if ((pglFragmentLightModelfEXT = (PFNGLFRAGMENTLIGHTMODELFEXTPROC) __GLeeGetProcAddress("glFragmentLightModelfEXT"))!=0) nLinked++;
    if ((pglFragmentLightModelivEXT = (PFNGLFRAGMENTLIGHTMODELIVEXTPROC) __GLeeGetProcAddress("glFragmentLightModelivEXT"))!=0) nLinked++;
    if ((pglFragmentLightModelfvEXT = (PFNGLFRAGMENTLIGHTMODELFVEXTPROC) __GLeeGetProcAddress("glFragmentLightModelfvEXT"))!=0) nLinked++;
    if ((pglFragmentLightiEXT = (PFNGLFRAGMENTLIGHTIEXTPROC) __GLeeGetProcAddress("glFragmentLightiEXT"))!=0) nLinked++;
    if ((pglFragmentLightfEXT = (PFNGLFRAGMENTLIGHTFEXTPROC) __GLeeGetProcAddress("glFragmentLightfEXT"))!=0) nLinked++;
    if ((pglFragmentLightivEXT = (PFNGLFRAGMENTLIGHTIVEXTPROC) __GLeeGetProcAddress("glFragmentLightivEXT"))!=0) nLinked++;
    if ((pglFragmentLightfvEXT = (PFNGLFRAGMENTLIGHTFVEXTPROC) __GLeeGetProcAddress("glFragmentLightfvEXT"))!=0) nLinked++;
    if ((pglGetFragmentLightivEXT = (PFNGLGETFRAGMENTLIGHTIVEXTPROC) __GLeeGetProcAddress("glGetFragmentLightivEXT"))!=0) nLinked++;
    if ((pglGetFragmentLightfvEXT = (PFNGLGETFRAGMENTLIGHTFVEXTPROC) __GLeeGetProcAddress("glGetFragmentLightfvEXT"))!=0) nLinked++;
    if ((pglFragmentMaterialfEXT = (PFNGLFRAGMENTMATERIALFEXTPROC) __GLeeGetProcAddress("glFragmentMaterialfEXT"))!=0) nLinked++;
    if ((pglFragmentMaterialiEXT = (PFNGLFRAGMENTMATERIALIEXTPROC) __GLeeGetProcAddress("glFragmentMaterialiEXT"))!=0) nLinked++;
    if ((pglFragmentMaterialfvEXT = (PFNGLFRAGMENTMATERIALFVEXTPROC) __GLeeGetProcAddress("glFragmentMaterialfvEXT"))!=0) nLinked++;
    if ((pglFragmentMaterialivEXT = (PFNGLFRAGMENTMATERIALIVEXTPROC) __GLeeGetProcAddress("glFragmentMaterialivEXT"))!=0) nLinked++;
    if ((pglFragmentColorMaterialEXT = (PFNGLFRAGMENTCOLORMATERIALEXTPROC) __GLeeGetProcAddress("glFragmentColorMaterialEXT"))!=0) nLinked++;
    if ((pglGetFragmentMaterialfvEXT = (PFNGLGETFRAGMENTMATERIALFVEXTPROC) __GLeeGetProcAddress("glGetFragmentMaterialfvEXT"))!=0) nLinked++;
    if ((pglGetFragmentMaterialivEXT = (PFNGLGETFRAGMENTMATERIALIVEXTPROC) __GLeeGetProcAddress("glGetFragmentMaterialivEXT"))!=0) nLinked++;
    if ((pglLightEnviEXT = (PFNGLLIGHTENVIEXTPROC) __GLeeGetProcAddress("glLightEnviEXT"))!=0) nLinked++;
#endif
    if (nLinked==18) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_packed_depth_stencil(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_scene_marker(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_EXT_scene_marker
    if ((pglBeginSceneEXT = (PFNGLBEGINSCENEEXTPROC) __GLeeGetProcAddress("glBeginSceneEXT"))!=0) nLinked++;
    if ((pglEndSceneEXT = (PFNGLENDSCENEEXTPROC) __GLeeGetProcAddress("glEndSceneEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_EXT_stencil_clear_tag(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_compression_dxt1(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_env(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_EXT_texture_sRGB(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_IBM_static_data(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_MESAX_texture_stack(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_OES_byte_coordinates(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_OES_compressed_paletted_texture(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_OES_single_precision(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GL_OES_single_precision
    if ((pglDepthRangefOES = (PFNGLDEPTHRANGEFOESPROC) __GLeeGetProcAddress("glDepthRangefOES"))!=0) nLinked++;
    if ((pglFrustumfOES = (PFNGLFRUSTUMFOESPROC) __GLeeGetProcAddress("glFrustumfOES"))!=0) nLinked++;
    if ((pglOrthofOES = (PFNGLORTHOFOESPROC) __GLeeGetProcAddress("glOrthofOES"))!=0) nLinked++;
    if ((pglClipPlanefOES = (PFNGLCLIPPLANEFOESPROC) __GLeeGetProcAddress("glClipPlanefOES"))!=0) nLinked++;
    if ((pglGetClipPlanefOES = (PFNGLGETCLIPPLANEFOESPROC) __GLeeGetProcAddress("glGetClipPlanefOES"))!=0) nLinked++;
    if ((pglClearDepthfOES = (PFNGLCLEARDEPTHFOESPROC) __GLeeGetProcAddress("glClearDepthfOES"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GL_SGIX_pixel_texture_bits(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GL_SGIX_texture_range(void) {return GLEE_LINK_COMPLETE;}

GLEE_LINK_FUNCTION __GLeeGLLoadFunction[300];

void initGLLoadFunctions(void)
{
    __GLeeGLLoadFunction[0]=__GLeeLink_GL_VERSION_1_2;
    __GLeeGLLoadFunction[1]=__GLeeLink_GL_ARB_imaging;
    __GLeeGLLoadFunction[2]=__GLeeLink_GL_VERSION_1_3;
    __GLeeGLLoadFunction[3]=__GLeeLink_GL_VERSION_1_4;
    __GLeeGLLoadFunction[4]=__GLeeLink_GL_VERSION_1_5;
    __GLeeGLLoadFunction[5]=__GLeeLink_GL_VERSION_2_0;
    __GLeeGLLoadFunction[6]=__GLeeLink_GL_VERSION_2_1;
    __GLeeGLLoadFunction[7]=__GLeeLink_GL_ARB_multitexture;
    __GLeeGLLoadFunction[8]=__GLeeLink_GL_ARB_transpose_matrix;
    __GLeeGLLoadFunction[9]=__GLeeLink_GL_ARB_multisample;
    __GLeeGLLoadFunction[10]=__GLeeLink_GL_ARB_texture_env_add;
    __GLeeGLLoadFunction[11]=__GLeeLink_GL_ARB_texture_cube_map;
    __GLeeGLLoadFunction[12]=__GLeeLink_GL_ARB_texture_compression;
    __GLeeGLLoadFunction[13]=__GLeeLink_GL_ARB_texture_border_clamp;
    __GLeeGLLoadFunction[14]=__GLeeLink_GL_ARB_point_parameters;
    __GLeeGLLoadFunction[15]=__GLeeLink_GL_ARB_vertex_blend;
    __GLeeGLLoadFunction[16]=__GLeeLink_GL_ARB_matrix_palette;
    __GLeeGLLoadFunction[17]=__GLeeLink_GL_ARB_texture_env_combine;
    __GLeeGLLoadFunction[18]=__GLeeLink_GL_ARB_texture_env_crossbar;
    __GLeeGLLoadFunction[19]=__GLeeLink_GL_ARB_texture_env_dot3;
    __GLeeGLLoadFunction[20]=__GLeeLink_GL_ARB_texture_mirrored_repeat;
    __GLeeGLLoadFunction[21]=__GLeeLink_GL_ARB_depth_texture;
    __GLeeGLLoadFunction[22]=__GLeeLink_GL_ARB_shadow;
    __GLeeGLLoadFunction[23]=__GLeeLink_GL_ARB_shadow_ambient;
    __GLeeGLLoadFunction[24]=__GLeeLink_GL_ARB_window_pos;
    __GLeeGLLoadFunction[25]=__GLeeLink_GL_ARB_vertex_program;
    __GLeeGLLoadFunction[26]=__GLeeLink_GL_ARB_fragment_program;
    __GLeeGLLoadFunction[27]=__GLeeLink_GL_ARB_vertex_buffer_object;
    __GLeeGLLoadFunction[28]=__GLeeLink_GL_ARB_occlusion_query;
    __GLeeGLLoadFunction[29]=__GLeeLink_GL_ARB_shader_objects;
    __GLeeGLLoadFunction[30]=__GLeeLink_GL_ARB_vertex_shader;
    __GLeeGLLoadFunction[31]=__GLeeLink_GL_ARB_fragment_shader;
    __GLeeGLLoadFunction[32]=__GLeeLink_GL_ARB_shading_language_100;
    __GLeeGLLoadFunction[33]=__GLeeLink_GL_ARB_texture_non_power_of_two;
    __GLeeGLLoadFunction[34]=__GLeeLink_GL_ARB_point_sprite;
    __GLeeGLLoadFunction[35]=__GLeeLink_GL_ARB_fragment_program_shadow;
    __GLeeGLLoadFunction[36]=__GLeeLink_GL_ARB_draw_buffers;
    __GLeeGLLoadFunction[37]=__GLeeLink_GL_ARB_texture_rectangle;
    __GLeeGLLoadFunction[38]=__GLeeLink_GL_ARB_color_buffer_float;
    __GLeeGLLoadFunction[39]=__GLeeLink_GL_ARB_half_float_pixel;
    __GLeeGLLoadFunction[40]=__GLeeLink_GL_ARB_texture_float;
    __GLeeGLLoadFunction[41]=__GLeeLink_GL_ARB_pixel_buffer_object;
    __GLeeGLLoadFunction[42]=__GLeeLink_GL_EXT_abgr;
    __GLeeGLLoadFunction[43]=__GLeeLink_GL_EXT_blend_color;
    __GLeeGLLoadFunction[44]=__GLeeLink_GL_EXT_polygon_offset;
    __GLeeGLLoadFunction[45]=__GLeeLink_GL_EXT_texture;
    __GLeeGLLoadFunction[46]=__GLeeLink_GL_EXT_texture3D;
    __GLeeGLLoadFunction[47]=__GLeeLink_GL_SGIS_texture_filter4;
    __GLeeGLLoadFunction[48]=__GLeeLink_GL_EXT_subtexture;
    __GLeeGLLoadFunction[49]=__GLeeLink_GL_EXT_copy_texture;
    __GLeeGLLoadFunction[50]=__GLeeLink_GL_EXT_histogram;
    __GLeeGLLoadFunction[51]=__GLeeLink_GL_EXT_convolution;
    __GLeeGLLoadFunction[52]=__GLeeLink_GL_SGI_color_matrix;
    __GLeeGLLoadFunction[53]=__GLeeLink_GL_SGI_color_table;
    __GLeeGLLoadFunction[54]=__GLeeLink_GL_SGIS_pixel_texture;
    __GLeeGLLoadFunction[55]=__GLeeLink_GL_SGIX_pixel_texture;
    __GLeeGLLoadFunction[56]=__GLeeLink_GL_SGIS_texture4D;
    __GLeeGLLoadFunction[57]=__GLeeLink_GL_SGI_texture_color_table;
    __GLeeGLLoadFunction[58]=__GLeeLink_GL_EXT_cmyka;
    __GLeeGLLoadFunction[59]=__GLeeLink_GL_EXT_texture_object;
    __GLeeGLLoadFunction[60]=__GLeeLink_GL_SGIS_detail_texture;
    __GLeeGLLoadFunction[61]=__GLeeLink_GL_SGIS_sharpen_texture;
    __GLeeGLLoadFunction[62]=__GLeeLink_GL_EXT_packed_pixels;
    __GLeeGLLoadFunction[63]=__GLeeLink_GL_SGIS_texture_lod;
    __GLeeGLLoadFunction[64]=__GLeeLink_GL_SGIS_multisample;
    __GLeeGLLoadFunction[65]=__GLeeLink_GL_EXT_rescale_normal;
    __GLeeGLLoadFunction[66]=__GLeeLink_GL_EXT_vertex_array;
    __GLeeGLLoadFunction[67]=__GLeeLink_GL_EXT_misc_attribute;
    __GLeeGLLoadFunction[68]=__GLeeLink_GL_SGIS_generate_mipmap;
    __GLeeGLLoadFunction[69]=__GLeeLink_GL_SGIX_clipmap;
    __GLeeGLLoadFunction[70]=__GLeeLink_GL_SGIX_shadow;
    __GLeeGLLoadFunction[71]=__GLeeLink_GL_SGIS_texture_edge_clamp;
    __GLeeGLLoadFunction[72]=__GLeeLink_GL_SGIS_texture_border_clamp;
    __GLeeGLLoadFunction[73]=__GLeeLink_GL_EXT_blend_minmax;
    __GLeeGLLoadFunction[74]=__GLeeLink_GL_EXT_blend_subtract;
    __GLeeGLLoadFunction[75]=__GLeeLink_GL_EXT_blend_logic_op;
    __GLeeGLLoadFunction[76]=__GLeeLink_GL_SGIX_interlace;
    __GLeeGLLoadFunction[77]=__GLeeLink_GL_SGIX_pixel_tiles;
    __GLeeGLLoadFunction[78]=__GLeeLink_GL_SGIS_texture_select;
    __GLeeGLLoadFunction[79]=__GLeeLink_GL_SGIX_sprite;
    __GLeeGLLoadFunction[80]=__GLeeLink_GL_SGIX_texture_multi_buffer;
    __GLeeGLLoadFunction[81]=__GLeeLink_GL_EXT_point_parameters;
    __GLeeGLLoadFunction[82]=__GLeeLink_GL_SGIS_point_parameters;
    __GLeeGLLoadFunction[83]=__GLeeLink_GL_SGIX_instruments;
    __GLeeGLLoadFunction[84]=__GLeeLink_GL_SGIX_texture_scale_bias;
    __GLeeGLLoadFunction[85]=__GLeeLink_GL_SGIX_framezoom;
    __GLeeGLLoadFunction[86]=__GLeeLink_GL_SGIX_tag_sample_buffer;
    __GLeeGLLoadFunction[87]=__GLeeLink_GL_FfdMaskSGIX;
    __GLeeGLLoadFunction[88]=__GLeeLink_GL_SGIX_polynomial_ffd;
    __GLeeGLLoadFunction[89]=__GLeeLink_GL_SGIX_reference_plane;
    __GLeeGLLoadFunction[90]=__GLeeLink_GL_SGIX_flush_raster;
    __GLeeGLLoadFunction[91]=__GLeeLink_GL_SGIX_depth_texture;
    __GLeeGLLoadFunction[92]=__GLeeLink_GL_SGIS_fog_function;
    __GLeeGLLoadFunction[93]=__GLeeLink_GL_SGIX_fog_offset;
    __GLeeGLLoadFunction[94]=__GLeeLink_GL_HP_image_transform;
    __GLeeGLLoadFunction[95]=__GLeeLink_GL_HP_convolution_border_modes;
    __GLeeGLLoadFunction[96]=__GLeeLink_GL_INGR_palette_buffer;
    __GLeeGLLoadFunction[97]=__GLeeLink_GL_SGIX_texture_add_env;
    __GLeeGLLoadFunction[98]=__GLeeLink_GL_EXT_color_subtable;
    __GLeeGLLoadFunction[99]=__GLeeLink_GL_PGI_vertex_hints;
    __GLeeGLLoadFunction[100]=__GLeeLink_GL_PGI_misc_hints;
    __GLeeGLLoadFunction[101]=__GLeeLink_GL_EXT_paletted_texture;
    __GLeeGLLoadFunction[102]=__GLeeLink_GL_EXT_clip_volume_hint;
    __GLeeGLLoadFunction[103]=__GLeeLink_GL_SGIX_list_priority;
    __GLeeGLLoadFunction[104]=__GLeeLink_GL_SGIX_ir_instrument1;
    __GLeeGLLoadFunction[105]=__GLeeLink_GL_SGIX_calligraphic_fragment;
    __GLeeGLLoadFunction[106]=__GLeeLink_GL_SGIX_texture_lod_bias;
    __GLeeGLLoadFunction[107]=__GLeeLink_GL_SGIX_shadow_ambient;
    __GLeeGLLoadFunction[108]=__GLeeLink_GL_EXT_index_texture;
    __GLeeGLLoadFunction[109]=__GLeeLink_GL_EXT_index_material;
    __GLeeGLLoadFunction[110]=__GLeeLink_GL_EXT_index_func;
    __GLeeGLLoadFunction[111]=__GLeeLink_GL_EXT_index_array_formats;
    __GLeeGLLoadFunction[112]=__GLeeLink_GL_EXT_compiled_vertex_array;
    __GLeeGLLoadFunction[113]=__GLeeLink_GL_EXT_cull_vertex;
    __GLeeGLLoadFunction[114]=__GLeeLink_GL_SGIX_ycrcb;
    __GLeeGLLoadFunction[115]=__GLeeLink_GL_SGIX_fragment_lighting;
    __GLeeGLLoadFunction[116]=__GLeeLink_GL_IBM_rasterpos_clip;
    __GLeeGLLoadFunction[117]=__GLeeLink_GL_HP_texture_lighting;
    __GLeeGLLoadFunction[118]=__GLeeLink_GL_EXT_draw_range_elements;
    __GLeeGLLoadFunction[119]=__GLeeLink_GL_WIN_phong_shading;
    __GLeeGLLoadFunction[120]=__GLeeLink_GL_WIN_specular_fog;
    __GLeeGLLoadFunction[121]=__GLeeLink_GL_EXT_light_texture;
    __GLeeGLLoadFunction[122]=__GLeeLink_GL_SGIX_blend_alpha_minmax;
    __GLeeGLLoadFunction[123]=__GLeeLink_GL_SGIX_impact_pixel_texture;
    __GLeeGLLoadFunction[124]=__GLeeLink_GL_EXT_bgra;
    __GLeeGLLoadFunction[125]=__GLeeLink_GL_SGIX_async;
    __GLeeGLLoadFunction[126]=__GLeeLink_GL_SGIX_async_pixel;
    __GLeeGLLoadFunction[127]=__GLeeLink_GL_SGIX_async_histogram;
    __GLeeGLLoadFunction[128]=__GLeeLink_GL_INTEL_texture_scissor;
    __GLeeGLLoadFunction[129]=__GLeeLink_GL_INTEL_parallel_arrays;
    __GLeeGLLoadFunction[130]=__GLeeLink_GL_HP_occlusion_test;
    __GLeeGLLoadFunction[131]=__GLeeLink_GL_EXT_pixel_transform;
    __GLeeGLLoadFunction[132]=__GLeeLink_GL_EXT_pixel_transform_color_table;
    __GLeeGLLoadFunction[133]=__GLeeLink_GL_EXT_shared_texture_palette;
    __GLeeGLLoadFunction[134]=__GLeeLink_GL_EXT_separate_specular_color;
    __GLeeGLLoadFunction[135]=__GLeeLink_GL_EXT_secondary_color;
    __GLeeGLLoadFunction[136]=__GLeeLink_GL_EXT_texture_perturb_normal;
    __GLeeGLLoadFunction[137]=__GLeeLink_GL_EXT_multi_draw_arrays;
    __GLeeGLLoadFunction[138]=__GLeeLink_GL_EXT_fog_coord;
    __GLeeGLLoadFunction[139]=__GLeeLink_GL_REND_screen_coordinates;
    __GLeeGLLoadFunction[140]=__GLeeLink_GL_EXT_coordinate_frame;
    __GLeeGLLoadFunction[141]=__GLeeLink_GL_EXT_texture_env_combine;
    __GLeeGLLoadFunction[142]=__GLeeLink_GL_APPLE_specular_vector;
    __GLeeGLLoadFunction[143]=__GLeeLink_GL_APPLE_transform_hint;
    __GLeeGLLoadFunction[144]=__GLeeLink_GL_SGIX_fog_scale;
    __GLeeGLLoadFunction[145]=__GLeeLink_GL_SUNX_constant_data;
    __GLeeGLLoadFunction[146]=__GLeeLink_GL_SUN_global_alpha;
    __GLeeGLLoadFunction[147]=__GLeeLink_GL_SUN_triangle_list;
    __GLeeGLLoadFunction[148]=__GLeeLink_GL_SUN_vertex;
    __GLeeGLLoadFunction[149]=__GLeeLink_GL_EXT_blend_func_separate;
    __GLeeGLLoadFunction[150]=__GLeeLink_GL_INGR_color_clamp;
    __GLeeGLLoadFunction[151]=__GLeeLink_GL_INGR_interlace_read;
    __GLeeGLLoadFunction[152]=__GLeeLink_GL_EXT_stencil_wrap;
    __GLeeGLLoadFunction[153]=__GLeeLink_GL_EXT_422_pixels;
    __GLeeGLLoadFunction[154]=__GLeeLink_GL_NV_texgen_reflection;
    __GLeeGLLoadFunction[155]=__GLeeLink_GL_EXT_texture_cube_map;
    __GLeeGLLoadFunction[156]=__GLeeLink_GL_SUN_convolution_border_modes;
    __GLeeGLLoadFunction[157]=__GLeeLink_GL_EXT_texture_env_add;
    __GLeeGLLoadFunction[158]=__GLeeLink_GL_EXT_texture_lod_bias;
    __GLeeGLLoadFunction[159]=__GLeeLink_GL_EXT_texture_filter_anisotropic;
    __GLeeGLLoadFunction[160]=__GLeeLink_GL_EXT_vertex_weighting;
    __GLeeGLLoadFunction[161]=__GLeeLink_GL_NV_light_max_exponent;
    __GLeeGLLoadFunction[162]=__GLeeLink_GL_NV_vertex_array_range;
    __GLeeGLLoadFunction[163]=__GLeeLink_GL_NV_register_combiners;
    __GLeeGLLoadFunction[164]=__GLeeLink_GL_NV_fog_distance;
    __GLeeGLLoadFunction[165]=__GLeeLink_GL_NV_texgen_emboss;
    __GLeeGLLoadFunction[166]=__GLeeLink_GL_NV_blend_square;
    __GLeeGLLoadFunction[167]=__GLeeLink_GL_NV_texture_env_combine4;
    __GLeeGLLoadFunction[168]=__GLeeLink_GL_MESA_resize_buffers;
    __GLeeGLLoadFunction[169]=__GLeeLink_GL_MESA_window_pos;
    __GLeeGLLoadFunction[170]=__GLeeLink_GL_EXT_texture_compression_s3tc;
    __GLeeGLLoadFunction[171]=__GLeeLink_GL_IBM_cull_vertex;
    __GLeeGLLoadFunction[172]=__GLeeLink_GL_IBM_multimode_draw_arrays;
    __GLeeGLLoadFunction[173]=__GLeeLink_GL_IBM_vertex_array_lists;
    __GLeeGLLoadFunction[174]=__GLeeLink_GL_SGIX_subsample;
    __GLeeGLLoadFunction[175]=__GLeeLink_GL_SGIX_ycrcb_subsample;
    __GLeeGLLoadFunction[176]=__GLeeLink_GL_SGIX_ycrcba;
    __GLeeGLLoadFunction[177]=__GLeeLink_GL_SGI_depth_pass_instrument;
    __GLeeGLLoadFunction[178]=__GLeeLink_GL_3DFX_texture_compression_FXT1;
    __GLeeGLLoadFunction[179]=__GLeeLink_GL_3DFX_multisample;
    __GLeeGLLoadFunction[180]=__GLeeLink_GL_3DFX_tbuffer;
    __GLeeGLLoadFunction[181]=__GLeeLink_GL_EXT_multisample;
    __GLeeGLLoadFunction[182]=__GLeeLink_GL_SGIX_vertex_preclip;
    __GLeeGLLoadFunction[183]=__GLeeLink_GL_SGIX_convolution_accuracy;
    __GLeeGLLoadFunction[184]=__GLeeLink_GL_SGIX_resample;
    __GLeeGLLoadFunction[185]=__GLeeLink_GL_SGIS_point_line_texgen;
    __GLeeGLLoadFunction[186]=__GLeeLink_GL_SGIS_texture_color_mask;
    __GLeeGLLoadFunction[187]=__GLeeLink_GL_EXT_texture_env_dot3;
    __GLeeGLLoadFunction[188]=__GLeeLink_GL_ATI_texture_mirror_once;
    __GLeeGLLoadFunction[189]=__GLeeLink_GL_NV_fence;
    __GLeeGLLoadFunction[190]=__GLeeLink_GL_IBM_texture_mirrored_repeat;
    __GLeeGLLoadFunction[191]=__GLeeLink_GL_NV_evaluators;
    __GLeeGLLoadFunction[192]=__GLeeLink_GL_NV_packed_depth_stencil;
    __GLeeGLLoadFunction[193]=__GLeeLink_GL_NV_register_combiners2;
    __GLeeGLLoadFunction[194]=__GLeeLink_GL_NV_texture_compression_vtc;
    __GLeeGLLoadFunction[195]=__GLeeLink_GL_NV_texture_rectangle;
    __GLeeGLLoadFunction[196]=__GLeeLink_GL_NV_texture_shader;
    __GLeeGLLoadFunction[197]=__GLeeLink_GL_NV_texture_shader2;
    __GLeeGLLoadFunction[198]=__GLeeLink_GL_NV_vertex_array_range2;
    __GLeeGLLoadFunction[199]=__GLeeLink_GL_NV_vertex_program;
    __GLeeGLLoadFunction[200]=__GLeeLink_GL_SGIX_texture_coordinate_clamp;
    __GLeeGLLoadFunction[201]=__GLeeLink_GL_SGIX_scalebias_hint;
    __GLeeGLLoadFunction[202]=__GLeeLink_GL_OML_interlace;
    __GLeeGLLoadFunction[203]=__GLeeLink_GL_OML_subsample;
    __GLeeGLLoadFunction[204]=__GLeeLink_GL_OML_resample;
    __GLeeGLLoadFunction[205]=__GLeeLink_GL_NV_copy_depth_to_color;
    __GLeeGLLoadFunction[206]=__GLeeLink_GL_ATI_envmap_bumpmap;
    __GLeeGLLoadFunction[207]=__GLeeLink_GL_ATI_fragment_shader;
    __GLeeGLLoadFunction[208]=__GLeeLink_GL_ATI_pn_triangles;
    __GLeeGLLoadFunction[209]=__GLeeLink_GL_ATI_vertex_array_object;
    __GLeeGLLoadFunction[210]=__GLeeLink_GL_EXT_vertex_shader;
    __GLeeGLLoadFunction[211]=__GLeeLink_GL_ATI_vertex_streams;
    __GLeeGLLoadFunction[212]=__GLeeLink_GL_ATI_element_array;
    __GLeeGLLoadFunction[213]=__GLeeLink_GL_SUN_mesh_array;
    __GLeeGLLoadFunction[214]=__GLeeLink_GL_SUN_slice_accum;
    __GLeeGLLoadFunction[215]=__GLeeLink_GL_NV_multisample_filter_hint;
    __GLeeGLLoadFunction[216]=__GLeeLink_GL_NV_depth_clamp;
    __GLeeGLLoadFunction[217]=__GLeeLink_GL_NV_occlusion_query;
    __GLeeGLLoadFunction[218]=__GLeeLink_GL_NV_point_sprite;
    __GLeeGLLoadFunction[219]=__GLeeLink_GL_NV_texture_shader3;
    __GLeeGLLoadFunction[220]=__GLeeLink_GL_NV_vertex_program1_1;
    __GLeeGLLoadFunction[221]=__GLeeLink_GL_EXT_shadow_funcs;
    __GLeeGLLoadFunction[222]=__GLeeLink_GL_EXT_stencil_two_side;
    __GLeeGLLoadFunction[223]=__GLeeLink_GL_ATI_text_fragment_shader;
    __GLeeGLLoadFunction[224]=__GLeeLink_GL_APPLE_client_storage;
    __GLeeGLLoadFunction[225]=__GLeeLink_GL_APPLE_element_array;
    __GLeeGLLoadFunction[226]=__GLeeLink_GL_APPLE_fence;
    __GLeeGLLoadFunction[227]=__GLeeLink_GL_APPLE_vertex_array_object;
    __GLeeGLLoadFunction[228]=__GLeeLink_GL_APPLE_vertex_array_range;
    __GLeeGLLoadFunction[229]=__GLeeLink_GL_APPLE_ycbcr_422;
    __GLeeGLLoadFunction[230]=__GLeeLink_GL_S3_s3tc;
    __GLeeGLLoadFunction[231]=__GLeeLink_GL_ATI_draw_buffers;
    __GLeeGLLoadFunction[232]=__GLeeLink_GL_ATI_pixel_format_float;
    __GLeeGLLoadFunction[233]=__GLeeLink_GL_ATI_texture_env_combine3;
    __GLeeGLLoadFunction[234]=__GLeeLink_GL_ATI_texture_float;
    __GLeeGLLoadFunction[235]=__GLeeLink_GL_NV_float_buffer;
    __GLeeGLLoadFunction[236]=__GLeeLink_GL_NV_fragment_program;
    __GLeeGLLoadFunction[237]=__GLeeLink_GL_NV_half_float;
    __GLeeGLLoadFunction[238]=__GLeeLink_GL_NV_pixel_data_range;
    __GLeeGLLoadFunction[239]=__GLeeLink_GL_NV_primitive_restart;
    __GLeeGLLoadFunction[240]=__GLeeLink_GL_NV_texture_expand_normal;
    __GLeeGLLoadFunction[241]=__GLeeLink_GL_NV_vertex_program2;
    __GLeeGLLoadFunction[242]=__GLeeLink_GL_ATI_map_object_buffer;
    __GLeeGLLoadFunction[243]=__GLeeLink_GL_ATI_separate_stencil;
    __GLeeGLLoadFunction[244]=__GLeeLink_GL_ATI_vertex_attrib_array_object;
    __GLeeGLLoadFunction[245]=__GLeeLink_GL_OES_read_format;
    __GLeeGLLoadFunction[246]=__GLeeLink_GL_EXT_depth_bounds_test;
    __GLeeGLLoadFunction[247]=__GLeeLink_GL_EXT_texture_mirror_clamp;
    __GLeeGLLoadFunction[248]=__GLeeLink_GL_EXT_blend_equation_separate;
    __GLeeGLLoadFunction[249]=__GLeeLink_GL_MESA_pack_invert;
    __GLeeGLLoadFunction[250]=__GLeeLink_GL_MESA_ycbcr_texture;
    __GLeeGLLoadFunction[251]=__GLeeLink_GL_EXT_pixel_buffer_object;
    __GLeeGLLoadFunction[252]=__GLeeLink_GL_NV_fragment_program_option;
    __GLeeGLLoadFunction[253]=__GLeeLink_GL_NV_fragment_program2;
    __GLeeGLLoadFunction[254]=__GLeeLink_GL_NV_vertex_program2_option;
    __GLeeGLLoadFunction[255]=__GLeeLink_GL_NV_vertex_program3;
    __GLeeGLLoadFunction[256]=__GLeeLink_GL_EXT_framebuffer_object;
    __GLeeGLLoadFunction[257]=__GLeeLink_GL_GREMEDY_string_marker;
    __GLeeGLLoadFunction[258]=__GLeeLink_GL_EXT_Cg_shader;
    __GLeeGLLoadFunction[259]=__GLeeLink_GL_EXT_timer_query;
    __GLeeGLLoadFunction[260]=__GLeeLink_GL_EXT_texture_buffer_object;
    __GLeeGLLoadFunction[261]=__GLeeLink_GL_EXT_gpu_shader4;
    __GLeeGLLoadFunction[262]=__GLeeLink_GL_EXT_geometry_shader4;
    __GLeeGLLoadFunction[263]=__GLeeLink_GL_EXT_bindable_uniform;
    __GLeeGLLoadFunction[264]=__GLeeLink_GL_EXT_framebuffer_sRGB;
    __GLeeGLLoadFunction[265]=__GLeeLink_GL_EXT_texture_shared_exponent;
    __GLeeGLLoadFunction[266]=__GLeeLink_GL_EXT_packed_float;
    __GLeeGLLoadFunction[267]=__GLeeLink_GL_EXT_texture_array;
    __GLeeGLLoadFunction[268]=__GLeeLink_GL_EXT_texture_integer;
    __GLeeGLLoadFunction[269]=__GLeeLink_GL_NV_depth_buffer_float;
    __GLeeGLLoadFunction[270]=__GLeeLink_GL_EXT_texture_compression_latc;
    __GLeeGLLoadFunction[271]=__GLeeLink_GL_NV_transform_feedback;
    __GLeeGLLoadFunction[272]=__GLeeLink_GL_NV_geometry_program4;
    __GLeeGLLoadFunction[273]=__GLeeLink_GL_NV_gpu_program4;
    __GLeeGLLoadFunction[274]=__GLeeLink_GL_NV_framebuffer_multisample_coverage;
    __GLeeGLLoadFunction[275]=__GLeeLink_GL_EXT_framebuffer_multisample;
    __GLeeGLLoadFunction[276]=__GLeeLink_GL_EXT_framebuffer_blit;
    __GLeeGLLoadFunction[277]=__GLeeLink_GL_EXT_texture_compression_rgtc;
    __GLeeGLLoadFunction[278]=__GLeeLink_GL_EXT_color_matrix;
    __GLeeGLLoadFunction[279]=__GLeeLink_GL_SGIX_texture_select;
    __GLeeGLLoadFunction[280]=__GLeeLink_GL_INGR_blend_func_separate;
    __GLeeGLLoadFunction[281]=__GLeeLink_GL_SGIX_depth_pass_instrument;
    __GLeeGLLoadFunction[282]=__GLeeLink_GL_SGIX_igloo_interface;
    __GLeeGLLoadFunction[283]=__GLeeLink_GL_EXT_draw_buffers2;
    __GLeeGLLoadFunction[284]=__GLeeLink_GL_NV_parameter_buffer_object;
    __GLeeGLLoadFunction[285]=__GLeeLink_GL_EXT_draw_instanced;
    __GLeeGLLoadFunction[286]=__GLeeLink_GL_EXT_fragment_lighting;
    __GLeeGLLoadFunction[287]=__GLeeLink_GL_EXT_packed_depth_stencil;
    __GLeeGLLoadFunction[288]=__GLeeLink_GL_EXT_scene_marker;
    __GLeeGLLoadFunction[289]=__GLeeLink_GL_EXT_stencil_clear_tag;
    __GLeeGLLoadFunction[290]=__GLeeLink_GL_EXT_texture_compression_dxt1;
    __GLeeGLLoadFunction[291]=__GLeeLink_GL_EXT_texture_env;
    __GLeeGLLoadFunction[292]=__GLeeLink_GL_EXT_texture_sRGB;
    __GLeeGLLoadFunction[293]=__GLeeLink_GL_IBM_static_data;
    __GLeeGLLoadFunction[294]=__GLeeLink_GL_MESAX_texture_stack;
    __GLeeGLLoadFunction[295]=__GLeeLink_GL_OES_byte_coordinates;
    __GLeeGLLoadFunction[296]=__GLeeLink_GL_OES_compressed_paletted_texture;
    __GLeeGLLoadFunction[297]=__GLeeLink_GL_OES_single_precision;
    __GLeeGLLoadFunction[298]=__GLeeLink_GL_SGIX_pixel_texture_bits;
    __GLeeGLLoadFunction[299]=__GLeeLink_GL_SGIX_texture_range;
}

#ifdef WIN32
GLuint __GLeeLink_WGL_ARB_buffer_region(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_ARB_buffer_region
    if ((pwglCreateBufferRegionARB = (PFNWGLCREATEBUFFERREGIONARBPROC) __GLeeGetProcAddress("wglCreateBufferRegionARB"))!=0) nLinked++;
    if ((pwglDeleteBufferRegionARB = (PFNWGLDELETEBUFFERREGIONARBPROC) __GLeeGetProcAddress("wglDeleteBufferRegionARB"))!=0) nLinked++;
    if ((pwglSaveBufferRegionARB = (PFNWGLSAVEBUFFERREGIONARBPROC) __GLeeGetProcAddress("wglSaveBufferRegionARB"))!=0) nLinked++;
    if ((pwglRestoreBufferRegionARB = (PFNWGLRESTOREBUFFERREGIONARBPROC) __GLeeGetProcAddress("wglRestoreBufferRegionARB"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_ARB_multisample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_WGL_ARB_extensions_string(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_ARB_extensions_string
    if ((pwglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) __GLeeGetProcAddress("wglGetExtensionsStringARB"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_ARB_pixel_format(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_ARB_pixel_format
    if ((pwglGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC) __GLeeGetProcAddress("wglGetPixelFormatAttribivARB"))!=0) nLinked++;
    if ((pwglGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC) __GLeeGetProcAddress("wglGetPixelFormatAttribfvARB"))!=0) nLinked++;
    if ((pwglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC) __GLeeGetProcAddress("wglChoosePixelFormatARB"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_ARB_make_current_read(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_ARB_make_current_read
    if ((pwglMakeContextCurrentARB = (PFNWGLMAKECONTEXTCURRENTARBPROC) __GLeeGetProcAddress("wglMakeContextCurrentARB"))!=0) nLinked++;
    if ((pwglGetCurrentReadDCARB = (PFNWGLGETCURRENTREADDCARBPROC) __GLeeGetProcAddress("wglGetCurrentReadDCARB"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_ARB_pbuffer(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_ARB_pbuffer
    if ((pwglCreatePbufferARB = (PFNWGLCREATEPBUFFERARBPROC) __GLeeGetProcAddress("wglCreatePbufferARB"))!=0) nLinked++;
    if ((pwglGetPbufferDCARB = (PFNWGLGETPBUFFERDCARBPROC) __GLeeGetProcAddress("wglGetPbufferDCARB"))!=0) nLinked++;
    if ((pwglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC) __GLeeGetProcAddress("wglReleasePbufferDCARB"))!=0) nLinked++;
    if ((pwglDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARBPROC) __GLeeGetProcAddress("wglDestroyPbufferARB"))!=0) nLinked++;
    if ((pwglQueryPbufferARB = (PFNWGLQUERYPBUFFERARBPROC) __GLeeGetProcAddress("wglQueryPbufferARB"))!=0) nLinked++;
#endif
    if (nLinked==5) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_ARB_render_texture(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_ARB_render_texture
    if ((pwglBindTexImageARB = (PFNWGLBINDTEXIMAGEARBPROC) __GLeeGetProcAddress("wglBindTexImageARB"))!=0) nLinked++;
    if ((pwglReleaseTexImageARB = (PFNWGLRELEASETEXIMAGEARBPROC) __GLeeGetProcAddress("wglReleaseTexImageARB"))!=0) nLinked++;
    if ((pwglSetPbufferAttribARB = (PFNWGLSETPBUFFERATTRIBARBPROC) __GLeeGetProcAddress("wglSetPbufferAttribARB"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_ARB_pixel_format_float(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_WGL_EXT_make_current_read(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_EXT_make_current_read
    if ((pwglMakeContextCurrentEXT = (PFNWGLMAKECONTEXTCURRENTEXTPROC) __GLeeGetProcAddress("wglMakeContextCurrentEXT"))!=0) nLinked++;
    if ((pwglGetCurrentReadDCEXT = (PFNWGLGETCURRENTREADDCEXTPROC) __GLeeGetProcAddress("wglGetCurrentReadDCEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_EXT_pixel_format(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_EXT_pixel_format
    if ((pwglGetPixelFormatAttribivEXT = (PFNWGLGETPIXELFORMATATTRIBIVEXTPROC) __GLeeGetProcAddress("wglGetPixelFormatAttribivEXT"))!=0) nLinked++;
    if ((pwglGetPixelFormatAttribfvEXT = (PFNWGLGETPIXELFORMATATTRIBFVEXTPROC) __GLeeGetProcAddress("wglGetPixelFormatAttribfvEXT"))!=0) nLinked++;
    if ((pwglChoosePixelFormatEXT = (PFNWGLCHOOSEPIXELFORMATEXTPROC) __GLeeGetProcAddress("wglChoosePixelFormatEXT"))!=0) nLinked++;
#endif
    if (nLinked==3) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_EXT_pbuffer(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_EXT_pbuffer
    if ((pwglCreatePbufferEXT = (PFNWGLCREATEPBUFFEREXTPROC) __GLeeGetProcAddress("wglCreatePbufferEXT"))!=0) nLinked++;
    if ((pwglGetPbufferDCEXT = (PFNWGLGETPBUFFERDCEXTPROC) __GLeeGetProcAddress("wglGetPbufferDCEXT"))!=0) nLinked++;
    if ((pwglReleasePbufferDCEXT = (PFNWGLRELEASEPBUFFERDCEXTPROC) __GLeeGetProcAddress("wglReleasePbufferDCEXT"))!=0) nLinked++;
    if ((pwglDestroyPbufferEXT = (PFNWGLDESTROYPBUFFEREXTPROC) __GLeeGetProcAddress("wglDestroyPbufferEXT"))!=0) nLinked++;
    if ((pwglQueryPbufferEXT = (PFNWGLQUERYPBUFFEREXTPROC) __GLeeGetProcAddress("wglQueryPbufferEXT"))!=0) nLinked++;
#endif
    if (nLinked==5) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_EXT_depth_float(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_WGL_3DFX_multisample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_WGL_EXT_multisample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_WGL_I3D_digital_video_control(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_I3D_digital_video_control
    if ((pwglGetDigitalVideoParametersI3D = (PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC) __GLeeGetProcAddress("wglGetDigitalVideoParametersI3D"))!=0) nLinked++;
    if ((pwglSetDigitalVideoParametersI3D = (PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC) __GLeeGetProcAddress("wglSetDigitalVideoParametersI3D"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_I3D_gamma(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_I3D_gamma
    if ((pwglGetGammaTableParametersI3D = (PFNWGLGETGAMMATABLEPARAMETERSI3DPROC) __GLeeGetProcAddress("wglGetGammaTableParametersI3D"))!=0) nLinked++;
    if ((pwglSetGammaTableParametersI3D = (PFNWGLSETGAMMATABLEPARAMETERSI3DPROC) __GLeeGetProcAddress("wglSetGammaTableParametersI3D"))!=0) nLinked++;
    if ((pwglGetGammaTableI3D = (PFNWGLGETGAMMATABLEI3DPROC) __GLeeGetProcAddress("wglGetGammaTableI3D"))!=0) nLinked++;
    if ((pwglSetGammaTableI3D = (PFNWGLSETGAMMATABLEI3DPROC) __GLeeGetProcAddress("wglSetGammaTableI3D"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_I3D_genlock(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_I3D_genlock
    if ((pwglEnableGenlockI3D = (PFNWGLENABLEGENLOCKI3DPROC) __GLeeGetProcAddress("wglEnableGenlockI3D"))!=0) nLinked++;
    if ((pwglDisableGenlockI3D = (PFNWGLDISABLEGENLOCKI3DPROC) __GLeeGetProcAddress("wglDisableGenlockI3D"))!=0) nLinked++;
    if ((pwglIsEnabledGenlockI3D = (PFNWGLISENABLEDGENLOCKI3DPROC) __GLeeGetProcAddress("wglIsEnabledGenlockI3D"))!=0) nLinked++;
    if ((pwglGenlockSourceI3D = (PFNWGLGENLOCKSOURCEI3DPROC) __GLeeGetProcAddress("wglGenlockSourceI3D"))!=0) nLinked++;
    if ((pwglGetGenlockSourceI3D = (PFNWGLGETGENLOCKSOURCEI3DPROC) __GLeeGetProcAddress("wglGetGenlockSourceI3D"))!=0) nLinked++;
    if ((pwglGenlockSourceEdgeI3D = (PFNWGLGENLOCKSOURCEEDGEI3DPROC) __GLeeGetProcAddress("wglGenlockSourceEdgeI3D"))!=0) nLinked++;
    if ((pwglGetGenlockSourceEdgeI3D = (PFNWGLGETGENLOCKSOURCEEDGEI3DPROC) __GLeeGetProcAddress("wglGetGenlockSourceEdgeI3D"))!=0) nLinked++;
    if ((pwglGenlockSampleRateI3D = (PFNWGLGENLOCKSAMPLERATEI3DPROC) __GLeeGetProcAddress("wglGenlockSampleRateI3D"))!=0) nLinked++;
    if ((pwglGetGenlockSampleRateI3D = (PFNWGLGETGENLOCKSAMPLERATEI3DPROC) __GLeeGetProcAddress("wglGetGenlockSampleRateI3D"))!=0) nLinked++;
    if ((pwglGenlockSourceDelayI3D = (PFNWGLGENLOCKSOURCEDELAYI3DPROC) __GLeeGetProcAddress("wglGenlockSourceDelayI3D"))!=0) nLinked++;
    if ((pwglGetGenlockSourceDelayI3D = (PFNWGLGETGENLOCKSOURCEDELAYI3DPROC) __GLeeGetProcAddress("wglGetGenlockSourceDelayI3D"))!=0) nLinked++;
    if ((pwglQueryGenlockMaxSourceDelayI3D = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) __GLeeGetProcAddress("wglQueryGenlockMaxSourceDelayI3D"))!=0) nLinked++;
#endif
    if (nLinked==12) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_I3D_image_buffer(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_I3D_image_buffer
    if ((pwglCreateImageBufferI3D = (PFNWGLCREATEIMAGEBUFFERI3DPROC) __GLeeGetProcAddress("wglCreateImageBufferI3D"))!=0) nLinked++;
    if ((pwglDestroyImageBufferI3D = (PFNWGLDESTROYIMAGEBUFFERI3DPROC) __GLeeGetProcAddress("wglDestroyImageBufferI3D"))!=0) nLinked++;
    if ((pwglAssociateImageBufferEventsI3D = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) __GLeeGetProcAddress("wglAssociateImageBufferEventsI3D"))!=0) nLinked++;
    if ((pwglReleaseImageBufferEventsI3D = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC) __GLeeGetProcAddress("wglReleaseImageBufferEventsI3D"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_I3D_swap_frame_lock(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_I3D_swap_frame_lock
    if ((pwglEnableFrameLockI3D = (PFNWGLENABLEFRAMELOCKI3DPROC) __GLeeGetProcAddress("wglEnableFrameLockI3D"))!=0) nLinked++;
    if ((pwglDisableFrameLockI3D = (PFNWGLDISABLEFRAMELOCKI3DPROC) __GLeeGetProcAddress("wglDisableFrameLockI3D"))!=0) nLinked++;
    if ((pwglIsEnabledFrameLockI3D = (PFNWGLISENABLEDFRAMELOCKI3DPROC) __GLeeGetProcAddress("wglIsEnabledFrameLockI3D"))!=0) nLinked++;
    if ((pwglQueryFrameLockMasterI3D = (PFNWGLQUERYFRAMELOCKMASTERI3DPROC) __GLeeGetProcAddress("wglQueryFrameLockMasterI3D"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_NV_render_depth_texture(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_WGL_NV_render_texture_rectangle(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_WGL_ATI_pixel_format_float(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_WGL_NV_float_buffer(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_WGL_EXT_display_color_table(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_EXT_display_color_table
    if ((pwglCreateDisplayColorTableEXT = (PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC) __GLeeGetProcAddress("wglCreateDisplayColorTableEXT"))!=0) nLinked++;
    if ((pwglLoadDisplayColorTableEXT = (PFNWGLLOADDISPLAYCOLORTABLEEXTPROC) __GLeeGetProcAddress("wglLoadDisplayColorTableEXT"))!=0) nLinked++;
    if ((pwglBindDisplayColorTableEXT = (PFNWGLBINDDISPLAYCOLORTABLEEXTPROC) __GLeeGetProcAddress("wglBindDisplayColorTableEXT"))!=0) nLinked++;
    if ((pwglDestroyDisplayColorTableEXT = (PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC) __GLeeGetProcAddress("wglDestroyDisplayColorTableEXT"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_EXT_extensions_string(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_EXT_extensions_string
    if ((pwglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC) __GLeeGetProcAddress("wglGetExtensionsStringEXT"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_EXT_swap_control(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_EXT_swap_control
    if ((pwglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) __GLeeGetProcAddress("wglSwapIntervalEXT"))!=0) nLinked++;
    if ((pwglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC) __GLeeGetProcAddress("wglGetSwapIntervalEXT"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_NV_vertex_array_range(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_NV_vertex_array_range
    if ((pwglAllocateMemoryNV = (PFNWGLALLOCATEMEMORYNVPROC) __GLeeGetProcAddress("wglAllocateMemoryNV"))!=0) nLinked++;
    if ((pwglFreeMemoryNV = (PFNWGLFREEMEMORYNVPROC) __GLeeGetProcAddress("wglFreeMemoryNV"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_OML_sync_control(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_OML_sync_control
    if ((pwglGetSyncValuesOML = (PFNWGLGETSYNCVALUESOMLPROC) __GLeeGetProcAddress("wglGetSyncValuesOML"))!=0) nLinked++;
    if ((pwglGetMscRateOML = (PFNWGLGETMSCRATEOMLPROC) __GLeeGetProcAddress("wglGetMscRateOML"))!=0) nLinked++;
    if ((pwglSwapBuffersMscOML = (PFNWGLSWAPBUFFERSMSCOMLPROC) __GLeeGetProcAddress("wglSwapBuffersMscOML"))!=0) nLinked++;
    if ((pwglSwapLayerBuffersMscOML = (PFNWGLSWAPLAYERBUFFERSMSCOMLPROC) __GLeeGetProcAddress("wglSwapLayerBuffersMscOML"))!=0) nLinked++;
    if ((pwglWaitForMscOML = (PFNWGLWAITFORMSCOMLPROC) __GLeeGetProcAddress("wglWaitForMscOML"))!=0) nLinked++;
    if ((pwglWaitForSbcOML = (PFNWGLWAITFORSBCOMLPROC) __GLeeGetProcAddress("wglWaitForSbcOML"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_I3D_swap_frame_usage(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_I3D_swap_frame_usage
    if ((pwglGetFrameUsageI3D = (PFNWGLGETFRAMEUSAGEI3DPROC) __GLeeGetProcAddress("wglGetFrameUsageI3D"))!=0) nLinked++;
    if ((pwglBeginFrameTrackingI3D = (PFNWGLBEGINFRAMETRACKINGI3DPROC) __GLeeGetProcAddress("wglBeginFrameTrackingI3D"))!=0) nLinked++;
    if ((pwglEndFrameTrackingI3D = (PFNWGLENDFRAMETRACKINGI3DPROC) __GLeeGetProcAddress("wglEndFrameTrackingI3D"))!=0) nLinked++;
    if ((pwglQueryFrameTrackingI3D = (PFNWGLQUERYFRAMETRACKINGI3DPROC) __GLeeGetProcAddress("wglQueryFrameTrackingI3D"))!=0) nLinked++;
#endif
    if (nLinked==4) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_WGL_3DL_stereo_control(void)
{
    GLint nLinked=0;
#ifdef __GLEE_WGL_3DL_stereo_control
    if ((pwglSetStereoEmitterState3DL = (PFNWGLSETSTEREOEMITTERSTATE3DLPROC) __GLeeGetProcAddress("wglSetStereoEmitterState3DL"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLEE_LINK_FUNCTION __GLeeWGLLoadFunction[30];

void initWGLLoadFunctions(void)
{
    __GLeeWGLLoadFunction[0]=__GLeeLink_WGL_ARB_buffer_region;
    __GLeeWGLLoadFunction[1]=__GLeeLink_WGL_ARB_multisample;
    __GLeeWGLLoadFunction[2]=__GLeeLink_WGL_ARB_extensions_string;
    __GLeeWGLLoadFunction[3]=__GLeeLink_WGL_ARB_pixel_format;
    __GLeeWGLLoadFunction[4]=__GLeeLink_WGL_ARB_make_current_read;
    __GLeeWGLLoadFunction[5]=__GLeeLink_WGL_ARB_pbuffer;
    __GLeeWGLLoadFunction[6]=__GLeeLink_WGL_ARB_render_texture;
    __GLeeWGLLoadFunction[7]=__GLeeLink_WGL_ARB_pixel_format_float;
    __GLeeWGLLoadFunction[8]=__GLeeLink_WGL_EXT_make_current_read;
    __GLeeWGLLoadFunction[9]=__GLeeLink_WGL_EXT_pixel_format;
    __GLeeWGLLoadFunction[10]=__GLeeLink_WGL_EXT_pbuffer;
    __GLeeWGLLoadFunction[11]=__GLeeLink_WGL_EXT_depth_float;
    __GLeeWGLLoadFunction[12]=__GLeeLink_WGL_3DFX_multisample;
    __GLeeWGLLoadFunction[13]=__GLeeLink_WGL_EXT_multisample;
    __GLeeWGLLoadFunction[14]=__GLeeLink_WGL_I3D_digital_video_control;
    __GLeeWGLLoadFunction[15]=__GLeeLink_WGL_I3D_gamma;
    __GLeeWGLLoadFunction[16]=__GLeeLink_WGL_I3D_genlock;
    __GLeeWGLLoadFunction[17]=__GLeeLink_WGL_I3D_image_buffer;
    __GLeeWGLLoadFunction[18]=__GLeeLink_WGL_I3D_swap_frame_lock;
    __GLeeWGLLoadFunction[19]=__GLeeLink_WGL_NV_render_depth_texture;
    __GLeeWGLLoadFunction[20]=__GLeeLink_WGL_NV_render_texture_rectangle;
    __GLeeWGLLoadFunction[21]=__GLeeLink_WGL_ATI_pixel_format_float;
    __GLeeWGLLoadFunction[22]=__GLeeLink_WGL_NV_float_buffer;
    __GLeeWGLLoadFunction[23]=__GLeeLink_WGL_EXT_display_color_table;
    __GLeeWGLLoadFunction[24]=__GLeeLink_WGL_EXT_extensions_string;
    __GLeeWGLLoadFunction[25]=__GLeeLink_WGL_EXT_swap_control;
    __GLeeWGLLoadFunction[26]=__GLeeLink_WGL_NV_vertex_array_range;
    __GLeeWGLLoadFunction[27]=__GLeeLink_WGL_OML_sync_control;
    __GLeeWGLLoadFunction[28]=__GLeeLink_WGL_I3D_swap_frame_usage;
    __GLeeWGLLoadFunction[29]=__GLeeLink_WGL_3DL_stereo_control;
}

#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else /* Linux */
GLuint __GLeeLink_GLX_VERSION_1_3(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_VERSION_1_3
    if ((pglXGetFBConfigs = (PFNGLXGETFBCONFIGSPROC) __GLeeGetProcAddress("glXGetFBConfigs"))!=0) nLinked++;
    if ((pglXChooseFBConfig = (PFNGLXCHOOSEFBCONFIGPROC) __GLeeGetProcAddress("glXChooseFBConfig"))!=0) nLinked++;
    if ((pglXGetFBConfigAttrib = (PFNGLXGETFBCONFIGATTRIBPROC) __GLeeGetProcAddress("glXGetFBConfigAttrib"))!=0) nLinked++;
    if ((pglXGetVisualFromFBConfig = (PFNGLXGETVISUALFROMFBCONFIGPROC) __GLeeGetProcAddress("glXGetVisualFromFBConfig"))!=0) nLinked++;
    if ((pglXCreateWindow = (PFNGLXCREATEWINDOWPROC) __GLeeGetProcAddress("glXCreateWindow"))!=0) nLinked++;
    if ((pglXDestroyWindow = (PFNGLXDESTROYWINDOWPROC) __GLeeGetProcAddress("glXDestroyWindow"))!=0) nLinked++;
    if ((pglXCreatePixmap = (PFNGLXCREATEPIXMAPPROC) __GLeeGetProcAddress("glXCreatePixmap"))!=0) nLinked++;
    if ((pglXDestroyPixmap = (PFNGLXDESTROYPIXMAPPROC) __GLeeGetProcAddress("glXDestroyPixmap"))!=0) nLinked++;
    if ((pglXCreatePbuffer = (PFNGLXCREATEPBUFFERPROC) __GLeeGetProcAddress("glXCreatePbuffer"))!=0) nLinked++;
    if ((pglXDestroyPbuffer = (PFNGLXDESTROYPBUFFERPROC) __GLeeGetProcAddress("glXDestroyPbuffer"))!=0) nLinked++;
    if ((pglXQueryDrawable = (PFNGLXQUERYDRAWABLEPROC) __GLeeGetProcAddress("glXQueryDrawable"))!=0) nLinked++;
    if ((pglXCreateNewContext = (PFNGLXCREATENEWCONTEXTPROC) __GLeeGetProcAddress("glXCreateNewContext"))!=0) nLinked++;
    if ((pglXMakeContextCurrent = (PFNGLXMAKECONTEXTCURRENTPROC) __GLeeGetProcAddress("glXMakeContextCurrent"))!=0) nLinked++;
    if ((pglXGetCurrentReadDrawable = (PFNGLXGETCURRENTREADDRAWABLEPROC) __GLeeGetProcAddress("glXGetCurrentReadDrawable"))!=0) nLinked++;
    if ((pglXGetCurrentDisplay = (PFNGLXGETCURRENTDISPLAYPROC) __GLeeGetProcAddress("glXGetCurrentDisplay"))!=0) nLinked++;
    if ((pglXQueryContext = (PFNGLXQUERYCONTEXTPROC) __GLeeGetProcAddress("glXQueryContext"))!=0) nLinked++;
    if ((pglXSelectEvent = (PFNGLXSELECTEVENTPROC) __GLeeGetProcAddress("glXSelectEvent"))!=0) nLinked++;
    if ((pglXGetSelectedEvent = (PFNGLXGETSELECTEDEVENTPROC) __GLeeGetProcAddress("glXGetSelectedEvent"))!=0) nLinked++;
#endif
    if (nLinked==18) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_VERSION_1_4(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_VERSION_1_4
    if ((pglXGetProcAddress = (PFNGLXGETPROCADDRESSPROC) __GLeeGetProcAddress("glXGetProcAddress"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_ARB_multisample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_ARB_fbconfig_float(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_SGIS_multisample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_EXT_visual_info(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_SGI_swap_control(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SGI_swap_control
    if ((pglXSwapIntervalSGI = (PFNGLXSWAPINTERVALSGIPROC) __GLeeGetProcAddress("glXSwapIntervalSGI"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_SGI_video_sync(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SGI_video_sync
    if ((pglXGetVideoSyncSGI = (PFNGLXGETVIDEOSYNCSGIPROC) __GLeeGetProcAddress("glXGetVideoSyncSGI"))!=0) nLinked++;
    if ((pglXWaitVideoSyncSGI = (PFNGLXWAITVIDEOSYNCSGIPROC) __GLeeGetProcAddress("glXWaitVideoSyncSGI"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_SGI_make_current_read(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SGI_make_current_read
    if ((pglXMakeCurrentReadSGI = (PFNGLXMAKECURRENTREADSGIPROC) __GLeeGetProcAddress("glXMakeCurrentReadSGI"))!=0) nLinked++;
    if ((pglXGetCurrentReadDrawableSGI = (PFNGLXGETCURRENTREADDRAWABLESGIPROC) __GLeeGetProcAddress("glXGetCurrentReadDrawableSGI"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_EXT_visual_rating(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_EXT_import_context(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_EXT_import_context
    if ((pglXGetCurrentDisplayEXT = (PFNGLXGETCURRENTDISPLAYEXTPROC) __GLeeGetProcAddress("glXGetCurrentDisplayEXT"))!=0) nLinked++;
    if ((pglXQueryContextInfoEXT = (PFNGLXQUERYCONTEXTINFOEXTPROC) __GLeeGetProcAddress("glXQueryContextInfoEXT"))!=0) nLinked++;
    if ((pglXGetContextIDEXT = (PFNGLXGETCONTEXTIDEXTPROC) __GLeeGetProcAddress("glXGetContextIDEXT"))!=0) nLinked++;
    if ((pglXImportContextEXT = (PFNGLXIMPORTCONTEXTEXTPROC) __GLeeGetProcAddress("glXImportContextEXT"))!=0) nLinked++;
    if ((pglXFreeContextEXT = (PFNGLXFREECONTEXTEXTPROC) __GLeeGetProcAddress("glXFreeContextEXT"))!=0) nLinked++;
#endif
    if (nLinked==5) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_SGIX_fbconfig(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SGIX_fbconfig
    if ((pglXGetFBConfigAttribSGIX = (PFNGLXGETFBCONFIGATTRIBSGIXPROC) __GLeeGetProcAddress("glXGetFBConfigAttribSGIX"))!=0) nLinked++;
    if ((pglXChooseFBConfigSGIX = (PFNGLXCHOOSEFBCONFIGSGIXPROC) __GLeeGetProcAddress("glXChooseFBConfigSGIX"))!=0) nLinked++;
    if ((pglXCreateGLXPixmapWithConfigSGIX = (PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC) __GLeeGetProcAddress("glXCreateGLXPixmapWithConfigSGIX"))!=0) nLinked++;
    if ((pglXCreateContextWithConfigSGIX = (PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC) __GLeeGetProcAddress("glXCreateContextWithConfigSGIX"))!=0) nLinked++;
    if ((pglXGetVisualFromFBConfigSGIX = (PFNGLXGETVISUALFROMFBCONFIGSGIXPROC) __GLeeGetProcAddress("glXGetVisualFromFBConfigSGIX"))!=0) nLinked++;
    if ((pglXGetFBConfigFromVisualSGIX = (PFNGLXGETFBCONFIGFROMVISUALSGIXPROC) __GLeeGetProcAddress("glXGetFBConfigFromVisualSGIX"))!=0) nLinked++;
#endif
    if (nLinked==6) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_SGIX_pbuffer(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SGIX_pbuffer
    if ((pglXCreateGLXPbufferSGIX = (PFNGLXCREATEGLXPBUFFERSGIXPROC) __GLeeGetProcAddress("glXCreateGLXPbufferSGIX"))!=0) nLinked++;
    if ((pglXDestroyGLXPbufferSGIX = (PFNGLXDESTROYGLXPBUFFERSGIXPROC) __GLeeGetProcAddress("glXDestroyGLXPbufferSGIX"))!=0) nLinked++;
    if ((pglXQueryGLXPbufferSGIX = (PFNGLXQUERYGLXPBUFFERSGIXPROC) __GLeeGetProcAddress("glXQueryGLXPbufferSGIX"))!=0) nLinked++;
    if ((pglXSelectEventSGIX = (PFNGLXSELECTEVENTSGIXPROC) __GLeeGetProcAddress("glXSelectEventSGIX"))!=0) nLinked++;
    if ((pglXGetSelectedEventSGIX = (PFNGLXGETSELECTEDEVENTSGIXPROC) __GLeeGetProcAddress("glXGetSelectedEventSGIX"))!=0) nLinked++;
#endif
    if (nLinked==5) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_SGI_cushion(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SGI_cushion
    if ((pglXCushionSGI = (PFNGLXCUSHIONSGIPROC) __GLeeGetProcAddress("glXCushionSGI"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_SGIX_video_resize(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SGIX_video_resize
    if ((pglXBindChannelToWindowSGIX = (PFNGLXBINDCHANNELTOWINDOWSGIXPROC) __GLeeGetProcAddress("glXBindChannelToWindowSGIX"))!=0) nLinked++;
    if ((pglXChannelRectSGIX = (PFNGLXCHANNELRECTSGIXPROC) __GLeeGetProcAddress("glXChannelRectSGIX"))!=0) nLinked++;
    if ((pglXQueryChannelRectSGIX = (PFNGLXQUERYCHANNELRECTSGIXPROC) __GLeeGetProcAddress("glXQueryChannelRectSGIX"))!=0) nLinked++;
    if ((pglXQueryChannelDeltasSGIX = (PFNGLXQUERYCHANNELDELTASSGIXPROC) __GLeeGetProcAddress("glXQueryChannelDeltasSGIX"))!=0) nLinked++;
    if ((pglXChannelRectSyncSGIX = (PFNGLXCHANNELRECTSYNCSGIXPROC) __GLeeGetProcAddress("glXChannelRectSyncSGIX"))!=0) nLinked++;
#endif
    if (nLinked==5) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_SGIX_swap_group(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SGIX_swap_group
    if ((pglXJoinSwapGroupSGIX = (PFNGLXJOINSWAPGROUPSGIXPROC) __GLeeGetProcAddress("glXJoinSwapGroupSGIX"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_SGIX_swap_barrier(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SGIX_swap_barrier
    if ((pglXBindSwapBarrierSGIX = (PFNGLXBINDSWAPBARRIERSGIXPROC) __GLeeGetProcAddress("glXBindSwapBarrierSGIX"))!=0) nLinked++;
    if ((pglXQueryMaxSwapBarriersSGIX = (PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC) __GLeeGetProcAddress("glXQueryMaxSwapBarriersSGIX"))!=0) nLinked++;
#endif
    if (nLinked==2) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_SGIS_blended_overlay(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_SGIS_shared_multisample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_SUN_get_transparent_index(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SUN_get_transparent_index
    if ((pglXGetTransparentIndexSUN = (PFNGLXGETTRANSPARENTINDEXSUNPROC) __GLeeGetProcAddress("glXGetTransparentIndexSUN"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_3DFX_multisample(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_MESA_copy_sub_buffer(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_MESA_copy_sub_buffer
    if ((pglXCopySubBufferMESA = (PFNGLXCOPYSUBBUFFERMESAPROC) __GLeeGetProcAddress("glXCopySubBufferMESA"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_MESA_pixmap_colormap(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_MESA_pixmap_colormap
    if ((pglXCreateGLXPixmapMESA = (PFNGLXCREATEGLXPIXMAPMESAPROC) __GLeeGetProcAddress("glXCreateGLXPixmapMESA"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_MESA_release_buffers(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_MESA_release_buffers
    if ((pglXReleaseBuffersMESA = (PFNGLXRELEASEBUFFERSMESAPROC) __GLeeGetProcAddress("glXReleaseBuffersMESA"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_MESA_set_3dfx_mode(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_MESA_set_3dfx_mode
    if ((pglXSet3DfxModeMESA = (PFNGLXSET3DFXMODEMESAPROC) __GLeeGetProcAddress("glXSet3DfxModeMESA"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_SGIX_visual_select_group(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_OML_swap_method(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_OML_sync_control(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_OML_sync_control
    if ((pglXGetSyncValuesOML = (PFNGLXGETSYNCVALUESOMLPROC) __GLeeGetProcAddress("glXGetSyncValuesOML"))!=0) nLinked++;
    if ((pglXGetMscRateOML = (PFNGLXGETMSCRATEOMLPROC) __GLeeGetProcAddress("glXGetMscRateOML"))!=0) nLinked++;
    if ((pglXSwapBuffersMscOML = (PFNGLXSWAPBUFFERSMSCOMLPROC) __GLeeGetProcAddress("glXSwapBuffersMscOML"))!=0) nLinked++;
    if ((pglXWaitForMscOML = (PFNGLXWAITFORMSCOMLPROC) __GLeeGetProcAddress("glXWaitForMscOML"))!=0) nLinked++;
    if ((pglXWaitForSbcOML = (PFNGLXWAITFORSBCOMLPROC) __GLeeGetProcAddress("glXWaitForSbcOML"))!=0) nLinked++;
#endif
    if (nLinked==5) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_NV_float_buffer(void) {return GLEE_LINK_COMPLETE;}

GLuint __GLeeLink_GLX_SGIX_hyperpipe(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_SGIX_hyperpipe
    if ((pglXQueryHyperpipeNetworkSGIX = (PFNGLXQUERYHYPERPIPENETWORKSGIXPROC) __GLeeGetProcAddress("glXQueryHyperpipeNetworkSGIX"))!=0) nLinked++;
    if ((pglXHyperpipeConfigSGIX = (PFNGLXHYPERPIPECONFIGSGIXPROC) __GLeeGetProcAddress("glXHyperpipeConfigSGIX"))!=0) nLinked++;
    if ((pglXQueryHyperpipeConfigSGIX = (PFNGLXQUERYHYPERPIPECONFIGSGIXPROC) __GLeeGetProcAddress("glXQueryHyperpipeConfigSGIX"))!=0) nLinked++;
    if ((pglXDestroyHyperpipeConfigSGIX = (PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC) __GLeeGetProcAddress("glXDestroyHyperpipeConfigSGIX"))!=0) nLinked++;
    if ((pglXBindHyperpipeSGIX = (PFNGLXBINDHYPERPIPESGIXPROC) __GLeeGetProcAddress("glXBindHyperpipeSGIX"))!=0) nLinked++;
    if ((pglXQueryHyperpipeBestAttribSGIX = (PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC) __GLeeGetProcAddress("glXQueryHyperpipeBestAttribSGIX"))!=0) nLinked++;
    if ((pglXHyperpipeAttribSGIX = (PFNGLXHYPERPIPEATTRIBSGIXPROC) __GLeeGetProcAddress("glXHyperpipeAttribSGIX"))!=0) nLinked++;
    if ((pglXQueryHyperpipeAttribSGIX = (PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC) __GLeeGetProcAddress("glXQueryHyperpipeAttribSGIX"))!=0) nLinked++;
#endif
    if (nLinked==8) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_MESA_agp_offset(void)
{
    GLint nLinked=0;
#ifdef __GLEE_GLX_MESA_agp_offset
    if ((pglXGetAGPOffsetMESA = (PFNGLXGETAGPOFFSETMESAPROC) __GLeeGetProcAddress("glXGetAGPOffsetMESA"))!=0) nLinked++;
#endif
    if (nLinked==1) return GLEE_LINK_COMPLETE;
    if (nLinked==0) return GLEE_LINK_FAIL;
    return GLEE_LINK_PARTIAL;
}

GLuint __GLeeLink_GLX_EXT_scene_marker(void) {return GLEE_LINK_COMPLETE;}

GLEE_LINK_FUNCTION __GLeeGLXLoadFunction[32];

void initGLXLoadFunctions(void)
{
    __GLeeGLXLoadFunction[0]=__GLeeLink_GLX_VERSION_1_3;
    __GLeeGLXLoadFunction[1]=__GLeeLink_GLX_VERSION_1_4;
    __GLeeGLXLoadFunction[2]=__GLeeLink_GLX_ARB_multisample;
    __GLeeGLXLoadFunction[3]=__GLeeLink_GLX_ARB_fbconfig_float;
    __GLeeGLXLoadFunction[4]=__GLeeLink_GLX_SGIS_multisample;
    __GLeeGLXLoadFunction[5]=__GLeeLink_GLX_EXT_visual_info;
    __GLeeGLXLoadFunction[6]=__GLeeLink_GLX_SGI_swap_control;
    __GLeeGLXLoadFunction[7]=__GLeeLink_GLX_SGI_video_sync;
    __GLeeGLXLoadFunction[8]=__GLeeLink_GLX_SGI_make_current_read;
    __GLeeGLXLoadFunction[9]=__GLeeLink_GLX_EXT_visual_rating;
    __GLeeGLXLoadFunction[10]=__GLeeLink_GLX_EXT_import_context;
    __GLeeGLXLoadFunction[11]=__GLeeLink_GLX_SGIX_fbconfig;
    __GLeeGLXLoadFunction[12]=__GLeeLink_GLX_SGIX_pbuffer;
    __GLeeGLXLoadFunction[13]=__GLeeLink_GLX_SGI_cushion;
    __GLeeGLXLoadFunction[14]=__GLeeLink_GLX_SGIX_video_resize;
    __GLeeGLXLoadFunction[15]=__GLeeLink_GLX_SGIX_swap_group;
    __GLeeGLXLoadFunction[16]=__GLeeLink_GLX_SGIX_swap_barrier;
    __GLeeGLXLoadFunction[17]=__GLeeLink_GLX_SGIS_blended_overlay;
    __GLeeGLXLoadFunction[18]=__GLeeLink_GLX_SGIS_shared_multisample;
    __GLeeGLXLoadFunction[19]=__GLeeLink_GLX_SUN_get_transparent_index;
    __GLeeGLXLoadFunction[20]=__GLeeLink_GLX_3DFX_multisample;
    __GLeeGLXLoadFunction[21]=__GLeeLink_GLX_MESA_copy_sub_buffer;
    __GLeeGLXLoadFunction[22]=__GLeeLink_GLX_MESA_pixmap_colormap;
    __GLeeGLXLoadFunction[23]=__GLeeLink_GLX_MESA_release_buffers;
    __GLeeGLXLoadFunction[24]=__GLeeLink_GLX_MESA_set_3dfx_mode;
    __GLeeGLXLoadFunction[25]=__GLeeLink_GLX_SGIX_visual_select_group;
    __GLeeGLXLoadFunction[26]=__GLeeLink_GLX_OML_swap_method;
    __GLeeGLXLoadFunction[27]=__GLeeLink_GLX_OML_sync_control;
    __GLeeGLXLoadFunction[28]=__GLeeLink_GLX_NV_float_buffer;
    __GLeeGLXLoadFunction[29]=__GLeeLink_GLX_SGIX_hyperpipe;
    __GLeeGLXLoadFunction[30]=__GLeeLink_GLX_MESA_agp_offset;
    __GLeeGLXLoadFunction[31]=__GLeeLink_GLX_EXT_scene_marker;
}

#endif /* end Linux */


/*****************************************************************
 * GLee internal types
 *****************************************************************/
typedef struct 
{
	char ** names;
	int * lengths;
	int numNames;
}ExtensionList;


/*****************************************************************
 * GLee internal variables
 *****************************************************************/
char GLeeErrorString[256]="";


/*****************************************************************
 * GLee internal functions
 *****************************************************************/

void __GLeeExtList_init(ExtensionList *extList)
{
	extList->names=0;
	extList->lengths=0;
	extList->numNames=0;
}

void __GLeeExtList_clean(ExtensionList *extList)
{
	int a;
	for (a=0;a<extList->numNames;a++)
	{
		if (extList->names[a]!=0) free((void *)extList->names[a]);
	}
	if (extList->names!=0) free((void *)extList->names);
	if (extList->lengths!=0) free((void *)extList->lengths);
	extList->names=0;
	extList->lengths=0;
	extList->numNames=0;
}

void __GLeeExtList_add(ExtensionList *extList, const char * extName)
{
	int length=(int)strlen(extName)+1;
	int i=extList->numNames;
	int n=i+1;
	if (i==0)
	{
		extList->lengths=(int *)malloc(sizeof(int));
		extList->names=(char **)malloc(sizeof(char *));
	}else
	{
		extList->lengths=(int *)realloc((void *)extList->lengths, n*sizeof(int));
		extList->names=(char **)realloc((void *)extList->names, n*sizeof(char *));
	}
	extList->names[i]=(char *)malloc(length*sizeof(char));
	strcpy(extList->names[i],extName);
	extList->lengths[i]=length;
	extList->numNames++;
}

const char *__GLeeGetExtStrPlat()
{
#ifdef WIN32
	if (!_GLEE_WGL_ARB_extensions_string)
		pwglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) wglGetProcAddress("wglGetExtensionsStringARB");

	if (pwglGetExtensionsStringARB)
		return (const char *)pwglGetExtensionsStringARB(wglGetCurrentDC());
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else
	Display *dpy=glXGetCurrentDisplay();
	if(dpy)
	{
		int dpynr=DefaultScreen(dpy);
		return (const char*)glXQueryExtensionsString(dpy,dpynr);
	}
#endif
	return 0;
}

void __GLeeWriteError(const char * errorStr)
{
	int a=0;
	for (a=0;a<256;a++)
	{
		GLeeErrorString[a]=errorStr[a];
	}
	GLeeErrorString[255]='\0';
}

int __GLeeGetVersionNumber(char *versionStr)
{
	int major=(int)versionStr[0]-(int)'0';
	int minor=(int)versionStr[2]-(int)'0';
	return major<<8 | minor;
}

GLboolean __GLeeGetExtensions(ExtensionList* extList)
{
	const char * platExtStr;
	const char * glExtStr;
	char * extStr;
	char emptyString[1]="";
	char extensionName[1024];
	int a,b;
	int numExtensions;
	int eNum;
	
	/* read the platform specific extension string */
	platExtStr=__GLeeGetExtStrPlat(); 
	if (!platExtStr) platExtStr=emptyString;

	glExtStr=(const char *)glGetString(GL_EXTENSIONS);
	if (glExtStr==0) 
	{
		__GLeeWriteError("glGetString(GL_EXTENSIONS) failed.");
		return GL_FALSE;
	}

	/* allocate the extension string */
	extStr=(char *)malloc( (strlen(platExtStr)+strlen(glExtStr)+1) * sizeof(char) );

	/* concatenate the two extension strings */
	sprintf(extStr,"%s%s",platExtStr,glExtStr);

	/* count the extensions */
	numExtensions=0;
	for (a=0;extStr[a]!='\0';++a)
	{
		if (extStr[a]==' ') ++numExtensions;
	}

	/* extract the extensions */
	eNum=0;
	a=0;
	while (extStr[a]!='\0')
	{
		b=0;
		while (extStr[a]!=' ' && extStr[a]!='\0' && b<1022)
		{
			extensionName[b]=extStr[a];
			b++; a++;
		}
		if (b==1023)
		{
			__GLeeWriteError("Extension name exceeds 1023 characters.");
			free((void *)extStr);
			return GL_FALSE;
		}

		extensionName[b]='\0'; 

		/* add the extension */
		__GLeeExtList_add(extList,extensionName);

		eNum++;	a++; 
	}
	free((void *)extStr);
	return GL_TRUE;
}

GLboolean __GLeeCheckExtension(const char * name, ExtensionList *extensionNames)
{
	int n=extensionNames->numNames;
	int a;
    for (a=0;a<n;a++)
	{
		if (strcmp(extensionNames->names[a],name)==0)
			return GL_TRUE;
	}
	return GL_FALSE;
}

GLEE_EXTERN GLint __GLeeGetExtensionNumber(const char *extensionName, int type)
{
	int a;
	switch (type)
	{
	case 0:
		for (a=0;a<__GLeeGLNumExtensions;a++)
			if (strcmp(extensionName,__GLeeGLExtensionNames[a])==0)	return a;
		return -1;
#ifdef WIN32
	case 1:
		for (a=0;a<__GLeeWGLNumExtensions;a++)
			if (strcmp(extensionName,__GLeeWGLExtensionNames[a])==0) return a;
		return -1;
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else
	case 2:
		for (a=0;a<__GLeeGLXNumExtensions;a++)
			if (strcmp(extensionName,__GLeeGLXExtensionNames[a])==0) return a;
		return -1;
#endif
	}
	return -1;
}

/*****************************************************************
 * GLee external functions 
 *****************************************************************/

#ifdef WIN32
GLEE_EXTERN const char * GLeeGetExtStrWGL()
{
	return __GLeeGetExtStrPlat();
}
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else
GLEE_EXTERN const char * GLeeGetExtStrGLX()	
{
	return __GLeeGetExtStrPlat();
}
#endif

GLEE_EXTERN const char * GLeeGetExtStrGL()
{
	return (const char *)glGetString(GL_EXTENSIONS);
}

GLEE_EXTERN const char * GLeeGetErrorString()
{
	return GLeeErrorString;
}

GLboolean __GLeeInitedLoadFunctions=GL_FALSE;

GLEE_EXTERN GLint GLeeForceLink(const char * extensionName)
{
	int type=0; 
	int extNum;
	int len=(int)strlen(extensionName);
	if (len<5) return GLEE_LINK_FAIL;
	if (!__GLeeInitedLoadFunctions)
	{
		if (!__GLeeInited) GLeeInit();
		initGLLoadFunctions();
#ifdef WIN32
		initWGLLoadFunctions();
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else
		initGLXLoadFunctions();
#endif
		__GLeeInitedLoadFunctions=GL_TRUE;
	}
	if (extensionName[0]=='W') type=1;
	else if (extensionName[2]=='X') type=2;	
	extNum=__GLeeGetExtensionNumber(extensionName,type);
	if (extNum==-1) return GLEE_LINK_FAIL;
	if (type==0) return __GLeeGLLoadFunction[extNum]();
#ifdef WIN32
	if (type==1) return __GLeeWGLLoadFunction[extNum]();
#elif defined(__APPLE__) || defined(__APPLE_CC__)	
#else
	if (type==2) return __GLeeGLXLoadFunction[extNum]();
#endif
	return GLEE_LINK_FAIL;
}

GLEE_EXTERN GLboolean GLeeEnabled(GLboolean * extensionQueryingVariable)
{
	if (!__GLeeInited) GLeeInit();
	return *extensionQueryingVariable;	
}

GLEE_EXTERN GLboolean GLeeInit()
{
	int version;
	ExtensionList extensionNames;
	
	if (__GLeeInited) 
	{
		return GL_FALSE;
	}

	__GLeeExtList_init(&extensionNames);
	if (!__GLeeGetExtensions(&extensionNames)) 
	{
		__GLeeWriteError("GL extension querying failed.");
		__GLeeExtList_clean(&extensionNames);
		return GL_FALSE;
	}

	version=__GLeeGetVersionNumber((char *)glGetString(GL_VERSION));

	__GLeeInited = GL_TRUE;


/*****************************************************************
 * Autogenerated linking functions
 *****************************************************************/
    if (version>=258)
    {
        _GLEE_VERSION_1_2 = GL_TRUE;
        __GLeeLink_GL_VERSION_1_2();
    }
    if (__GLeeCheckExtension("GL_ARB_imaging", &extensionNames) )
    {
        _GLEE_ARB_imaging = GL_TRUE;
        __GLeeLink_GL_ARB_imaging();
    }
    if (version>=259)
    {
        _GLEE_VERSION_1_3 = GL_TRUE;
        __GLeeLink_GL_VERSION_1_3();
    }
    if (version>=260)
    {
        _GLEE_VERSION_1_4 = GL_TRUE;
        __GLeeLink_GL_VERSION_1_4();
    }
    if (version>=261)
    {
        _GLEE_VERSION_1_5 = GL_TRUE;
        __GLeeLink_GL_VERSION_1_5();
    }
    if (version>=512)
    {
        _GLEE_VERSION_2_0 = GL_TRUE;
        __GLeeLink_GL_VERSION_2_0();
    }
    if (version>=513)
    {
        _GLEE_VERSION_2_1 = GL_TRUE;
        __GLeeLink_GL_VERSION_2_1();
    }
    if (__GLeeCheckExtension("GL_ARB_multitexture", &extensionNames) )
    {
        _GLEE_ARB_multitexture = GL_TRUE;
        __GLeeLink_GL_ARB_multitexture();
    }
    if (__GLeeCheckExtension("GL_ARB_transpose_matrix", &extensionNames) )
    {
        _GLEE_ARB_transpose_matrix = GL_TRUE;
        __GLeeLink_GL_ARB_transpose_matrix();
    }
    if (__GLeeCheckExtension("GL_ARB_multisample", &extensionNames) )
    {
        _GLEE_ARB_multisample = GL_TRUE;
        __GLeeLink_GL_ARB_multisample();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_env_add", &extensionNames) )
    {
        _GLEE_ARB_texture_env_add = GL_TRUE;
        __GLeeLink_GL_ARB_texture_env_add();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_cube_map", &extensionNames) )
    {
        _GLEE_ARB_texture_cube_map = GL_TRUE;
        __GLeeLink_GL_ARB_texture_cube_map();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_compression", &extensionNames) )
    {
        _GLEE_ARB_texture_compression = GL_TRUE;
        __GLeeLink_GL_ARB_texture_compression();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_border_clamp", &extensionNames) )
    {
        _GLEE_ARB_texture_border_clamp = GL_TRUE;
        __GLeeLink_GL_ARB_texture_border_clamp();
    }
    if (__GLeeCheckExtension("GL_ARB_point_parameters", &extensionNames) )
    {
        _GLEE_ARB_point_parameters = GL_TRUE;
        __GLeeLink_GL_ARB_point_parameters();
    }
    if (__GLeeCheckExtension("GL_ARB_vertex_blend", &extensionNames) )
    {
        _GLEE_ARB_vertex_blend = GL_TRUE;
        __GLeeLink_GL_ARB_vertex_blend();
    }
    if (__GLeeCheckExtension("GL_ARB_matrix_palette", &extensionNames) )
    {
        _GLEE_ARB_matrix_palette = GL_TRUE;
        __GLeeLink_GL_ARB_matrix_palette();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_env_combine", &extensionNames) )
    {
        _GLEE_ARB_texture_env_combine = GL_TRUE;
        __GLeeLink_GL_ARB_texture_env_combine();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_env_crossbar", &extensionNames) )
    {
        _GLEE_ARB_texture_env_crossbar = GL_TRUE;
        __GLeeLink_GL_ARB_texture_env_crossbar();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_env_dot3", &extensionNames) )
    {
        _GLEE_ARB_texture_env_dot3 = GL_TRUE;
        __GLeeLink_GL_ARB_texture_env_dot3();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_mirrored_repeat", &extensionNames) )
    {
        _GLEE_ARB_texture_mirrored_repeat = GL_TRUE;
        __GLeeLink_GL_ARB_texture_mirrored_repeat();
    }
    if (__GLeeCheckExtension("GL_ARB_depth_texture", &extensionNames) )
    {
        _GLEE_ARB_depth_texture = GL_TRUE;
        __GLeeLink_GL_ARB_depth_texture();
    }
    if (__GLeeCheckExtension("GL_ARB_shadow", &extensionNames) )
    {
        _GLEE_ARB_shadow = GL_TRUE;
        __GLeeLink_GL_ARB_shadow();
    }
    if (__GLeeCheckExtension("GL_ARB_shadow_ambient", &extensionNames) )
    {
        _GLEE_ARB_shadow_ambient = GL_TRUE;
        __GLeeLink_GL_ARB_shadow_ambient();
    }
    if (__GLeeCheckExtension("GL_ARB_window_pos", &extensionNames) )
    {
        _GLEE_ARB_window_pos = GL_TRUE;
        __GLeeLink_GL_ARB_window_pos();
    }
    if (__GLeeCheckExtension("GL_ARB_vertex_program", &extensionNames) )
    {
        _GLEE_ARB_vertex_program = GL_TRUE;
        __GLeeLink_GL_ARB_vertex_program();
    }
    if (__GLeeCheckExtension("GL_ARB_fragment_program", &extensionNames) )
    {
        _GLEE_ARB_fragment_program = GL_TRUE;
        __GLeeLink_GL_ARB_fragment_program();
    }
    if (__GLeeCheckExtension("GL_ARB_vertex_buffer_object", &extensionNames) )
    {
        _GLEE_ARB_vertex_buffer_object = GL_TRUE;
        __GLeeLink_GL_ARB_vertex_buffer_object();
    }
    if (__GLeeCheckExtension("GL_ARB_occlusion_query", &extensionNames) )
    {
        _GLEE_ARB_occlusion_query = GL_TRUE;
        __GLeeLink_GL_ARB_occlusion_query();
    }
    if (__GLeeCheckExtension("GL_ARB_shader_objects", &extensionNames) )
    {
        _GLEE_ARB_shader_objects = GL_TRUE;
        __GLeeLink_GL_ARB_shader_objects();
    }
    if (__GLeeCheckExtension("GL_ARB_vertex_shader", &extensionNames) )
    {
        _GLEE_ARB_vertex_shader = GL_TRUE;
        __GLeeLink_GL_ARB_vertex_shader();
    }
    if (__GLeeCheckExtension("GL_ARB_fragment_shader", &extensionNames) )
    {
        _GLEE_ARB_fragment_shader = GL_TRUE;
        __GLeeLink_GL_ARB_fragment_shader();
    }
    if (__GLeeCheckExtension("GL_ARB_shading_language_100", &extensionNames) )
    {
        _GLEE_ARB_shading_language_100 = GL_TRUE;
        __GLeeLink_GL_ARB_shading_language_100();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_non_power_of_two", &extensionNames) )
    {
        _GLEE_ARB_texture_non_power_of_two = GL_TRUE;
        __GLeeLink_GL_ARB_texture_non_power_of_two();
    }
    if (__GLeeCheckExtension("GL_ARB_point_sprite", &extensionNames) )
    {
        _GLEE_ARB_point_sprite = GL_TRUE;
        __GLeeLink_GL_ARB_point_sprite();
    }
    if (__GLeeCheckExtension("GL_ARB_fragment_program_shadow", &extensionNames) )
    {
        _GLEE_ARB_fragment_program_shadow = GL_TRUE;
        __GLeeLink_GL_ARB_fragment_program_shadow();
    }
    if (__GLeeCheckExtension("GL_ARB_draw_buffers", &extensionNames) )
    {
        _GLEE_ARB_draw_buffers = GL_TRUE;
        __GLeeLink_GL_ARB_draw_buffers();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_rectangle", &extensionNames) )
    {
        _GLEE_ARB_texture_rectangle = GL_TRUE;
        __GLeeLink_GL_ARB_texture_rectangle();
    }
    if (__GLeeCheckExtension("GL_ARB_color_buffer_float", &extensionNames) )
    {
        _GLEE_ARB_color_buffer_float = GL_TRUE;
        __GLeeLink_GL_ARB_color_buffer_float();
    }
    if (__GLeeCheckExtension("GL_ARB_half_float_pixel", &extensionNames) )
    {
        _GLEE_ARB_half_float_pixel = GL_TRUE;
        __GLeeLink_GL_ARB_half_float_pixel();
    }
    if (__GLeeCheckExtension("GL_ARB_texture_float", &extensionNames) )
    {
        _GLEE_ARB_texture_float = GL_TRUE;
        __GLeeLink_GL_ARB_texture_float();
    }
    if (__GLeeCheckExtension("GL_ARB_pixel_buffer_object", &extensionNames) )
    {
        _GLEE_ARB_pixel_buffer_object = GL_TRUE;
        __GLeeLink_GL_ARB_pixel_buffer_object();
    }
    if (__GLeeCheckExtension("GL_EXT_abgr", &extensionNames) )
    {
        _GLEE_EXT_abgr = GL_TRUE;
        __GLeeLink_GL_EXT_abgr();
    }
    if (__GLeeCheckExtension("GL_EXT_blend_color", &extensionNames) )
    {
        _GLEE_EXT_blend_color = GL_TRUE;
        __GLeeLink_GL_EXT_blend_color();
    }
    if (__GLeeCheckExtension("GL_EXT_polygon_offset", &extensionNames) )
    {
        _GLEE_EXT_polygon_offset = GL_TRUE;
        __GLeeLink_GL_EXT_polygon_offset();
    }
    if (__GLeeCheckExtension("GL_EXT_texture", &extensionNames) )
    {
        _GLEE_EXT_texture = GL_TRUE;
        __GLeeLink_GL_EXT_texture();
    }
    if (__GLeeCheckExtension("GL_EXT_texture3D", &extensionNames) )
    {
        _GLEE_EXT_texture3D = GL_TRUE;
        __GLeeLink_GL_EXT_texture3D();
    }
    if (__GLeeCheckExtension("GL_SGIS_texture_filter4", &extensionNames) )
    {
        _GLEE_SGIS_texture_filter4 = GL_TRUE;
        __GLeeLink_GL_SGIS_texture_filter4();
    }
    if (__GLeeCheckExtension("GL_EXT_subtexture", &extensionNames) )
    {
        _GLEE_EXT_subtexture = GL_TRUE;
        __GLeeLink_GL_EXT_subtexture();
    }
    if (__GLeeCheckExtension("GL_EXT_copy_texture", &extensionNames) )
    {
        _GLEE_EXT_copy_texture = GL_TRUE;
        __GLeeLink_GL_EXT_copy_texture();
    }
    if (__GLeeCheckExtension("GL_EXT_histogram", &extensionNames) )
    {
        _GLEE_EXT_histogram = GL_TRUE;
        __GLeeLink_GL_EXT_histogram();
    }
    if (__GLeeCheckExtension("GL_EXT_convolution", &extensionNames) )
    {
        _GLEE_EXT_convolution = GL_TRUE;
        __GLeeLink_GL_EXT_convolution();
    }
    if (__GLeeCheckExtension("GL_SGI_color_matrix", &extensionNames) )
    {
        _GLEE_SGI_color_matrix = GL_TRUE;
        __GLeeLink_GL_SGI_color_matrix();
    }
    if (__GLeeCheckExtension("GL_SGI_color_table", &extensionNames) )
    {
        _GLEE_SGI_color_table = GL_TRUE;
        __GLeeLink_GL_SGI_color_table();
    }
    if (__GLeeCheckExtension("GL_SGIS_pixel_texture", &extensionNames) )
    {
        _GLEE_SGIS_pixel_texture = GL_TRUE;
        __GLeeLink_GL_SGIS_pixel_texture();
    }
    if (__GLeeCheckExtension("GL_SGIX_pixel_texture", &extensionNames) )
    {
        _GLEE_SGIX_pixel_texture = GL_TRUE;
        __GLeeLink_GL_SGIX_pixel_texture();
    }
    if (__GLeeCheckExtension("GL_SGIS_texture4D", &extensionNames) )
    {
        _GLEE_SGIS_texture4D = GL_TRUE;
        __GLeeLink_GL_SGIS_texture4D();
    }
    if (__GLeeCheckExtension("GL_SGI_texture_color_table", &extensionNames) )
    {
        _GLEE_SGI_texture_color_table = GL_TRUE;
        __GLeeLink_GL_SGI_texture_color_table();
    }
    if (__GLeeCheckExtension("GL_EXT_cmyka", &extensionNames) )
    {
        _GLEE_EXT_cmyka = GL_TRUE;
        __GLeeLink_GL_EXT_cmyka();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_object", &extensionNames) )
    {
        _GLEE_EXT_texture_object = GL_TRUE;
        __GLeeLink_GL_EXT_texture_object();
    }
    if (__GLeeCheckExtension("GL_SGIS_detail_texture", &extensionNames) )
    {
        _GLEE_SGIS_detail_texture = GL_TRUE;
        __GLeeLink_GL_SGIS_detail_texture();
    }
    if (__GLeeCheckExtension("GL_SGIS_sharpen_texture", &extensionNames) )
    {
        _GLEE_SGIS_sharpen_texture = GL_TRUE;
        __GLeeLink_GL_SGIS_sharpen_texture();
    }
    if (__GLeeCheckExtension("GL_EXT_packed_pixels", &extensionNames) )
    {
        _GLEE_EXT_packed_pixels = GL_TRUE;
        __GLeeLink_GL_EXT_packed_pixels();
    }
    if (__GLeeCheckExtension("GL_SGIS_texture_lod", &extensionNames) )
    {
        _GLEE_SGIS_texture_lod = GL_TRUE;
        __GLeeLink_GL_SGIS_texture_lod();
    }
    if (__GLeeCheckExtension("GL_SGIS_multisample", &extensionNames) )
    {
        _GLEE_SGIS_multisample = GL_TRUE;
        __GLeeLink_GL_SGIS_multisample();
    }
    if (__GLeeCheckExtension("GL_EXT_rescale_normal", &extensionNames) )
    {
        _GLEE_EXT_rescale_normal = GL_TRUE;
        __GLeeLink_GL_EXT_rescale_normal();
    }
    if (__GLeeCheckExtension("GL_EXT_vertex_array", &extensionNames) )
    {
        _GLEE_EXT_vertex_array = GL_TRUE;
        __GLeeLink_GL_EXT_vertex_array();
    }
    if (__GLeeCheckExtension("GL_EXT_misc_attribute", &extensionNames) )
    {
        _GLEE_EXT_misc_attribute = GL_TRUE;
        __GLeeLink_GL_EXT_misc_attribute();
    }
    if (__GLeeCheckExtension("GL_SGIS_generate_mipmap", &extensionNames) )
    {
        _GLEE_SGIS_generate_mipmap = GL_TRUE;
        __GLeeLink_GL_SGIS_generate_mipmap();
    }
    if (__GLeeCheckExtension("GL_SGIX_clipmap", &extensionNames) )
    {
        _GLEE_SGIX_clipmap = GL_TRUE;
        __GLeeLink_GL_SGIX_clipmap();
    }
    if (__GLeeCheckExtension("GL_SGIX_shadow", &extensionNames) )
    {
        _GLEE_SGIX_shadow = GL_TRUE;
        __GLeeLink_GL_SGIX_shadow();
    }
    if (__GLeeCheckExtension("GL_SGIS_texture_edge_clamp", &extensionNames) )
    {
        _GLEE_SGIS_texture_edge_clamp = GL_TRUE;
        __GLeeLink_GL_SGIS_texture_edge_clamp();
    }
    if (__GLeeCheckExtension("GL_SGIS_texture_border_clamp", &extensionNames) )
    {
        _GLEE_SGIS_texture_border_clamp = GL_TRUE;
        __GLeeLink_GL_SGIS_texture_border_clamp();
    }
    if (__GLeeCheckExtension("GL_EXT_blend_minmax", &extensionNames) )
    {
        _GLEE_EXT_blend_minmax = GL_TRUE;
        __GLeeLink_GL_EXT_blend_minmax();
    }
    if (__GLeeCheckExtension("GL_EXT_blend_subtract", &extensionNames) )
    {
        _GLEE_EXT_blend_subtract = GL_TRUE;
        __GLeeLink_GL_EXT_blend_subtract();
    }
    if (__GLeeCheckExtension("GL_EXT_blend_logic_op", &extensionNames) )
    {
        _GLEE_EXT_blend_logic_op = GL_TRUE;
        __GLeeLink_GL_EXT_blend_logic_op();
    }
    if (__GLeeCheckExtension("GL_SGIX_interlace", &extensionNames) )
    {
        _GLEE_SGIX_interlace = GL_TRUE;
        __GLeeLink_GL_SGIX_interlace();
    }
    if (__GLeeCheckExtension("GL_SGIX_pixel_tiles", &extensionNames) )
    {
        _GLEE_SGIX_pixel_tiles = GL_TRUE;
        __GLeeLink_GL_SGIX_pixel_tiles();
    }
    if (__GLeeCheckExtension("GL_SGIS_texture_select", &extensionNames) )
    {
        _GLEE_SGIS_texture_select = GL_TRUE;
        __GLeeLink_GL_SGIS_texture_select();
    }
    if (__GLeeCheckExtension("GL_SGIX_sprite", &extensionNames) )
    {
        _GLEE_SGIX_sprite = GL_TRUE;
        __GLeeLink_GL_SGIX_sprite();
    }
    if (__GLeeCheckExtension("GL_SGIX_texture_multi_buffer", &extensionNames) )
    {
        _GLEE_SGIX_texture_multi_buffer = GL_TRUE;
        __GLeeLink_GL_SGIX_texture_multi_buffer();
    }
    if (__GLeeCheckExtension("GL_EXT_point_parameters", &extensionNames) )
    {
        _GLEE_EXT_point_parameters = GL_TRUE;
        __GLeeLink_GL_EXT_point_parameters();
    }
    if (__GLeeCheckExtension("GL_SGIS_point_parameters", &extensionNames) )
    {
        _GLEE_SGIS_point_parameters = GL_TRUE;
        __GLeeLink_GL_SGIS_point_parameters();
    }
    if (__GLeeCheckExtension("GL_SGIX_instruments", &extensionNames) )
    {
        _GLEE_SGIX_instruments = GL_TRUE;
        __GLeeLink_GL_SGIX_instruments();
    }
    if (__GLeeCheckExtension("GL_SGIX_texture_scale_bias", &extensionNames) )
    {
        _GLEE_SGIX_texture_scale_bias = GL_TRUE;
        __GLeeLink_GL_SGIX_texture_scale_bias();
    }
    if (__GLeeCheckExtension("GL_SGIX_framezoom", &extensionNames) )
    {
        _GLEE_SGIX_framezoom = GL_TRUE;
        __GLeeLink_GL_SGIX_framezoom();
    }
    if (__GLeeCheckExtension("GL_SGIX_tag_sample_buffer", &extensionNames) )
    {
        _GLEE_SGIX_tag_sample_buffer = GL_TRUE;
        __GLeeLink_GL_SGIX_tag_sample_buffer();
    }
    if (__GLeeCheckExtension("GL_FfdMaskSGIX", &extensionNames) )
    {
        _GLEE_FfdMaskSGIX = GL_TRUE;
        __GLeeLink_GL_FfdMaskSGIX();
    }
    if (__GLeeCheckExtension("GL_SGIX_polynomial_ffd", &extensionNames) )
    {
        _GLEE_SGIX_polynomial_ffd = GL_TRUE;
        __GLeeLink_GL_SGIX_polynomial_ffd();
    }
    if (__GLeeCheckExtension("GL_SGIX_reference_plane", &extensionNames) )
    {
        _GLEE_SGIX_reference_plane = GL_TRUE;
        __GLeeLink_GL_SGIX_reference_plane();
    }
    if (__GLeeCheckExtension("GL_SGIX_flush_raster", &extensionNames) )
    {
        _GLEE_SGIX_flush_raster = GL_TRUE;
        __GLeeLink_GL_SGIX_flush_raster();
    }
    if (__GLeeCheckExtension("GL_SGIX_depth_texture", &extensionNames) )
    {
        _GLEE_SGIX_depth_texture = GL_TRUE;
        __GLeeLink_GL_SGIX_depth_texture();
    }
    if (__GLeeCheckExtension("GL_SGIS_fog_function", &extensionNames) )
    {
        _GLEE_SGIS_fog_function = GL_TRUE;
        __GLeeLink_GL_SGIS_fog_function();
    }
    if (__GLeeCheckExtension("GL_SGIX_fog_offset", &extensionNames) )
    {
        _GLEE_SGIX_fog_offset = GL_TRUE;
        __GLeeLink_GL_SGIX_fog_offset();
    }
    if (__GLeeCheckExtension("GL_HP_image_transform", &extensionNames) )
    {
        _GLEE_HP_image_transform = GL_TRUE;
        __GLeeLink_GL_HP_image_transform();
    }
    if (__GLeeCheckExtension("GL_HP_convolution_border_modes", &extensionNames) )
    {
        _GLEE_HP_convolution_border_modes = GL_TRUE;
        __GLeeLink_GL_HP_convolution_border_modes();
    }
    if (__GLeeCheckExtension("GL_INGR_palette_buffer", &extensionNames) )
    {
        _GLEE_INGR_palette_buffer = GL_TRUE;
        __GLeeLink_GL_INGR_palette_buffer();
    }
    if (__GLeeCheckExtension("GL_SGIX_texture_add_env", &extensionNames) )
    {
        _GLEE_SGIX_texture_add_env = GL_TRUE;
        __GLeeLink_GL_SGIX_texture_add_env();
    }
    if (__GLeeCheckExtension("GL_EXT_color_subtable", &extensionNames) )
    {
        _GLEE_EXT_color_subtable = GL_TRUE;
        __GLeeLink_GL_EXT_color_subtable();
    }
    if (__GLeeCheckExtension("GL_PGI_vertex_hints", &extensionNames) )
    {
        _GLEE_PGI_vertex_hints = GL_TRUE;
        __GLeeLink_GL_PGI_vertex_hints();
    }
    if (__GLeeCheckExtension("GL_PGI_misc_hints", &extensionNames) )
    {
        _GLEE_PGI_misc_hints = GL_TRUE;
        __GLeeLink_GL_PGI_misc_hints();
    }
    if (__GLeeCheckExtension("GL_EXT_paletted_texture", &extensionNames) )
    {
        _GLEE_EXT_paletted_texture = GL_TRUE;
        __GLeeLink_GL_EXT_paletted_texture();
    }
    if (__GLeeCheckExtension("GL_EXT_clip_volume_hint", &extensionNames) )
    {
        _GLEE_EXT_clip_volume_hint = GL_TRUE;
        __GLeeLink_GL_EXT_clip_volume_hint();
    }
    if (__GLeeCheckExtension("GL_SGIX_list_priority", &extensionNames) )
    {
        _GLEE_SGIX_list_priority = GL_TRUE;
        __GLeeLink_GL_SGIX_list_priority();
    }
    if (__GLeeCheckExtension("GL_SGIX_ir_instrument1", &extensionNames) )
    {
        _GLEE_SGIX_ir_instrument1 = GL_TRUE;
        __GLeeLink_GL_SGIX_ir_instrument1();
    }
    if (__GLeeCheckExtension("GL_SGIX_calligraphic_fragment", &extensionNames) )
    {
        _GLEE_SGIX_calligraphic_fragment = GL_TRUE;
        __GLeeLink_GL_SGIX_calligraphic_fragment();
    }
    if (__GLeeCheckExtension("GL_SGIX_texture_lod_bias", &extensionNames) )
    {
        _GLEE_SGIX_texture_lod_bias = GL_TRUE;
        __GLeeLink_GL_SGIX_texture_lod_bias();
    }
    if (__GLeeCheckExtension("GL_SGIX_shadow_ambient", &extensionNames) )
    {
        _GLEE_SGIX_shadow_ambient = GL_TRUE;
        __GLeeLink_GL_SGIX_shadow_ambient();
    }
    if (__GLeeCheckExtension("GL_EXT_index_texture", &extensionNames) )
    {
        _GLEE_EXT_index_texture = GL_TRUE;
        __GLeeLink_GL_EXT_index_texture();
    }
    if (__GLeeCheckExtension("GL_EXT_index_material", &extensionNames) )
    {
        _GLEE_EXT_index_material = GL_TRUE;
        __GLeeLink_GL_EXT_index_material();
    }
    if (__GLeeCheckExtension("GL_EXT_index_func", &extensionNames) )
    {
        _GLEE_EXT_index_func = GL_TRUE;
        __GLeeLink_GL_EXT_index_func();
    }
    if (__GLeeCheckExtension("GL_EXT_index_array_formats", &extensionNames) )
    {
        _GLEE_EXT_index_array_formats = GL_TRUE;
        __GLeeLink_GL_EXT_index_array_formats();
    }
    if (__GLeeCheckExtension("GL_EXT_compiled_vertex_array", &extensionNames) )
    {
        _GLEE_EXT_compiled_vertex_array = GL_TRUE;
        __GLeeLink_GL_EXT_compiled_vertex_array();
    }
    if (__GLeeCheckExtension("GL_EXT_cull_vertex", &extensionNames) )
    {
        _GLEE_EXT_cull_vertex = GL_TRUE;
        __GLeeLink_GL_EXT_cull_vertex();
    }
    if (__GLeeCheckExtension("GL_SGIX_ycrcb", &extensionNames) )
    {
        _GLEE_SGIX_ycrcb = GL_TRUE;
        __GLeeLink_GL_SGIX_ycrcb();
    }
    if (__GLeeCheckExtension("GL_SGIX_fragment_lighting", &extensionNames) )
    {
        _GLEE_SGIX_fragment_lighting = GL_TRUE;
        __GLeeLink_GL_SGIX_fragment_lighting();
    }
    if (__GLeeCheckExtension("GL_IBM_rasterpos_clip", &extensionNames) )
    {
        _GLEE_IBM_rasterpos_clip = GL_TRUE;
        __GLeeLink_GL_IBM_rasterpos_clip();
    }
    if (__GLeeCheckExtension("GL_HP_texture_lighting", &extensionNames) )
    {
        _GLEE_HP_texture_lighting = GL_TRUE;
        __GLeeLink_GL_HP_texture_lighting();
    }
    if (__GLeeCheckExtension("GL_EXT_draw_range_elements", &extensionNames) )
    {
        _GLEE_EXT_draw_range_elements = GL_TRUE;
        __GLeeLink_GL_EXT_draw_range_elements();
    }
    if (__GLeeCheckExtension("GL_WIN_phong_shading", &extensionNames) )
    {
        _GLEE_WIN_phong_shading = GL_TRUE;
        __GLeeLink_GL_WIN_phong_shading();
    }
    if (__GLeeCheckExtension("GL_WIN_specular_fog", &extensionNames) )
    {
        _GLEE_WIN_specular_fog = GL_TRUE;
        __GLeeLink_GL_WIN_specular_fog();
    }
    if (__GLeeCheckExtension("GL_EXT_light_texture", &extensionNames) )
    {
        _GLEE_EXT_light_texture = GL_TRUE;
        __GLeeLink_GL_EXT_light_texture();
    }
    if (__GLeeCheckExtension("GL_SGIX_blend_alpha_minmax", &extensionNames) )
    {
        _GLEE_SGIX_blend_alpha_minmax = GL_TRUE;
        __GLeeLink_GL_SGIX_blend_alpha_minmax();
    }
    if (__GLeeCheckExtension("GL_SGIX_impact_pixel_texture", &extensionNames) )
    {
        _GLEE_SGIX_impact_pixel_texture = GL_TRUE;
        __GLeeLink_GL_SGIX_impact_pixel_texture();
    }
    if (__GLeeCheckExtension("GL_EXT_bgra", &extensionNames) )
    {
        _GLEE_EXT_bgra = GL_TRUE;
        __GLeeLink_GL_EXT_bgra();
    }
    if (__GLeeCheckExtension("GL_SGIX_async", &extensionNames) )
    {
        _GLEE_SGIX_async = GL_TRUE;
        __GLeeLink_GL_SGIX_async();
    }
    if (__GLeeCheckExtension("GL_SGIX_async_pixel", &extensionNames) )
    {
        _GLEE_SGIX_async_pixel = GL_TRUE;
        __GLeeLink_GL_SGIX_async_pixel();
    }
    if (__GLeeCheckExtension("GL_SGIX_async_histogram", &extensionNames) )
    {
        _GLEE_SGIX_async_histogram = GL_TRUE;
        __GLeeLink_GL_SGIX_async_histogram();
    }
    if (__GLeeCheckExtension("GL_INTEL_texture_scissor", &extensionNames) )
    {
        _GLEE_INTEL_texture_scissor = GL_TRUE;
        __GLeeLink_GL_INTEL_texture_scissor();
    }
    if (__GLeeCheckExtension("GL_INTEL_parallel_arrays", &extensionNames) )
    {
        _GLEE_INTEL_parallel_arrays = GL_TRUE;
        __GLeeLink_GL_INTEL_parallel_arrays();
    }
    if (__GLeeCheckExtension("GL_HP_occlusion_test", &extensionNames) )
    {
        _GLEE_HP_occlusion_test = GL_TRUE;
        __GLeeLink_GL_HP_occlusion_test();
    }
    if (__GLeeCheckExtension("GL_EXT_pixel_transform", &extensionNames) )
    {
        _GLEE_EXT_pixel_transform = GL_TRUE;
        __GLeeLink_GL_EXT_pixel_transform();
    }
    if (__GLeeCheckExtension("GL_EXT_pixel_transform_color_table", &extensionNames) )
    {
        _GLEE_EXT_pixel_transform_color_table = GL_TRUE;
        __GLeeLink_GL_EXT_pixel_transform_color_table();
    }
    if (__GLeeCheckExtension("GL_EXT_shared_texture_palette", &extensionNames) )
    {
        _GLEE_EXT_shared_texture_palette = GL_TRUE;
        __GLeeLink_GL_EXT_shared_texture_palette();
    }
    if (__GLeeCheckExtension("GL_EXT_separate_specular_color", &extensionNames) )
    {
        _GLEE_EXT_separate_specular_color = GL_TRUE;
        __GLeeLink_GL_EXT_separate_specular_color();
    }
    if (__GLeeCheckExtension("GL_EXT_secondary_color", &extensionNames) )
    {
        _GLEE_EXT_secondary_color = GL_TRUE;
        __GLeeLink_GL_EXT_secondary_color();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_perturb_normal", &extensionNames) )
    {
        _GLEE_EXT_texture_perturb_normal = GL_TRUE;
        __GLeeLink_GL_EXT_texture_perturb_normal();
    }
    if (__GLeeCheckExtension("GL_EXT_multi_draw_arrays", &extensionNames) )
    {
        _GLEE_EXT_multi_draw_arrays = GL_TRUE;
        __GLeeLink_GL_EXT_multi_draw_arrays();
    }
    if (__GLeeCheckExtension("GL_EXT_fog_coord", &extensionNames) )
    {
        _GLEE_EXT_fog_coord = GL_TRUE;
        __GLeeLink_GL_EXT_fog_coord();
    }
    if (__GLeeCheckExtension("GL_REND_screen_coordinates", &extensionNames) )
    {
        _GLEE_REND_screen_coordinates = GL_TRUE;
        __GLeeLink_GL_REND_screen_coordinates();
    }
    if (__GLeeCheckExtension("GL_EXT_coordinate_frame", &extensionNames) )
    {
        _GLEE_EXT_coordinate_frame = GL_TRUE;
        __GLeeLink_GL_EXT_coordinate_frame();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_env_combine", &extensionNames) )
    {
        _GLEE_EXT_texture_env_combine = GL_TRUE;
        __GLeeLink_GL_EXT_texture_env_combine();
    }
    if (__GLeeCheckExtension("GL_APPLE_specular_vector", &extensionNames) )
    {
        _GLEE_APPLE_specular_vector = GL_TRUE;
        __GLeeLink_GL_APPLE_specular_vector();
    }
    if (__GLeeCheckExtension("GL_APPLE_transform_hint", &extensionNames) )
    {
        _GLEE_APPLE_transform_hint = GL_TRUE;
        __GLeeLink_GL_APPLE_transform_hint();
    }
    if (__GLeeCheckExtension("GL_SGIX_fog_scale", &extensionNames) )
    {
        _GLEE_SGIX_fog_scale = GL_TRUE;
        __GLeeLink_GL_SGIX_fog_scale();
    }
    if (__GLeeCheckExtension("GL_SUNX_constant_data", &extensionNames) )
    {
        _GLEE_SUNX_constant_data = GL_TRUE;
        __GLeeLink_GL_SUNX_constant_data();
    }
    if (__GLeeCheckExtension("GL_SUN_global_alpha", &extensionNames) )
    {
        _GLEE_SUN_global_alpha = GL_TRUE;
        __GLeeLink_GL_SUN_global_alpha();
    }
    if (__GLeeCheckExtension("GL_SUN_triangle_list", &extensionNames) )
    {
        _GLEE_SUN_triangle_list = GL_TRUE;
        __GLeeLink_GL_SUN_triangle_list();
    }
    if (__GLeeCheckExtension("GL_SUN_vertex", &extensionNames) )
    {
        _GLEE_SUN_vertex = GL_TRUE;
        __GLeeLink_GL_SUN_vertex();
    }
    if (__GLeeCheckExtension("GL_EXT_blend_func_separate", &extensionNames) )
    {
        _GLEE_EXT_blend_func_separate = GL_TRUE;
        __GLeeLink_GL_EXT_blend_func_separate();
    }
    if (__GLeeCheckExtension("GL_INGR_color_clamp", &extensionNames) )
    {
        _GLEE_INGR_color_clamp = GL_TRUE;
        __GLeeLink_GL_INGR_color_clamp();
    }
    if (__GLeeCheckExtension("GL_INGR_interlace_read", &extensionNames) )
    {
        _GLEE_INGR_interlace_read = GL_TRUE;
        __GLeeLink_GL_INGR_interlace_read();
    }
    if (__GLeeCheckExtension("GL_EXT_stencil_wrap", &extensionNames) )
    {
        _GLEE_EXT_stencil_wrap = GL_TRUE;
        __GLeeLink_GL_EXT_stencil_wrap();
    }
    if (__GLeeCheckExtension("GL_EXT_422_pixels", &extensionNames) )
    {
        _GLEE_EXT_422_pixels = GL_TRUE;
        __GLeeLink_GL_EXT_422_pixels();
    }
    if (__GLeeCheckExtension("GL_NV_texgen_reflection", &extensionNames) )
    {
        _GLEE_NV_texgen_reflection = GL_TRUE;
        __GLeeLink_GL_NV_texgen_reflection();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_cube_map", &extensionNames) )
    {
        _GLEE_EXT_texture_cube_map = GL_TRUE;
        __GLeeLink_GL_EXT_texture_cube_map();
    }
    if (__GLeeCheckExtension("GL_SUN_convolution_border_modes", &extensionNames) )
    {
        _GLEE_SUN_convolution_border_modes = GL_TRUE;
        __GLeeLink_GL_SUN_convolution_border_modes();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_env_add", &extensionNames) )
    {
        _GLEE_EXT_texture_env_add = GL_TRUE;
        __GLeeLink_GL_EXT_texture_env_add();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_lod_bias", &extensionNames) )
    {
        _GLEE_EXT_texture_lod_bias = GL_TRUE;
        __GLeeLink_GL_EXT_texture_lod_bias();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_filter_anisotropic", &extensionNames) )
    {
        _GLEE_EXT_texture_filter_anisotropic = GL_TRUE;
        __GLeeLink_GL_EXT_texture_filter_anisotropic();
    }
    if (__GLeeCheckExtension("GL_EXT_vertex_weighting", &extensionNames) )
    {
        _GLEE_EXT_vertex_weighting = GL_TRUE;
        __GLeeLink_GL_EXT_vertex_weighting();
    }
    if (__GLeeCheckExtension("GL_NV_light_max_exponent", &extensionNames) )
    {
        _GLEE_NV_light_max_exponent = GL_TRUE;
        __GLeeLink_GL_NV_light_max_exponent();
    }
    if (__GLeeCheckExtension("GL_NV_vertex_array_range", &extensionNames) )
    {
        _GLEE_NV_vertex_array_range = GL_TRUE;
        __GLeeLink_GL_NV_vertex_array_range();
    }
    if (__GLeeCheckExtension("GL_NV_register_combiners", &extensionNames) )
    {
        _GLEE_NV_register_combiners = GL_TRUE;
        __GLeeLink_GL_NV_register_combiners();
    }
    if (__GLeeCheckExtension("GL_NV_fog_distance", &extensionNames) )
    {
        _GLEE_NV_fog_distance = GL_TRUE;
        __GLeeLink_GL_NV_fog_distance();
    }
    if (__GLeeCheckExtension("GL_NV_texgen_emboss", &extensionNames) )
    {
        _GLEE_NV_texgen_emboss = GL_TRUE;
        __GLeeLink_GL_NV_texgen_emboss();
    }
    if (__GLeeCheckExtension("GL_NV_blend_square", &extensionNames) )
    {
        _GLEE_NV_blend_square = GL_TRUE;
        __GLeeLink_GL_NV_blend_square();
    }
    if (__GLeeCheckExtension("GL_NV_texture_env_combine4", &extensionNames) )
    {
        _GLEE_NV_texture_env_combine4 = GL_TRUE;
        __GLeeLink_GL_NV_texture_env_combine4();
    }
    if (__GLeeCheckExtension("GL_MESA_resize_buffers", &extensionNames) )
    {
        _GLEE_MESA_resize_buffers = GL_TRUE;
        __GLeeLink_GL_MESA_resize_buffers();
    }
    if (__GLeeCheckExtension("GL_MESA_window_pos", &extensionNames) )
    {
        _GLEE_MESA_window_pos = GL_TRUE;
        __GLeeLink_GL_MESA_window_pos();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_compression_s3tc", &extensionNames) )
    {
        _GLEE_EXT_texture_compression_s3tc = GL_TRUE;
        __GLeeLink_GL_EXT_texture_compression_s3tc();
    }
    if (__GLeeCheckExtension("GL_IBM_cull_vertex", &extensionNames) )
    {
        _GLEE_IBM_cull_vertex = GL_TRUE;
        __GLeeLink_GL_IBM_cull_vertex();
    }
    if (__GLeeCheckExtension("GL_IBM_multimode_draw_arrays", &extensionNames) )
    {
        _GLEE_IBM_multimode_draw_arrays = GL_TRUE;
        __GLeeLink_GL_IBM_multimode_draw_arrays();
    }
    if (__GLeeCheckExtension("GL_IBM_vertex_array_lists", &extensionNames) )
    {
        _GLEE_IBM_vertex_array_lists = GL_TRUE;
        __GLeeLink_GL_IBM_vertex_array_lists();
    }
    if (__GLeeCheckExtension("GL_SGIX_subsample", &extensionNames) )
    {
        _GLEE_SGIX_subsample = GL_TRUE;
        __GLeeLink_GL_SGIX_subsample();
    }
    if (__GLeeCheckExtension("GL_SGIX_ycrcb_subsample", &extensionNames) )
    {
        _GLEE_SGIX_ycrcb_subsample = GL_TRUE;
        __GLeeLink_GL_SGIX_ycrcb_subsample();
    }
    if (__GLeeCheckExtension("GL_SGIX_ycrcba", &extensionNames) )
    {
        _GLEE_SGIX_ycrcba = GL_TRUE;
        __GLeeLink_GL_SGIX_ycrcba();
    }
    if (__GLeeCheckExtension("GL_SGI_depth_pass_instrument", &extensionNames) )
    {
        _GLEE_SGI_depth_pass_instrument = GL_TRUE;
        __GLeeLink_GL_SGI_depth_pass_instrument();
    }
    if (__GLeeCheckExtension("GL_3DFX_texture_compression_FXT1", &extensionNames) )
    {
        _GLEE_3DFX_texture_compression_FXT1 = GL_TRUE;
        __GLeeLink_GL_3DFX_texture_compression_FXT1();
    }
    if (__GLeeCheckExtension("GL_3DFX_multisample", &extensionNames) )
    {
        _GLEE_3DFX_multisample = GL_TRUE;
        __GLeeLink_GL_3DFX_multisample();
    }
    if (__GLeeCheckExtension("GL_3DFX_tbuffer", &extensionNames) )
    {
        _GLEE_3DFX_tbuffer = GL_TRUE;
        __GLeeLink_GL_3DFX_tbuffer();
    }
    if (__GLeeCheckExtension("GL_EXT_multisample", &extensionNames) )
    {
        _GLEE_EXT_multisample = GL_TRUE;
        __GLeeLink_GL_EXT_multisample();
    }
    if (__GLeeCheckExtension("GL_SGIX_vertex_preclip", &extensionNames) )
    {
        _GLEE_SGIX_vertex_preclip = GL_TRUE;
        __GLeeLink_GL_SGIX_vertex_preclip();
    }
    if (__GLeeCheckExtension("GL_SGIX_convolution_accuracy", &extensionNames) )
    {
        _GLEE_SGIX_convolution_accuracy = GL_TRUE;
        __GLeeLink_GL_SGIX_convolution_accuracy();
    }
    if (__GLeeCheckExtension("GL_SGIX_resample", &extensionNames) )
    {
        _GLEE_SGIX_resample = GL_TRUE;
        __GLeeLink_GL_SGIX_resample();
    }
    if (__GLeeCheckExtension("GL_SGIS_point_line_texgen", &extensionNames) )
    {
        _GLEE_SGIS_point_line_texgen = GL_TRUE;
        __GLeeLink_GL_SGIS_point_line_texgen();
    }
    if (__GLeeCheckExtension("GL_SGIS_texture_color_mask", &extensionNames) )
    {
        _GLEE_SGIS_texture_color_mask = GL_TRUE;
        __GLeeLink_GL_SGIS_texture_color_mask();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_env_dot3", &extensionNames) )
    {
        _GLEE_EXT_texture_env_dot3 = GL_TRUE;
        __GLeeLink_GL_EXT_texture_env_dot3();
    }
    if (__GLeeCheckExtension("GL_ATI_texture_mirror_once", &extensionNames) )
    {
        _GLEE_ATI_texture_mirror_once = GL_TRUE;
        __GLeeLink_GL_ATI_texture_mirror_once();
    }
    if (__GLeeCheckExtension("GL_NV_fence", &extensionNames) )
    {
        _GLEE_NV_fence = GL_TRUE;
        __GLeeLink_GL_NV_fence();
    }
    if (__GLeeCheckExtension("GL_IBM_texture_mirrored_repeat", &extensionNames) )
    {
        _GLEE_IBM_texture_mirrored_repeat = GL_TRUE;
        __GLeeLink_GL_IBM_texture_mirrored_repeat();
    }
    if (__GLeeCheckExtension("GL_NV_evaluators", &extensionNames) )
    {
        _GLEE_NV_evaluators = GL_TRUE;
        __GLeeLink_GL_NV_evaluators();
    }
    if (__GLeeCheckExtension("GL_NV_packed_depth_stencil", &extensionNames) )
    {
        _GLEE_NV_packed_depth_stencil = GL_TRUE;
        __GLeeLink_GL_NV_packed_depth_stencil();
    }
    if (__GLeeCheckExtension("GL_NV_register_combiners2", &extensionNames) )
    {
        _GLEE_NV_register_combiners2 = GL_TRUE;
        __GLeeLink_GL_NV_register_combiners2();
    }
    if (__GLeeCheckExtension("GL_NV_texture_compression_vtc", &extensionNames) )
    {
        _GLEE_NV_texture_compression_vtc = GL_TRUE;
        __GLeeLink_GL_NV_texture_compression_vtc();
    }
    if (__GLeeCheckExtension("GL_NV_texture_rectangle", &extensionNames) )
    {
        _GLEE_NV_texture_rectangle = GL_TRUE;
        __GLeeLink_GL_NV_texture_rectangle();
    }
    if (__GLeeCheckExtension("GL_NV_texture_shader", &extensionNames) )
    {
        _GLEE_NV_texture_shader = GL_TRUE;
        __GLeeLink_GL_NV_texture_shader();
    }
    if (__GLeeCheckExtension("GL_NV_texture_shader2", &extensionNames) )
    {
        _GLEE_NV_texture_shader2 = GL_TRUE;
        __GLeeLink_GL_NV_texture_shader2();
    }
    if (__GLeeCheckExtension("GL_NV_vertex_array_range2", &extensionNames) )
    {
        _GLEE_NV_vertex_array_range2 = GL_TRUE;
        __GLeeLink_GL_NV_vertex_array_range2();
    }
    if (__GLeeCheckExtension("GL_NV_vertex_program", &extensionNames) )
    {
        _GLEE_NV_vertex_program = GL_TRUE;
        __GLeeLink_GL_NV_vertex_program();
    }
    if (__GLeeCheckExtension("GL_SGIX_texture_coordinate_clamp", &extensionNames) )
    {
        _GLEE_SGIX_texture_coordinate_clamp = GL_TRUE;
        __GLeeLink_GL_SGIX_texture_coordinate_clamp();
    }
    if (__GLeeCheckExtension("GL_SGIX_scalebias_hint", &extensionNames) )
    {
        _GLEE_SGIX_scalebias_hint = GL_TRUE;
        __GLeeLink_GL_SGIX_scalebias_hint();
    }
    if (__GLeeCheckExtension("GL_OML_interlace", &extensionNames) )
    {
        _GLEE_OML_interlace = GL_TRUE;
        __GLeeLink_GL_OML_interlace();
    }
    if (__GLeeCheckExtension("GL_OML_subsample", &extensionNames) )
    {
        _GLEE_OML_subsample = GL_TRUE;
        __GLeeLink_GL_OML_subsample();
    }
    if (__GLeeCheckExtension("GL_OML_resample", &extensionNames) )
    {
        _GLEE_OML_resample = GL_TRUE;
        __GLeeLink_GL_OML_resample();
    }
    if (__GLeeCheckExtension("GL_NV_copy_depth_to_color", &extensionNames) )
    {
        _GLEE_NV_copy_depth_to_color = GL_TRUE;
        __GLeeLink_GL_NV_copy_depth_to_color();
    }
    if (__GLeeCheckExtension("GL_ATI_envmap_bumpmap", &extensionNames) )
    {
        _GLEE_ATI_envmap_bumpmap = GL_TRUE;
        __GLeeLink_GL_ATI_envmap_bumpmap();
    }
    if (__GLeeCheckExtension("GL_ATI_fragment_shader", &extensionNames) )
    {
        _GLEE_ATI_fragment_shader = GL_TRUE;
        __GLeeLink_GL_ATI_fragment_shader();
    }
    if (__GLeeCheckExtension("GL_ATI_pn_triangles", &extensionNames) )
    {
        _GLEE_ATI_pn_triangles = GL_TRUE;
        __GLeeLink_GL_ATI_pn_triangles();
    }
    if (__GLeeCheckExtension("GL_ATI_vertex_array_object", &extensionNames) )
    {
        _GLEE_ATI_vertex_array_object = GL_TRUE;
        __GLeeLink_GL_ATI_vertex_array_object();
    }
    if (__GLeeCheckExtension("GL_EXT_vertex_shader", &extensionNames) )
    {
        _GLEE_EXT_vertex_shader = GL_TRUE;
        __GLeeLink_GL_EXT_vertex_shader();
    }
    if (__GLeeCheckExtension("GL_ATI_vertex_streams", &extensionNames) )
    {
        _GLEE_ATI_vertex_streams = GL_TRUE;
        __GLeeLink_GL_ATI_vertex_streams();
    }
    if (__GLeeCheckExtension("GL_ATI_element_array", &extensionNames) )
    {
        _GLEE_ATI_element_array = GL_TRUE;
        __GLeeLink_GL_ATI_element_array();
    }
    if (__GLeeCheckExtension("GL_SUN_mesh_array", &extensionNames) )
    {
        _GLEE_SUN_mesh_array = GL_TRUE;
        __GLeeLink_GL_SUN_mesh_array();
    }
    if (__GLeeCheckExtension("GL_SUN_slice_accum", &extensionNames) )
    {
        _GLEE_SUN_slice_accum = GL_TRUE;
        __GLeeLink_GL_SUN_slice_accum();
    }
    if (__GLeeCheckExtension("GL_NV_multisample_filter_hint", &extensionNames) )
    {
        _GLEE_NV_multisample_filter_hint = GL_TRUE;
        __GLeeLink_GL_NV_multisample_filter_hint();
    }
    if (__GLeeCheckExtension("GL_NV_depth_clamp", &extensionNames) )
    {
        _GLEE_NV_depth_clamp = GL_TRUE;
        __GLeeLink_GL_NV_depth_clamp();
    }
    if (__GLeeCheckExtension("GL_NV_occlusion_query", &extensionNames) )
    {
        _GLEE_NV_occlusion_query = GL_TRUE;
        __GLeeLink_GL_NV_occlusion_query();
    }
    if (__GLeeCheckExtension("GL_NV_point_sprite", &extensionNames) )
    {
        _GLEE_NV_point_sprite = GL_TRUE;
        __GLeeLink_GL_NV_point_sprite();
    }
    if (__GLeeCheckExtension("GL_NV_texture_shader3", &extensionNames) )
    {
        _GLEE_NV_texture_shader3 = GL_TRUE;
        __GLeeLink_GL_NV_texture_shader3();
    }
    if (__GLeeCheckExtension("GL_NV_vertex_program1_1", &extensionNames) )
    {
        _GLEE_NV_vertex_program1_1 = GL_TRUE;
        __GLeeLink_GL_NV_vertex_program1_1();
    }
    if (__GLeeCheckExtension("GL_EXT_shadow_funcs", &extensionNames) )
    {
        _GLEE_EXT_shadow_funcs = GL_TRUE;
        __GLeeLink_GL_EXT_shadow_funcs();
    }
    if (__GLeeCheckExtension("GL_EXT_stencil_two_side", &extensionNames) )
    {
        _GLEE_EXT_stencil_two_side = GL_TRUE;
        __GLeeLink_GL_EXT_stencil_two_side();
    }
    if (__GLeeCheckExtension("GL_ATI_text_fragment_shader", &extensionNames) )
    {
        _GLEE_ATI_text_fragment_shader = GL_TRUE;
        __GLeeLink_GL_ATI_text_fragment_shader();
    }
    if (__GLeeCheckExtension("GL_APPLE_client_storage", &extensionNames) )
    {
        _GLEE_APPLE_client_storage = GL_TRUE;
        __GLeeLink_GL_APPLE_client_storage();
    }
    if (__GLeeCheckExtension("GL_APPLE_element_array", &extensionNames) )
    {
        _GLEE_APPLE_element_array = GL_TRUE;
        __GLeeLink_GL_APPLE_element_array();
    }
    if (__GLeeCheckExtension("GL_APPLE_fence", &extensionNames) )
    {
        _GLEE_APPLE_fence = GL_TRUE;
        __GLeeLink_GL_APPLE_fence();
    }
    if (__GLeeCheckExtension("GL_APPLE_vertex_array_object", &extensionNames) )
    {
        _GLEE_APPLE_vertex_array_object = GL_TRUE;
        __GLeeLink_GL_APPLE_vertex_array_object();
    }
    if (__GLeeCheckExtension("GL_APPLE_vertex_array_range", &extensionNames) )
    {
        _GLEE_APPLE_vertex_array_range = GL_TRUE;
        __GLeeLink_GL_APPLE_vertex_array_range();
    }
    if (__GLeeCheckExtension("GL_APPLE_ycbcr_422", &extensionNames) )
    {
        _GLEE_APPLE_ycbcr_422 = GL_TRUE;
        __GLeeLink_GL_APPLE_ycbcr_422();
    }
    if (__GLeeCheckExtension("GL_S3_s3tc", &extensionNames) )
    {
        _GLEE_S3_s3tc = GL_TRUE;
        __GLeeLink_GL_S3_s3tc();
    }
    if (__GLeeCheckExtension("GL_ATI_draw_buffers", &extensionNames) )
    {
        _GLEE_ATI_draw_buffers = GL_TRUE;
        __GLeeLink_GL_ATI_draw_buffers();
    }
    if (__GLeeCheckExtension("GL_ATI_pixel_format_float", &extensionNames) )
    {
        _GLEE_ATI_pixel_format_float = GL_TRUE;
        __GLeeLink_GL_ATI_pixel_format_float();
    }
    if (__GLeeCheckExtension("GL_ATI_texture_env_combine3", &extensionNames) )
    {
        _GLEE_ATI_texture_env_combine3 = GL_TRUE;
        __GLeeLink_GL_ATI_texture_env_combine3();
    }
    if (__GLeeCheckExtension("GL_ATI_texture_float", &extensionNames) )
    {
        _GLEE_ATI_texture_float = GL_TRUE;
        __GLeeLink_GL_ATI_texture_float();
    }
    if (__GLeeCheckExtension("GL_NV_float_buffer", &extensionNames) )
    {
        _GLEE_NV_float_buffer = GL_TRUE;
        __GLeeLink_GL_NV_float_buffer();
    }
    if (__GLeeCheckExtension("GL_NV_fragment_program", &extensionNames) )
    {
        _GLEE_NV_fragment_program = GL_TRUE;
        __GLeeLink_GL_NV_fragment_program();
    }
    if (__GLeeCheckExtension("GL_NV_half_float", &extensionNames) )
    {
        _GLEE_NV_half_float = GL_TRUE;
        __GLeeLink_GL_NV_half_float();
    }
    if (__GLeeCheckExtension("GL_NV_pixel_data_range", &extensionNames) )
    {
        _GLEE_NV_pixel_data_range = GL_TRUE;
        __GLeeLink_GL_NV_pixel_data_range();
    }
    if (__GLeeCheckExtension("GL_NV_primitive_restart", &extensionNames) )
    {
        _GLEE_NV_primitive_restart = GL_TRUE;
        __GLeeLink_GL_NV_primitive_restart();
    }
    if (__GLeeCheckExtension("GL_NV_texture_expand_normal", &extensionNames) )
    {
        _GLEE_NV_texture_expand_normal = GL_TRUE;
        __GLeeLink_GL_NV_texture_expand_normal();
    }
    if (__GLeeCheckExtension("GL_NV_vertex_program2", &extensionNames) )
    {
        _GLEE_NV_vertex_program2 = GL_TRUE;
        __GLeeLink_GL_NV_vertex_program2();
    }
    if (__GLeeCheckExtension("GL_ATI_map_object_buffer", &extensionNames) )
    {
        _GLEE_ATI_map_object_buffer = GL_TRUE;
        __GLeeLink_GL_ATI_map_object_buffer();
    }
    if (__GLeeCheckExtension("GL_ATI_separate_stencil", &extensionNames) )
    {
        _GLEE_ATI_separate_stencil = GL_TRUE;
        __GLeeLink_GL_ATI_separate_stencil();
    }
    if (__GLeeCheckExtension("GL_ATI_vertex_attrib_array_object", &extensionNames) )
    {
        _GLEE_ATI_vertex_attrib_array_object = GL_TRUE;
        __GLeeLink_GL_ATI_vertex_attrib_array_object();
    }
    if (__GLeeCheckExtension("GL_OES_read_format", &extensionNames) )
    {
        _GLEE_OES_read_format = GL_TRUE;
        __GLeeLink_GL_OES_read_format();
    }
    if (__GLeeCheckExtension("GL_EXT_depth_bounds_test", &extensionNames) )
    {
        _GLEE_EXT_depth_bounds_test = GL_TRUE;
        __GLeeLink_GL_EXT_depth_bounds_test();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_mirror_clamp", &extensionNames) )
    {
        _GLEE_EXT_texture_mirror_clamp = GL_TRUE;
        __GLeeLink_GL_EXT_texture_mirror_clamp();
    }
    if (__GLeeCheckExtension("GL_EXT_blend_equation_separate", &extensionNames) )
    {
        _GLEE_EXT_blend_equation_separate = GL_TRUE;
        __GLeeLink_GL_EXT_blend_equation_separate();
    }
    if (__GLeeCheckExtension("GL_MESA_pack_invert", &extensionNames) )
    {
        _GLEE_MESA_pack_invert = GL_TRUE;
        __GLeeLink_GL_MESA_pack_invert();
    }
    if (__GLeeCheckExtension("GL_MESA_ycbcr_texture", &extensionNames) )
    {
        _GLEE_MESA_ycbcr_texture = GL_TRUE;
        __GLeeLink_GL_MESA_ycbcr_texture();
    }
    if (__GLeeCheckExtension("GL_EXT_pixel_buffer_object", &extensionNames) )
    {
        _GLEE_EXT_pixel_buffer_object = GL_TRUE;
        __GLeeLink_GL_EXT_pixel_buffer_object();
    }
    if (__GLeeCheckExtension("GL_NV_fragment_program_option", &extensionNames) )
    {
        _GLEE_NV_fragment_program_option = GL_TRUE;
        __GLeeLink_GL_NV_fragment_program_option();
    }
    if (__GLeeCheckExtension("GL_NV_fragment_program2", &extensionNames) )
    {
        _GLEE_NV_fragment_program2 = GL_TRUE;
        __GLeeLink_GL_NV_fragment_program2();
    }
    if (__GLeeCheckExtension("GL_NV_vertex_program2_option", &extensionNames) )
    {
        _GLEE_NV_vertex_program2_option = GL_TRUE;
        __GLeeLink_GL_NV_vertex_program2_option();
    }
    if (__GLeeCheckExtension("GL_NV_vertex_program3", &extensionNames) )
    {
        _GLEE_NV_vertex_program3 = GL_TRUE;
        __GLeeLink_GL_NV_vertex_program3();
    }
    if (__GLeeCheckExtension("GL_EXT_framebuffer_object", &extensionNames) )
    {
        _GLEE_EXT_framebuffer_object = GL_TRUE;
        __GLeeLink_GL_EXT_framebuffer_object();
    }
    if (__GLeeCheckExtension("GL_GREMEDY_string_marker", &extensionNames) )
    {
        _GLEE_GREMEDY_string_marker = GL_TRUE;
        __GLeeLink_GL_GREMEDY_string_marker();
    }
    if (__GLeeCheckExtension("GL_EXT_Cg_shader", &extensionNames) )
    {
        _GLEE_EXT_Cg_shader = GL_TRUE;
        __GLeeLink_GL_EXT_Cg_shader();
    }
    if (__GLeeCheckExtension("GL_EXT_timer_query", &extensionNames) )
    {
        _GLEE_EXT_timer_query = GL_TRUE;
        __GLeeLink_GL_EXT_timer_query();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_buffer_object", &extensionNames) )
    {
        _GLEE_EXT_texture_buffer_object = GL_TRUE;
        __GLeeLink_GL_EXT_texture_buffer_object();
    }
    if (__GLeeCheckExtension("GL_EXT_gpu_shader4", &extensionNames) )
    {
        _GLEE_EXT_gpu_shader4 = GL_TRUE;
        __GLeeLink_GL_EXT_gpu_shader4();
    }
    if (__GLeeCheckExtension("GL_EXT_geometry_shader4", &extensionNames) )
    {
        _GLEE_EXT_geometry_shader4 = GL_TRUE;
        __GLeeLink_GL_EXT_geometry_shader4();
    }
    if (__GLeeCheckExtension("GL_EXT_bindable_uniform", &extensionNames) )
    {
        _GLEE_EXT_bindable_uniform = GL_TRUE;
        __GLeeLink_GL_EXT_bindable_uniform();
    }
    if (__GLeeCheckExtension("GL_EXT_framebuffer_sRGB", &extensionNames) )
    {
        _GLEE_EXT_framebuffer_sRGB = GL_TRUE;
        __GLeeLink_GL_EXT_framebuffer_sRGB();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_shared_exponent", &extensionNames) )
    {
        _GLEE_EXT_texture_shared_exponent = GL_TRUE;
        __GLeeLink_GL_EXT_texture_shared_exponent();
    }
    if (__GLeeCheckExtension("GL_EXT_packed_float", &extensionNames) )
    {
        _GLEE_EXT_packed_float = GL_TRUE;
        __GLeeLink_GL_EXT_packed_float();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_array", &extensionNames) )
    {
        _GLEE_EXT_texture_array = GL_TRUE;
        __GLeeLink_GL_EXT_texture_array();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_integer", &extensionNames) )
    {
        _GLEE_EXT_texture_integer = GL_TRUE;
        __GLeeLink_GL_EXT_texture_integer();
    }
    if (__GLeeCheckExtension("GL_NV_depth_buffer_float", &extensionNames) )
    {
        _GLEE_NV_depth_buffer_float = GL_TRUE;
        __GLeeLink_GL_NV_depth_buffer_float();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_compression_latc", &extensionNames) )
    {
        _GLEE_EXT_texture_compression_latc = GL_TRUE;
        __GLeeLink_GL_EXT_texture_compression_latc();
    }
    if (__GLeeCheckExtension("GL_NV_transform_feedback", &extensionNames) )
    {
        _GLEE_NV_transform_feedback = GL_TRUE;
        __GLeeLink_GL_NV_transform_feedback();
    }
    if (__GLeeCheckExtension("GL_NV_geometry_program4", &extensionNames) )
    {
        _GLEE_NV_geometry_program4 = GL_TRUE;
        __GLeeLink_GL_NV_geometry_program4();
    }
    if (__GLeeCheckExtension("GL_NV_gpu_program4", &extensionNames) )
    {
        _GLEE_NV_gpu_program4 = GL_TRUE;
        __GLeeLink_GL_NV_gpu_program4();
    }
    if (__GLeeCheckExtension("GL_NV_framebuffer_multisample_coverage", &extensionNames) )
    {
        _GLEE_NV_framebuffer_multisample_coverage = GL_TRUE;
        __GLeeLink_GL_NV_framebuffer_multisample_coverage();
    }
    if (__GLeeCheckExtension("GL_EXT_framebuffer_multisample", &extensionNames) )
    {
        _GLEE_EXT_framebuffer_multisample = GL_TRUE;
        __GLeeLink_GL_EXT_framebuffer_multisample();
    }
    if (__GLeeCheckExtension("GL_EXT_framebuffer_blit", &extensionNames) )
    {
        _GLEE_EXT_framebuffer_blit = GL_TRUE;
        __GLeeLink_GL_EXT_framebuffer_blit();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_compression_rgtc", &extensionNames) )
    {
        _GLEE_EXT_texture_compression_rgtc = GL_TRUE;
        __GLeeLink_GL_EXT_texture_compression_rgtc();
    }
    if (__GLeeCheckExtension("GL_EXT_color_matrix", &extensionNames) )
    {
        _GLEE_EXT_color_matrix = GL_TRUE;
        __GLeeLink_GL_EXT_color_matrix();
    }
    if (__GLeeCheckExtension("GL_SGIX_texture_select", &extensionNames) )
    {
        _GLEE_SGIX_texture_select = GL_TRUE;
        __GLeeLink_GL_SGIX_texture_select();
    }
    if (__GLeeCheckExtension("GL_INGR_blend_func_separate", &extensionNames) )
    {
        _GLEE_INGR_blend_func_separate = GL_TRUE;
        __GLeeLink_GL_INGR_blend_func_separate();
    }
    if (__GLeeCheckExtension("GL_SGIX_depth_pass_instrument", &extensionNames) )
    {
        _GLEE_SGIX_depth_pass_instrument = GL_TRUE;
        __GLeeLink_GL_SGIX_depth_pass_instrument();
    }
    if (__GLeeCheckExtension("GL_SGIX_igloo_interface", &extensionNames) )
    {
        _GLEE_SGIX_igloo_interface = GL_TRUE;
        __GLeeLink_GL_SGIX_igloo_interface();
    }
    if (__GLeeCheckExtension("GL_EXT_draw_buffers2", &extensionNames) )
    {
        _GLEE_EXT_draw_buffers2 = GL_TRUE;
        __GLeeLink_GL_EXT_draw_buffers2();
    }
    if (__GLeeCheckExtension("GL_NV_parameter_buffer_object", &extensionNames) )
    {
        _GLEE_NV_parameter_buffer_object = GL_TRUE;
        __GLeeLink_GL_NV_parameter_buffer_object();
    }
    if (__GLeeCheckExtension("GL_EXT_draw_instanced", &extensionNames) )
    {
        _GLEE_EXT_draw_instanced = GL_TRUE;
        __GLeeLink_GL_EXT_draw_instanced();
    }
    if (__GLeeCheckExtension("GL_EXT_fragment_lighting", &extensionNames) )
    {
        _GLEE_EXT_fragment_lighting = GL_TRUE;
        __GLeeLink_GL_EXT_fragment_lighting();
    }
    if (__GLeeCheckExtension("GL_EXT_packed_depth_stencil", &extensionNames) )
    {
        _GLEE_EXT_packed_depth_stencil = GL_TRUE;
        __GLeeLink_GL_EXT_packed_depth_stencil();
    }
    if (__GLeeCheckExtension("GL_EXT_scene_marker", &extensionNames) )
    {
        _GLEE_EXT_scene_marker = GL_TRUE;
        __GLeeLink_GL_EXT_scene_marker();
    }
    if (__GLeeCheckExtension("GL_EXT_stencil_clear_tag", &extensionNames) )
    {
        _GLEE_EXT_stencil_clear_tag = GL_TRUE;
        __GLeeLink_GL_EXT_stencil_clear_tag();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_compression_dxt1", &extensionNames) )
    {
        _GLEE_EXT_texture_compression_dxt1 = GL_TRUE;
        __GLeeLink_GL_EXT_texture_compression_dxt1();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_env", &extensionNames) )
    {
        _GLEE_EXT_texture_env = GL_TRUE;
        __GLeeLink_GL_EXT_texture_env();
    }
    if (__GLeeCheckExtension("GL_EXT_texture_sRGB", &extensionNames) )
    {
        _GLEE_EXT_texture_sRGB = GL_TRUE;
        __GLeeLink_GL_EXT_texture_sRGB();
    }
    if (__GLeeCheckExtension("GL_IBM_static_data", &extensionNames) )
    {
        _GLEE_IBM_static_data = GL_TRUE;
        __GLeeLink_GL_IBM_static_data();
    }
    if (__GLeeCheckExtension("GL_MESAX_texture_stack", &extensionNames) )
    {
        _GLEE_MESAX_texture_stack = GL_TRUE;
        __GLeeLink_GL_MESAX_texture_stack();
    }
    if (__GLeeCheckExtension("GL_OES_byte_coordinates", &extensionNames) )
    {
        _GLEE_OES_byte_coordinates = GL_TRUE;
        __GLeeLink_GL_OES_byte_coordinates();
    }
    if (__GLeeCheckExtension("GL_OES_compressed_paletted_texture", &extensionNames) )
    {
        _GLEE_OES_compressed_paletted_texture = GL_TRUE;
        __GLeeLink_GL_OES_compressed_paletted_texture();
    }
    if (__GLeeCheckExtension("GL_OES_single_precision", &extensionNames) )
    {
        _GLEE_OES_single_precision = GL_TRUE;
        __GLeeLink_GL_OES_single_precision();
    }
    if (__GLeeCheckExtension("GL_SGIX_pixel_texture_bits", &extensionNames) )
    {
        _GLEE_SGIX_pixel_texture_bits = GL_TRUE;
        __GLeeLink_GL_SGIX_pixel_texture_bits();
    }
    if (__GLeeCheckExtension("GL_SGIX_texture_range", &extensionNames) )
    {
        _GLEE_SGIX_texture_range = GL_TRUE;
        __GLeeLink_GL_SGIX_texture_range();
    }
#ifdef WIN32
    if (__GLeeCheckExtension("WGL_ARB_buffer_region", &extensionNames) )
    {
        _GLEE_WGL_ARB_buffer_region = GL_TRUE;
        __GLeeLink_WGL_ARB_buffer_region();
    }
    if (__GLeeCheckExtension("WGL_ARB_multisample", &extensionNames) )
    {
        _GLEE_WGL_ARB_multisample = GL_TRUE;
        __GLeeLink_WGL_ARB_multisample();
    }
    if (__GLeeCheckExtension("WGL_ARB_extensions_string", &extensionNames) )
    {
        _GLEE_WGL_ARB_extensions_string = GL_TRUE;
        __GLeeLink_WGL_ARB_extensions_string();
    }
    if (__GLeeCheckExtension("WGL_ARB_pixel_format", &extensionNames) )
    {
        _GLEE_WGL_ARB_pixel_format = GL_TRUE;
        __GLeeLink_WGL_ARB_pixel_format();
    }
    if (__GLeeCheckExtension("WGL_ARB_make_current_read", &extensionNames) )
    {
        _GLEE_WGL_ARB_make_current_read = GL_TRUE;
        __GLeeLink_WGL_ARB_make_current_read();
    }
    if (__GLeeCheckExtension("WGL_ARB_pbuffer", &extensionNames) )
    {
        _GLEE_WGL_ARB_pbuffer = GL_TRUE;
        __GLeeLink_WGL_ARB_pbuffer();
    }
    if (__GLeeCheckExtension("WGL_ARB_render_texture", &extensionNames) )
    {
        _GLEE_WGL_ARB_render_texture = GL_TRUE;
        __GLeeLink_WGL_ARB_render_texture();
    }
    if (__GLeeCheckExtension("WGL_ARB_pixel_format_float", &extensionNames) )
    {
        _GLEE_WGL_ARB_pixel_format_float = GL_TRUE;
        __GLeeLink_WGL_ARB_pixel_format_float();
    }
    if (__GLeeCheckExtension("WGL_EXT_make_current_read", &extensionNames) )
    {
        _GLEE_WGL_EXT_make_current_read = GL_TRUE;
        __GLeeLink_WGL_EXT_make_current_read();
    }
    if (__GLeeCheckExtension("WGL_EXT_pixel_format", &extensionNames) )
    {
        _GLEE_WGL_EXT_pixel_format = GL_TRUE;
        __GLeeLink_WGL_EXT_pixel_format();
    }
    if (__GLeeCheckExtension("WGL_EXT_pbuffer", &extensionNames) )
    {
        _GLEE_WGL_EXT_pbuffer = GL_TRUE;
        __GLeeLink_WGL_EXT_pbuffer();
    }
    if (__GLeeCheckExtension("WGL_EXT_depth_float", &extensionNames) )
    {
        _GLEE_WGL_EXT_depth_float = GL_TRUE;
        __GLeeLink_WGL_EXT_depth_float();
    }
    if (__GLeeCheckExtension("WGL_3DFX_multisample", &extensionNames) )
    {
        _GLEE_WGL_3DFX_multisample = GL_TRUE;
        __GLeeLink_WGL_3DFX_multisample();
    }
    if (__GLeeCheckExtension("WGL_EXT_multisample", &extensionNames) )
    {
        _GLEE_WGL_EXT_multisample = GL_TRUE;
        __GLeeLink_WGL_EXT_multisample();
    }
    if (__GLeeCheckExtension("WGL_I3D_digital_video_control", &extensionNames) )
    {
        _GLEE_WGL_I3D_digital_video_control = GL_TRUE;
        __GLeeLink_WGL_I3D_digital_video_control();
    }
    if (__GLeeCheckExtension("WGL_I3D_gamma", &extensionNames) )
    {
        _GLEE_WGL_I3D_gamma = GL_TRUE;
        __GLeeLink_WGL_I3D_gamma();
    }
    if (__GLeeCheckExtension("WGL_I3D_genlock", &extensionNames) )
    {
        _GLEE_WGL_I3D_genlock = GL_TRUE;
        __GLeeLink_WGL_I3D_genlock();
    }
    if (__GLeeCheckExtension("WGL_I3D_image_buffer", &extensionNames) )
    {
        _GLEE_WGL_I3D_image_buffer = GL_TRUE;
        __GLeeLink_WGL_I3D_image_buffer();
    }
    if (__GLeeCheckExtension("WGL_I3D_swap_frame_lock", &extensionNames) )
    {
        _GLEE_WGL_I3D_swap_frame_lock = GL_TRUE;
        __GLeeLink_WGL_I3D_swap_frame_lock();
    }
    if (__GLeeCheckExtension("WGL_NV_render_depth_texture", &extensionNames) )
    {
        _GLEE_WGL_NV_render_depth_texture = GL_TRUE;
        __GLeeLink_WGL_NV_render_depth_texture();
    }
    if (__GLeeCheckExtension("WGL_NV_render_texture_rectangle", &extensionNames) )
    {
        _GLEE_WGL_NV_render_texture_rectangle = GL_TRUE;
        __GLeeLink_WGL_NV_render_texture_rectangle();
    }
    if (__GLeeCheckExtension("WGL_ATI_pixel_format_float", &extensionNames) )
    {
        _GLEE_WGL_ATI_pixel_format_float = GL_TRUE;
        __GLeeLink_WGL_ATI_pixel_format_float();
    }
    if (__GLeeCheckExtension("WGL_NV_float_buffer", &extensionNames) )
    {
        _GLEE_WGL_NV_float_buffer = GL_TRUE;
        __GLeeLink_WGL_NV_float_buffer();
    }
    if (__GLeeCheckExtension("WGL_EXT_display_color_table", &extensionNames) )
    {
        _GLEE_WGL_EXT_display_color_table = GL_TRUE;
        __GLeeLink_WGL_EXT_display_color_table();
    }
    if (__GLeeCheckExtension("WGL_EXT_extensions_string", &extensionNames) )
    {
        _GLEE_WGL_EXT_extensions_string = GL_TRUE;
        __GLeeLink_WGL_EXT_extensions_string();
    }
    if (__GLeeCheckExtension("WGL_EXT_swap_control", &extensionNames) )
    {
        _GLEE_WGL_EXT_swap_control = GL_TRUE;
        __GLeeLink_WGL_EXT_swap_control();
    }
    if (__GLeeCheckExtension("WGL_NV_vertex_array_range", &extensionNames) )
    {
        _GLEE_WGL_NV_vertex_array_range = GL_TRUE;
        __GLeeLink_WGL_NV_vertex_array_range();
    }
    if (__GLeeCheckExtension("WGL_OML_sync_control", &extensionNames) )
    {
        _GLEE_WGL_OML_sync_control = GL_TRUE;
        __GLeeLink_WGL_OML_sync_control();
    }
    if (__GLeeCheckExtension("WGL_I3D_swap_frame_usage", &extensionNames) )
    {
        _GLEE_WGL_I3D_swap_frame_usage = GL_TRUE;
        __GLeeLink_WGL_I3D_swap_frame_usage();
    }
    if (__GLeeCheckExtension("WGL_3DL_stereo_control", &extensionNames) )
    {
        _GLEE_WGL_3DL_stereo_control = GL_TRUE;
        __GLeeLink_WGL_3DL_stereo_control();
    }
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else /* GLX */
    if (__GLeeCheckExtension("GLX_VERSION_1_3", &extensionNames) )
    {
        _GLEE_GLX_VERSION_1_3 = GL_TRUE;
        __GLeeLink_GLX_VERSION_1_3();
    }
    if (__GLeeCheckExtension("GLX_VERSION_1_4", &extensionNames) )
    {
        _GLEE_GLX_VERSION_1_4 = GL_TRUE;
        __GLeeLink_GLX_VERSION_1_4();
    }
    if (__GLeeCheckExtension("GLX_ARB_multisample", &extensionNames) )
    {
        _GLEE_GLX_ARB_multisample = GL_TRUE;
        __GLeeLink_GLX_ARB_multisample();
    }
    if (__GLeeCheckExtension("GLX_ARB_fbconfig_float", &extensionNames) )
    {
        _GLEE_GLX_ARB_fbconfig_float = GL_TRUE;
        __GLeeLink_GLX_ARB_fbconfig_float();
    }
    if (__GLeeCheckExtension("GLX_SGIS_multisample", &extensionNames) )
    {
        _GLEE_GLX_SGIS_multisample = GL_TRUE;
        __GLeeLink_GLX_SGIS_multisample();
    }
    if (__GLeeCheckExtension("GLX_EXT_visual_info", &extensionNames) )
    {
        _GLEE_GLX_EXT_visual_info = GL_TRUE;
        __GLeeLink_GLX_EXT_visual_info();
    }
    if (__GLeeCheckExtension("GLX_SGI_swap_control", &extensionNames) )
    {
        _GLEE_GLX_SGI_swap_control = GL_TRUE;
        __GLeeLink_GLX_SGI_swap_control();
    }
    if (__GLeeCheckExtension("GLX_SGI_video_sync", &extensionNames) )
    {
        _GLEE_GLX_SGI_video_sync = GL_TRUE;
        __GLeeLink_GLX_SGI_video_sync();
    }
    if (__GLeeCheckExtension("GLX_SGI_make_current_read", &extensionNames) )
    {
        _GLEE_GLX_SGI_make_current_read = GL_TRUE;
        __GLeeLink_GLX_SGI_make_current_read();
    }
    if (__GLeeCheckExtension("GLX_EXT_visual_rating", &extensionNames) )
    {
        _GLEE_GLX_EXT_visual_rating = GL_TRUE;
        __GLeeLink_GLX_EXT_visual_rating();
    }
    if (__GLeeCheckExtension("GLX_EXT_import_context", &extensionNames) )
    {
        _GLEE_GLX_EXT_import_context = GL_TRUE;
        __GLeeLink_GLX_EXT_import_context();
    }
    if (__GLeeCheckExtension("GLX_SGIX_fbconfig", &extensionNames) )
    {
        _GLEE_GLX_SGIX_fbconfig = GL_TRUE;
        __GLeeLink_GLX_SGIX_fbconfig();
    }
    if (__GLeeCheckExtension("GLX_SGIX_pbuffer", &extensionNames) )
    {
        _GLEE_GLX_SGIX_pbuffer = GL_TRUE;
        __GLeeLink_GLX_SGIX_pbuffer();
    }
    if (__GLeeCheckExtension("GLX_SGI_cushion", &extensionNames) )
    {
        _GLEE_GLX_SGI_cushion = GL_TRUE;
        __GLeeLink_GLX_SGI_cushion();
    }
    if (__GLeeCheckExtension("GLX_SGIX_video_resize", &extensionNames) )
    {
        _GLEE_GLX_SGIX_video_resize = GL_TRUE;
        __GLeeLink_GLX_SGIX_video_resize();
    }
    if (__GLeeCheckExtension("GLX_SGIX_swap_group", &extensionNames) )
    {
        _GLEE_GLX_SGIX_swap_group = GL_TRUE;
        __GLeeLink_GLX_SGIX_swap_group();
    }
    if (__GLeeCheckExtension("GLX_SGIX_swap_barrier", &extensionNames) )
    {
        _GLEE_GLX_SGIX_swap_barrier = GL_TRUE;
        __GLeeLink_GLX_SGIX_swap_barrier();
    }
    if (__GLeeCheckExtension("GLX_SGIS_blended_overlay", &extensionNames) )
    {
        _GLEE_GLX_SGIS_blended_overlay = GL_TRUE;
        __GLeeLink_GLX_SGIS_blended_overlay();
    }
    if (__GLeeCheckExtension("GLX_SGIS_shared_multisample", &extensionNames) )
    {
        _GLEE_GLX_SGIS_shared_multisample = GL_TRUE;
        __GLeeLink_GLX_SGIS_shared_multisample();
    }
    if (__GLeeCheckExtension("GLX_SUN_get_transparent_index", &extensionNames) )
    {
        _GLEE_GLX_SUN_get_transparent_index = GL_TRUE;
        __GLeeLink_GLX_SUN_get_transparent_index();
    }
    if (__GLeeCheckExtension("GLX_3DFX_multisample", &extensionNames) )
    {
        _GLEE_GLX_3DFX_multisample = GL_TRUE;
        __GLeeLink_GLX_3DFX_multisample();
    }
    if (__GLeeCheckExtension("GLX_MESA_copy_sub_buffer", &extensionNames) )
    {
        _GLEE_GLX_MESA_copy_sub_buffer = GL_TRUE;
        __GLeeLink_GLX_MESA_copy_sub_buffer();
    }
    if (__GLeeCheckExtension("GLX_MESA_pixmap_colormap", &extensionNames) )
    {
        _GLEE_GLX_MESA_pixmap_colormap = GL_TRUE;
        __GLeeLink_GLX_MESA_pixmap_colormap();
    }
    if (__GLeeCheckExtension("GLX_MESA_release_buffers", &extensionNames) )
    {
        _GLEE_GLX_MESA_release_buffers = GL_TRUE;
        __GLeeLink_GLX_MESA_release_buffers();
    }
    if (__GLeeCheckExtension("GLX_MESA_set_3dfx_mode", &extensionNames) )
    {
        _GLEE_GLX_MESA_set_3dfx_mode = GL_TRUE;
        __GLeeLink_GLX_MESA_set_3dfx_mode();
    }
    if (__GLeeCheckExtension("GLX_SGIX_visual_select_group", &extensionNames) )
    {
        _GLEE_GLX_SGIX_visual_select_group = GL_TRUE;
        __GLeeLink_GLX_SGIX_visual_select_group();
    }
    if (__GLeeCheckExtension("GLX_OML_swap_method", &extensionNames) )
    {
        _GLEE_GLX_OML_swap_method = GL_TRUE;
        __GLeeLink_GLX_OML_swap_method();
    }
    if (__GLeeCheckExtension("GLX_OML_sync_control", &extensionNames) )
    {
        _GLEE_GLX_OML_sync_control = GL_TRUE;
        __GLeeLink_GLX_OML_sync_control();
    }
    if (__GLeeCheckExtension("GLX_NV_float_buffer", &extensionNames) )
    {
        _GLEE_GLX_NV_float_buffer = GL_TRUE;
        __GLeeLink_GLX_NV_float_buffer();
    }
    if (__GLeeCheckExtension("GLX_SGIX_hyperpipe", &extensionNames) )
    {
        _GLEE_GLX_SGIX_hyperpipe = GL_TRUE;
        __GLeeLink_GLX_SGIX_hyperpipe();
    }
    if (__GLeeCheckExtension("GLX_MESA_agp_offset", &extensionNames) )
    {
        _GLEE_GLX_MESA_agp_offset = GL_TRUE;
        __GLeeLink_GLX_MESA_agp_offset();
    }
    if (__GLeeCheckExtension("GLX_EXT_scene_marker", &extensionNames) )
    {
        _GLEE_GLX_EXT_scene_marker = GL_TRUE;
        __GLeeLink_GLX_EXT_scene_marker();
    }
#endif /* end GLX */

    __GLeeExtList_clean(&extensionNames);
    return GL_TRUE;
}
