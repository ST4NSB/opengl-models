

#ifndef __glee_h_
#define __glee_h_

#ifdef __gl_h_
	#error gl.h included before glee.h
#endif

#ifdef __glext_h_
	#error glext.h included before glee.h
#endif

#ifdef __wglext_h_
	#error wglext.h included before glee.h
#endif

#ifdef __glxext_h_
	#error glxext.h included before glee.h
#endif

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	#include <GL/gl.h>
#elif defined(__APPLE__) || defined(__APPLE_CC__)
	#include <OpenGL/gl.h>
#else // GLX
	#define __glext_h_  /* prevent glext.h from being included  */
	#define __glxext_h_ /* prevent glxext.h from being included */
	#define GLX_GLXEXT_PROTOTYPES
	#include <GL/gl.h>
	#include <GL/glx.h>
#endif

#ifndef APIENTRY
	#define APIENTRY
#endif

#ifndef APIENTRYP
	#define APIENTRYP APIENTRY *
#endif

#define GLEE_EXTERN extern

#ifdef __cplusplus 
	extern "C" {		/* begin C linkage */
#endif

#define GLEE_LINK_FAIL 0
#define GLEE_LINK_PARTIAL 1
#define GLEE_LINK_COMPLETE 2

/* Extension querying variables */

GLEE_EXTERN GLboolean _GLEE_VERSION_1_2;
GLEE_EXTERN GLboolean _GLEE_ARB_imaging;
GLEE_EXTERN GLboolean _GLEE_VERSION_1_3;
GLEE_EXTERN GLboolean _GLEE_VERSION_1_4;
GLEE_EXTERN GLboolean _GLEE_VERSION_1_5;
GLEE_EXTERN GLboolean _GLEE_VERSION_2_0;
GLEE_EXTERN GLboolean _GLEE_VERSION_2_1;
GLEE_EXTERN GLboolean _GLEE_ARB_multitexture;
GLEE_EXTERN GLboolean _GLEE_ARB_transpose_matrix;
GLEE_EXTERN GLboolean _GLEE_ARB_multisample;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_env_add;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_cube_map;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_compression;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_border_clamp;
GLEE_EXTERN GLboolean _GLEE_ARB_point_parameters;
GLEE_EXTERN GLboolean _GLEE_ARB_vertex_blend;
GLEE_EXTERN GLboolean _GLEE_ARB_matrix_palette;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_env_combine;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_env_crossbar;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_env_dot3;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_mirrored_repeat;
GLEE_EXTERN GLboolean _GLEE_ARB_depth_texture;
GLEE_EXTERN GLboolean _GLEE_ARB_shadow;
GLEE_EXTERN GLboolean _GLEE_ARB_shadow_ambient;
GLEE_EXTERN GLboolean _GLEE_ARB_window_pos;
GLEE_EXTERN GLboolean _GLEE_ARB_vertex_program;
GLEE_EXTERN GLboolean _GLEE_ARB_fragment_program;
GLEE_EXTERN GLboolean _GLEE_ARB_vertex_buffer_object;
GLEE_EXTERN GLboolean _GLEE_ARB_occlusion_query;
GLEE_EXTERN GLboolean _GLEE_ARB_shader_objects;
GLEE_EXTERN GLboolean _GLEE_ARB_vertex_shader;
GLEE_EXTERN GLboolean _GLEE_ARB_fragment_shader;
GLEE_EXTERN GLboolean _GLEE_ARB_shading_language_100;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_non_power_of_two;
GLEE_EXTERN GLboolean _GLEE_ARB_point_sprite;
GLEE_EXTERN GLboolean _GLEE_ARB_fragment_program_shadow;
GLEE_EXTERN GLboolean _GLEE_ARB_draw_buffers;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_rectangle;
GLEE_EXTERN GLboolean _GLEE_ARB_color_buffer_float;
GLEE_EXTERN GLboolean _GLEE_ARB_half_float_pixel;
GLEE_EXTERN GLboolean _GLEE_ARB_texture_float;
GLEE_EXTERN GLboolean _GLEE_ARB_pixel_buffer_object;
GLEE_EXTERN GLboolean _GLEE_EXT_abgr;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_color;
GLEE_EXTERN GLboolean _GLEE_EXT_polygon_offset;
GLEE_EXTERN GLboolean _GLEE_EXT_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_texture3D;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_filter4;
GLEE_EXTERN GLboolean _GLEE_EXT_subtexture;
GLEE_EXTERN GLboolean _GLEE_EXT_copy_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_histogram;
GLEE_EXTERN GLboolean _GLEE_EXT_convolution;
GLEE_EXTERN GLboolean _GLEE_SGI_color_matrix;
GLEE_EXTERN GLboolean _GLEE_SGI_color_table;
GLEE_EXTERN GLboolean _GLEE_SGIS_pixel_texture;
GLEE_EXTERN GLboolean _GLEE_SGIX_pixel_texture;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture4D;
GLEE_EXTERN GLboolean _GLEE_SGI_texture_color_table;
GLEE_EXTERN GLboolean _GLEE_EXT_cmyka;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_object;
GLEE_EXTERN GLboolean _GLEE_SGIS_detail_texture;
GLEE_EXTERN GLboolean _GLEE_SGIS_sharpen_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_packed_pixels;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_lod;
GLEE_EXTERN GLboolean _GLEE_SGIS_multisample;
GLEE_EXTERN GLboolean _GLEE_EXT_rescale_normal;
GLEE_EXTERN GLboolean _GLEE_EXT_vertex_array;
GLEE_EXTERN GLboolean _GLEE_EXT_misc_attribute;
GLEE_EXTERN GLboolean _GLEE_SGIS_generate_mipmap;
GLEE_EXTERN GLboolean _GLEE_SGIX_clipmap;
GLEE_EXTERN GLboolean _GLEE_SGIX_shadow;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_edge_clamp;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_border_clamp;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_minmax;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_subtract;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_logic_op;
GLEE_EXTERN GLboolean _GLEE_SGIX_interlace;
GLEE_EXTERN GLboolean _GLEE_SGIX_pixel_tiles;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_select;
GLEE_EXTERN GLboolean _GLEE_SGIX_sprite;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_multi_buffer;
GLEE_EXTERN GLboolean _GLEE_EXT_point_parameters;
GLEE_EXTERN GLboolean _GLEE_SGIS_point_parameters;
GLEE_EXTERN GLboolean _GLEE_SGIX_instruments;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_scale_bias;
GLEE_EXTERN GLboolean _GLEE_SGIX_framezoom;
GLEE_EXTERN GLboolean _GLEE_SGIX_tag_sample_buffer;
GLEE_EXTERN GLboolean _GLEE_FfdMaskSGIX;
GLEE_EXTERN GLboolean _GLEE_SGIX_polynomial_ffd;
GLEE_EXTERN GLboolean _GLEE_SGIX_reference_plane;
GLEE_EXTERN GLboolean _GLEE_SGIX_flush_raster;
GLEE_EXTERN GLboolean _GLEE_SGIX_depth_texture;
GLEE_EXTERN GLboolean _GLEE_SGIS_fog_function;
GLEE_EXTERN GLboolean _GLEE_SGIX_fog_offset;
GLEE_EXTERN GLboolean _GLEE_HP_image_transform;
GLEE_EXTERN GLboolean _GLEE_HP_convolution_border_modes;
GLEE_EXTERN GLboolean _GLEE_INGR_palette_buffer;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_add_env;
GLEE_EXTERN GLboolean _GLEE_EXT_color_subtable;
GLEE_EXTERN GLboolean _GLEE_PGI_vertex_hints;
GLEE_EXTERN GLboolean _GLEE_PGI_misc_hints;
GLEE_EXTERN GLboolean _GLEE_EXT_paletted_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_clip_volume_hint;
GLEE_EXTERN GLboolean _GLEE_SGIX_list_priority;
GLEE_EXTERN GLboolean _GLEE_SGIX_ir_instrument1;
GLEE_EXTERN GLboolean _GLEE_SGIX_calligraphic_fragment;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_lod_bias;
GLEE_EXTERN GLboolean _GLEE_SGIX_shadow_ambient;
GLEE_EXTERN GLboolean _GLEE_EXT_index_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_index_material;
GLEE_EXTERN GLboolean _GLEE_EXT_index_func;
GLEE_EXTERN GLboolean _GLEE_EXT_index_array_formats;
GLEE_EXTERN GLboolean _GLEE_EXT_compiled_vertex_array;
GLEE_EXTERN GLboolean _GLEE_EXT_cull_vertex;
GLEE_EXTERN GLboolean _GLEE_SGIX_ycrcb;
GLEE_EXTERN GLboolean _GLEE_SGIX_fragment_lighting;
GLEE_EXTERN GLboolean _GLEE_IBM_rasterpos_clip;
GLEE_EXTERN GLboolean _GLEE_HP_texture_lighting;
GLEE_EXTERN GLboolean _GLEE_EXT_draw_range_elements;
GLEE_EXTERN GLboolean _GLEE_WIN_phong_shading;
GLEE_EXTERN GLboolean _GLEE_WIN_specular_fog;
GLEE_EXTERN GLboolean _GLEE_EXT_light_texture;
GLEE_EXTERN GLboolean _GLEE_SGIX_blend_alpha_minmax;
GLEE_EXTERN GLboolean _GLEE_SGIX_impact_pixel_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_bgra;
GLEE_EXTERN GLboolean _GLEE_SGIX_async;
GLEE_EXTERN GLboolean _GLEE_SGIX_async_pixel;
GLEE_EXTERN GLboolean _GLEE_SGIX_async_histogram;
GLEE_EXTERN GLboolean _GLEE_INTEL_texture_scissor;
GLEE_EXTERN GLboolean _GLEE_INTEL_parallel_arrays;
GLEE_EXTERN GLboolean _GLEE_HP_occlusion_test;
GLEE_EXTERN GLboolean _GLEE_EXT_pixel_transform;
GLEE_EXTERN GLboolean _GLEE_EXT_pixel_transform_color_table;
GLEE_EXTERN GLboolean _GLEE_EXT_shared_texture_palette;
GLEE_EXTERN GLboolean _GLEE_EXT_separate_specular_color;
GLEE_EXTERN GLboolean _GLEE_EXT_secondary_color;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_perturb_normal;
GLEE_EXTERN GLboolean _GLEE_EXT_multi_draw_arrays;
GLEE_EXTERN GLboolean _GLEE_EXT_fog_coord;
GLEE_EXTERN GLboolean _GLEE_REND_screen_coordinates;
GLEE_EXTERN GLboolean _GLEE_EXT_coordinate_frame;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_env_combine;
GLEE_EXTERN GLboolean _GLEE_APPLE_specular_vector;
GLEE_EXTERN GLboolean _GLEE_APPLE_transform_hint;
GLEE_EXTERN GLboolean _GLEE_SGIX_fog_scale;
GLEE_EXTERN GLboolean _GLEE_SUNX_constant_data;
GLEE_EXTERN GLboolean _GLEE_SUN_global_alpha;
GLEE_EXTERN GLboolean _GLEE_SUN_triangle_list;
GLEE_EXTERN GLboolean _GLEE_SUN_vertex;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_func_separate;
GLEE_EXTERN GLboolean _GLEE_INGR_color_clamp;
GLEE_EXTERN GLboolean _GLEE_INGR_interlace_read;
GLEE_EXTERN GLboolean _GLEE_EXT_stencil_wrap;
GLEE_EXTERN GLboolean _GLEE_EXT_422_pixels;
GLEE_EXTERN GLboolean _GLEE_NV_texgen_reflection;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_cube_map;
GLEE_EXTERN GLboolean _GLEE_SUN_convolution_border_modes;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_env_add;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_lod_bias;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_filter_anisotropic;
GLEE_EXTERN GLboolean _GLEE_EXT_vertex_weighting;
GLEE_EXTERN GLboolean _GLEE_NV_light_max_exponent;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_array_range;
GLEE_EXTERN GLboolean _GLEE_NV_register_combiners;
GLEE_EXTERN GLboolean _GLEE_NV_fog_distance;
GLEE_EXTERN GLboolean _GLEE_NV_texgen_emboss;
GLEE_EXTERN GLboolean _GLEE_NV_blend_square;
GLEE_EXTERN GLboolean _GLEE_NV_texture_env_combine4;
GLEE_EXTERN GLboolean _GLEE_MESA_resize_buffers;
GLEE_EXTERN GLboolean _GLEE_MESA_window_pos;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_compression_s3tc;
GLEE_EXTERN GLboolean _GLEE_IBM_cull_vertex;
GLEE_EXTERN GLboolean _GLEE_IBM_multimode_draw_arrays;
GLEE_EXTERN GLboolean _GLEE_IBM_vertex_array_lists;
GLEE_EXTERN GLboolean _GLEE_SGIX_subsample;
GLEE_EXTERN GLboolean _GLEE_SGIX_ycrcb_subsample;
GLEE_EXTERN GLboolean _GLEE_SGIX_ycrcba;
GLEE_EXTERN GLboolean _GLEE_SGI_depth_pass_instrument;
GLEE_EXTERN GLboolean _GLEE_3DFX_texture_compression_FXT1;
GLEE_EXTERN GLboolean _GLEE_3DFX_multisample;
GLEE_EXTERN GLboolean _GLEE_3DFX_tbuffer;
GLEE_EXTERN GLboolean _GLEE_EXT_multisample;
GLEE_EXTERN GLboolean _GLEE_SGIX_vertex_preclip;
GLEE_EXTERN GLboolean _GLEE_SGIX_convolution_accuracy;
GLEE_EXTERN GLboolean _GLEE_SGIX_resample;
GLEE_EXTERN GLboolean _GLEE_SGIS_point_line_texgen;
GLEE_EXTERN GLboolean _GLEE_SGIS_texture_color_mask;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_env_dot3;
GLEE_EXTERN GLboolean _GLEE_ATI_texture_mirror_once;
GLEE_EXTERN GLboolean _GLEE_NV_fence;
GLEE_EXTERN GLboolean _GLEE_IBM_texture_mirrored_repeat;
GLEE_EXTERN GLboolean _GLEE_NV_evaluators;
GLEE_EXTERN GLboolean _GLEE_NV_packed_depth_stencil;
GLEE_EXTERN GLboolean _GLEE_NV_register_combiners2;
GLEE_EXTERN GLboolean _GLEE_NV_texture_compression_vtc;
GLEE_EXTERN GLboolean _GLEE_NV_texture_rectangle;
GLEE_EXTERN GLboolean _GLEE_NV_texture_shader;
GLEE_EXTERN GLboolean _GLEE_NV_texture_shader2;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_array_range2;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_program;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_coordinate_clamp;
GLEE_EXTERN GLboolean _GLEE_SGIX_scalebias_hint;
GLEE_EXTERN GLboolean _GLEE_OML_interlace;
GLEE_EXTERN GLboolean _GLEE_OML_subsample;
GLEE_EXTERN GLboolean _GLEE_OML_resample;
GLEE_EXTERN GLboolean _GLEE_NV_copy_depth_to_color;
GLEE_EXTERN GLboolean _GLEE_ATI_envmap_bumpmap;
GLEE_EXTERN GLboolean _GLEE_ATI_fragment_shader;
GLEE_EXTERN GLboolean _GLEE_ATI_pn_triangles;
GLEE_EXTERN GLboolean _GLEE_ATI_vertex_array_object;
GLEE_EXTERN GLboolean _GLEE_EXT_vertex_shader;
GLEE_EXTERN GLboolean _GLEE_ATI_vertex_streams;
GLEE_EXTERN GLboolean _GLEE_ATI_element_array;
GLEE_EXTERN GLboolean _GLEE_SUN_mesh_array;
GLEE_EXTERN GLboolean _GLEE_SUN_slice_accum;
GLEE_EXTERN GLboolean _GLEE_NV_multisample_filter_hint;
GLEE_EXTERN GLboolean _GLEE_NV_depth_clamp;
GLEE_EXTERN GLboolean _GLEE_NV_occlusion_query;
GLEE_EXTERN GLboolean _GLEE_NV_point_sprite;
GLEE_EXTERN GLboolean _GLEE_NV_texture_shader3;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_program1_1;
GLEE_EXTERN GLboolean _GLEE_EXT_shadow_funcs;
GLEE_EXTERN GLboolean _GLEE_EXT_stencil_two_side;
GLEE_EXTERN GLboolean _GLEE_ATI_text_fragment_shader;
GLEE_EXTERN GLboolean _GLEE_APPLE_client_storage;
GLEE_EXTERN GLboolean _GLEE_APPLE_element_array;
GLEE_EXTERN GLboolean _GLEE_APPLE_fence;
GLEE_EXTERN GLboolean _GLEE_APPLE_vertex_array_object;
GLEE_EXTERN GLboolean _GLEE_APPLE_vertex_array_range;
GLEE_EXTERN GLboolean _GLEE_APPLE_ycbcr_422;
GLEE_EXTERN GLboolean _GLEE_S3_s3tc;
GLEE_EXTERN GLboolean _GLEE_ATI_draw_buffers;
GLEE_EXTERN GLboolean _GLEE_ATI_pixel_format_float;
GLEE_EXTERN GLboolean _GLEE_ATI_texture_env_combine3;
GLEE_EXTERN GLboolean _GLEE_ATI_texture_float;
GLEE_EXTERN GLboolean _GLEE_NV_float_buffer;
GLEE_EXTERN GLboolean _GLEE_NV_fragment_program;
GLEE_EXTERN GLboolean _GLEE_NV_half_float;
GLEE_EXTERN GLboolean _GLEE_NV_pixel_data_range;
GLEE_EXTERN GLboolean _GLEE_NV_primitive_restart;
GLEE_EXTERN GLboolean _GLEE_NV_texture_expand_normal;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_program2;
GLEE_EXTERN GLboolean _GLEE_ATI_map_object_buffer;
GLEE_EXTERN GLboolean _GLEE_ATI_separate_stencil;
GLEE_EXTERN GLboolean _GLEE_ATI_vertex_attrib_array_object;
GLEE_EXTERN GLboolean _GLEE_OES_read_format;
GLEE_EXTERN GLboolean _GLEE_EXT_depth_bounds_test;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_mirror_clamp;
GLEE_EXTERN GLboolean _GLEE_EXT_blend_equation_separate;
GLEE_EXTERN GLboolean _GLEE_MESA_pack_invert;
GLEE_EXTERN GLboolean _GLEE_MESA_ycbcr_texture;
GLEE_EXTERN GLboolean _GLEE_EXT_pixel_buffer_object;
GLEE_EXTERN GLboolean _GLEE_NV_fragment_program_option;
GLEE_EXTERN GLboolean _GLEE_NV_fragment_program2;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_program2_option;
GLEE_EXTERN GLboolean _GLEE_NV_vertex_program3;
GLEE_EXTERN GLboolean _GLEE_EXT_framebuffer_object;
GLEE_EXTERN GLboolean _GLEE_GREMEDY_string_marker;
GLEE_EXTERN GLboolean _GLEE_EXT_Cg_shader;
GLEE_EXTERN GLboolean _GLEE_EXT_timer_query;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_buffer_object;
GLEE_EXTERN GLboolean _GLEE_EXT_gpu_shader4;
GLEE_EXTERN GLboolean _GLEE_EXT_geometry_shader4;
GLEE_EXTERN GLboolean _GLEE_EXT_bindable_uniform;
GLEE_EXTERN GLboolean _GLEE_EXT_framebuffer_sRGB;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_shared_exponent;
GLEE_EXTERN GLboolean _GLEE_EXT_packed_float;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_array;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_integer;
GLEE_EXTERN GLboolean _GLEE_NV_depth_buffer_float;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_compression_latc;
GLEE_EXTERN GLboolean _GLEE_NV_transform_feedback;
GLEE_EXTERN GLboolean _GLEE_NV_geometry_program4;
GLEE_EXTERN GLboolean _GLEE_NV_gpu_program4;
GLEE_EXTERN GLboolean _GLEE_NV_framebuffer_multisample_coverage;
GLEE_EXTERN GLboolean _GLEE_EXT_framebuffer_multisample;
GLEE_EXTERN GLboolean _GLEE_EXT_framebuffer_blit;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_compression_rgtc;
GLEE_EXTERN GLboolean _GLEE_EXT_color_matrix;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_select;
GLEE_EXTERN GLboolean _GLEE_INGR_blend_func_separate;
GLEE_EXTERN GLboolean _GLEE_SGIX_depth_pass_instrument;
GLEE_EXTERN GLboolean _GLEE_SGIX_igloo_interface;
GLEE_EXTERN GLboolean _GLEE_EXT_draw_buffers2;
GLEE_EXTERN GLboolean _GLEE_NV_parameter_buffer_object;
GLEE_EXTERN GLboolean _GLEE_EXT_draw_instanced;
GLEE_EXTERN GLboolean _GLEE_EXT_fragment_lighting;
GLEE_EXTERN GLboolean _GLEE_EXT_packed_depth_stencil;
GLEE_EXTERN GLboolean _GLEE_EXT_scene_marker;
GLEE_EXTERN GLboolean _GLEE_EXT_stencil_clear_tag;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_compression_dxt1;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_env;
GLEE_EXTERN GLboolean _GLEE_EXT_texture_sRGB;
GLEE_EXTERN GLboolean _GLEE_IBM_static_data;
GLEE_EXTERN GLboolean _GLEE_MESAX_texture_stack;
GLEE_EXTERN GLboolean _GLEE_OES_byte_coordinates;
GLEE_EXTERN GLboolean _GLEE_OES_compressed_paletted_texture;
GLEE_EXTERN GLboolean _GLEE_OES_single_precision;
GLEE_EXTERN GLboolean _GLEE_SGIX_pixel_texture_bits;
GLEE_EXTERN GLboolean _GLEE_SGIX_texture_range;

/* Aliases for extension querying variables */

#define GLEE_VERSION_1_2     GLeeEnabled(&_GLEE_VERSION_1_2)
#define GLEE_ARB_imaging     GLeeEnabled(&_GLEE_ARB_imaging)
#define GLEE_VERSION_1_3     GLeeEnabled(&_GLEE_VERSION_1_3)
#define GLEE_VERSION_1_4     GLeeEnabled(&_GLEE_VERSION_1_4)
#define GLEE_VERSION_1_5     GLeeEnabled(&_GLEE_VERSION_1_5)
#define GLEE_VERSION_2_0     GLeeEnabled(&_GLEE_VERSION_2_0)
#define GLEE_VERSION_2_1     GLeeEnabled(&_GLEE_VERSION_2_1)
#define GLEE_ARB_multitexture     GLeeEnabled(&_GLEE_ARB_multitexture)
#define GLEE_ARB_transpose_matrix     GLeeEnabled(&_GLEE_ARB_transpose_matrix)
#define GLEE_ARB_multisample     GLeeEnabled(&_GLEE_ARB_multisample)
#define GLEE_ARB_texture_env_add     GLeeEnabled(&_GLEE_ARB_texture_env_add)
#define GLEE_ARB_texture_cube_map     GLeeEnabled(&_GLEE_ARB_texture_cube_map)
#define GLEE_ARB_texture_compression     GLeeEnabled(&_GLEE_ARB_texture_compression)
#define GLEE_ARB_texture_border_clamp     GLeeEnabled(&_GLEE_ARB_texture_border_clamp)
#define GLEE_ARB_point_parameters     GLeeEnabled(&_GLEE_ARB_point_parameters)
#define GLEE_ARB_vertex_blend     GLeeEnabled(&_GLEE_ARB_vertex_blend)
#define GLEE_ARB_matrix_palette     GLeeEnabled(&_GLEE_ARB_matrix_palette)
#define GLEE_ARB_texture_env_combine     GLeeEnabled(&_GLEE_ARB_texture_env_combine)
#define GLEE_ARB_texture_env_crossbar     GLeeEnabled(&_GLEE_ARB_texture_env_crossbar)
#define GLEE_ARB_texture_env_dot3     GLeeEnabled(&_GLEE_ARB_texture_env_dot3)
#define GLEE_ARB_texture_mirrored_repeat     GLeeEnabled(&_GLEE_ARB_texture_mirrored_repeat)
#define GLEE_ARB_depth_texture     GLeeEnabled(&_GLEE_ARB_depth_texture)
#define GLEE_ARB_shadow     GLeeEnabled(&_GLEE_ARB_shadow)
#define GLEE_ARB_shadow_ambient     GLeeEnabled(&_GLEE_ARB_shadow_ambient)
#define GLEE_ARB_window_pos     GLeeEnabled(&_GLEE_ARB_window_pos)
#define GLEE_ARB_vertex_program     GLeeEnabled(&_GLEE_ARB_vertex_program)
#define GLEE_ARB_fragment_program     GLeeEnabled(&_GLEE_ARB_fragment_program)
#define GLEE_ARB_vertex_buffer_object     GLeeEnabled(&_GLEE_ARB_vertex_buffer_object)
#define GLEE_ARB_occlusion_query     GLeeEnabled(&_GLEE_ARB_occlusion_query)
#define GLEE_ARB_shader_objects     GLeeEnabled(&_GLEE_ARB_shader_objects)
#define GLEE_ARB_vertex_shader     GLeeEnabled(&_GLEE_ARB_vertex_shader)
#define GLEE_ARB_fragment_shader     GLeeEnabled(&_GLEE_ARB_fragment_shader)
#define GLEE_ARB_shading_language_100     GLeeEnabled(&_GLEE_ARB_shading_language_100)
#define GLEE_ARB_texture_non_power_of_two     GLeeEnabled(&_GLEE_ARB_texture_non_power_of_two)
#define GLEE_ARB_point_sprite     GLeeEnabled(&_GLEE_ARB_point_sprite)
#define GLEE_ARB_fragment_program_shadow     GLeeEnabled(&_GLEE_ARB_fragment_program_shadow)
#define GLEE_ARB_draw_buffers     GLeeEnabled(&_GLEE_ARB_draw_buffers)
#define GLEE_ARB_texture_rectangle     GLeeEnabled(&_GLEE_ARB_texture_rectangle)
#define GLEE_ARB_color_buffer_float     GLeeEnabled(&_GLEE_ARB_color_buffer_float)
#define GLEE_ARB_half_float_pixel     GLeeEnabled(&_GLEE_ARB_half_float_pixel)
#define GLEE_ARB_texture_float     GLeeEnabled(&_GLEE_ARB_texture_float)
#define GLEE_ARB_pixel_buffer_object     GLeeEnabled(&_GLEE_ARB_pixel_buffer_object)
#define GLEE_EXT_abgr     GLeeEnabled(&_GLEE_EXT_abgr)
#define GLEE_EXT_blend_color     GLeeEnabled(&_GLEE_EXT_blend_color)
#define GLEE_EXT_polygon_offset     GLeeEnabled(&_GLEE_EXT_polygon_offset)
#define GLEE_EXT_texture     GLeeEnabled(&_GLEE_EXT_texture)
#define GLEE_EXT_texture3D     GLeeEnabled(&_GLEE_EXT_texture3D)
#define GLEE_SGIS_texture_filter4     GLeeEnabled(&_GLEE_SGIS_texture_filter4)
#define GLEE_EXT_subtexture     GLeeEnabled(&_GLEE_EXT_subtexture)
#define GLEE_EXT_copy_texture     GLeeEnabled(&_GLEE_EXT_copy_texture)
#define GLEE_EXT_histogram     GLeeEnabled(&_GLEE_EXT_histogram)
#define GLEE_EXT_convolution     GLeeEnabled(&_GLEE_EXT_convolution)
#define GLEE_SGI_color_matrix     GLeeEnabled(&_GLEE_SGI_color_matrix)
#define GLEE_SGI_color_table     GLeeEnabled(&_GLEE_SGI_color_table)
#define GLEE_SGIS_pixel_texture     GLeeEnabled(&_GLEE_SGIS_pixel_texture)
#define GLEE_SGIX_pixel_texture     GLeeEnabled(&_GLEE_SGIX_pixel_texture)
#define GLEE_SGIS_texture4D     GLeeEnabled(&_GLEE_SGIS_texture4D)
#define GLEE_SGI_texture_color_table     GLeeEnabled(&_GLEE_SGI_texture_color_table)
#define GLEE_EXT_cmyka     GLeeEnabled(&_GLEE_EXT_cmyka)
#define GLEE_EXT_texture_object     GLeeEnabled(&_GLEE_EXT_texture_object)
#define GLEE_SGIS_detail_texture     GLeeEnabled(&_GLEE_SGIS_detail_texture)
#define GLEE_SGIS_sharpen_texture     GLeeEnabled(&_GLEE_SGIS_sharpen_texture)
#define GLEE_EXT_packed_pixels     GLeeEnabled(&_GLEE_EXT_packed_pixels)
#define GLEE_SGIS_texture_lod     GLeeEnabled(&_GLEE_SGIS_texture_lod)
#define GLEE_SGIS_multisample     GLeeEnabled(&_GLEE_SGIS_multisample)
#define GLEE_EXT_rescale_normal     GLeeEnabled(&_GLEE_EXT_rescale_normal)
#define GLEE_EXT_vertex_array     GLeeEnabled(&_GLEE_EXT_vertex_array)
#define GLEE_EXT_misc_attribute     GLeeEnabled(&_GLEE_EXT_misc_attribute)
#define GLEE_SGIS_generate_mipmap     GLeeEnabled(&_GLEE_SGIS_generate_mipmap)
#define GLEE_SGIX_clipmap     GLeeEnabled(&_GLEE_SGIX_clipmap)
#define GLEE_SGIX_shadow     GLeeEnabled(&_GLEE_SGIX_shadow)
#define GLEE_SGIS_texture_edge_clamp     GLeeEnabled(&_GLEE_SGIS_texture_edge_clamp)
#define GLEE_SGIS_texture_border_clamp     GLeeEnabled(&_GLEE_SGIS_texture_border_clamp)
#define GLEE_EXT_blend_minmax     GLeeEnabled(&_GLEE_EXT_blend_minmax)
#define GLEE_EXT_blend_subtract     GLeeEnabled(&_GLEE_EXT_blend_subtract)
#define GLEE_EXT_blend_logic_op     GLeeEnabled(&_GLEE_EXT_blend_logic_op)
#define GLEE_SGIX_interlace     GLeeEnabled(&_GLEE_SGIX_interlace)
#define GLEE_SGIX_pixel_tiles     GLeeEnabled(&_GLEE_SGIX_pixel_tiles)
#define GLEE_SGIS_texture_select     GLeeEnabled(&_GLEE_SGIS_texture_select)
#define GLEE_SGIX_sprite     GLeeEnabled(&_GLEE_SGIX_sprite)
#define GLEE_SGIX_texture_multi_buffer     GLeeEnabled(&_GLEE_SGIX_texture_multi_buffer)
#define GLEE_EXT_point_parameters     GLeeEnabled(&_GLEE_EXT_point_parameters)
#define GLEE_SGIS_point_parameters     GLeeEnabled(&_GLEE_SGIS_point_parameters)
#define GLEE_SGIX_instruments     GLeeEnabled(&_GLEE_SGIX_instruments)
#define GLEE_SGIX_texture_scale_bias     GLeeEnabled(&_GLEE_SGIX_texture_scale_bias)
#define GLEE_SGIX_framezoom     GLeeEnabled(&_GLEE_SGIX_framezoom)
#define GLEE_SGIX_tag_sample_buffer     GLeeEnabled(&_GLEE_SGIX_tag_sample_buffer)
#define GLEE_FfdMaskSGIX     GLeeEnabled(&_GLEE_FfdMaskSGIX)
#define GLEE_SGIX_polynomial_ffd     GLeeEnabled(&_GLEE_SGIX_polynomial_ffd)
#define GLEE_SGIX_reference_plane     GLeeEnabled(&_GLEE_SGIX_reference_plane)
#define GLEE_SGIX_flush_raster     GLeeEnabled(&_GLEE_SGIX_flush_raster)
#define GLEE_SGIX_depth_texture     GLeeEnabled(&_GLEE_SGIX_depth_texture)
#define GLEE_SGIS_fog_function     GLeeEnabled(&_GLEE_SGIS_fog_function)
#define GLEE_SGIX_fog_offset     GLeeEnabled(&_GLEE_SGIX_fog_offset)
#define GLEE_HP_image_transform     GLeeEnabled(&_GLEE_HP_image_transform)
#define GLEE_HP_convolution_border_modes     GLeeEnabled(&_GLEE_HP_convolution_border_modes)
#define GLEE_INGR_palette_buffer     GLeeEnabled(&_GLEE_INGR_palette_buffer)
#define GLEE_SGIX_texture_add_env     GLeeEnabled(&_GLEE_SGIX_texture_add_env)
#define GLEE_EXT_color_subtable     GLeeEnabled(&_GLEE_EXT_color_subtable)
#define GLEE_PGI_vertex_hints     GLeeEnabled(&_GLEE_PGI_vertex_hints)
#define GLEE_PGI_misc_hints     GLeeEnabled(&_GLEE_PGI_misc_hints)
#define GLEE_EXT_paletted_texture     GLeeEnabled(&_GLEE_EXT_paletted_texture)
#define GLEE_EXT_clip_volume_hint     GLeeEnabled(&_GLEE_EXT_clip_volume_hint)
#define GLEE_SGIX_list_priority     GLeeEnabled(&_GLEE_SGIX_list_priority)
#define GLEE_SGIX_ir_instrument1     GLeeEnabled(&_GLEE_SGIX_ir_instrument1)
#define GLEE_SGIX_calligraphic_fragment     GLeeEnabled(&_GLEE_SGIX_calligraphic_fragment)
#define GLEE_SGIX_texture_lod_bias     GLeeEnabled(&_GLEE_SGIX_texture_lod_bias)
#define GLEE_SGIX_shadow_ambient     GLeeEnabled(&_GLEE_SGIX_shadow_ambient)
#define GLEE_EXT_index_texture     GLeeEnabled(&_GLEE_EXT_index_texture)
#define GLEE_EXT_index_material     GLeeEnabled(&_GLEE_EXT_index_material)
#define GLEE_EXT_index_func     GLeeEnabled(&_GLEE_EXT_index_func)
#define GLEE_EXT_index_array_formats     GLeeEnabled(&_GLEE_EXT_index_array_formats)
#define GLEE_EXT_compiled_vertex_array     GLeeEnabled(&_GLEE_EXT_compiled_vertex_array)
#define GLEE_EXT_cull_vertex     GLeeEnabled(&_GLEE_EXT_cull_vertex)
#define GLEE_SGIX_ycrcb     GLeeEnabled(&_GLEE_SGIX_ycrcb)
#define GLEE_SGIX_fragment_lighting     GLeeEnabled(&_GLEE_SGIX_fragment_lighting)
#define GLEE_IBM_rasterpos_clip     GLeeEnabled(&_GLEE_IBM_rasterpos_clip)
#define GLEE_HP_texture_lighting     GLeeEnabled(&_GLEE_HP_texture_lighting)
#define GLEE_EXT_draw_range_elements     GLeeEnabled(&_GLEE_EXT_draw_range_elements)
#define GLEE_WIN_phong_shading     GLeeEnabled(&_GLEE_WIN_phong_shading)
#define GLEE_WIN_specular_fog     GLeeEnabled(&_GLEE_WIN_specular_fog)
#define GLEE_EXT_light_texture     GLeeEnabled(&_GLEE_EXT_light_texture)
#define GLEE_SGIX_blend_alpha_minmax     GLeeEnabled(&_GLEE_SGIX_blend_alpha_minmax)
#define GLEE_SGIX_impact_pixel_texture     GLeeEnabled(&_GLEE_SGIX_impact_pixel_texture)
#define GLEE_EXT_bgra     GLeeEnabled(&_GLEE_EXT_bgra)
#define GLEE_SGIX_async     GLeeEnabled(&_GLEE_SGIX_async)
#define GLEE_SGIX_async_pixel     GLeeEnabled(&_GLEE_SGIX_async_pixel)
#define GLEE_SGIX_async_histogram     GLeeEnabled(&_GLEE_SGIX_async_histogram)
#define GLEE_INTEL_texture_scissor     GLeeEnabled(&_GLEE_INTEL_texture_scissor)
#define GLEE_INTEL_parallel_arrays     GLeeEnabled(&_GLEE_INTEL_parallel_arrays)
#define GLEE_HP_occlusion_test     GLeeEnabled(&_GLEE_HP_occlusion_test)
#define GLEE_EXT_pixel_transform     GLeeEnabled(&_GLEE_EXT_pixel_transform)
#define GLEE_EXT_pixel_transform_color_table     GLeeEnabled(&_GLEE_EXT_pixel_transform_color_table)
#define GLEE_EXT_shared_texture_palette     GLeeEnabled(&_GLEE_EXT_shared_texture_palette)
#define GLEE_EXT_separate_specular_color     GLeeEnabled(&_GLEE_EXT_separate_specular_color)
#define GLEE_EXT_secondary_color     GLeeEnabled(&_GLEE_EXT_secondary_color)
#define GLEE_EXT_texture_perturb_normal     GLeeEnabled(&_GLEE_EXT_texture_perturb_normal)
#define GLEE_EXT_multi_draw_arrays     GLeeEnabled(&_GLEE_EXT_multi_draw_arrays)
#define GLEE_EXT_fog_coord     GLeeEnabled(&_GLEE_EXT_fog_coord)
#define GLEE_REND_screen_coordinates     GLeeEnabled(&_GLEE_REND_screen_coordinates)
#define GLEE_EXT_coordinate_frame     GLeeEnabled(&_GLEE_EXT_coordinate_frame)
#define GLEE_EXT_texture_env_combine     GLeeEnabled(&_GLEE_EXT_texture_env_combine)
#define GLEE_APPLE_specular_vector     GLeeEnabled(&_GLEE_APPLE_specular_vector)
#define GLEE_APPLE_transform_hint     GLeeEnabled(&_GLEE_APPLE_transform_hint)
#define GLEE_SGIX_fog_scale     GLeeEnabled(&_GLEE_SGIX_fog_scale)
#define GLEE_SUNX_constant_data     GLeeEnabled(&_GLEE_SUNX_constant_data)
#define GLEE_SUN_global_alpha     GLeeEnabled(&_GLEE_SUN_global_alpha)
#define GLEE_SUN_triangle_list     GLeeEnabled(&_GLEE_SUN_triangle_list)
#define GLEE_SUN_vertex     GLeeEnabled(&_GLEE_SUN_vertex)
#define GLEE_EXT_blend_func_separate     GLeeEnabled(&_GLEE_EXT_blend_func_separate)
#define GLEE_INGR_color_clamp     GLeeEnabled(&_GLEE_INGR_color_clamp)
#define GLEE_INGR_interlace_read     GLeeEnabled(&_GLEE_INGR_interlace_read)
#define GLEE_EXT_stencil_wrap     GLeeEnabled(&_GLEE_EXT_stencil_wrap)
#define GLEE_EXT_422_pixels     GLeeEnabled(&_GLEE_EXT_422_pixels)
#define GLEE_NV_texgen_reflection     GLeeEnabled(&_GLEE_NV_texgen_reflection)
#define GLEE_EXT_texture_cube_map     GLeeEnabled(&_GLEE_EXT_texture_cube_map)
#define GLEE_SUN_convolution_border_modes     GLeeEnabled(&_GLEE_SUN_convolution_border_modes)
#define GLEE_EXT_texture_env_add     GLeeEnabled(&_GLEE_EXT_texture_env_add)
#define GLEE_EXT_texture_lod_bias     GLeeEnabled(&_GLEE_EXT_texture_lod_bias)
#define GLEE_EXT_texture_filter_anisotropic     GLeeEnabled(&_GLEE_EXT_texture_filter_anisotropic)
#define GLEE_EXT_vertex_weighting     GLeeEnabled(&_GLEE_EXT_vertex_weighting)
#define GLEE_NV_light_max_exponent     GLeeEnabled(&_GLEE_NV_light_max_exponent)
#define GLEE_NV_vertex_array_range     GLeeEnabled(&_GLEE_NV_vertex_array_range)
#define GLEE_NV_register_combiners     GLeeEnabled(&_GLEE_NV_register_combiners)
#define GLEE_NV_fog_distance     GLeeEnabled(&_GLEE_NV_fog_distance)
#define GLEE_NV_texgen_emboss     GLeeEnabled(&_GLEE_NV_texgen_emboss)
#define GLEE_NV_blend_square     GLeeEnabled(&_GLEE_NV_blend_square)
#define GLEE_NV_texture_env_combine4     GLeeEnabled(&_GLEE_NV_texture_env_combine4)
#define GLEE_MESA_resize_buffers     GLeeEnabled(&_GLEE_MESA_resize_buffers)
#define GLEE_MESA_window_pos     GLeeEnabled(&_GLEE_MESA_window_pos)
#define GLEE_EXT_texture_compression_s3tc     GLeeEnabled(&_GLEE_EXT_texture_compression_s3tc)
#define GLEE_IBM_cull_vertex     GLeeEnabled(&_GLEE_IBM_cull_vertex)
#define GLEE_IBM_multimode_draw_arrays     GLeeEnabled(&_GLEE_IBM_multimode_draw_arrays)
#define GLEE_IBM_vertex_array_lists     GLeeEnabled(&_GLEE_IBM_vertex_array_lists)
#define GLEE_SGIX_subsample     GLeeEnabled(&_GLEE_SGIX_subsample)
#define GLEE_SGIX_ycrcb_subsample     GLeeEnabled(&_GLEE_SGIX_ycrcb_subsample)
#define GLEE_SGIX_ycrcba     GLeeEnabled(&_GLEE_SGIX_ycrcba)
#define GLEE_SGI_depth_pass_instrument     GLeeEnabled(&_GLEE_SGI_depth_pass_instrument)
#define GLEE_3DFX_texture_compression_FXT1     GLeeEnabled(&_GLEE_3DFX_texture_compression_FXT1)
#define GLEE_3DFX_multisample     GLeeEnabled(&_GLEE_3DFX_multisample)
#define GLEE_3DFX_tbuffer     GLeeEnabled(&_GLEE_3DFX_tbuffer)
#define GLEE_EXT_multisample     GLeeEnabled(&_GLEE_EXT_multisample)
#define GLEE_SGIX_vertex_preclip     GLeeEnabled(&_GLEE_SGIX_vertex_preclip)
#define GLEE_SGIX_convolution_accuracy     GLeeEnabled(&_GLEE_SGIX_convolution_accuracy)
#define GLEE_SGIX_resample     GLeeEnabled(&_GLEE_SGIX_resample)
#define GLEE_SGIS_point_line_texgen     GLeeEnabled(&_GLEE_SGIS_point_line_texgen)
#define GLEE_SGIS_texture_color_mask     GLeeEnabled(&_GLEE_SGIS_texture_color_mask)
#define GLEE_EXT_texture_env_dot3     GLeeEnabled(&_GLEE_EXT_texture_env_dot3)
#define GLEE_ATI_texture_mirror_once     GLeeEnabled(&_GLEE_ATI_texture_mirror_once)
#define GLEE_NV_fence     GLeeEnabled(&_GLEE_NV_fence)
#define GLEE_IBM_texture_mirrored_repeat     GLeeEnabled(&_GLEE_IBM_texture_mirrored_repeat)
#define GLEE_NV_evaluators     GLeeEnabled(&_GLEE_NV_evaluators)
#define GLEE_NV_packed_depth_stencil     GLeeEnabled(&_GLEE_NV_packed_depth_stencil)
#define GLEE_NV_register_combiners2     GLeeEnabled(&_GLEE_NV_register_combiners2)
#define GLEE_NV_texture_compression_vtc     GLeeEnabled(&_GLEE_NV_texture_compression_vtc)
#define GLEE_NV_texture_rectangle     GLeeEnabled(&_GLEE_NV_texture_rectangle)
#define GLEE_NV_texture_shader     GLeeEnabled(&_GLEE_NV_texture_shader)
#define GLEE_NV_texture_shader2     GLeeEnabled(&_GLEE_NV_texture_shader2)
#define GLEE_NV_vertex_array_range2     GLeeEnabled(&_GLEE_NV_vertex_array_range2)
#define GLEE_NV_vertex_program     GLeeEnabled(&_GLEE_NV_vertex_program)
#define GLEE_SGIX_texture_coordinate_clamp     GLeeEnabled(&_GLEE_SGIX_texture_coordinate_clamp)
#define GLEE_SGIX_scalebias_hint     GLeeEnabled(&_GLEE_SGIX_scalebias_hint)
#define GLEE_OML_interlace     GLeeEnabled(&_GLEE_OML_interlace)
#define GLEE_OML_subsample     GLeeEnabled(&_GLEE_OML_subsample)
#define GLEE_OML_resample     GLeeEnabled(&_GLEE_OML_resample)
#define GLEE_NV_copy_depth_to_color     GLeeEnabled(&_GLEE_NV_copy_depth_to_color)
#define GLEE_ATI_envmap_bumpmap     GLeeEnabled(&_GLEE_ATI_envmap_bumpmap)
#define GLEE_ATI_fragment_shader     GLeeEnabled(&_GLEE_ATI_fragment_shader)
#define GLEE_ATI_pn_triangles     GLeeEnabled(&_GLEE_ATI_pn_triangles)
#define GLEE_ATI_vertex_array_object     GLeeEnabled(&_GLEE_ATI_vertex_array_object)
#define GLEE_EXT_vertex_shader     GLeeEnabled(&_GLEE_EXT_vertex_shader)
#define GLEE_ATI_vertex_streams     GLeeEnabled(&_GLEE_ATI_vertex_streams)
#define GLEE_ATI_element_array     GLeeEnabled(&_GLEE_ATI_element_array)
#define GLEE_SUN_mesh_array     GLeeEnabled(&_GLEE_SUN_mesh_array)
#define GLEE_SUN_slice_accum     GLeeEnabled(&_GLEE_SUN_slice_accum)
#define GLEE_NV_multisample_filter_hint     GLeeEnabled(&_GLEE_NV_multisample_filter_hint)
#define GLEE_NV_depth_clamp     GLeeEnabled(&_GLEE_NV_depth_clamp)
#define GLEE_NV_occlusion_query     GLeeEnabled(&_GLEE_NV_occlusion_query)
#define GLEE_NV_point_sprite     GLeeEnabled(&_GLEE_NV_point_sprite)
#define GLEE_NV_texture_shader3     GLeeEnabled(&_GLEE_NV_texture_shader3)
#define GLEE_NV_vertex_program1_1     GLeeEnabled(&_GLEE_NV_vertex_program1_1)
#define GLEE_EXT_shadow_funcs     GLeeEnabled(&_GLEE_EXT_shadow_funcs)
#define GLEE_EXT_stencil_two_side     GLeeEnabled(&_GLEE_EXT_stencil_two_side)
#define GLEE_ATI_text_fragment_shader     GLeeEnabled(&_GLEE_ATI_text_fragment_shader)
#define GLEE_APPLE_client_storage     GLeeEnabled(&_GLEE_APPLE_client_storage)
#define GLEE_APPLE_element_array     GLeeEnabled(&_GLEE_APPLE_element_array)
#define GLEE_APPLE_fence     GLeeEnabled(&_GLEE_APPLE_fence)
#define GLEE_APPLE_vertex_array_object     GLeeEnabled(&_GLEE_APPLE_vertex_array_object)
#define GLEE_APPLE_vertex_array_range     GLeeEnabled(&_GLEE_APPLE_vertex_array_range)
#define GLEE_APPLE_ycbcr_422     GLeeEnabled(&_GLEE_APPLE_ycbcr_422)
#define GLEE_S3_s3tc     GLeeEnabled(&_GLEE_S3_s3tc)
#define GLEE_ATI_draw_buffers     GLeeEnabled(&_GLEE_ATI_draw_buffers)
#define GLEE_ATI_pixel_format_float     GLeeEnabled(&_GLEE_ATI_pixel_format_float)
#define GLEE_ATI_texture_env_combine3     GLeeEnabled(&_GLEE_ATI_texture_env_combine3)
#define GLEE_ATI_texture_float     GLeeEnabled(&_GLEE_ATI_texture_float)
#define GLEE_NV_float_buffer     GLeeEnabled(&_GLEE_NV_float_buffer)
#define GLEE_NV_fragment_program     GLeeEnabled(&_GLEE_NV_fragment_program)
#define GLEE_NV_half_float     GLeeEnabled(&_GLEE_NV_half_float)
#define GLEE_NV_pixel_data_range     GLeeEnabled(&_GLEE_NV_pixel_data_range)
#define GLEE_NV_primitive_restart     GLeeEnabled(&_GLEE_NV_primitive_restart)
#define GLEE_NV_texture_expand_normal     GLeeEnabled(&_GLEE_NV_texture_expand_normal)
#define GLEE_NV_vertex_program2     GLeeEnabled(&_GLEE_NV_vertex_program2)
#define GLEE_ATI_map_object_buffer     GLeeEnabled(&_GLEE_ATI_map_object_buffer)
#define GLEE_ATI_separate_stencil     GLeeEnabled(&_GLEE_ATI_separate_stencil)
#define GLEE_ATI_vertex_attrib_array_object     GLeeEnabled(&_GLEE_ATI_vertex_attrib_array_object)
#define GLEE_OES_read_format     GLeeEnabled(&_GLEE_OES_read_format)
#define GLEE_EXT_depth_bounds_test     GLeeEnabled(&_GLEE_EXT_depth_bounds_test)
#define GLEE_EXT_texture_mirror_clamp     GLeeEnabled(&_GLEE_EXT_texture_mirror_clamp)
#define GLEE_EXT_blend_equation_separate     GLeeEnabled(&_GLEE_EXT_blend_equation_separate)
#define GLEE_MESA_pack_invert     GLeeEnabled(&_GLEE_MESA_pack_invert)
#define GLEE_MESA_ycbcr_texture     GLeeEnabled(&_GLEE_MESA_ycbcr_texture)
#define GLEE_EXT_pixel_buffer_object     GLeeEnabled(&_GLEE_EXT_pixel_buffer_object)
#define GLEE_NV_fragment_program_option     GLeeEnabled(&_GLEE_NV_fragment_program_option)
#define GLEE_NV_fragment_program2     GLeeEnabled(&_GLEE_NV_fragment_program2)
#define GLEE_NV_vertex_program2_option     GLeeEnabled(&_GLEE_NV_vertex_program2_option)
#define GLEE_NV_vertex_program3     GLeeEnabled(&_GLEE_NV_vertex_program3)
#define GLEE_EXT_framebuffer_object     GLeeEnabled(&_GLEE_EXT_framebuffer_object)
#define GLEE_GREMEDY_string_marker     GLeeEnabled(&_GLEE_GREMEDY_string_marker)
#define GLEE_EXT_Cg_shader     GLeeEnabled(&_GLEE_EXT_Cg_shader)
#define GLEE_EXT_timer_query     GLeeEnabled(&_GLEE_EXT_timer_query)
#define GLEE_EXT_texture_buffer_object     GLeeEnabled(&_GLEE_EXT_texture_buffer_object)
#define GLEE_EXT_gpu_shader4     GLeeEnabled(&_GLEE_EXT_gpu_shader4)
#define GLEE_EXT_geometry_shader4     GLeeEnabled(&_GLEE_EXT_geometry_shader4)
#define GLEE_EXT_bindable_uniform     GLeeEnabled(&_GLEE_EXT_bindable_uniform)
#define GLEE_EXT_framebuffer_sRGB     GLeeEnabled(&_GLEE_EXT_framebuffer_sRGB)
#define GLEE_EXT_texture_shared_exponent     GLeeEnabled(&_GLEE_EXT_texture_shared_exponent)
#define GLEE_EXT_packed_float     GLeeEnabled(&_GLEE_EXT_packed_float)
#define GLEE_EXT_texture_array     GLeeEnabled(&_GLEE_EXT_texture_array)
#define GLEE_EXT_texture_integer     GLeeEnabled(&_GLEE_EXT_texture_integer)
#define GLEE_NV_depth_buffer_float     GLeeEnabled(&_GLEE_NV_depth_buffer_float)
#define GLEE_EXT_texture_compression_latc     GLeeEnabled(&_GLEE_EXT_texture_compression_latc)
#define GLEE_NV_transform_feedback     GLeeEnabled(&_GLEE_NV_transform_feedback)
#define GLEE_NV_geometry_program4     GLeeEnabled(&_GLEE_NV_geometry_program4)
#define GLEE_NV_gpu_program4     GLeeEnabled(&_GLEE_NV_gpu_program4)
#define GLEE_NV_framebuffer_multisample_coverage     GLeeEnabled(&_GLEE_NV_framebuffer_multisample_coverage)
#define GLEE_EXT_framebuffer_multisample     GLeeEnabled(&_GLEE_EXT_framebuffer_multisample)
#define GLEE_EXT_framebuffer_blit     GLeeEnabled(&_GLEE_EXT_framebuffer_blit)
#define GLEE_EXT_texture_compression_rgtc     GLeeEnabled(&_GLEE_EXT_texture_compression_rgtc)
#define GLEE_EXT_color_matrix     GLeeEnabled(&_GLEE_EXT_color_matrix)
#define GLEE_SGIX_texture_select     GLeeEnabled(&_GLEE_SGIX_texture_select)
#define GLEE_INGR_blend_func_separate     GLeeEnabled(&_GLEE_INGR_blend_func_separate)
#define GLEE_SGIX_depth_pass_instrument     GLeeEnabled(&_GLEE_SGIX_depth_pass_instrument)
#define GLEE_SGIX_igloo_interface     GLeeEnabled(&_GLEE_SGIX_igloo_interface)
#define GLEE_EXT_draw_buffers2     GLeeEnabled(&_GLEE_EXT_draw_buffers2)
#define GLEE_NV_parameter_buffer_object     GLeeEnabled(&_GLEE_NV_parameter_buffer_object)
#define GLEE_EXT_draw_instanced     GLeeEnabled(&_GLEE_EXT_draw_instanced)
#define GLEE_EXT_fragment_lighting     GLeeEnabled(&_GLEE_EXT_fragment_lighting)
#define GLEE_EXT_packed_depth_stencil     GLeeEnabled(&_GLEE_EXT_packed_depth_stencil)
#define GLEE_EXT_scene_marker     GLeeEnabled(&_GLEE_EXT_scene_marker)
#define GLEE_EXT_stencil_clear_tag     GLeeEnabled(&_GLEE_EXT_stencil_clear_tag)
#define GLEE_EXT_texture_compression_dxt1     GLeeEnabled(&_GLEE_EXT_texture_compression_dxt1)
#define GLEE_EXT_texture_env     GLeeEnabled(&_GLEE_EXT_texture_env)
#define GLEE_EXT_texture_sRGB     GLeeEnabled(&_GLEE_EXT_texture_sRGB)
#define GLEE_IBM_static_data     GLeeEnabled(&_GLEE_IBM_static_data)
#define GLEE_MESAX_texture_stack     GLeeEnabled(&_GLEE_MESAX_texture_stack)
#define GLEE_OES_byte_coordinates     GLeeEnabled(&_GLEE_OES_byte_coordinates)
#define GLEE_OES_compressed_paletted_texture     GLeeEnabled(&_GLEE_OES_compressed_paletted_texture)
#define GLEE_OES_single_precision     GLeeEnabled(&_GLEE_OES_single_precision)
#define GLEE_SGIX_pixel_texture_bits     GLeeEnabled(&_GLEE_SGIX_pixel_texture_bits)
#define GLEE_SGIX_texture_range     GLeeEnabled(&_GLEE_SGIX_texture_range)


/*****************************************************************
 * Additional types needed for extensions
 *****************************************************************/

/* Used for GLSL shader text */
#ifndef GL_VERSION_2_0
	typedef char GLchar; 
#endif

#include <stddef.h>

#ifndef GL_VERSION_1_5
	typedef ptrdiff_t GLintptr;
	typedef ptrdiff_t GLsizeiptr;
#endif

#ifndef GL_NV_half_float
	typedef unsigned short GLhalfNV;
#endif

#ifndef GL_ARB_vertex_buffer_object
	typedef ptrdiff_t GLintptrARB;
	typedef ptrdiff_t GLsizeiptrARB;
#endif

#ifndef GL_ARB_shader_objects
	typedef int GLhandleARB;
	typedef char GLcharARB;
#endif

#ifndef GL_EXT_timer_query
	typedef signed long long GLint64EXT;
	typedef unsigned long long GLuint64EXT;
#endif

/* Platform-specific */

#ifdef WIN32    

	/* WGL */

	#ifndef WGL_ARB_pbuffer
	DECLARE_HANDLE(HPBUFFERARB);
	#endif
	#ifndef WGL_EXT_pbuffer
	DECLARE_HANDLE(HPBUFFEREXT);
	#endif

#elif defined(__APPLE__) || defined(__APPLE_CC__)

	/* Mac OS X */

#else          

	/* GLX */

	typedef void (*__GLXextFuncPtr)(void);

	#ifndef GLX_ARB_get_proc_address 
	#define GLX_ARB_get_proc_address 1
	extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *);
	extern void ( * glXGetProcAddressARB (const GLubyte *procName))(void);
	typedef __GLXextFuncPtr ( * PFNGLXGETPROCADDRESSARBPROC) (const GLubyte *procName);
	#endif

	#ifndef GLX_SGIX_fbconfig
	typedef XID GLXFBConfigIDSGIX;
	typedef struct __GLXFBConfigRec *GLXFBConfigSGIX;
	#endif

	#ifndef GLX_SGIX_pbuffer
	typedef XID GLXPbufferSGIX;
	typedef struct {
		int type;
		unsigned long serial;
		Bool send_event;
		Display *display;
		GLXDrawable drawable;
		int event_type;		  
		int draw_type;		  
		unsigned int mask;	  
		int x, y;
		int width, height;
		int count;
	} GLXBufferClobberEventSGIX;
	#endif

	#ifndef GLX_SGIX_hyperpipe
		#define _GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX 80
		typedef struct 
		{
			char  pipeName[_GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
			int  networkId;
		} GLXHyperpipeNetworkSGIX;

		typedef struct 
		{
			char pipeName[_GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
			int channel;
			unsigned int participationType;
			int timeSlice;
		} GLXHyperpipeConfigSGIX;

		typedef struct 
		{
			char pipeName[_GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
			int srcXOrigin;
			int srcYOrigin;
			int srcWidth;
			int srcHeight;
			int destXOrigin;
			int destYOrigin;
			int destWidth;
			int destHeight;
		} GLXPipeRect;

		typedef struct 
		{
			char pipeName[_GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
			int XOrigin; 
			int YOrigin;
			int maxHeight;
			int maxWidth;
		} GLXPipeRectLimits;
	#endif 
#endif /* end platform specific */



/* GL_VERSION_1_2 */

#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
#define __GLEE_GL_VERSION_1_2 1
/* Constants */
#define GL_UNSIGNED_BYTE_3_3_2                             0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4                          0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1                          0x8034
#define GL_UNSIGNED_INT_8_8_8_8                            0x8035
#define GL_UNSIGNED_INT_10_10_10_2                         0x8036
#define GL_RESCALE_NORMAL                                  0x803A
#define GL_TEXTURE_BINDING_3D                              0x806A
#define GL_PACK_SKIP_IMAGES                                0x806B
#define GL_PACK_IMAGE_HEIGHT                               0x806C
#define GL_UNPACK_SKIP_IMAGES                              0x806D
#define GL_UNPACK_IMAGE_HEIGHT                             0x806E
#define GL_TEXTURE_3D                                      0x806F
#define GL_PROXY_TEXTURE_3D                                0x8070
#define GL_TEXTURE_DEPTH                                   0x8071
#define GL_TEXTURE_WRAP_R                                  0x8072
#define GL_MAX_3D_TEXTURE_SIZE                             0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV                         0x8362
#define GL_UNSIGNED_SHORT_5_6_5                            0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV                        0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV                      0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV                      0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV                        0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV                     0x8368
#define GL_BGR                                             0x80E0
#define GL_BGRA                                            0x80E1
#define GL_MAX_ELEMENTS_VERTICES                           0x80E8
#define GL_MAX_ELEMENTS_INDICES                            0x80E9
#define GL_CLAMP_TO_EDGE                                   0x812F
#define GL_TEXTURE_MIN_LOD                                 0x813A
#define GL_TEXTURE_MAX_LOD                                 0x813B
#define GL_TEXTURE_BASE_LEVEL                              0x813C
#define GL_TEXTURE_MAX_LEVEL                               0x813D
#define GL_LIGHT_MODEL_COLOR_CONTROL                       0x81F8
#define GL_SINGLE_COLOR                                    0x81F9
#define GL_SEPARATE_SPECULAR_COLOR                         0x81FA
#define GL_SMOOTH_POINT_SIZE_RANGE                         0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY                   0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE                         0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY                   0x0B23
#define GL_ALIASED_POINT_SIZE_RANGE                        0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE                        0x846E
typedef void (APIENTRYP PFNGLBLENDCOLORPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices);
typedef void (APIENTRYP PFNGLCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table);
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLCOPYCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLGETCOLORTABLEPROC) (GLenum target, GLenum format, GLenum type, GLvoid * table);
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLCOLORSUBTABLEPROC) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOPYCOLORSUBTABLEPROC) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER1DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image);
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER2DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat params);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIPROC) (GLenum target, GLenum pname, GLint params);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER1DPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER2DPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETCONVOLUTIONFILTERPROC) (GLenum target, GLenum format, GLenum type, GLvoid * image);
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETSEPARABLEFILTERPROC) (GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span);
typedef void (APIENTRYP PFNGLSEPARABLEFILTER2DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column);
typedef void (APIENTRYP PFNGLGETHISTOGRAMPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETMINMAXPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLHISTOGRAMPROC) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
typedef void (APIENTRYP PFNGLMINMAXPROC) (GLenum target, GLenum internalformat, GLboolean sink);
typedef void (APIENTRYP PFNGLRESETHISTOGRAMPROC) (GLenum target);
typedef void (APIENTRYP PFNGLRESETMINMAXPROC) (GLenum target);
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLEE_EXTERN PFNGLBLENDCOLORPROC pglBlendColor;
GLEE_EXTERN PFNGLBLENDEQUATIONPROC pglBlendEquation;
GLEE_EXTERN PFNGLDRAWRANGEELEMENTSPROC pglDrawRangeElements;
GLEE_EXTERN PFNGLCOLORTABLEPROC pglColorTable;
GLEE_EXTERN PFNGLCOLORTABLEPARAMETERFVPROC pglColorTableParameterfv;
GLEE_EXTERN PFNGLCOLORTABLEPARAMETERIVPROC pglColorTableParameteriv;
GLEE_EXTERN PFNGLCOPYCOLORTABLEPROC pglCopyColorTable;
GLEE_EXTERN PFNGLGETCOLORTABLEPROC pglGetColorTable;
GLEE_EXTERN PFNGLGETCOLORTABLEPARAMETERFVPROC pglGetColorTableParameterfv;
GLEE_EXTERN PFNGLGETCOLORTABLEPARAMETERIVPROC pglGetColorTableParameteriv;
GLEE_EXTERN PFNGLCOLORSUBTABLEPROC pglColorSubTable;
GLEE_EXTERN PFNGLCOPYCOLORSUBTABLEPROC pglCopyColorSubTable;
GLEE_EXTERN PFNGLCONVOLUTIONFILTER1DPROC pglConvolutionFilter1D;
GLEE_EXTERN PFNGLCONVOLUTIONFILTER2DPROC pglConvolutionFilter2D;
GLEE_EXTERN PFNGLCONVOLUTIONPARAMETERFPROC pglConvolutionParameterf;
GLEE_EXTERN PFNGLCONVOLUTIONPARAMETERFVPROC pglConvolutionParameterfv;
GLEE_EXTERN PFNGLCONVOLUTIONPARAMETERIPROC pglConvolutionParameteri;
GLEE_EXTERN PFNGLCONVOLUTIONPARAMETERIVPROC pglConvolutionParameteriv;
GLEE_EXTERN PFNGLCOPYCONVOLUTIONFILTER1DPROC pglCopyConvolutionFilter1D;
GLEE_EXTERN PFNGLCOPYCONVOLUTIONFILTER2DPROC pglCopyConvolutionFilter2D;
GLEE_EXTERN PFNGLGETCONVOLUTIONFILTERPROC pglGetConvolutionFilter;
GLEE_EXTERN PFNGLGETCONVOLUTIONPARAMETERFVPROC pglGetConvolutionParameterfv;
GLEE_EXTERN PFNGLGETCONVOLUTIONPARAMETERIVPROC pglGetConvolutionParameteriv;
GLEE_EXTERN PFNGLGETSEPARABLEFILTERPROC pglGetSeparableFilter;
GLEE_EXTERN PFNGLSEPARABLEFILTER2DPROC pglSeparableFilter2D;
GLEE_EXTERN PFNGLGETHISTOGRAMPROC pglGetHistogram;
GLEE_EXTERN PFNGLGETHISTOGRAMPARAMETERFVPROC pglGetHistogramParameterfv;
GLEE_EXTERN PFNGLGETHISTOGRAMPARAMETERIVPROC pglGetHistogramParameteriv;
GLEE_EXTERN PFNGLGETMINMAXPROC pglGetMinmax;
GLEE_EXTERN PFNGLGETMINMAXPARAMETERFVPROC pglGetMinmaxParameterfv;
GLEE_EXTERN PFNGLGETMINMAXPARAMETERIVPROC pglGetMinmaxParameteriv;
GLEE_EXTERN PFNGLHISTOGRAMPROC pglHistogram;
GLEE_EXTERN PFNGLMINMAXPROC pglMinmax;
GLEE_EXTERN PFNGLRESETHISTOGRAMPROC pglResetHistogram;
GLEE_EXTERN PFNGLRESETMINMAXPROC pglResetMinmax;
GLEE_EXTERN PFNGLTEXIMAGE3DPROC pglTexImage3D;
GLEE_EXTERN PFNGLTEXSUBIMAGE3DPROC pglTexSubImage3D;
GLEE_EXTERN PFNGLCOPYTEXSUBIMAGE3DPROC pglCopyTexSubImage3D;
#define glBlendColor pglBlendColor
#define glBlendEquation pglBlendEquation
#define glDrawRangeElements pglDrawRangeElements
#define glColorTable pglColorTable
#define glColorTableParameterfv pglColorTableParameterfv
#define glColorTableParameteriv pglColorTableParameteriv
#define glCopyColorTable pglCopyColorTable
#define glGetColorTable pglGetColorTable
#define glGetColorTableParameterfv pglGetColorTableParameterfv
#define glGetColorTableParameteriv pglGetColorTableParameteriv
#define glColorSubTable pglColorSubTable
#define glCopyColorSubTable pglCopyColorSubTable
#define glConvolutionFilter1D pglConvolutionFilter1D
#define glConvolutionFilter2D pglConvolutionFilter2D
#define glConvolutionParameterf pglConvolutionParameterf
#define glConvolutionParameterfv pglConvolutionParameterfv
#define glConvolutionParameteri pglConvolutionParameteri
#define glConvolutionParameteriv pglConvolutionParameteriv
#define glCopyConvolutionFilter1D pglCopyConvolutionFilter1D
#define glCopyConvolutionFilter2D pglCopyConvolutionFilter2D
#define glGetConvolutionFilter pglGetConvolutionFilter
#define glGetConvolutionParameterfv pglGetConvolutionParameterfv
#define glGetConvolutionParameteriv pglGetConvolutionParameteriv
#define glGetSeparableFilter pglGetSeparableFilter
#define glSeparableFilter2D pglSeparableFilter2D
#define glGetHistogram pglGetHistogram
#define glGetHistogramParameterfv pglGetHistogramParameterfv
#define glGetHistogramParameteriv pglGetHistogramParameteriv
#define glGetMinmax pglGetMinmax
#define glGetMinmaxParameterfv pglGetMinmaxParameterfv
#define glGetMinmaxParameteriv pglGetMinmaxParameteriv
#define glHistogram pglHistogram
#define glMinmax pglMinmax
#define glResetHistogram pglResetHistogram
#define glResetMinmax pglResetMinmax
#define glTexImage3D pglTexImage3D
#define glTexSubImage3D pglTexSubImage3D
#define glCopyTexSubImage3D pglCopyTexSubImage3D
#endif 

/* GL_ARB_imaging */

#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#define __GLEE_GL_ARB_imaging 1
/* Constants */
#define GL_CONSTANT_COLOR                                  0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR                        0x8002
#define GL_CONSTANT_ALPHA                                  0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA                        0x8004
#define GL_BLEND_COLOR                                     0x8005
#define GL_FUNC_ADD                                        0x8006
#define GL_MIN                                             0x8007
#define GL_MAX                                             0x8008
#define GL_BLEND_EQUATION                                  0x8009
#define GL_FUNC_SUBTRACT                                   0x800A
#define GL_FUNC_REVERSE_SUBTRACT                           0x800B
#define GL_CONVOLUTION_1D                                  0x8010
#define GL_CONVOLUTION_2D                                  0x8011
#define GL_SEPARABLE_2D                                    0x8012
#define GL_CONVOLUTION_BORDER_MODE                         0x8013
#define GL_CONVOLUTION_FILTER_SCALE                        0x8014
#define GL_CONVOLUTION_FILTER_BIAS                         0x8015
#define GL_REDUCE                                          0x8016
#define GL_CONVOLUTION_FORMAT                              0x8017
#define GL_CONVOLUTION_WIDTH                               0x8018
#define GL_CONVOLUTION_HEIGHT                              0x8019
#define GL_MAX_CONVOLUTION_WIDTH                           0x801A
#define GL_MAX_CONVOLUTION_HEIGHT                          0x801B
#define GL_POST_CONVOLUTION_RED_SCALE                      0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE                    0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE                     0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE                    0x801F
#define GL_POST_CONVOLUTION_RED_BIAS                       0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS                     0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS                      0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS                     0x8023
#define GL_HISTOGRAM                                       0x8024
#define GL_PROXY_HISTOGRAM                                 0x8025
#define GL_HISTOGRAM_WIDTH                                 0x8026
#define GL_HISTOGRAM_FORMAT                                0x8027
#define GL_HISTOGRAM_RED_SIZE                              0x8028
#define GL_HISTOGRAM_GREEN_SIZE                            0x8029
#define GL_HISTOGRAM_BLUE_SIZE                             0x802A
#define GL_HISTOGRAM_ALPHA_SIZE                            0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE                        0x802C
#define GL_HISTOGRAM_SINK                                  0x802D
#define GL_MINMAX                                          0x802E
#define GL_MINMAX_FORMAT                                   0x802F
#define GL_MINMAX_SINK                                     0x8030
#define GL_TABLE_TOO_LARGE                                 0x8031
#define GL_COLOR_MATRIX                                    0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH                        0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH                    0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE                     0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE                   0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE                    0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE                   0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS                      0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS                    0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS                     0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS                    0x80BB
#define GL_COLOR_TABLE                                     0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE                    0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE                   0x80D2
#define GL_PROXY_COLOR_TABLE                               0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE              0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE             0x80D5
#define GL_COLOR_TABLE_SCALE                               0x80D6
#define GL_COLOR_TABLE_BIAS                                0x80D7
#define GL_COLOR_TABLE_FORMAT                              0x80D8
#define GL_COLOR_TABLE_WIDTH                               0x80D9
#define GL_COLOR_TABLE_RED_SIZE                            0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE                          0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE                           0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE                          0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE                      0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE                      0x80DF
#define GL_CONSTANT_BORDER                                 0x8151
#define GL_REPLICATE_BORDER                                0x8153
#define GL_CONVOLUTION_BORDER_COLOR                        0x8154
#endif 

/* GL_VERSION_1_3 */

#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#define __GLEE_GL_VERSION_1_3 1
/* Constants */
#define GL_TEXTURE0                                        0x84C0
#define GL_TEXTURE1                                        0x84C1
#define GL_TEXTURE2                                        0x84C2
#define GL_TEXTURE3                                        0x84C3
#define GL_TEXTURE4                                        0x84C4
#define GL_TEXTURE5                                        0x84C5
#define GL_TEXTURE6                                        0x84C6
#define GL_TEXTURE7                                        0x84C7
#define GL_TEXTURE8                                        0x84C8
#define GL_TEXTURE9                                        0x84C9
#define GL_TEXTURE10                                       0x84CA
#define GL_TEXTURE11                                       0x84CB
#define GL_TEXTURE12                                       0x84CC
#define GL_TEXTURE13                                       0x84CD
#define GL_TEXTURE14                                       0x84CE
#define GL_TEXTURE15                                       0x84CF
#define GL_TEXTURE16                                       0x84D0
#define GL_TEXTURE17                                       0x84D1
#define GL_TEXTURE18                                       0x84D2
#define GL_TEXTURE19                                       0x84D3
#define GL_TEXTURE20                                       0x84D4
#define GL_TEXTURE21                                       0x84D5
#define GL_TEXTURE22                                       0x84D6
#define GL_TEXTURE23                                       0x84D7
#define GL_TEXTURE24                                       0x84D8
#define GL_TEXTURE25                                       0x84D9
#define GL_TEXTURE26                                       0x84DA
#define GL_TEXTURE27                                       0x84DB
#define GL_TEXTURE28                                       0x84DC
#define GL_TEXTURE29                                       0x84DD
#define GL_TEXTURE30                                       0x84DE
#define GL_TEXTURE31                                       0x84DF
#define GL_ACTIVE_TEXTURE                                  0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE                           0x84E1
#define GL_MAX_TEXTURE_UNITS                               0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX                      0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX                     0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX                        0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX                          0x84E6
#define GL_MULTISAMPLE                                     0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE                        0x809E
#define GL_SAMPLE_ALPHA_TO_ONE                             0x809F
#define GL_SAMPLE_COVERAGE                                 0x80A0
#define GL_SAMPLE_BUFFERS                                  0x80A8
#define GL_SAMPLES                                         0x80A9
#define GL_SAMPLE_COVERAGE_VALUE                           0x80AA
#define GL_SAMPLE_COVERAGE_INVERT                          0x80AB
#define GL_MULTISAMPLE_BIT                                 0x20000000
#define GL_NORMAL_MAP                                      0x8511
#define GL_REFLECTION_MAP                                  0x8512
#define GL_TEXTURE_CUBE_MAP                                0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP                        0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X                     0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X                     0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y                     0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y                     0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z                     0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z                     0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP                          0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE                       0x851C
#define GL_COMPRESSED_ALPHA                                0x84E9
#define GL_COMPRESSED_LUMINANCE                            0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA                      0x84EB
#define GL_COMPRESSED_INTENSITY                            0x84EC
#define GL_COMPRESSED_RGB                                  0x84ED
#define GL_COMPRESSED_RGBA                                 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT                        0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE                   0x86A0
#define GL_TEXTURE_COMPRESSED                              0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS                  0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS                      0x86A3
#define GL_CLAMP_TO_BORDER                                 0x812D
#define GL_COMBINE                                         0x8570
#define GL_COMBINE_RGB                                     0x8571
#define GL_COMBINE_ALPHA                                   0x8572
#define GL_SOURCE0_RGB                                     0x8580
#define GL_SOURCE1_RGB                                     0x8581
#define GL_SOURCE2_RGB                                     0x8582
#define GL_SOURCE0_ALPHA                                   0x8588
#define GL_SOURCE1_ALPHA                                   0x8589
#define GL_SOURCE2_ALPHA                                   0x858A
#define GL_OPERAND0_RGB                                    0x8590
#define GL_OPERAND1_RGB                                    0x8591
#define GL_OPERAND2_RGB                                    0x8592
#define GL_OPERAND0_ALPHA                                  0x8598
#define GL_OPERAND1_ALPHA                                  0x8599
#define GL_OPERAND2_ALPHA                                  0x859A
#define GL_RGB_SCALE                                       0x8573
#define GL_ADD_SIGNED                                      0x8574
#define GL_INTERPOLATE                                     0x8575
#define GL_SUBTRACT                                        0x84E7
#define GL_CONSTANT                                        0x8576
#define GL_PRIMARY_COLOR                                   0x8577
#define GL_PREVIOUS                                        0x8578
#define GL_DOT3_RGB                                        0x86AE
#define GL_DOT3_RGBA                                       0x86AF
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DPROC) (GLenum target, GLdouble s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVPROC) (GLenum target, const GLdouble * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FPROC) (GLenum target, GLfloat s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVPROC) (GLenum target, const GLfloat * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IPROC) (GLenum target, GLint s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVPROC) (GLenum target, const GLint * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SPROC) (GLenum target, GLshort s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVPROC) (GLenum target, const GLshort * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DPROC) (GLenum target, GLdouble s, GLdouble t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVPROC) (GLenum target, const GLdouble * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FPROC) (GLenum target, GLfloat s, GLfloat t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVPROC) (GLenum target, const GLfloat * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IPROC) (GLenum target, GLint s, GLint t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVPROC) (GLenum target, const GLint * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SPROC) (GLenum target, GLshort s, GLshort t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVPROC) (GLenum target, const GLshort * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVPROC) (GLenum target, const GLdouble * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVPROC) (GLenum target, const GLfloat * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IPROC) (GLenum target, GLint s, GLint t, GLint r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVPROC) (GLenum target, const GLint * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVPROC) (GLenum target, const GLshort * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVPROC) (GLenum target, const GLdouble * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVPROC) (GLenum target, const GLfloat * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVPROC) (GLenum target, const GLint * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVPROC) (GLenum target, const GLshort * v);
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFPROC) (const GLfloat * m);
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDPROC) (const GLdouble * m);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFPROC) (const GLfloat * m);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDPROC) (const GLdouble * m);
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC) (GLclampf value, GLboolean invert);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint level, GLvoid * img);
GLEE_EXTERN PFNGLACTIVETEXTUREPROC pglActiveTexture;
GLEE_EXTERN PFNGLCLIENTACTIVETEXTUREPROC pglClientActiveTexture;
GLEE_EXTERN PFNGLMULTITEXCOORD1DPROC pglMultiTexCoord1d;
GLEE_EXTERN PFNGLMULTITEXCOORD1DVPROC pglMultiTexCoord1dv;
GLEE_EXTERN PFNGLMULTITEXCOORD1FPROC pglMultiTexCoord1f;
GLEE_EXTERN PFNGLMULTITEXCOORD1FVPROC pglMultiTexCoord1fv;
GLEE_EXTERN PFNGLMULTITEXCOORD1IPROC pglMultiTexCoord1i;
GLEE_EXTERN PFNGLMULTITEXCOORD1IVPROC pglMultiTexCoord1iv;
GLEE_EXTERN PFNGLMULTITEXCOORD1SPROC pglMultiTexCoord1s;
GLEE_EXTERN PFNGLMULTITEXCOORD1SVPROC pglMultiTexCoord1sv;
GLEE_EXTERN PFNGLMULTITEXCOORD2DPROC pglMultiTexCoord2d;
GLEE_EXTERN PFNGLMULTITEXCOORD2DVPROC pglMultiTexCoord2dv;
GLEE_EXTERN PFNGLMULTITEXCOORD2FPROC pglMultiTexCoord2f;
GLEE_EXTERN PFNGLMULTITEXCOORD2FVPROC pglMultiTexCoord2fv;
GLEE_EXTERN PFNGLMULTITEXCOORD2IPROC pglMultiTexCoord2i;
GLEE_EXTERN PFNGLMULTITEXCOORD2IVPROC pglMultiTexCoord2iv;
GLEE_EXTERN PFNGLMULTITEXCOORD2SPROC pglMultiTexCoord2s;
GLEE_EXTERN PFNGLMULTITEXCOORD2SVPROC pglMultiTexCoord2sv;
GLEE_EXTERN PFNGLMULTITEXCOORD3DPROC pglMultiTexCoord3d;
GLEE_EXTERN PFNGLMULTITEXCOORD3DVPROC pglMultiTexCoord3dv;
GLEE_EXTERN PFNGLMULTITEXCOORD3FPROC pglMultiTexCoord3f;
GLEE_EXTERN PFNGLMULTITEXCOORD3FVPROC pglMultiTexCoord3fv;
GLEE_EXTERN PFNGLMULTITEXCOORD3IPROC pglMultiTexCoord3i;
GLEE_EXTERN PFNGLMULTITEXCOORD3IVPROC pglMultiTexCoord3iv;
GLEE_EXTERN PFNGLMULTITEXCOORD3SPROC pglMultiTexCoord3s;
GLEE_EXTERN PFNGLMULTITEXCOORD3SVPROC pglMultiTexCoord3sv;
GLEE_EXTERN PFNGLMULTITEXCOORD4DPROC pglMultiTexCoord4d;
GLEE_EXTERN PFNGLMULTITEXCOORD4DVPROC pglMultiTexCoord4dv;
GLEE_EXTERN PFNGLMULTITEXCOORD4FPROC pglMultiTexCoord4f;
GLEE_EXTERN PFNGLMULTITEXCOORD4FVPROC pglMultiTexCoord4fv;
GLEE_EXTERN PFNGLMULTITEXCOORD4IPROC pglMultiTexCoord4i;
GLEE_EXTERN PFNGLMULTITEXCOORD4IVPROC pglMultiTexCoord4iv;
GLEE_EXTERN PFNGLMULTITEXCOORD4SPROC pglMultiTexCoord4s;
GLEE_EXTERN PFNGLMULTITEXCOORD4SVPROC pglMultiTexCoord4sv;
GLEE_EXTERN PFNGLLOADTRANSPOSEMATRIXFPROC pglLoadTransposeMatrixf;
GLEE_EXTERN PFNGLLOADTRANSPOSEMATRIXDPROC pglLoadTransposeMatrixd;
GLEE_EXTERN PFNGLMULTTRANSPOSEMATRIXFPROC pglMultTransposeMatrixf;
GLEE_EXTERN PFNGLMULTTRANSPOSEMATRIXDPROC pglMultTransposeMatrixd;
GLEE_EXTERN PFNGLSAMPLECOVERAGEPROC pglSampleCoverage;
GLEE_EXTERN PFNGLCOMPRESSEDTEXIMAGE3DPROC pglCompressedTexImage3D;
GLEE_EXTERN PFNGLCOMPRESSEDTEXIMAGE2DPROC pglCompressedTexImage2D;
GLEE_EXTERN PFNGLCOMPRESSEDTEXIMAGE1DPROC pglCompressedTexImage1D;
GLEE_EXTERN PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC pglCompressedTexSubImage3D;
GLEE_EXTERN PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC pglCompressedTexSubImage2D;
GLEE_EXTERN PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC pglCompressedTexSubImage1D;
GLEE_EXTERN PFNGLGETCOMPRESSEDTEXIMAGEPROC pglGetCompressedTexImage;
#define glActiveTexture pglActiveTexture
#define glClientActiveTexture pglClientActiveTexture
#define glMultiTexCoord1d pglMultiTexCoord1d
#define glMultiTexCoord1dv pglMultiTexCoord1dv
#define glMultiTexCoord1f pglMultiTexCoord1f
#define glMultiTexCoord1fv pglMultiTexCoord1fv
#define glMultiTexCoord1i pglMultiTexCoord1i
#define glMultiTexCoord1iv pglMultiTexCoord1iv
#define glMultiTexCoord1s pglMultiTexCoord1s
#define glMultiTexCoord1sv pglMultiTexCoord1sv
#define glMultiTexCoord2d pglMultiTexCoord2d
#define glMultiTexCoord2dv pglMultiTexCoord2dv
#define glMultiTexCoord2f pglMultiTexCoord2f
#define glMultiTexCoord2fv pglMultiTexCoord2fv
#define glMultiTexCoord2i pglMultiTexCoord2i
#define glMultiTexCoord2iv pglMultiTexCoord2iv
#define glMultiTexCoord2s pglMultiTexCoord2s
#define glMultiTexCoord2sv pglMultiTexCoord2sv
#define glMultiTexCoord3d pglMultiTexCoord3d
#define glMultiTexCoord3dv pglMultiTexCoord3dv
#define glMultiTexCoord3f pglMultiTexCoord3f
#define glMultiTexCoord3fv pglMultiTexCoord3fv
#define glMultiTexCoord3i pglMultiTexCoord3i
#define glMultiTexCoord3iv pglMultiTexCoord3iv
#define glMultiTexCoord3s pglMultiTexCoord3s
#define glMultiTexCoord3sv pglMultiTexCoord3sv
#define glMultiTexCoord4d pglMultiTexCoord4d
#define glMultiTexCoord4dv pglMultiTexCoord4dv
#define glMultiTexCoord4f pglMultiTexCoord4f
#define glMultiTexCoord4fv pglMultiTexCoord4fv
#define glMultiTexCoord4i pglMultiTexCoord4i
#define glMultiTexCoord4iv pglMultiTexCoord4iv
#define glMultiTexCoord4s pglMultiTexCoord4s
#define glMultiTexCoord4sv pglMultiTexCoord4sv
#define glLoadTransposeMatrixf pglLoadTransposeMatrixf
#define glLoadTransposeMatrixd pglLoadTransposeMatrixd
#define glMultTransposeMatrixf pglMultTransposeMatrixf
#define glMultTransposeMatrixd pglMultTransposeMatrixd
#define glSampleCoverage pglSampleCoverage
#define glCompressedTexImage3D pglCompressedTexImage3D
#define glCompressedTexImage2D pglCompressedTexImage2D
#define glCompressedTexImage1D pglCompressedTexImage1D
#define glCompressedTexSubImage3D pglCompressedTexSubImage3D
#define glCompressedTexSubImage2D pglCompressedTexSubImage2D
#define glCompressedTexSubImage1D pglCompressedTexSubImage1D
#define glGetCompressedTexImage pglGetCompressedTexImage
#endif 

/* GL_VERSION_1_4 */

#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
#define __GLEE_GL_VERSION_1_4 1
/* Constants */
#define GL_BLEND_DST_RGB                                   0x80C8
#define GL_BLEND_SRC_RGB                                   0x80C9
#define GL_BLEND_DST_ALPHA                                 0x80CA
#define GL_BLEND_SRC_ALPHA                                 0x80CB
#define GL_POINT_SIZE_MIN                                  0x8126
#define GL_POINT_SIZE_MAX                                  0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE                       0x8128
#define GL_POINT_DISTANCE_ATTENUATION                      0x8129
#define GL_GENERATE_MIPMAP                                 0x8191
#define GL_GENERATE_MIPMAP_HINT                            0x8192
#define GL_DEPTH_COMPONENT16                               0x81A5
#define GL_DEPTH_COMPONENT24                               0x81A6
#define GL_DEPTH_COMPONENT32                               0x81A7
#define GL_MIRRORED_REPEAT                                 0x8370
#define GL_FOG_COORDINATE_SOURCE                           0x8450
#define GL_FOG_COORDINATE                                  0x8451
#define GL_FRAGMENT_DEPTH                                  0x8452
#define GL_CURRENT_FOG_COORDINATE                          0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE                       0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE                     0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER                    0x8456
#define GL_FOG_COORDINATE_ARRAY                            0x8457
#define GL_COLOR_SUM                                       0x8458
#define GL_CURRENT_SECONDARY_COLOR                         0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE                      0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE                      0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE                    0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER                   0x845D
#define GL_SECONDARY_COLOR_ARRAY                           0x845E
#define GL_MAX_TEXTURE_LOD_BIAS                            0x84FD
#define GL_TEXTURE_FILTER_CONTROL                          0x8500
#define GL_TEXTURE_LOD_BIAS                                0x8501
#define GL_INCR_WRAP                                       0x8507
#define GL_DECR_WRAP                                       0x8508
#define GL_TEXTURE_DEPTH_SIZE                              0x884A
#define GL_DEPTH_TEXTURE_MODE                              0x884B
#define GL_TEXTURE_COMPARE_MODE                            0x884C
#define GL_TEXTURE_COMPARE_FUNC                            0x884D
#define GL_COMPARE_R_TO_TEXTURE                            0x884E
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLFOGCOORDFPROC) (GLfloat coord);
typedef void (APIENTRYP PFNGLFOGCOORDFVPROC) (const GLfloat * coord);
typedef void (APIENTRYP PFNGLFOGCOORDDPROC) (GLdouble coord);
typedef void (APIENTRYP PFNGLFOGCOORDDVPROC) (const GLdouble * coord);
typedef void (APIENTRYP PFNGLFOGCOORDPOINTERPROC) (GLenum type, GLsizei stride, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, GLint * first, GLsizei * count, GLsizei primcount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei * count, GLenum type, const GLvoid* * indices, GLsizei primcount);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BPROC) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVPROC) (const GLbyte * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DPROC) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FPROC) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IPROC) (GLint red, GLint green, GLint blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SPROC) (GLshort red, GLshort green, GLshort blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVPROC) (const GLshort * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBPROC) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVPROC) (const GLubyte * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIPROC) (GLuint red, GLuint green, GLuint blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVPROC) (const GLuint * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USPROC) (GLushort red, GLushort green, GLushort blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVPROC) (const GLushort * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLWINDOWPOS2DPROC) (GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLWINDOWPOS2DVPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLWINDOWPOS2FPROC) (GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLWINDOWPOS2FVPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLWINDOWPOS2IPROC) (GLint x, GLint y);
typedef void (APIENTRYP PFNGLWINDOWPOS2IVPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLWINDOWPOS2SPROC) (GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLWINDOWPOS2SVPROC) (const GLshort * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3DPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLWINDOWPOS3DVPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3FPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLWINDOWPOS3FVPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3IPROC) (GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLWINDOWPOS3IVPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3SPROC) (GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLWINDOWPOS3SVPROC) (const GLshort * v);
GLEE_EXTERN PFNGLBLENDFUNCSEPARATEPROC pglBlendFuncSeparate;
GLEE_EXTERN PFNGLFOGCOORDFPROC pglFogCoordf;
GLEE_EXTERN PFNGLFOGCOORDFVPROC pglFogCoordfv;
GLEE_EXTERN PFNGLFOGCOORDDPROC pglFogCoordd;
GLEE_EXTERN PFNGLFOGCOORDDVPROC pglFogCoorddv;
GLEE_EXTERN PFNGLFOGCOORDPOINTERPROC pglFogCoordPointer;
GLEE_EXTERN PFNGLMULTIDRAWARRAYSPROC pglMultiDrawArrays;
GLEE_EXTERN PFNGLMULTIDRAWELEMENTSPROC pglMultiDrawElements;
GLEE_EXTERN PFNGLPOINTPARAMETERFPROC pglPointParameterf;
GLEE_EXTERN PFNGLPOINTPARAMETERFVPROC pglPointParameterfv;
GLEE_EXTERN PFNGLPOINTPARAMETERIPROC pglPointParameteri;
GLEE_EXTERN PFNGLPOINTPARAMETERIVPROC pglPointParameteriv;
GLEE_EXTERN PFNGLSECONDARYCOLOR3BPROC pglSecondaryColor3b;
GLEE_EXTERN PFNGLSECONDARYCOLOR3BVPROC pglSecondaryColor3bv;
GLEE_EXTERN PFNGLSECONDARYCOLOR3DPROC pglSecondaryColor3d;
GLEE_EXTERN PFNGLSECONDARYCOLOR3DVPROC pglSecondaryColor3dv;
GLEE_EXTERN PFNGLSECONDARYCOLOR3FPROC pglSecondaryColor3f;
GLEE_EXTERN PFNGLSECONDARYCOLOR3FVPROC pglSecondaryColor3fv;
GLEE_EXTERN PFNGLSECONDARYCOLOR3IPROC pglSecondaryColor3i;
GLEE_EXTERN PFNGLSECONDARYCOLOR3IVPROC pglSecondaryColor3iv;
GLEE_EXTERN PFNGLSECONDARYCOLOR3SPROC pglSecondaryColor3s;
GLEE_EXTERN PFNGLSECONDARYCOLOR3SVPROC pglSecondaryColor3sv;
GLEE_EXTERN PFNGLSECONDARYCOLOR3UBPROC pglSecondaryColor3ub;
GLEE_EXTERN PFNGLSECONDARYCOLOR3UBVPROC pglSecondaryColor3ubv;
GLEE_EXTERN PFNGLSECONDARYCOLOR3UIPROC pglSecondaryColor3ui;
GLEE_EXTERN PFNGLSECONDARYCOLOR3UIVPROC pglSecondaryColor3uiv;
GLEE_EXTERN PFNGLSECONDARYCOLOR3USPROC pglSecondaryColor3us;
GLEE_EXTERN PFNGLSECONDARYCOLOR3USVPROC pglSecondaryColor3usv;
GLEE_EXTERN PFNGLSECONDARYCOLORPOINTERPROC pglSecondaryColorPointer;
GLEE_EXTERN PFNGLWINDOWPOS2DPROC pglWindowPos2d;
GLEE_EXTERN PFNGLWINDOWPOS2DVPROC pglWindowPos2dv;
GLEE_EXTERN PFNGLWINDOWPOS2FPROC pglWindowPos2f;
GLEE_EXTERN PFNGLWINDOWPOS2FVPROC pglWindowPos2fv;
GLEE_EXTERN PFNGLWINDOWPOS2IPROC pglWindowPos2i;
GLEE_EXTERN PFNGLWINDOWPOS2IVPROC pglWindowPos2iv;
GLEE_EXTERN PFNGLWINDOWPOS2SPROC pglWindowPos2s;
GLEE_EXTERN PFNGLWINDOWPOS2SVPROC pglWindowPos2sv;
GLEE_EXTERN PFNGLWINDOWPOS3DPROC pglWindowPos3d;
GLEE_EXTERN PFNGLWINDOWPOS3DVPROC pglWindowPos3dv;
GLEE_EXTERN PFNGLWINDOWPOS3FPROC pglWindowPos3f;
GLEE_EXTERN PFNGLWINDOWPOS3FVPROC pglWindowPos3fv;
GLEE_EXTERN PFNGLWINDOWPOS3IPROC pglWindowPos3i;
GLEE_EXTERN PFNGLWINDOWPOS3IVPROC pglWindowPos3iv;
GLEE_EXTERN PFNGLWINDOWPOS3SPROC pglWindowPos3s;
GLEE_EXTERN PFNGLWINDOWPOS3SVPROC pglWindowPos3sv;
#define glBlendFuncSeparate pglBlendFuncSeparate
#define glFogCoordf pglFogCoordf
#define glFogCoordfv pglFogCoordfv
#define glFogCoordd pglFogCoordd
#define glFogCoorddv pglFogCoorddv
#define glFogCoordPointer pglFogCoordPointer
#define glMultiDrawArrays pglMultiDrawArrays
#define glMultiDrawElements pglMultiDrawElements
#define glPointParameterf pglPointParameterf
#define glPointParameterfv pglPointParameterfv
#define glPointParameteri pglPointParameteri
#define glPointParameteriv pglPointParameteriv
#define glSecondaryColor3b pglSecondaryColor3b
#define glSecondaryColor3bv pglSecondaryColor3bv
#define glSecondaryColor3d pglSecondaryColor3d
#define glSecondaryColor3dv pglSecondaryColor3dv
#define glSecondaryColor3f pglSecondaryColor3f
#define glSecondaryColor3fv pglSecondaryColor3fv
#define glSecondaryColor3i pglSecondaryColor3i
#define glSecondaryColor3iv pglSecondaryColor3iv
#define glSecondaryColor3s pglSecondaryColor3s
#define glSecondaryColor3sv pglSecondaryColor3sv
#define glSecondaryColor3ub pglSecondaryColor3ub
#define glSecondaryColor3ubv pglSecondaryColor3ubv
#define glSecondaryColor3ui pglSecondaryColor3ui
#define glSecondaryColor3uiv pglSecondaryColor3uiv
#define glSecondaryColor3us pglSecondaryColor3us
#define glSecondaryColor3usv pglSecondaryColor3usv
#define glSecondaryColorPointer pglSecondaryColorPointer
#define glWindowPos2d pglWindowPos2d
#define glWindowPos2dv pglWindowPos2dv
#define glWindowPos2f pglWindowPos2f
#define glWindowPos2fv pglWindowPos2fv
#define glWindowPos2i pglWindowPos2i
#define glWindowPos2iv pglWindowPos2iv
#define glWindowPos2s pglWindowPos2s
#define glWindowPos2sv pglWindowPos2sv
#define glWindowPos3d pglWindowPos3d
#define glWindowPos3dv pglWindowPos3dv
#define glWindowPos3f pglWindowPos3f
#define glWindowPos3fv pglWindowPos3fv
#define glWindowPos3i pglWindowPos3i
#define glWindowPos3iv pglWindowPos3iv
#define glWindowPos3s pglWindowPos3s
#define glWindowPos3sv pglWindowPos3sv
#endif 

/* GL_VERSION_1_5 */

#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
#define __GLEE_GL_VERSION_1_5 1
/* Constants */
#define GL_BUFFER_SIZE                                     0x8764
#define GL_BUFFER_USAGE                                    0x8765
#define GL_QUERY_COUNTER_BITS                              0x8864
#define GL_CURRENT_QUERY                                   0x8865
#define GL_QUERY_RESULT                                    0x8866
#define GL_QUERY_RESULT_AVAILABLE                          0x8867
#define GL_ARRAY_BUFFER                                    0x8892
#define GL_ELEMENT_ARRAY_BUFFER                            0x8893
#define GL_ARRAY_BUFFER_BINDING                            0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING                    0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING                     0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING                     0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING                      0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING                      0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING              0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING                  0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING            0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING             0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING                     0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING              0x889F
#define GL_READ_ONLY                                       0x88B8
#define GL_WRITE_ONLY                                      0x88B9
#define GL_READ_WRITE                                      0x88BA
#define GL_BUFFER_ACCESS                                   0x88BB
#define GL_BUFFER_MAPPED                                   0x88BC
#define GL_BUFFER_MAP_POINTER                              0x88BD
#define GL_STREAM_DRAW                                     0x88E0
#define GL_STREAM_READ                                     0x88E1
#define GL_STREAM_COPY                                     0x88E2
#define GL_STATIC_DRAW                                     0x88E4
#define GL_STATIC_READ                                     0x88E5
#define GL_STATIC_COPY                                     0x88E6
#define GL_DYNAMIC_DRAW                                    0x88E8
#define GL_DYNAMIC_READ                                    0x88E9
#define GL_DYNAMIC_COPY                                    0x88EA
#define GL_SAMPLES_PASSED                                  0x8914
#define GL_FOG_COORD_SRC                                   GL_FOG_COORDINATE_SOURCE
#define GL_FOG_COORD                                       GL_FOG_COORDINATE
#define GL_CURRENT_FOG_COORD                               GL_CURRENT_FOG_COORDINATE
#define GL_FOG_COORD_ARRAY_TYPE                            GL_FOG_COORDINATE_ARRAY_TYPE
#define GL_FOG_COORD_ARRAY_STRIDE                          GL_FOG_COORDINATE_ARRAY_STRIDE
#define GL_FOG_COORD_ARRAY_POINTER                         GL_FOG_COORDINATE_ARRAY_POINTER
#define GL_FOG_COORD_ARRAY                                 GL_FOG_COORDINATE_ARRAY
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING                  GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
#define GL_SRC0_RGB                                        GL_SOURCE0_RGB
#define GL_SRC1_RGB                                        GL_SOURCE1_RGB
#define GL_SRC2_RGB                                        GL_SOURCE2_RGB
#define GL_SRC0_ALPHA                                      GL_SOURCE0_ALPHA
#define GL_SRC1_ALPHA                                      GL_SOURCE1_ALPHA
#define GL_SRC2_ALPHA                                      GL_SOURCE2_ALPHA
typedef void (APIENTRYP PFNGLGENQUERIESPROC) (GLsizei n, GLuint * ids);
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint * ids);
typedef GLboolean (APIENTRYP PFNGLISQUERYPROC) (GLuint id);
typedef void (APIENTRYP PFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint * params);
typedef void (APIENTRYP PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint * buffers);
typedef void (APIENTRYP PFNGLGENBUFFERSPROC) (GLsizei n, GLuint * buffers);
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);
typedef GLvoid* (APIENTRYP PFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, GLvoid* * params);
GLEE_EXTERN PFNGLGENQUERIESPROC pglGenQueries;
GLEE_EXTERN PFNGLDELETEQUERIESPROC pglDeleteQueries;
GLEE_EXTERN PFNGLISQUERYPROC pglIsQuery;
GLEE_EXTERN PFNGLBEGINQUERYPROC pglBeginQuery;
GLEE_EXTERN PFNGLENDQUERYPROC pglEndQuery;
GLEE_EXTERN PFNGLGETQUERYIVPROC pglGetQueryiv;
GLEE_EXTERN PFNGLGETQUERYOBJECTIVPROC pglGetQueryObjectiv;
GLEE_EXTERN PFNGLGETQUERYOBJECTUIVPROC pglGetQueryObjectuiv;
GLEE_EXTERN PFNGLBINDBUFFERPROC pglBindBuffer;
GLEE_EXTERN PFNGLDELETEBUFFERSPROC pglDeleteBuffers;
GLEE_EXTERN PFNGLGENBUFFERSPROC pglGenBuffers;
GLEE_EXTERN PFNGLISBUFFERPROC pglIsBuffer;
GLEE_EXTERN PFNGLBUFFERDATAPROC pglBufferData;
GLEE_EXTERN PFNGLBUFFERSUBDATAPROC pglBufferSubData;
GLEE_EXTERN PFNGLGETBUFFERSUBDATAPROC pglGetBufferSubData;
GLEE_EXTERN PFNGLMAPBUFFERPROC pglMapBuffer;
GLEE_EXTERN PFNGLUNMAPBUFFERPROC pglUnmapBuffer;
GLEE_EXTERN PFNGLGETBUFFERPARAMETERIVPROC pglGetBufferParameteriv;
GLEE_EXTERN PFNGLGETBUFFERPOINTERVPROC pglGetBufferPointerv;
#define glGenQueries pglGenQueries
#define glDeleteQueries pglDeleteQueries
#define glIsQuery pglIsQuery
#define glBeginQuery pglBeginQuery
#define glEndQuery pglEndQuery
#define glGetQueryiv pglGetQueryiv
#define glGetQueryObjectiv pglGetQueryObjectiv
#define glGetQueryObjectuiv pglGetQueryObjectuiv
#define glBindBuffer pglBindBuffer
#define glDeleteBuffers pglDeleteBuffers
#define glGenBuffers pglGenBuffers
#define glIsBuffer pglIsBuffer
#define glBufferData pglBufferData
#define glBufferSubData pglBufferSubData
#define glGetBufferSubData pglGetBufferSubData
#define glMapBuffer pglMapBuffer
#define glUnmapBuffer pglUnmapBuffer
#define glGetBufferParameteriv pglGetBufferParameteriv
#define glGetBufferPointerv pglGetBufferPointerv
#endif 

/* GL_VERSION_2_0 */

#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
#define __GLEE_GL_VERSION_2_0 1
/* Constants */
#define GL_BLEND_EQUATION_RGB                              GL_BLEND_EQUATION
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED                     0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE                        0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE                      0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE                        0x8625
#define GL_CURRENT_VERTEX_ATTRIB                           0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE                       0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE                         0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER                     0x8645
#define GL_STENCIL_BACK_FUNC                               0x8800
#define GL_STENCIL_BACK_FAIL                               0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL                    0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS                    0x8803
#define GL_MAX_DRAW_BUFFERS                                0x8824
#define GL_DRAW_BUFFER0                                    0x8825
#define GL_DRAW_BUFFER1                                    0x8826
#define GL_DRAW_BUFFER2                                    0x8827
#define GL_DRAW_BUFFER3                                    0x8828
#define GL_DRAW_BUFFER4                                    0x8829
#define GL_DRAW_BUFFER5                                    0x882A
#define GL_DRAW_BUFFER6                                    0x882B
#define GL_DRAW_BUFFER7                                    0x882C
#define GL_DRAW_BUFFER8                                    0x882D
#define GL_DRAW_BUFFER9                                    0x882E
#define GL_DRAW_BUFFER10                                   0x882F
#define GL_DRAW_BUFFER11                                   0x8830
#define GL_DRAW_BUFFER12                                   0x8831
#define GL_DRAW_BUFFER13                                   0x8832
#define GL_DRAW_BUFFER14                                   0x8833
#define GL_DRAW_BUFFER15                                   0x8834
#define GL_BLEND_EQUATION_ALPHA                            0x883D
#define GL_POINT_SPRITE                                    0x8861
#define GL_COORD_REPLACE                                   0x8862
#define GL_MAX_VERTEX_ATTRIBS                              0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED                  0x886A
#define GL_MAX_TEXTURE_COORDS                              0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS                         0x8872
#define GL_FRAGMENT_SHADER                                 0x8B30
#define GL_VERTEX_SHADER                                   0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS                 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS                   0x8B4A
#define GL_MAX_VARYING_FLOATS                              0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS                  0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS                0x8B4D
#define GL_SHADER_TYPE                                     0x8B4F
#define GL_FLOAT_VEC2                                      0x8B50
#define GL_FLOAT_VEC3                                      0x8B51
#define GL_FLOAT_VEC4                                      0x8B52
#define GL_INT_VEC2                                        0x8B53
#define GL_INT_VEC3                                        0x8B54
#define GL_INT_VEC4                                        0x8B55
#define GL_BOOL                                            0x8B56
#define GL_BOOL_VEC2                                       0x8B57
#define GL_BOOL_VEC3                                       0x8B58
#define GL_BOOL_VEC4                                       0x8B59
#define GL_FLOAT_MAT2                                      0x8B5A
#define GL_FLOAT_MAT3                                      0x8B5B
#define GL_FLOAT_MAT4                                      0x8B5C
#define GL_SAMPLER_1D                                      0x8B5D
#define GL_SAMPLER_2D                                      0x8B5E
#define GL_SAMPLER_3D                                      0x8B5F
#define GL_SAMPLER_CUBE                                    0x8B60
#define GL_SAMPLER_1D_SHADOW                               0x8B61
#define GL_SAMPLER_2D_SHADOW                               0x8B62
#define GL_DELETE_STATUS                                   0x8B80
#define GL_COMPILE_STATUS                                  0x8B81
#define GL_LINK_STATUS                                     0x8B82
#define GL_VALIDATE_STATUS                                 0x8B83
#define GL_INFO_LOG_LENGTH                                 0x8B84
#define GL_ATTACHED_SHADERS                                0x8B85
#define GL_ACTIVE_UNIFORMS                                 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH                       0x8B87
#define GL_SHADER_SOURCE_LENGTH                            0x8B88
#define GL_ACTIVE_ATTRIBUTES                               0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH                     0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT                 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION                        0x8B8C
#define GL_CURRENT_PROGRAM                                 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN                       0x8CA0
#define GL_LOWER_LEFT                                      0x8CA1
#define GL_UPPER_LEFT                                      0x8CA2
#define GL_STENCIL_BACK_REF                                0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK                         0x8CA4
#define GL_STENCIL_BACK_WRITEMASK                          0x8CA5
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum * bufs);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC) (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
typedef void (APIENTRYP PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar * name);
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC) ();
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC) (GLenum type);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj);
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar * name);
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
typedef void (APIENTRYP PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar * name);
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat * params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, GLvoid* * pointer);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC) (GLuint program);
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar* * string, const GLint * length);
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint * value);
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint * value);
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint * value);
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
GLEE_EXTERN PFNGLBLENDEQUATIONSEPARATEPROC pglBlendEquationSeparate;
GLEE_EXTERN PFNGLDRAWBUFFERSPROC pglDrawBuffers;
GLEE_EXTERN PFNGLSTENCILOPSEPARATEPROC pglStencilOpSeparate;
GLEE_EXTERN PFNGLSTENCILFUNCSEPARATEPROC pglStencilFuncSeparate;
GLEE_EXTERN PFNGLSTENCILMASKSEPARATEPROC pglStencilMaskSeparate;
GLEE_EXTERN PFNGLATTACHSHADERPROC pglAttachShader;
GLEE_EXTERN PFNGLBINDATTRIBLOCATIONPROC pglBindAttribLocation;
GLEE_EXTERN PFNGLCOMPILESHADERPROC pglCompileShader;
GLEE_EXTERN PFNGLCREATEPROGRAMPROC pglCreateProgram;
GLEE_EXTERN PFNGLCREATESHADERPROC pglCreateShader;
GLEE_EXTERN PFNGLDELETEPROGRAMPROC pglDeleteProgram;
GLEE_EXTERN PFNGLDELETESHADERPROC pglDeleteShader;
GLEE_EXTERN PFNGLDETACHSHADERPROC pglDetachShader;
GLEE_EXTERN PFNGLDISABLEVERTEXATTRIBARRAYPROC pglDisableVertexAttribArray;
GLEE_EXTERN PFNGLENABLEVERTEXATTRIBARRAYPROC pglEnableVertexAttribArray;
GLEE_EXTERN PFNGLGETACTIVEATTRIBPROC pglGetActiveAttrib;
GLEE_EXTERN PFNGLGETACTIVEUNIFORMPROC pglGetActiveUniform;
GLEE_EXTERN PFNGLGETATTACHEDSHADERSPROC pglGetAttachedShaders;
GLEE_EXTERN PFNGLGETATTRIBLOCATIONPROC pglGetAttribLocation;
GLEE_EXTERN PFNGLGETPROGRAMIVPROC pglGetProgramiv;
GLEE_EXTERN PFNGLGETPROGRAMINFOLOGPROC pglGetProgramInfoLog;
GLEE_EXTERN PFNGLGETSHADERIVPROC pglGetShaderiv;
GLEE_EXTERN PFNGLGETSHADERINFOLOGPROC pglGetShaderInfoLog;
GLEE_EXTERN PFNGLGETSHADERSOURCEPROC pglGetShaderSource;
GLEE_EXTERN PFNGLGETUNIFORMLOCATIONPROC pglGetUniformLocation;
GLEE_EXTERN PFNGLGETUNIFORMFVPROC pglGetUniformfv;
GLEE_EXTERN PFNGLGETUNIFORMIVPROC pglGetUniformiv;
GLEE_EXTERN PFNGLGETVERTEXATTRIBDVPROC pglGetVertexAttribdv;
GLEE_EXTERN PFNGLGETVERTEXATTRIBFVPROC pglGetVertexAttribfv;
GLEE_EXTERN PFNGLGETVERTEXATTRIBIVPROC pglGetVertexAttribiv;
GLEE_EXTERN PFNGLGETVERTEXATTRIBPOINTERVPROC pglGetVertexAttribPointerv;
GLEE_EXTERN PFNGLISPROGRAMPROC pglIsProgram;
GLEE_EXTERN PFNGLISSHADERPROC pglIsShader;
GLEE_EXTERN PFNGLLINKPROGRAMPROC pglLinkProgram;
GLEE_EXTERN PFNGLSHADERSOURCEPROC pglShaderSource;
GLEE_EXTERN PFNGLUSEPROGRAMPROC pglUseProgram;
GLEE_EXTERN PFNGLUNIFORM1FPROC pglUniform1f;
GLEE_EXTERN PFNGLUNIFORM2FPROC pglUniform2f;
GLEE_EXTERN PFNGLUNIFORM3FPROC pglUniform3f;
GLEE_EXTERN PFNGLUNIFORM4FPROC pglUniform4f;
GLEE_EXTERN PFNGLUNIFORM1IPROC pglUniform1i;
GLEE_EXTERN PFNGLUNIFORM2IPROC pglUniform2i;
GLEE_EXTERN PFNGLUNIFORM3IPROC pglUniform3i;
GLEE_EXTERN PFNGLUNIFORM4IPROC pglUniform4i;
GLEE_EXTERN PFNGLUNIFORM1FVPROC pglUniform1fv;
GLEE_EXTERN PFNGLUNIFORM2FVPROC pglUniform2fv;
GLEE_EXTERN PFNGLUNIFORM3FVPROC pglUniform3fv;
GLEE_EXTERN PFNGLUNIFORM4FVPROC pglUniform4fv;
GLEE_EXTERN PFNGLUNIFORM1IVPROC pglUniform1iv;
GLEE_EXTERN PFNGLUNIFORM2IVPROC pglUniform2iv;
GLEE_EXTERN PFNGLUNIFORM3IVPROC pglUniform3iv;
GLEE_EXTERN PFNGLUNIFORM4IVPROC pglUniform4iv;
GLEE_EXTERN PFNGLUNIFORMMATRIX2FVPROC pglUniformMatrix2fv;
GLEE_EXTERN PFNGLUNIFORMMATRIX3FVPROC pglUniformMatrix3fv;
GLEE_EXTERN PFNGLUNIFORMMATRIX4FVPROC pglUniformMatrix4fv;
GLEE_EXTERN PFNGLVALIDATEPROGRAMPROC pglValidateProgram;
GLEE_EXTERN PFNGLVERTEXATTRIB1DPROC pglVertexAttrib1d;
GLEE_EXTERN PFNGLVERTEXATTRIB1DVPROC pglVertexAttrib1dv;
GLEE_EXTERN PFNGLVERTEXATTRIB1FPROC pglVertexAttrib1f;
GLEE_EXTERN PFNGLVERTEXATTRIB1FVPROC pglVertexAttrib1fv;
GLEE_EXTERN PFNGLVERTEXATTRIB1SPROC pglVertexAttrib1s;
GLEE_EXTERN PFNGLVERTEXATTRIB1SVPROC pglVertexAttrib1sv;
GLEE_EXTERN PFNGLVERTEXATTRIB2DPROC pglVertexAttrib2d;
GLEE_EXTERN PFNGLVERTEXATTRIB2DVPROC pglVertexAttrib2dv;
GLEE_EXTERN PFNGLVERTEXATTRIB2FPROC pglVertexAttrib2f;
GLEE_EXTERN PFNGLVERTEXATTRIB2FVPROC pglVertexAttrib2fv;
GLEE_EXTERN PFNGLVERTEXATTRIB2SPROC pglVertexAttrib2s;
GLEE_EXTERN PFNGLVERTEXATTRIB2SVPROC pglVertexAttrib2sv;
GLEE_EXTERN PFNGLVERTEXATTRIB3DPROC pglVertexAttrib3d;
GLEE_EXTERN PFNGLVERTEXATTRIB3DVPROC pglVertexAttrib3dv;
GLEE_EXTERN PFNGLVERTEXATTRIB3FPROC pglVertexAttrib3f;
GLEE_EXTERN PFNGLVERTEXATTRIB3FVPROC pglVertexAttrib3fv;
GLEE_EXTERN PFNGLVERTEXATTRIB3SPROC pglVertexAttrib3s;
GLEE_EXTERN PFNGLVERTEXATTRIB3SVPROC pglVertexAttrib3sv;
GLEE_EXTERN PFNGLVERTEXATTRIB4NBVPROC pglVertexAttrib4Nbv;
GLEE_EXTERN PFNGLVERTEXATTRIB4NIVPROC pglVertexAttrib4Niv;
GLEE_EXTERN PFNGLVERTEXATTRIB4NSVPROC pglVertexAttrib4Nsv;
GLEE_EXTERN PFNGLVERTEXATTRIB4NUBPROC pglVertexAttrib4Nub;
GLEE_EXTERN PFNGLVERTEXATTRIB4NUBVPROC pglVertexAttrib4Nubv;
GLEE_EXTERN PFNGLVERTEXATTRIB4NUIVPROC pglVertexAttrib4Nuiv;
GLEE_EXTERN PFNGLVERTEXATTRIB4NUSVPROC pglVertexAttrib4Nusv;
GLEE_EXTERN PFNGLVERTEXATTRIB4BVPROC pglVertexAttrib4bv;
GLEE_EXTERN PFNGLVERTEXATTRIB4DPROC pglVertexAttrib4d;
GLEE_EXTERN PFNGLVERTEXATTRIB4DVPROC pglVertexAttrib4dv;
GLEE_EXTERN PFNGLVERTEXATTRIB4FPROC pglVertexAttrib4f;
GLEE_EXTERN PFNGLVERTEXATTRIB4FVPROC pglVertexAttrib4fv;
GLEE_EXTERN PFNGLVERTEXATTRIB4IVPROC pglVertexAttrib4iv;
GLEE_EXTERN PFNGLVERTEXATTRIB4SPROC pglVertexAttrib4s;
GLEE_EXTERN PFNGLVERTEXATTRIB4SVPROC pglVertexAttrib4sv;
GLEE_EXTERN PFNGLVERTEXATTRIB4UBVPROC pglVertexAttrib4ubv;
GLEE_EXTERN PFNGLVERTEXATTRIB4UIVPROC pglVertexAttrib4uiv;
GLEE_EXTERN PFNGLVERTEXATTRIB4USVPROC pglVertexAttrib4usv;
GLEE_EXTERN PFNGLVERTEXATTRIBPOINTERPROC pglVertexAttribPointer;
#define glBlendEquationSeparate pglBlendEquationSeparate
#define glDrawBuffers pglDrawBuffers
#define glStencilOpSeparate pglStencilOpSeparate
#define glStencilFuncSeparate pglStencilFuncSeparate
#define glStencilMaskSeparate pglStencilMaskSeparate
#define glAttachShader pglAttachShader
#define glBindAttribLocation pglBindAttribLocation
#define glCompileShader pglCompileShader
#define glCreateProgram pglCreateProgram
#define glCreateShader pglCreateShader
#define glDeleteProgram pglDeleteProgram
#define glDeleteShader pglDeleteShader
#define glDetachShader pglDetachShader
#define glDisableVertexAttribArray pglDisableVertexAttribArray
#define glEnableVertexAttribArray pglEnableVertexAttribArray
#define glGetActiveAttrib pglGetActiveAttrib
#define glGetActiveUniform pglGetActiveUniform
#define glGetAttachedShaders pglGetAttachedShaders
#define glGetAttribLocation pglGetAttribLocation
#define glGetProgramiv pglGetProgramiv
#define glGetProgramInfoLog pglGetProgramInfoLog
#define glGetShaderiv pglGetShaderiv
#define glGetShaderInfoLog pglGetShaderInfoLog
#define glGetShaderSource pglGetShaderSource
#define glGetUniformLocation pglGetUniformLocation
#define glGetUniformfv pglGetUniformfv
#define glGetUniformiv pglGetUniformiv
#define glGetVertexAttribdv pglGetVertexAttribdv
#define glGetVertexAttribfv pglGetVertexAttribfv
#define glGetVertexAttribiv pglGetVertexAttribiv
#define glGetVertexAttribPointerv pglGetVertexAttribPointerv
#define glIsProgram pglIsProgram
#define glIsShader pglIsShader
#define glLinkProgram pglLinkProgram
#define glShaderSource pglShaderSource
#define glUseProgram pglUseProgram
#define glUniform1f pglUniform1f
#define glUniform2f pglUniform2f
#define glUniform3f pglUniform3f
#define glUniform4f pglUniform4f
#define glUniform1i pglUniform1i
#define glUniform2i pglUniform2i
#define glUniform3i pglUniform3i
#define glUniform4i pglUniform4i
#define glUniform1fv pglUniform1fv
#define glUniform2fv pglUniform2fv
#define glUniform3fv pglUniform3fv
#define glUniform4fv pglUniform4fv
#define glUniform1iv pglUniform1iv
#define glUniform2iv pglUniform2iv
#define glUniform3iv pglUniform3iv
#define glUniform4iv pglUniform4iv
#define glUniformMatrix2fv pglUniformMatrix2fv
#define glUniformMatrix3fv pglUniformMatrix3fv
#define glUniformMatrix4fv pglUniformMatrix4fv
#define glValidateProgram pglValidateProgram
#define glVertexAttrib1d pglVertexAttrib1d
#define glVertexAttrib1dv pglVertexAttrib1dv
#define glVertexAttrib1f pglVertexAttrib1f
#define glVertexAttrib1fv pglVertexAttrib1fv
#define glVertexAttrib1s pglVertexAttrib1s
#define glVertexAttrib1sv pglVertexAttrib1sv
#define glVertexAttrib2d pglVertexAttrib2d
#define glVertexAttrib2dv pglVertexAttrib2dv
#define glVertexAttrib2f pglVertexAttrib2f
#define glVertexAttrib2fv pglVertexAttrib2fv
#define glVertexAttrib2s pglVertexAttrib2s
#define glVertexAttrib2sv pglVertexAttrib2sv
#define glVertexAttrib3d pglVertexAttrib3d
#define glVertexAttrib3dv pglVertexAttrib3dv
#define glVertexAttrib3f pglVertexAttrib3f
#define glVertexAttrib3fv pglVertexAttrib3fv
#define glVertexAttrib3s pglVertexAttrib3s
#define glVertexAttrib3sv pglVertexAttrib3sv
#define glVertexAttrib4Nbv pglVertexAttrib4Nbv
#define glVertexAttrib4Niv pglVertexAttrib4Niv
#define glVertexAttrib4Nsv pglVertexAttrib4Nsv
#define glVertexAttrib4Nub pglVertexAttrib4Nub
#define glVertexAttrib4Nubv pglVertexAttrib4Nubv
#define glVertexAttrib4Nuiv pglVertexAttrib4Nuiv
#define glVertexAttrib4Nusv pglVertexAttrib4Nusv
#define glVertexAttrib4bv pglVertexAttrib4bv
#define glVertexAttrib4d pglVertexAttrib4d
#define glVertexAttrib4dv pglVertexAttrib4dv
#define glVertexAttrib4f pglVertexAttrib4f
#define glVertexAttrib4fv pglVertexAttrib4fv
#define glVertexAttrib4iv pglVertexAttrib4iv
#define glVertexAttrib4s pglVertexAttrib4s
#define glVertexAttrib4sv pglVertexAttrib4sv
#define glVertexAttrib4ubv pglVertexAttrib4ubv
#define glVertexAttrib4uiv pglVertexAttrib4uiv
#define glVertexAttrib4usv pglVertexAttrib4usv
#define glVertexAttribPointer pglVertexAttribPointer
#endif 

/* GL_VERSION_2_1 */

#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#define __GLEE_GL_VERSION_2_1 1
/* Constants */
#define GL_PIXEL_PACK_BUFFER                               0x88EB
#define GL_PIXEL_UNPACK_BUFFER                             0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING                       0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING                     0x88EF
#define GL_SRGB                                            0x8C40
#define GL_SRGB8                                           0x8C41
#define GL_SRGB_ALPHA                                      0x8C42
#define GL_SRGB8_ALPHA8                                    0x8C43
#define GL_SLUMINANCE_ALPHA                                0x8C44
#define GL_SLUMINANCE8_ALPHA8                              0x8C45
#define GL_SLUMINANCE                                      0x8C46
#define GL_SLUMINANCE8                                     0x8C47
#define GL_COMPRESSED_SRGB                                 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA                           0x8C49
#define GL_COMPRESSED_SLUMINANCE                           0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA                     0x8C4B
#define GL_FLOAT_MAT2x3                                    0x8B65
#define GL_FLOAT_MAT2x4                                    0x8B66
#define GL_FLOAT_MAT3x2                                    0x8B67
#define GL_FLOAT_MAT3x4                                    0x8B68
#define GL_FLOAT_MAT4x2                                    0x8B69
#define GL_FLOAT_MAT4x3                                    0x8B6A
#define GL_CURRENT_RASTER_SECONDARY_COLOR                  0x845F
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
GLEE_EXTERN PFNGLUNIFORMMATRIX2X3FVPROC pglUniformMatrix2x3fv;
GLEE_EXTERN PFNGLUNIFORMMATRIX3X2FVPROC pglUniformMatrix3x2fv;
GLEE_EXTERN PFNGLUNIFORMMATRIX2X4FVPROC pglUniformMatrix2x4fv;
GLEE_EXTERN PFNGLUNIFORMMATRIX4X2FVPROC pglUniformMatrix4x2fv;
GLEE_EXTERN PFNGLUNIFORMMATRIX3X4FVPROC pglUniformMatrix3x4fv;
GLEE_EXTERN PFNGLUNIFORMMATRIX4X3FVPROC pglUniformMatrix4x3fv;
#define glUniformMatrix2x3fv pglUniformMatrix2x3fv
#define glUniformMatrix3x2fv pglUniformMatrix3x2fv
#define glUniformMatrix2x4fv pglUniformMatrix2x4fv
#define glUniformMatrix4x2fv pglUniformMatrix4x2fv
#define glUniformMatrix3x4fv pglUniformMatrix3x4fv
#define glUniformMatrix4x3fv pglUniformMatrix4x3fv
#endif 

/* GL_ARB_multitexture */

#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1
#define __GLEE_GL_ARB_multitexture 1
/* Constants */
#define GL_TEXTURE0_ARB                                    0x84C0
#define GL_TEXTURE1_ARB                                    0x84C1
#define GL_TEXTURE2_ARB                                    0x84C2
#define GL_TEXTURE3_ARB                                    0x84C3
#define GL_TEXTURE4_ARB                                    0x84C4
#define GL_TEXTURE5_ARB                                    0x84C5
#define GL_TEXTURE6_ARB                                    0x84C6
#define GL_TEXTURE7_ARB                                    0x84C7
#define GL_TEXTURE8_ARB                                    0x84C8
#define GL_TEXTURE9_ARB                                    0x84C9
#define GL_TEXTURE10_ARB                                   0x84CA
#define GL_TEXTURE11_ARB                                   0x84CB
#define GL_TEXTURE12_ARB                                   0x84CC
#define GL_TEXTURE13_ARB                                   0x84CD
#define GL_TEXTURE14_ARB                                   0x84CE
#define GL_TEXTURE15_ARB                                   0x84CF
#define GL_TEXTURE16_ARB                                   0x84D0
#define GL_TEXTURE17_ARB                                   0x84D1
#define GL_TEXTURE18_ARB                                   0x84D2
#define GL_TEXTURE19_ARB                                   0x84D3
#define GL_TEXTURE20_ARB                                   0x84D4
#define GL_TEXTURE21_ARB                                   0x84D5
#define GL_TEXTURE22_ARB                                   0x84D6
#define GL_TEXTURE23_ARB                                   0x84D7
#define GL_TEXTURE24_ARB                                   0x84D8
#define GL_TEXTURE25_ARB                                   0x84D9
#define GL_TEXTURE26_ARB                                   0x84DA
#define GL_TEXTURE27_ARB                                   0x84DB
#define GL_TEXTURE28_ARB                                   0x84DC
#define GL_TEXTURE29_ARB                                   0x84DD
#define GL_TEXTURE30_ARB                                   0x84DE
#define GL_TEXTURE31_ARB                                   0x84DF
#define GL_ACTIVE_TEXTURE_ARB                              0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB                       0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB                           0x84E2
typedef void (APIENTRYP PFNGLACTIVETEXTUREARBPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREARBPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DARBPROC) (GLenum target, GLdouble s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVARBPROC) (GLenum target, const GLdouble * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FARBPROC) (GLenum target, GLfloat s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVARBPROC) (GLenum target, const GLfloat * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IARBPROC) (GLenum target, GLint s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVARBPROC) (GLenum target, const GLint * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SARBPROC) (GLenum target, GLshort s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVARBPROC) (GLenum target, const GLshort * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DARBPROC) (GLenum target, GLdouble s, GLdouble t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVARBPROC) (GLenum target, const GLdouble * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FARBPROC) (GLenum target, GLfloat s, GLfloat t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVARBPROC) (GLenum target, const GLfloat * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IARBPROC) (GLenum target, GLint s, GLint t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVARBPROC) (GLenum target, const GLint * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SARBPROC) (GLenum target, GLshort s, GLshort t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVARBPROC) (GLenum target, const GLshort * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVARBPROC) (GLenum target, const GLdouble * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVARBPROC) (GLenum target, const GLfloat * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IARBPROC) (GLenum target, GLint s, GLint t, GLint r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVARBPROC) (GLenum target, const GLint * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVARBPROC) (GLenum target, const GLshort * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVARBPROC) (GLenum target, const GLdouble * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVARBPROC) (GLenum target, const GLfloat * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IARBPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVARBPROC) (GLenum target, const GLint * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVARBPROC) (GLenum target, const GLshort * v);
GLEE_EXTERN PFNGLACTIVETEXTUREARBPROC pglActiveTextureARB;
GLEE_EXTERN PFNGLCLIENTACTIVETEXTUREARBPROC pglClientActiveTextureARB;
GLEE_EXTERN PFNGLMULTITEXCOORD1DARBPROC pglMultiTexCoord1dARB;
GLEE_EXTERN PFNGLMULTITEXCOORD1DVARBPROC pglMultiTexCoord1dvARB;
GLEE_EXTERN PFNGLMULTITEXCOORD1FARBPROC pglMultiTexCoord1fARB;
GLEE_EXTERN PFNGLMULTITEXCOORD1FVARBPROC pglMultiTexCoord1fvARB;
GLEE_EXTERN PFNGLMULTITEXCOORD1IARBPROC pglMultiTexCoord1iARB;
GLEE_EXTERN PFNGLMULTITEXCOORD1IVARBPROC pglMultiTexCoord1ivARB;
GLEE_EXTERN PFNGLMULTITEXCOORD1SARBPROC pglMultiTexCoord1sARB;
GLEE_EXTERN PFNGLMULTITEXCOORD1SVARBPROC pglMultiTexCoord1svARB;
GLEE_EXTERN PFNGLMULTITEXCOORD2DARBPROC pglMultiTexCoord2dARB;
GLEE_EXTERN PFNGLMULTITEXCOORD2DVARBPROC pglMultiTexCoord2dvARB;
GLEE_EXTERN PFNGLMULTITEXCOORD2FARBPROC pglMultiTexCoord2fARB;
GLEE_EXTERN PFNGLMULTITEXCOORD2FVARBPROC pglMultiTexCoord2fvARB;
GLEE_EXTERN PFNGLMULTITEXCOORD2IARBPROC pglMultiTexCoord2iARB;
GLEE_EXTERN PFNGLMULTITEXCOORD2IVARBPROC pglMultiTexCoord2ivARB;
GLEE_EXTERN PFNGLMULTITEXCOORD2SARBPROC pglMultiTexCoord2sARB;
GLEE_EXTERN PFNGLMULTITEXCOORD2SVARBPROC pglMultiTexCoord2svARB;
GLEE_EXTERN PFNGLMULTITEXCOORD3DARBPROC pglMultiTexCoord3dARB;
GLEE_EXTERN PFNGLMULTITEXCOORD3DVARBPROC pglMultiTexCoord3dvARB;
GLEE_EXTERN PFNGLMULTITEXCOORD3FARBPROC pglMultiTexCoord3fARB;
GLEE_EXTERN PFNGLMULTITEXCOORD3FVARBPROC pglMultiTexCoord3fvARB;
GLEE_EXTERN PFNGLMULTITEXCOORD3IARBPROC pglMultiTexCoord3iARB;
GLEE_EXTERN PFNGLMULTITEXCOORD3IVARBPROC pglMultiTexCoord3ivARB;
GLEE_EXTERN PFNGLMULTITEXCOORD3SARBPROC pglMultiTexCoord3sARB;
GLEE_EXTERN PFNGLMULTITEXCOORD3SVARBPROC pglMultiTexCoord3svARB;
GLEE_EXTERN PFNGLMULTITEXCOORD4DARBPROC pglMultiTexCoord4dARB;
GLEE_EXTERN PFNGLMULTITEXCOORD4DVARBPROC pglMultiTexCoord4dvARB;
GLEE_EXTERN PFNGLMULTITEXCOORD4FARBPROC pglMultiTexCoord4fARB;
GLEE_EXTERN PFNGLMULTITEXCOORD4FVARBPROC pglMultiTexCoord4fvARB;
GLEE_EXTERN PFNGLMULTITEXCOORD4IARBPROC pglMultiTexCoord4iARB;
GLEE_EXTERN PFNGLMULTITEXCOORD4IVARBPROC pglMultiTexCoord4ivARB;
GLEE_EXTERN PFNGLMULTITEXCOORD4SARBPROC pglMultiTexCoord4sARB;
GLEE_EXTERN PFNGLMULTITEXCOORD4SVARBPROC pglMultiTexCoord4svARB;
#define glActiveTextureARB pglActiveTextureARB
#define glClientActiveTextureARB pglClientActiveTextureARB
#define glMultiTexCoord1dARB pglMultiTexCoord1dARB
#define glMultiTexCoord1dvARB pglMultiTexCoord1dvARB
#define glMultiTexCoord1fARB pglMultiTexCoord1fARB
#define glMultiTexCoord1fvARB pglMultiTexCoord1fvARB
#define glMultiTexCoord1iARB pglMultiTexCoord1iARB
#define glMultiTexCoord1ivARB pglMultiTexCoord1ivARB
#define glMultiTexCoord1sARB pglMultiTexCoord1sARB
#define glMultiTexCoord1svARB pglMultiTexCoord1svARB
#define glMultiTexCoord2dARB pglMultiTexCoord2dARB
#define glMultiTexCoord2dvARB pglMultiTexCoord2dvARB
#define glMultiTexCoord2fARB pglMultiTexCoord2fARB
#define glMultiTexCoord2fvARB pglMultiTexCoord2fvARB
#define glMultiTexCoord2iARB pglMultiTexCoord2iARB
#define glMultiTexCoord2ivARB pglMultiTexCoord2ivARB
#define glMultiTexCoord2sARB pglMultiTexCoord2sARB
#define glMultiTexCoord2svARB pglMultiTexCoord2svARB
#define glMultiTexCoord3dARB pglMultiTexCoord3dARB
#define glMultiTexCoord3dvARB pglMultiTexCoord3dvARB
#define glMultiTexCoord3fARB pglMultiTexCoord3fARB
#define glMultiTexCoord3fvARB pglMultiTexCoord3fvARB
#define glMultiTexCoord3iARB pglMultiTexCoord3iARB
#define glMultiTexCoord3ivARB pglMultiTexCoord3ivARB
#define glMultiTexCoord3sARB pglMultiTexCoord3sARB
#define glMultiTexCoord3svARB pglMultiTexCoord3svARB
#define glMultiTexCoord4dARB pglMultiTexCoord4dARB
#define glMultiTexCoord4dvARB pglMultiTexCoord4dvARB
#define glMultiTexCoord4fARB pglMultiTexCoord4fARB
#define glMultiTexCoord4fvARB pglMultiTexCoord4fvARB
#define glMultiTexCoord4iARB pglMultiTexCoord4iARB
#define glMultiTexCoord4ivARB pglMultiTexCoord4ivARB
#define glMultiTexCoord4sARB pglMultiTexCoord4sARB
#define glMultiTexCoord4svARB pglMultiTexCoord4svARB
#endif 

/* GL_ARB_transpose_matrix */

#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix 1
#define __GLEE_GL_ARB_transpose_matrix 1
/* Constants */
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB                  0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB                 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB                    0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB                      0x84E6
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFARBPROC) (const GLfloat * m);
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDARBPROC) (const GLdouble * m);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFARBPROC) (const GLfloat * m);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDARBPROC) (const GLdouble * m);
GLEE_EXTERN PFNGLLOADTRANSPOSEMATRIXFARBPROC pglLoadTransposeMatrixfARB;
GLEE_EXTERN PFNGLLOADTRANSPOSEMATRIXDARBPROC pglLoadTransposeMatrixdARB;
GLEE_EXTERN PFNGLMULTTRANSPOSEMATRIXFARBPROC pglMultTransposeMatrixfARB;
GLEE_EXTERN PFNGLMULTTRANSPOSEMATRIXDARBPROC pglMultTransposeMatrixdARB;
#define glLoadTransposeMatrixfARB pglLoadTransposeMatrixfARB
#define glLoadTransposeMatrixdARB pglLoadTransposeMatrixdARB
#define glMultTransposeMatrixfARB pglMultTransposeMatrixfARB
#define glMultTransposeMatrixdARB pglMultTransposeMatrixdARB
#endif 

/* GL_ARB_multisample */

#ifndef GL_ARB_multisample
#define GL_ARB_multisample 1
#define __GLEE_GL_ARB_multisample 1
/* Constants */
#define GL_MULTISAMPLE_ARB                                 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB                    0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB                         0x809F
#define GL_SAMPLE_COVERAGE_ARB                             0x80A0
#define GL_SAMPLE_BUFFERS_ARB                              0x80A8
#define GL_SAMPLES_ARB                                     0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB                       0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB                      0x80AB
#define GL_MULTISAMPLE_BIT_ARB                             0x20000000
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEARBPROC) (GLclampf value, GLboolean invert);
GLEE_EXTERN PFNGLSAMPLECOVERAGEARBPROC pglSampleCoverageARB;
#define glSampleCoverageARB pglSampleCoverageARB
#endif 

/* GL_ARB_texture_env_add */

#ifndef GL_ARB_texture_env_add
#define GL_ARB_texture_env_add 1
#define __GLEE_GL_ARB_texture_env_add 1
/* Constants */
#endif 

/* GL_ARB_texture_cube_map */

#ifndef GL_ARB_texture_cube_map
#define GL_ARB_texture_cube_map 1
#define __GLEE_GL_ARB_texture_cube_map 1
/* Constants */
#define GL_NORMAL_MAP_ARB                                  0x8511
#define GL_REFLECTION_MAP_ARB                              0x8512
#define GL_TEXTURE_CUBE_MAP_ARB                            0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB                    0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB                 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB                 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB                 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB                 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB                 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB                 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB                      0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB                   0x851C
#endif 

/* GL_ARB_texture_compression */

#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1
#define __GLEE_GL_ARB_texture_compression 1
/* Constants */
#define GL_COMPRESSED_ALPHA_ARB                            0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB                        0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB                  0x84EB
#define GL_COMPRESSED_INTENSITY_ARB                        0x84EC
#define GL_COMPRESSED_RGB_ARB                              0x84ED
#define GL_COMPRESSED_RGBA_ARB                             0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB                    0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB               0x86A0
#define GL_TEXTURE_COMPRESSED_ARB                          0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB              0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB                  0x86A3
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint level, GLvoid * img);
GLEE_EXTERN PFNGLCOMPRESSEDTEXIMAGE3DARBPROC pglCompressedTexImage3DARB;
GLEE_EXTERN PFNGLCOMPRESSEDTEXIMAGE2DARBPROC pglCompressedTexImage2DARB;
GLEE_EXTERN PFNGLCOMPRESSEDTEXIMAGE1DARBPROC pglCompressedTexImage1DARB;
GLEE_EXTERN PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC pglCompressedTexSubImage3DARB;
GLEE_EXTERN PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC pglCompressedTexSubImage2DARB;
GLEE_EXTERN PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC pglCompressedTexSubImage1DARB;
GLEE_EXTERN PFNGLGETCOMPRESSEDTEXIMAGEARBPROC pglGetCompressedTexImageARB;
#define glCompressedTexImage3DARB pglCompressedTexImage3DARB
#define glCompressedTexImage2DARB pglCompressedTexImage2DARB
#define glCompressedTexImage1DARB pglCompressedTexImage1DARB
#define glCompressedTexSubImage3DARB pglCompressedTexSubImage3DARB
#define glCompressedTexSubImage2DARB pglCompressedTexSubImage2DARB
#define glCompressedTexSubImage1DARB pglCompressedTexSubImage1DARB
#define glGetCompressedTexImageARB pglGetCompressedTexImageARB
#endif 

/* GL_ARB_texture_border_clamp */

#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp 1
#define __GLEE_GL_ARB_texture_border_clamp 1
/* Constants */
#define GL_CLAMP_TO_BORDER_ARB                             0x812D
#endif 

/* GL_ARB_point_parameters */

#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters 1
#define __GLEE_GL_ARB_point_parameters 1
/* Constants */
#define GL_POINT_SIZE_MIN_ARB                              0x8126
#define GL_POINT_SIZE_MAX_ARB                              0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB                   0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB                  0x8129
typedef void (APIENTRYP PFNGLPOINTPARAMETERFARBPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVARBPROC) (GLenum pname, const GLfloat * params);
GLEE_EXTERN PFNGLPOINTPARAMETERFARBPROC pglPointParameterfARB;
GLEE_EXTERN PFNGLPOINTPARAMETERFVARBPROC pglPointParameterfvARB;
#define glPointParameterfARB pglPointParameterfARB
#define glPointParameterfvARB pglPointParameterfvARB
#endif 

/* GL_ARB_vertex_blend */

#ifndef GL_ARB_vertex_blend
#define GL_ARB_vertex_blend 1
#define __GLEE_GL_ARB_vertex_blend 1
/* Constants */
#define GL_MAX_VERTEX_UNITS_ARB                            0x86A4
#define GL_ACTIVE_VERTEX_UNITS_ARB                         0x86A5
#define GL_WEIGHT_SUM_UNITY_ARB                            0x86A6
#define GL_VERTEX_BLEND_ARB                                0x86A7
#define GL_CURRENT_WEIGHT_ARB                              0x86A8
#define GL_WEIGHT_ARRAY_TYPE_ARB                           0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_ARB                         0x86AA
#define GL_WEIGHT_ARRAY_SIZE_ARB                           0x86AB
#define GL_WEIGHT_ARRAY_POINTER_ARB                        0x86AC
#define GL_WEIGHT_ARRAY_ARB                                0x86AD
#define GL_MODELVIEW0_ARB                                  0x1700
#define GL_MODELVIEW1_ARB                                  0x850A
#define GL_MODELVIEW2_ARB                                  0x8722
#define GL_MODELVIEW3_ARB                                  0x8723
#define GL_MODELVIEW4_ARB                                  0x8724
#define GL_MODELVIEW5_ARB                                  0x8725
#define GL_MODELVIEW6_ARB                                  0x8726
#define GL_MODELVIEW7_ARB                                  0x8727
#define GL_MODELVIEW8_ARB                                  0x8728
#define GL_MODELVIEW9_ARB                                  0x8729
#define GL_MODELVIEW10_ARB                                 0x872A
#define GL_MODELVIEW11_ARB                                 0x872B
#define GL_MODELVIEW12_ARB                                 0x872C
#define GL_MODELVIEW13_ARB                                 0x872D
#define GL_MODELVIEW14_ARB                                 0x872E
#define GL_MODELVIEW15_ARB                                 0x872F
#define GL_MODELVIEW16_ARB                                 0x8730
#define GL_MODELVIEW17_ARB                                 0x8731
#define GL_MODELVIEW18_ARB                                 0x8732
#define GL_MODELVIEW19_ARB                                 0x8733
#define GL_MODELVIEW20_ARB                                 0x8734
#define GL_MODELVIEW21_ARB                                 0x8735
#define GL_MODELVIEW22_ARB                                 0x8736
#define GL_MODELVIEW23_ARB                                 0x8737
#define GL_MODELVIEW24_ARB                                 0x8738
#define GL_MODELVIEW25_ARB                                 0x8739
#define GL_MODELVIEW26_ARB                                 0x873A
#define GL_MODELVIEW27_ARB                                 0x873B
#define GL_MODELVIEW28_ARB                                 0x873C
#define GL_MODELVIEW29_ARB                                 0x873D
#define GL_MODELVIEW30_ARB                                 0x873E
#define GL_MODELVIEW31_ARB                                 0x873F
typedef void (APIENTRYP PFNGLWEIGHTBVARBPROC) (GLint size, const GLbyte * weights);
typedef void (APIENTRYP PFNGLWEIGHTSVARBPROC) (GLint size, const GLshort * weights);
typedef void (APIENTRYP PFNGLWEIGHTIVARBPROC) (GLint size, const GLint * weights);
typedef void (APIENTRYP PFNGLWEIGHTFVARBPROC) (GLint size, const GLfloat * weights);
typedef void (APIENTRYP PFNGLWEIGHTDVARBPROC) (GLint size, const GLdouble * weights);
typedef void (APIENTRYP PFNGLWEIGHTUBVARBPROC) (GLint size, const GLubyte * weights);
typedef void (APIENTRYP PFNGLWEIGHTUSVARBPROC) (GLint size, const GLushort * weights);
typedef void (APIENTRYP PFNGLWEIGHTUIVARBPROC) (GLint size, const GLuint * weights);
typedef void (APIENTRYP PFNGLWEIGHTPOINTERARBPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLVERTEXBLENDARBPROC) (GLint count);
GLEE_EXTERN PFNGLWEIGHTBVARBPROC pglWeightbvARB;
GLEE_EXTERN PFNGLWEIGHTSVARBPROC pglWeightsvARB;
GLEE_EXTERN PFNGLWEIGHTIVARBPROC pglWeightivARB;
GLEE_EXTERN PFNGLWEIGHTFVARBPROC pglWeightfvARB;
GLEE_EXTERN PFNGLWEIGHTDVARBPROC pglWeightdvARB;
GLEE_EXTERN PFNGLWEIGHTUBVARBPROC pglWeightubvARB;
GLEE_EXTERN PFNGLWEIGHTUSVARBPROC pglWeightusvARB;
GLEE_EXTERN PFNGLWEIGHTUIVARBPROC pglWeightuivARB;
GLEE_EXTERN PFNGLWEIGHTPOINTERARBPROC pglWeightPointerARB;
GLEE_EXTERN PFNGLVERTEXBLENDARBPROC pglVertexBlendARB;
#define glWeightbvARB pglWeightbvARB
#define glWeightsvARB pglWeightsvARB
#define glWeightivARB pglWeightivARB
#define glWeightfvARB pglWeightfvARB
#define glWeightdvARB pglWeightdvARB
#define glWeightubvARB pglWeightubvARB
#define glWeightusvARB pglWeightusvARB
#define glWeightuivARB pglWeightuivARB
#define glWeightPointerARB pglWeightPointerARB
#define glVertexBlendARB pglVertexBlendARB
#endif 

/* GL_ARB_matrix_palette */

#ifndef GL_ARB_matrix_palette
#define GL_ARB_matrix_palette 1
#define __GLEE_GL_ARB_matrix_palette 1
/* Constants */
#define GL_MATRIX_PALETTE_ARB                              0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB              0x8841
#define GL_MAX_PALETTE_MATRICES_ARB                        0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB                      0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB                          0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB                        0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB                     0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB                     0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB                   0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB                  0x8849
typedef void (APIENTRYP PFNGLCURRENTPALETTEMATRIXARBPROC) (GLint index);
typedef void (APIENTRYP PFNGLMATRIXINDEXUBVARBPROC) (GLint size, const GLubyte * indices);
typedef void (APIENTRYP PFNGLMATRIXINDEXUSVARBPROC) (GLint size, const GLushort * indices);
typedef void (APIENTRYP PFNGLMATRIXINDEXUIVARBPROC) (GLint size, const GLuint * indices);
typedef void (APIENTRYP PFNGLMATRIXINDEXPOINTERARBPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
GLEE_EXTERN PFNGLCURRENTPALETTEMATRIXARBPROC pglCurrentPaletteMatrixARB;
GLEE_EXTERN PFNGLMATRIXINDEXUBVARBPROC pglMatrixIndexubvARB;
GLEE_EXTERN PFNGLMATRIXINDEXUSVARBPROC pglMatrixIndexusvARB;
GLEE_EXTERN PFNGLMATRIXINDEXUIVARBPROC pglMatrixIndexuivARB;
GLEE_EXTERN PFNGLMATRIXINDEXPOINTERARBPROC pglMatrixIndexPointerARB;
#define glCurrentPaletteMatrixARB pglCurrentPaletteMatrixARB
#define glMatrixIndexubvARB pglMatrixIndexubvARB
#define glMatrixIndexusvARB pglMatrixIndexusvARB
#define glMatrixIndexuivARB pglMatrixIndexuivARB
#define glMatrixIndexPointerARB pglMatrixIndexPointerARB
#endif 

/* GL_ARB_texture_env_combine */

#ifndef GL_ARB_texture_env_combine
#define GL_ARB_texture_env_combine 1
#define __GLEE_GL_ARB_texture_env_combine 1
/* Constants */
#define GL_COMBINE_ARB                                     0x8570
#define GL_COMBINE_RGB_ARB                                 0x8571
#define GL_COMBINE_ALPHA_ARB                               0x8572
#define GL_SOURCE0_RGB_ARB                                 0x8580
#define GL_SOURCE1_RGB_ARB                                 0x8581
#define GL_SOURCE2_RGB_ARB                                 0x8582
#define GL_SOURCE0_ALPHA_ARB                               0x8588
#define GL_SOURCE1_ALPHA_ARB                               0x8589
#define GL_SOURCE2_ALPHA_ARB                               0x858A
#define GL_OPERAND0_RGB_ARB                                0x8590
#define GL_OPERAND1_RGB_ARB                                0x8591
#define GL_OPERAND2_RGB_ARB                                0x8592
#define GL_OPERAND0_ALPHA_ARB                              0x8598
#define GL_OPERAND1_ALPHA_ARB                              0x8599
#define GL_OPERAND2_ALPHA_ARB                              0x859A
#define GL_RGB_SCALE_ARB                                   0x8573
#define GL_ADD_SIGNED_ARB                                  0x8574
#define GL_INTERPOLATE_ARB                                 0x8575
#define GL_SUBTRACT_ARB                                    0x84E7
#define GL_CONSTANT_ARB                                    0x8576
#define GL_PRIMARY_COLOR_ARB                               0x8577
#define GL_PREVIOUS_ARB                                    0x8578
#endif 

/* GL_ARB_texture_env_crossbar */

#ifndef GL_ARB_texture_env_crossbar
#define GL_ARB_texture_env_crossbar 1
#define __GLEE_GL_ARB_texture_env_crossbar 1
/* Constants */
#endif 

/* GL_ARB_texture_env_dot3 */

#ifndef GL_ARB_texture_env_dot3
#define GL_ARB_texture_env_dot3 1
#define __GLEE_GL_ARB_texture_env_dot3 1
/* Constants */
#define GL_DOT3_RGB_ARB                                    0x86AE
#define GL_DOT3_RGBA_ARB                                   0x86AF
#endif 

/* GL_ARB_texture_mirrored_repeat */

#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat 1
#define __GLEE_GL_ARB_texture_mirrored_repeat 1
/* Constants */
#define GL_MIRRORED_REPEAT_ARB                             0x8370
#endif 

/* GL_ARB_depth_texture */

#ifndef GL_ARB_depth_texture
#define GL_ARB_depth_texture 1
#define __GLEE_GL_ARB_depth_texture 1
/* Constants */
#define GL_DEPTH_COMPONENT16_ARB                           0x81A5
#define GL_DEPTH_COMPONENT24_ARB                           0x81A6
#define GL_DEPTH_COMPONENT32_ARB                           0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB                          0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB                          0x884B
#endif 

/* GL_ARB_shadow */

#ifndef GL_ARB_shadow
#define GL_ARB_shadow 1
#define __GLEE_GL_ARB_shadow 1
/* Constants */
#define GL_TEXTURE_COMPARE_MODE_ARB                        0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB                        0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB                        0x884E
#endif 

/* GL_ARB_shadow_ambient */

#ifndef GL_ARB_shadow_ambient
#define GL_ARB_shadow_ambient 1
#define __GLEE_GL_ARB_shadow_ambient 1
/* Constants */
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB                  0x80BF
#endif 

/* GL_ARB_window_pos */

#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos 1
#define __GLEE_GL_ARB_window_pos 1
/* Constants */
typedef void (APIENTRYP PFNGLWINDOWPOS2DARBPROC) (GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLWINDOWPOS2DVARBPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLWINDOWPOS2FARBPROC) (GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLWINDOWPOS2FVARBPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLWINDOWPOS2IARBPROC) (GLint x, GLint y);
typedef void (APIENTRYP PFNGLWINDOWPOS2IVARBPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLWINDOWPOS2SARBPROC) (GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLWINDOWPOS2SVARBPROC) (const GLshort * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3DARBPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLWINDOWPOS3DVARBPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3FARBPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLWINDOWPOS3FVARBPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3IARBPROC) (GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLWINDOWPOS3IVARBPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3SARBPROC) (GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLWINDOWPOS3SVARBPROC) (const GLshort * v);
GLEE_EXTERN PFNGLWINDOWPOS2DARBPROC pglWindowPos2dARB;
GLEE_EXTERN PFNGLWINDOWPOS2DVARBPROC pglWindowPos2dvARB;
GLEE_EXTERN PFNGLWINDOWPOS2FARBPROC pglWindowPos2fARB;
GLEE_EXTERN PFNGLWINDOWPOS2FVARBPROC pglWindowPos2fvARB;
GLEE_EXTERN PFNGLWINDOWPOS2IARBPROC pglWindowPos2iARB;
GLEE_EXTERN PFNGLWINDOWPOS2IVARBPROC pglWindowPos2ivARB;
GLEE_EXTERN PFNGLWINDOWPOS2SARBPROC pglWindowPos2sARB;
GLEE_EXTERN PFNGLWINDOWPOS2SVARBPROC pglWindowPos2svARB;
GLEE_EXTERN PFNGLWINDOWPOS3DARBPROC pglWindowPos3dARB;
GLEE_EXTERN PFNGLWINDOWPOS3DVARBPROC pglWindowPos3dvARB;
GLEE_EXTERN PFNGLWINDOWPOS3FARBPROC pglWindowPos3fARB;
GLEE_EXTERN PFNGLWINDOWPOS3FVARBPROC pglWindowPos3fvARB;
GLEE_EXTERN PFNGLWINDOWPOS3IARBPROC pglWindowPos3iARB;
GLEE_EXTERN PFNGLWINDOWPOS3IVARBPROC pglWindowPos3ivARB;
GLEE_EXTERN PFNGLWINDOWPOS3SARBPROC pglWindowPos3sARB;
GLEE_EXTERN PFNGLWINDOWPOS3SVARBPROC pglWindowPos3svARB;
#define glWindowPos2dARB pglWindowPos2dARB
#define glWindowPos2dvARB pglWindowPos2dvARB
#define glWindowPos2fARB pglWindowPos2fARB
#define glWindowPos2fvARB pglWindowPos2fvARB
#define glWindowPos2iARB pglWindowPos2iARB
#define glWindowPos2ivARB pglWindowPos2ivARB
#define glWindowPos2sARB pglWindowPos2sARB
#define glWindowPos2svARB pglWindowPos2svARB
#define glWindowPos3dARB pglWindowPos3dARB
#define glWindowPos3dvARB pglWindowPos3dvARB
#define glWindowPos3fARB pglWindowPos3fARB
#define glWindowPos3fvARB pglWindowPos3fvARB
#define glWindowPos3iARB pglWindowPos3iARB
#define glWindowPos3ivARB pglWindowPos3ivARB
#define glWindowPos3sARB pglWindowPos3sARB
#define glWindowPos3svARB pglWindowPos3svARB
#endif 

/* GL_ARB_vertex_program */

#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program 1
#define __GLEE_GL_ARB_vertex_program 1
/* Constants */
#define GL_COLOR_SUM_ARB                                   0x8458
#define GL_VERTEX_PROGRAM_ARB                              0x8620
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB                 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB                    0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB                  0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB                    0x8625
#define GL_CURRENT_VERTEX_ATTRIB_ARB                       0x8626
#define GL_PROGRAM_LENGTH_ARB                              0x8627
#define GL_PROGRAM_STRING_ARB                              0x8628
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB              0x862E
#define GL_MAX_PROGRAM_MATRICES_ARB                        0x862F
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB                  0x8640
#define GL_CURRENT_MATRIX_ARB                              0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB                   0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB                     0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB                 0x8645
#define GL_PROGRAM_ERROR_POSITION_ARB                      0x864B
#define GL_PROGRAM_BINDING_ARB                             0x8677
#define GL_MAX_VERTEX_ATTRIBS_ARB                          0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB              0x886A
#define GL_PROGRAM_ERROR_STRING_ARB                        0x8874
#define GL_PROGRAM_FORMAT_ASCII_ARB                        0x8875
#define GL_PROGRAM_FORMAT_ARB                              0x8876
#define GL_PROGRAM_INSTRUCTIONS_ARB                        0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB                    0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB                 0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB             0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB                         0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB                     0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB                  0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB              0x88A7
#define GL_PROGRAM_PARAMETERS_ARB                          0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB                      0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB                   0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB               0x88AB
#define GL_PROGRAM_ATTRIBS_ARB                             0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB                         0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB                      0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB                  0x88AF
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB                   0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB               0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB            0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB        0x88B3
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB                0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB                  0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB                 0x88B6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB                    0x88B7
#define GL_MATRIX0_ARB                                     0x88C0
#define GL_MATRIX1_ARB                                     0x88C1
#define GL_MATRIX2_ARB                                     0x88C2
#define GL_MATRIX3_ARB                                     0x88C3
#define GL_MATRIX4_ARB                                     0x88C4
#define GL_MATRIX5_ARB                                     0x88C5
#define GL_MATRIX6_ARB                                     0x88C6
#define GL_MATRIX7_ARB                                     0x88C7
#define GL_MATRIX8_ARB                                     0x88C8
#define GL_MATRIX9_ARB                                     0x88C9
#define GL_MATRIX10_ARB                                    0x88CA
#define GL_MATRIX11_ARB                                    0x88CB
#define GL_MATRIX12_ARB                                    0x88CC
#define GL_MATRIX13_ARB                                    0x88CD
#define GL_MATRIX14_ARB                                    0x88CE
#define GL_MATRIX15_ARB                                    0x88CF
#define GL_MATRIX16_ARB                                    0x88D0
#define GL_MATRIX17_ARB                                    0x88D1
#define GL_MATRIX18_ARB                                    0x88D2
#define GL_MATRIX19_ARB                                    0x88D3
#define GL_MATRIX20_ARB                                    0x88D4
#define GL_MATRIX21_ARB                                    0x88D5
#define GL_MATRIX22_ARB                                    0x88D6
#define GL_MATRIX23_ARB                                    0x88D7
#define GL_MATRIX24_ARB                                    0x88D8
#define GL_MATRIX25_ARB                                    0x88D9
#define GL_MATRIX26_ARB                                    0x88DA
#define GL_MATRIX27_ARB                                    0x88DB
#define GL_MATRIX28_ARB                                    0x88DC
#define GL_MATRIX29_ARB                                    0x88DD
#define GL_MATRIX30_ARB                                    0x88DE
#define GL_MATRIX31_ARB                                    0x88DF
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DARBPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVARBPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FARBPROC) (GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVARBPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SARBPROC) (GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVARBPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DARBPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVARBPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FARBPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVARBPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SARBPROC) (GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVARBPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DARBPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVARBPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FARBPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVARBPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SARBPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVARBPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVARBPROC) (GLuint index, const GLbyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVARBPROC) (GLuint index, const GLint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVARBPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBARBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVARBPROC) (GLuint index, const GLubyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVARBPROC) (GLuint index, const GLuint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVARBPROC) (GLuint index, const GLushort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVARBPROC) (GLuint index, const GLbyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DARBPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVARBPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FARBPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVARBPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVARBPROC) (GLuint index, const GLint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SARBPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVARBPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVARBPROC) (GLuint index, const GLubyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVARBPROC) (GLuint index, const GLuint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVARBPROC) (GLuint index, const GLushort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERARBPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYARBPROC) (GLuint index);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYARBPROC) (GLuint index);
typedef void (APIENTRYP PFNGLPROGRAMSTRINGARBPROC) (GLenum target, GLenum format, GLsizei len, const GLvoid * string);
typedef void (APIENTRYP PFNGLBINDPROGRAMARBPROC) (GLenum target, GLuint program);
typedef void (APIENTRYP PFNGLDELETEPROGRAMSARBPROC) (GLsizei n, const GLuint * programs);
typedef void (APIENTRYP PFNGLGENPROGRAMSARBPROC) (GLsizei n, GLuint * programs);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4DARBPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4DVARBPROC) (GLenum target, GLuint index, const GLdouble * params);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4FARBPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4FVARBPROC) (GLenum target, GLuint index, const GLfloat * params);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4DARBPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4DVARBPROC) (GLenum target, GLuint index, const GLdouble * params);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4FARBPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4FVARBPROC) (GLenum target, GLuint index, const GLfloat * params);
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERDVARBPROC) (GLenum target, GLuint index, GLdouble * params);
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERFVARBPROC) (GLenum target, GLuint index, GLfloat * params);
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC) (GLenum target, GLuint index, GLdouble * params);
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC) (GLenum target, GLuint index, GLfloat * params);
typedef void (APIENTRYP PFNGLGETPROGRAMIVARBPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETPROGRAMSTRINGARBPROC) (GLenum target, GLenum pname, GLvoid * string);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVARBPROC) (GLuint index, GLenum pname, GLdouble * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVARBPROC) (GLuint index, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVARBPROC) (GLuint index, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVARBPROC) (GLuint index, GLenum pname, GLvoid* * pointer);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMARBPROC) (GLuint program);
GLEE_EXTERN PFNGLVERTEXATTRIB1DARBPROC pglVertexAttrib1dARB;
GLEE_EXTERN PFNGLVERTEXATTRIB1DVARBPROC pglVertexAttrib1dvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB1FARBPROC pglVertexAttrib1fARB;
GLEE_EXTERN PFNGLVERTEXATTRIB1FVARBPROC pglVertexAttrib1fvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB1SARBPROC pglVertexAttrib1sARB;
GLEE_EXTERN PFNGLVERTEXATTRIB1SVARBPROC pglVertexAttrib1svARB;
GLEE_EXTERN PFNGLVERTEXATTRIB2DARBPROC pglVertexAttrib2dARB;
GLEE_EXTERN PFNGLVERTEXATTRIB2DVARBPROC pglVertexAttrib2dvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB2FARBPROC pglVertexAttrib2fARB;
GLEE_EXTERN PFNGLVERTEXATTRIB2FVARBPROC pglVertexAttrib2fvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB2SARBPROC pglVertexAttrib2sARB;
GLEE_EXTERN PFNGLVERTEXATTRIB2SVARBPROC pglVertexAttrib2svARB;
GLEE_EXTERN PFNGLVERTEXATTRIB3DARBPROC pglVertexAttrib3dARB;
GLEE_EXTERN PFNGLVERTEXATTRIB3DVARBPROC pglVertexAttrib3dvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB3FARBPROC pglVertexAttrib3fARB;
GLEE_EXTERN PFNGLVERTEXATTRIB3FVARBPROC pglVertexAttrib3fvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB3SARBPROC pglVertexAttrib3sARB;
GLEE_EXTERN PFNGLVERTEXATTRIB3SVARBPROC pglVertexAttrib3svARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4NBVARBPROC pglVertexAttrib4NbvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4NIVARBPROC pglVertexAttrib4NivARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4NSVARBPROC pglVertexAttrib4NsvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4NUBARBPROC pglVertexAttrib4NubARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4NUBVARBPROC pglVertexAttrib4NubvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4NUIVARBPROC pglVertexAttrib4NuivARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4NUSVARBPROC pglVertexAttrib4NusvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4BVARBPROC pglVertexAttrib4bvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4DARBPROC pglVertexAttrib4dARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4DVARBPROC pglVertexAttrib4dvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4FARBPROC pglVertexAttrib4fARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4FVARBPROC pglVertexAttrib4fvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4IVARBPROC pglVertexAttrib4ivARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4SARBPROC pglVertexAttrib4sARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4SVARBPROC pglVertexAttrib4svARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4UBVARBPROC pglVertexAttrib4ubvARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4UIVARBPROC pglVertexAttrib4uivARB;
GLEE_EXTERN PFNGLVERTEXATTRIB4USVARBPROC pglVertexAttrib4usvARB;
GLEE_EXTERN PFNGLVERTEXATTRIBPOINTERARBPROC pglVertexAttribPointerARB;
GLEE_EXTERN PFNGLENABLEVERTEXATTRIBARRAYARBPROC pglEnableVertexAttribArrayARB;
GLEE_EXTERN PFNGLDISABLEVERTEXATTRIBARRAYARBPROC pglDisableVertexAttribArrayARB;
GLEE_EXTERN PFNGLPROGRAMSTRINGARBPROC pglProgramStringARB;
GLEE_EXTERN PFNGLBINDPROGRAMARBPROC pglBindProgramARB;
GLEE_EXTERN PFNGLDELETEPROGRAMSARBPROC pglDeleteProgramsARB;
GLEE_EXTERN PFNGLGENPROGRAMSARBPROC pglGenProgramsARB;
GLEE_EXTERN PFNGLPROGRAMENVPARAMETER4DARBPROC pglProgramEnvParameter4dARB;
GLEE_EXTERN PFNGLPROGRAMENVPARAMETER4DVARBPROC pglProgramEnvParameter4dvARB;
GLEE_EXTERN PFNGLPROGRAMENVPARAMETER4FARBPROC pglProgramEnvParameter4fARB;
GLEE_EXTERN PFNGLPROGRAMENVPARAMETER4FVARBPROC pglProgramEnvParameter4fvARB;
GLEE_EXTERN PFNGLPROGRAMLOCALPARAMETER4DARBPROC pglProgramLocalParameter4dARB;
GLEE_EXTERN PFNGLPROGRAMLOCALPARAMETER4DVARBPROC pglProgramLocalParameter4dvARB;
GLEE_EXTERN PFNGLPROGRAMLOCALPARAMETER4FARBPROC pglProgramLocalParameter4fARB;
GLEE_EXTERN PFNGLPROGRAMLOCALPARAMETER4FVARBPROC pglProgramLocalParameter4fvARB;
GLEE_EXTERN PFNGLGETPROGRAMENVPARAMETERDVARBPROC pglGetProgramEnvParameterdvARB;
GLEE_EXTERN PFNGLGETPROGRAMENVPARAMETERFVARBPROC pglGetProgramEnvParameterfvARB;
GLEE_EXTERN PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC pglGetProgramLocalParameterdvARB;
GLEE_EXTERN PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC pglGetProgramLocalParameterfvARB;
GLEE_EXTERN PFNGLGETPROGRAMIVARBPROC pglGetProgramivARB;
GLEE_EXTERN PFNGLGETPROGRAMSTRINGARBPROC pglGetProgramStringARB;
GLEE_EXTERN PFNGLGETVERTEXATTRIBDVARBPROC pglGetVertexAttribdvARB;
GLEE_EXTERN PFNGLGETVERTEXATTRIBFVARBPROC pglGetVertexAttribfvARB;
GLEE_EXTERN PFNGLGETVERTEXATTRIBIVARBPROC pglGetVertexAttribivARB;
GLEE_EXTERN PFNGLGETVERTEXATTRIBPOINTERVARBPROC pglGetVertexAttribPointervARB;
GLEE_EXTERN PFNGLISPROGRAMARBPROC pglIsProgramARB;
#define glVertexAttrib1dARB pglVertexAttrib1dARB
#define glVertexAttrib1dvARB pglVertexAttrib1dvARB
#define glVertexAttrib1fARB pglVertexAttrib1fARB
#define glVertexAttrib1fvARB pglVertexAttrib1fvARB
#define glVertexAttrib1sARB pglVertexAttrib1sARB
#define glVertexAttrib1svARB pglVertexAttrib1svARB
#define glVertexAttrib2dARB pglVertexAttrib2dARB
#define glVertexAttrib2dvARB pglVertexAttrib2dvARB
#define glVertexAttrib2fARB pglVertexAttrib2fARB
#define glVertexAttrib2fvARB pglVertexAttrib2fvARB
#define glVertexAttrib2sARB pglVertexAttrib2sARB
#define glVertexAttrib2svARB pglVertexAttrib2svARB
#define glVertexAttrib3dARB pglVertexAttrib3dARB
#define glVertexAttrib3dvARB pglVertexAttrib3dvARB
#define glVertexAttrib3fARB pglVertexAttrib3fARB
#define glVertexAttrib3fvARB pglVertexAttrib3fvARB
#define glVertexAttrib3sARB pglVertexAttrib3sARB
#define glVertexAttrib3svARB pglVertexAttrib3svARB
#define glVertexAttrib4NbvARB pglVertexAttrib4NbvARB
#define glVertexAttrib4NivARB pglVertexAttrib4NivARB
#define glVertexAttrib4NsvARB pglVertexAttrib4NsvARB
#define glVertexAttrib4NubARB pglVertexAttrib4NubARB
#define glVertexAttrib4NubvARB pglVertexAttrib4NubvARB
#define glVertexAttrib4NuivARB pglVertexAttrib4NuivARB
#define glVertexAttrib4NusvARB pglVertexAttrib4NusvARB
#define glVertexAttrib4bvARB pglVertexAttrib4bvARB
#define glVertexAttrib4dARB pglVertexAttrib4dARB
#define glVertexAttrib4dvARB pglVertexAttrib4dvARB
#define glVertexAttrib4fARB pglVertexAttrib4fARB
#define glVertexAttrib4fvARB pglVertexAttrib4fvARB
#define glVertexAttrib4ivARB pglVertexAttrib4ivARB
#define glVertexAttrib4sARB pglVertexAttrib4sARB
#define glVertexAttrib4svARB pglVertexAttrib4svARB
#define glVertexAttrib4ubvARB pglVertexAttrib4ubvARB
#define glVertexAttrib4uivARB pglVertexAttrib4uivARB
#define glVertexAttrib4usvARB pglVertexAttrib4usvARB
#define glVertexAttribPointerARB pglVertexAttribPointerARB
#define glEnableVertexAttribArrayARB pglEnableVertexAttribArrayARB
#define glDisableVertexAttribArrayARB pglDisableVertexAttribArrayARB
#define glProgramStringARB pglProgramStringARB
#define glBindProgramARB pglBindProgramARB
#define glDeleteProgramsARB pglDeleteProgramsARB
#define glGenProgramsARB pglGenProgramsARB
#define glProgramEnvParameter4dARB pglProgramEnvParameter4dARB
#define glProgramEnvParameter4dvARB pglProgramEnvParameter4dvARB
#define glProgramEnvParameter4fARB pglProgramEnvParameter4fARB
#define glProgramEnvParameter4fvARB pglProgramEnvParameter4fvARB
#define glProgramLocalParameter4dARB pglProgramLocalParameter4dARB
#define glProgramLocalParameter4dvARB pglProgramLocalParameter4dvARB
#define glProgramLocalParameter4fARB pglProgramLocalParameter4fARB
#define glProgramLocalParameter4fvARB pglProgramLocalParameter4fvARB
#define glGetProgramEnvParameterdvARB pglGetProgramEnvParameterdvARB
#define glGetProgramEnvParameterfvARB pglGetProgramEnvParameterfvARB
#define glGetProgramLocalParameterdvARB pglGetProgramLocalParameterdvARB
#define glGetProgramLocalParameterfvARB pglGetProgramLocalParameterfvARB
#define glGetProgramivARB pglGetProgramivARB
#define glGetProgramStringARB pglGetProgramStringARB
#define glGetVertexAttribdvARB pglGetVertexAttribdvARB
#define glGetVertexAttribfvARB pglGetVertexAttribfvARB
#define glGetVertexAttribivARB pglGetVertexAttribivARB
#define glGetVertexAttribPointervARB pglGetVertexAttribPointervARB
#define glIsProgramARB pglIsProgramARB
#endif 

/* GL_ARB_fragment_program */

#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program 1
#define __GLEE_GL_ARB_fragment_program 1
/* Constants */
#define GL_FRAGMENT_PROGRAM_ARB                            0x8804
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB                    0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB                    0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB                    0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB             0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB             0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB             0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB                0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB                0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB                0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB         0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB         0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB         0x8810
#define GL_MAX_TEXTURE_COORDS_ARB                          0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB                     0x8872
#endif 

/* GL_ARB_vertex_buffer_object */

#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object 1
#define __GLEE_GL_ARB_vertex_buffer_object 1
/* Constants */
#define GL_BUFFER_SIZE_ARB                                 0x8764
#define GL_BUFFER_USAGE_ARB                                0x8765
#define GL_ARRAY_BUFFER_ARB                                0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB                        0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB                        0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB                0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB                 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB                 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB                  0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB                  0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB          0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB              0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB        0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB         0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB                 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB          0x889F
#define GL_READ_ONLY_ARB                                   0x88B8
#define GL_WRITE_ONLY_ARB                                  0x88B9
#define GL_READ_WRITE_ARB                                  0x88BA
#define GL_BUFFER_ACCESS_ARB                               0x88BB
#define GL_BUFFER_MAPPED_ARB                               0x88BC
#define GL_BUFFER_MAP_POINTER_ARB                          0x88BD
#define GL_STREAM_DRAW_ARB                                 0x88E0
#define GL_STREAM_READ_ARB                                 0x88E1
#define GL_STREAM_COPY_ARB                                 0x88E2
#define GL_STATIC_DRAW_ARB                                 0x88E4
#define GL_STATIC_READ_ARB                                 0x88E5
#define GL_STATIC_COPY_ARB                                 0x88E6
#define GL_DYNAMIC_DRAW_ARB                                0x88E8
#define GL_DYNAMIC_READ_ARB                                0x88E9
#define GL_DYNAMIC_COPY_ARB                                0x88EA
typedef void (APIENTRYP PFNGLBINDBUFFERARBPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLDELETEBUFFERSARBPROC) (GLsizei n, const GLuint * buffers);
typedef void (APIENTRYP PFNGLGENBUFFERSARBPROC) (GLsizei n, GLuint * buffers);
typedef GLboolean (APIENTRYP PFNGLISBUFFERARBPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLBUFFERDATAARBPROC) (GLenum target, GLsizeiptrARB size, const GLvoid * data, GLenum usage);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAARBPROC) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid * data);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAARBPROC) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid * data);
typedef GLvoid* (APIENTRYP PFNGLMAPBUFFERARBPROC) (GLenum target, GLenum access);
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERARBPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVARBPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVARBPROC) (GLenum target, GLenum pname, GLvoid* * params);
GLEE_EXTERN PFNGLBINDBUFFERARBPROC pglBindBufferARB;
GLEE_EXTERN PFNGLDELETEBUFFERSARBPROC pglDeleteBuffersARB;
GLEE_EXTERN PFNGLGENBUFFERSARBPROC pglGenBuffersARB;
GLEE_EXTERN PFNGLISBUFFERARBPROC pglIsBufferARB;
GLEE_EXTERN PFNGLBUFFERDATAARBPROC pglBufferDataARB;
GLEE_EXTERN PFNGLBUFFERSUBDATAARBPROC pglBufferSubDataARB;
GLEE_EXTERN PFNGLGETBUFFERSUBDATAARBPROC pglGetBufferSubDataARB;
GLEE_EXTERN PFNGLMAPBUFFERARBPROC pglMapBufferARB;
GLEE_EXTERN PFNGLUNMAPBUFFERARBPROC pglUnmapBufferARB;
GLEE_EXTERN PFNGLGETBUFFERPARAMETERIVARBPROC pglGetBufferParameterivARB;
GLEE_EXTERN PFNGLGETBUFFERPOINTERVARBPROC pglGetBufferPointervARB;
#define glBindBufferARB pglBindBufferARB
#define glDeleteBuffersARB pglDeleteBuffersARB
#define glGenBuffersARB pglGenBuffersARB
#define glIsBufferARB pglIsBufferARB
#define glBufferDataARB pglBufferDataARB
#define glBufferSubDataARB pglBufferSubDataARB
#define glGetBufferSubDataARB pglGetBufferSubDataARB
#define glMapBufferARB pglMapBufferARB
#define glUnmapBufferARB pglUnmapBufferARB
#define glGetBufferParameterivARB pglGetBufferParameterivARB
#define glGetBufferPointervARB pglGetBufferPointervARB
#endif 

/* GL_ARB_occlusion_query */

#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query 1
#define __GLEE_GL_ARB_occlusion_query 1
/* Constants */
#define GL_QUERY_COUNTER_BITS_ARB                          0x8864
#define GL_CURRENT_QUERY_ARB                               0x8865
#define GL_QUERY_RESULT_ARB                                0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB                      0x8867
#define GL_SAMPLES_PASSED_ARB                              0x8914
typedef void (APIENTRYP PFNGLGENQUERIESARBPROC) (GLsizei n, GLuint * ids);
typedef void (APIENTRYP PFNGLDELETEQUERIESARBPROC) (GLsizei n, const GLuint * ids);
typedef GLboolean (APIENTRYP PFNGLISQUERYARBPROC) (GLuint id);
typedef void (APIENTRYP PFNGLBEGINQUERYARBPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYARBPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYIVARBPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVARBPROC) (GLuint id, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVARBPROC) (GLuint id, GLenum pname, GLuint * params);
GLEE_EXTERN PFNGLGENQUERIESARBPROC pglGenQueriesARB;
GLEE_EXTERN PFNGLDELETEQUERIESARBPROC pglDeleteQueriesARB;
GLEE_EXTERN PFNGLISQUERYARBPROC pglIsQueryARB;
GLEE_EXTERN PFNGLBEGINQUERYARBPROC pglBeginQueryARB;
GLEE_EXTERN PFNGLENDQUERYARBPROC pglEndQueryARB;
GLEE_EXTERN PFNGLGETQUERYIVARBPROC pglGetQueryivARB;
GLEE_EXTERN PFNGLGETQUERYOBJECTIVARBPROC pglGetQueryObjectivARB;
GLEE_EXTERN PFNGLGETQUERYOBJECTUIVARBPROC pglGetQueryObjectuivARB;
#define glGenQueriesARB pglGenQueriesARB
#define glDeleteQueriesARB pglDeleteQueriesARB
#define glIsQueryARB pglIsQueryARB
#define glBeginQueryARB pglBeginQueryARB
#define glEndQueryARB pglEndQueryARB
#define glGetQueryivARB pglGetQueryivARB
#define glGetQueryObjectivARB pglGetQueryObjectivARB
#define glGetQueryObjectuivARB pglGetQueryObjectuivARB
#endif 

/* GL_ARB_shader_objects */

#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects 1
#define __GLEE_GL_ARB_shader_objects 1
/* Constants */
#define GL_PROGRAM_OBJECT_ARB                              0x8B40
#define GL_SHADER_OBJECT_ARB                               0x8B48
#define GL_OBJECT_TYPE_ARB                                 0x8B4E
#define GL_OBJECT_SUBTYPE_ARB                              0x8B4F
#define GL_FLOAT_VEC2_ARB                                  0x8B50
#define GL_FLOAT_VEC3_ARB                                  0x8B51
#define GL_FLOAT_VEC4_ARB                                  0x8B52
#define GL_INT_VEC2_ARB                                    0x8B53
#define GL_INT_VEC3_ARB                                    0x8B54
#define GL_INT_VEC4_ARB                                    0x8B55
#define GL_BOOL_ARB                                        0x8B56
#define GL_BOOL_VEC2_ARB                                   0x8B57
#define GL_BOOL_VEC3_ARB                                   0x8B58
#define GL_BOOL_VEC4_ARB                                   0x8B59
#define GL_FLOAT_MAT2_ARB                                  0x8B5A
#define GL_FLOAT_MAT3_ARB                                  0x8B5B
#define GL_FLOAT_MAT4_ARB                                  0x8B5C
#define GL_SAMPLER_1D_ARB                                  0x8B5D
#define GL_SAMPLER_2D_ARB                                  0x8B5E
#define GL_SAMPLER_3D_ARB                                  0x8B5F
#define GL_SAMPLER_CUBE_ARB                                0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB                           0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB                           0x8B62
#define GL_SAMPLER_2D_RECT_ARB                             0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB                      0x8B64
#define GL_OBJECT_DELETE_STATUS_ARB                        0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB                       0x8B81
#define GL_OBJECT_LINK_STATUS_ARB                          0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB                      0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB                      0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB                     0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB                      0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB            0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB                 0x8B88
typedef void (APIENTRYP PFNGLDELETEOBJECTARBPROC) (GLhandleARB obj);
typedef GLhandleARB (APIENTRYP PFNGLGETHANDLEARBPROC) (GLenum pname);
typedef void (APIENTRYP PFNGLDETACHOBJECTARBPROC) (GLhandleARB containerObj, GLhandleARB attachedObj);
typedef GLhandleARB (APIENTRYP PFNGLCREATESHADEROBJECTARBPROC) (GLenum shaderType);
typedef void (APIENTRYP PFNGLSHADERSOURCEARBPROC) (GLhandleARB shaderObj, GLsizei count, const GLcharARB* * string, const GLint * length);
typedef void (APIENTRYP PFNGLCOMPILESHADERARBPROC) (GLhandleARB shaderObj);
typedef GLhandleARB (APIENTRYP PFNGLCREATEPROGRAMOBJECTARBPROC) ();
typedef void (APIENTRYP PFNGLATTACHOBJECTARBPROC) (GLhandleARB containerObj, GLhandleARB obj);
typedef void (APIENTRYP PFNGLLINKPROGRAMARBPROC) (GLhandleARB programObj);
typedef void (APIENTRYP PFNGLUSEPROGRAMOBJECTARBPROC) (GLhandleARB programObj);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMARBPROC) (GLhandleARB programObj);
typedef void (APIENTRYP PFNGLUNIFORM1FARBPROC) (GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM2FARBPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM3FARBPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM4FARBPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM1IARBPROC) (GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM2IARBPROC) (GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM3IARBPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM4IARBPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM1FVARBPROC) (GLint location, GLsizei count, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORM2FVARBPROC) (GLint location, GLsizei count, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORM3FVARBPROC) (GLint location, GLsizei count, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORM4FVARBPROC) (GLint location, GLsizei count, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORM1IVARBPROC) (GLint location, GLsizei count, const GLint * value);
typedef void (APIENTRYP PFNGLUNIFORM2IVARBPROC) (GLint location, GLsizei count, const GLint * value);
typedef void (APIENTRYP PFNGLUNIFORM3IVARBPROC) (GLint location, GLsizei count, const GLint * value);
typedef void (APIENTRYP PFNGLUNIFORM4IVARBPROC) (GLint location, GLsizei count, const GLint * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (APIENTRYP PFNGLGETOBJECTPARAMETERFVARBPROC) (GLhandleARB obj, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETOBJECTPARAMETERIVARBPROC) (GLhandleARB obj, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETINFOLOGARBPROC) (GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * infoLog);
typedef void (APIENTRYP PFNGLGETATTACHEDOBJECTSARBPROC) (GLhandleARB containerObj, GLsizei maxCount, GLsizei * count, GLhandleARB * obj);
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONARBPROC) (GLhandleARB programObj, const GLcharARB * name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMARBPROC) (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name);
typedef void (APIENTRYP PFNGLGETUNIFORMFVARBPROC) (GLhandleARB programObj, GLint location, GLfloat * params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVARBPROC) (GLhandleARB programObj, GLint location, GLint * params);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEARBPROC) (GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * source);
GLEE_EXTERN PFNGLDELETEOBJECTARBPROC pglDeleteObjectARB;
GLEE_EXTERN PFNGLGETHANDLEARBPROC pglGetHandleARB;
GLEE_EXTERN PFNGLDETACHOBJECTARBPROC pglDetachObjectARB;
GLEE_EXTERN PFNGLCREATESHADEROBJECTARBPROC pglCreateShaderObjectARB;
GLEE_EXTERN PFNGLSHADERSOURCEARBPROC pglShaderSourceARB;
GLEE_EXTERN PFNGLCOMPILESHADERARBPROC pglCompileShaderARB;
GLEE_EXTERN PFNGLCREATEPROGRAMOBJECTARBPROC pglCreateProgramObjectARB;
GLEE_EXTERN PFNGLATTACHOBJECTARBPROC pglAttachObjectARB;
GLEE_EXTERN PFNGLLINKPROGRAMARBPROC pglLinkProgramARB;
GLEE_EXTERN PFNGLUSEPROGRAMOBJECTARBPROC pglUseProgramObjectARB;
GLEE_EXTERN PFNGLVALIDATEPROGRAMARBPROC pglValidateProgramARB;
GLEE_EXTERN PFNGLUNIFORM1FARBPROC pglUniform1fARB;
GLEE_EXTERN PFNGLUNIFORM2FARBPROC pglUniform2fARB;
GLEE_EXTERN PFNGLUNIFORM3FARBPROC pglUniform3fARB;
GLEE_EXTERN PFNGLUNIFORM4FARBPROC pglUniform4fARB;
GLEE_EXTERN PFNGLUNIFORM1IARBPROC pglUniform1iARB;
GLEE_EXTERN PFNGLUNIFORM2IARBPROC pglUniform2iARB;
GLEE_EXTERN PFNGLUNIFORM3IARBPROC pglUniform3iARB;
GLEE_EXTERN PFNGLUNIFORM4IARBPROC pglUniform4iARB;
GLEE_EXTERN PFNGLUNIFORM1FVARBPROC pglUniform1fvARB;
GLEE_EXTERN PFNGLUNIFORM2FVARBPROC pglUniform2fvARB;
GLEE_EXTERN PFNGLUNIFORM3FVARBPROC pglUniform3fvARB;
GLEE_EXTERN PFNGLUNIFORM4FVARBPROC pglUniform4fvARB;
GLEE_EXTERN PFNGLUNIFORM1IVARBPROC pglUniform1ivARB;
GLEE_EXTERN PFNGLUNIFORM2IVARBPROC pglUniform2ivARB;
GLEE_EXTERN PFNGLUNIFORM3IVARBPROC pglUniform3ivARB;
GLEE_EXTERN PFNGLUNIFORM4IVARBPROC pglUniform4ivARB;
GLEE_EXTERN PFNGLUNIFORMMATRIX2FVARBPROC pglUniformMatrix2fvARB;
GLEE_EXTERN PFNGLUNIFORMMATRIX3FVARBPROC pglUniformMatrix3fvARB;
GLEE_EXTERN PFNGLUNIFORMMATRIX4FVARBPROC pglUniformMatrix4fvARB;
GLEE_EXTERN PFNGLGETOBJECTPARAMETERFVARBPROC pglGetObjectParameterfvARB;
GLEE_EXTERN PFNGLGETOBJECTPARAMETERIVARBPROC pglGetObjectParameterivARB;
GLEE_EXTERN PFNGLGETINFOLOGARBPROC pglGetInfoLogARB;
GLEE_EXTERN PFNGLGETATTACHEDOBJECTSARBPROC pglGetAttachedObjectsARB;
GLEE_EXTERN PFNGLGETUNIFORMLOCATIONARBPROC pglGetUniformLocationARB;
GLEE_EXTERN PFNGLGETACTIVEUNIFORMARBPROC pglGetActiveUniformARB;
GLEE_EXTERN PFNGLGETUNIFORMFVARBPROC pglGetUniformfvARB;
GLEE_EXTERN PFNGLGETUNIFORMIVARBPROC pglGetUniformivARB;
GLEE_EXTERN PFNGLGETSHADERSOURCEARBPROC pglGetShaderSourceARB;
#define glDeleteObjectARB pglDeleteObjectARB
#define glGetHandleARB pglGetHandleARB
#define glDetachObjectARB pglDetachObjectARB
#define glCreateShaderObjectARB pglCreateShaderObjectARB
#define glShaderSourceARB pglShaderSourceARB
#define glCompileShaderARB pglCompileShaderARB
#define glCreateProgramObjectARB pglCreateProgramObjectARB
#define glAttachObjectARB pglAttachObjectARB
#define glLinkProgramARB pglLinkProgramARB
#define glUseProgramObjectARB pglUseProgramObjectARB
#define glValidateProgramARB pglValidateProgramARB
#define glUniform1fARB pglUniform1fARB
#define glUniform2fARB pglUniform2fARB
#define glUniform3fARB pglUniform3fARB
#define glUniform4fARB pglUniform4fARB
#define glUniform1iARB pglUniform1iARB
#define glUniform2iARB pglUniform2iARB
#define glUniform3iARB pglUniform3iARB
#define glUniform4iARB pglUniform4iARB
#define glUniform1fvARB pglUniform1fvARB
#define glUniform2fvARB pglUniform2fvARB
#define glUniform3fvARB pglUniform3fvARB
#define glUniform4fvARB pglUniform4fvARB
#define glUniform1ivARB pglUniform1ivARB
#define glUniform2ivARB pglUniform2ivARB
#define glUniform3ivARB pglUniform3ivARB
#define glUniform4ivARB pglUniform4ivARB
#define glUniformMatrix2fvARB pglUniformMatrix2fvARB
#define glUniformMatrix3fvARB pglUniformMatrix3fvARB
#define glUniformMatrix4fvARB pglUniformMatrix4fvARB
#define glGetObjectParameterfvARB pglGetObjectParameterfvARB
#define glGetObjectParameterivARB pglGetObjectParameterivARB
#define glGetInfoLogARB pglGetInfoLogARB
#define glGetAttachedObjectsARB pglGetAttachedObjectsARB
#define glGetUniformLocationARB pglGetUniformLocationARB
#define glGetActiveUniformARB pglGetActiveUniformARB
#define glGetUniformfvARB pglGetUniformfvARB
#define glGetUniformivARB pglGetUniformivARB
#define glGetShaderSourceARB pglGetShaderSourceARB
#endif 

/* GL_ARB_vertex_shader */

#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader 1
#define __GLEE_GL_ARB_vertex_shader 1
/* Constants */
#define GL_VERTEX_SHADER_ARB                               0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB               0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB                          0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB              0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB            0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB                    0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB          0x8B8A
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONARBPROC) (GLhandleARB programObj, GLuint index, const GLcharARB * name);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBARBPROC) (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name);
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONARBPROC) (GLhandleARB programObj, const GLcharARB * name);
GLEE_EXTERN PFNGLBINDATTRIBLOCATIONARBPROC pglBindAttribLocationARB;
GLEE_EXTERN PFNGLGETACTIVEATTRIBARBPROC pglGetActiveAttribARB;
GLEE_EXTERN PFNGLGETATTRIBLOCATIONARBPROC pglGetAttribLocationARB;
#define glBindAttribLocationARB pglBindAttribLocationARB
#define glGetActiveAttribARB pglGetActiveAttribARB
#define glGetAttribLocationARB pglGetAttribLocationARB
#endif 

/* GL_ARB_fragment_shader */

#ifndef GL_ARB_fragment_shader
#define GL_ARB_fragment_shader 1
#define __GLEE_GL_ARB_fragment_shader 1
/* Constants */
#define GL_FRAGMENT_SHADER_ARB                             0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB             0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB             0x8B8B
#endif 

/* GL_ARB_shading_language_100 */

#ifndef GL_ARB_shading_language_100
#define GL_ARB_shading_language_100 1
#define __GLEE_GL_ARB_shading_language_100 1
/* Constants */
#define GL_SHADING_LANGUAGE_VERSION_ARB                    0x8B8C
#endif 

/* GL_ARB_texture_non_power_of_two */

#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two 1
#define __GLEE_GL_ARB_texture_non_power_of_two 1
/* Constants */
#endif 

/* GL_ARB_point_sprite */

#ifndef GL_ARB_point_sprite
#define GL_ARB_point_sprite 1
#define __GLEE_GL_ARB_point_sprite 1
/* Constants */
#define GL_POINT_SPRITE_ARB                                0x8861
#define GL_COORD_REPLACE_ARB                               0x8862
#endif 

/* GL_ARB_fragment_program_shadow */

#ifndef GL_ARB_fragment_program_shadow
#define GL_ARB_fragment_program_shadow 1
#define __GLEE_GL_ARB_fragment_program_shadow 1
/* Constants */
#endif 

/* GL_ARB_draw_buffers */

#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1
#define __GLEE_GL_ARB_draw_buffers 1
/* Constants */
#define GL_MAX_DRAW_BUFFERS_ARB                            0x8824
#define GL_DRAW_BUFFER0_ARB                                0x8825
#define GL_DRAW_BUFFER1_ARB                                0x8826
#define GL_DRAW_BUFFER2_ARB                                0x8827
#define GL_DRAW_BUFFER3_ARB                                0x8828
#define GL_DRAW_BUFFER4_ARB                                0x8829
#define GL_DRAW_BUFFER5_ARB                                0x882A
#define GL_DRAW_BUFFER6_ARB                                0x882B
#define GL_DRAW_BUFFER7_ARB                                0x882C
#define GL_DRAW_BUFFER8_ARB                                0x882D
#define GL_DRAW_BUFFER9_ARB                                0x882E
#define GL_DRAW_BUFFER10_ARB                               0x882F
#define GL_DRAW_BUFFER11_ARB                               0x8830
#define GL_DRAW_BUFFER12_ARB                               0x8831
#define GL_DRAW_BUFFER13_ARB                               0x8832
#define GL_DRAW_BUFFER14_ARB                               0x8833
#define GL_DRAW_BUFFER15_ARB                               0x8834
typedef void (APIENTRYP PFNGLDRAWBUFFERSARBPROC) (GLsizei n, const GLenum * bufs);
GLEE_EXTERN PFNGLDRAWBUFFERSARBPROC pglDrawBuffersARB;
#define glDrawBuffersARB pglDrawBuffersARB
#endif 

/* GL_ARB_texture_rectangle */

#ifndef GL_ARB_texture_rectangle
#define GL_ARB_texture_rectangle 1
#define __GLEE_GL_ARB_texture_rectangle 1
/* Constants */
#define GL_TEXTURE_RECTANGLE_ARB                           0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB                   0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB                     0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB                  0x84F8
#endif 

/* GL_ARB_color_buffer_float */

#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1
#define __GLEE_GL_ARB_color_buffer_float 1
/* Constants */
#define GL_RGBA_FLOAT_MODE_ARB                             0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB                          0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB                        0x891B
#define GL_CLAMP_READ_COLOR_ARB                            0x891C
#define GL_FIXED_ONLY_ARB                                  0x891D
typedef void (APIENTRYP PFNGLCLAMPCOLORARBPROC) (GLenum target, GLenum clamp);
GLEE_EXTERN PFNGLCLAMPCOLORARBPROC pglClampColorARB;
#define glClampColorARB pglClampColorARB
#endif 

/* GL_ARB_half_float_pixel */

#ifndef GL_ARB_half_float_pixel
#define GL_ARB_half_float_pixel 1
#define __GLEE_GL_ARB_half_float_pixel 1
/* Constants */
#define GL_HALF_FLOAT_ARB                                  0x140B
#endif 

/* GL_ARB_texture_float */

#ifndef GL_ARB_texture_float
#define GL_ARB_texture_float 1
#define __GLEE_GL_ARB_texture_float 1
/* Constants */
#define GL_TEXTURE_RED_TYPE_ARB                            0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB                          0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB                           0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB                          0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB                      0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB                      0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB                          0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB                         0x8C17
#define GL_RGBA32F_ARB                                     0x8814
#define GL_RGB32F_ARB                                      0x8815
#define GL_ALPHA32F_ARB                                    0x8816
#define GL_INTENSITY32F_ARB                                0x8817
#define GL_LUMINANCE32F_ARB                                0x8818
#define GL_LUMINANCE_ALPHA32F_ARB                          0x8819
#define GL_RGBA16F_ARB                                     0x881A
#define GL_RGB16F_ARB                                      0x881B
#define GL_ALPHA16F_ARB                                    0x881C
#define GL_INTENSITY16F_ARB                                0x881D
#define GL_LUMINANCE16F_ARB                                0x881E
#define GL_LUMINANCE_ALPHA16F_ARB                          0x881F
#endif 

/* GL_ARB_pixel_buffer_object */

#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object 1
#define __GLEE_GL_ARB_pixel_buffer_object 1
/* Constants */
#define GL_PIXEL_PACK_BUFFER_ARB                           0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB                         0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB                   0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB                 0x88EF
#endif 

/* GL_EXT_abgr */

#ifndef GL_EXT_abgr
#define GL_EXT_abgr 1
#define __GLEE_GL_EXT_abgr 1
/* Constants */
#define GL_ABGR_EXT                                        0x8000
#endif 

/* GL_EXT_blend_color */

#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color 1
#define __GLEE_GL_EXT_blend_color 1
/* Constants */
#define GL_CONSTANT_COLOR_EXT                              0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT                    0x8002
#define GL_CONSTANT_ALPHA_EXT                              0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT                    0x8004
#define GL_BLEND_COLOR_EXT                                 0x8005
typedef void (APIENTRYP PFNGLBLENDCOLOREXTPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
GLEE_EXTERN PFNGLBLENDCOLOREXTPROC pglBlendColorEXT;
#define glBlendColorEXT pglBlendColorEXT
#endif 

/* GL_EXT_polygon_offset */

#ifndef GL_EXT_polygon_offset
#define GL_EXT_polygon_offset 1
#define __GLEE_GL_EXT_polygon_offset 1
/* Constants */
#define GL_POLYGON_OFFSET_EXT                              0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT                       0x8038
#define GL_POLYGON_OFFSET_BIAS_EXT                         0x8039
typedef void (APIENTRYP PFNGLPOLYGONOFFSETEXTPROC) (GLfloat factor, GLfloat bias);
GLEE_EXTERN PFNGLPOLYGONOFFSETEXTPROC pglPolygonOffsetEXT;
#define glPolygonOffsetEXT pglPolygonOffsetEXT
#endif 

/* GL_EXT_texture */

#ifndef GL_EXT_texture
#define GL_EXT_texture 1
#define __GLEE_GL_EXT_texture 1
/* Constants */
#define GL_ALPHA4_EXT                                      0x803B
#define GL_ALPHA8_EXT                                      0x803C
#define GL_ALPHA12_EXT                                     0x803D
#define GL_ALPHA16_EXT                                     0x803E
#define GL_LUMINANCE4_EXT                                  0x803F
#define GL_LUMINANCE8_EXT                                  0x8040
#define GL_LUMINANCE12_EXT                                 0x8041
#define GL_LUMINANCE16_EXT                                 0x8042
#define GL_LUMINANCE4_ALPHA4_EXT                           0x8043
#define GL_LUMINANCE6_ALPHA2_EXT                           0x8044
#define GL_LUMINANCE8_ALPHA8_EXT                           0x8045
#define GL_LUMINANCE12_ALPHA4_EXT                          0x8046
#define GL_LUMINANCE12_ALPHA12_EXT                         0x8047
#define GL_LUMINANCE16_ALPHA16_EXT                         0x8048
#define GL_INTENSITY_EXT                                   0x8049
#define GL_INTENSITY4_EXT                                  0x804A
#define GL_INTENSITY8_EXT                                  0x804B
#define GL_INTENSITY12_EXT                                 0x804C
#define GL_INTENSITY16_EXT                                 0x804D
#define GL_RGB2_EXT                                        0x804E
#define GL_RGB4_EXT                                        0x804F
#define GL_RGB5_EXT                                        0x8050
#define GL_RGB8_EXT                                        0x8051
#define GL_RGB10_EXT                                       0x8052
#define GL_RGB12_EXT                                       0x8053
#define GL_RGB16_EXT                                       0x8054
#define GL_RGBA2_EXT                                       0x8055
#define GL_RGBA4_EXT                                       0x8056
#define GL_RGB5_A1_EXT                                     0x8057
#define GL_RGBA8_EXT                                       0x8058
#define GL_RGB10_A2_EXT                                    0x8059
#define GL_RGBA12_EXT                                      0x805A
#define GL_RGBA16_EXT                                      0x805B
#define GL_TEXTURE_RED_SIZE_EXT                            0x805C
#define GL_TEXTURE_GREEN_SIZE_EXT                          0x805D
#define GL_TEXTURE_BLUE_SIZE_EXT                           0x805E
#define GL_TEXTURE_ALPHA_SIZE_EXT                          0x805F
#define GL_TEXTURE_LUMINANCE_SIZE_EXT                      0x8060
#define GL_TEXTURE_INTENSITY_SIZE_EXT                      0x8061
#define GL_REPLACE_EXT                                     0x8062
#define GL_PROXY_TEXTURE_1D_EXT                            0x8063
#define GL_PROXY_TEXTURE_2D_EXT                            0x8064
#define GL_TEXTURE_TOO_LARGE_EXT                           0x8065
#endif 

/* GL_EXT_texture3D */

#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D 1
#define __GLEE_GL_EXT_texture3D 1
/* Constants */
#define GL_PACK_SKIP_IMAGES_EXT                            0x806B
#define GL_PACK_IMAGE_HEIGHT_EXT                           0x806C
#define GL_UNPACK_SKIP_IMAGES_EXT                          0x806D
#define GL_UNPACK_IMAGE_HEIGHT_EXT                         0x806E
#define GL_TEXTURE_3D_EXT                                  0x806F
#define GL_PROXY_TEXTURE_3D_EXT                            0x8070
#define GL_TEXTURE_DEPTH_EXT                               0x8071
#define GL_TEXTURE_WRAP_R_EXT                              0x8072
#define GL_MAX_3D_TEXTURE_SIZE_EXT                         0x8073
typedef void (APIENTRYP PFNGLTEXIMAGE3DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
GLEE_EXTERN PFNGLTEXIMAGE3DEXTPROC pglTexImage3DEXT;
GLEE_EXTERN PFNGLTEXSUBIMAGE3DEXTPROC pglTexSubImage3DEXT;
#define glTexImage3DEXT pglTexImage3DEXT
#define glTexSubImage3DEXT pglTexSubImage3DEXT
#endif 

/* GL_SGIS_texture_filter4 */

#ifndef GL_SGIS_texture_filter4
#define GL_SGIS_texture_filter4 1
#define __GLEE_GL_SGIS_texture_filter4 1
/* Constants */
#define GL_FILTER4_SGIS                                    0x8146
#define GL_TEXTURE_FILTER4_SIZE_SGIS                       0x8147
typedef void (APIENTRYP PFNGLGETTEXFILTERFUNCSGISPROC) (GLenum target, GLenum filter, GLfloat * weights);
typedef void (APIENTRYP PFNGLTEXFILTERFUNCSGISPROC) (GLenum target, GLenum filter, GLsizei n, const GLfloat * weights);
GLEE_EXTERN PFNGLGETTEXFILTERFUNCSGISPROC pglGetTexFilterFuncSGIS;
GLEE_EXTERN PFNGLTEXFILTERFUNCSGISPROC pglTexFilterFuncSGIS;
#define glGetTexFilterFuncSGIS pglGetTexFilterFuncSGIS
#define glTexFilterFuncSGIS pglTexFilterFuncSGIS
#endif 

/* GL_EXT_subtexture */

#ifndef GL_EXT_subtexture
#define GL_EXT_subtexture 1
#define __GLEE_GL_EXT_subtexture 1
/* Constants */
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
GLEE_EXTERN PFNGLTEXSUBIMAGE1DEXTPROC pglTexSubImage1DEXT;
GLEE_EXTERN PFNGLTEXSUBIMAGE2DEXTPROC pglTexSubImage2DEXT;
#define glTexSubImage1DEXT pglTexSubImage1DEXT
#define glTexSubImage2DEXT pglTexSubImage2DEXT
#endif 

/* GL_EXT_copy_texture */

#ifndef GL_EXT_copy_texture
#define GL_EXT_copy_texture 1
#define __GLEE_GL_EXT_copy_texture 1
/* Constants */
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLEE_EXTERN PFNGLCOPYTEXIMAGE1DEXTPROC pglCopyTexImage1DEXT;
GLEE_EXTERN PFNGLCOPYTEXIMAGE2DEXTPROC pglCopyTexImage2DEXT;
GLEE_EXTERN PFNGLCOPYTEXSUBIMAGE1DEXTPROC pglCopyTexSubImage1DEXT;
GLEE_EXTERN PFNGLCOPYTEXSUBIMAGE2DEXTPROC pglCopyTexSubImage2DEXT;
GLEE_EXTERN PFNGLCOPYTEXSUBIMAGE3DEXTPROC pglCopyTexSubImage3DEXT;
#define glCopyTexImage1DEXT pglCopyTexImage1DEXT
#define glCopyTexImage2DEXT pglCopyTexImage2DEXT
#define glCopyTexSubImage1DEXT pglCopyTexSubImage1DEXT
#define glCopyTexSubImage2DEXT pglCopyTexSubImage2DEXT
#define glCopyTexSubImage3DEXT pglCopyTexSubImage3DEXT
#endif 

/* GL_EXT_histogram */

#ifndef GL_EXT_histogram
#define GL_EXT_histogram 1
#define __GLEE_GL_EXT_histogram 1
/* Constants */
#define GL_HISTOGRAM_EXT                                   0x8024
#define GL_PROXY_HISTOGRAM_EXT                             0x8025
#define GL_HISTOGRAM_WIDTH_EXT                             0x8026
#define GL_HISTOGRAM_FORMAT_EXT                            0x8027
#define GL_HISTOGRAM_RED_SIZE_EXT                          0x8028
#define GL_HISTOGRAM_GREEN_SIZE_EXT                        0x8029
#define GL_HISTOGRAM_BLUE_SIZE_EXT                         0x802A
#define GL_HISTOGRAM_ALPHA_SIZE_EXT                        0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT                    0x802C
#define GL_HISTOGRAM_SINK_EXT                              0x802D
#define GL_MINMAX_EXT                                      0x802E
#define GL_MINMAX_FORMAT_EXT                               0x802F
#define GL_MINMAX_SINK_EXT                                 0x8030
#define GL_TABLE_TOO_LARGE_EXT                             0x8031
typedef void (APIENTRYP PFNGLGETHISTOGRAMEXTPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETMINMAXEXTPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLHISTOGRAMEXTPROC) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
typedef void (APIENTRYP PFNGLMINMAXEXTPROC) (GLenum target, GLenum internalformat, GLboolean sink);
typedef void (APIENTRYP PFNGLRESETHISTOGRAMEXTPROC) (GLenum target);
typedef void (APIENTRYP PFNGLRESETMINMAXEXTPROC) (GLenum target);
GLEE_EXTERN PFNGLGETHISTOGRAMEXTPROC pglGetHistogramEXT;
GLEE_EXTERN PFNGLGETHISTOGRAMPARAMETERFVEXTPROC pglGetHistogramParameterfvEXT;
GLEE_EXTERN PFNGLGETHISTOGRAMPARAMETERIVEXTPROC pglGetHistogramParameterivEXT;
GLEE_EXTERN PFNGLGETMINMAXEXTPROC pglGetMinmaxEXT;
GLEE_EXTERN PFNGLGETMINMAXPARAMETERFVEXTPROC pglGetMinmaxParameterfvEXT;
GLEE_EXTERN PFNGLGETMINMAXPARAMETERIVEXTPROC pglGetMinmaxParameterivEXT;
GLEE_EXTERN PFNGLHISTOGRAMEXTPROC pglHistogramEXT;
GLEE_EXTERN PFNGLMINMAXEXTPROC pglMinmaxEXT;
GLEE_EXTERN PFNGLRESETHISTOGRAMEXTPROC pglResetHistogramEXT;
GLEE_EXTERN PFNGLRESETMINMAXEXTPROC pglResetMinmaxEXT;
#define glGetHistogramEXT pglGetHistogramEXT
#define glGetHistogramParameterfvEXT pglGetHistogramParameterfvEXT
#define glGetHistogramParameterivEXT pglGetHistogramParameterivEXT
#define glGetMinmaxEXT pglGetMinmaxEXT
#define glGetMinmaxParameterfvEXT pglGetMinmaxParameterfvEXT
#define glGetMinmaxParameterivEXT pglGetMinmaxParameterivEXT
#define glHistogramEXT pglHistogramEXT
#define glMinmaxEXT pglMinmaxEXT
#define glResetHistogramEXT pglResetHistogramEXT
#define glResetMinmaxEXT pglResetMinmaxEXT
#endif 

/* GL_EXT_convolution */

#ifndef GL_EXT_convolution
#define GL_EXT_convolution 1
#define __GLEE_GL_EXT_convolution 1
/* Constants */
#define GL_CONVOLUTION_1D_EXT                              0x8010
#define GL_CONVOLUTION_2D_EXT                              0x8011
#define GL_SEPARABLE_2D_EXT                                0x8012
#define GL_CONVOLUTION_BORDER_MODE_EXT                     0x8013
#define GL_CONVOLUTION_FILTER_SCALE_EXT                    0x8014
#define GL_CONVOLUTION_FILTER_BIAS_EXT                     0x8015
#define GL_REDUCE_EXT                                      0x8016
#define GL_CONVOLUTION_FORMAT_EXT                          0x8017
#define GL_CONVOLUTION_WIDTH_EXT                           0x8018
#define GL_CONVOLUTION_HEIGHT_EXT                          0x8019
#define GL_MAX_CONVOLUTION_WIDTH_EXT                       0x801A
#define GL_MAX_CONVOLUTION_HEIGHT_EXT                      0x801B
#define GL_POST_CONVOLUTION_RED_SCALE_EXT                  0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT                0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT                 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT                0x801F
#define GL_POST_CONVOLUTION_RED_BIAS_EXT                   0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT                 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT                  0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT                 0x8023
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER1DEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image);
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER2DEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFEXTPROC) (GLenum target, GLenum pname, GLfloat params);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFVEXTPROC) (GLenum target, GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIEXTPROC) (GLenum target, GLenum pname, GLint params);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIVEXTPROC) (GLenum target, GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETCONVOLUTIONFILTEREXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid * image);
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETSEPARABLEFILTEREXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span);
typedef void (APIENTRYP PFNGLSEPARABLEFILTER2DEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column);
GLEE_EXTERN PFNGLCONVOLUTIONFILTER1DEXTPROC pglConvolutionFilter1DEXT;
GLEE_EXTERN PFNGLCONVOLUTIONFILTER2DEXTPROC pglConvolutionFilter2DEXT;
GLEE_EXTERN PFNGLCONVOLUTIONPARAMETERFEXTPROC pglConvolutionParameterfEXT;
GLEE_EXTERN PFNGLCONVOLUTIONPARAMETERFVEXTPROC pglConvolutionParameterfvEXT;
GLEE_EXTERN PFNGLCONVOLUTIONPARAMETERIEXTPROC pglConvolutionParameteriEXT;
GLEE_EXTERN PFNGLCONVOLUTIONPARAMETERIVEXTPROC pglConvolutionParameterivEXT;
GLEE_EXTERN PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC pglCopyConvolutionFilter1DEXT;
GLEE_EXTERN PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC pglCopyConvolutionFilter2DEXT;
GLEE_EXTERN PFNGLGETCONVOLUTIONFILTEREXTPROC pglGetConvolutionFilterEXT;
GLEE_EXTERN PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC pglGetConvolutionParameterfvEXT;
GLEE_EXTERN PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC pglGetConvolutionParameterivEXT;
GLEE_EXTERN PFNGLGETSEPARABLEFILTEREXTPROC pglGetSeparableFilterEXT;
GLEE_EXTERN PFNGLSEPARABLEFILTER2DEXTPROC pglSeparableFilter2DEXT;
#define glConvolutionFilter1DEXT pglConvolutionFilter1DEXT
#define glConvolutionFilter2DEXT pglConvolutionFilter2DEXT
#define glConvolutionParameterfEXT pglConvolutionParameterfEXT
#define glConvolutionParameterfvEXT pglConvolutionParameterfvEXT
#define glConvolutionParameteriEXT pglConvolutionParameteriEXT
#define glConvolutionParameterivEXT pglConvolutionParameterivEXT
#define glCopyConvolutionFilter1DEXT pglCopyConvolutionFilter1DEXT
#define glCopyConvolutionFilter2DEXT pglCopyConvolutionFilter2DEXT
#define glGetConvolutionFilterEXT pglGetConvolutionFilterEXT
#define glGetConvolutionParameterfvEXT pglGetConvolutionParameterfvEXT
#define glGetConvolutionParameterivEXT pglGetConvolutionParameterivEXT
#define glGetSeparableFilterEXT pglGetSeparableFilterEXT
#define glSeparableFilter2DEXT pglSeparableFilter2DEXT
#endif 

/* GL_SGI_color_matrix */

#ifndef GL_SGI_color_matrix
#define GL_SGI_color_matrix 1
#define __GLEE_GL_SGI_color_matrix 1
/* Constants */
#define GL_COLOR_MATRIX_SGI                                0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI                    0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI                0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI                 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI               0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI                0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI               0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI                  0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI                0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI                 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI                0x80BB
#endif 

/* GL_SGI_color_table */

#ifndef GL_SGI_color_table
#define GL_SGI_color_table 1
#define __GLEE_GL_SGI_color_table 1
/* Constants */
#define GL_COLOR_TABLE_SGI                                 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI                0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI               0x80D2
#define GL_PROXY_COLOR_TABLE_SGI                           0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI          0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI         0x80D5
#define GL_COLOR_TABLE_SCALE_SGI                           0x80D6
#define GL_COLOR_TABLE_BIAS_SGI                            0x80D7
#define GL_COLOR_TABLE_FORMAT_SGI                          0x80D8
#define GL_COLOR_TABLE_WIDTH_SGI                           0x80D9
#define GL_COLOR_TABLE_RED_SIZE_SGI                        0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_SGI                      0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_SGI                       0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI                      0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI                  0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI                  0x80DF
typedef void (APIENTRYP PFNGLCOLORTABLESGIPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table);
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERFVSGIPROC) (GLenum target, GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERIVSGIPROC) (GLenum target, GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLCOPYCOLORTABLESGIPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLGETCOLORTABLESGIPROC) (GLenum target, GLenum format, GLenum type, GLvoid * table);
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERFVSGIPROC) (GLenum target, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERIVSGIPROC) (GLenum target, GLenum pname, GLint * params);
GLEE_EXTERN PFNGLCOLORTABLESGIPROC pglColorTableSGI;
GLEE_EXTERN PFNGLCOLORTABLEPARAMETERFVSGIPROC pglColorTableParameterfvSGI;
GLEE_EXTERN PFNGLCOLORTABLEPARAMETERIVSGIPROC pglColorTableParameterivSGI;
GLEE_EXTERN PFNGLCOPYCOLORTABLESGIPROC pglCopyColorTableSGI;
GLEE_EXTERN PFNGLGETCOLORTABLESGIPROC pglGetColorTableSGI;
GLEE_EXTERN PFNGLGETCOLORTABLEPARAMETERFVSGIPROC pglGetColorTableParameterfvSGI;
GLEE_EXTERN PFNGLGETCOLORTABLEPARAMETERIVSGIPROC pglGetColorTableParameterivSGI;
#define glColorTableSGI pglColorTableSGI
#define glColorTableParameterfvSGI pglColorTableParameterfvSGI
#define glColorTableParameterivSGI pglColorTableParameterivSGI
#define glCopyColorTableSGI pglCopyColorTableSGI
#define glGetColorTableSGI pglGetColorTableSGI
#define glGetColorTableParameterfvSGI pglGetColorTableParameterfvSGI
#define glGetColorTableParameterivSGI pglGetColorTableParameterivSGI
#endif 

/* GL_SGIS_pixel_texture */

#ifndef GL_SGIS_pixel_texture
#define GL_SGIS_pixel_texture 1
#define __GLEE_GL_SGIS_pixel_texture 1
/* Constants */
#define GL_PIXEL_TEXTURE_SGIS                              0x8353
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS                  0x8354
#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS                0x8355
#define GL_PIXEL_GROUP_COLOR_SGIS                          0x8356
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERISGISPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERIVSGISPROC) (GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERFSGISPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERFVSGISPROC) (GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC) (GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC) (GLenum pname, GLfloat * params);
GLEE_EXTERN PFNGLPIXELTEXGENPARAMETERISGISPROC pglPixelTexGenParameteriSGIS;
GLEE_EXTERN PFNGLPIXELTEXGENPARAMETERIVSGISPROC pglPixelTexGenParameterivSGIS;
GLEE_EXTERN PFNGLPIXELTEXGENPARAMETERFSGISPROC pglPixelTexGenParameterfSGIS;
GLEE_EXTERN PFNGLPIXELTEXGENPARAMETERFVSGISPROC pglPixelTexGenParameterfvSGIS;
GLEE_EXTERN PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC pglGetPixelTexGenParameterivSGIS;
GLEE_EXTERN PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC pglGetPixelTexGenParameterfvSGIS;
#define glPixelTexGenParameteriSGIS pglPixelTexGenParameteriSGIS
#define glPixelTexGenParameterivSGIS pglPixelTexGenParameterivSGIS
#define glPixelTexGenParameterfSGIS pglPixelTexGenParameterfSGIS
#define glPixelTexGenParameterfvSGIS pglPixelTexGenParameterfvSGIS
#define glGetPixelTexGenParameterivSGIS pglGetPixelTexGenParameterivSGIS
#define glGetPixelTexGenParameterfvSGIS pglGetPixelTexGenParameterfvSGIS
#endif 

/* GL_SGIX_pixel_texture */

#ifndef GL_SGIX_pixel_texture
#define GL_SGIX_pixel_texture 1
#define __GLEE_GL_SGIX_pixel_texture 1
/* Constants */
#define GL_PIXEL_TEX_GEN_SGIX                              0x8139
#define GL_PIXEL_TEX_GEN_MODE_SGIX                         0x832B
typedef void (APIENTRYP PFNGLPIXELTEXGENSGIXPROC) (GLenum mode);
GLEE_EXTERN PFNGLPIXELTEXGENSGIXPROC pglPixelTexGenSGIX;
#define glPixelTexGenSGIX pglPixelTexGenSGIX
#endif 

/* GL_SGIS_texture4D */

#ifndef GL_SGIS_texture4D
#define GL_SGIS_texture4D 1
#define __GLEE_GL_SGIS_texture4D 1
/* Constants */
#define GL_PACK_SKIP_VOLUMES_SGIS                          0x8130
#define GL_PACK_IMAGE_DEPTH_SGIS                           0x8131
#define GL_UNPACK_SKIP_VOLUMES_SGIS                        0x8132
#define GL_UNPACK_IMAGE_DEPTH_SGIS                         0x8133
#define GL_TEXTURE_4D_SGIS                                 0x8134
#define GL_PROXY_TEXTURE_4D_SGIS                           0x8135
#define GL_TEXTURE_4DSIZE_SGIS                             0x8136
#define GL_TEXTURE_WRAP_Q_SGIS                             0x8137
#define GL_MAX_4D_TEXTURE_SIZE_SGIS                        0x8138
#define GL_TEXTURE_4D_BINDING_SGIS                         0x814F
typedef void (APIENTRYP PFNGLTEXIMAGE4DSGISPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE4DSGISPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const GLvoid * pixels);
GLEE_EXTERN PFNGLTEXIMAGE4DSGISPROC pglTexImage4DSGIS;
GLEE_EXTERN PFNGLTEXSUBIMAGE4DSGISPROC pglTexSubImage4DSGIS;
#define glTexImage4DSGIS pglTexImage4DSGIS
#define glTexSubImage4DSGIS pglTexSubImage4DSGIS
#endif 

/* GL_SGI_texture_color_table */

#ifndef GL_SGI_texture_color_table
#define GL_SGI_texture_color_table 1
#define __GLEE_GL_SGI_texture_color_table 1
/* Constants */
#define GL_TEXTURE_COLOR_TABLE_SGI                         0x80BC
#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI                   0x80BD
#endif 

/* GL_EXT_cmyka */

#ifndef GL_EXT_cmyka
#define GL_EXT_cmyka 1
#define __GLEE_GL_EXT_cmyka 1
/* Constants */
#define GL_CMYK_EXT                                        0x800C
#define GL_CMYKA_EXT                                       0x800D
#define GL_PACK_CMYK_HINT_EXT                              0x800E
#define GL_UNPACK_CMYK_HINT_EXT                            0x800F
#endif 

/* GL_EXT_texture_object */

#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object 1
#define __GLEE_GL_EXT_texture_object 1
/* Constants */
#define GL_TEXTURE_PRIORITY_EXT                            0x8066
#define GL_TEXTURE_RESIDENT_EXT                            0x8067
#define GL_TEXTURE_1D_BINDING_EXT                          0x8068
#define GL_TEXTURE_2D_BINDING_EXT                          0x8069
#define GL_TEXTURE_3D_BINDING_EXT                          0x806A
typedef GLboolean (APIENTRYP PFNGLARETEXTURESRESIDENTEXTPROC) (GLsizei n, const GLuint * textures, GLboolean * residences);
typedef void (APIENTRYP PFNGLBINDTEXTUREEXTPROC) (GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLDELETETEXTURESEXTPROC) (GLsizei n, const GLuint * textures);
typedef void (APIENTRYP PFNGLGENTEXTURESEXTPROC) (GLsizei n, GLuint * textures);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREEXTPROC) (GLuint texture);
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESEXTPROC) (GLsizei n, const GLuint * textures, const GLclampf * priorities);
GLEE_EXTERN PFNGLARETEXTURESRESIDENTEXTPROC pglAreTexturesResidentEXT;
GLEE_EXTERN PFNGLBINDTEXTUREEXTPROC pglBindTextureEXT;
GLEE_EXTERN PFNGLDELETETEXTURESEXTPROC pglDeleteTexturesEXT;
GLEE_EXTERN PFNGLGENTEXTURESEXTPROC pglGenTexturesEXT;
GLEE_EXTERN PFNGLISTEXTUREEXTPROC pglIsTextureEXT;
GLEE_EXTERN PFNGLPRIORITIZETEXTURESEXTPROC pglPrioritizeTexturesEXT;
#define glAreTexturesResidentEXT pglAreTexturesResidentEXT
#define glBindTextureEXT pglBindTextureEXT
#define glDeleteTexturesEXT pglDeleteTexturesEXT
#define glGenTexturesEXT pglGenTexturesEXT
#define glIsTextureEXT pglIsTextureEXT
#define glPrioritizeTexturesEXT pglPrioritizeTexturesEXT
#endif 

/* GL_SGIS_detail_texture */

#ifndef GL_SGIS_detail_texture
#define GL_SGIS_detail_texture 1
#define __GLEE_GL_SGIS_detail_texture 1
/* Constants */
#define GL_DETAIL_TEXTURE_2D_SGIS                          0x8095
#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS                  0x8096
#define GL_LINEAR_DETAIL_SGIS                              0x8097
#define GL_LINEAR_DETAIL_ALPHA_SGIS                        0x8098
#define GL_LINEAR_DETAIL_COLOR_SGIS                        0x8099
#define GL_DETAIL_TEXTURE_LEVEL_SGIS                       0x809A
#define GL_DETAIL_TEXTURE_MODE_SGIS                        0x809B
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS                 0x809C
typedef void (APIENTRYP PFNGLDETAILTEXFUNCSGISPROC) (GLenum target, GLsizei n, const GLfloat * points);
typedef void (APIENTRYP PFNGLGETDETAILTEXFUNCSGISPROC) (GLenum target, GLfloat * points);
GLEE_EXTERN PFNGLDETAILTEXFUNCSGISPROC pglDetailTexFuncSGIS;
GLEE_EXTERN PFNGLGETDETAILTEXFUNCSGISPROC pglGetDetailTexFuncSGIS;
#define glDetailTexFuncSGIS pglDetailTexFuncSGIS
#define glGetDetailTexFuncSGIS pglGetDetailTexFuncSGIS
#endif 

/* GL_SGIS_sharpen_texture */

#ifndef GL_SGIS_sharpen_texture
#define GL_SGIS_sharpen_texture 1
#define __GLEE_GL_SGIS_sharpen_texture 1
/* Constants */
#define GL_LINEAR_SHARPEN_SGIS                             0x80AD
#define GL_LINEAR_SHARPEN_ALPHA_SGIS                       0x80AE
#define GL_LINEAR_SHARPEN_COLOR_SGIS                       0x80AF
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS                0x80B0
typedef void (APIENTRYP PFNGLSHARPENTEXFUNCSGISPROC) (GLenum target, GLsizei n, const GLfloat * points);
typedef void (APIENTRYP PFNGLGETSHARPENTEXFUNCSGISPROC) (GLenum target, GLfloat * points);
GLEE_EXTERN PFNGLSHARPENTEXFUNCSGISPROC pglSharpenTexFuncSGIS;
GLEE_EXTERN PFNGLGETSHARPENTEXFUNCSGISPROC pglGetSharpenTexFuncSGIS;
#define glSharpenTexFuncSGIS pglSharpenTexFuncSGIS
#define glGetSharpenTexFuncSGIS pglGetSharpenTexFuncSGIS
#endif 

/* GL_EXT_packed_pixels */

#ifndef GL_EXT_packed_pixels
#define GL_EXT_packed_pixels 1
#define __GLEE_GL_EXT_packed_pixels 1
/* Constants */
#define GL_UNSIGNED_BYTE_3_3_2_EXT                         0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT                      0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT                      0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT                        0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT                     0x8036
#endif 

/* GL_SGIS_texture_lod */

#ifndef GL_SGIS_texture_lod
#define GL_SGIS_texture_lod 1
#define __GLEE_GL_SGIS_texture_lod 1
/* Constants */
#define GL_TEXTURE_MIN_LOD_SGIS                            0x813A
#define GL_TEXTURE_MAX_LOD_SGIS                            0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS                         0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS                          0x813D
#endif 

/* GL_SGIS_multisample */

#ifndef GL_SGIS_multisample
#define GL_SGIS_multisample 1
#define __GLEE_GL_SGIS_multisample 1
/* Constants */
#define GL_MULTISAMPLE_SGIS                                0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS                       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS                        0x809F
#define GL_SAMPLE_MASK_SGIS                                0x80A0
#define GL_1PASS_SGIS                                      0x80A1
#define GL_2PASS_0_SGIS                                    0x80A2
#define GL_2PASS_1_SGIS                                    0x80A3
#define GL_4PASS_0_SGIS                                    0x80A4
#define GL_4PASS_1_SGIS                                    0x80A5
#define GL_4PASS_2_SGIS                                    0x80A6
#define GL_4PASS_3_SGIS                                    0x80A7
#define GL_SAMPLE_BUFFERS_SGIS                             0x80A8
#define GL_SAMPLES_SGIS                                    0x80A9
#define GL_SAMPLE_MASK_VALUE_SGIS                          0x80AA
#define GL_SAMPLE_MASK_INVERT_SGIS                         0x80AB
#define GL_SAMPLE_PATTERN_SGIS                             0x80AC
typedef void (APIENTRYP PFNGLSAMPLEMASKSGISPROC) (GLclampf value, GLboolean invert);
typedef void (APIENTRYP PFNGLSAMPLEPATTERNSGISPROC) (GLenum pattern);
GLEE_EXTERN PFNGLSAMPLEMASKSGISPROC pglSampleMaskSGIS;
GLEE_EXTERN PFNGLSAMPLEPATTERNSGISPROC pglSamplePatternSGIS;
#define glSampleMaskSGIS pglSampleMaskSGIS
#define glSamplePatternSGIS pglSamplePatternSGIS
#endif 

/* GL_EXT_rescale_normal */

#ifndef GL_EXT_rescale_normal
#define GL_EXT_rescale_normal 1
#define __GLEE_GL_EXT_rescale_normal 1
/* Constants */
#define GL_RESCALE_NORMAL_EXT                              0x803A
#endif 

/* GL_EXT_vertex_array */

#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array 1
#define __GLEE_GL_EXT_vertex_array 1
/* Constants */
#define GL_VERTEX_ARRAY_EXT                                0x8074
#define GL_NORMAL_ARRAY_EXT                                0x8075
#define GL_COLOR_ARRAY_EXT                                 0x8076
#define GL_INDEX_ARRAY_EXT                                 0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT                         0x8078
#define GL_EDGE_FLAG_ARRAY_EXT                             0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT                           0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT                           0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT                         0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT                          0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT                           0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT                         0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT                          0x8080
#define GL_COLOR_ARRAY_SIZE_EXT                            0x8081
#define GL_COLOR_ARRAY_TYPE_EXT                            0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT                          0x8083
#define GL_COLOR_ARRAY_COUNT_EXT                           0x8084
#define GL_INDEX_ARRAY_TYPE_EXT                            0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT                          0x8086
#define GL_INDEX_ARRAY_COUNT_EXT                           0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT                    0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT                    0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT                  0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT                   0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT                      0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT                       0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT                        0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT                        0x808F
#define GL_COLOR_ARRAY_POINTER_EXT                         0x8090
#define GL_INDEX_ARRAY_POINTER_EXT                         0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT                 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT                     0x8093
typedef void (APIENTRYP PFNGLARRAYELEMENTEXTPROC) (GLint i);
typedef void (APIENTRYP PFNGLCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLDRAWARRAYSEXTPROC) (GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTEREXTPROC) (GLsizei stride, GLsizei count, const GLboolean * pointer);
typedef void (APIENTRYP PFNGLGETPOINTERVEXTPROC) (GLenum pname, GLvoid* * params);
typedef void (APIENTRYP PFNGLINDEXPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLNORMALPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLTEXCOORDPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLVERTEXPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid * pointer);
GLEE_EXTERN PFNGLARRAYELEMENTEXTPROC pglArrayElementEXT;
GLEE_EXTERN PFNGLCOLORPOINTEREXTPROC pglColorPointerEXT;
GLEE_EXTERN PFNGLDRAWARRAYSEXTPROC pglDrawArraysEXT;
GLEE_EXTERN PFNGLEDGEFLAGPOINTEREXTPROC pglEdgeFlagPointerEXT;
GLEE_EXTERN PFNGLGETPOINTERVEXTPROC pglGetPointervEXT;
GLEE_EXTERN PFNGLINDEXPOINTEREXTPROC pglIndexPointerEXT;
GLEE_EXTERN PFNGLNORMALPOINTEREXTPROC pglNormalPointerEXT;
GLEE_EXTERN PFNGLTEXCOORDPOINTEREXTPROC pglTexCoordPointerEXT;
GLEE_EXTERN PFNGLVERTEXPOINTEREXTPROC pglVertexPointerEXT;
#define glArrayElementEXT pglArrayElementEXT
#define glColorPointerEXT pglColorPointerEXT
#define glDrawArraysEXT pglDrawArraysEXT
#define glEdgeFlagPointerEXT pglEdgeFlagPointerEXT
#define glGetPointervEXT pglGetPointervEXT
#define glIndexPointerEXT pglIndexPointerEXT
#define glNormalPointerEXT pglNormalPointerEXT
#define glTexCoordPointerEXT pglTexCoordPointerEXT
#define glVertexPointerEXT pglVertexPointerEXT
#endif 

/* GL_EXT_misc_attribute */

#ifndef GL_EXT_misc_attribute
#define GL_EXT_misc_attribute 1
#define __GLEE_GL_EXT_misc_attribute 1
/* Constants */
#endif 

/* GL_SGIS_generate_mipmap */

#ifndef GL_SGIS_generate_mipmap
#define GL_SGIS_generate_mipmap 1
#define __GLEE_GL_SGIS_generate_mipmap 1
/* Constants */
#define GL_GENERATE_MIPMAP_SGIS                            0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS                       0x8192
#endif 

/* GL_SGIX_clipmap */

#ifndef GL_SGIX_clipmap
#define GL_SGIX_clipmap 1
#define __GLEE_GL_SGIX_clipmap 1
/* Constants */
#define GL_LINEAR_CLIPMAP_LINEAR_SGIX                      0x8170
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX                     0x8171
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX                      0x8172
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX                     0x8173
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX              0x8174
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX                 0x8175
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX                      0x8176
#define GL_MAX_CLIPMAP_DEPTH_SGIX                          0x8177
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX                  0x8178
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX                    0x844D
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX                     0x844E
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX                     0x844F
#endif 

/* GL_SGIX_shadow */

#ifndef GL_SGIX_shadow
#define GL_SGIX_shadow 1
#define __GLEE_GL_SGIX_shadow 1
/* Constants */
#define GL_TEXTURE_COMPARE_SGIX                            0x819A
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX                   0x819B
#define GL_TEXTURE_LEQUAL_R_SGIX                           0x819C
#define GL_TEXTURE_GEQUAL_R_SGIX                           0x819D
#endif 

/* GL_SGIS_texture_edge_clamp */

#ifndef GL_SGIS_texture_edge_clamp
#define GL_SGIS_texture_edge_clamp 1
#define __GLEE_GL_SGIS_texture_edge_clamp 1
/* Constants */
#define GL_CLAMP_TO_EDGE_SGIS                              0x812F
#endif 

/* GL_SGIS_texture_border_clamp */

#ifndef GL_SGIS_texture_border_clamp
#define GL_SGIS_texture_border_clamp 1
#define __GLEE_GL_SGIS_texture_border_clamp 1
/* Constants */
#define GL_CLAMP_TO_BORDER_SGIS                            0x812D
#endif 

/* GL_EXT_blend_minmax */

#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1
#define __GLEE_GL_EXT_blend_minmax 1
/* Constants */
#define GL_FUNC_ADD_EXT                                    0x8006
#define GL_MIN_EXT                                         0x8007
#define GL_MAX_EXT                                         0x8008
#define GL_BLEND_EQUATION_EXT                              0x8009
typedef void (APIENTRYP PFNGLBLENDEQUATIONEXTPROC) (GLenum mode);
GLEE_EXTERN PFNGLBLENDEQUATIONEXTPROC pglBlendEquationEXT;
#define glBlendEquationEXT pglBlendEquationEXT
#endif 

/* GL_EXT_blend_subtract */

#ifndef GL_EXT_blend_subtract
#define GL_EXT_blend_subtract 1
#define __GLEE_GL_EXT_blend_subtract 1
/* Constants */
#define GL_FUNC_SUBTRACT_EXT                               0x800A
#define GL_FUNC_REVERSE_SUBTRACT_EXT                       0x800B
#endif 

/* GL_EXT_blend_logic_op */

#ifndef GL_EXT_blend_logic_op
#define GL_EXT_blend_logic_op 1
#define __GLEE_GL_EXT_blend_logic_op 1
/* Constants */
#endif 

/* GL_SGIX_interlace */

#ifndef GL_SGIX_interlace
#define GL_SGIX_interlace 1
#define __GLEE_GL_SGIX_interlace 1
/* Constants */
#define GL_INTERLACE_SGIX                                  0x8094
#endif 

/* GL_SGIX_pixel_tiles */

#ifndef GL_SGIX_pixel_tiles
#define GL_SGIX_pixel_tiles 1
#define __GLEE_GL_SGIX_pixel_tiles 1
/* Constants */
#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX                  0x813E
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX                 0x813F
#define GL_PIXEL_TILE_WIDTH_SGIX                           0x8140
#define GL_PIXEL_TILE_HEIGHT_SGIX                          0x8141
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX                      0x8142
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX                     0x8143
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX                      0x8144
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX                      0x8145
#endif 

/* GL_SGIS_texture_select */

#ifndef GL_SGIS_texture_select
#define GL_SGIS_texture_select 1
#define __GLEE_GL_SGIS_texture_select 1
/* Constants */
#define GL_DUAL_ALPHA4_SGIS                                0x8110
#define GL_DUAL_ALPHA8_SGIS                                0x8111
#define GL_DUAL_ALPHA12_SGIS                               0x8112
#define GL_DUAL_ALPHA16_SGIS                               0x8113
#define GL_DUAL_LUMINANCE4_SGIS                            0x8114
#define GL_DUAL_LUMINANCE8_SGIS                            0x8115
#define GL_DUAL_LUMINANCE12_SGIS                           0x8116
#define GL_DUAL_LUMINANCE16_SGIS                           0x8117
#define GL_DUAL_INTENSITY4_SGIS                            0x8118
#define GL_DUAL_INTENSITY8_SGIS                            0x8119
#define GL_DUAL_INTENSITY12_SGIS                           0x811A
#define GL_DUAL_INTENSITY16_SGIS                           0x811B
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS                      0x811C
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS                      0x811D
#define GL_QUAD_ALPHA4_SGIS                                0x811E
#define GL_QUAD_ALPHA8_SGIS                                0x811F
#define GL_QUAD_LUMINANCE4_SGIS                            0x8120
#define GL_QUAD_LUMINANCE8_SGIS                            0x8121
#define GL_QUAD_INTENSITY4_SGIS                            0x8122
#define GL_QUAD_INTENSITY8_SGIS                            0x8123
#define GL_DUAL_TEXTURE_SELECT_SGIS                        0x8124
#define GL_QUAD_TEXTURE_SELECT_SGIS                        0x8125
#endif 

/* GL_SGIX_sprite */

#ifndef GL_SGIX_sprite
#define GL_SGIX_sprite 1
#define __GLEE_GL_SGIX_sprite 1
/* Constants */
#define GL_SPRITE_SGIX                                     0x8148
#define GL_SPRITE_MODE_SGIX                                0x8149
#define GL_SPRITE_AXIS_SGIX                                0x814A
#define GL_SPRITE_TRANSLATION_SGIX                         0x814B
#define GL_SPRITE_AXIAL_SGIX                               0x814C
#define GL_SPRITE_OBJECT_ALIGNED_SGIX                      0x814D
#define GL_SPRITE_EYE_ALIGNED_SGIX                         0x814E
typedef void (APIENTRYP PFNGLSPRITEPARAMETERFSGIXPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLSPRITEPARAMETERFVSGIXPROC) (GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLSPRITEPARAMETERISGIXPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLSPRITEPARAMETERIVSGIXPROC) (GLenum pname, const GLint * params);
GLEE_EXTERN PFNGLSPRITEPARAMETERFSGIXPROC pglSpriteParameterfSGIX;
GLEE_EXTERN PFNGLSPRITEPARAMETERFVSGIXPROC pglSpriteParameterfvSGIX;
GLEE_EXTERN PFNGLSPRITEPARAMETERISGIXPROC pglSpriteParameteriSGIX;
GLEE_EXTERN PFNGLSPRITEPARAMETERIVSGIXPROC pglSpriteParameterivSGIX;
#define glSpriteParameterfSGIX pglSpriteParameterfSGIX
#define glSpriteParameterfvSGIX pglSpriteParameterfvSGIX
#define glSpriteParameteriSGIX pglSpriteParameteriSGIX
#define glSpriteParameterivSGIX pglSpriteParameterivSGIX
#endif 

/* GL_SGIX_texture_multi_buffer */

#ifndef GL_SGIX_texture_multi_buffer
#define GL_SGIX_texture_multi_buffer 1
#define __GLEE_GL_SGIX_texture_multi_buffer 1
/* Constants */
#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX                  0x812E
#endif 

/* GL_EXT_point_parameters */

#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters 1
#define __GLEE_GL_EXT_point_parameters 1
/* Constants */
#define GL_POINT_SIZE_MIN_EXT                              0x8126
#define GL_POINT_SIZE_MAX_EXT                              0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT                   0x8128
#define GL_DISTANCE_ATTENUATION_EXT                        0x8129
typedef void (APIENTRYP PFNGLPOINTPARAMETERFEXTPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVEXTPROC) (GLenum pname, const GLfloat * params);
GLEE_EXTERN PFNGLPOINTPARAMETERFEXTPROC pglPointParameterfEXT;
GLEE_EXTERN PFNGLPOINTPARAMETERFVEXTPROC pglPointParameterfvEXT;
#define glPointParameterfEXT pglPointParameterfEXT
#define glPointParameterfvEXT pglPointParameterfvEXT
#endif 

/* GL_SGIS_point_parameters */

#ifndef GL_SGIS_point_parameters
#define GL_SGIS_point_parameters 1
#define __GLEE_GL_SGIS_point_parameters 1
/* Constants */
#define GL_POINT_SIZE_MIN_SGIS                             0x8126
#define GL_POINT_SIZE_MAX_SGIS                             0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS                  0x8128
#define GL_DISTANCE_ATTENUATION_SGIS                       0x8129
typedef void (APIENTRYP PFNGLPOINTPARAMETERFSGISPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVSGISPROC) (GLenum pname, const GLfloat * params);
GLEE_EXTERN PFNGLPOINTPARAMETERFSGISPROC pglPointParameterfSGIS;
GLEE_EXTERN PFNGLPOINTPARAMETERFVSGISPROC pglPointParameterfvSGIS;
#define glPointParameterfSGIS pglPointParameterfSGIS
#define glPointParameterfvSGIS pglPointParameterfvSGIS
#endif 

/* GL_SGIX_instruments */

#ifndef GL_SGIX_instruments
#define GL_SGIX_instruments 1
#define __GLEE_GL_SGIX_instruments 1
/* Constants */
#define GL_INSTRUMENT_BUFFER_POINTER_SGIX                  0x8180
#define GL_INSTRUMENT_MEASUREMENTS_SGIX                    0x8181
typedef GLint (APIENTRYP PFNGLGETINSTRUMENTSSGIXPROC) ();
typedef void (APIENTRYP PFNGLINSTRUMENTSBUFFERSGIXPROC) (GLsizei size, GLint * buffer);
typedef GLint (APIENTRYP PFNGLPOLLINSTRUMENTSSGIXPROC) (GLint * marker_p);
typedef void (APIENTRYP PFNGLREADINSTRUMENTSSGIXPROC) (GLint marker);
typedef void (APIENTRYP PFNGLSTARTINSTRUMENTSSGIXPROC) ();
typedef void (APIENTRYP PFNGLSTOPINSTRUMENTSSGIXPROC) (GLint marker);
GLEE_EXTERN PFNGLGETINSTRUMENTSSGIXPROC pglGetInstrumentsSGIX;
GLEE_EXTERN PFNGLINSTRUMENTSBUFFERSGIXPROC pglInstrumentsBufferSGIX;
GLEE_EXTERN PFNGLPOLLINSTRUMENTSSGIXPROC pglPollInstrumentsSGIX;
GLEE_EXTERN PFNGLREADINSTRUMENTSSGIXPROC pglReadInstrumentsSGIX;
GLEE_EXTERN PFNGLSTARTINSTRUMENTSSGIXPROC pglStartInstrumentsSGIX;
GLEE_EXTERN PFNGLSTOPINSTRUMENTSSGIXPROC pglStopInstrumentsSGIX;
#define glGetInstrumentsSGIX pglGetInstrumentsSGIX
#define glInstrumentsBufferSGIX pglInstrumentsBufferSGIX
#define glPollInstrumentsSGIX pglPollInstrumentsSGIX
#define glReadInstrumentsSGIX pglReadInstrumentsSGIX
#define glStartInstrumentsSGIX pglStartInstrumentsSGIX
#define glStopInstrumentsSGIX pglStopInstrumentsSGIX
#endif 

/* GL_SGIX_texture_scale_bias */

#ifndef GL_SGIX_texture_scale_bias
#define GL_SGIX_texture_scale_bias 1
#define __GLEE_GL_SGIX_texture_scale_bias 1
/* Constants */
#define GL_POST_TEXTURE_FILTER_BIAS_SGIX                   0x8179
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX                  0x817A
#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX             0x817B
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX            0x817C
#endif 

/* GL_SGIX_framezoom */

#ifndef GL_SGIX_framezoom
#define GL_SGIX_framezoom 1
#define __GLEE_GL_SGIX_framezoom 1
/* Constants */
#define GL_FRAMEZOOM_SGIX                                  0x818B
#define GL_FRAMEZOOM_FACTOR_SGIX                           0x818C
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX                       0x818D
typedef void (APIENTRYP PFNGLFRAMEZOOMSGIXPROC) (GLint factor);
GLEE_EXTERN PFNGLFRAMEZOOMSGIXPROC pglFrameZoomSGIX;
#define glFrameZoomSGIX pglFrameZoomSGIX
#endif 

/* GL_SGIX_tag_sample_buffer */

#ifndef GL_SGIX_tag_sample_buffer
#define GL_SGIX_tag_sample_buffer 1
#define __GLEE_GL_SGIX_tag_sample_buffer 1
/* Constants */
typedef void (APIENTRYP PFNGLTAGSAMPLEBUFFERSGIXPROC) ();
GLEE_EXTERN PFNGLTAGSAMPLEBUFFERSGIXPROC pglTagSampleBufferSGIX;
#define glTagSampleBufferSGIX pglTagSampleBufferSGIX
#endif 

/* GL_FfdMaskSGIX */

#ifndef GL_FfdMaskSGIX
#define GL_FfdMaskSGIX 1
#define __GLEE_GL_FfdMaskSGIX 1
/* Constants */
#define GL_TEXTURE_DEFORMATION_BIT_SGIX                    0x00000001
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX                   0x00000002
#endif 

/* GL_SGIX_polynomial_ffd */

#ifndef GL_SGIX_polynomial_ffd
#define GL_SGIX_polynomial_ffd 1
#define __GLEE_GL_SGIX_polynomial_ffd 1
/* Constants */
#define GL_GEOMETRY_DEFORMATION_SGIX                       0x8194
#define GL_TEXTURE_DEFORMATION_SGIX                        0x8195
#define GL_DEFORMATIONS_MASK_SGIX                          0x8196
#define GL_MAX_DEFORMATION_ORDER_SGIX                      0x8197
typedef void (APIENTRYP PFNGLDEFORMATIONMAP3DSGIXPROC) (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble * points);
typedef void (APIENTRYP PFNGLDEFORMATIONMAP3FSGIXPROC) (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat * points);
typedef void (APIENTRYP PFNGLDEFORMSGIXPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC) (GLbitfield mask);
GLEE_EXTERN PFNGLDEFORMATIONMAP3DSGIXPROC pglDeformationMap3dSGIX;
GLEE_EXTERN PFNGLDEFORMATIONMAP3FSGIXPROC pglDeformationMap3fSGIX;
GLEE_EXTERN PFNGLDEFORMSGIXPROC pglDeformSGIX;
GLEE_EXTERN PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC pglLoadIdentityDeformationMapSGIX;
#define glDeformationMap3dSGIX pglDeformationMap3dSGIX
#define glDeformationMap3fSGIX pglDeformationMap3fSGIX
#define glDeformSGIX pglDeformSGIX
#define glLoadIdentityDeformationMapSGIX pglLoadIdentityDeformationMapSGIX
#endif 

/* GL_SGIX_reference_plane */

#ifndef GL_SGIX_reference_plane
#define GL_SGIX_reference_plane 1
#define __GLEE_GL_SGIX_reference_plane 1
/* Constants */
#define GL_REFERENCE_PLANE_SGIX                            0x817D
#define GL_REFERENCE_PLANE_EQUATION_SGIX                   0x817E
typedef void (APIENTRYP PFNGLREFERENCEPLANESGIXPROC) (const GLdouble * equation);
GLEE_EXTERN PFNGLREFERENCEPLANESGIXPROC pglReferencePlaneSGIX;
#define glReferencePlaneSGIX pglReferencePlaneSGIX
#endif 

/* GL_SGIX_flush_raster */

#ifndef GL_SGIX_flush_raster
#define GL_SGIX_flush_raster 1
#define __GLEE_GL_SGIX_flush_raster 1
/* Constants */
typedef void (APIENTRYP PFNGLFLUSHRASTERSGIXPROC) ();
GLEE_EXTERN PFNGLFLUSHRASTERSGIXPROC pglFlushRasterSGIX;
#define glFlushRasterSGIX pglFlushRasterSGIX
#endif 

/* GL_SGIX_depth_texture */

#ifndef GL_SGIX_depth_texture
#define GL_SGIX_depth_texture 1
#define __GLEE_GL_SGIX_depth_texture 1
/* Constants */
#define GL_DEPTH_COMPONENT16_SGIX                          0x81A5
#define GL_DEPTH_COMPONENT24_SGIX                          0x81A6
#define GL_DEPTH_COMPONENT32_SGIX                          0x81A7
#endif 

/* GL_SGIS_fog_function */

#ifndef GL_SGIS_fog_function
#define GL_SGIS_fog_function 1
#define __GLEE_GL_SGIS_fog_function 1
/* Constants */
#define GL_FOG_FUNC_SGIS                                   0x812A
#define GL_FOG_FUNC_POINTS_SGIS                            0x812B
#define GL_MAX_FOG_FUNC_POINTS_SGIS                        0x812C
typedef void (APIENTRYP PFNGLFOGFUNCSGISPROC) (GLsizei n, const GLfloat * points);
typedef void (APIENTRYP PFNGLGETFOGFUNCSGISPROC) (GLfloat * points);
GLEE_EXTERN PFNGLFOGFUNCSGISPROC pglFogFuncSGIS;
GLEE_EXTERN PFNGLGETFOGFUNCSGISPROC pglGetFogFuncSGIS;
#define glFogFuncSGIS pglFogFuncSGIS
#define glGetFogFuncSGIS pglGetFogFuncSGIS
#endif 

/* GL_SGIX_fog_offset */

#ifndef GL_SGIX_fog_offset
#define GL_SGIX_fog_offset 1
#define __GLEE_GL_SGIX_fog_offset 1
/* Constants */
#define GL_FOG_OFFSET_SGIX                                 0x8198
#define GL_FOG_OFFSET_VALUE_SGIX                           0x8199
#endif 

/* GL_HP_image_transform */

#ifndef GL_HP_image_transform
#define GL_HP_image_transform 1
#define __GLEE_GL_HP_image_transform 1
/* Constants */
#define GL_IMAGE_SCALE_X_HP                                0x8155
#define GL_IMAGE_SCALE_Y_HP                                0x8156
#define GL_IMAGE_TRANSLATE_X_HP                            0x8157
#define GL_IMAGE_TRANSLATE_Y_HP                            0x8158
#define GL_IMAGE_ROTATE_ANGLE_HP                           0x8159
#define GL_IMAGE_ROTATE_ORIGIN_X_HP                        0x815A
#define GL_IMAGE_ROTATE_ORIGIN_Y_HP                        0x815B
#define GL_IMAGE_MAG_FILTER_HP                             0x815C
#define GL_IMAGE_MIN_FILTER_HP                             0x815D
#define GL_IMAGE_CUBIC_WEIGHT_HP                           0x815E
#define GL_CUBIC_HP                                        0x815F
#define GL_AVERAGE_HP                                      0x8160
#define GL_IMAGE_TRANSFORM_2D_HP                           0x8161
#define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP             0x8162
#define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP       0x8163
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERIHPPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERFHPPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERIVHPPROC) (GLenum target, GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERFVHPPROC) (GLenum target, GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC) (GLenum target, GLenum pname, GLfloat * params);
GLEE_EXTERN PFNGLIMAGETRANSFORMPARAMETERIHPPROC pglImageTransformParameteriHP;
GLEE_EXTERN PFNGLIMAGETRANSFORMPARAMETERFHPPROC pglImageTransformParameterfHP;
GLEE_EXTERN PFNGLIMAGETRANSFORMPARAMETERIVHPPROC pglImageTransformParameterivHP;
GLEE_EXTERN PFNGLIMAGETRANSFORMPARAMETERFVHPPROC pglImageTransformParameterfvHP;
GLEE_EXTERN PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC pglGetImageTransformParameterivHP;
GLEE_EXTERN PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC pglGetImageTransformParameterfvHP;
#define glImageTransformParameteriHP pglImageTransformParameteriHP
#define glImageTransformParameterfHP pglImageTransformParameterfHP
#define glImageTransformParameterivHP pglImageTransformParameterivHP
#define glImageTransformParameterfvHP pglImageTransformParameterfvHP
#define glGetImageTransformParameterivHP pglGetImageTransformParameterivHP
#define glGetImageTransformParameterfvHP pglGetImageTransformParameterfvHP
#endif 

/* GL_HP_convolution_border_modes */

#ifndef GL_HP_convolution_border_modes
#define GL_HP_convolution_border_modes 1
#define __GLEE_GL_HP_convolution_border_modes 1
/* Constants */
#define GL_IGNORE_BORDER_HP                                0x8150
#define GL_CONSTANT_BORDER_HP                              0x8151
#define GL_REPLICATE_BORDER_HP                             0x8153
#define GL_CONVOLUTION_BORDER_COLOR_HP                     0x8154
#endif 

/* GL_INGR_palette_buffer */

#ifndef GL_INGR_palette_buffer
#define GL_INGR_palette_buffer 1
#define __GLEE_GL_INGR_palette_buffer 1
/* Constants */
#endif 

/* GL_SGIX_texture_add_env */

#ifndef GL_SGIX_texture_add_env
#define GL_SGIX_texture_add_env 1
#define __GLEE_GL_SGIX_texture_add_env 1
/* Constants */
#define GL_TEXTURE_ENV_BIAS_SGIX                           0x80BE
#endif 

/* GL_EXT_color_subtable */

#ifndef GL_EXT_color_subtable
#define GL_EXT_color_subtable 1
#define __GLEE_GL_EXT_color_subtable 1
/* Constants */
typedef void (APIENTRYP PFNGLCOLORSUBTABLEEXTPROC) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data);
typedef void (APIENTRYP PFNGLCOPYCOLORSUBTABLEEXTPROC) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
GLEE_EXTERN PFNGLCOLORSUBTABLEEXTPROC pglColorSubTableEXT;
GLEE_EXTERN PFNGLCOPYCOLORSUBTABLEEXTPROC pglCopyColorSubTableEXT;
#define glColorSubTableEXT pglColorSubTableEXT
#define glCopyColorSubTableEXT pglCopyColorSubTableEXT
#endif 

/* GL_PGI_vertex_hints */

#ifndef GL_PGI_vertex_hints
#define GL_PGI_vertex_hints 1
#define __GLEE_GL_PGI_vertex_hints 1
/* Constants */
#define GL_VERTEX_DATA_HINT_PGI                            0x1A22A
#define GL_VERTEX_CONSISTENT_HINT_PGI                      0x1A22B
#define GL_MATERIAL_SIDE_HINT_PGI                          0x1A22C
#define GL_MAX_VERTEX_HINT_PGI                             0x1A22D
#define GL_COLOR3_BIT_PGI                                  0x00010000
#define GL_COLOR4_BIT_PGI                                  0x00020000
#define GL_EDGEFLAG_BIT_PGI                                0x00040000
#define GL_INDEX_BIT_PGI                                   0x00080000
#define GL_MAT_AMBIENT_BIT_PGI                             0x00100000
#define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI                 0x00200000
#define GL_MAT_DIFFUSE_BIT_PGI                             0x00400000
#define GL_MAT_EMISSION_BIT_PGI                            0x00800000
#define GL_MAT_COLOR_INDEXES_BIT_PGI                       0x01000000
#define GL_MAT_SHININESS_BIT_PGI                           0x02000000
#define GL_MAT_SPECULAR_BIT_PGI                            0x04000000
#define GL_NORMAL_BIT_PGI                                  0x08000000
#define GL_TEXCOORD1_BIT_PGI                               0x10000000
#define GL_TEXCOORD2_BIT_PGI                               0x20000000
#define GL_TEXCOORD3_BIT_PGI                               0x40000000
#define GL_TEXCOORD4_BIT_PGI                               0x80000000
#define GL_VERTEX23_BIT_PGI                                0x00000004
#define GL_VERTEX4_BIT_PGI                                 0x00000008
#endif 

/* GL_PGI_misc_hints */

#ifndef GL_PGI_misc_hints
#define GL_PGI_misc_hints 1
#define __GLEE_GL_PGI_misc_hints 1
/* Constants */
#define GL_PREFER_DOUBLEBUFFER_HINT_PGI                    0x1A1F8
#define GL_CONSERVE_MEMORY_HINT_PGI                        0x1A1FD
#define GL_RECLAIM_MEMORY_HINT_PGI                         0x1A1FE
#define GL_NATIVE_GRAPHICS_HANDLE_PGI                      0x1A202
#define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI                  0x1A203
#define GL_NATIVE_GRAPHICS_END_HINT_PGI                    0x1A204
#define GL_ALWAYS_FAST_HINT_PGI                            0x1A20C
#define GL_ALWAYS_SOFT_HINT_PGI                            0x1A20D
#define GL_ALLOW_DRAW_OBJ_HINT_PGI                         0x1A20E
#define GL_ALLOW_DRAW_WIN_HINT_PGI                         0x1A20F
#define GL_ALLOW_DRAW_FRG_HINT_PGI                         0x1A210
#define GL_ALLOW_DRAW_MEM_HINT_PGI                         0x1A211
#define GL_STRICT_DEPTHFUNC_HINT_PGI                       0x1A216
#define GL_STRICT_LIGHTING_HINT_PGI                        0x1A217
#define GL_STRICT_SCISSOR_HINT_PGI                         0x1A218
#define GL_FULL_STIPPLE_HINT_PGI                           0x1A219
#define GL_CLIP_NEAR_HINT_PGI                              0x1A220
#define GL_CLIP_FAR_HINT_PGI                               0x1A221
#define GL_WIDE_LINE_HINT_PGI                              0x1A222
#define GL_BACK_NORMALS_HINT_PGI                           0x1A223
typedef void (APIENTRYP PFNGLHINTPGIPROC) (GLenum target, GLint mode);
GLEE_EXTERN PFNGLHINTPGIPROC pglHintPGI;
#define glHintPGI pglHintPGI
#endif 

/* GL_EXT_paletted_texture */

#ifndef GL_EXT_paletted_texture
#define GL_EXT_paletted_texture 1
#define __GLEE_GL_EXT_paletted_texture 1
/* Constants */
#define GL_COLOR_INDEX1_EXT                                0x80E2
#define GL_COLOR_INDEX2_EXT                                0x80E3
#define GL_COLOR_INDEX4_EXT                                0x80E4
#define GL_COLOR_INDEX8_EXT                                0x80E5
#define GL_COLOR_INDEX12_EXT                               0x80E6
#define GL_COLOR_INDEX16_EXT                               0x80E7
#define GL_TEXTURE_INDEX_SIZE_EXT                          0x80ED
typedef void (APIENTRYP PFNGLCOLORTABLEEXTPROC) (GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid * table);
typedef void (APIENTRYP PFNGLGETCOLORTABLEEXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid * data);
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat * params);
GLEE_EXTERN PFNGLCOLORTABLEEXTPROC pglColorTableEXT;
GLEE_EXTERN PFNGLGETCOLORTABLEEXTPROC pglGetColorTableEXT;
GLEE_EXTERN PFNGLGETCOLORTABLEPARAMETERIVEXTPROC pglGetColorTableParameterivEXT;
GLEE_EXTERN PFNGLGETCOLORTABLEPARAMETERFVEXTPROC pglGetColorTableParameterfvEXT;
#define glColorTableEXT pglColorTableEXT
#define glGetColorTableEXT pglGetColorTableEXT
#define glGetColorTableParameterivEXT pglGetColorTableParameterivEXT
#define glGetColorTableParameterfvEXT pglGetColorTableParameterfvEXT
#endif 

/* GL_EXT_clip_volume_hint */

#ifndef GL_EXT_clip_volume_hint
#define GL_EXT_clip_volume_hint 1
#define __GLEE_GL_EXT_clip_volume_hint 1
/* Constants */
#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT                   0x80F0
#endif 

/* GL_SGIX_list_priority */

#ifndef GL_SGIX_list_priority
#define GL_SGIX_list_priority 1
#define __GLEE_GL_SGIX_list_priority 1
/* Constants */
#define GL_LIST_PRIORITY_SGIX                              0x8182
typedef void (APIENTRYP PFNGLGETLISTPARAMETERFVSGIXPROC) (GLuint list, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETLISTPARAMETERIVSGIXPROC) (GLuint list, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLLISTPARAMETERFSGIXPROC) (GLuint list, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLLISTPARAMETERFVSGIXPROC) (GLuint list, GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLLISTPARAMETERISGIXPROC) (GLuint list, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLLISTPARAMETERIVSGIXPROC) (GLuint list, GLenum pname, const GLint * params);
GLEE_EXTERN PFNGLGETLISTPARAMETERFVSGIXPROC pglGetListParameterfvSGIX;
GLEE_EXTERN PFNGLGETLISTPARAMETERIVSGIXPROC pglGetListParameterivSGIX;
GLEE_EXTERN PFNGLLISTPARAMETERFSGIXPROC pglListParameterfSGIX;
GLEE_EXTERN PFNGLLISTPARAMETERFVSGIXPROC pglListParameterfvSGIX;
GLEE_EXTERN PFNGLLISTPARAMETERISGIXPROC pglListParameteriSGIX;
GLEE_EXTERN PFNGLLISTPARAMETERIVSGIXPROC pglListParameterivSGIX;
#define glGetListParameterfvSGIX pglGetListParameterfvSGIX
#define glGetListParameterivSGIX pglGetListParameterivSGIX
#define glListParameterfSGIX pglListParameterfSGIX
#define glListParameterfvSGIX pglListParameterfvSGIX
#define glListParameteriSGIX pglListParameteriSGIX
#define glListParameterivSGIX pglListParameterivSGIX
#endif 

/* GL_SGIX_ir_instrument1 */

#ifndef GL_SGIX_ir_instrument1
#define GL_SGIX_ir_instrument1 1
#define __GLEE_GL_SGIX_ir_instrument1 1
/* Constants */
#define GL_IR_INSTRUMENT1_SGIX                             0x817F
#endif 

/* GL_SGIX_calligraphic_fragment */

#ifndef GL_SGIX_calligraphic_fragment
#define GL_SGIX_calligraphic_fragment 1
#define __GLEE_GL_SGIX_calligraphic_fragment 1
/* Constants */
#define GL_CALLIGRAPHIC_FRAGMENT_SGIX                      0x8183
#endif 

/* GL_SGIX_texture_lod_bias */

#ifndef GL_SGIX_texture_lod_bias
#define GL_SGIX_texture_lod_bias 1
#define __GLEE_GL_SGIX_texture_lod_bias 1
/* Constants */
#define GL_TEXTURE_LOD_BIAS_S_SGIX                         0x818E
#define GL_TEXTURE_LOD_BIAS_T_SGIX                         0x818F
#define GL_TEXTURE_LOD_BIAS_R_SGIX                         0x8190
#endif 

/* GL_SGIX_shadow_ambient */

#ifndef GL_SGIX_shadow_ambient
#define GL_SGIX_shadow_ambient 1
#define __GLEE_GL_SGIX_shadow_ambient 1
/* Constants */
#define GL_SHADOW_AMBIENT_SGIX                             0x80BF
#endif 

/* GL_EXT_index_texture */

#ifndef GL_EXT_index_texture
#define GL_EXT_index_texture 1
#define __GLEE_GL_EXT_index_texture 1
/* Constants */
#endif 

/* GL_EXT_index_material */

#ifndef GL_EXT_index_material
#define GL_EXT_index_material 1
#define __GLEE_GL_EXT_index_material 1
/* Constants */
#define GL_INDEX_MATERIAL_EXT                              0x81B8
#define GL_INDEX_MATERIAL_PARAMETER_EXT                    0x81B9
#define GL_INDEX_MATERIAL_FACE_EXT                         0x81BA
typedef void (APIENTRYP PFNGLINDEXMATERIALEXTPROC) (GLenum face, GLenum mode);
GLEE_EXTERN PFNGLINDEXMATERIALEXTPROC pglIndexMaterialEXT;
#define glIndexMaterialEXT pglIndexMaterialEXT
#endif 

/* GL_EXT_index_func */

#ifndef GL_EXT_index_func
#define GL_EXT_index_func 1
#define __GLEE_GL_EXT_index_func 1
/* Constants */
#define GL_INDEX_TEST_EXT                                  0x81B5
#define GL_INDEX_TEST_FUNC_EXT                             0x81B6
#define GL_INDEX_TEST_REF_EXT                              0x81B7
typedef void (APIENTRYP PFNGLINDEXFUNCEXTPROC) (GLenum func, GLclampf ref);
GLEE_EXTERN PFNGLINDEXFUNCEXTPROC pglIndexFuncEXT;
#define glIndexFuncEXT pglIndexFuncEXT
#endif 

/* GL_EXT_index_array_formats */

#ifndef GL_EXT_index_array_formats
#define GL_EXT_index_array_formats 1
#define __GLEE_GL_EXT_index_array_formats 1
/* Constants */
#define GL_IUI_V2F_EXT                                     0x81AD
#define GL_IUI_V3F_EXT                                     0x81AE
#define GL_IUI_N3F_V2F_EXT                                 0x81AF
#define GL_IUI_N3F_V3F_EXT                                 0x81B0
#define GL_T2F_IUI_V2F_EXT                                 0x81B1
#define GL_T2F_IUI_V3F_EXT                                 0x81B2
#define GL_T2F_IUI_N3F_V2F_EXT                             0x81B3
#define GL_T2F_IUI_N3F_V3F_EXT                             0x81B4
#endif 

/* GL_EXT_compiled_vertex_array */

#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1
#define __GLEE_GL_EXT_compiled_vertex_array 1
/* Constants */
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT                    0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT                    0x81A9
typedef void (APIENTRYP PFNGLLOCKARRAYSEXTPROC) (GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLUNLOCKARRAYSEXTPROC) ();
GLEE_EXTERN PFNGLLOCKARRAYSEXTPROC pglLockArraysEXT;
GLEE_EXTERN PFNGLUNLOCKARRAYSEXTPROC pglUnlockArraysEXT;
#define glLockArraysEXT pglLockArraysEXT
#define glUnlockArraysEXT pglUnlockArraysEXT
#endif 

/* GL_EXT_cull_vertex */

#ifndef GL_EXT_cull_vertex
#define GL_EXT_cull_vertex 1
#define __GLEE_GL_EXT_cull_vertex 1
/* Constants */
#define GL_CULL_VERTEX_EXT                                 0x81AA
#define GL_CULL_VERTEX_EYE_POSITION_EXT                    0x81AB
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT                 0x81AC
typedef void (APIENTRYP PFNGLCULLPARAMETERDVEXTPROC) (GLenum pname, GLdouble * params);
typedef void (APIENTRYP PFNGLCULLPARAMETERFVEXTPROC) (GLenum pname, GLfloat * params);
GLEE_EXTERN PFNGLCULLPARAMETERDVEXTPROC pglCullParameterdvEXT;
GLEE_EXTERN PFNGLCULLPARAMETERFVEXTPROC pglCullParameterfvEXT;
#define glCullParameterdvEXT pglCullParameterdvEXT
#define glCullParameterfvEXT pglCullParameterfvEXT
#endif 

/* GL_SGIX_ycrcb */

#ifndef GL_SGIX_ycrcb
#define GL_SGIX_ycrcb 1
#define __GLEE_GL_SGIX_ycrcb 1
/* Constants */
#define GL_YCRCB_422_SGIX                                  0x81BB
#define GL_YCRCB_444_SGIX                                  0x81BC
#endif 

/* GL_SGIX_fragment_lighting */

#ifndef GL_SGIX_fragment_lighting
#define GL_SGIX_fragment_lighting 1
#define __GLEE_GL_SGIX_fragment_lighting 1
/* Constants */
#define GL_FRAGMENT_LIGHTING_SGIX                          0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX                    0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX               0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX          0x8403
#define GL_MAX_FRAGMENT_LIGHTS_SGIX                        0x8404
#define GL_MAX_ACTIVE_LIGHTS_SGIX                          0x8405
#define GL_CURRENT_RASTER_NORMAL_SGIX                      0x8406
#define GL_LIGHT_ENV_MODE_SGIX                             0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX          0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX              0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX               0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX  0x840B
#define GL_FRAGMENT_LIGHT0_SGIX                            0x840C
#define GL_FRAGMENT_LIGHT1_SGIX                            0x840D
#define GL_FRAGMENT_LIGHT2_SGIX                            0x840E
#define GL_FRAGMENT_LIGHT3_SGIX                            0x840F
#define GL_FRAGMENT_LIGHT4_SGIX                            0x8410
#define GL_FRAGMENT_LIGHT5_SGIX                            0x8411
#define GL_FRAGMENT_LIGHT6_SGIX                            0x8412
#define GL_FRAGMENT_LIGHT7_SGIX                            0x8413
typedef void (APIENTRYP PFNGLFRAGMENTCOLORMATERIALSGIXPROC) (GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTFSGIXPROC) (GLenum light, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTFVSGIXPROC) (GLenum light, GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTISGIXPROC) (GLenum light, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTIVSGIXPROC) (GLenum light, GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELFSGIXPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELFVSGIXPROC) (GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELISGIXPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELIVSGIXPROC) (GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALFSGIXPROC) (GLenum face, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALFVSGIXPROC) (GLenum face, GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALISGIXPROC) (GLenum face, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALIVSGIXPROC) (GLenum face, GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLGETFRAGMENTLIGHTFVSGIXPROC) (GLenum light, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETFRAGMENTLIGHTIVSGIXPROC) (GLenum light, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETFRAGMENTMATERIALFVSGIXPROC) (GLenum face, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETFRAGMENTMATERIALIVSGIXPROC) (GLenum face, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLLIGHTENVISGIXPROC) (GLenum pname, GLint param);
GLEE_EXTERN PFNGLFRAGMENTCOLORMATERIALSGIXPROC pglFragmentColorMaterialSGIX;
GLEE_EXTERN PFNGLFRAGMENTLIGHTFSGIXPROC pglFragmentLightfSGIX;
GLEE_EXTERN PFNGLFRAGMENTLIGHTFVSGIXPROC pglFragmentLightfvSGIX;
GLEE_EXTERN PFNGLFRAGMENTLIGHTISGIXPROC pglFragmentLightiSGIX;
GLEE_EXTERN PFNGLFRAGMENTLIGHTIVSGIXPROC pglFragmentLightivSGIX;
GLEE_EXTERN PFNGLFRAGMENTLIGHTMODELFSGIXPROC pglFragmentLightModelfSGIX;
GLEE_EXTERN PFNGLFRAGMENTLIGHTMODELFVSGIXPROC pglFragmentLightModelfvSGIX;
GLEE_EXTERN PFNGLFRAGMENTLIGHTMODELISGIXPROC pglFragmentLightModeliSGIX;
GLEE_EXTERN PFNGLFRAGMENTLIGHTMODELIVSGIXPROC pglFragmentLightModelivSGIX;
GLEE_EXTERN PFNGLFRAGMENTMATERIALFSGIXPROC pglFragmentMaterialfSGIX;
GLEE_EXTERN PFNGLFRAGMENTMATERIALFVSGIXPROC pglFragmentMaterialfvSGIX;
GLEE_EXTERN PFNGLFRAGMENTMATERIALISGIXPROC pglFragmentMaterialiSGIX;
GLEE_EXTERN PFNGLFRAGMENTMATERIALIVSGIXPROC pglFragmentMaterialivSGIX;
GLEE_EXTERN PFNGLGETFRAGMENTLIGHTFVSGIXPROC pglGetFragmentLightfvSGIX;
GLEE_EXTERN PFNGLGETFRAGMENTLIGHTIVSGIXPROC pglGetFragmentLightivSGIX;
GLEE_EXTERN PFNGLGETFRAGMENTMATERIALFVSGIXPROC pglGetFragmentMaterialfvSGIX;
GLEE_EXTERN PFNGLGETFRAGMENTMATERIALIVSGIXPROC pglGetFragmentMaterialivSGIX;
GLEE_EXTERN PFNGLLIGHTENVISGIXPROC pglLightEnviSGIX;
#define glFragmentColorMaterialSGIX pglFragmentColorMaterialSGIX
#define glFragmentLightfSGIX pglFragmentLightfSGIX
#define glFragmentLightfvSGIX pglFragmentLightfvSGIX
#define glFragmentLightiSGIX pglFragmentLightiSGIX
#define glFragmentLightivSGIX pglFragmentLightivSGIX
#define glFragmentLightModelfSGIX pglFragmentLightModelfSGIX
#define glFragmentLightModelfvSGIX pglFragmentLightModelfvSGIX
#define glFragmentLightModeliSGIX pglFragmentLightModeliSGIX
#define glFragmentLightModelivSGIX pglFragmentLightModelivSGIX
#define glFragmentMaterialfSGIX pglFragmentMaterialfSGIX
#define glFragmentMaterialfvSGIX pglFragmentMaterialfvSGIX
#define glFragmentMaterialiSGIX pglFragmentMaterialiSGIX
#define glFragmentMaterialivSGIX pglFragmentMaterialivSGIX
#define glGetFragmentLightfvSGIX pglGetFragmentLightfvSGIX
#define glGetFragmentLightivSGIX pglGetFragmentLightivSGIX
#define glGetFragmentMaterialfvSGIX pglGetFragmentMaterialfvSGIX
#define glGetFragmentMaterialivSGIX pglGetFragmentMaterialivSGIX
#define glLightEnviSGIX pglLightEnviSGIX
#endif 

/* GL_IBM_rasterpos_clip */

#ifndef GL_IBM_rasterpos_clip
#define GL_IBM_rasterpos_clip 1
#define __GLEE_GL_IBM_rasterpos_clip 1
/* Constants */
#define GL_RASTER_POSITION_UNCLIPPED_IBM                   0x19262
#endif 

/* GL_HP_texture_lighting */

#ifndef GL_HP_texture_lighting
#define GL_HP_texture_lighting 1
#define __GLEE_GL_HP_texture_lighting 1
/* Constants */
#define GL_TEXTURE_LIGHTING_MODE_HP                        0x8167
#define GL_TEXTURE_POST_SPECULAR_HP                        0x8168
#define GL_TEXTURE_PRE_SPECULAR_HP                         0x8169
#endif 

/* GL_EXT_draw_range_elements */

#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements 1
#define __GLEE_GL_EXT_draw_range_elements 1
/* Constants */
#define GL_MAX_ELEMENTS_VERTICES_EXT                       0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT                        0x80E9
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSEXTPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices);
GLEE_EXTERN PFNGLDRAWRANGEELEMENTSEXTPROC pglDrawRangeElementsEXT;
#define glDrawRangeElementsEXT pglDrawRangeElementsEXT
#endif 

/* GL_WIN_phong_shading */

#ifndef GL_WIN_phong_shading
#define GL_WIN_phong_shading 1
#define __GLEE_GL_WIN_phong_shading 1
/* Constants */
#define GL_PHONG_WIN                                       0x80EA
#define GL_PHONG_HINT_WIN                                  0x80EB
#endif 

/* GL_WIN_specular_fog */

#ifndef GL_WIN_specular_fog
#define GL_WIN_specular_fog 1
#define __GLEE_GL_WIN_specular_fog 1
/* Constants */
#define GL_FOG_SPECULAR_TEXTURE_WIN                        0x80EC
#endif 

/* GL_EXT_light_texture */

#ifndef GL_EXT_light_texture
#define GL_EXT_light_texture 1
#define __GLEE_GL_EXT_light_texture 1
/* Constants */
#define GL_FRAGMENT_MATERIAL_EXT                           0x8349
#define GL_FRAGMENT_NORMAL_EXT                             0x834A
#define GL_FRAGMENT_COLOR_EXT                              0x834C
#define GL_ATTENUATION_EXT                                 0x834D
#define GL_SHADOW_ATTENUATION_EXT                          0x834E
#define GL_TEXTURE_APPLICATION_MODE_EXT                    0x834F
#define GL_TEXTURE_LIGHT_EXT                               0x8350
#define GL_TEXTURE_MATERIAL_FACE_EXT                       0x8351
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT                  0x8352
typedef void (APIENTRYP PFNGLAPPLYTEXTUREEXTPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLTEXTURELIGHTEXTPROC) (GLenum pname);
typedef void (APIENTRYP PFNGLTEXTUREMATERIALEXTPROC) (GLenum face, GLenum mode);
GLEE_EXTERN PFNGLAPPLYTEXTUREEXTPROC pglApplyTextureEXT;
GLEE_EXTERN PFNGLTEXTURELIGHTEXTPROC pglTextureLightEXT;
GLEE_EXTERN PFNGLTEXTUREMATERIALEXTPROC pglTextureMaterialEXT;
#define glApplyTextureEXT pglApplyTextureEXT
#define glTextureLightEXT pglTextureLightEXT
#define glTextureMaterialEXT pglTextureMaterialEXT
#endif 

/* GL_SGIX_blend_alpha_minmax */

#ifndef GL_SGIX_blend_alpha_minmax
#define GL_SGIX_blend_alpha_minmax 1
#define __GLEE_GL_SGIX_blend_alpha_minmax 1
/* Constants */
#define GL_ALPHA_MIN_SGIX                                  0x8320
#define GL_ALPHA_MAX_SGIX                                  0x8321
#endif 

/* GL_SGIX_impact_pixel_texture */

#ifndef GL_SGIX_impact_pixel_texture
#define GL_SGIX_impact_pixel_texture 1
#define __GLEE_GL_SGIX_impact_pixel_texture 1
/* Constants */
#define GL_PIXEL_TEX_GEN_Q_CEILING_SGIX                    0x8184
#define GL_PIXEL_TEX_GEN_Q_ROUND_SGIX                      0x8185
#define GL_PIXEL_TEX_GEN_Q_FLOOR_SGIX                      0x8186
#define GL_PIXEL_TEX_GEN_ALPHA_REPLACE_SGIX                0x8187
#define GL_PIXEL_TEX_GEN_ALPHA_NO_REPLACE_SGIX             0x8188
#define GL_PIXEL_TEX_GEN_ALPHA_LS_SGIX                     0x8189
#define GL_PIXEL_TEX_GEN_ALPHA_MS_SGIX                     0x818A
#endif 

/* GL_EXT_bgra */

#ifndef GL_EXT_bgra
#define GL_EXT_bgra 1
#define __GLEE_GL_EXT_bgra 1
/* Constants */
#define GL_BGR_EXT                                         0x80E0
#define GL_BGRA_EXT                                        0x80E1
#endif 

/* GL_SGIX_async */

#ifndef GL_SGIX_async
#define GL_SGIX_async 1
#define __GLEE_GL_SGIX_async 1
/* Constants */
#define GL_ASYNC_MARKER_SGIX                               0x8329
typedef void (APIENTRYP PFNGLASYNCMARKERSGIXPROC) (GLuint marker);
typedef GLint (APIENTRYP PFNGLFINISHASYNCSGIXPROC) (GLuint * markerp);
typedef GLint (APIENTRYP PFNGLPOLLASYNCSGIXPROC) (GLuint * markerp);
typedef GLuint (APIENTRYP PFNGLGENASYNCMARKERSSGIXPROC) (GLsizei range);
typedef void (APIENTRYP PFNGLDELETEASYNCMARKERSSGIXPROC) (GLuint marker, GLsizei range);
typedef GLboolean (APIENTRYP PFNGLISASYNCMARKERSGIXPROC) (GLuint marker);
GLEE_EXTERN PFNGLASYNCMARKERSGIXPROC pglAsyncMarkerSGIX;
GLEE_EXTERN PFNGLFINISHASYNCSGIXPROC pglFinishAsyncSGIX;
GLEE_EXTERN PFNGLPOLLASYNCSGIXPROC pglPollAsyncSGIX;
GLEE_EXTERN PFNGLGENASYNCMARKERSSGIXPROC pglGenAsyncMarkersSGIX;
GLEE_EXTERN PFNGLDELETEASYNCMARKERSSGIXPROC pglDeleteAsyncMarkersSGIX;
GLEE_EXTERN PFNGLISASYNCMARKERSGIXPROC pglIsAsyncMarkerSGIX;
#define glAsyncMarkerSGIX pglAsyncMarkerSGIX
#define glFinishAsyncSGIX pglFinishAsyncSGIX
#define glPollAsyncSGIX pglPollAsyncSGIX
#define glGenAsyncMarkersSGIX pglGenAsyncMarkersSGIX
#define glDeleteAsyncMarkersSGIX pglDeleteAsyncMarkersSGIX
#define glIsAsyncMarkerSGIX pglIsAsyncMarkerSGIX
#endif 

/* GL_SGIX_async_pixel */

#ifndef GL_SGIX_async_pixel
#define GL_SGIX_async_pixel 1
#define __GLEE_GL_SGIX_async_pixel 1
/* Constants */
#define GL_ASYNC_TEX_IMAGE_SGIX                            0x835C
#define GL_ASYNC_DRAW_PIXELS_SGIX                          0x835D
#define GL_ASYNC_READ_PIXELS_SGIX                          0x835E
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX                        0x835F
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX                      0x8360
#define GL_MAX_ASYNC_READ_PIXELS_SGIX                      0x8361
#endif 

/* GL_SGIX_async_histogram */

#ifndef GL_SGIX_async_histogram
#define GL_SGIX_async_histogram 1
#define __GLEE_GL_SGIX_async_histogram 1
/* Constants */
#define GL_ASYNC_HISTOGRAM_SGIX                            0x832C
#define GL_MAX_ASYNC_HISTOGRAM_SGIX                        0x832D
#endif 

/* GL_INTEL_texture_scissor */

#ifndef GL_INTEL_texture_scissor
#define GL_INTEL_texture_scissor 1
#define __GLEE_GL_INTEL_texture_scissor 1
/* Constants */
#endif 

/* GL_INTEL_parallel_arrays */

#ifndef GL_INTEL_parallel_arrays
#define GL_INTEL_parallel_arrays 1
#define __GLEE_GL_INTEL_parallel_arrays 1
/* Constants */
#define GL_PARALLEL_ARRAYS_INTEL                           0x83F4
#define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL            0x83F5
#define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL            0x83F6
#define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL             0x83F7
#define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL     0x83F8
typedef void (APIENTRYP PFNGLVERTEXPOINTERVINTELPROC) (GLint size, GLenum type, const GLvoid* * pointer);
typedef void (APIENTRYP PFNGLNORMALPOINTERVINTELPROC) (GLenum type, const GLvoid* * pointer);
typedef void (APIENTRYP PFNGLCOLORPOINTERVINTELPROC) (GLint size, GLenum type, const GLvoid* * pointer);
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERVINTELPROC) (GLint size, GLenum type, const GLvoid* * pointer);
GLEE_EXTERN PFNGLVERTEXPOINTERVINTELPROC pglVertexPointervINTEL;
GLEE_EXTERN PFNGLNORMALPOINTERVINTELPROC pglNormalPointervINTEL;
GLEE_EXTERN PFNGLCOLORPOINTERVINTELPROC pglColorPointervINTEL;
GLEE_EXTERN PFNGLTEXCOORDPOINTERVINTELPROC pglTexCoordPointervINTEL;
#define glVertexPointervINTEL pglVertexPointervINTEL
#define glNormalPointervINTEL pglNormalPointervINTEL
#define glColorPointervINTEL pglColorPointervINTEL
#define glTexCoordPointervINTEL pglTexCoordPointervINTEL
#endif 

/* GL_HP_occlusion_test */

#ifndef GL_HP_occlusion_test
#define GL_HP_occlusion_test 1
#define __GLEE_GL_HP_occlusion_test 1
/* Constants */
#define GL_OCCLUSION_TEST_HP                               0x8165
#define GL_OCCLUSION_TEST_RESULT_HP                        0x8166
#endif 

/* GL_EXT_pixel_transform */

#ifndef GL_EXT_pixel_transform
#define GL_EXT_pixel_transform 1
#define __GLEE_GL_EXT_pixel_transform 1
/* Constants */
#define GL_PIXEL_TRANSFORM_2D_EXT                          0x8330
#define GL_PIXEL_MAG_FILTER_EXT                            0x8331
#define GL_PIXEL_MIN_FILTER_EXT                            0x8332
#define GL_PIXEL_CUBIC_WEIGHT_EXT                          0x8333
#define GL_CUBIC_EXT                                       0x8334
#define GL_AVERAGE_EXT                                     0x8335
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT              0x8336
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT          0x8337
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT                   0x8338
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERIEXTPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERFEXTPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC) (GLenum target, GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC) (GLenum target, GLenum pname, const GLfloat * params);
GLEE_EXTERN PFNGLPIXELTRANSFORMPARAMETERIEXTPROC pglPixelTransformParameteriEXT;
GLEE_EXTERN PFNGLPIXELTRANSFORMPARAMETERFEXTPROC pglPixelTransformParameterfEXT;
GLEE_EXTERN PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC pglPixelTransformParameterivEXT;
GLEE_EXTERN PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC pglPixelTransformParameterfvEXT;
#define glPixelTransformParameteriEXT pglPixelTransformParameteriEXT
#define glPixelTransformParameterfEXT pglPixelTransformParameterfEXT
#define glPixelTransformParameterivEXT pglPixelTransformParameterivEXT
#define glPixelTransformParameterfvEXT pglPixelTransformParameterfvEXT
#endif 

/* GL_EXT_pixel_transform_color_table */

#ifndef GL_EXT_pixel_transform_color_table
#define GL_EXT_pixel_transform_color_table 1
#define __GLEE_GL_EXT_pixel_transform_color_table 1
/* Constants */
#endif 

/* GL_EXT_shared_texture_palette */

#ifndef GL_EXT_shared_texture_palette
#define GL_EXT_shared_texture_palette 1
#define __GLEE_GL_EXT_shared_texture_palette 1
/* Constants */
#define GL_SHARED_TEXTURE_PALETTE_EXT                      0x81FB
#endif 

/* GL_EXT_separate_specular_color */

#ifndef GL_EXT_separate_specular_color
#define GL_EXT_separate_specular_color 1
#define __GLEE_GL_EXT_separate_specular_color 1
/* Constants */
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT                   0x81F8
#define GL_SINGLE_COLOR_EXT                                0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT                     0x81FA
#endif 

/* GL_EXT_secondary_color */

#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color 1
#define __GLEE_GL_EXT_secondary_color 1
/* Constants */
#define GL_COLOR_SUM_EXT                                   0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT                     0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT                  0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT                  0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT                0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT               0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT                       0x845E
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BEXTPROC) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVEXTPROC) (const GLbyte * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DEXTPROC) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVEXTPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FEXTPROC) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVEXTPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IEXTPROC) (GLint red, GLint green, GLint blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVEXTPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SEXTPROC) (GLshort red, GLshort green, GLshort blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVEXTPROC) (const GLshort * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBEXTPROC) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVEXTPROC) (const GLubyte * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIEXTPROC) (GLuint red, GLuint green, GLuint blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVEXTPROC) (const GLuint * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USEXTPROC) (GLushort red, GLushort green, GLushort blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVEXTPROC) (const GLushort * v);
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
GLEE_EXTERN PFNGLSECONDARYCOLOR3BEXTPROC pglSecondaryColor3bEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3BVEXTPROC pglSecondaryColor3bvEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3DEXTPROC pglSecondaryColor3dEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3DVEXTPROC pglSecondaryColor3dvEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3FEXTPROC pglSecondaryColor3fEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3FVEXTPROC pglSecondaryColor3fvEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3IEXTPROC pglSecondaryColor3iEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3IVEXTPROC pglSecondaryColor3ivEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3SEXTPROC pglSecondaryColor3sEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3SVEXTPROC pglSecondaryColor3svEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3UBEXTPROC pglSecondaryColor3ubEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3UBVEXTPROC pglSecondaryColor3ubvEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3UIEXTPROC pglSecondaryColor3uiEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3UIVEXTPROC pglSecondaryColor3uivEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3USEXTPROC pglSecondaryColor3usEXT;
GLEE_EXTERN PFNGLSECONDARYCOLOR3USVEXTPROC pglSecondaryColor3usvEXT;
GLEE_EXTERN PFNGLSECONDARYCOLORPOINTEREXTPROC pglSecondaryColorPointerEXT;
#define glSecondaryColor3bEXT pglSecondaryColor3bEXT
#define glSecondaryColor3bvEXT pglSecondaryColor3bvEXT
#define glSecondaryColor3dEXT pglSecondaryColor3dEXT
#define glSecondaryColor3dvEXT pglSecondaryColor3dvEXT
#define glSecondaryColor3fEXT pglSecondaryColor3fEXT
#define glSecondaryColor3fvEXT pglSecondaryColor3fvEXT
#define glSecondaryColor3iEXT pglSecondaryColor3iEXT
#define glSecondaryColor3ivEXT pglSecondaryColor3ivEXT
#define glSecondaryColor3sEXT pglSecondaryColor3sEXT
#define glSecondaryColor3svEXT pglSecondaryColor3svEXT
#define glSecondaryColor3ubEXT pglSecondaryColor3ubEXT
#define glSecondaryColor3ubvEXT pglSecondaryColor3ubvEXT
#define glSecondaryColor3uiEXT pglSecondaryColor3uiEXT
#define glSecondaryColor3uivEXT pglSecondaryColor3uivEXT
#define glSecondaryColor3usEXT pglSecondaryColor3usEXT
#define glSecondaryColor3usvEXT pglSecondaryColor3usvEXT
#define glSecondaryColorPointerEXT pglSecondaryColorPointerEXT
#endif 

/* GL_EXT_texture_perturb_normal */

#ifndef GL_EXT_texture_perturb_normal
#define GL_EXT_texture_perturb_normal 1
#define __GLEE_GL_EXT_texture_perturb_normal 1
/* Constants */
#define GL_PERTURB_EXT                                     0x85AE
#define GL_TEXTURE_NORMAL_EXT                              0x85AF
typedef void (APIENTRYP PFNGLTEXTURENORMALEXTPROC) (GLenum mode);
GLEE_EXTERN PFNGLTEXTURENORMALEXTPROC pglTextureNormalEXT;
#define glTextureNormalEXT pglTextureNormalEXT
#endif 

/* GL_EXT_multi_draw_arrays */

#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1
#define __GLEE_GL_EXT_multi_draw_arrays 1
/* Constants */
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSEXTPROC) (GLenum mode, GLint * first, GLsizei * count, GLsizei primcount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSEXTPROC) (GLenum mode, const GLsizei * count, GLenum type, const GLvoid* * indices, GLsizei primcount);
GLEE_EXTERN PFNGLMULTIDRAWARRAYSEXTPROC pglMultiDrawArraysEXT;
GLEE_EXTERN PFNGLMULTIDRAWELEMENTSEXTPROC pglMultiDrawElementsEXT;
#define glMultiDrawArraysEXT pglMultiDrawArraysEXT
#define glMultiDrawElementsEXT pglMultiDrawElementsEXT
#endif 

/* GL_EXT_fog_coord */

#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1
#define __GLEE_GL_EXT_fog_coord 1
/* Constants */
#define GL_FOG_COORDINATE_SOURCE_EXT                       0x8450
#define GL_FOG_COORDINATE_EXT                              0x8451
#define GL_FRAGMENT_DEPTH_EXT                              0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT                      0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT                   0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT                 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT                0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT                        0x8457
typedef void (APIENTRYP PFNGLFOGCOORDFEXTPROC) (GLfloat coord);
typedef void (APIENTRYP PFNGLFOGCOORDFVEXTPROC) (const GLfloat * coord);
typedef void (APIENTRYP PFNGLFOGCOORDDEXTPROC) (GLdouble coord);
typedef void (APIENTRYP PFNGLFOGCOORDDVEXTPROC) (const GLdouble * coord);
typedef void (APIENTRYP PFNGLFOGCOORDPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid * pointer);
GLEE_EXTERN PFNGLFOGCOORDFEXTPROC pglFogCoordfEXT;
GLEE_EXTERN PFNGLFOGCOORDFVEXTPROC pglFogCoordfvEXT;
GLEE_EXTERN PFNGLFOGCOORDDEXTPROC pglFogCoorddEXT;
GLEE_EXTERN PFNGLFOGCOORDDVEXTPROC pglFogCoorddvEXT;
GLEE_EXTERN PFNGLFOGCOORDPOINTEREXTPROC pglFogCoordPointerEXT;
#define glFogCoordfEXT pglFogCoordfEXT
#define glFogCoordfvEXT pglFogCoordfvEXT
#define glFogCoorddEXT pglFogCoorddEXT
#define glFogCoorddvEXT pglFogCoorddvEXT
#define glFogCoordPointerEXT pglFogCoordPointerEXT
#endif 

/* GL_REND_screen_coordinates */

#ifndef GL_REND_screen_coordinates
#define GL_REND_screen_coordinates 1
#define __GLEE_GL_REND_screen_coordinates 1
/* Constants */
#define GL_SCREEN_COORDINATES_REND                         0x8490
#define GL_INVERTED_SCREEN_W_REND                          0x8491
#endif 

/* GL_EXT_coordinate_frame */

#ifndef GL_EXT_coordinate_frame
#define GL_EXT_coordinate_frame 1
#define __GLEE_GL_EXT_coordinate_frame 1
/* Constants */
#define GL_TANGENT_ARRAY_EXT                               0x8439
#define GL_BINORMAL_ARRAY_EXT                              0x843A
#define GL_CURRENT_TANGENT_EXT                             0x843B
#define GL_CURRENT_BINORMAL_EXT                            0x843C
#define GL_TANGENT_ARRAY_TYPE_EXT                          0x843E
#define GL_TANGENT_ARRAY_STRIDE_EXT                        0x843F
#define GL_BINORMAL_ARRAY_TYPE_EXT                         0x8440
#define GL_BINORMAL_ARRAY_STRIDE_EXT                       0x8441
#define GL_TANGENT_ARRAY_POINTER_EXT                       0x8442
#define GL_BINORMAL_ARRAY_POINTER_EXT                      0x8443
#define GL_MAP1_TANGENT_EXT                                0x8444
#define GL_MAP2_TANGENT_EXT                                0x8445
#define GL_MAP1_BINORMAL_EXT                               0x8446
#define GL_MAP2_BINORMAL_EXT                               0x8447
typedef void (APIENTRYP PFNGLTANGENT3BEXTPROC) (GLbyte tx, GLbyte ty, GLbyte tz);
typedef void (APIENTRYP PFNGLTANGENT3BVEXTPROC) (const GLbyte * v);
typedef void (APIENTRYP PFNGLTANGENT3DEXTPROC) (GLdouble tx, GLdouble ty, GLdouble tz);
typedef void (APIENTRYP PFNGLTANGENT3DVEXTPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLTANGENT3FEXTPROC) (GLfloat tx, GLfloat ty, GLfloat tz);
typedef void (APIENTRYP PFNGLTANGENT3FVEXTPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLTANGENT3IEXTPROC) (GLint tx, GLint ty, GLint tz);
typedef void (APIENTRYP PFNGLTANGENT3IVEXTPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLTANGENT3SEXTPROC) (GLshort tx, GLshort ty, GLshort tz);
typedef void (APIENTRYP PFNGLTANGENT3SVEXTPROC) (const GLshort * v);
typedef void (APIENTRYP PFNGLBINORMAL3BEXTPROC) (GLbyte bx, GLbyte by, GLbyte bz);
typedef void (APIENTRYP PFNGLBINORMAL3BVEXTPROC) (const GLbyte * v);
typedef void (APIENTRYP PFNGLBINORMAL3DEXTPROC) (GLdouble bx, GLdouble by, GLdouble bz);
typedef void (APIENTRYP PFNGLBINORMAL3DVEXTPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLBINORMAL3FEXTPROC) (GLfloat bx, GLfloat by, GLfloat bz);
typedef void (APIENTRYP PFNGLBINORMAL3FVEXTPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLBINORMAL3IEXTPROC) (GLint bx, GLint by, GLint bz);
typedef void (APIENTRYP PFNGLBINORMAL3IVEXTPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLBINORMAL3SEXTPROC) (GLshort bx, GLshort by, GLshort bz);
typedef void (APIENTRYP PFNGLBINORMAL3SVEXTPROC) (const GLshort * v);
typedef void (APIENTRYP PFNGLTANGENTPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLBINORMALPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid * pointer);
GLEE_EXTERN PFNGLTANGENT3BEXTPROC pglTangent3bEXT;
GLEE_EXTERN PFNGLTANGENT3BVEXTPROC pglTangent3bvEXT;
GLEE_EXTERN PFNGLTANGENT3DEXTPROC pglTangent3dEXT;
GLEE_EXTERN PFNGLTANGENT3DVEXTPROC pglTangent3dvEXT;
GLEE_EXTERN PFNGLTANGENT3FEXTPROC pglTangent3fEXT;
GLEE_EXTERN PFNGLTANGENT3FVEXTPROC pglTangent3fvEXT;
GLEE_EXTERN PFNGLTANGENT3IEXTPROC pglTangent3iEXT;
GLEE_EXTERN PFNGLTANGENT3IVEXTPROC pglTangent3ivEXT;
GLEE_EXTERN PFNGLTANGENT3SEXTPROC pglTangent3sEXT;
GLEE_EXTERN PFNGLTANGENT3SVEXTPROC pglTangent3svEXT;
GLEE_EXTERN PFNGLBINORMAL3BEXTPROC pglBinormal3bEXT;
GLEE_EXTERN PFNGLBINORMAL3BVEXTPROC pglBinormal3bvEXT;
GLEE_EXTERN PFNGLBINORMAL3DEXTPROC pglBinormal3dEXT;
GLEE_EXTERN PFNGLBINORMAL3DVEXTPROC pglBinormal3dvEXT;
GLEE_EXTERN PFNGLBINORMAL3FEXTPROC pglBinormal3fEXT;
GLEE_EXTERN PFNGLBINORMAL3FVEXTPROC pglBinormal3fvEXT;
GLEE_EXTERN PFNGLBINORMAL3IEXTPROC pglBinormal3iEXT;
GLEE_EXTERN PFNGLBINORMAL3IVEXTPROC pglBinormal3ivEXT;
GLEE_EXTERN PFNGLBINORMAL3SEXTPROC pglBinormal3sEXT;
GLEE_EXTERN PFNGLBINORMAL3SVEXTPROC pglBinormal3svEXT;
GLEE_EXTERN PFNGLTANGENTPOINTEREXTPROC pglTangentPointerEXT;
GLEE_EXTERN PFNGLBINORMALPOINTEREXTPROC pglBinormalPointerEXT;
#define glTangent3bEXT pglTangent3bEXT
#define glTangent3bvEXT pglTangent3bvEXT
#define glTangent3dEXT pglTangent3dEXT
#define glTangent3dvEXT pglTangent3dvEXT
#define glTangent3fEXT pglTangent3fEXT
#define glTangent3fvEXT pglTangent3fvEXT
#define glTangent3iEXT pglTangent3iEXT
#define glTangent3ivEXT pglTangent3ivEXT
#define glTangent3sEXT pglTangent3sEXT
#define glTangent3svEXT pglTangent3svEXT
#define glBinormal3bEXT pglBinormal3bEXT
#define glBinormal3bvEXT pglBinormal3bvEXT
#define glBinormal3dEXT pglBinormal3dEXT
#define glBinormal3dvEXT pglBinormal3dvEXT
#define glBinormal3fEXT pglBinormal3fEXT
#define glBinormal3fvEXT pglBinormal3fvEXT
#define glBinormal3iEXT pglBinormal3iEXT
#define glBinormal3ivEXT pglBinormal3ivEXT
#define glBinormal3sEXT pglBinormal3sEXT
#define glBinormal3svEXT pglBinormal3svEXT
#define glTangentPointerEXT pglTangentPointerEXT
#define glBinormalPointerEXT pglBinormalPointerEXT
#endif 

/* GL_EXT_texture_env_combine */

#ifndef GL_EXT_texture_env_combine
#define GL_EXT_texture_env_combine 1
#define __GLEE_GL_EXT_texture_env_combine 1
/* Constants */
#define GL_COMBINE_EXT                                     0x8570
#define GL_COMBINE_RGB_EXT                                 0x8571
#define GL_COMBINE_ALPHA_EXT                               0x8572
#define GL_RGB_SCALE_EXT                                   0x8573
#define GL_ADD_SIGNED_EXT                                  0x8574
#define GL_INTERPOLATE_EXT                                 0x8575
#define GL_CONSTANT_EXT                                    0x8576
#define GL_PRIMARY_COLOR_EXT                               0x8577
#define GL_PREVIOUS_EXT                                    0x8578
#define GL_SOURCE0_RGB_EXT                                 0x8580
#define GL_SOURCE1_RGB_EXT                                 0x8581
#define GL_SOURCE2_RGB_EXT                                 0x8582
#define GL_SOURCE0_ALPHA_EXT                               0x8588
#define GL_SOURCE1_ALPHA_EXT                               0x8589
#define GL_SOURCE2_ALPHA_EXT                               0x858A
#define GL_OPERAND0_RGB_EXT                                0x8590
#define GL_OPERAND1_RGB_EXT                                0x8591
#define GL_OPERAND2_RGB_EXT                                0x8592
#define GL_OPERAND0_ALPHA_EXT                              0x8598
#define GL_OPERAND1_ALPHA_EXT                              0x8599
#define GL_OPERAND2_ALPHA_EXT                              0x859A
#endif 

/* GL_APPLE_specular_vector */

#ifndef GL_APPLE_specular_vector
#define GL_APPLE_specular_vector 1
#define __GLEE_GL_APPLE_specular_vector 1
/* Constants */
#define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE               0x85B0
#endif 

/* GL_APPLE_transform_hint */

#ifndef GL_APPLE_transform_hint
#define GL_APPLE_transform_hint 1
#define __GLEE_GL_APPLE_transform_hint 1
/* Constants */
#define GL_TRANSFORM_HINT_APPLE                            0x85B1
#endif 

/* GL_SGIX_fog_scale */

#ifndef GL_SGIX_fog_scale
#define GL_SGIX_fog_scale 1
#define __GLEE_GL_SGIX_fog_scale 1
/* Constants */
#define GL_FOG_SCALE_SGIX                                  0x81FC
#define GL_FOG_SCALE_VALUE_SGIX                            0x81FD
#endif 

/* GL_SUNX_constant_data */

#ifndef GL_SUNX_constant_data
#define GL_SUNX_constant_data 1
#define __GLEE_GL_SUNX_constant_data 1
/* Constants */
#define GL_UNPACK_CONSTANT_DATA_SUNX                       0x81D5
#define GL_TEXTURE_CONSTANT_DATA_SUNX                      0x81D6
typedef void (APIENTRYP PFNGLFINISHTEXTURESUNXPROC) ();
GLEE_EXTERN PFNGLFINISHTEXTURESUNXPROC pglFinishTextureSUNX;
#define glFinishTextureSUNX pglFinishTextureSUNX
#endif 

/* GL_SUN_global_alpha */

#ifndef GL_SUN_global_alpha
#define GL_SUN_global_alpha 1
#define __GLEE_GL_SUN_global_alpha 1
/* Constants */
#define GL_GLOBAL_ALPHA_SUN                                0x81D9
#define GL_GLOBAL_ALPHA_FACTOR_SUN                         0x81DA
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORBSUNPROC) (GLbyte factor);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORSSUNPROC) (GLshort factor);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORISUNPROC) (GLint factor);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORFSUNPROC) (GLfloat factor);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORDSUNPROC) (GLdouble factor);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORUBSUNPROC) (GLubyte factor);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORUSSUNPROC) (GLushort factor);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORUISUNPROC) (GLuint factor);
GLEE_EXTERN PFNGLGLOBALALPHAFACTORBSUNPROC pglGlobalAlphaFactorbSUN;
GLEE_EXTERN PFNGLGLOBALALPHAFACTORSSUNPROC pglGlobalAlphaFactorsSUN;
GLEE_EXTERN PFNGLGLOBALALPHAFACTORISUNPROC pglGlobalAlphaFactoriSUN;
GLEE_EXTERN PFNGLGLOBALALPHAFACTORFSUNPROC pglGlobalAlphaFactorfSUN;
GLEE_EXTERN PFNGLGLOBALALPHAFACTORDSUNPROC pglGlobalAlphaFactordSUN;
GLEE_EXTERN PFNGLGLOBALALPHAFACTORUBSUNPROC pglGlobalAlphaFactorubSUN;
GLEE_EXTERN PFNGLGLOBALALPHAFACTORUSSUNPROC pglGlobalAlphaFactorusSUN;
GLEE_EXTERN PFNGLGLOBALALPHAFACTORUISUNPROC pglGlobalAlphaFactoruiSUN;
#define glGlobalAlphaFactorbSUN pglGlobalAlphaFactorbSUN
#define glGlobalAlphaFactorsSUN pglGlobalAlphaFactorsSUN
#define glGlobalAlphaFactoriSUN pglGlobalAlphaFactoriSUN
#define glGlobalAlphaFactorfSUN pglGlobalAlphaFactorfSUN
#define glGlobalAlphaFactordSUN pglGlobalAlphaFactordSUN
#define glGlobalAlphaFactorubSUN pglGlobalAlphaFactorubSUN
#define glGlobalAlphaFactorusSUN pglGlobalAlphaFactorusSUN
#define glGlobalAlphaFactoruiSUN pglGlobalAlphaFactoruiSUN
#endif 

/* GL_SUN_triangle_list */

#ifndef GL_SUN_triangle_list
#define GL_SUN_triangle_list 1
#define __GLEE_GL_SUN_triangle_list 1
/* Constants */
#define GL_RESTART_SUN                                     0x0001
#define GL_REPLACE_MIDDLE_SUN                              0x0002
#define GL_REPLACE_OLDEST_SUN                              0x0003
#define GL_TRIANGLE_LIST_SUN                               0x81D7
#define GL_REPLACEMENT_CODE_SUN                            0x81D8
#define GL_REPLACEMENT_CODE_ARRAY_SUN                      0x85C0
#define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN                 0x85C1
#define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN               0x85C2
#define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN              0x85C3
#define GL_R1UI_V3F_SUN                                    0x85C4
#define GL_R1UI_C4UB_V3F_SUN                               0x85C5
#define GL_R1UI_C3F_V3F_SUN                                0x85C6
#define GL_R1UI_N3F_V3F_SUN                                0x85C7
#define GL_R1UI_C4F_N3F_V3F_SUN                            0x85C8
#define GL_R1UI_T2F_V3F_SUN                                0x85C9
#define GL_R1UI_T2F_N3F_V3F_SUN                            0x85CA
#define GL_R1UI_T2F_C4F_N3F_V3F_SUN                        0x85CB
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUISUNPROC) (GLuint code);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUSSUNPROC) (GLushort code);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUBSUNPROC) (GLubyte code);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUIVSUNPROC) (const GLuint * code);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUSVSUNPROC) (const GLushort * code);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUBVSUNPROC) (const GLubyte * code);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEPOINTERSUNPROC) (GLenum type, GLsizei stride, const GLvoid* * pointer);
GLEE_EXTERN PFNGLREPLACEMENTCODEUISUNPROC pglReplacementCodeuiSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUSSUNPROC pglReplacementCodeusSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUBSUNPROC pglReplacementCodeubSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUIVSUNPROC pglReplacementCodeuivSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUSVSUNPROC pglReplacementCodeusvSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUBVSUNPROC pglReplacementCodeubvSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEPOINTERSUNPROC pglReplacementCodePointerSUN;
#define glReplacementCodeuiSUN pglReplacementCodeuiSUN
#define glReplacementCodeusSUN pglReplacementCodeusSUN
#define glReplacementCodeubSUN pglReplacementCodeubSUN
#define glReplacementCodeuivSUN pglReplacementCodeuivSUN
#define glReplacementCodeusvSUN pglReplacementCodeusvSUN
#define glReplacementCodeubvSUN pglReplacementCodeubvSUN
#define glReplacementCodePointerSUN pglReplacementCodePointerSUN
#endif 

/* GL_SUN_vertex */

#ifndef GL_SUN_vertex
#define GL_SUN_vertex 1
#define __GLEE_GL_SUN_vertex 1
/* Constants */
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX2FSUNPROC) (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX2FVSUNPROC) (const GLubyte * c, const GLfloat * v);
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX3FSUNPROC) (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX3FVSUNPROC) (const GLubyte * c, const GLfloat * v);
typedef void (APIENTRYP PFNGLCOLOR3FVERTEX3FSUNPROC) (GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLCOLOR3FVERTEX3FVSUNPROC) (const GLfloat * c, const GLfloat * v);
typedef void (APIENTRYP PFNGLNORMAL3FVERTEX3FSUNPROC) (GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLNORMAL3FVERTEX3FVSUNPROC) (const GLfloat * n, const GLfloat * v);
typedef void (APIENTRYP PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLfloat * c, const GLfloat * n, const GLfloat * v);
typedef void (APIENTRYP PFNGLTEXCOORD2FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLTEXCOORD2FVERTEX3FVSUNPROC) (const GLfloat * tc, const GLfloat * v);
typedef void (APIENTRYP PFNGLTEXCOORD4FVERTEX4FSUNPROC) (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLTEXCOORD4FVERTEX4FVSUNPROC) (const GLfloat * tc, const GLfloat * v);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC) (const GLfloat * tc, const GLubyte * c, const GLfloat * v);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC) (const GLfloat * tc, const GLfloat * c, const GLfloat * v);
typedef void (APIENTRYP PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) (const GLfloat * tc, const GLfloat * n, const GLfloat * v);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
typedef void (APIENTRYP PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC) (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC) (const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC) (GLuint rc, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC) (GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC) (const GLuint * rc, const GLubyte * c, const GLfloat * v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC) (GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * c, const GLfloat * v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC) (GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * n, const GLfloat * v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC) (GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * tc, const GLfloat * v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC) (GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * tc, const GLfloat * n, const GLfloat * v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLuint * rc, const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
GLEE_EXTERN PFNGLCOLOR4UBVERTEX2FSUNPROC pglColor4ubVertex2fSUN;
GLEE_EXTERN PFNGLCOLOR4UBVERTEX2FVSUNPROC pglColor4ubVertex2fvSUN;
GLEE_EXTERN PFNGLCOLOR4UBVERTEX3FSUNPROC pglColor4ubVertex3fSUN;
GLEE_EXTERN PFNGLCOLOR4UBVERTEX3FVSUNPROC pglColor4ubVertex3fvSUN;
GLEE_EXTERN PFNGLCOLOR3FVERTEX3FSUNPROC pglColor3fVertex3fSUN;
GLEE_EXTERN PFNGLCOLOR3FVERTEX3FVSUNPROC pglColor3fVertex3fvSUN;
GLEE_EXTERN PFNGLNORMAL3FVERTEX3FSUNPROC pglNormal3fVertex3fSUN;
GLEE_EXTERN PFNGLNORMAL3FVERTEX3FVSUNPROC pglNormal3fVertex3fvSUN;
GLEE_EXTERN PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC pglColor4fNormal3fVertex3fSUN;
GLEE_EXTERN PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC pglColor4fNormal3fVertex3fvSUN;
GLEE_EXTERN PFNGLTEXCOORD2FVERTEX3FSUNPROC pglTexCoord2fVertex3fSUN;
GLEE_EXTERN PFNGLTEXCOORD2FVERTEX3FVSUNPROC pglTexCoord2fVertex3fvSUN;
GLEE_EXTERN PFNGLTEXCOORD4FVERTEX4FSUNPROC pglTexCoord4fVertex4fSUN;
GLEE_EXTERN PFNGLTEXCOORD4FVERTEX4FVSUNPROC pglTexCoord4fVertex4fvSUN;
GLEE_EXTERN PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC pglTexCoord2fColor4ubVertex3fSUN;
GLEE_EXTERN PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC pglTexCoord2fColor4ubVertex3fvSUN;
GLEE_EXTERN PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC pglTexCoord2fColor3fVertex3fSUN;
GLEE_EXTERN PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC pglTexCoord2fColor3fVertex3fvSUN;
GLEE_EXTERN PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC pglTexCoord2fNormal3fVertex3fSUN;
GLEE_EXTERN PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC pglTexCoord2fNormal3fVertex3fvSUN;
GLEE_EXTERN PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC pglTexCoord2fColor4fNormal3fVertex3fSUN;
GLEE_EXTERN PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC pglTexCoord2fColor4fNormal3fVertex3fvSUN;
GLEE_EXTERN PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC pglTexCoord4fColor4fNormal3fVertex4fSUN;
GLEE_EXTERN PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC pglTexCoord4fColor4fNormal3fVertex4fvSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC pglReplacementCodeuiVertex3fSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC pglReplacementCodeuiVertex3fvSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC pglReplacementCodeuiColor4ubVertex3fSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC pglReplacementCodeuiColor4ubVertex3fvSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC pglReplacementCodeuiColor3fVertex3fSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC pglReplacementCodeuiColor3fVertex3fvSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC pglReplacementCodeuiNormal3fVertex3fSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC pglReplacementCodeuiNormal3fVertex3fvSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC pglReplacementCodeuiColor4fNormal3fVertex3fSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC pglReplacementCodeuiColor4fNormal3fVertex3fvSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC pglReplacementCodeuiTexCoord2fVertex3fSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC pglReplacementCodeuiTexCoord2fVertex3fvSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC pglReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC pglReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC pglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
GLEE_EXTERN PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC pglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
#define glColor4ubVertex2fSUN pglColor4ubVertex2fSUN
#define glColor4ubVertex2fvSUN pglColor4ubVertex2fvSUN
#define glColor4ubVertex3fSUN pglColor4ubVertex3fSUN
#define glColor4ubVertex3fvSUN pglColor4ubVertex3fvSUN
#define glColor3fVertex3fSUN pglColor3fVertex3fSUN
#define glColor3fVertex3fvSUN pglColor3fVertex3fvSUN
#define glNormal3fVertex3fSUN pglNormal3fVertex3fSUN
#define glNormal3fVertex3fvSUN pglNormal3fVertex3fvSUN
#define glColor4fNormal3fVertex3fSUN pglColor4fNormal3fVertex3fSUN
#define glColor4fNormal3fVertex3fvSUN pglColor4fNormal3fVertex3fvSUN
#define glTexCoord2fVertex3fSUN pglTexCoord2fVertex3fSUN
#define glTexCoord2fVertex3fvSUN pglTexCoord2fVertex3fvSUN
#define glTexCoord4fVertex4fSUN pglTexCoord4fVertex4fSUN
#define glTexCoord4fVertex4fvSUN pglTexCoord4fVertex4fvSUN
#define glTexCoord2fColor4ubVertex3fSUN pglTexCoord2fColor4ubVertex3fSUN
#define glTexCoord2fColor4ubVertex3fvSUN pglTexCoord2fColor4ubVertex3fvSUN
#define glTexCoord2fColor3fVertex3fSUN pglTexCoord2fColor3fVertex3fSUN
#define glTexCoord2fColor3fVertex3fvSUN pglTexCoord2fColor3fVertex3fvSUN
#define glTexCoord2fNormal3fVertex3fSUN pglTexCoord2fNormal3fVertex3fSUN
#define glTexCoord2fNormal3fVertex3fvSUN pglTexCoord2fNormal3fVertex3fvSUN
#define glTexCoord2fColor4fNormal3fVertex3fSUN pglTexCoord2fColor4fNormal3fVertex3fSUN
#define glTexCoord2fColor4fNormal3fVertex3fvSUN pglTexCoord2fColor4fNormal3fVertex3fvSUN
#define glTexCoord4fColor4fNormal3fVertex4fSUN pglTexCoord4fColor4fNormal3fVertex4fSUN
#define glTexCoord4fColor4fNormal3fVertex4fvSUN pglTexCoord4fColor4fNormal3fVertex4fvSUN
#define glReplacementCodeuiVertex3fSUN pglReplacementCodeuiVertex3fSUN
#define glReplacementCodeuiVertex3fvSUN pglReplacementCodeuiVertex3fvSUN
#define glReplacementCodeuiColor4ubVertex3fSUN pglReplacementCodeuiColor4ubVertex3fSUN
#define glReplacementCodeuiColor4ubVertex3fvSUN pglReplacementCodeuiColor4ubVertex3fvSUN
#define glReplacementCodeuiColor3fVertex3fSUN pglReplacementCodeuiColor3fVertex3fSUN
#define glReplacementCodeuiColor3fVertex3fvSUN pglReplacementCodeuiColor3fVertex3fvSUN
#define glReplacementCodeuiNormal3fVertex3fSUN pglReplacementCodeuiNormal3fVertex3fSUN
#define glReplacementCodeuiNormal3fVertex3fvSUN pglReplacementCodeuiNormal3fVertex3fvSUN
#define glReplacementCodeuiColor4fNormal3fVertex3fSUN pglReplacementCodeuiColor4fNormal3fVertex3fSUN
#define glReplacementCodeuiColor4fNormal3fVertex3fvSUN pglReplacementCodeuiColor4fNormal3fVertex3fvSUN
#define glReplacementCodeuiTexCoord2fVertex3fSUN pglReplacementCodeuiTexCoord2fVertex3fSUN
#define glReplacementCodeuiTexCoord2fVertex3fvSUN pglReplacementCodeuiTexCoord2fVertex3fvSUN
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN pglReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN pglReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN pglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN pglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
#endif 

/* GL_EXT_blend_func_separate */

#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate 1
#define __GLEE_GL_EXT_blend_func_separate 1
/* Constants */
#define GL_BLEND_DST_RGB_EXT                               0x80C8
#define GL_BLEND_SRC_RGB_EXT                               0x80C9
#define GL_BLEND_DST_ALPHA_EXT                             0x80CA
#define GL_BLEND_SRC_ALPHA_EXT                             0x80CB
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEEXTPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLEE_EXTERN PFNGLBLENDFUNCSEPARATEEXTPROC pglBlendFuncSeparateEXT;
#define glBlendFuncSeparateEXT pglBlendFuncSeparateEXT
#endif 

/* GL_INGR_color_clamp */

#ifndef GL_INGR_color_clamp
#define GL_INGR_color_clamp 1
#define __GLEE_GL_INGR_color_clamp 1
/* Constants */
#define GL_RED_MIN_CLAMP_INGR                              0x8560
#define GL_GREEN_MIN_CLAMP_INGR                            0x8561
#define GL_BLUE_MIN_CLAMP_INGR                             0x8562
#define GL_ALPHA_MIN_CLAMP_INGR                            0x8563
#define GL_RED_MAX_CLAMP_INGR                              0x8564
#define GL_GREEN_MAX_CLAMP_INGR                            0x8565
#define GL_BLUE_MAX_CLAMP_INGR                             0x8566
#define GL_ALPHA_MAX_CLAMP_INGR                            0x8567
#endif 

/* GL_INGR_interlace_read */

#ifndef GL_INGR_interlace_read
#define GL_INGR_interlace_read 1
#define __GLEE_GL_INGR_interlace_read 1
/* Constants */
#define GL_INTERLACE_READ_INGR                             0x8568
#endif 

/* GL_EXT_stencil_wrap */

#ifndef GL_EXT_stencil_wrap
#define GL_EXT_stencil_wrap 1
#define __GLEE_GL_EXT_stencil_wrap 1
/* Constants */
#define GL_INCR_WRAP_EXT                                   0x8507
#define GL_DECR_WRAP_EXT                                   0x8508
#endif 

/* GL_EXT_422_pixels */

#ifndef GL_EXT_422_pixels
#define GL_EXT_422_pixels 1
#define __GLEE_GL_EXT_422_pixels 1
/* Constants */
#define GL_422_EXT                                         0x80CC
#define GL_422_REV_EXT                                     0x80CD
#define GL_422_AVERAGE_EXT                                 0x80CE
#define GL_422_REV_AVERAGE_EXT                             0x80CF
#endif 

/* GL_NV_texgen_reflection */

#ifndef GL_NV_texgen_reflection
#define GL_NV_texgen_reflection 1
#define __GLEE_GL_NV_texgen_reflection 1
/* Constants */
#define GL_NORMAL_MAP_NV                                   0x8511
#define GL_REFLECTION_MAP_NV                               0x8512
#endif 

/* GL_EXT_texture_cube_map */

#ifndef GL_EXT_texture_cube_map
#define GL_EXT_texture_cube_map 1
#define __GLEE_GL_EXT_texture_cube_map 1
/* Constants */
#define GL_NORMAL_MAP_EXT                                  0x8511
#define GL_REFLECTION_MAP_EXT                              0x8512
#define GL_TEXTURE_CUBE_MAP_EXT                            0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT                    0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT                 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT                 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT                 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT                 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT                 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT                 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT                      0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT                   0x851C
#endif 

/* GL_SUN_convolution_border_modes */

#ifndef GL_SUN_convolution_border_modes
#define GL_SUN_convolution_border_modes 1
#define __GLEE_GL_SUN_convolution_border_modes 1
/* Constants */
#define GL_WRAP_BORDER_SUN                                 0x81D4
#endif 

/* GL_EXT_texture_env_add */

#ifndef GL_EXT_texture_env_add
#define GL_EXT_texture_env_add 1
#define __GLEE_GL_EXT_texture_env_add 1
/* Constants */
#endif 

/* GL_EXT_texture_lod_bias */

#ifndef GL_EXT_texture_lod_bias
#define GL_EXT_texture_lod_bias 1
#define __GLEE_GL_EXT_texture_lod_bias 1
/* Constants */
#define GL_MAX_TEXTURE_LOD_BIAS_EXT                        0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT                      0x8500
#define GL_TEXTURE_LOD_BIAS_EXT                            0x8501
#endif 

/* GL_EXT_texture_filter_anisotropic */

#ifndef GL_EXT_texture_filter_anisotropic
#define GL_EXT_texture_filter_anisotropic 1
#define __GLEE_GL_EXT_texture_filter_anisotropic 1
/* Constants */
#define GL_TEXTURE_MAX_ANISOTROPY_EXT                      0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT                  0x84FF
#endif 

/* GL_EXT_vertex_weighting */

#ifndef GL_EXT_vertex_weighting
#define GL_EXT_vertex_weighting 1
#define __GLEE_GL_EXT_vertex_weighting 1
/* Constants */
#define GL_MODELVIEW0_STACK_DEPTH_EXT                      GL_MODELVIEW_STACK_DEPTH
#define GL_MODELVIEW1_STACK_DEPTH_EXT                      0x8502
#define GL_MODELVIEW0_MATRIX_EXT                           GL_MODELVIEW_MATRIX
#define GL_MODELVIEW1_MATRIX_EXT                           0x8506
#define GL_VERTEX_WEIGHTING_EXT                            0x8509
#define GL_MODELVIEW0_EXT                                  GL_MODELVIEW
#define GL_MODELVIEW1_EXT                                  0x850A
#define GL_CURRENT_VERTEX_WEIGHT_EXT                       0x850B
#define GL_VERTEX_WEIGHT_ARRAY_EXT                         0x850C
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT                    0x850D
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT                    0x850E
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT                  0x850F
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT                 0x8510
typedef void (APIENTRYP PFNGLVERTEXWEIGHTFEXTPROC) (GLfloat weight);
typedef void (APIENTRYP PFNGLVERTEXWEIGHTFVEXTPROC) (const GLfloat * weight);
typedef void (APIENTRYP PFNGLVERTEXWEIGHTPOINTEREXTPROC) (GLsizei size, GLenum type, GLsizei stride, const GLvoid * pointer);
GLEE_EXTERN PFNGLVERTEXWEIGHTFEXTPROC pglVertexWeightfEXT;
GLEE_EXTERN PFNGLVERTEXWEIGHTFVEXTPROC pglVertexWeightfvEXT;
GLEE_EXTERN PFNGLVERTEXWEIGHTPOINTEREXTPROC pglVertexWeightPointerEXT;
#define glVertexWeightfEXT pglVertexWeightfEXT
#define glVertexWeightfvEXT pglVertexWeightfvEXT
#define glVertexWeightPointerEXT pglVertexWeightPointerEXT
#endif 

/* GL_NV_light_max_exponent */

#ifndef GL_NV_light_max_exponent
#define GL_NV_light_max_exponent 1
#define __GLEE_GL_NV_light_max_exponent 1
/* Constants */
#define GL_MAX_SHININESS_NV                                0x8504
#define GL_MAX_SPOT_EXPONENT_NV                            0x8505
#endif 

/* GL_NV_vertex_array_range */

#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range 1
#define __GLEE_GL_NV_vertex_array_range 1
/* Constants */
#define GL_VERTEX_ARRAY_RANGE_NV                           0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV                    0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV                     0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV               0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV                   0x8521
typedef void (APIENTRYP PFNGLFLUSHVERTEXARRAYRANGENVPROC) ();
typedef void (APIENTRYP PFNGLVERTEXARRAYRANGENVPROC) (GLsizei length, const GLvoid * pointer);
GLEE_EXTERN PFNGLFLUSHVERTEXARRAYRANGENVPROC pglFlushVertexArrayRangeNV;
GLEE_EXTERN PFNGLVERTEXARRAYRANGENVPROC pglVertexArrayRangeNV;
#define glFlushVertexArrayRangeNV pglFlushVertexArrayRangeNV
#define glVertexArrayRangeNV pglVertexArrayRangeNV
#endif 

/* GL_NV_register_combiners */

#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners 1
#define __GLEE_GL_NV_register_combiners 1
/* Constants */
#define GL_REGISTER_COMBINERS_NV                           0x8522
#define GL_VARIABLE_A_NV                                   0x8523
#define GL_VARIABLE_B_NV                                   0x8524
#define GL_VARIABLE_C_NV                                   0x8525
#define GL_VARIABLE_D_NV                                   0x8526
#define GL_VARIABLE_E_NV                                   0x8527
#define GL_VARIABLE_F_NV                                   0x8528
#define GL_VARIABLE_G_NV                                   0x8529
#define GL_CONSTANT_COLOR0_NV                              0x852A
#define GL_CONSTANT_COLOR1_NV                              0x852B
#define GL_PRIMARY_COLOR_NV                                0x852C
#define GL_SECONDARY_COLOR_NV                              0x852D
#define GL_SPARE0_NV                                       0x852E
#define GL_SPARE1_NV                                       0x852F
#define GL_DISCARD_NV                                      0x8530
#define GL_E_TIMES_F_NV                                    0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV                  0x8532
#define GL_UNSIGNED_IDENTITY_NV                            0x8536
#define GL_UNSIGNED_INVERT_NV                              0x8537
#define GL_EXPAND_NORMAL_NV                                0x8538
#define GL_EXPAND_NEGATE_NV                                0x8539
#define GL_HALF_BIAS_NORMAL_NV                             0x853A
#define GL_HALF_BIAS_NEGATE_NV                             0x853B
#define GL_SIGNED_IDENTITY_NV                              0x853C
#define GL_SIGNED_NEGATE_NV                                0x853D
#define GL_SCALE_BY_TWO_NV                                 0x853E
#define GL_SCALE_BY_FOUR_NV                                0x853F
#define GL_SCALE_BY_ONE_HALF_NV                            0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV                    0x8541
#define GL_COMBINER_INPUT_NV                               0x8542
#define GL_COMBINER_MAPPING_NV                             0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV                     0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV                      0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV                      0x8546
#define GL_COMBINER_MUX_SUM_NV                             0x8547
#define GL_COMBINER_SCALE_NV                               0x8548
#define GL_COMBINER_BIAS_NV                                0x8549
#define GL_COMBINER_AB_OUTPUT_NV                           0x854A
#define GL_COMBINER_CD_OUTPUT_NV                           0x854B
#define GL_COMBINER_SUM_OUTPUT_NV                          0x854C
#define GL_MAX_GENERAL_COMBINERS_NV                        0x854D
#define GL_NUM_GENERAL_COMBINERS_NV                        0x854E
#define GL_COLOR_SUM_CLAMP_NV                              0x854F
#define GL_COMBINER0_NV                                    0x8550
#define GL_COMBINER1_NV                                    0x8551
#define GL_COMBINER2_NV                                    0x8552
#define GL_COMBINER3_NV                                    0x8553
#define GL_COMBINER4_NV                                    0x8554
#define GL_COMBINER5_NV                                    0x8555
#define GL_COMBINER6_NV                                    0x8556
#define GL_COMBINER7_NV                                    0x8557
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERFVNVPROC) (GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERFNVPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERIVNVPROC) (GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERINVPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLCOMBINERINPUTNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (APIENTRYP PFNGLCOMBINEROUTPUTNVPROC) (GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
typedef void (APIENTRYP PFNGLFINALCOMBINERINPUTNVPROC) (GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (APIENTRYP PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC) (GLenum stage, GLenum portion, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC) (GLenum stage, GLenum portion, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC) (GLenum variable, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC) (GLenum variable, GLenum pname, GLint * params);
GLEE_EXTERN PFNGLCOMBINERPARAMETERFVNVPROC pglCombinerParameterfvNV;
GLEE_EXTERN PFNGLCOMBINERPARAMETERFNVPROC pglCombinerParameterfNV;
GLEE_EXTERN PFNGLCOMBINERPARAMETERIVNVPROC pglCombinerParameterivNV;
GLEE_EXTERN PFNGLCOMBINERPARAMETERINVPROC pglCombinerParameteriNV;
GLEE_EXTERN PFNGLCOMBINERINPUTNVPROC pglCombinerInputNV;
GLEE_EXTERN PFNGLCOMBINEROUTPUTNVPROC pglCombinerOutputNV;
GLEE_EXTERN PFNGLFINALCOMBINERINPUTNVPROC pglFinalCombinerInputNV;
GLEE_EXTERN PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC pglGetCombinerInputParameterfvNV;
GLEE_EXTERN PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC pglGetCombinerInputParameterivNV;
GLEE_EXTERN PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC pglGetCombinerOutputParameterfvNV;
GLEE_EXTERN PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC pglGetCombinerOutputParameterivNV;
GLEE_EXTERN PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC pglGetFinalCombinerInputParameterfvNV;
GLEE_EXTERN PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC pglGetFinalCombinerInputParameterivNV;
#define glCombinerParameterfvNV pglCombinerParameterfvNV
#define glCombinerParameterfNV pglCombinerParameterfNV
#define glCombinerParameterivNV pglCombinerParameterivNV
#define glCombinerParameteriNV pglCombinerParameteriNV
#define glCombinerInputNV pglCombinerInputNV
#define glCombinerOutputNV pglCombinerOutputNV
#define glFinalCombinerInputNV pglFinalCombinerInputNV
#define glGetCombinerInputParameterfvNV pglGetCombinerInputParameterfvNV
#define glGetCombinerInputParameterivNV pglGetCombinerInputParameterivNV
#define glGetCombinerOutputParameterfvNV pglGetCombinerOutputParameterfvNV
#define glGetCombinerOutputParameterivNV pglGetCombinerOutputParameterivNV
#define glGetFinalCombinerInputParameterfvNV pglGetFinalCombinerInputParameterfvNV
#define glGetFinalCombinerInputParameterivNV pglGetFinalCombinerInputParameterivNV
#endif 

/* GL_NV_fog_distance */

#ifndef GL_NV_fog_distance
#define GL_NV_fog_distance 1
#define __GLEE_GL_NV_fog_distance 1
/* Constants */
#define GL_FOG_DISTANCE_MODE_NV                            0x855A
#define GL_EYE_RADIAL_NV                                   0x855B
#define GL_EYE_PLANE_ABSOLUTE_NV                           0x855C
#endif 

/* GL_NV_texgen_emboss */

#ifndef GL_NV_texgen_emboss
#define GL_NV_texgen_emboss 1
#define __GLEE_GL_NV_texgen_emboss 1
/* Constants */
#define GL_EMBOSS_LIGHT_NV                                 0x855D
#define GL_EMBOSS_CONSTANT_NV                              0x855E
#define GL_EMBOSS_MAP_NV                                   0x855F
#endif 

/* GL_NV_blend_square */

#ifndef GL_NV_blend_square
#define GL_NV_blend_square 1
#define __GLEE_GL_NV_blend_square 1
/* Constants */
#endif 

/* GL_NV_texture_env_combine4 */

#ifndef GL_NV_texture_env_combine4
#define GL_NV_texture_env_combine4 1
#define __GLEE_GL_NV_texture_env_combine4 1
/* Constants */
#define GL_COMBINE4_NV                                     0x8503
#define GL_SOURCE3_RGB_NV                                  0x8583
#define GL_SOURCE3_ALPHA_NV                                0x858B
#define GL_OPERAND3_RGB_NV                                 0x8593
#define GL_OPERAND3_ALPHA_NV                               0x859B
#endif 

/* GL_MESA_resize_buffers */

#ifndef GL_MESA_resize_buffers
#define GL_MESA_resize_buffers 1
#define __GLEE_GL_MESA_resize_buffers 1
/* Constants */
typedef void (APIENTRYP PFNGLRESIZEBUFFERSMESAPROC) ();
GLEE_EXTERN PFNGLRESIZEBUFFERSMESAPROC pglResizeBuffersMESA;
#define glResizeBuffersMESA pglResizeBuffersMESA
#endif 

/* GL_MESA_window_pos */

#ifndef GL_MESA_window_pos
#define GL_MESA_window_pos 1
#define __GLEE_GL_MESA_window_pos 1
/* Constants */
typedef void (APIENTRYP PFNGLWINDOWPOS2DMESAPROC) (GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLWINDOWPOS2DVMESAPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLWINDOWPOS2FMESAPROC) (GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLWINDOWPOS2FVMESAPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLWINDOWPOS2IMESAPROC) (GLint x, GLint y);
typedef void (APIENTRYP PFNGLWINDOWPOS2IVMESAPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLWINDOWPOS2SMESAPROC) (GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLWINDOWPOS2SVMESAPROC) (const GLshort * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3DMESAPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLWINDOWPOS3DVMESAPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3FMESAPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLWINDOWPOS3FVMESAPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3IMESAPROC) (GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLWINDOWPOS3IVMESAPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLWINDOWPOS3SMESAPROC) (GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLWINDOWPOS3SVMESAPROC) (const GLshort * v);
typedef void (APIENTRYP PFNGLWINDOWPOS4DMESAPROC) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLWINDOWPOS4DVMESAPROC) (const GLdouble * v);
typedef void (APIENTRYP PFNGLWINDOWPOS4FMESAPROC) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLWINDOWPOS4FVMESAPROC) (const GLfloat * v);
typedef void (APIENTRYP PFNGLWINDOWPOS4IMESAPROC) (GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLWINDOWPOS4IVMESAPROC) (const GLint * v);
typedef void (APIENTRYP PFNGLWINDOWPOS4SMESAPROC) (GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLWINDOWPOS4SVMESAPROC) (const GLshort * v);
GLEE_EXTERN PFNGLWINDOWPOS2DMESAPROC pglWindowPos2dMESA;
GLEE_EXTERN PFNGLWINDOWPOS2DVMESAPROC pglWindowPos2dvMESA;
GLEE_EXTERN PFNGLWINDOWPOS2FMESAPROC pglWindowPos2fMESA;
GLEE_EXTERN PFNGLWINDOWPOS2FVMESAPROC pglWindowPos2fvMESA;
GLEE_EXTERN PFNGLWINDOWPOS2IMESAPROC pglWindowPos2iMESA;
GLEE_EXTERN PFNGLWINDOWPOS2IVMESAPROC pglWindowPos2ivMESA;
GLEE_EXTERN PFNGLWINDOWPOS2SMESAPROC pglWindowPos2sMESA;
GLEE_EXTERN PFNGLWINDOWPOS2SVMESAPROC pglWindowPos2svMESA;
GLEE_EXTERN PFNGLWINDOWPOS3DMESAPROC pglWindowPos3dMESA;
GLEE_EXTERN PFNGLWINDOWPOS3DVMESAPROC pglWindowPos3dvMESA;
GLEE_EXTERN PFNGLWINDOWPOS3FMESAPROC pglWindowPos3fMESA;
GLEE_EXTERN PFNGLWINDOWPOS3FVMESAPROC pglWindowPos3fvMESA;
GLEE_EXTERN PFNGLWINDOWPOS3IMESAPROC pglWindowPos3iMESA;
GLEE_EXTERN PFNGLWINDOWPOS3IVMESAPROC pglWindowPos3ivMESA;
GLEE_EXTERN PFNGLWINDOWPOS3SMESAPROC pglWindowPos3sMESA;
GLEE_EXTERN PFNGLWINDOWPOS3SVMESAPROC pglWindowPos3svMESA;
GLEE_EXTERN PFNGLWINDOWPOS4DMESAPROC pglWindowPos4dMESA;
GLEE_EXTERN PFNGLWINDOWPOS4DVMESAPROC pglWindowPos4dvMESA;
GLEE_EXTERN PFNGLWINDOWPOS4FMESAPROC pglWindowPos4fMESA;
GLEE_EXTERN PFNGLWINDOWPOS4FVMESAPROC pglWindowPos4fvMESA;
GLEE_EXTERN PFNGLWINDOWPOS4IMESAPROC pglWindowPos4iMESA;
GLEE_EXTERN PFNGLWINDOWPOS4IVMESAPROC pglWindowPos4ivMESA;
GLEE_EXTERN PFNGLWINDOWPOS4SMESAPROC pglWindowPos4sMESA;
GLEE_EXTERN PFNGLWINDOWPOS4SVMESAPROC pglWindowPos4svMESA;
#define glWindowPos2dMESA pglWindowPos2dMESA
#define glWindowPos2dvMESA pglWindowPos2dvMESA
#define glWindowPos2fMESA pglWindowPos2fMESA
#define glWindowPos2fvMESA pglWindowPos2fvMESA
#define glWindowPos2iMESA pglWindowPos2iMESA
#define glWindowPos2ivMESA pglWindowPos2ivMESA
#define glWindowPos2sMESA pglWindowPos2sMESA
#define glWindowPos2svMESA pglWindowPos2svMESA
#define glWindowPos3dMESA pglWindowPos3dMESA
#define glWindowPos3dvMESA pglWindowPos3dvMESA
#define glWindowPos3fMESA pglWindowPos3fMESA
#define glWindowPos3fvMESA pglWindowPos3fvMESA
#define glWindowPos3iMESA pglWindowPos3iMESA
#define glWindowPos3ivMESA pglWindowPos3ivMESA
#define glWindowPos3sMESA pglWindowPos3sMESA
#define glWindowPos3svMESA pglWindowPos3svMESA
#define glWindowPos4dMESA pglWindowPos4dMESA
#define glWindowPos4dvMESA pglWindowPos4dvMESA
#define glWindowPos4fMESA pglWindowPos4fMESA
#define glWindowPos4fvMESA pglWindowPos4fvMESA
#define glWindowPos4iMESA pglWindowPos4iMESA
#define glWindowPos4ivMESA pglWindowPos4ivMESA
#define glWindowPos4sMESA pglWindowPos4sMESA
#define glWindowPos4svMESA pglWindowPos4svMESA
#endif 

/* GL_EXT_texture_compression_s3tc */

#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc 1
#define __GLEE_GL_EXT_texture_compression_s3tc 1
/* Constants */
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT                    0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT                   0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT                   0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT                   0x83F3
#endif 

/* GL_IBM_cull_vertex */

#ifndef GL_IBM_cull_vertex
#define GL_IBM_cull_vertex 1
#define __GLEE_GL_IBM_cull_vertex 1
/* Constants */
#define GL_CULL_VERTEX_IBM                                 103050
#endif 

/* GL_IBM_multimode_draw_arrays */

#ifndef GL_IBM_multimode_draw_arrays
#define GL_IBM_multimode_draw_arrays 1
#define __GLEE_GL_IBM_multimode_draw_arrays 1
/* Constants */
typedef void (APIENTRYP PFNGLMULTIMODEDRAWARRAYSIBMPROC) (const GLenum * mode, const GLint * first, const GLsizei * count, GLsizei primcount, GLint modestride);
typedef void (APIENTRYP PFNGLMULTIMODEDRAWELEMENTSIBMPROC) (const GLenum * mode, const GLsizei * count, GLenum type, const GLvoid* const * indices, GLsizei primcount, GLint modestride);
GLEE_EXTERN PFNGLMULTIMODEDRAWARRAYSIBMPROC pglMultiModeDrawArraysIBM;
GLEE_EXTERN PFNGLMULTIMODEDRAWELEMENTSIBMPROC pglMultiModeDrawElementsIBM;
#define glMultiModeDrawArraysIBM pglMultiModeDrawArraysIBM
#define glMultiModeDrawElementsIBM pglMultiModeDrawElementsIBM
#endif 

/* GL_IBM_vertex_array_lists */

#ifndef GL_IBM_vertex_array_lists
#define GL_IBM_vertex_array_lists 1
#define __GLEE_GL_IBM_vertex_array_lists 1
/* Constants */
#define GL_VERTEX_ARRAY_LIST_IBM                           103070
#define GL_NORMAL_ARRAY_LIST_IBM                           103071
#define GL_COLOR_ARRAY_LIST_IBM                            103072
#define GL_INDEX_ARRAY_LIST_IBM                            103073
#define GL_TEXTURE_COORD_ARRAY_LIST_IBM                    103074
#define GL_EDGE_FLAG_ARRAY_LIST_IBM                        103075
#define GL_FOG_COORDINATE_ARRAY_LIST_IBM                   103076
#define GL_SECONDARY_COLOR_ARRAY_LIST_IBM                  103077
#define GL_VERTEX_ARRAY_LIST_STRIDE_IBM                    103080
#define GL_NORMAL_ARRAY_LIST_STRIDE_IBM                    103081
#define GL_COLOR_ARRAY_LIST_STRIDE_IBM                     103082
#define GL_INDEX_ARRAY_LIST_STRIDE_IBM                     103083
#define GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM             103084
#define GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM                 103085
#define GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM            103086
#define GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM           103087
typedef void (APIENTRYP PFNGLCOLORPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTERLISTIBMPROC) (GLint stride, const GLboolean* * pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLFOGCOORDPOINTERLISTIBMPROC) (GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLINDEXPOINTERLISTIBMPROC) (GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLNORMALPOINTERLISTIBMPROC) (GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLVERTEXPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid* * pointer, GLint ptrstride);
GLEE_EXTERN PFNGLCOLORPOINTERLISTIBMPROC pglColorPointerListIBM;
GLEE_EXTERN PFNGLSECONDARYCOLORPOINTERLISTIBMPROC pglSecondaryColorPointerListIBM;
GLEE_EXTERN PFNGLEDGEFLAGPOINTERLISTIBMPROC pglEdgeFlagPointerListIBM;
GLEE_EXTERN PFNGLFOGCOORDPOINTERLISTIBMPROC pglFogCoordPointerListIBM;
GLEE_EXTERN PFNGLINDEXPOINTERLISTIBMPROC pglIndexPointerListIBM;
GLEE_EXTERN PFNGLNORMALPOINTERLISTIBMPROC pglNormalPointerListIBM;
GLEE_EXTERN PFNGLTEXCOORDPOINTERLISTIBMPROC pglTexCoordPointerListIBM;
GLEE_EXTERN PFNGLVERTEXPOINTERLISTIBMPROC pglVertexPointerListIBM;
#define glColorPointerListIBM pglColorPointerListIBM
#define glSecondaryColorPointerListIBM pglSecondaryColorPointerListIBM
#define glEdgeFlagPointerListIBM pglEdgeFlagPointerListIBM
#define glFogCoordPointerListIBM pglFogCoordPointerListIBM
#define glIndexPointerListIBM pglIndexPointerListIBM
#define glNormalPointerListIBM pglNormalPointerListIBM
#define glTexCoordPointerListIBM pglTexCoordPointerListIBM
#define glVertexPointerListIBM pglVertexPointerListIBM
#endif 

/* GL_SGIX_subsample */

#ifndef GL_SGIX_subsample
#define GL_SGIX_subsample 1
#define __GLEE_GL_SGIX_subsample 1
/* Constants */
#define GL_PACK_SUBSAMPLE_RATE_SGIX                        0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX                      0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX                       0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX                       0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX                       0x85A4
#endif 

/* GL_SGIX_ycrcb_subsample */

#ifndef GL_SGIX_ycrcb_subsample
#define GL_SGIX_ycrcb_subsample 1
#define __GLEE_GL_SGIX_ycrcb_subsample 1
/* Constants */
#endif 

/* GL_SGIX_ycrcba */

#ifndef GL_SGIX_ycrcba
#define GL_SGIX_ycrcba 1
#define __GLEE_GL_SGIX_ycrcba 1
/* Constants */
#define GL_YCRCB_SGIX                                      0x8318
#define GL_YCRCBA_SGIX                                     0x8319
#endif 

/* GL_SGI_depth_pass_instrument */

#ifndef GL_SGI_depth_pass_instrument
#define GL_SGI_depth_pass_instrument 1
#define __GLEE_GL_SGI_depth_pass_instrument 1
/* Constants */
#define GL_DEPTH_PASS_INSTRUMENT_SGIX                      0x8310
#define GL_DEPTH_PASS_INSTRUMENT_COUNTERS_SGIX             0x8311
#define GL_DEPTH_PASS_INSTRUMENT_MAX_SGIX                  0x8312
#endif 

/* GL_3DFX_texture_compression_FXT1 */

#ifndef GL_3DFX_texture_compression_FXT1
#define GL_3DFX_texture_compression_FXT1 1
#define __GLEE_GL_3DFX_texture_compression_FXT1 1
/* Constants */
#define GL_COMPRESSED_RGB_FXT1_3DFX                        0x86B0
#define GL_COMPRESSED_RGBA_FXT1_3DFX                       0x86B1
#endif 

/* GL_3DFX_multisample */

#ifndef GL_3DFX_multisample
#define GL_3DFX_multisample 1
#define __GLEE_GL_3DFX_multisample 1
/* Constants */
#define GL_MULTISAMPLE_3DFX                                0x86B2
#define GL_SAMPLE_BUFFERS_3DFX                             0x86B3
#define GL_SAMPLES_3DFX                                    0x86B4
#define GL_MULTISAMPLE_BIT_3DFX                            0x20000000
#endif 

/* GL_3DFX_tbuffer */

#ifndef GL_3DFX_tbuffer
#define GL_3DFX_tbuffer 1
#define __GLEE_GL_3DFX_tbuffer 1
/* Constants */
typedef void (APIENTRYP PFNGLTBUFFERMASK3DFXPROC) (GLuint mask);
GLEE_EXTERN PFNGLTBUFFERMASK3DFXPROC pglTbufferMask3DFX;
#define glTbufferMask3DFX pglTbufferMask3DFX
#endif 

/* GL_EXT_multisample */

#ifndef GL_EXT_multisample
#define GL_EXT_multisample 1
#define __GLEE_GL_EXT_multisample 1
/* Constants */
#define GL_MULTISAMPLE_EXT                                 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_EXT                        0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_EXT                         0x809F
#define GL_SAMPLE_MASK_EXT                                 0x80A0
#define GL_1PASS_EXT                                       0x80A1
#define GL_2PASS_0_EXT                                     0x80A2
#define GL_2PASS_1_EXT                                     0x80A3
#define GL_4PASS_0_EXT                                     0x80A4
#define GL_4PASS_1_EXT                                     0x80A5
#define GL_4PASS_2_EXT                                     0x80A6
#define GL_4PASS_3_EXT                                     0x80A7
#define GL_SAMPLE_BUFFERS_EXT                              0x80A8
#define GL_SAMPLES_EXT                                     0x80A9
#define GL_SAMPLE_MASK_VALUE_EXT                           0x80AA
#define GL_SAMPLE_MASK_INVERT_EXT                          0x80AB
#define GL_SAMPLE_PATTERN_EXT                              0x80AC
#define GL_MULTISAMPLE_BIT_EXT                             0x20000000
typedef void (APIENTRYP PFNGLSAMPLEMASKEXTPROC) (GLclampf value, GLboolean invert);
typedef void (APIENTRYP PFNGLSAMPLEPATTERNEXTPROC) (GLenum pattern);
GLEE_EXTERN PFNGLSAMPLEMASKEXTPROC pglSampleMaskEXT;
GLEE_EXTERN PFNGLSAMPLEPATTERNEXTPROC pglSamplePatternEXT;
#define glSampleMaskEXT pglSampleMaskEXT
#define glSamplePatternEXT pglSamplePatternEXT
#endif 

/* GL_SGIX_vertex_preclip */

#ifndef GL_SGIX_vertex_preclip
#define GL_SGIX_vertex_preclip 1
#define __GLEE_GL_SGIX_vertex_preclip 1
/* Constants */
#define GL_VERTEX_PRECLIP_SGIX                             0x83EE
#define GL_VERTEX_PRECLIP_HINT_SGIX                        0x83EF
#endif 

/* GL_SGIX_convolution_accuracy */

#ifndef GL_SGIX_convolution_accuracy
#define GL_SGIX_convolution_accuracy 1
#define __GLEE_GL_SGIX_convolution_accuracy 1
/* Constants */
#define GL_CONVOLUTION_HINT_SGIX                           0x8316
#endif 

/* GL_SGIX_resample */

#ifndef GL_SGIX_resample
#define GL_SGIX_resample 1
#define __GLEE_GL_SGIX_resample 1
/* Constants */
#define GL_PACK_RESAMPLE_SGIX                              0x842C
#define GL_UNPACK_RESAMPLE_SGIX                            0x842D
#define GL_RESAMPLE_REPLICATE_SGIX                         0x842E
#define GL_RESAMPLE_ZERO_FILL_SGIX                         0x842F
#define GL_RESAMPLE_DECIMATE_SGIX                          0x8430
#endif 

/* GL_SGIS_point_line_texgen */

#ifndef GL_SGIS_point_line_texgen
#define GL_SGIS_point_line_texgen 1
#define __GLEE_GL_SGIS_point_line_texgen 1
/* Constants */
#define GL_EYE_DISTANCE_TO_POINT_SGIS                      0x81F0
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS                   0x81F1
#define GL_EYE_DISTANCE_TO_LINE_SGIS                       0x81F2
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS                    0x81F3
#define GL_EYE_POINT_SGIS                                  0x81F4
#define GL_OBJECT_POINT_SGIS                               0x81F5
#define GL_EYE_LINE_SGIS                                   0x81F6
#define GL_OBJECT_LINE_SGIS                                0x81F7
#endif 

/* GL_SGIS_texture_color_mask */

#ifndef GL_SGIS_texture_color_mask
#define GL_SGIS_texture_color_mask 1
#define __GLEE_GL_SGIS_texture_color_mask 1
/* Constants */
#define GL_TEXTURE_COLOR_WRITEMASK_SGIS                    0x81EF
typedef void (APIENTRYP PFNGLTEXTURECOLORMASKSGISPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLEE_EXTERN PFNGLTEXTURECOLORMASKSGISPROC pglTextureColorMaskSGIS;
#define glTextureColorMaskSGIS pglTextureColorMaskSGIS
#endif 

/* GL_EXT_texture_env_dot3 */

#ifndef GL_EXT_texture_env_dot3
#define GL_EXT_texture_env_dot3 1
#define __GLEE_GL_EXT_texture_env_dot3 1
/* Constants */
#define GL_DOT3_RGB_EXT                                    0x8740
#define GL_DOT3_RGBA_EXT                                   0x8741
#endif 

/* GL_ATI_texture_mirror_once */

#ifndef GL_ATI_texture_mirror_once
#define GL_ATI_texture_mirror_once 1
#define __GLEE_GL_ATI_texture_mirror_once 1
/* Constants */
#define GL_MIRROR_CLAMP_ATI                                0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI                        0x8743
#endif 

/* GL_NV_fence */

#ifndef GL_NV_fence
#define GL_NV_fence 1
#define __GLEE_GL_NV_fence 1
/* Constants */
#define GL_ALL_COMPLETED_NV                                0x84F2
#define GL_FENCE_STATUS_NV                                 0x84F3
#define GL_FENCE_CONDITION_NV                              0x84F4
typedef void (APIENTRYP PFNGLDELETEFENCESNVPROC) (GLsizei n, const GLuint * fences);
typedef void (APIENTRYP PFNGLGENFENCESNVPROC) (GLsizei n, GLuint * fences);
typedef GLboolean (APIENTRYP PFNGLISFENCENVPROC) (GLuint fence);
typedef GLboolean (APIENTRYP PFNGLTESTFENCENVPROC) (GLuint fence);
typedef void (APIENTRYP PFNGLGETFENCEIVNVPROC) (GLuint fence, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLFINISHFENCENVPROC) (GLuint fence);
typedef void (APIENTRYP PFNGLSETFENCENVPROC) (GLuint fence, GLenum condition);
GLEE_EXTERN PFNGLDELETEFENCESNVPROC pglDeleteFencesNV;
GLEE_EXTERN PFNGLGENFENCESNVPROC pglGenFencesNV;
GLEE_EXTERN PFNGLISFENCENVPROC pglIsFenceNV;
GLEE_EXTERN PFNGLTESTFENCENVPROC pglTestFenceNV;
GLEE_EXTERN PFNGLGETFENCEIVNVPROC pglGetFenceivNV;
GLEE_EXTERN PFNGLFINISHFENCENVPROC pglFinishFenceNV;
GLEE_EXTERN PFNGLSETFENCENVPROC pglSetFenceNV;
#define glDeleteFencesNV pglDeleteFencesNV
#define glGenFencesNV pglGenFencesNV
#define glIsFenceNV pglIsFenceNV
#define glTestFenceNV pglTestFenceNV
#define glGetFenceivNV pglGetFenceivNV
#define glFinishFenceNV pglFinishFenceNV
#define glSetFenceNV pglSetFenceNV
#endif 

/* GL_IBM_texture_mirrored_repeat */

#ifndef GL_IBM_texture_mirrored_repeat
#define GL_IBM_texture_mirrored_repeat 1
#define __GLEE_GL_IBM_texture_mirrored_repeat 1
/* Constants */
#define GL_MIRRORED_REPEAT_IBM                             0x8370
#endif 

/* GL_NV_evaluators */

#ifndef GL_NV_evaluators
#define GL_NV_evaluators 1
#define __GLEE_GL_NV_evaluators 1
/* Constants */
#define GL_EVAL_2D_NV                                      0x86C0
#define GL_EVAL_TRIANGULAR_2D_NV                           0x86C1
#define GL_MAP_TESSELLATION_NV                             0x86C2
#define GL_MAP_ATTRIB_U_ORDER_NV                           0x86C3
#define GL_MAP_ATTRIB_V_ORDER_NV                           0x86C4
#define GL_EVAL_FRACTIONAL_TESSELLATION_NV                 0x86C5
#define GL_EVAL_VERTEX_ATTRIB0_NV                          0x86C6
#define GL_EVAL_VERTEX_ATTRIB1_NV                          0x86C7
#define GL_EVAL_VERTEX_ATTRIB2_NV                          0x86C8
#define GL_EVAL_VERTEX_ATTRIB3_NV                          0x86C9
#define GL_EVAL_VERTEX_ATTRIB4_NV                          0x86CA
#define GL_EVAL_VERTEX_ATTRIB5_NV                          0x86CB
#define GL_EVAL_VERTEX_ATTRIB6_NV                          0x86CC
#define GL_EVAL_VERTEX_ATTRIB7_NV                          0x86CD
#define GL_EVAL_VERTEX_ATTRIB8_NV                          0x86CE
#define GL_EVAL_VERTEX_ATTRIB9_NV                          0x86CF
#define GL_EVAL_VERTEX_ATTRIB10_NV                         0x86D0
#define GL_EVAL_VERTEX_ATTRIB11_NV                         0x86D1
#define GL_EVAL_VERTEX_ATTRIB12_NV                         0x86D2
#define GL_EVAL_VERTEX_ATTRIB13_NV                         0x86D3
#define GL_EVAL_VERTEX_ATTRIB14_NV                         0x86D4
#define GL_EVAL_VERTEX_ATTRIB15_NV                         0x86D5
#define GL_MAX_MAP_TESSELLATION_NV                         0x86D6
#define GL_MAX_RATIONAL_EVAL_ORDER_NV                      0x86D7
typedef void (APIENTRYP PFNGLMAPCONTROLPOINTSNVPROC) (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const GLvoid * points);
typedef void (APIENTRYP PFNGLMAPPARAMETERIVNVPROC) (GLenum target, GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLMAPPARAMETERFVNVPROC) (GLenum target, GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLGETMAPCONTROLPOINTSNVPROC) (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid * points);
typedef void (APIENTRYP PFNGLGETMAPPARAMETERIVNVPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETMAPPARAMETERFVNVPROC) (GLenum target, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETMAPATTRIBPARAMETERIVNVPROC) (GLenum target, GLuint index, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETMAPATTRIBPARAMETERFVNVPROC) (GLenum target, GLuint index, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLEVALMAPSNVPROC) (GLenum target, GLenum mode);
GLEE_EXTERN PFNGLMAPCONTROLPOINTSNVPROC pglMapControlPointsNV;
GLEE_EXTERN PFNGLMAPPARAMETERIVNVPROC pglMapParameterivNV;
GLEE_EXTERN PFNGLMAPPARAMETERFVNVPROC pglMapParameterfvNV;
GLEE_EXTERN PFNGLGETMAPCONTROLPOINTSNVPROC pglGetMapControlPointsNV;
GLEE_EXTERN PFNGLGETMAPPARAMETERIVNVPROC pglGetMapParameterivNV;
GLEE_EXTERN PFNGLGETMAPPARAMETERFVNVPROC pglGetMapParameterfvNV;
GLEE_EXTERN PFNGLGETMAPATTRIBPARAMETERIVNVPROC pglGetMapAttribParameterivNV;
GLEE_EXTERN PFNGLGETMAPATTRIBPARAMETERFVNVPROC pglGetMapAttribParameterfvNV;
GLEE_EXTERN PFNGLEVALMAPSNVPROC pglEvalMapsNV;
#define glMapControlPointsNV pglMapControlPointsNV
#define glMapParameterivNV pglMapParameterivNV
#define glMapParameterfvNV pglMapParameterfvNV
#define glGetMapControlPointsNV pglGetMapControlPointsNV
#define glGetMapParameterivNV pglGetMapParameterivNV
#define glGetMapParameterfvNV pglGetMapParameterfvNV
#define glGetMapAttribParameterivNV pglGetMapAttribParameterivNV
#define glGetMapAttribParameterfvNV pglGetMapAttribParameterfvNV
#define glEvalMapsNV pglEvalMapsNV
#endif 

/* GL_NV_packed_depth_stencil */

#ifndef GL_NV_packed_depth_stencil
#define GL_NV_packed_depth_stencil 1
#define __GLEE_GL_NV_packed_depth_stencil 1
/* Constants */
#define GL_DEPTH_STENCIL_NV                                0x84F9
#define GL_UNSIGNED_INT_24_8_NV                            0x84FA
#endif 

/* GL_NV_register_combiners2 */

#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2 1
#define __GLEE_GL_NV_register_combiners2 1
/* Constants */
#define GL_PER_STAGE_CONSTANTS_NV                          0x8535
typedef void (APIENTRYP PFNGLCOMBINERSTAGEPARAMETERFVNVPROC) (GLenum stage, GLenum pname, const GLfloat * params);
typedef void (APIENTRYP PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC) (GLenum stage, GLenum pname, GLfloat * params);
GLEE_EXTERN PFNGLCOMBINERSTAGEPARAMETERFVNVPROC pglCombinerStageParameterfvNV;
GLEE_EXTERN PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC pglGetCombinerStageParameterfvNV;
#define glCombinerStageParameterfvNV pglCombinerStageParameterfvNV
#define glGetCombinerStageParameterfvNV pglGetCombinerStageParameterfvNV
#endif 

/* GL_NV_texture_compression_vtc */

#ifndef GL_NV_texture_compression_vtc
#define GL_NV_texture_compression_vtc 1
#define __GLEE_GL_NV_texture_compression_vtc 1
/* Constants */
#endif 

/* GL_NV_texture_rectangle */

#ifndef GL_NV_texture_rectangle
#define GL_NV_texture_rectangle 1
#define __GLEE_GL_NV_texture_rectangle 1
/* Constants */
#define GL_TEXTURE_RECTANGLE_NV                            0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV                    0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_NV                      0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV                   0x84F8
#endif 

/* GL_NV_texture_shader */

#ifndef GL_NV_texture_shader
#define GL_NV_texture_shader 1
#define __GLEE_GL_NV_texture_shader 1
/* Constants */
#define GL_OFFSET_TEXTURE_RECTANGLE_NV                     0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV               0x864D
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV                0x864E
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV            0x86D9
#define GL_UNSIGNED_INT_S8_S8_8_8_NV                       0x86DA
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV                   0x86DB
#define GL_DSDT_MAG_INTENSITY_NV                           0x86DC
#define GL_SHADER_CONSISTENT_NV                            0x86DD
#define GL_TEXTURE_SHADER_NV                               0x86DE
#define GL_SHADER_OPERATION_NV                             0x86DF
#define GL_CULL_MODES_NV                                   0x86E0
#define GL_OFFSET_TEXTURE_MATRIX_NV                        0x86E1
#define GL_OFFSET_TEXTURE_SCALE_NV                         0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV                          0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV                     GL_OFFSET_TEXTURE_MATRIX_NV
#define GL_OFFSET_TEXTURE_2D_SCALE_NV                      GL_OFFSET_TEXTURE_SCALE_NV
#define GL_OFFSET_TEXTURE_2D_BIAS_NV                       GL_OFFSET_TEXTURE_BIAS_NV
#define GL_PREVIOUS_TEXTURE_INPUT_NV                       0x86E4
#define GL_CONST_EYE_NV                                    0x86E5
#define GL_PASS_THROUGH_NV                                 0x86E6
#define GL_CULL_FRAGMENT_NV                                0x86E7
#define GL_OFFSET_TEXTURE_2D_NV                            0x86E8
#define GL_DEPENDENT_AR_TEXTURE_2D_NV                      0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV                      0x86EA
#define GL_DOT_PRODUCT_NV                                  0x86EC
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV                    0x86ED
#define GL_DOT_PRODUCT_TEXTURE_2D_NV                       0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV                 0x86F0
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV                 0x86F1
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV                 0x86F2
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV       0x86F3
#define GL_HILO_NV                                         0x86F4
#define GL_DSDT_NV                                         0x86F5
#define GL_DSDT_MAG_NV                                     0x86F6
#define GL_DSDT_MAG_VIB_NV                                 0x86F7
#define GL_HILO16_NV                                       0x86F8
#define GL_SIGNED_HILO_NV                                  0x86F9
#define GL_SIGNED_HILO16_NV                                0x86FA
#define GL_SIGNED_RGBA_NV                                  0x86FB
#define GL_SIGNED_RGBA8_NV                                 0x86FC
#define GL_SIGNED_RGB_NV                                   0x86FE
#define GL_SIGNED_RGB8_NV                                  0x86FF
#define GL_SIGNED_LUMINANCE_NV                             0x8701
#define GL_SIGNED_LUMINANCE8_NV                            0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV                       0x8703
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV                     0x8704
#define GL_SIGNED_ALPHA_NV                                 0x8705
#define GL_SIGNED_ALPHA8_NV                                0x8706
#define GL_SIGNED_INTENSITY_NV                             0x8707
#define GL_SIGNED_INTENSITY8_NV                            0x8708
#define GL_DSDT8_NV                                        0x8709
#define GL_DSDT8_MAG8_NV                                   0x870A
#define GL_DSDT8_MAG8_INTENSITY8_NV                        0x870B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV                    0x870C
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV                  0x870D
#define GL_HI_SCALE_NV                                     0x870E
#define GL_LO_SCALE_NV                                     0x870F
#define GL_DS_SCALE_NV                                     0x8710
#define GL_DT_SCALE_NV                                     0x8711
#define GL_MAGNITUDE_SCALE_NV                              0x8712
#define GL_VIBRANCE_SCALE_NV                               0x8713
#define GL_HI_BIAS_NV                                      0x8714
#define GL_LO_BIAS_NV                                      0x8715
#define GL_DS_BIAS_NV                                      0x8716
#define GL_DT_BIAS_NV                                      0x8717
#define GL_MAGNITUDE_BIAS_NV                               0x8718
#define GL_VIBRANCE_BIAS_NV                                0x8719
#define GL_TEXTURE_BORDER_VALUES_NV                        0x871A
#define GL_TEXTURE_HI_SIZE_NV                              0x871B
#define GL_TEXTURE_LO_SIZE_NV                              0x871C
#define GL_TEXTURE_DS_SIZE_NV                              0x871D
#define GL_TEXTURE_DT_SIZE_NV                              0x871E
#define GL_TEXTURE_MAG_SIZE_NV                             0x871F
#endif 

/* GL_NV_texture_shader2 */

#ifndef GL_NV_texture_shader2
#define GL_NV_texture_shader2 1
#define __GLEE_GL_NV_texture_shader2 1
/* Constants */
#define GL_DOT_PRODUCT_TEXTURE_3D_NV                       0x86EF
#endif 

/* GL_NV_vertex_array_range2 */

#ifndef GL_NV_vertex_array_range2
#define GL_NV_vertex_array_range2 1
#define __GLEE_GL_NV_vertex_array_range2 1
/* Constants */
#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV             0x8533
#endif 

/* GL_NV_vertex_program */

#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program 1
#define __GLEE_GL_NV_vertex_program 1
/* Constants */
#define GL_VERTEX_PROGRAM_NV                               0x8620
#define GL_VERTEX_STATE_PROGRAM_NV                         0x8621
#define GL_ATTRIB_ARRAY_SIZE_NV                            0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV                          0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV                            0x8625
#define GL_CURRENT_ATTRIB_NV                               0x8626
#define GL_PROGRAM_LENGTH_NV                               0x8627
#define GL_PROGRAM_STRING_NV                               0x8628
#define GL_MODELVIEW_PROJECTION_NV                         0x8629
#define GL_IDENTITY_NV                                     0x862A
#define GL_INVERSE_NV                                      0x862B
#define GL_TRANSPOSE_NV                                    0x862C
#define GL_INVERSE_TRANSPOSE_NV                            0x862D
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV                 0x862E
#define GL_MAX_TRACK_MATRICES_NV                           0x862F
#define GL_MATRIX0_NV                                      0x8630
#define GL_MATRIX1_NV                                      0x8631
#define GL_MATRIX2_NV                                      0x8632
#define GL_MATRIX3_NV                                      0x8633
#define GL_MATRIX4_NV                                      0x8634
#define GL_MATRIX5_NV                                      0x8635
#define GL_MATRIX6_NV                                      0x8636
#define GL_MATRIX7_NV                                      0x8637
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV                   0x8640
#define GL_CURRENT_MATRIX_NV                               0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV                    0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV                      0x8643
#define GL_PROGRAM_PARAMETER_NV                            0x8644
#define GL_ATTRIB_ARRAY_POINTER_NV                         0x8645
#define GL_PROGRAM_TARGET_NV                               0x8646
#define GL_PROGRAM_RESIDENT_NV                             0x8647
#define GL_TRACK_MATRIX_NV                                 0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV                       0x8649
#define GL_VERTEX_PROGRAM_BINDING_NV                       0x864A
#define GL_PROGRAM_ERROR_POSITION_NV                       0x864B
#define GL_VERTEX_ATTRIB_ARRAY0_NV                         0x8650
#define GL_VERTEX_ATTRIB_ARRAY1_NV                         0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV                         0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV                         0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV                         0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV                         0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV                         0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV                         0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV                         0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV                         0x8659
#define GL_VERTEX_ATTRIB_ARRAY10_NV                        0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV                        0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV                        0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV                        0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV                        0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV                        0x865F
#define GL_MAP1_VERTEX_ATTRIB0_4_NV                        0x8660
#define GL_MAP1_VERTEX_ATTRIB1_4_NV                        0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV                        0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV                        0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV                        0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV                        0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV                        0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV                        0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV                        0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV                        0x8669
#define GL_MAP1_VERTEX_ATTRIB10_4_NV                       0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV                       0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV                       0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV                       0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV                       0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV                       0x866F
#define GL_MAP2_VERTEX_ATTRIB0_4_NV                        0x8670
#define GL_MAP2_VERTEX_ATTRIB1_4_NV                        0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV                        0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV                        0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV                        0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV                        0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV                        0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV                        0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV                        0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV                        0x8679
#define GL_MAP2_VERTEX_ATTRIB10_4_NV                       0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV                       0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV                       0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV                       0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV                       0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV                       0x867F
typedef GLboolean (APIENTRYP PFNGLAREPROGRAMSRESIDENTNVPROC) (GLsizei n, const GLuint * programs, GLboolean * residences);
typedef void (APIENTRYP PFNGLBINDPROGRAMNVPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLDELETEPROGRAMSNVPROC) (GLsizei n, const GLuint * programs);
typedef void (APIENTRYP PFNGLEXECUTEPROGRAMNVPROC) (GLenum target, GLuint id, const GLfloat * params);
typedef void (APIENTRYP PFNGLGENPROGRAMSNVPROC) (GLsizei n, GLuint * programs);
typedef void (APIENTRYP PFNGLGETPROGRAMPARAMETERDVNVPROC) (GLenum target, GLuint index, GLenum pname, GLdouble * params);
typedef void (APIENTRYP PFNGLGETPROGRAMPARAMETERFVNVPROC) (GLenum target, GLuint index, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETPROGRAMIVNVPROC) (GLuint id, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETPROGRAMSTRINGNVPROC) (GLuint id, GLenum pname, GLubyte * program);
typedef void (APIENTRYP PFNGLGETTRACKMATRIXIVNVPROC) (GLenum target, GLuint address, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVNVPROC) (GLuint index, GLenum pname, GLdouble * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVNVPROC) (GLuint index, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVNVPROC) (GLuint index, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVNVPROC) (GLuint index, GLenum pname, GLvoid* * pointer);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMNVPROC) (GLuint id);
typedef void (APIENTRYP PFNGLLOADPROGRAMNVPROC) (GLenum target, GLuint id, GLsizei len, const GLubyte * program);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4DNVPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4DVNVPROC) (GLenum target, GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4FNVPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4FVNVPROC) (GLenum target, GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERS4DVNVPROC) (GLenum target, GLuint index, GLuint count, const GLdouble * v);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERS4FVNVPROC) (GLenum target, GLuint index, GLuint count, const GLfloat * v);
typedef void (APIENTRYP PFNGLREQUESTRESIDENTPROGRAMSNVPROC) (GLsizei n, const GLuint * programs);
typedef void (APIENTRYP PFNGLTRACKMATRIXNVPROC) (GLenum target, GLuint address, GLenum matrix, GLenum transform);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERNVPROC) (GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DNVPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVNVPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FNVPROC) (GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVNVPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SNVPROC) (GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVNVPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DNVPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVNVPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FNVPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVNVPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SNVPROC) (GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVNVPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DNVPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVNVPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FNVPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVNVPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SNVPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVNVPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DNVPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVNVPROC) (GLuint index, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FNVPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVNVPROC) (GLuint index, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SNVPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVNVPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBNVPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVNVPROC) (GLuint index, const GLubyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1DVNVPROC) (GLuint index, GLsizei count, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1FVNVPROC) (GLuint index, GLsizei count, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1SVNVPROC) (GLuint index, GLsizei count, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2DVNVPROC) (GLuint index, GLsizei count, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2FVNVPROC) (GLuint index, GLsizei count, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2SVNVPROC) (GLuint index, GLsizei count, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3DVNVPROC) (GLuint index, GLsizei count, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3FVNVPROC) (GLuint index, GLsizei count, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3SVNVPROC) (GLuint index, GLsizei count, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4DVNVPROC) (GLuint index, GLsizei count, const GLdouble * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4FVNVPROC) (GLuint index, GLsizei count, const GLfloat * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4SVNVPROC) (GLuint index, GLsizei count, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4UBVNVPROC) (GLuint index, GLsizei count, const GLubyte * v);
GLEE_EXTERN PFNGLAREPROGRAMSRESIDENTNVPROC pglAreProgramsResidentNV;
GLEE_EXTERN PFNGLBINDPROGRAMNVPROC pglBindProgramNV;
GLEE_EXTERN PFNGLDELETEPROGRAMSNVPROC pglDeleteProgramsNV;
GLEE_EXTERN PFNGLEXECUTEPROGRAMNVPROC pglExecuteProgramNV;
GLEE_EXTERN PFNGLGENPROGRAMSNVPROC pglGenProgramsNV;
GLEE_EXTERN PFNGLGETPROGRAMPARAMETERDVNVPROC pglGetProgramParameterdvNV;
GLEE_EXTERN PFNGLGETPROGRAMPARAMETERFVNVPROC pglGetProgramParameterfvNV;
GLEE_EXTERN PFNGLGETPROGRAMIVNVPROC pglGetProgramivNV;
GLEE_EXTERN PFNGLGETPROGRAMSTRINGNVPROC pglGetProgramStringNV;
GLEE_EXTERN PFNGLGETTRACKMATRIXIVNVPROC pglGetTrackMatrixivNV;
GLEE_EXTERN PFNGLGETVERTEXATTRIBDVNVPROC pglGetVertexAttribdvNV;
GLEE_EXTERN PFNGLGETVERTEXATTRIBFVNVPROC pglGetVertexAttribfvNV;
GLEE_EXTERN PFNGLGETVERTEXATTRIBIVNVPROC pglGetVertexAttribivNV;
GLEE_EXTERN PFNGLGETVERTEXATTRIBPOINTERVNVPROC pglGetVertexAttribPointervNV;
GLEE_EXTERN PFNGLISPROGRAMNVPROC pglIsProgramNV;
GLEE_EXTERN PFNGLLOADPROGRAMNVPROC pglLoadProgramNV;
GLEE_EXTERN PFNGLPROGRAMPARAMETER4DNVPROC pglProgramParameter4dNV;
GLEE_EXTERN PFNGLPROGRAMPARAMETER4DVNVPROC pglProgramParameter4dvNV;
GLEE_EXTERN PFNGLPROGRAMPARAMETER4FNVPROC pglProgramParameter4fNV;
GLEE_EXTERN PFNGLPROGRAMPARAMETER4FVNVPROC pglProgramParameter4fvNV;
GLEE_EXTERN PFNGLPROGRAMPARAMETERS4DVNVPROC pglProgramParameters4dvNV;
GLEE_EXTERN PFNGLPROGRAMPARAMETERS4FVNVPROC pglProgramParameters4fvNV;
GLEE_EXTERN PFNGLREQUESTRESIDENTPROGRAMSNVPROC pglRequestResidentProgramsNV;
GLEE_EXTERN PFNGLTRACKMATRIXNVPROC pglTrackMatrixNV;
GLEE_EXTERN PFNGLVERTEXATTRIBPOINTERNVPROC pglVertexAttribPointerNV;
GLEE_EXTERN PFNGLVERTEXATTRIB1DNVPROC pglVertexAttrib1dNV;
GLEE_EXTERN PFNGLVERTEXATTRIB1DVNVPROC pglVertexAttrib1dvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB1FNVPROC pglVertexAttrib1fNV;
GLEE_EXTERN PFNGLVERTEXATTRIB1FVNVPROC pglVertexAttrib1fvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB1SNVPROC pglVertexAttrib1sNV;
GLEE_EXTERN PFNGLVERTEXATTRIB1SVNVPROC pglVertexAttrib1svNV;
GLEE_EXTERN PFNGLVERTEXATTRIB2DNVPROC pglVertexAttrib2dNV;
GLEE_EXTERN PFNGLVERTEXATTRIB2DVNVPROC pglVertexAttrib2dvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB2FNVPROC pglVertexAttrib2fNV;
GLEE_EXTERN PFNGLVERTEXATTRIB2FVNVPROC pglVertexAttrib2fvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB2SNVPROC pglVertexAttrib2sNV;
GLEE_EXTERN PFNGLVERTEXATTRIB2SVNVPROC pglVertexAttrib2svNV;
GLEE_EXTERN PFNGLVERTEXATTRIB3DNVPROC pglVertexAttrib3dNV;
GLEE_EXTERN PFNGLVERTEXATTRIB3DVNVPROC pglVertexAttrib3dvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB3FNVPROC pglVertexAttrib3fNV;
GLEE_EXTERN PFNGLVERTEXATTRIB3FVNVPROC pglVertexAttrib3fvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB3SNVPROC pglVertexAttrib3sNV;
GLEE_EXTERN PFNGLVERTEXATTRIB3SVNVPROC pglVertexAttrib3svNV;
GLEE_EXTERN PFNGLVERTEXATTRIB4DNVPROC pglVertexAttrib4dNV;
GLEE_EXTERN PFNGLVERTEXATTRIB4DVNVPROC pglVertexAttrib4dvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB4FNVPROC pglVertexAttrib4fNV;
GLEE_EXTERN PFNGLVERTEXATTRIB4FVNVPROC pglVertexAttrib4fvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB4SNVPROC pglVertexAttrib4sNV;
GLEE_EXTERN PFNGLVERTEXATTRIB4SVNVPROC pglVertexAttrib4svNV;
GLEE_EXTERN PFNGLVERTEXATTRIB4UBNVPROC pglVertexAttrib4ubNV;
GLEE_EXTERN PFNGLVERTEXATTRIB4UBVNVPROC pglVertexAttrib4ubvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS1DVNVPROC pglVertexAttribs1dvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS1FVNVPROC pglVertexAttribs1fvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS1SVNVPROC pglVertexAttribs1svNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS2DVNVPROC pglVertexAttribs2dvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS2FVNVPROC pglVertexAttribs2fvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS2SVNVPROC pglVertexAttribs2svNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS3DVNVPROC pglVertexAttribs3dvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS3FVNVPROC pglVertexAttribs3fvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS3SVNVPROC pglVertexAttribs3svNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS4DVNVPROC pglVertexAttribs4dvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS4FVNVPROC pglVertexAttribs4fvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS4SVNVPROC pglVertexAttribs4svNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS4UBVNVPROC pglVertexAttribs4ubvNV;
#define glAreProgramsResidentNV pglAreProgramsResidentNV
#define glBindProgramNV pglBindProgramNV
#define glDeleteProgramsNV pglDeleteProgramsNV
#define glExecuteProgramNV pglExecuteProgramNV
#define glGenProgramsNV pglGenProgramsNV
#define glGetProgramParameterdvNV pglGetProgramParameterdvNV
#define glGetProgramParameterfvNV pglGetProgramParameterfvNV
#define glGetProgramivNV pglGetProgramivNV
#define glGetProgramStringNV pglGetProgramStringNV
#define glGetTrackMatrixivNV pglGetTrackMatrixivNV
#define glGetVertexAttribdvNV pglGetVertexAttribdvNV
#define glGetVertexAttribfvNV pglGetVertexAttribfvNV
#define glGetVertexAttribivNV pglGetVertexAttribivNV
#define glGetVertexAttribPointervNV pglGetVertexAttribPointervNV
#define glIsProgramNV pglIsProgramNV
#define glLoadProgramNV pglLoadProgramNV
#define glProgramParameter4dNV pglProgramParameter4dNV
#define glProgramParameter4dvNV pglProgramParameter4dvNV
#define glProgramParameter4fNV pglProgramParameter4fNV
#define glProgramParameter4fvNV pglProgramParameter4fvNV
#define glProgramParameters4dvNV pglProgramParameters4dvNV
#define glProgramParameters4fvNV pglProgramParameters4fvNV
#define glRequestResidentProgramsNV pglRequestResidentProgramsNV
#define glTrackMatrixNV pglTrackMatrixNV
#define glVertexAttribPointerNV pglVertexAttribPointerNV
#define glVertexAttrib1dNV pglVertexAttrib1dNV
#define glVertexAttrib1dvNV pglVertexAttrib1dvNV
#define glVertexAttrib1fNV pglVertexAttrib1fNV
#define glVertexAttrib1fvNV pglVertexAttrib1fvNV
#define glVertexAttrib1sNV pglVertexAttrib1sNV
#define glVertexAttrib1svNV pglVertexAttrib1svNV
#define glVertexAttrib2dNV pglVertexAttrib2dNV
#define glVertexAttrib2dvNV pglVertexAttrib2dvNV
#define glVertexAttrib2fNV pglVertexAttrib2fNV
#define glVertexAttrib2fvNV pglVertexAttrib2fvNV
#define glVertexAttrib2sNV pglVertexAttrib2sNV
#define glVertexAttrib2svNV pglVertexAttrib2svNV
#define glVertexAttrib3dNV pglVertexAttrib3dNV
#define glVertexAttrib3dvNV pglVertexAttrib3dvNV
#define glVertexAttrib3fNV pglVertexAttrib3fNV
#define glVertexAttrib3fvNV pglVertexAttrib3fvNV
#define glVertexAttrib3sNV pglVertexAttrib3sNV
#define glVertexAttrib3svNV pglVertexAttrib3svNV
#define glVertexAttrib4dNV pglVertexAttrib4dNV
#define glVertexAttrib4dvNV pglVertexAttrib4dvNV
#define glVertexAttrib4fNV pglVertexAttrib4fNV
#define glVertexAttrib4fvNV pglVertexAttrib4fvNV
#define glVertexAttrib4sNV pglVertexAttrib4sNV
#define glVertexAttrib4svNV pglVertexAttrib4svNV
#define glVertexAttrib4ubNV pglVertexAttrib4ubNV
#define glVertexAttrib4ubvNV pglVertexAttrib4ubvNV
#define glVertexAttribs1dvNV pglVertexAttribs1dvNV
#define glVertexAttribs1fvNV pglVertexAttribs1fvNV
#define glVertexAttribs1svNV pglVertexAttribs1svNV
#define glVertexAttribs2dvNV pglVertexAttribs2dvNV
#define glVertexAttribs2fvNV pglVertexAttribs2fvNV
#define glVertexAttribs2svNV pglVertexAttribs2svNV
#define glVertexAttribs3dvNV pglVertexAttribs3dvNV
#define glVertexAttribs3fvNV pglVertexAttribs3fvNV
#define glVertexAttribs3svNV pglVertexAttribs3svNV
#define glVertexAttribs4dvNV pglVertexAttribs4dvNV
#define glVertexAttribs4fvNV pglVertexAttribs4fvNV
#define glVertexAttribs4svNV pglVertexAttribs4svNV
#define glVertexAttribs4ubvNV pglVertexAttribs4ubvNV
#endif 

/* GL_SGIX_texture_coordinate_clamp */

#ifndef GL_SGIX_texture_coordinate_clamp
#define GL_SGIX_texture_coordinate_clamp 1
#define __GLEE_GL_SGIX_texture_coordinate_clamp 1
/* Constants */
#define GL_TEXTURE_MAX_CLAMP_S_SGIX                        0x8369
#define GL_TEXTURE_MAX_CLAMP_T_SGIX                        0x836A
#define GL_TEXTURE_MAX_CLAMP_R_SGIX                        0x836B
#endif 

/* GL_SGIX_scalebias_hint */

#ifndef GL_SGIX_scalebias_hint
#define GL_SGIX_scalebias_hint 1
#define __GLEE_GL_SGIX_scalebias_hint 1
/* Constants */
#define GL_SCALEBIAS_HINT_SGIX                             0x8322
#endif 

/* GL_OML_interlace */

#ifndef GL_OML_interlace
#define GL_OML_interlace 1
#define __GLEE_GL_OML_interlace 1
/* Constants */
#define GL_INTERLACE_OML                                   0x8980
#define GL_INTERLACE_READ_OML                              0x8981
#endif 

/* GL_OML_subsample */

#ifndef GL_OML_subsample
#define GL_OML_subsample 1
#define __GLEE_GL_OML_subsample 1
/* Constants */
#define GL_FORMAT_SUBSAMPLE_24_24_OML                      0x8982
#define GL_FORMAT_SUBSAMPLE_244_244_OML                    0x8983
#endif 

/* GL_OML_resample */

#ifndef GL_OML_resample
#define GL_OML_resample 1
#define __GLEE_GL_OML_resample 1
/* Constants */
#define GL_PACK_RESAMPLE_OML                               0x8984
#define GL_UNPACK_RESAMPLE_OML                             0x8985
#define GL_RESAMPLE_REPLICATE_OML                          0x8986
#define GL_RESAMPLE_ZERO_FILL_OML                          0x8987
#define GL_RESAMPLE_AVERAGE_OML                            0x8988
#define GL_RESAMPLE_DECIMATE_OML                           0x8989
#endif 

/* GL_NV_copy_depth_to_color */

#ifndef GL_NV_copy_depth_to_color
#define GL_NV_copy_depth_to_color 1
#define __GLEE_GL_NV_copy_depth_to_color 1
/* Constants */
#define GL_DEPTH_STENCIL_TO_RGBA_NV                        0x886E
#define GL_DEPTH_STENCIL_TO_BGRA_NV                        0x886F
#endif 

/* GL_ATI_envmap_bumpmap */

#ifndef GL_ATI_envmap_bumpmap
#define GL_ATI_envmap_bumpmap 1
#define __GLEE_GL_ATI_envmap_bumpmap 1
/* Constants */
#define GL_BUMP_ROT_MATRIX_ATI                             0x8775
#define GL_BUMP_ROT_MATRIX_SIZE_ATI                        0x8776
#define GL_BUMP_NUM_TEX_UNITS_ATI                          0x8777
#define GL_BUMP_TEX_UNITS_ATI                              0x8778
#define GL_DUDV_ATI                                        0x8779
#define GL_DU8DV8_ATI                                      0x877A
#define GL_BUMP_ENVMAP_ATI                                 0x877B
#define GL_BUMP_TARGET_ATI                                 0x877C
typedef void (APIENTRYP PFNGLTEXBUMPPARAMETERIVATIPROC) (GLenum pname, const GLint * param);
typedef void (APIENTRYP PFNGLTEXBUMPPARAMETERFVATIPROC) (GLenum pname, const GLfloat * param);
typedef void (APIENTRYP PFNGLGETTEXBUMPPARAMETERIVATIPROC) (GLenum pname, GLint * param);
typedef void (APIENTRYP PFNGLGETTEXBUMPPARAMETERFVATIPROC) (GLenum pname, GLfloat * param);
GLEE_EXTERN PFNGLTEXBUMPPARAMETERIVATIPROC pglTexBumpParameterivATI;
GLEE_EXTERN PFNGLTEXBUMPPARAMETERFVATIPROC pglTexBumpParameterfvATI;
GLEE_EXTERN PFNGLGETTEXBUMPPARAMETERIVATIPROC pglGetTexBumpParameterivATI;
GLEE_EXTERN PFNGLGETTEXBUMPPARAMETERFVATIPROC pglGetTexBumpParameterfvATI;
#define glTexBumpParameterivATI pglTexBumpParameterivATI
#define glTexBumpParameterfvATI pglTexBumpParameterfvATI
#define glGetTexBumpParameterivATI pglGetTexBumpParameterivATI
#define glGetTexBumpParameterfvATI pglGetTexBumpParameterfvATI
#endif 

/* GL_ATI_fragment_shader */

#ifndef GL_ATI_fragment_shader
#define GL_ATI_fragment_shader 1
#define __GLEE_GL_ATI_fragment_shader 1
/* Constants */
#define GL_FRAGMENT_SHADER_ATI                             0x8920
#define GL_REG_0_ATI                                       0x8921
#define GL_REG_1_ATI                                       0x8922
#define GL_REG_2_ATI                                       0x8923
#define GL_REG_3_ATI                                       0x8924
#define GL_REG_4_ATI                                       0x8925
#define GL_REG_5_ATI                                       0x8926
#define GL_REG_6_ATI                                       0x8927
#define GL_REG_7_ATI                                       0x8928
#define GL_REG_8_ATI                                       0x8929
#define GL_REG_9_ATI                                       0x892A
#define GL_REG_10_ATI                                      0x892B
#define GL_REG_11_ATI                                      0x892C
#define GL_REG_12_ATI                                      0x892D
#define GL_REG_13_ATI                                      0x892E
#define GL_REG_14_ATI                                      0x892F
#define GL_REG_15_ATI                                      0x8930
#define GL_REG_16_ATI                                      0x8931
#define GL_REG_17_ATI                                      0x8932
#define GL_REG_18_ATI                                      0x8933
#define GL_REG_19_ATI                                      0x8934
#define GL_REG_20_ATI                                      0x8935
#define GL_REG_21_ATI                                      0x8936
#define GL_REG_22_ATI                                      0x8937
#define GL_REG_23_ATI                                      0x8938
#define GL_REG_24_ATI                                      0x8939
#define GL_REG_25_ATI                                      0x893A
#define GL_REG_26_ATI                                      0x893B
#define GL_REG_27_ATI                                      0x893C
#define GL_REG_28_ATI                                      0x893D
#define GL_REG_29_ATI                                      0x893E
#define GL_REG_30_ATI                                      0x893F
#define GL_REG_31_ATI                                      0x8940
#define GL_CON_0_ATI                                       0x8941
#define GL_CON_1_ATI                                       0x8942
#define GL_CON_2_ATI                                       0x8943
#define GL_CON_3_ATI                                       0x8944
#define GL_CON_4_ATI                                       0x8945
#define GL_CON_5_ATI                                       0x8946
#define GL_CON_6_ATI                                       0x8947
#define GL_CON_7_ATI                                       0x8948
#define GL_CON_8_ATI                                       0x8949
#define GL_CON_9_ATI                                       0x894A
#define GL_CON_10_ATI                                      0x894B
#define GL_CON_11_ATI                                      0x894C
#define GL_CON_12_ATI                                      0x894D
#define GL_CON_13_ATI                                      0x894E
#define GL_CON_14_ATI                                      0x894F
#define GL_CON_15_ATI                                      0x8950
#define GL_CON_16_ATI                                      0x8951
#define GL_CON_17_ATI                                      0x8952
#define GL_CON_18_ATI                                      0x8953
#define GL_CON_19_ATI                                      0x8954
#define GL_CON_20_ATI                                      0x8955
#define GL_CON_21_ATI                                      0x8956
#define GL_CON_22_ATI                                      0x8957
#define GL_CON_23_ATI                                      0x8958
#define GL_CON_24_ATI                                      0x8959
#define GL_CON_25_ATI                                      0x895A
#define GL_CON_26_ATI                                      0x895B
#define GL_CON_27_ATI                                      0x895C
#define GL_CON_28_ATI                                      0x895D
#define GL_CON_29_ATI                                      0x895E
#define GL_CON_30_ATI                                      0x895F
#define GL_CON_31_ATI                                      0x8960
#define GL_MOV_ATI                                         0x8961
#define GL_ADD_ATI                                         0x8963
#define GL_MUL_ATI                                         0x8964
#define GL_SUB_ATI                                         0x8965
#define GL_DOT3_ATI                                        0x8966
#define GL_DOT4_ATI                                        0x8967
#define GL_MAD_ATI                                         0x8968
#define GL_LERP_ATI                                        0x8969
#define GL_CND_ATI                                         0x896A
#define GL_CND0_ATI                                        0x896B
#define GL_DOT2_ADD_ATI                                    0x896C
#define GL_SECONDARY_INTERPOLATOR_ATI                      0x896D
#define GL_NUM_FRAGMENT_REGISTERS_ATI                      0x896E
#define GL_NUM_FRAGMENT_CONSTANTS_ATI                      0x896F
#define GL_NUM_PASSES_ATI                                  0x8970
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI                   0x8971
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI                      0x8972
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI           0x8973
#define GL_NUM_LOOPBACK_COMPONENTS_ATI                     0x8974
#define GL_COLOR_ALPHA_PAIRING_ATI                         0x8975
#define GL_SWIZZLE_STR_ATI                                 0x8976
#define GL_SWIZZLE_STQ_ATI                                 0x8977
#define GL_SWIZZLE_STR_DR_ATI                              0x8978
#define GL_SWIZZLE_STQ_DQ_ATI                              0x8979
#define GL_SWIZZLE_STRQ_ATI                                0x897A
#define GL_SWIZZLE_STRQ_DQ_ATI                             0x897B
#define GL_RED_BIT_ATI                                     0x00000001
#define GL_GREEN_BIT_ATI                                   0x00000002
#define GL_BLUE_BIT_ATI                                    0x00000004
#define GL_2X_BIT_ATI                                      0x00000001
#define GL_4X_BIT_ATI                                      0x00000002
#define GL_8X_BIT_ATI                                      0x00000004
#define GL_HALF_BIT_ATI                                    0x00000008
#define GL_QUARTER_BIT_ATI                                 0x00000010
#define GL_EIGHTH_BIT_ATI                                  0x00000020
#define GL_SATURATE_BIT_ATI                                0x00000040
#define GL_COMP_BIT_ATI                                    0x00000002
#define GL_NEGATE_BIT_ATI                                  0x00000004
#define GL_BIAS_BIT_ATI                                    0x00000008
typedef GLuint (APIENTRYP PFNGLGENFRAGMENTSHADERSATIPROC) (GLuint range);
typedef void (APIENTRYP PFNGLBINDFRAGMENTSHADERATIPROC) (GLuint id);
typedef void (APIENTRYP PFNGLDELETEFRAGMENTSHADERATIPROC) (GLuint id);
typedef void (APIENTRYP PFNGLBEGINFRAGMENTSHADERATIPROC) ();
typedef void (APIENTRYP PFNGLENDFRAGMENTSHADERATIPROC) ();
typedef void (APIENTRYP PFNGLPASSTEXCOORDATIPROC) (GLuint dst, GLuint coord, GLenum swizzle);
typedef void (APIENTRYP PFNGLSAMPLEMAPATIPROC) (GLuint dst, GLuint interp, GLenum swizzle);
typedef void (APIENTRYP PFNGLCOLORFRAGMENTOP1ATIPROC) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
typedef void (APIENTRYP PFNGLCOLORFRAGMENTOP2ATIPROC) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
typedef void (APIENTRYP PFNGLCOLORFRAGMENTOP3ATIPROC) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
typedef void (APIENTRYP PFNGLALPHAFRAGMENTOP1ATIPROC) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
typedef void (APIENTRYP PFNGLALPHAFRAGMENTOP2ATIPROC) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
typedef void (APIENTRYP PFNGLALPHAFRAGMENTOP3ATIPROC) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
typedef void (APIENTRYP PFNGLSETFRAGMENTSHADERCONSTANTATIPROC) (GLuint dst, const GLfloat * value);
GLEE_EXTERN PFNGLGENFRAGMENTSHADERSATIPROC pglGenFragmentShadersATI;
GLEE_EXTERN PFNGLBINDFRAGMENTSHADERATIPROC pglBindFragmentShaderATI;
GLEE_EXTERN PFNGLDELETEFRAGMENTSHADERATIPROC pglDeleteFragmentShaderATI;
GLEE_EXTERN PFNGLBEGINFRAGMENTSHADERATIPROC pglBeginFragmentShaderATI;
GLEE_EXTERN PFNGLENDFRAGMENTSHADERATIPROC pglEndFragmentShaderATI;
GLEE_EXTERN PFNGLPASSTEXCOORDATIPROC pglPassTexCoordATI;
GLEE_EXTERN PFNGLSAMPLEMAPATIPROC pglSampleMapATI;
GLEE_EXTERN PFNGLCOLORFRAGMENTOP1ATIPROC pglColorFragmentOp1ATI;
GLEE_EXTERN PFNGLCOLORFRAGMENTOP2ATIPROC pglColorFragmentOp2ATI;
GLEE_EXTERN PFNGLCOLORFRAGMENTOP3ATIPROC pglColorFragmentOp3ATI;
GLEE_EXTERN PFNGLALPHAFRAGMENTOP1ATIPROC pglAlphaFragmentOp1ATI;
GLEE_EXTERN PFNGLALPHAFRAGMENTOP2ATIPROC pglAlphaFragmentOp2ATI;
GLEE_EXTERN PFNGLALPHAFRAGMENTOP3ATIPROC pglAlphaFragmentOp3ATI;
GLEE_EXTERN PFNGLSETFRAGMENTSHADERCONSTANTATIPROC pglSetFragmentShaderConstantATI;
#define glGenFragmentShadersATI pglGenFragmentShadersATI
#define glBindFragmentShaderATI pglBindFragmentShaderATI
#define glDeleteFragmentShaderATI pglDeleteFragmentShaderATI
#define glBeginFragmentShaderATI pglBeginFragmentShaderATI
#define glEndFragmentShaderATI pglEndFragmentShaderATI
#define glPassTexCoordATI pglPassTexCoordATI
#define glSampleMapATI pglSampleMapATI
#define glColorFragmentOp1ATI pglColorFragmentOp1ATI
#define glColorFragmentOp2ATI pglColorFragmentOp2ATI
#define glColorFragmentOp3ATI pglColorFragmentOp3ATI
#define glAlphaFragmentOp1ATI pglAlphaFragmentOp1ATI
#define glAlphaFragmentOp2ATI pglAlphaFragmentOp2ATI
#define glAlphaFragmentOp3ATI pglAlphaFragmentOp3ATI
#define glSetFragmentShaderConstantATI pglSetFragmentShaderConstantATI
#endif 

/* GL_ATI_pn_triangles */

#ifndef GL_ATI_pn_triangles
#define GL_ATI_pn_triangles 1
#define __GLEE_GL_ATI_pn_triangles 1
/* Constants */
#define GL_PN_TRIANGLES_ATI                                0x87F0
#define GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI          0x87F1
#define GL_PN_TRIANGLES_POINT_MODE_ATI                     0x87F2
#define GL_PN_TRIANGLES_NORMAL_MODE_ATI                    0x87F3
#define GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI              0x87F4
#define GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI              0x87F5
#define GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI               0x87F6
#define GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI             0x87F7
#define GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI          0x87F8
typedef void (APIENTRYP PFNGLPNTRIANGLESIATIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPNTRIANGLESFATIPROC) (GLenum pname, GLfloat param);
GLEE_EXTERN PFNGLPNTRIANGLESIATIPROC pglPNTrianglesiATI;
GLEE_EXTERN PFNGLPNTRIANGLESFATIPROC pglPNTrianglesfATI;
#define glPNTrianglesiATI pglPNTrianglesiATI
#define glPNTrianglesfATI pglPNTrianglesfATI
#endif 

/* GL_ATI_vertex_array_object */

#ifndef GL_ATI_vertex_array_object
#define GL_ATI_vertex_array_object 1
#define __GLEE_GL_ATI_vertex_array_object 1
/* Constants */
#define GL_STATIC_ATI                                      0x8760
#define GL_DYNAMIC_ATI                                     0x8761
#define GL_PRESERVE_ATI                                    0x8762
#define GL_DISCARD_ATI                                     0x8763
#define GL_OBJECT_BUFFER_SIZE_ATI                          0x8764
#define GL_OBJECT_BUFFER_USAGE_ATI                         0x8765
#define GL_ARRAY_OBJECT_BUFFER_ATI                         0x8766
#define GL_ARRAY_OBJECT_OFFSET_ATI                         0x8767
typedef GLuint (APIENTRYP PFNGLNEWOBJECTBUFFERATIPROC) (GLsizei size, const GLvoid * pointer, GLenum usage);
typedef GLboolean (APIENTRYP PFNGLISOBJECTBUFFERATIPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLUPDATEOBJECTBUFFERATIPROC) (GLuint buffer, GLuint offset, GLsizei size, const GLvoid * pointer, GLenum preserve);
typedef void (APIENTRYP PFNGLGETOBJECTBUFFERFVATIPROC) (GLuint buffer, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETOBJECTBUFFERIVATIPROC) (GLuint buffer, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLFREEOBJECTBUFFERATIPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLARRAYOBJECTATIPROC) (GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
typedef void (APIENTRYP PFNGLGETARRAYOBJECTFVATIPROC) (GLenum array, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETARRAYOBJECTIVATIPROC) (GLenum array, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLVARIANTARRAYOBJECTATIPROC) (GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
typedef void (APIENTRYP PFNGLGETVARIANTARRAYOBJECTFVATIPROC) (GLuint id, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETVARIANTARRAYOBJECTIVATIPROC) (GLuint id, GLenum pname, GLint * params);
GLEE_EXTERN PFNGLNEWOBJECTBUFFERATIPROC pglNewObjectBufferATI;
GLEE_EXTERN PFNGLISOBJECTBUFFERATIPROC pglIsObjectBufferATI;
GLEE_EXTERN PFNGLUPDATEOBJECTBUFFERATIPROC pglUpdateObjectBufferATI;
GLEE_EXTERN PFNGLGETOBJECTBUFFERFVATIPROC pglGetObjectBufferfvATI;
GLEE_EXTERN PFNGLGETOBJECTBUFFERIVATIPROC pglGetObjectBufferivATI;
GLEE_EXTERN PFNGLFREEOBJECTBUFFERATIPROC pglFreeObjectBufferATI;
GLEE_EXTERN PFNGLARRAYOBJECTATIPROC pglArrayObjectATI;
GLEE_EXTERN PFNGLGETARRAYOBJECTFVATIPROC pglGetArrayObjectfvATI;
GLEE_EXTERN PFNGLGETARRAYOBJECTIVATIPROC pglGetArrayObjectivATI;
GLEE_EXTERN PFNGLVARIANTARRAYOBJECTATIPROC pglVariantArrayObjectATI;
GLEE_EXTERN PFNGLGETVARIANTARRAYOBJECTFVATIPROC pglGetVariantArrayObjectfvATI;
GLEE_EXTERN PFNGLGETVARIANTARRAYOBJECTIVATIPROC pglGetVariantArrayObjectivATI;
#define glNewObjectBufferATI pglNewObjectBufferATI
#define glIsObjectBufferATI pglIsObjectBufferATI
#define glUpdateObjectBufferATI pglUpdateObjectBufferATI
#define glGetObjectBufferfvATI pglGetObjectBufferfvATI
#define glGetObjectBufferivATI pglGetObjectBufferivATI
#define glFreeObjectBufferATI pglFreeObjectBufferATI
#define glArrayObjectATI pglArrayObjectATI
#define glGetArrayObjectfvATI pglGetArrayObjectfvATI
#define glGetArrayObjectivATI pglGetArrayObjectivATI
#define glVariantArrayObjectATI pglVariantArrayObjectATI
#define glGetVariantArrayObjectfvATI pglGetVariantArrayObjectfvATI
#define glGetVariantArrayObjectivATI pglGetVariantArrayObjectivATI
#endif 

/* GL_EXT_vertex_shader */

#ifndef GL_EXT_vertex_shader
#define GL_EXT_vertex_shader 1
#define __GLEE_GL_EXT_vertex_shader 1
/* Constants */
#define GL_VERTEX_SHADER_EXT                               0x8780
#define GL_VERTEX_SHADER_BINDING_EXT                       0x8781
#define GL_OP_INDEX_EXT                                    0x8782
#define GL_OP_NEGATE_EXT                                   0x8783
#define GL_OP_DOT3_EXT                                     0x8784
#define GL_OP_DOT4_EXT                                     0x8785
#define GL_OP_MUL_EXT                                      0x8786
#define GL_OP_ADD_EXT                                      0x8787
#define GL_OP_MADD_EXT                                     0x8788
#define GL_OP_FRAC_EXT                                     0x8789
#define GL_OP_MAX_EXT                                      0x878A
#define GL_OP_MIN_EXT                                      0x878B
#define GL_OP_SET_GE_EXT                                   0x878C
#define GL_OP_SET_LT_EXT                                   0x878D
#define GL_OP_CLAMP_EXT                                    0x878E
#define GL_OP_FLOOR_EXT                                    0x878F
#define GL_OP_ROUND_EXT                                    0x8790
#define GL_OP_EXP_BASE_2_EXT                               0x8791
#define GL_OP_LOG_BASE_2_EXT                               0x8792
#define GL_OP_POWER_EXT                                    0x8793
#define GL_OP_RECIP_EXT                                    0x8794
#define GL_OP_RECIP_SQRT_EXT                               0x8795
#define GL_OP_SUB_EXT                                      0x8796
#define GL_OP_CROSS_PRODUCT_EXT                            0x8797
#define GL_OP_MULTIPLY_MATRIX_EXT                          0x8798
#define GL_OP_MOV_EXT                                      0x8799
#define GL_OUTPUT_VERTEX_EXT                               0x879A
#define GL_OUTPUT_COLOR0_EXT                               0x879B
#define GL_OUTPUT_COLOR1_EXT                               0x879C
#define GL_OUTPUT_TEXTURE_COORD0_EXT                       0x879D
#define GL_OUTPUT_TEXTURE_COORD1_EXT                       0x879E
#define GL_OUTPUT_TEXTURE_COORD2_EXT                       0x879F
#define GL_OUTPUT_TEXTURE_COORD3_EXT                       0x87A0
#define GL_OUTPUT_TEXTURE_COORD4_EXT                       0x87A1
#define GL_OUTPUT_TEXTURE_COORD5_EXT                       0x87A2
#define GL_OUTPUT_TEXTURE_COORD6_EXT                       0x87A3
#define GL_OUTPUT_TEXTURE_COORD7_EXT                       0x87A4
#define GL_OUTPUT_TEXTURE_COORD8_EXT                       0x87A5
#define GL_OUTPUT_TEXTURE_COORD9_EXT                       0x87A6
#define GL_OUTPUT_TEXTURE_COORD10_EXT                      0x87A7
#define GL_OUTPUT_TEXTURE_COORD11_EXT                      0x87A8
#define GL_OUTPUT_TEXTURE_COORD12_EXT                      0x87A9
#define GL_OUTPUT_TEXTURE_COORD13_EXT                      0x87AA
#define GL_OUTPUT_TEXTURE_COORD14_EXT                      0x87AB
#define GL_OUTPUT_TEXTURE_COORD15_EXT                      0x87AC
#define GL_OUTPUT_TEXTURE_COORD16_EXT                      0x87AD
#define GL_OUTPUT_TEXTURE_COORD17_EXT                      0x87AE
#define GL_OUTPUT_TEXTURE_COORD18_EXT                      0x87AF
#define GL_OUTPUT_TEXTURE_COORD19_EXT                      0x87B0
#define GL_OUTPUT_TEXTURE_COORD20_EXT                      0x87B1
#define GL_OUTPUT_TEXTURE_COORD21_EXT                      0x87B2
#define GL_OUTPUT_TEXTURE_COORD22_EXT                      0x87B3
#define GL_OUTPUT_TEXTURE_COORD23_EXT                      0x87B4
#define GL_OUTPUT_TEXTURE_COORD24_EXT                      0x87B5
#define GL_OUTPUT_TEXTURE_COORD25_EXT                      0x87B6
#define GL_OUTPUT_TEXTURE_COORD26_EXT                      0x87B7
#define GL_OUTPUT_TEXTURE_COORD27_EXT                      0x87B8
#define GL_OUTPUT_TEXTURE_COORD28_EXT                      0x87B9
#define GL_OUTPUT_TEXTURE_COORD29_EXT                      0x87BA
#define GL_OUTPUT_TEXTURE_COORD30_EXT                      0x87BB
#define GL_OUTPUT_TEXTURE_COORD31_EXT                      0x87BC
#define GL_OUTPUT_FOG_EXT                                  0x87BD
#define GL_SCALAR_EXT                                      0x87BE
#define GL_VECTOR_EXT                                      0x87BF
#define GL_MATRIX_EXT                                      0x87C0
#define GL_VARIANT_EXT                                     0x87C1
#define GL_INVARIANT_EXT                                   0x87C2
#define GL_LOCAL_CONSTANT_EXT                              0x87C3
#define GL_LOCAL_EXT                                       0x87C4
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT              0x87C5
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT                  0x87C6
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT                0x87C7
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT           0x87C8
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT                    0x87C9
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT    0x87CA
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT        0x87CB
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87CC
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT      0x87CD
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT          0x87CE
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT                  0x87CF
#define GL_VERTEX_SHADER_VARIANTS_EXT                      0x87D0
#define GL_VERTEX_SHADER_INVARIANTS_EXT                    0x87D1
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT               0x87D2
#define GL_VERTEX_SHADER_LOCALS_EXT                        0x87D3
#define GL_VERTEX_SHADER_OPTIMIZED_EXT                     0x87D4
#define GL_X_EXT                                           0x87D5
#define GL_Y_EXT                                           0x87D6
#define GL_Z_EXT                                           0x87D7
#define GL_W_EXT                                           0x87D8
#define GL_NEGATIVE_X_EXT                                  0x87D9
#define GL_NEGATIVE_Y_EXT                                  0x87DA
#define GL_NEGATIVE_Z_EXT                                  0x87DB
#define GL_NEGATIVE_W_EXT                                  0x87DC
#define GL_ZERO_EXT                                        0x87DD
#define GL_ONE_EXT                                         0x87DE
#define GL_NEGATIVE_ONE_EXT                                0x87DF
#define GL_NORMALIZED_RANGE_EXT                            0x87E0
#define GL_FULL_RANGE_EXT                                  0x87E1
#define GL_CURRENT_VERTEX_EXT                              0x87E2
#define GL_MVP_MATRIX_EXT                                  0x87E3
#define GL_VARIANT_VALUE_EXT                               0x87E4
#define GL_VARIANT_DATATYPE_EXT                            0x87E5
#define GL_VARIANT_ARRAY_STRIDE_EXT                        0x87E6
#define GL_VARIANT_ARRAY_TYPE_EXT                          0x87E7
#define GL_VARIANT_ARRAY_EXT                               0x87E8
#define GL_VARIANT_ARRAY_POINTER_EXT                       0x87E9
#define GL_INVARIANT_VALUE_EXT                             0x87EA
#define GL_INVARIANT_DATATYPE_EXT                          0x87EB
#define GL_LOCAL_CONSTANT_VALUE_EXT                        0x87EC
#define GL_LOCAL_CONSTANT_DATATYPE_EXT                     0x87ED
typedef void (APIENTRYP PFNGLBEGINVERTEXSHADEREXTPROC) ();
typedef void (APIENTRYP PFNGLENDVERTEXSHADEREXTPROC) ();
typedef void (APIENTRYP PFNGLBINDVERTEXSHADEREXTPROC) (GLuint id);
typedef GLuint (APIENTRYP PFNGLGENVERTEXSHADERSEXTPROC) (GLuint range);
typedef void (APIENTRYP PFNGLDELETEVERTEXSHADEREXTPROC) (GLuint id);
typedef void (APIENTRYP PFNGLSHADEROP1EXTPROC) (GLenum op, GLuint res, GLuint arg1);
typedef void (APIENTRYP PFNGLSHADEROP2EXTPROC) (GLenum op, GLuint res, GLuint arg1, GLuint arg2);
typedef void (APIENTRYP PFNGLSHADEROP3EXTPROC) (GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
typedef void (APIENTRYP PFNGLSWIZZLEEXTPROC) (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
typedef void (APIENTRYP PFNGLWRITEMASKEXTPROC) (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
typedef void (APIENTRYP PFNGLINSERTCOMPONENTEXTPROC) (GLuint res, GLuint src, GLuint num);
typedef void (APIENTRYP PFNGLEXTRACTCOMPONENTEXTPROC) (GLuint res, GLuint src, GLuint num);
typedef GLuint (APIENTRYP PFNGLGENSYMBOLSEXTPROC) (GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
typedef void (APIENTRYP PFNGLSETINVARIANTEXTPROC) (GLuint id, GLenum type, const GLvoid * addr);
typedef void (APIENTRYP PFNGLSETLOCALCONSTANTEXTPROC) (GLuint id, GLenum type, const GLvoid * addr);
typedef void (APIENTRYP PFNGLVARIANTBVEXTPROC) (GLuint id, const GLbyte * addr);
typedef void (APIENTRYP PFNGLVARIANTSVEXTPROC) (GLuint id, const GLshort * addr);
typedef void (APIENTRYP PFNGLVARIANTIVEXTPROC) (GLuint id, const GLint * addr);
typedef void (APIENTRYP PFNGLVARIANTFVEXTPROC) (GLuint id, const GLfloat * addr);
typedef void (APIENTRYP PFNGLVARIANTDVEXTPROC) (GLuint id, const GLdouble * addr);
typedef void (APIENTRYP PFNGLVARIANTUBVEXTPROC) (GLuint id, const GLubyte * addr);
typedef void (APIENTRYP PFNGLVARIANTUSVEXTPROC) (GLuint id, const GLushort * addr);
typedef void (APIENTRYP PFNGLVARIANTUIVEXTPROC) (GLuint id, const GLuint * addr);
typedef void (APIENTRYP PFNGLVARIANTPOINTEREXTPROC) (GLuint id, GLenum type, GLuint stride, const GLvoid * addr);
typedef void (APIENTRYP PFNGLENABLEVARIANTCLIENTSTATEEXTPROC) (GLuint id);
typedef void (APIENTRYP PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC) (GLuint id);
typedef GLuint (APIENTRYP PFNGLBINDLIGHTPARAMETEREXTPROC) (GLenum light, GLenum value);
typedef GLuint (APIENTRYP PFNGLBINDMATERIALPARAMETEREXTPROC) (GLenum face, GLenum value);
typedef GLuint (APIENTRYP PFNGLBINDTEXGENPARAMETEREXTPROC) (GLenum unit, GLenum coord, GLenum value);
typedef GLuint (APIENTRYP PFNGLBINDTEXTUREUNITPARAMETEREXTPROC) (GLenum unit, GLenum value);
typedef GLuint (APIENTRYP PFNGLBINDPARAMETEREXTPROC) (GLenum value);
typedef GLboolean (APIENTRYP PFNGLISVARIANTENABLEDEXTPROC) (GLuint id, GLenum cap);
typedef void (APIENTRYP PFNGLGETVARIANTBOOLEANVEXTPROC) (GLuint id, GLenum value, GLboolean * data);
typedef void (APIENTRYP PFNGLGETVARIANTINTEGERVEXTPROC) (GLuint id, GLenum value, GLint * data);
typedef void (APIENTRYP PFNGLGETVARIANTFLOATVEXTPROC) (GLuint id, GLenum value, GLfloat * data);
typedef void (APIENTRYP PFNGLGETVARIANTPOINTERVEXTPROC) (GLuint id, GLenum value, GLvoid* * data);
typedef void (APIENTRYP PFNGLGETINVARIANTBOOLEANVEXTPROC) (GLuint id, GLenum value, GLboolean * data);
typedef void (APIENTRYP PFNGLGETINVARIANTINTEGERVEXTPROC) (GLuint id, GLenum value, GLint * data);
typedef void (APIENTRYP PFNGLGETINVARIANTFLOATVEXTPROC) (GLuint id, GLenum value, GLfloat * data);
typedef void (APIENTRYP PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC) (GLuint id, GLenum value, GLboolean * data);
typedef void (APIENTRYP PFNGLGETLOCALCONSTANTINTEGERVEXTPROC) (GLuint id, GLenum value, GLint * data);
typedef void (APIENTRYP PFNGLGETLOCALCONSTANTFLOATVEXTPROC) (GLuint id, GLenum value, GLfloat * data);
GLEE_EXTERN PFNGLBEGINVERTEXSHADEREXTPROC pglBeginVertexShaderEXT;
GLEE_EXTERN PFNGLENDVERTEXSHADEREXTPROC pglEndVertexShaderEXT;
GLEE_EXTERN PFNGLBINDVERTEXSHADEREXTPROC pglBindVertexShaderEXT;
GLEE_EXTERN PFNGLGENVERTEXSHADERSEXTPROC pglGenVertexShadersEXT;
GLEE_EXTERN PFNGLDELETEVERTEXSHADEREXTPROC pglDeleteVertexShaderEXT;
GLEE_EXTERN PFNGLSHADEROP1EXTPROC pglShaderOp1EXT;
GLEE_EXTERN PFNGLSHADEROP2EXTPROC pglShaderOp2EXT;
GLEE_EXTERN PFNGLSHADEROP3EXTPROC pglShaderOp3EXT;
GLEE_EXTERN PFNGLSWIZZLEEXTPROC pglSwizzleEXT;
GLEE_EXTERN PFNGLWRITEMASKEXTPROC pglWriteMaskEXT;
GLEE_EXTERN PFNGLINSERTCOMPONENTEXTPROC pglInsertComponentEXT;
GLEE_EXTERN PFNGLEXTRACTCOMPONENTEXTPROC pglExtractComponentEXT;
GLEE_EXTERN PFNGLGENSYMBOLSEXTPROC pglGenSymbolsEXT;
GLEE_EXTERN PFNGLSETINVARIANTEXTPROC pglSetInvariantEXT;
GLEE_EXTERN PFNGLSETLOCALCONSTANTEXTPROC pglSetLocalConstantEXT;
GLEE_EXTERN PFNGLVARIANTBVEXTPROC pglVariantbvEXT;
GLEE_EXTERN PFNGLVARIANTSVEXTPROC pglVariantsvEXT;
GLEE_EXTERN PFNGLVARIANTIVEXTPROC pglVariantivEXT;
GLEE_EXTERN PFNGLVARIANTFVEXTPROC pglVariantfvEXT;
GLEE_EXTERN PFNGLVARIANTDVEXTPROC pglVariantdvEXT;
GLEE_EXTERN PFNGLVARIANTUBVEXTPROC pglVariantubvEXT;
GLEE_EXTERN PFNGLVARIANTUSVEXTPROC pglVariantusvEXT;
GLEE_EXTERN PFNGLVARIANTUIVEXTPROC pglVariantuivEXT;
GLEE_EXTERN PFNGLVARIANTPOINTEREXTPROC pglVariantPointerEXT;
GLEE_EXTERN PFNGLENABLEVARIANTCLIENTSTATEEXTPROC pglEnableVariantClientStateEXT;
GLEE_EXTERN PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC pglDisableVariantClientStateEXT;
GLEE_EXTERN PFNGLBINDLIGHTPARAMETEREXTPROC pglBindLightParameterEXT;
GLEE_EXTERN PFNGLBINDMATERIALPARAMETEREXTPROC pglBindMaterialParameterEXT;
GLEE_EXTERN PFNGLBINDTEXGENPARAMETEREXTPROC pglBindTexGenParameterEXT;
GLEE_EXTERN PFNGLBINDTEXTUREUNITPARAMETEREXTPROC pglBindTextureUnitParameterEXT;
GLEE_EXTERN PFNGLBINDPARAMETEREXTPROC pglBindParameterEXT;
GLEE_EXTERN PFNGLISVARIANTENABLEDEXTPROC pglIsVariantEnabledEXT;
GLEE_EXTERN PFNGLGETVARIANTBOOLEANVEXTPROC pglGetVariantBooleanvEXT;
GLEE_EXTERN PFNGLGETVARIANTINTEGERVEXTPROC pglGetVariantIntegervEXT;
GLEE_EXTERN PFNGLGETVARIANTFLOATVEXTPROC pglGetVariantFloatvEXT;
GLEE_EXTERN PFNGLGETVARIANTPOINTERVEXTPROC pglGetVariantPointervEXT;
GLEE_EXTERN PFNGLGETINVARIANTBOOLEANVEXTPROC pglGetInvariantBooleanvEXT;
GLEE_EXTERN PFNGLGETINVARIANTINTEGERVEXTPROC pglGetInvariantIntegervEXT;
GLEE_EXTERN PFNGLGETINVARIANTFLOATVEXTPROC pglGetInvariantFloatvEXT;
GLEE_EXTERN PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC pglGetLocalConstantBooleanvEXT;
GLEE_EXTERN PFNGLGETLOCALCONSTANTINTEGERVEXTPROC pglGetLocalConstantIntegervEXT;
GLEE_EXTERN PFNGLGETLOCALCONSTANTFLOATVEXTPROC pglGetLocalConstantFloatvEXT;
#define glBeginVertexShaderEXT pglBeginVertexShaderEXT
#define glEndVertexShaderEXT pglEndVertexShaderEXT
#define glBindVertexShaderEXT pglBindVertexShaderEXT
#define glGenVertexShadersEXT pglGenVertexShadersEXT
#define glDeleteVertexShaderEXT pglDeleteVertexShaderEXT
#define glShaderOp1EXT pglShaderOp1EXT
#define glShaderOp2EXT pglShaderOp2EXT
#define glShaderOp3EXT pglShaderOp3EXT
#define glSwizzleEXT pglSwizzleEXT
#define glWriteMaskEXT pglWriteMaskEXT
#define glInsertComponentEXT pglInsertComponentEXT
#define glExtractComponentEXT pglExtractComponentEXT
#define glGenSymbolsEXT pglGenSymbolsEXT
#define glSetInvariantEXT pglSetInvariantEXT
#define glSetLocalConstantEXT pglSetLocalConstantEXT
#define glVariantbvEXT pglVariantbvEXT
#define glVariantsvEXT pglVariantsvEXT
#define glVariantivEXT pglVariantivEXT
#define glVariantfvEXT pglVariantfvEXT
#define glVariantdvEXT pglVariantdvEXT
#define glVariantubvEXT pglVariantubvEXT
#define glVariantusvEXT pglVariantusvEXT
#define glVariantuivEXT pglVariantuivEXT
#define glVariantPointerEXT pglVariantPointerEXT
#define glEnableVariantClientStateEXT pglEnableVariantClientStateEXT
#define glDisableVariantClientStateEXT pglDisableVariantClientStateEXT
#define glBindLightParameterEXT pglBindLightParameterEXT
#define glBindMaterialParameterEXT pglBindMaterialParameterEXT
#define glBindTexGenParameterEXT pglBindTexGenParameterEXT
#define glBindTextureUnitParameterEXT pglBindTextureUnitParameterEXT
#define glBindParameterEXT pglBindParameterEXT
#define glIsVariantEnabledEXT pglIsVariantEnabledEXT
#define glGetVariantBooleanvEXT pglGetVariantBooleanvEXT
#define glGetVariantIntegervEXT pglGetVariantIntegervEXT
#define glGetVariantFloatvEXT pglGetVariantFloatvEXT
#define glGetVariantPointervEXT pglGetVariantPointervEXT
#define glGetInvariantBooleanvEXT pglGetInvariantBooleanvEXT
#define glGetInvariantIntegervEXT pglGetInvariantIntegervEXT
#define glGetInvariantFloatvEXT pglGetInvariantFloatvEXT
#define glGetLocalConstantBooleanvEXT pglGetLocalConstantBooleanvEXT
#define glGetLocalConstantIntegervEXT pglGetLocalConstantIntegervEXT
#define glGetLocalConstantFloatvEXT pglGetLocalConstantFloatvEXT
#endif 

/* GL_ATI_vertex_streams */

#ifndef GL_ATI_vertex_streams
#define GL_ATI_vertex_streams 1
#define __GLEE_GL_ATI_vertex_streams 1
/* Constants */
#define GL_MAX_VERTEX_STREAMS_ATI                          0x876B
#define GL_VERTEX_STREAM0_ATI                              0x876C
#define GL_VERTEX_STREAM1_ATI                              0x876D
#define GL_VERTEX_STREAM2_ATI                              0x876E
#define GL_VERTEX_STREAM3_ATI                              0x876F
#define GL_VERTEX_STREAM4_ATI                              0x8770
#define GL_VERTEX_STREAM5_ATI                              0x8771
#define GL_VERTEX_STREAM6_ATI                              0x8772
#define GL_VERTEX_STREAM7_ATI                              0x8773
#define GL_VERTEX_SOURCE_ATI                               0x8774
typedef void (APIENTRYP PFNGLVERTEXSTREAM1SATIPROC) (GLenum stream, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1SVATIPROC) (GLenum stream, const GLshort * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1IATIPROC) (GLenum stream, GLint x);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1IVATIPROC) (GLenum stream, const GLint * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1FATIPROC) (GLenum stream, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1FVATIPROC) (GLenum stream, const GLfloat * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1DATIPROC) (GLenum stream, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1DVATIPROC) (GLenum stream, const GLdouble * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2SATIPROC) (GLenum stream, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2SVATIPROC) (GLenum stream, const GLshort * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2IATIPROC) (GLenum stream, GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2IVATIPROC) (GLenum stream, const GLint * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2FATIPROC) (GLenum stream, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2FVATIPROC) (GLenum stream, const GLfloat * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2DATIPROC) (GLenum stream, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2DVATIPROC) (GLenum stream, const GLdouble * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3SATIPROC) (GLenum stream, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3SVATIPROC) (GLenum stream, const GLshort * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3IATIPROC) (GLenum stream, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3IVATIPROC) (GLenum stream, const GLint * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3FATIPROC) (GLenum stream, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3FVATIPROC) (GLenum stream, const GLfloat * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3DATIPROC) (GLenum stream, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3DVATIPROC) (GLenum stream, const GLdouble * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4SATIPROC) (GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4SVATIPROC) (GLenum stream, const GLshort * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4IATIPROC) (GLenum stream, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4IVATIPROC) (GLenum stream, const GLint * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4FATIPROC) (GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4FVATIPROC) (GLenum stream, const GLfloat * coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4DATIPROC) (GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4DVATIPROC) (GLenum stream, const GLdouble * coords);
typedef void (APIENTRYP PFNGLNORMALSTREAM3BATIPROC) (GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
typedef void (APIENTRYP PFNGLNORMALSTREAM3BVATIPROC) (GLenum stream, const GLbyte * coords);
typedef void (APIENTRYP PFNGLNORMALSTREAM3SATIPROC) (GLenum stream, GLshort nx, GLshort ny, GLshort nz);
typedef void (APIENTRYP PFNGLNORMALSTREAM3SVATIPROC) (GLenum stream, const GLshort * coords);
typedef void (APIENTRYP PFNGLNORMALSTREAM3IATIPROC) (GLenum stream, GLint nx, GLint ny, GLint nz);
typedef void (APIENTRYP PFNGLNORMALSTREAM3IVATIPROC) (GLenum stream, const GLint * coords);
typedef void (APIENTRYP PFNGLNORMALSTREAM3FATIPROC) (GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
typedef void (APIENTRYP PFNGLNORMALSTREAM3FVATIPROC) (GLenum stream, const GLfloat * coords);
typedef void (APIENTRYP PFNGLNORMALSTREAM3DATIPROC) (GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
typedef void (APIENTRYP PFNGLNORMALSTREAM3DVATIPROC) (GLenum stream, const GLdouble * coords);
typedef void (APIENTRYP PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC) (GLenum stream);
typedef void (APIENTRYP PFNGLVERTEXBLENDENVIATIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLVERTEXBLENDENVFATIPROC) (GLenum pname, GLfloat param);
GLEE_EXTERN PFNGLVERTEXSTREAM1SATIPROC pglVertexStream1sATI;
GLEE_EXTERN PFNGLVERTEXSTREAM1SVATIPROC pglVertexStream1svATI;
GLEE_EXTERN PFNGLVERTEXSTREAM1IATIPROC pglVertexStream1iATI;
GLEE_EXTERN PFNGLVERTEXSTREAM1IVATIPROC pglVertexStream1ivATI;
GLEE_EXTERN PFNGLVERTEXSTREAM1FATIPROC pglVertexStream1fATI;
GLEE_EXTERN PFNGLVERTEXSTREAM1FVATIPROC pglVertexStream1fvATI;
GLEE_EXTERN PFNGLVERTEXSTREAM1DATIPROC pglVertexStream1dATI;
GLEE_EXTERN PFNGLVERTEXSTREAM1DVATIPROC pglVertexStream1dvATI;
GLEE_EXTERN PFNGLVERTEXSTREAM2SATIPROC pglVertexStream2sATI;
GLEE_EXTERN PFNGLVERTEXSTREAM2SVATIPROC pglVertexStream2svATI;
GLEE_EXTERN PFNGLVERTEXSTREAM2IATIPROC pglVertexStream2iATI;
GLEE_EXTERN PFNGLVERTEXSTREAM2IVATIPROC pglVertexStream2ivATI;
GLEE_EXTERN PFNGLVERTEXSTREAM2FATIPROC pglVertexStream2fATI;
GLEE_EXTERN PFNGLVERTEXSTREAM2FVATIPROC pglVertexStream2fvATI;
GLEE_EXTERN PFNGLVERTEXSTREAM2DATIPROC pglVertexStream2dATI;
GLEE_EXTERN PFNGLVERTEXSTREAM2DVATIPROC pglVertexStream2dvATI;
GLEE_EXTERN PFNGLVERTEXSTREAM3SATIPROC pglVertexStream3sATI;
GLEE_EXTERN PFNGLVERTEXSTREAM3SVATIPROC pglVertexStream3svATI;
GLEE_EXTERN PFNGLVERTEXSTREAM3IATIPROC pglVertexStream3iATI;
GLEE_EXTERN PFNGLVERTEXSTREAM3IVATIPROC pglVertexStream3ivATI;
GLEE_EXTERN PFNGLVERTEXSTREAM3FATIPROC pglVertexStream3fATI;
GLEE_EXTERN PFNGLVERTEXSTREAM3FVATIPROC pglVertexStream3fvATI;
GLEE_EXTERN PFNGLVERTEXSTREAM3DATIPROC pglVertexStream3dATI;
GLEE_EXTERN PFNGLVERTEXSTREAM3DVATIPROC pglVertexStream3dvATI;
GLEE_EXTERN PFNGLVERTEXSTREAM4SATIPROC pglVertexStream4sATI;
GLEE_EXTERN PFNGLVERTEXSTREAM4SVATIPROC pglVertexStream4svATI;
GLEE_EXTERN PFNGLVERTEXSTREAM4IATIPROC pglVertexStream4iATI;
GLEE_EXTERN PFNGLVERTEXSTREAM4IVATIPROC pglVertexStream4ivATI;
GLEE_EXTERN PFNGLVERTEXSTREAM4FATIPROC pglVertexStream4fATI;
GLEE_EXTERN PFNGLVERTEXSTREAM4FVATIPROC pglVertexStream4fvATI;
GLEE_EXTERN PFNGLVERTEXSTREAM4DATIPROC pglVertexStream4dATI;
GLEE_EXTERN PFNGLVERTEXSTREAM4DVATIPROC pglVertexStream4dvATI;
GLEE_EXTERN PFNGLNORMALSTREAM3BATIPROC pglNormalStream3bATI;
GLEE_EXTERN PFNGLNORMALSTREAM3BVATIPROC pglNormalStream3bvATI;
GLEE_EXTERN PFNGLNORMALSTREAM3SATIPROC pglNormalStream3sATI;
GLEE_EXTERN PFNGLNORMALSTREAM3SVATIPROC pglNormalStream3svATI;
GLEE_EXTERN PFNGLNORMALSTREAM3IATIPROC pglNormalStream3iATI;
GLEE_EXTERN PFNGLNORMALSTREAM3IVATIPROC pglNormalStream3ivATI;
GLEE_EXTERN PFNGLNORMALSTREAM3FATIPROC pglNormalStream3fATI;
GLEE_EXTERN PFNGLNORMALSTREAM3FVATIPROC pglNormalStream3fvATI;
GLEE_EXTERN PFNGLNORMALSTREAM3DATIPROC pglNormalStream3dATI;
GLEE_EXTERN PFNGLNORMALSTREAM3DVATIPROC pglNormalStream3dvATI;
GLEE_EXTERN PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC pglClientActiveVertexStreamATI;
GLEE_EXTERN PFNGLVERTEXBLENDENVIATIPROC pglVertexBlendEnviATI;
GLEE_EXTERN PFNGLVERTEXBLENDENVFATIPROC pglVertexBlendEnvfATI;
#define glVertexStream1sATI pglVertexStream1sATI
#define glVertexStream1svATI pglVertexStream1svATI
#define glVertexStream1iATI pglVertexStream1iATI
#define glVertexStream1ivATI pglVertexStream1ivATI
#define glVertexStream1fATI pglVertexStream1fATI
#define glVertexStream1fvATI pglVertexStream1fvATI
#define glVertexStream1dATI pglVertexStream1dATI
#define glVertexStream1dvATI pglVertexStream1dvATI
#define glVertexStream2sATI pglVertexStream2sATI
#define glVertexStream2svATI pglVertexStream2svATI
#define glVertexStream2iATI pglVertexStream2iATI
#define glVertexStream2ivATI pglVertexStream2ivATI
#define glVertexStream2fATI pglVertexStream2fATI
#define glVertexStream2fvATI pglVertexStream2fvATI
#define glVertexStream2dATI pglVertexStream2dATI
#define glVertexStream2dvATI pglVertexStream2dvATI
#define glVertexStream3sATI pglVertexStream3sATI
#define glVertexStream3svATI pglVertexStream3svATI
#define glVertexStream3iATI pglVertexStream3iATI
#define glVertexStream3ivATI pglVertexStream3ivATI
#define glVertexStream3fATI pglVertexStream3fATI
#define glVertexStream3fvATI pglVertexStream3fvATI
#define glVertexStream3dATI pglVertexStream3dATI
#define glVertexStream3dvATI pglVertexStream3dvATI
#define glVertexStream4sATI pglVertexStream4sATI
#define glVertexStream4svATI pglVertexStream4svATI
#define glVertexStream4iATI pglVertexStream4iATI
#define glVertexStream4ivATI pglVertexStream4ivATI
#define glVertexStream4fATI pglVertexStream4fATI
#define glVertexStream4fvATI pglVertexStream4fvATI
#define glVertexStream4dATI pglVertexStream4dATI
#define glVertexStream4dvATI pglVertexStream4dvATI
#define glNormalStream3bATI pglNormalStream3bATI
#define glNormalStream3bvATI pglNormalStream3bvATI
#define glNormalStream3sATI pglNormalStream3sATI
#define glNormalStream3svATI pglNormalStream3svATI
#define glNormalStream3iATI pglNormalStream3iATI
#define glNormalStream3ivATI pglNormalStream3ivATI
#define glNormalStream3fATI pglNormalStream3fATI
#define glNormalStream3fvATI pglNormalStream3fvATI
#define glNormalStream3dATI pglNormalStream3dATI
#define glNormalStream3dvATI pglNormalStream3dvATI
#define glClientActiveVertexStreamATI pglClientActiveVertexStreamATI
#define glVertexBlendEnviATI pglVertexBlendEnviATI
#define glVertexBlendEnvfATI pglVertexBlendEnvfATI
#endif 

/* GL_ATI_element_array */

#ifndef GL_ATI_element_array
#define GL_ATI_element_array 1
#define __GLEE_GL_ATI_element_array 1
/* Constants */
#define GL_ELEMENT_ARRAY_ATI                               0x8768
#define GL_ELEMENT_ARRAY_TYPE_ATI                          0x8769
#define GL_ELEMENT_ARRAY_POINTER_ATI                       0x876A
typedef void (APIENTRYP PFNGLELEMENTPOINTERATIPROC) (GLenum type, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLDRAWELEMENTARRAYATIPROC) (GLenum mode, GLsizei count);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTARRAYATIPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count);
GLEE_EXTERN PFNGLELEMENTPOINTERATIPROC pglElementPointerATI;
GLEE_EXTERN PFNGLDRAWELEMENTARRAYATIPROC pglDrawElementArrayATI;
GLEE_EXTERN PFNGLDRAWRANGEELEMENTARRAYATIPROC pglDrawRangeElementArrayATI;
#define glElementPointerATI pglElementPointerATI
#define glDrawElementArrayATI pglDrawElementArrayATI
#define glDrawRangeElementArrayATI pglDrawRangeElementArrayATI
#endif 

/* GL_SUN_mesh_array */

#ifndef GL_SUN_mesh_array
#define GL_SUN_mesh_array 1
#define __GLEE_GL_SUN_mesh_array 1
/* Constants */
#define GL_QUAD_MESH_SUN                                   0x8614
#define GL_TRIANGLE_MESH_SUN                               0x8615
typedef void (APIENTRYP PFNGLDRAWMESHARRAYSSUNPROC) (GLenum mode, GLint first, GLsizei count, GLsizei width);
GLEE_EXTERN PFNGLDRAWMESHARRAYSSUNPROC pglDrawMeshArraysSUN;
#define glDrawMeshArraysSUN pglDrawMeshArraysSUN
#endif 

/* GL_SUN_slice_accum */

#ifndef GL_SUN_slice_accum
#define GL_SUN_slice_accum 1
#define __GLEE_GL_SUN_slice_accum 1
/* Constants */
#define GL_SLICE_ACCUM_SUN                                 0x85CC
#endif 

/* GL_NV_multisample_filter_hint */

#ifndef GL_NV_multisample_filter_hint
#define GL_NV_multisample_filter_hint 1
#define __GLEE_GL_NV_multisample_filter_hint 1
/* Constants */
#define GL_MULTISAMPLE_FILTER_HINT_NV                      0x8534
#endif 

/* GL_NV_depth_clamp */

#ifndef GL_NV_depth_clamp
#define GL_NV_depth_clamp 1
#define __GLEE_GL_NV_depth_clamp 1
/* Constants */
#define GL_DEPTH_CLAMP_NV                                  0x864F
#endif 

/* GL_NV_occlusion_query */

#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query 1
#define __GLEE_GL_NV_occlusion_query 1
/* Constants */
#define GL_PIXEL_COUNTER_BITS_NV                           0x8864
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV                   0x8865
#define GL_PIXEL_COUNT_NV                                  0x8866
#define GL_PIXEL_COUNT_AVAILABLE_NV                        0x8867
typedef void (APIENTRYP PFNGLGENOCCLUSIONQUERIESNVPROC) (GLsizei n, GLuint * ids);
typedef void (APIENTRYP PFNGLDELETEOCCLUSIONQUERIESNVPROC) (GLsizei n, const GLuint * ids);
typedef GLboolean (APIENTRYP PFNGLISOCCLUSIONQUERYNVPROC) (GLuint id);
typedef void (APIENTRYP PFNGLBEGINOCCLUSIONQUERYNVPROC) (GLuint id);
typedef void (APIENTRYP PFNGLENDOCCLUSIONQUERYNVPROC) ();
typedef void (APIENTRYP PFNGLGETOCCLUSIONQUERYIVNVPROC) (GLuint id, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETOCCLUSIONQUERYUIVNVPROC) (GLuint id, GLenum pname, GLuint * params);
GLEE_EXTERN PFNGLGENOCCLUSIONQUERIESNVPROC pglGenOcclusionQueriesNV;
GLEE_EXTERN PFNGLDELETEOCCLUSIONQUERIESNVPROC pglDeleteOcclusionQueriesNV;
GLEE_EXTERN PFNGLISOCCLUSIONQUERYNVPROC pglIsOcclusionQueryNV;
GLEE_EXTERN PFNGLBEGINOCCLUSIONQUERYNVPROC pglBeginOcclusionQueryNV;
GLEE_EXTERN PFNGLENDOCCLUSIONQUERYNVPROC pglEndOcclusionQueryNV;
GLEE_EXTERN PFNGLGETOCCLUSIONQUERYIVNVPROC pglGetOcclusionQueryivNV;
GLEE_EXTERN PFNGLGETOCCLUSIONQUERYUIVNVPROC pglGetOcclusionQueryuivNV;
#define glGenOcclusionQueriesNV pglGenOcclusionQueriesNV
#define glDeleteOcclusionQueriesNV pglDeleteOcclusionQueriesNV
#define glIsOcclusionQueryNV pglIsOcclusionQueryNV
#define glBeginOcclusionQueryNV pglBeginOcclusionQueryNV
#define glEndOcclusionQueryNV pglEndOcclusionQueryNV
#define glGetOcclusionQueryivNV pglGetOcclusionQueryivNV
#define glGetOcclusionQueryuivNV pglGetOcclusionQueryuivNV
#endif 

/* GL_NV_point_sprite */

#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite 1
#define __GLEE_GL_NV_point_sprite 1
/* Constants */
#define GL_POINT_SPRITE_NV                                 0x8861
#define GL_COORD_REPLACE_NV                                0x8862
#define GL_POINT_SPRITE_R_MODE_NV                          0x8863
typedef void (APIENTRYP PFNGLPOINTPARAMETERINVPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVNVPROC) (GLenum pname, const GLint * params);
GLEE_EXTERN PFNGLPOINTPARAMETERINVPROC pglPointParameteriNV;
GLEE_EXTERN PFNGLPOINTPARAMETERIVNVPROC pglPointParameterivNV;
#define glPointParameteriNV pglPointParameteriNV
#define glPointParameterivNV pglPointParameterivNV
#endif 

/* GL_NV_texture_shader3 */

#ifndef GL_NV_texture_shader3
#define GL_NV_texture_shader3 1
#define __GLEE_GL_NV_texture_shader3 1
/* Constants */
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV                 0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV           0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV          0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV    0x8853
#define GL_OFFSET_HILO_TEXTURE_2D_NV                       0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV                0x8855
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV            0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV     0x8857
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV                    0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV                     0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV               0x885A
#define GL_DOT_PRODUCT_PASS_THROUGH_NV                     0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV                       0x885C
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV             0x885D
#define GL_HILO8_NV                                        0x885E
#define GL_SIGNED_HILO8_NV                                 0x885F
#define GL_FORCE_BLUE_TO_ONE_NV                            0x8860
#endif 

/* GL_NV_vertex_program1_1 */

#ifndef GL_NV_vertex_program1_1
#define GL_NV_vertex_program1_1 1
#define __GLEE_GL_NV_vertex_program1_1 1
/* Constants */
#endif 

/* GL_EXT_shadow_funcs */

#ifndef GL_EXT_shadow_funcs
#define GL_EXT_shadow_funcs 1
#define __GLEE_GL_EXT_shadow_funcs 1
/* Constants */
#endif 

/* GL_EXT_stencil_two_side */

#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side 1
#define __GLEE_GL_EXT_stencil_two_side 1
/* Constants */
#define GL_STENCIL_TEST_TWO_SIDE_EXT                       0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT                         0x8911
typedef void (APIENTRYP PFNGLACTIVESTENCILFACEEXTPROC) (GLenum face);
GLEE_EXTERN PFNGLACTIVESTENCILFACEEXTPROC pglActiveStencilFaceEXT;
#define glActiveStencilFaceEXT pglActiveStencilFaceEXT
#endif 

/* GL_ATI_text_fragment_shader */

#ifndef GL_ATI_text_fragment_shader
#define GL_ATI_text_fragment_shader 1
#define __GLEE_GL_ATI_text_fragment_shader 1
/* Constants */
#define GL_TEXT_FRAGMENT_SHADER_ATI                        0x8200
#endif 

/* GL_APPLE_client_storage */

#ifndef GL_APPLE_client_storage
#define GL_APPLE_client_storage 1
#define __GLEE_GL_APPLE_client_storage 1
/* Constants */
#define GL_UNPACK_CLIENT_STORAGE_APPLE                     0x85B2
#endif 

/* GL_APPLE_element_array */

#ifndef GL_APPLE_element_array
#define GL_APPLE_element_array 1
#define __GLEE_GL_APPLE_element_array 1
/* Constants */
#define GL_ELEMENT_ARRAY_APPLE                             0x8768
#define GL_ELEMENT_ARRAY_TYPE_APPLE                        0x8769
#define GL_ELEMENT_ARRAY_POINTER_APPLE                     0x876A
typedef void (APIENTRYP PFNGLELEMENTPOINTERAPPLEPROC) (GLenum type, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLDRAWELEMENTARRAYAPPLEPROC) (GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC) (GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC) (GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount);
typedef void (APIENTRYP PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC) (GLenum mode, GLuint start, GLuint end, const GLint * first, const GLsizei * count, GLsizei primcount);
GLEE_EXTERN PFNGLELEMENTPOINTERAPPLEPROC pglElementPointerAPPLE;
GLEE_EXTERN PFNGLDRAWELEMENTARRAYAPPLEPROC pglDrawElementArrayAPPLE;
GLEE_EXTERN PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC pglDrawRangeElementArrayAPPLE;
GLEE_EXTERN PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC pglMultiDrawElementArrayAPPLE;
GLEE_EXTERN PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC pglMultiDrawRangeElementArrayAPPLE;
#define glElementPointerAPPLE pglElementPointerAPPLE
#define glDrawElementArrayAPPLE pglDrawElementArrayAPPLE
#define glDrawRangeElementArrayAPPLE pglDrawRangeElementArrayAPPLE
#define glMultiDrawElementArrayAPPLE pglMultiDrawElementArrayAPPLE
#define glMultiDrawRangeElementArrayAPPLE pglMultiDrawRangeElementArrayAPPLE
#endif 

/* GL_APPLE_fence */

#ifndef GL_APPLE_fence
#define GL_APPLE_fence 1
#define __GLEE_GL_APPLE_fence 1
/* Constants */
#define GL_DRAW_PIXELS_APPLE                               0x8A0A
#define GL_FENCE_APPLE                                     0x8A0B
typedef void (APIENTRYP PFNGLGENFENCESAPPLEPROC) (GLsizei n, GLuint * fences);
typedef void (APIENTRYP PFNGLDELETEFENCESAPPLEPROC) (GLsizei n, const GLuint * fences);
typedef void (APIENTRYP PFNGLSETFENCEAPPLEPROC) (GLuint fence);
typedef GLboolean (APIENTRYP PFNGLISFENCEAPPLEPROC) (GLuint fence);
typedef GLboolean (APIENTRYP PFNGLTESTFENCEAPPLEPROC) (GLuint fence);
typedef void (APIENTRYP PFNGLFINISHFENCEAPPLEPROC) (GLuint fence);
typedef GLboolean (APIENTRYP PFNGLTESTOBJECTAPPLEPROC) (GLenum object, GLuint name);
typedef void (APIENTRYP PFNGLFINISHOBJECTAPPLEPROC) (GLenum object, GLint name);
GLEE_EXTERN PFNGLGENFENCESAPPLEPROC pglGenFencesAPPLE;
GLEE_EXTERN PFNGLDELETEFENCESAPPLEPROC pglDeleteFencesAPPLE;
GLEE_EXTERN PFNGLSETFENCEAPPLEPROC pglSetFenceAPPLE;
GLEE_EXTERN PFNGLISFENCEAPPLEPROC pglIsFenceAPPLE;
GLEE_EXTERN PFNGLTESTFENCEAPPLEPROC pglTestFenceAPPLE;
GLEE_EXTERN PFNGLFINISHFENCEAPPLEPROC pglFinishFenceAPPLE;
GLEE_EXTERN PFNGLTESTOBJECTAPPLEPROC pglTestObjectAPPLE;
GLEE_EXTERN PFNGLFINISHOBJECTAPPLEPROC pglFinishObjectAPPLE;
#define glGenFencesAPPLE pglGenFencesAPPLE
#define glDeleteFencesAPPLE pglDeleteFencesAPPLE
#define glSetFenceAPPLE pglSetFenceAPPLE
#define glIsFenceAPPLE pglIsFenceAPPLE
#define glTestFenceAPPLE pglTestFenceAPPLE
#define glFinishFenceAPPLE pglFinishFenceAPPLE
#define glTestObjectAPPLE pglTestObjectAPPLE
#define glFinishObjectAPPLE pglFinishObjectAPPLE
#endif 

/* GL_APPLE_vertex_array_object */

#ifndef GL_APPLE_vertex_array_object
#define GL_APPLE_vertex_array_object 1
#define __GLEE_GL_APPLE_vertex_array_object 1
/* Constants */
#define GL_VERTEX_ARRAY_BINDING_APPLE                      0x85B5
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYAPPLEPROC) (GLuint array);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSAPPLEPROC) (GLsizei n, const GLuint * arrays);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSAPPLEPROC) (GLsizei n, const GLuint * arrays);
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYAPPLEPROC) (GLuint array);
GLEE_EXTERN PFNGLBINDVERTEXARRAYAPPLEPROC pglBindVertexArrayAPPLE;
GLEE_EXTERN PFNGLDELETEVERTEXARRAYSAPPLEPROC pglDeleteVertexArraysAPPLE;
GLEE_EXTERN PFNGLGENVERTEXARRAYSAPPLEPROC pglGenVertexArraysAPPLE;
GLEE_EXTERN PFNGLISVERTEXARRAYAPPLEPROC pglIsVertexArrayAPPLE;
#define glBindVertexArrayAPPLE pglBindVertexArrayAPPLE
#define glDeleteVertexArraysAPPLE pglDeleteVertexArraysAPPLE
#define glGenVertexArraysAPPLE pglGenVertexArraysAPPLE
#define glIsVertexArrayAPPLE pglIsVertexArrayAPPLE
#endif 

/* GL_APPLE_vertex_array_range */

#ifndef GL_APPLE_vertex_array_range
#define GL_APPLE_vertex_array_range 1
#define __GLEE_GL_APPLE_vertex_array_range 1
/* Constants */
#define GL_VERTEX_ARRAY_RANGE_APPLE                        0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE                 0x851E
#define GL_VERTEX_ARRAY_STORAGE_HINT_APPLE                 0x851F
#define GL_VERTEX_ARRAY_RANGE_POINTER_APPLE                0x8521
#define GL_STORAGE_CACHED_APPLE                            0x85BE
#define GL_STORAGE_SHARED_APPLE                            0x85BF
typedef void (APIENTRYP PFNGLVERTEXARRAYRANGEAPPLEPROC) (GLsizei length, GLvoid * pointer);
typedef void (APIENTRYP PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC) (GLsizei length, GLvoid * pointer);
typedef void (APIENTRYP PFNGLVERTEXARRAYPARAMETERIAPPLEPROC) (GLenum pname, GLint param);
GLEE_EXTERN PFNGLVERTEXARRAYRANGEAPPLEPROC pglVertexArrayRangeAPPLE;
GLEE_EXTERN PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC pglFlushVertexArrayRangeAPPLE;
GLEE_EXTERN PFNGLVERTEXARRAYPARAMETERIAPPLEPROC pglVertexArrayParameteriAPPLE;
#define glVertexArrayRangeAPPLE pglVertexArrayRangeAPPLE
#define glFlushVertexArrayRangeAPPLE pglFlushVertexArrayRangeAPPLE
#define glVertexArrayParameteriAPPLE pglVertexArrayParameteriAPPLE
#endif 

/* GL_APPLE_ycbcr_422 */

#ifndef GL_APPLE_ycbcr_422
#define GL_APPLE_ycbcr_422 1
#define __GLEE_GL_APPLE_ycbcr_422 1
/* Constants */
#define GL_YCBCR_422_APPLE                                 0x85B9
#define GL_UNSIGNED_SHORT_8_8_APPLE                        0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE                    0x85BB
#endif 

/* GL_S3_s3tc */

#ifndef GL_S3_s3tc
#define GL_S3_s3tc 1
#define __GLEE_GL_S3_s3tc 1
/* Constants */
#define GL_RGB_S3TC                                        0x83A0
#define GL_RGB4_S3TC                                       0x83A1
#define GL_RGBA_S3TC                                       0x83A2
#define GL_RGBA4_S3TC                                      0x83A3
#endif 

/* GL_ATI_draw_buffers */

#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers 1
#define __GLEE_GL_ATI_draw_buffers 1
/* Constants */
#define GL_MAX_DRAW_BUFFERS_ATI                            0x8824
#define GL_DRAW_BUFFER0_ATI                                0x8825
#define GL_DRAW_BUFFER1_ATI                                0x8826
#define GL_DRAW_BUFFER2_ATI                                0x8827
#define GL_DRAW_BUFFER3_ATI                                0x8828
#define GL_DRAW_BUFFER4_ATI                                0x8829
#define GL_DRAW_BUFFER5_ATI                                0x882A
#define GL_DRAW_BUFFER6_ATI                                0x882B
#define GL_DRAW_BUFFER7_ATI                                0x882C
#define GL_DRAW_BUFFER8_ATI                                0x882D
#define GL_DRAW_BUFFER9_ATI                                0x882E
#define GL_DRAW_BUFFER10_ATI                               0x882F
#define GL_DRAW_BUFFER11_ATI                               0x8830
#define GL_DRAW_BUFFER12_ATI                               0x8831
#define GL_DRAW_BUFFER13_ATI                               0x8832
#define GL_DRAW_BUFFER14_ATI                               0x8833
#define GL_DRAW_BUFFER15_ATI                               0x8834
typedef void (APIENTRYP PFNGLDRAWBUFFERSATIPROC) (GLsizei n, const GLenum * bufs);
GLEE_EXTERN PFNGLDRAWBUFFERSATIPROC pglDrawBuffersATI;
#define glDrawBuffersATI pglDrawBuffersATI
#endif 

/* GL_ATI_pixel_format_float */

#ifndef GL_ATI_pixel_format_float
#define GL_ATI_pixel_format_float 1
#define __GLEE_GL_ATI_pixel_format_float 1
/* Constants */
#define GL_TYPE_RGBA_FLOAT_ATI                             0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI                 0x8835
#endif 

/* GL_ATI_texture_env_combine3 */

#ifndef GL_ATI_texture_env_combine3
#define GL_ATI_texture_env_combine3 1
#define __GLEE_GL_ATI_texture_env_combine3 1
/* Constants */
#define GL_MODULATE_ADD_ATI                                0x8744
#define GL_MODULATE_SIGNED_ADD_ATI                         0x8745
#define GL_MODULATE_SUBTRACT_ATI                           0x8746
#endif 

/* GL_ATI_texture_float */

#ifndef GL_ATI_texture_float
#define GL_ATI_texture_float 1
#define __GLEE_GL_ATI_texture_float 1
/* Constants */
#define GL_RGBA_FLOAT32_ATI                                0x8814
#define GL_RGB_FLOAT32_ATI                                 0x8815
#define GL_ALPHA_FLOAT32_ATI                               0x8816
#define GL_INTENSITY_FLOAT32_ATI                           0x8817
#define GL_LUMINANCE_FLOAT32_ATI                           0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI                     0x8819
#define GL_RGBA_FLOAT16_ATI                                0x881A
#define GL_RGB_FLOAT16_ATI                                 0x881B
#define GL_ALPHA_FLOAT16_ATI                               0x881C
#define GL_INTENSITY_FLOAT16_ATI                           0x881D
#define GL_LUMINANCE_FLOAT16_ATI                           0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI                     0x881F
#endif 

/* GL_NV_float_buffer */

#ifndef GL_NV_float_buffer
#define GL_NV_float_buffer 1
#define __GLEE_GL_NV_float_buffer 1
/* Constants */
#define GL_FLOAT_R_NV                                      0x8880
#define GL_FLOAT_RG_NV                                     0x8881
#define GL_FLOAT_RGB_NV                                    0x8882
#define GL_FLOAT_RGBA_NV                                   0x8883
#define GL_FLOAT_R16_NV                                    0x8884
#define GL_FLOAT_R32_NV                                    0x8885
#define GL_FLOAT_RG16_NV                                   0x8886
#define GL_FLOAT_RG32_NV                                   0x8887
#define GL_FLOAT_RGB16_NV                                  0x8888
#define GL_FLOAT_RGB32_NV                                  0x8889
#define GL_FLOAT_RGBA16_NV                                 0x888A
#define GL_FLOAT_RGBA32_NV                                 0x888B
#define GL_TEXTURE_FLOAT_COMPONENTS_NV                     0x888C
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV                      0x888D
#define GL_FLOAT_RGBA_MODE_NV                              0x888E
#endif 

/* GL_NV_fragment_program */

#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program 1
#define __GLEE_GL_NV_fragment_program 1
/* Constants */
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV        0x8868
#define GL_FRAGMENT_PROGRAM_NV                             0x8870
#define GL_MAX_TEXTURE_COORDS_NV                           0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV                      0x8872
#define GL_FRAGMENT_PROGRAM_BINDING_NV                     0x8873
#define GL_PROGRAM_ERROR_STRING_NV                         0x8874
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4FNVPROC) (GLuint id, GLsizei len, const GLubyte * name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4DNVPROC) (GLuint id, GLsizei len, const GLubyte * name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC) (GLuint id, GLsizei len, const GLubyte * name, const GLfloat * v);
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC) (GLuint id, GLsizei len, const GLubyte * name, const GLdouble * v);
typedef void (APIENTRYP PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC) (GLuint id, GLsizei len, const GLubyte * name, GLfloat * params);
typedef void (APIENTRYP PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC) (GLuint id, GLsizei len, const GLubyte * name, GLdouble * params);
GLEE_EXTERN PFNGLPROGRAMNAMEDPARAMETER4FNVPROC pglProgramNamedParameter4fNV;
GLEE_EXTERN PFNGLPROGRAMNAMEDPARAMETER4DNVPROC pglProgramNamedParameter4dNV;
GLEE_EXTERN PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC pglProgramNamedParameter4fvNV;
GLEE_EXTERN PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC pglProgramNamedParameter4dvNV;
GLEE_EXTERN PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC pglGetProgramNamedParameterfvNV;
GLEE_EXTERN PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC pglGetProgramNamedParameterdvNV;
#define glProgramNamedParameter4fNV pglProgramNamedParameter4fNV
#define glProgramNamedParameter4dNV pglProgramNamedParameter4dNV
#define glProgramNamedParameter4fvNV pglProgramNamedParameter4fvNV
#define glProgramNamedParameter4dvNV pglProgramNamedParameter4dvNV
#define glGetProgramNamedParameterfvNV pglGetProgramNamedParameterfvNV
#define glGetProgramNamedParameterdvNV pglGetProgramNamedParameterdvNV
#endif 

/* GL_NV_half_float */

#ifndef GL_NV_half_float
#define GL_NV_half_float 1
#define __GLEE_GL_NV_half_float 1
/* Constants */
#define GL_HALF_FLOAT_NV                                   0x140B
typedef void (APIENTRYP PFNGLVERTEX2HNVPROC) (GLhalfNV x, GLhalfNV y);
typedef void (APIENTRYP PFNGLVERTEX2HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLVERTEX3HNVPROC) (GLhalfNV x, GLhalfNV y, GLhalfNV z);
typedef void (APIENTRYP PFNGLVERTEX3HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLVERTEX4HNVPROC) (GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
typedef void (APIENTRYP PFNGLVERTEX4HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLNORMAL3HNVPROC) (GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
typedef void (APIENTRYP PFNGLNORMAL3HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLCOLOR3HNVPROC) (GLhalfNV red, GLhalfNV green, GLhalfNV blue);
typedef void (APIENTRYP PFNGLCOLOR3HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLCOLOR4HNVPROC) (GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
typedef void (APIENTRYP PFNGLCOLOR4HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLTEXCOORD1HNVPROC) (GLhalfNV s);
typedef void (APIENTRYP PFNGLTEXCOORD1HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLTEXCOORD2HNVPROC) (GLhalfNV s, GLhalfNV t);
typedef void (APIENTRYP PFNGLTEXCOORD2HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLTEXCOORD3HNVPROC) (GLhalfNV s, GLhalfNV t, GLhalfNV r);
typedef void (APIENTRYP PFNGLTEXCOORD3HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLTEXCOORD4HNVPROC) (GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
typedef void (APIENTRYP PFNGLTEXCOORD4HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1HNVPROC) (GLenum target, GLhalfNV s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1HVNVPROC) (GLenum target, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2HNVPROC) (GLenum target, GLhalfNV s, GLhalfNV t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2HVNVPROC) (GLenum target, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3HNVPROC) (GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3HVNVPROC) (GLenum target, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4HNVPROC) (GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4HVNVPROC) (GLenum target, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLFOGCOORDHNVPROC) (GLhalfNV fog);
typedef void (APIENTRYP PFNGLFOGCOORDHVNVPROC) (const GLhalfNV * fog);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3HNVPROC) (GLhalfNV red, GLhalfNV green, GLhalfNV blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3HVNVPROC) (const GLhalfNV * v);
typedef void (APIENTRYP PFNGLVERTEXWEIGHTHNVPROC) (GLhalfNV weight);
typedef void (APIENTRYP PFNGLVERTEXWEIGHTHVNVPROC) (const GLhalfNV * weight);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1HNVPROC) (GLuint index, GLhalfNV x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1HVNVPROC) (GLuint index, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2HNVPROC) (GLuint index, GLhalfNV x, GLhalfNV y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2HVNVPROC) (GLuint index, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3HNVPROC) (GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3HVNVPROC) (GLuint index, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4HNVPROC) (GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4HVNVPROC) (GLuint index, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1HVNVPROC) (GLuint index, GLsizei n, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2HVNVPROC) (GLuint index, GLsizei n, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3HVNVPROC) (GLuint index, GLsizei n, const GLhalfNV * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4HVNVPROC) (GLuint index, GLsizei n, const GLhalfNV * v);
GLEE_EXTERN PFNGLVERTEX2HNVPROC pglVertex2hNV;
GLEE_EXTERN PFNGLVERTEX2HVNVPROC pglVertex2hvNV;
GLEE_EXTERN PFNGLVERTEX3HNVPROC pglVertex3hNV;
GLEE_EXTERN PFNGLVERTEX3HVNVPROC pglVertex3hvNV;
GLEE_EXTERN PFNGLVERTEX4HNVPROC pglVertex4hNV;
GLEE_EXTERN PFNGLVERTEX4HVNVPROC pglVertex4hvNV;
GLEE_EXTERN PFNGLNORMAL3HNVPROC pglNormal3hNV;
GLEE_EXTERN PFNGLNORMAL3HVNVPROC pglNormal3hvNV;
GLEE_EXTERN PFNGLCOLOR3HNVPROC pglColor3hNV;
GLEE_EXTERN PFNGLCOLOR3HVNVPROC pglColor3hvNV;
GLEE_EXTERN PFNGLCOLOR4HNVPROC pglColor4hNV;
GLEE_EXTERN PFNGLCOLOR4HVNVPROC pglColor4hvNV;
GLEE_EXTERN PFNGLTEXCOORD1HNVPROC pglTexCoord1hNV;
GLEE_EXTERN PFNGLTEXCOORD1HVNVPROC pglTexCoord1hvNV;
GLEE_EXTERN PFNGLTEXCOORD2HNVPROC pglTexCoord2hNV;
GLEE_EXTERN PFNGLTEXCOORD2HVNVPROC pglTexCoord2hvNV;
GLEE_EXTERN PFNGLTEXCOORD3HNVPROC pglTexCoord3hNV;
GLEE_EXTERN PFNGLTEXCOORD3HVNVPROC pglTexCoord3hvNV;
GLEE_EXTERN PFNGLTEXCOORD4HNVPROC pglTexCoord4hNV;
GLEE_EXTERN PFNGLTEXCOORD4HVNVPROC pglTexCoord4hvNV;
GLEE_EXTERN PFNGLMULTITEXCOORD1HNVPROC pglMultiTexCoord1hNV;
GLEE_EXTERN PFNGLMULTITEXCOORD1HVNVPROC pglMultiTexCoord1hvNV;
GLEE_EXTERN PFNGLMULTITEXCOORD2HNVPROC pglMultiTexCoord2hNV;
GLEE_EXTERN PFNGLMULTITEXCOORD2HVNVPROC pglMultiTexCoord2hvNV;
GLEE_EXTERN PFNGLMULTITEXCOORD3HNVPROC pglMultiTexCoord3hNV;
GLEE_EXTERN PFNGLMULTITEXCOORD3HVNVPROC pglMultiTexCoord3hvNV;
GLEE_EXTERN PFNGLMULTITEXCOORD4HNVPROC pglMultiTexCoord4hNV;
GLEE_EXTERN PFNGLMULTITEXCOORD4HVNVPROC pglMultiTexCoord4hvNV;
GLEE_EXTERN PFNGLFOGCOORDHNVPROC pglFogCoordhNV;
GLEE_EXTERN PFNGLFOGCOORDHVNVPROC pglFogCoordhvNV;
GLEE_EXTERN PFNGLSECONDARYCOLOR3HNVPROC pglSecondaryColor3hNV;
GLEE_EXTERN PFNGLSECONDARYCOLOR3HVNVPROC pglSecondaryColor3hvNV;
GLEE_EXTERN PFNGLVERTEXWEIGHTHNVPROC pglVertexWeighthNV;
GLEE_EXTERN PFNGLVERTEXWEIGHTHVNVPROC pglVertexWeighthvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB1HNVPROC pglVertexAttrib1hNV;
GLEE_EXTERN PFNGLVERTEXATTRIB1HVNVPROC pglVertexAttrib1hvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB2HNVPROC pglVertexAttrib2hNV;
GLEE_EXTERN PFNGLVERTEXATTRIB2HVNVPROC pglVertexAttrib2hvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB3HNVPROC pglVertexAttrib3hNV;
GLEE_EXTERN PFNGLVERTEXATTRIB3HVNVPROC pglVertexAttrib3hvNV;
GLEE_EXTERN PFNGLVERTEXATTRIB4HNVPROC pglVertexAttrib4hNV;
GLEE_EXTERN PFNGLVERTEXATTRIB4HVNVPROC pglVertexAttrib4hvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS1HVNVPROC pglVertexAttribs1hvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS2HVNVPROC pglVertexAttribs2hvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS3HVNVPROC pglVertexAttribs3hvNV;
GLEE_EXTERN PFNGLVERTEXATTRIBS4HVNVPROC pglVertexAttribs4hvNV;
#define glVertex2hNV pglVertex2hNV
#define glVertex2hvNV pglVertex2hvNV
#define glVertex3hNV pglVertex3hNV
#define glVertex3hvNV pglVertex3hvNV
#define glVertex4hNV pglVertex4hNV
#define glVertex4hvNV pglVertex4hvNV
#define glNormal3hNV pglNormal3hNV
#define glNormal3hvNV pglNormal3hvNV
#define glColor3hNV pglColor3hNV
#define glColor3hvNV pglColor3hvNV
#define glColor4hNV pglColor4hNV
#define glColor4hvNV pglColor4hvNV
#define glTexCoord1hNV pglTexCoord1hNV
#define glTexCoord1hvNV pglTexCoord1hvNV
#define glTexCoord2hNV pglTexCoord2hNV
#define glTexCoord2hvNV pglTexCoord2hvNV
#define glTexCoord3hNV pglTexCoord3hNV
#define glTexCoord3hvNV pglTexCoord3hvNV
#define glTexCoord4hNV pglTexCoord4hNV
#define glTexCoord4hvNV pglTexCoord4hvNV
#define glMultiTexCoord1hNV pglMultiTexCoord1hNV
#define glMultiTexCoord1hvNV pglMultiTexCoord1hvNV
#define glMultiTexCoord2hNV pglMultiTexCoord2hNV
#define glMultiTexCoord2hvNV pglMultiTexCoord2hvNV
#define glMultiTexCoord3hNV pglMultiTexCoord3hNV
#define glMultiTexCoord3hvNV pglMultiTexCoord3hvNV
#define glMultiTexCoord4hNV pglMultiTexCoord4hNV
#define glMultiTexCoord4hvNV pglMultiTexCoord4hvNV
#define glFogCoordhNV pglFogCoordhNV
#define glFogCoordhvNV pglFogCoordhvNV
#define glSecondaryColor3hNV pglSecondaryColor3hNV
#define glSecondaryColor3hvNV pglSecondaryColor3hvNV
#define glVertexWeighthNV pglVertexWeighthNV
#define glVertexWeighthvNV pglVertexWeighthvNV
#define glVertexAttrib1hNV pglVertexAttrib1hNV
#define glVertexAttrib1hvNV pglVertexAttrib1hvNV
#define glVertexAttrib2hNV pglVertexAttrib2hNV
#define glVertexAttrib2hvNV pglVertexAttrib2hvNV
#define glVertexAttrib3hNV pglVertexAttrib3hNV
#define glVertexAttrib3hvNV pglVertexAttrib3hvNV
#define glVertexAttrib4hNV pglVertexAttrib4hNV
#define glVertexAttrib4hvNV pglVertexAttrib4hvNV
#define glVertexAttribs1hvNV pglVertexAttribs1hvNV
#define glVertexAttribs2hvNV pglVertexAttribs2hvNV
#define glVertexAttribs3hvNV pglVertexAttribs3hvNV
#define glVertexAttribs4hvNV pglVertexAttribs4hvNV
#endif 

/* GL_NV_pixel_data_range */

#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range 1
#define __GLEE_GL_NV_pixel_data_range 1
/* Constants */
#define GL_WRITE_PIXEL_DATA_RANGE_NV                       0x8878
#define GL_READ_PIXEL_DATA_RANGE_NV                        0x8879
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV                0x887A
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV                 0x887B
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV               0x887C
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV                0x887D
typedef void (APIENTRYP PFNGLPIXELDATARANGENVPROC) (GLenum target, GLsizei length, GLvoid * pointer);
typedef void (APIENTRYP PFNGLFLUSHPIXELDATARANGENVPROC) (GLenum target);
GLEE_EXTERN PFNGLPIXELDATARANGENVPROC pglPixelDataRangeNV;
GLEE_EXTERN PFNGLFLUSHPIXELDATARANGENVPROC pglFlushPixelDataRangeNV;
#define glPixelDataRangeNV pglPixelDataRangeNV
#define glFlushPixelDataRangeNV pglFlushPixelDataRangeNV
#endif 

/* GL_NV_primitive_restart */

#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart 1
#define __GLEE_GL_NV_primitive_restart 1
/* Constants */
#define GL_PRIMITIVE_RESTART_NV                            0x8558
#define GL_PRIMITIVE_RESTART_INDEX_NV                      0x8559
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTNVPROC) ();
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXNVPROC) (GLuint index);
GLEE_EXTERN PFNGLPRIMITIVERESTARTNVPROC pglPrimitiveRestartNV;
GLEE_EXTERN PFNGLPRIMITIVERESTARTINDEXNVPROC pglPrimitiveRestartIndexNV;
#define glPrimitiveRestartNV pglPrimitiveRestartNV
#define glPrimitiveRestartIndexNV pglPrimitiveRestartIndexNV
#endif 

/* GL_NV_texture_expand_normal */

#ifndef GL_NV_texture_expand_normal
#define GL_NV_texture_expand_normal 1
#define __GLEE_GL_NV_texture_expand_normal 1
/* Constants */
#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV                  0x888F
#endif 

/* GL_NV_vertex_program2 */

#ifndef GL_NV_vertex_program2
#define GL_NV_vertex_program2 1
#define __GLEE_GL_NV_vertex_program2 1
/* Constants */
#endif 

/* GL_ATI_map_object_buffer */

#ifndef GL_ATI_map_object_buffer
#define GL_ATI_map_object_buffer 1
#define __GLEE_GL_ATI_map_object_buffer 1
/* Constants */
typedef GLvoid* (APIENTRYP PFNGLMAPOBJECTBUFFERATIPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLUNMAPOBJECTBUFFERATIPROC) (GLuint buffer);
GLEE_EXTERN PFNGLMAPOBJECTBUFFERATIPROC pglMapObjectBufferATI;
GLEE_EXTERN PFNGLUNMAPOBJECTBUFFERATIPROC pglUnmapObjectBufferATI;
#define glMapObjectBufferATI pglMapObjectBufferATI
#define glUnmapObjectBufferATI pglUnmapObjectBufferATI
#endif 

/* GL_ATI_separate_stencil */

#ifndef GL_ATI_separate_stencil
#define GL_ATI_separate_stencil 1
#define __GLEE_GL_ATI_separate_stencil 1
/* Constants */
#define GL_STENCIL_BACK_FUNC_ATI                           0x8800
#define GL_STENCIL_BACK_FAIL_ATI                           0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI                0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI                0x8803
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEATIPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEATIPROC) (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
GLEE_EXTERN PFNGLSTENCILOPSEPARATEATIPROC pglStencilOpSeparateATI;
GLEE_EXTERN PFNGLSTENCILFUNCSEPARATEATIPROC pglStencilFuncSeparateATI;
#define glStencilOpSeparateATI pglStencilOpSeparateATI
#define glStencilFuncSeparateATI pglStencilFuncSeparateATI
#endif 

/* GL_ATI_vertex_attrib_array_object */

#ifndef GL_ATI_vertex_attrib_array_object
#define GL_ATI_vertex_attrib_array_object 1
#define __GLEE_GL_ATI_vertex_attrib_array_object 1
/* Constants */
typedef void (APIENTRYP PFNGLVERTEXATTRIBARRAYOBJECTATIPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC) (GLuint index, GLenum pname, GLfloat * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC) (GLuint index, GLenum pname, GLint * params);
GLEE_EXTERN PFNGLVERTEXATTRIBARRAYOBJECTATIPROC pglVertexAttribArrayObjectATI;
GLEE_EXTERN PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC pglGetVertexAttribArrayObjectfvATI;
GLEE_EXTERN PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC pglGetVertexAttribArrayObjectivATI;
#define glVertexAttribArrayObjectATI pglVertexAttribArrayObjectATI
#define glGetVertexAttribArrayObjectfvATI pglGetVertexAttribArrayObjectfvATI
#define glGetVertexAttribArrayObjectivATI pglGetVertexAttribArrayObjectivATI
#endif 

/* GL_OES_read_format */

#ifndef GL_OES_read_format
#define GL_OES_read_format 1
#define __GLEE_GL_OES_read_format 1
/* Constants */
#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES              0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES            0x8B9B
#endif 

/* GL_EXT_depth_bounds_test */

#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test 1
#define __GLEE_GL_EXT_depth_bounds_test 1
/* Constants */
#define GL_DEPTH_BOUNDS_TEST_EXT                           0x8890
#define GL_DEPTH_BOUNDS_EXT                                0x8891
typedef void (APIENTRYP PFNGLDEPTHBOUNDSEXTPROC) (GLclampd zmin, GLclampd zmax);
GLEE_EXTERN PFNGLDEPTHBOUNDSEXTPROC pglDepthBoundsEXT;
#define glDepthBoundsEXT pglDepthBoundsEXT
#endif 

/* GL_EXT_texture_mirror_clamp */

#ifndef GL_EXT_texture_mirror_clamp
#define GL_EXT_texture_mirror_clamp 1
#define __GLEE_GL_EXT_texture_mirror_clamp 1
/* Constants */
#define GL_MIRROR_CLAMP_EXT                                0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT                        0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT                      0x8912
#endif 

/* GL_EXT_blend_equation_separate */

#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate 1
#define __GLEE_GL_EXT_blend_equation_separate 1
/* Constants */
#define GL_BLEND_EQUATION_RGB_EXT                          GL_BLEND_EQUATION
#define GL_BLEND_EQUATION_ALPHA_EXT                        0x883D
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEEXTPROC) (GLenum modeRGB, GLenum modeAlpha);
GLEE_EXTERN PFNGLBLENDEQUATIONSEPARATEEXTPROC pglBlendEquationSeparateEXT;
#define glBlendEquationSeparateEXT pglBlendEquationSeparateEXT
#endif 

/* GL_MESA_pack_invert */

#ifndef GL_MESA_pack_invert
#define GL_MESA_pack_invert 1
#define __GLEE_GL_MESA_pack_invert 1
/* Constants */
#define GL_PACK_INVERT_MESA                                0x8758
#endif 

/* GL_MESA_ycbcr_texture */

#ifndef GL_MESA_ycbcr_texture
#define GL_MESA_ycbcr_texture 1
#define __GLEE_GL_MESA_ycbcr_texture 1
/* Constants */
#define GL_UNSIGNED_SHORT_8_8_MESA                         0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_MESA                     0x85BB
#define GL_YCBCR_MESA                                      0x8757
#endif 

/* GL_EXT_pixel_buffer_object */

#ifndef GL_EXT_pixel_buffer_object
#define GL_EXT_pixel_buffer_object 1
#define __GLEE_GL_EXT_pixel_buffer_object 1
/* Constants */
#define GL_PIXEL_PACK_BUFFER_EXT                           0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT                         0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT                   0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT                 0x88EF
#endif 

/* GL_NV_fragment_program_option */

#ifndef GL_NV_fragment_program_option
#define GL_NV_fragment_program_option 1
#define __GLEE_GL_NV_fragment_program_option 1
/* Constants */
#endif 

/* GL_NV_fragment_program2 */

#ifndef GL_NV_fragment_program2
#define GL_NV_fragment_program2 1
#define __GLEE_GL_NV_fragment_program2 1
/* Constants */
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV                0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV                       0x88F5
#define GL_MAX_PROGRAM_IF_DEPTH_NV                         0x88F6
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV                       0x88F7
#define GL_MAX_PROGRAM_LOOP_COUNT_NV                       0x88F8
#endif 

/* GL_NV_vertex_program2_option */

#ifndef GL_NV_vertex_program2_option
#define GL_NV_vertex_program2_option 1
#define __GLEE_GL_NV_vertex_program2_option 1
/* Constants */
#endif 

/* GL_NV_vertex_program3 */

#ifndef GL_NV_vertex_program3
#define GL_NV_vertex_program3 1
#define __GLEE_GL_NV_vertex_program3 1
/* Constants */
#endif 

/* GL_EXT_framebuffer_object */

#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object 1
#define __GLEE_GL_EXT_framebuffer_object 1
/* Constants */
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT               0x0506
#define GL_MAX_RENDERBUFFER_SIZE_EXT                       0x84E8
#define GL_FRAMEBUFFER_BINDING_EXT                         0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT                        0x8CA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT          0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT          0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT        0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT   0x8CD4
#define GL_FRAMEBUFFER_COMPLETE_EXT                        0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT           0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT   0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DUPLICATE_ATTACHMENT_EXT 0x8CD8
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT           0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT              0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT          0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT          0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT                     0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS_EXT                       0x8CDF
#define GL_COLOR_ATTACHMENT0_EXT                           0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT                           0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT                           0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT                           0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT                           0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT                           0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT                           0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT                           0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT                           0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT                           0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT                          0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT                          0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT                          0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT                          0x8CED
#define GL_COLOR_ATTACHMENT14_EXT                          0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT                          0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT                            0x8D00
#define GL_STENCIL_ATTACHMENT_EXT                          0x8D20
#define GL_FRAMEBUFFER_EXT                                 0x8D40
#define GL_RENDERBUFFER_EXT                                0x8D41
#define GL_RENDERBUFFER_WIDTH_EXT                          0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT                         0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT                0x8D44
#define GL_STENCIL_INDEX_EXT                               0x8D45
#define GL_STENCIL_INDEX1_EXT                              0x8D46
#define GL_STENCIL_INDEX4_EXT                              0x8D47
#define GL_STENCIL_INDEX8_EXT                              0x8D48
#define GL_STENCIL_INDEX16_EXT                             0x8D49
#define GL_RENDERBUFFER_RED_SIZE_EXT                       0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT                     0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT                      0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT                     0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT                     0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT                   0x8D55
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFEREXTPROC) (GLuint renderbuffer);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFEREXTPROC) (GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSEXTPROC) (GLsizei n, const GLuint * renderbuffers);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSEXTPROC) (GLsizei n, GLuint * renderbuffers);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFEREXTPROC) (GLuint framebuffer);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFEREXTPROC) (GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSEXTPROC) (GLsizei n, const GLuint * framebuffers);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSEXTPROC) (GLsizei n, GLuint * framebuffers);
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC) (GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DEXTPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DEXTPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DEXTPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) (GLenum target, GLenum attachment, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPEXTPROC) (GLenum target);
GLEE_EXTERN PFNGLISRENDERBUFFEREXTPROC pglIsRenderbufferEXT;
GLEE_EXTERN PFNGLBINDRENDERBUFFEREXTPROC pglBindRenderbufferEXT;
GLEE_EXTERN PFNGLDELETERENDERBUFFERSEXTPROC pglDeleteRenderbuffersEXT;
GLEE_EXTERN PFNGLGENRENDERBUFFERSEXTPROC pglGenRenderbuffersEXT;
GLEE_EXTERN PFNGLRENDERBUFFERSTORAGEEXTPROC pglRenderbufferStorageEXT;
GLEE_EXTERN PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC pglGetRenderbufferParameterivEXT;
GLEE_EXTERN PFNGLISFRAMEBUFFEREXTPROC pglIsFramebufferEXT;
GLEE_EXTERN PFNGLBINDFRAMEBUFFEREXTPROC pglBindFramebufferEXT;
GLEE_EXTERN PFNGLDELETEFRAMEBUFFERSEXTPROC pglDeleteFramebuffersEXT;
GLEE_EXTERN PFNGLGENFRAMEBUFFERSEXTPROC pglGenFramebuffersEXT;
GLEE_EXTERN PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC pglCheckFramebufferStatusEXT;
GLEE_EXTERN PFNGLFRAMEBUFFERTEXTURE1DEXTPROC pglFramebufferTexture1DEXT;
GLEE_EXTERN PFNGLFRAMEBUFFERTEXTURE2DEXTPROC pglFramebufferTexture2DEXT;
GLEE_EXTERN PFNGLFRAMEBUFFERTEXTURE3DEXTPROC pglFramebufferTexture3DEXT;
GLEE_EXTERN PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC pglFramebufferRenderbufferEXT;
GLEE_EXTERN PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC pglGetFramebufferAttachmentParameterivEXT;
GLEE_EXTERN PFNGLGENERATEMIPMAPEXTPROC pglGenerateMipmapEXT;
#define glIsRenderbufferEXT pglIsRenderbufferEXT
#define glBindRenderbufferEXT pglBindRenderbufferEXT
#define glDeleteRenderbuffersEXT pglDeleteRenderbuffersEXT
#define glGenRenderbuffersEXT pglGenRenderbuffersEXT
#define glRenderbufferStorageEXT pglRenderbufferStorageEXT
#define glGetRenderbufferParameterivEXT pglGetRenderbufferParameterivEXT
#define glIsFramebufferEXT pglIsFramebufferEXT
#define glBindFramebufferEXT pglBindFramebufferEXT
#define glDeleteFramebuffersEXT pglDeleteFramebuffersEXT
#define glGenFramebuffersEXT pglGenFramebuffersEXT
#define glCheckFramebufferStatusEXT pglCheckFramebufferStatusEXT
#define glFramebufferTexture1DEXT pglFramebufferTexture1DEXT
#define glFramebufferTexture2DEXT pglFramebufferTexture2DEXT
#define glFramebufferTexture3DEXT pglFramebufferTexture3DEXT
#define glFramebufferRenderbufferEXT pglFramebufferRenderbufferEXT
#define glGetFramebufferAttachmentParameterivEXT pglGetFramebufferAttachmentParameterivEXT
#define glGenerateMipmapEXT pglGenerateMipmapEXT
#endif 

/* GL_GREMEDY_string_marker */

#ifndef GL_GREMEDY_string_marker
#define GL_GREMEDY_string_marker 1
#define __GLEE_GL_GREMEDY_string_marker 1
/* Constants */
typedef void (APIENTRYP PFNGLSTRINGMARKERGREMEDYPROC) (GLsizei len, const GLvoid * string);
GLEE_EXTERN PFNGLSTRINGMARKERGREMEDYPROC pglStringMarkerGREMEDY;
#define glStringMarkerGREMEDY pglStringMarkerGREMEDY
#endif 

/* GL_EXT_Cg_shader */

#ifndef GL_EXT_Cg_shader
#define GL_EXT_Cg_shader 1
#define __GLEE_GL_EXT_Cg_shader 1
/* Constants */
#define GL_CG_VERTEX_SHADER_EXT                            0x890E
#define GL_CG_FRAGMENT_SHADER_EXT                          0x890F
#endif 

/* GL_EXT_timer_query */

#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query 1
#define __GLEE_GL_EXT_timer_query 1
/* Constants */
#define GL_TIME_ELAPSED_EXT                                0x88BF
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VEXTPROC) (GLuint id, GLenum pname, GLint64EXT * params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VEXTPROC) (GLuint id, GLenum pname, GLuint64EXT * params);
GLEE_EXTERN PFNGLGETQUERYOBJECTI64VEXTPROC pglGetQueryObjecti64vEXT;
GLEE_EXTERN PFNGLGETQUERYOBJECTUI64VEXTPROC pglGetQueryObjectui64vEXT;
#define glGetQueryObjecti64vEXT pglGetQueryObjecti64vEXT
#define glGetQueryObjectui64vEXT pglGetQueryObjectui64vEXT
#endif 

/* GL_EXT_texture_buffer_object */

#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object 1
#define __GLEE_GL_EXT_texture_buffer_object 1
/* Constants */
#define GL_TEXTURE_BUFFER_EXT                              0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT                     0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT                      0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT           0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_EXT                       0x8C2E
typedef void (APIENTRYP PFNGLTEXBUFFEREXTPROC) (GLenum target, GLenum internalformat, GLuint buffer);
GLEE_EXTERN PFNGLTEXBUFFEREXTPROC pglTexBufferEXT;
#define glTexBufferEXT pglTexBufferEXT
#endif 

/* GL_EXT_gpu_shader4 */

#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4 1
#define __GLEE_GL_EXT_gpu_shader4 1
/* Constants */
#define GL_SAMPLER_1D_ARRAY_EXT                            0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT                            0x8DC1
#define GL_SAMPLER_BUFFER_EXT                              0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT                     0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT                     0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT                         0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT                           0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT                           0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT                           0x8DC8
#define GL_INT_SAMPLER_1D_EXT                              0x8DC9
#define GL_INT_SAMPLER_2D_EXT                              0x8DCA
#define GL_INT_SAMPLER_3D_EXT                              0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT                            0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT                         0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT                        0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT                        0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT                          0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT                     0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT                     0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT                     0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT                   0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT                0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT               0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT               0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT                 0x8DD8
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT                 0x88FD
typedef void (APIENTRYP PFNGLGETUNIFORMUIVEXTPROC) (GLuint program, GLint location, GLuint * params);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONEXTPROC) (GLuint program, GLuint color, const GLchar * name);
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONEXTPROC) (GLuint program, const GLchar * name);
typedef void (APIENTRYP PFNGLUNIFORM1UIEXTPROC) (GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLUNIFORM2UIEXTPROC) (GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLUNIFORM3UIEXTPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLUNIFORM4UIEXTPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLUNIFORM1UIVEXTPROC) (GLint location, GLsizei count, const GLuint * value);
typedef void (APIENTRYP PFNGLUNIFORM2UIVEXTPROC) (GLint location, GLsizei count, const GLuint * value);
typedef void (APIENTRYP PFNGLUNIFORM3UIVEXTPROC) (GLint location, GLsizei count, const GLuint * value);
typedef void (APIENTRYP PFNGLUNIFORM4UIVEXTPROC) (GLint location, GLsizei count, const GLuint * value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IEXTPROC) (GLuint index, GLint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IEXTPROC) (GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IEXTPROC) (GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IEXTPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIEXTPROC) (GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIEXTPROC) (GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIEXTPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIEXTPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVEXTPROC) (GLuint index, const GLint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVEXTPROC) (GLuint index, const GLint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVEXTPROC) (GLuint index, const GLint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVEXTPROC) (GLuint index, const GLint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVEXTPROC) (GLuint index, const GLuint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVEXTPROC) (GLuint index, const GLuint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVEXTPROC) (GLuint index, const GLuint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVEXTPROC) (GLuint index, const GLuint * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVEXTPROC) (GLuint index, const GLbyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVEXTPROC) (GLuint index, const GLshort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVEXTPROC) (GLuint index, const GLubyte * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVEXTPROC) (GLuint index, const GLushort * v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTEREXTPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVEXTPROC) (GLuint index, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVEXTPROC) (GLuint index, GLenum pname, GLuint * params);
GLEE_EXTERN PFNGLGETUNIFORMUIVEXTPROC pglGetUniformuivEXT;
GLEE_EXTERN PFNGLBINDFRAGDATALOCATIONEXTPROC pglBindFragDataLocationEXT;
GLEE_EXTERN PFNGLGETFRAGDATALOCATIONEXTPROC pglGetFragDataLocationEXT;
GLEE_EXTERN PFNGLUNIFORM1UIEXTPROC pglUniform1uiEXT;
GLEE_EXTERN PFNGLUNIFORM2UIEXTPROC pglUniform2uiEXT;
GLEE_EXTERN PFNGLUNIFORM3UIEXTPROC pglUniform3uiEXT;
GLEE_EXTERN PFNGLUNIFORM4UIEXTPROC pglUniform4uiEXT;
GLEE_EXTERN PFNGLUNIFORM1UIVEXTPROC pglUniform1uivEXT;
GLEE_EXTERN PFNGLUNIFORM2UIVEXTPROC pglUniform2uivEXT;
GLEE_EXTERN PFNGLUNIFORM3UIVEXTPROC pglUniform3uivEXT;
GLEE_EXTERN PFNGLUNIFORM4UIVEXTPROC pglUniform4uivEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI1IEXTPROC pglVertexAttribI1iEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI2IEXTPROC pglVertexAttribI2iEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI3IEXTPROC pglVertexAttribI3iEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI4IEXTPROC pglVertexAttribI4iEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI1UIEXTPROC pglVertexAttribI1uiEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI2UIEXTPROC pglVertexAttribI2uiEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI3UIEXTPROC pglVertexAttribI3uiEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI4UIEXTPROC pglVertexAttribI4uiEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI1IVEXTPROC pglVertexAttribI1ivEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI2IVEXTPROC pglVertexAttribI2ivEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI3IVEXTPROC pglVertexAttribI3ivEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI4IVEXTPROC pglVertexAttribI4ivEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI1UIVEXTPROC pglVertexAttribI1uivEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI2UIVEXTPROC pglVertexAttribI2uivEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI3UIVEXTPROC pglVertexAttribI3uivEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI4UIVEXTPROC pglVertexAttribI4uivEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI4BVEXTPROC pglVertexAttribI4bvEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI4SVEXTPROC pglVertexAttribI4svEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI4UBVEXTPROC pglVertexAttribI4ubvEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBI4USVEXTPROC pglVertexAttribI4usvEXT;
GLEE_EXTERN PFNGLVERTEXATTRIBIPOINTEREXTPROC pglVertexAttribIPointerEXT;
GLEE_EXTERN PFNGLGETVERTEXATTRIBIIVEXTPROC pglGetVertexAttribIivEXT;
GLEE_EXTERN PFNGLGETVERTEXATTRIBIUIVEXTPROC pglGetVertexAttribIuivEXT;
#define glGetUniformuivEXT pglGetUniformuivEXT
#define glBindFragDataLocationEXT pglBindFragDataLocationEXT
#define glGetFragDataLocationEXT pglGetFragDataLocationEXT
#define glUniform1uiEXT pglUniform1uiEXT
#define glUniform2uiEXT pglUniform2uiEXT
#define glUniform3uiEXT pglUniform3uiEXT
#define glUniform4uiEXT pglUniform4uiEXT
#define glUniform1uivEXT pglUniform1uivEXT
#define glUniform2uivEXT pglUniform2uivEXT
#define glUniform3uivEXT pglUniform3uivEXT
#define glUniform4uivEXT pglUniform4uivEXT
#define glVertexAttribI1iEXT pglVertexAttribI1iEXT
#define glVertexAttribI2iEXT pglVertexAttribI2iEXT
#define glVertexAttribI3iEXT pglVertexAttribI3iEXT
#define glVertexAttribI4iEXT pglVertexAttribI4iEXT
#define glVertexAttribI1uiEXT pglVertexAttribI1uiEXT
#define glVertexAttribI2uiEXT pglVertexAttribI2uiEXT
#define glVertexAttribI3uiEXT pglVertexAttribI3uiEXT
#define glVertexAttribI4uiEXT pglVertexAttribI4uiEXT
#define glVertexAttribI1ivEXT pglVertexAttribI1ivEXT
#define glVertexAttribI2ivEXT pglVertexAttribI2ivEXT
#define glVertexAttribI3ivEXT pglVertexAttribI3ivEXT
#define glVertexAttribI4ivEXT pglVertexAttribI4ivEXT
#define glVertexAttribI1uivEXT pglVertexAttribI1uivEXT
#define glVertexAttribI2uivEXT pglVertexAttribI2uivEXT
#define glVertexAttribI3uivEXT pglVertexAttribI3uivEXT
#define glVertexAttribI4uivEXT pglVertexAttribI4uivEXT
#define glVertexAttribI4bvEXT pglVertexAttribI4bvEXT
#define glVertexAttribI4svEXT pglVertexAttribI4svEXT
#define glVertexAttribI4ubvEXT pglVertexAttribI4ubvEXT
#define glVertexAttribI4usvEXT pglVertexAttribI4usvEXT
#define glVertexAttribIPointerEXT pglVertexAttribIPointerEXT
#define glGetVertexAttribIivEXT pglGetVertexAttribIivEXT
#define glGetVertexAttribIuivEXT pglGetVertexAttribIuivEXT
#endif 

/* GL_EXT_geometry_shader4 */

#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4 1
#define __GLEE_GL_EXT_geometry_shader4 1
/* Constants */
#define GL_GEOMETRY_SHADER_EXT                             0x8DD9
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT             0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT               0x8DDE
#define GL_MAX_VARYING_COMPONENTS_EXT                      0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT             0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT                0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT        0x8DE1
#define GL_GEOMETRY_VERTICES_OUT_EXT                       0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT                         0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT                        0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT            0x8C29
#define GL_LINES_ADJACENCY_EXT                             0xA
#define GL_LINE_STRIP_ADJACENCY_EXT                        0xB
#define GL_TRIANGLES_ADJACENCY_EXT                         0xC
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT                    0xD
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT              0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT        0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT          0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT        0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT                          0x8642
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIEXTPROC) (GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREEXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
GLEE_EXTERN PFNGLPROGRAMPARAMETERIEXTPROC pglProgramParameteriEXT;
GLEE_EXTERN PFNGLFRAMEBUFFERTEXTUREEXTPROC pglFramebufferTextureEXT;
GLEE_EXTERN PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC pglFramebufferTextureLayerEXT;
GLEE_EXTERN PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC pglFramebufferTextureFaceEXT;
#define glProgramParameteriEXT pglProgramParameteriEXT
#define glFramebufferTextureEXT pglFramebufferTextureEXT
#define glFramebufferTextureLayerEXT pglFramebufferTextureLayerEXT
#define glFramebufferTextureFaceEXT pglFramebufferTextureFaceEXT
#endif 

/* GL_EXT_bindable_uniform */

#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform 1
#define __GLEE_GL_EXT_bindable_uniform 1
/* Constants */
#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT                0x8DE2
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT              0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT              0x8DE4
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT                   0x8DED
#define GL_UNIFORM_BUFFER_EXT                              0x8DEE
#define GL_UNIFORM_BUFFER_BINDING_EXT                      0x8DEF
typedef void (APIENTRYP PFNGLUNIFORMBUFFEREXTPROC) (GLuint program, GLint location, GLuint buffer);
typedef GLint (APIENTRYP PFNGLGETUNIFORMBUFFERSIZEEXTPROC) (GLuint program, GLint location);
typedef GLintptr (APIENTRYP PFNGLGETUNIFORMOFFSETEXTPROC) (GLuint program, GLint location);
GLEE_EXTERN PFNGLUNIFORMBUFFEREXTPROC pglUniformBufferEXT;
GLEE_EXTERN PFNGLGETUNIFORMBUFFERSIZEEXTPROC pglGetUniformBufferSizeEXT;
GLEE_EXTERN PFNGLGETUNIFORMOFFSETEXTPROC pglGetUniformOffsetEXT;
#define glUniformBufferEXT pglUniformBufferEXT
#define glGetUniformBufferSizeEXT pglGetUniformBufferSizeEXT
#define glGetUniformOffsetEXT pglGetUniformOffsetEXT
#endif 

/* GL_EXT_framebuffer_sRGB */

#ifndef GL_EXT_framebuffer_sRGB
#define GL_EXT_framebuffer_sRGB 1
#define __GLEE_GL_EXT_framebuffer_sRGB 1
/* Constants */
#define GL_FRAMEBUFFER_SRGB_EXT                            0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT                    0x8DBA
#endif 

/* GL_EXT_texture_shared_exponent */

#ifndef GL_EXT_texture_shared_exponent
#define GL_EXT_texture_shared_exponent 1
#define __GLEE_GL_EXT_texture_shared_exponent 1
/* Constants */
#define GL_RGB9_E5_EXT                                     0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT                    0x8C3E
#define GL_TEXTURE_SHARED_SIZE_EXT                         0x8C3F
#endif 

/* GL_EXT_packed_float */

#ifndef GL_EXT_packed_float
#define GL_EXT_packed_float 1
#define __GLEE_GL_EXT_packed_float 1
/* Constants */
#define GL_R11F_G11F_B10F_EXT                              0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT                0x8C3B
#define GL_RGBA_SIGNED_COMPONENTS_EXT                      0x8C3C
#endif 

/* GL_EXT_texture_array */

#ifndef GL_EXT_texture_array
#define GL_EXT_texture_array 1
#define __GLEE_GL_EXT_texture_array 1
/* Constants */
#define GL_TEXTURE_1D_ARRAY_EXT                            0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT                      0x8C19
#define GL_TEXTURE_2D_ARRAY_EXT                            0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT                      0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT                    0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT                    0x8C1D
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT                    0x88FF
#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT                0x884E
#endif 

/* GL_EXT_texture_integer */

#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer 1
#define __GLEE_GL_EXT_texture_integer 1
/* Constants */
#define GL_RGBA32UI_EXT                                    0x8D70
#define GL_RGB32UI_EXT                                     0x8D71
#define GL_ALPHA32UI_EXT                                   0x8D72
#define GL_INTENSITY32UI_EXT                               0x8D73
#define GL_LUMINANCE32UI_EXT                               0x8D74
#define GL_LUMINANCE_ALPHA32UI_EXT                         0x8D75
#define GL_RGBA16UI_EXT                                    0x8D76
#define GL_RGB16UI_EXT                                     0x8D77
#define GL_ALPHA16UI_EXT                                   0x8D78
#define GL_INTENSITY16UI_EXT                               0x8D79
#define GL_LUMINANCE16UI_EXT                               0x8D7A
#define GL_LUMINANCE_ALPHA16UI_EXT                         0x8D7B
#define GL_RGBA8UI_EXT                                     0x8D7C
#define GL_RGB8UI_EXT                                      0x8D7D
#define GL_ALPHA8UI_EXT                                    0x8D7E
#define GL_INTENSITY8UI_EXT                                0x8D7F
#define GL_LUMINANCE8UI_EXT                                0x8D80
#define GL_LUMINANCE_ALPHA8UI_EXT                          0x8D81
#define GL_RGBA32I_EXT                                     0x8D82
#define GL_RGB32I_EXT                                      0x8D83
#define GL_ALPHA32I_EXT                                    0x8D84
#define GL_INTENSITY32I_EXT                                0x8D85
#define GL_LUMINANCE32I_EXT                                0x8D86
#define GL_LUMINANCE_ALPHA32I_EXT                          0x8D87
#define GL_RGBA16I_EXT                                     0x8D88
#define GL_RGB16I_EXT                                      0x8D89
#define GL_ALPHA16I_EXT                                    0x8D8A
#define GL_INTENSITY16I_EXT                                0x8D8B
#define GL_LUMINANCE16I_EXT                                0x8D8C
#define GL_LUMINANCE_ALPHA16I_EXT                          0x8D8D
#define GL_RGBA8I_EXT                                      0x8D8E
#define GL_RGB8I_EXT                                       0x8D8F
#define GL_ALPHA8I_EXT                                     0x8D90
#define GL_INTENSITY8I_EXT                                 0x8D91
#define GL_LUMINANCE8I_EXT                                 0x8D92
#define GL_LUMINANCE_ALPHA8I_EXT                           0x8D93
#define GL_RED_INTEGER_EXT                                 0x8D94
#define GL_GREEN_INTEGER_EXT                               0x8D95
#define GL_BLUE_INTEGER_EXT                                0x8D96
#define GL_ALPHA_INTEGER_EXT                               0x8D97
#define GL_RGB_INTEGER_EXT                                 0x8D98
#define GL_RGBA_INTEGER_EXT                                0x8D99
#define GL_BGR_INTEGER_EXT                                 0x8D9A
#define GL_BGRA_INTEGER_EXT                                0x8D9B
#define GL_LUMINANCE_INTEGER_EXT                           0x8D9C
#define GL_LUMINANCE_ALPHA_INTEGER_EXT                     0x8D9D
#define GL_RGBA_INTEGER_MODE_EXT                           0x8D9E
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVEXTPROC) (GLenum target, GLenum pname, const GLint * params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVEXTPROC) (GLenum target, GLenum pname, const GLuint * params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVEXTPROC) (GLenum target, GLenum pname, GLint * params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVEXTPROC) (GLenum target, GLenum pname, GLuint * params);
typedef void (APIENTRYP PFNGLCLEARCOLORIIEXTPROC) (GLint red, GLint green, GLint blue, GLint alpha);
typedef void (APIENTRYP PFNGLCLEARCOLORIUIEXTPROC) (GLuint red, GLuint green, GLuint blue, GLuint alpha);
GLEE_EXTERN PFNGLTEXPARAMETERIIVEXTPROC pglTexParameterIivEXT;
GLEE_EXTERN PFNGLTEXPARAMETERIUIVEXTPROC pglTexParameterIuivEXT;
GLEE_EXTERN PFNGLGETTEXPARAMETERIIVEXTPROC pglGetTexParameterIivEXT;
GLEE_EXTERN PFNGLGETTEXPARAMETERIUIVEXTPROC pglGetTexParameterIuivEXT;
GLEE_EXTERN PFNGLCLEARCOLORIIEXTPROC pglClearColorIiEXT;
GLEE_EXTERN PFNGLCLEARCOLORIUIEXTPROC pglClearColorIuiEXT;
#define glTexParameterIivEXT pglTexParameterIivEXT
#define glTexParameterIuivEXT pglTexParameterIuivEXT
#define glGetTexParameterIivEXT pglGetTexParameterIivEXT
#define glGetTexParameterIuivEXT pglGetTexParameterIuivEXT
#define glClearColorIiEXT pglClearColorIiEXT
#define glClearColorIuiEXT pglClearColorIuiEXT
#endif 

/* GL_NV_depth_buffer_float */

#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float 1
#define __GLEE_GL_NV_depth_buffer_float 1
/* Constants */
#define GL_DEPTH_COMPONENT32F_NV                           0x8DAB
#define GL_DEPTH32F_STENCIL8_NV                            0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV               0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV                      0x8DAF
typedef void (APIENTRYP PFNGLDEPTHRANGEDNVPROC) (GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLCLEARDEPTHDNVPROC) (GLdouble depth);
typedef void (APIENTRYP PFNGLDEPTHBOUNDSDNVPROC) (GLdouble zmin, GLdouble zmax);
GLEE_EXTERN PFNGLDEPTHRANGEDNVPROC pglDepthRangedNV;
GLEE_EXTERN PFNGLCLEARDEPTHDNVPROC pglClearDepthdNV;
GLEE_EXTERN PFNGLDEPTHBOUNDSDNVPROC pglDepthBoundsdNV;
#define glDepthRangedNV pglDepthRangedNV
#define glClearDepthdNV pglClearDepthdNV
#define glDepthBoundsdNV pglDepthBoundsdNV
#endif 

/* GL_EXT_texture_compression_latc */

#ifndef GL_EXT_texture_compression_latc
#define GL_EXT_texture_compression_latc 1
#define __GLEE_GL_EXT_texture_compression_latc 1
/* Constants */
#define GL_COMPRESSED_LUMINANCE_LATC1_EXT                  0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT           0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT            0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT     0x8C73
#endif 

/* GL_NV_transform_feedback */

#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback 1
#define __GLEE_GL_NV_transform_feedback 1
/* Constants */
#define GL_BACK_PRIMARY_COLOR_NV                           0x8C77
#define GL_BACK_SECONDARY_COLOR_NV                         0x8C78
#define GL_TEXTURE_COORD_NV                                0x8C79
#define GL_CLIP_DISTANCE_NV                                0x8C7A
#define GL_VERTEX_ID_NV                                    0x8C7B
#define GL_PRIMITIVE_ID_NV                                 0x8C7C
#define GL_GENERIC_ATTRIB_NV                               0x8C7D
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV                   0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV               0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV   0x8C80
#define GL_ACTIVE_VARYINGS_NV                              0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV                    0x8C82
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV                  0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV              0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV               0x8C85
#define GL_TRANSFORM_FEEDBACK_RECORD_NV                    0x8C86
#define GL_PRIMITIVES_GENERATED_NV                         0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV        0x8C88
#define GL_RASTERIZER_DISCARD_NV                           0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_ATTRIBS_NV   0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV      0x8C8B
#define GL_INTERLEAVED_ATTRIBS_NV                          0x8C8C
#define GL_SEPARATE_ATTRIBS_NV                             0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV                    0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV            0x8C8F
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKNVPROC) (GLenum primitiveMode);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKNVPROC) ();
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC) (GLuint count, const GLint * attribs, GLenum bufferMode);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGENVPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLBINDBUFFEROFFSETNVPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset);
typedef void (APIENTRYP PFNGLBINDBUFFERBASENVPROC) (GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC) (GLuint program, GLsizei count, const GLint * locations, GLenum bufferMode);
typedef void (APIENTRYP PFNGLACTIVEVARYINGNVPROC) (GLuint program, const GLchar * name);
typedef GLint (APIENTRYP PFNGLGETVARYINGLOCATIONNVPROC) (GLuint program, const GLchar * name);
typedef void (APIENTRYP PFNGLGETACTIVEVARYINGNVPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC) (GLuint program, GLuint index, GLint * location);
GLEE_EXTERN PFNGLBEGINTRANSFORMFEEDBACKNVPROC pglBeginTransformFeedbackNV;
GLEE_EXTERN PFNGLENDTRANSFORMFEEDBACKNVPROC pglEndTransformFeedbackNV;
GLEE_EXTERN PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC pglTransformFeedbackAttribsNV;
GLEE_EXTERN PFNGLBINDBUFFERRANGENVPROC pglBindBufferRangeNV;
GLEE_EXTERN PFNGLBINDBUFFEROFFSETNVPROC pglBindBufferOffsetNV;
GLEE_EXTERN PFNGLBINDBUFFERBASENVPROC pglBindBufferBaseNV;
GLEE_EXTERN PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC pglTransformFeedbackVaryingsNV;
GLEE_EXTERN PFNGLACTIVEVARYINGNVPROC pglActiveVaryingNV;
GLEE_EXTERN PFNGLGETVARYINGLOCATIONNVPROC pglGetVaryingLocationNV;
GLEE_EXTERN PFNGLGETACTIVEVARYINGNVPROC pglGetActiveVaryingNV;
GLEE_EXTERN PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC pglGetTransformFeedbackVaryingNV;
#define glBeginTransformFeedbackNV pglBeginTransformFeedbackNV
#define glEndTransformFeedbackNV pglEndTransformFeedbackNV
#define glTransformFeedbackAttribsNV pglTransformFeedbackAttribsNV
#define glBindBufferRangeNV pglBindBufferRangeNV
#define glBindBufferOffsetNV pglBindBufferOffsetNV
#define glBindBufferBaseNV pglBindBufferBaseNV
#define glTransformFeedbackVaryingsNV pglTransformFeedbackVaryingsNV
#define glActiveVaryingNV pglActiveVaryingNV
#define glGetVaryingLocationNV pglGetVaryingLocationNV
#define glGetActiveVaryingNV pglGetActiveVaryingNV
#define glGetTransformFeedbackVaryingNV pglGetTransformFeedbackVaryingNV
#endif 

/* GL_NV_geometry_program4 */

#ifndef GL_NV_geometry_program4
#define GL_NV_geometry_program4 1
#define __GLEE_GL_NV_geometry_program4 1
/* Constants */
#define GL_GEOMETRY_PROGRAM_NV                             0x8C26
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV                  0x8C27
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV          0x8C28
typedef void (APIENTRYP PFNGLPROGRAMVERTEXLIMITNVPROC) (GLenum target, GLint limit);
GLEE_EXTERN PFNGLPROGRAMVERTEXLIMITNVPROC pglProgramVertexLimitNV;
#define glProgramVertexLimitNV pglProgramVertexLimitNV
#endif 

/* GL_NV_gpu_program4 */

#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4 1
#define __GLEE_GL_NV_gpu_program4 1
/* Constants */
#define GL_MIN_PROGRAM_TEXEL_OFFSET_NV                     0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_NV                     0x8905
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV                    0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV                    0x8907
#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV                0x8908
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV                0x8909
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV                  0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV                  0x8DA6
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4INVPROC) (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC) (GLenum target, GLuint index, const GLint * params);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLint * params);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4UINVPROC) (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC) (GLenum target, GLuint index, const GLuint * params);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLuint * params);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4INVPROC) (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4IVNVPROC) (GLenum target, GLuint index, const GLint * params);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERSI4IVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLint * params);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4UINVPROC) (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4UIVNVPROC) (GLenum target, GLuint index, const GLuint * params);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLuint * params);
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC) (GLenum target, GLuint index, GLint * params);
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC) (GLenum target, GLuint index, GLuint * params);
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERIIVNVPROC) (GLenum target, GLuint index, GLint * params);
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC) (GLenum target, GLuint index, GLuint * params);
GLEE_EXTERN PFNGLPROGRAMLOCALPARAMETERI4INVPROC pglProgramLocalParameterI4iNV;
GLEE_EXTERN PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC pglProgramLocalParameterI4ivNV;
GLEE_EXTERN PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC pglProgramLocalParametersI4ivNV;
GLEE_EXTERN PFNGLPROGRAMLOCALPARAMETERI4UINVPROC pglProgramLocalParameterI4uiNV;
GLEE_EXTERN PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC pglProgramLocalParameterI4uivNV;
GLEE_EXTERN PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC pglProgramLocalParametersI4uivNV;
GLEE_EXTERN PFNGLPROGRAMENVPARAMETERI4INVPROC pglProgramEnvParameterI4iNV;
GLEE_EXTERN PFNGLPROGRAMENVPARAMETERI4IVNVPROC pglProgramEnvParameterI4ivNV;
GLEE_EXTERN PFNGLPROGRAMENVPARAMETERSI4IVNVPROC pglProgramEnvParametersI4ivNV;
GLEE_EXTERN PFNGLPROGRAMENVPARAMETERI4UINVPROC pglProgramEnvParameterI4uiNV;
GLEE_EXTERN PFNGLPROGRAMENVPARAMETERI4UIVNVPROC pglProgramEnvParameterI4uivNV;
GLEE_EXTERN PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC pglProgramEnvParametersI4uivNV;
GLEE_EXTERN PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC pglGetProgramLocalParameterIivNV;
GLEE_EXTERN PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC pglGetProgramLocalParameterIuivNV;
GLEE_EXTERN PFNGLGETPROGRAMENVPARAMETERIIVNVPROC pglGetProgramEnvParameterIivNV;
GLEE_EXTERN PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC pglGetProgramEnvParameterIuivNV;
#define glProgramLocalParameterI4iNV pglProgramLocalParameterI4iNV
#define glProgramLocalParameterI4ivNV pglProgramLocalParameterI4ivNV
#define glProgramLocalParametersI4ivNV pglProgramLocalParametersI4ivNV
#define glProgramLocalParameterI4uiNV pglProgramLocalParameterI4uiNV
#define glProgramLocalParameterI4uivNV pglProgramLocalParameterI4uivNV
#define glProgramLocalParametersI4uivNV pglProgramLocalParametersI4uivNV
#define glProgramEnvParameterI4iNV pglProgramEnvParameterI4iNV
#define glProgramEnvParameterI4ivNV pglProgramEnvParameterI4ivNV
#define glProgramEnvParametersI4ivNV pglProgramEnvParametersI4ivNV
#define glProgramEnvParameterI4uiNV pglProgramEnvParameterI4uiNV
#define glProgramEnvParameterI4uivNV pglProgramEnvParameterI4uivNV
#define glProgramEnvParametersI4uivNV pglProgramEnvParametersI4uivNV
#define glGetProgramLocalParameterIivNV pglGetProgramLocalParameterIivNV
#define glGetProgramLocalParameterIuivNV pglGetProgramLocalParameterIuivNV
#define glGetProgramEnvParameterIivNV pglGetProgramEnvParameterIivNV
#define glGetProgramEnvParameterIuivNV pglGetProgramEnvParameterIuivNV
#endif 

/* GL_NV_framebuffer_multisample_coverage */

#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
#define __GLEE_GL_NV_framebuffer_multisample_coverage 1
/* Constants */
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV                0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV                   0x8E10
#define GL_MAX_RENDERBUFFER_COVERAGE_SAMPLES_NV            0x8D57
#define GL_MAX_RENDERBUFFER_COLOR_SAMPLES_NV               0x8E11
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV               0x8E12
#define GL_MULTISAMPLE_COVERAGE_MODES_NV                   0x8E13
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC) (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
GLEE_EXTERN PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC pglRenderbufferStorageMultisampleCoverageNV;
#define glRenderbufferStorageMultisampleCoverageNV pglRenderbufferStorageMultisampleCoverageNV
#endif 

/* GL_EXT_framebuffer_multisample */

#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample 1
#define __GLEE_GL_EXT_framebuffer_multisample 1
/* Constants */
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT          0x8D56
#define GL_MAX_SAMPLES_EXT                                 0x8D57
#define GL_RENDERBUFFER_SAMPLES_EXT                        0x8CAB
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLEE_EXTERN PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC pglRenderbufferStorageMultisampleEXT;
#define glRenderbufferStorageMultisampleEXT pglRenderbufferStorageMultisampleEXT
#endif 

/* GL_EXT_framebuffer_blit */

#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit 1
#define __GLEE_GL_EXT_framebuffer_blit 1
/* Constants */
#define GL_READ_FRAMEBUFFER_EXT                            0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT                            0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT                    0x8CA6
#define GL_READ_FRAMEBUFFER_BINDING_EXT                    0x8CAA
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFEREXTPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLEE_EXTERN PFNGLBLITFRAMEBUFFEREXTPROC pglBlitFramebufferEXT;
#define glBlitFramebufferEXT pglBlitFramebufferEXT
#endif 

/* GL_EXT_texture_compression_rgtc */

#ifndef GL_EXT_texture_compression_rgtc
#define GL_EXT_texture_compression_rgtc 1
#define __GLEE_GL_EXT_texture_compression_rgtc 1
/* Constants */
#define GL_COMPRESSED_RED_RGTC1_EXT                        0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT                 0x8DBC
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT                  0x8DBD
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT           0x8DBE
#endif 

/* GL_EXT_color_matrix */

#ifndef GL_EXT_color_matrix
#define GL_EXT_color_matrix 1
#define __GLEE_GL_EXT_color_matrix 1
/* Constants */
#endif 

/* GL_SGIX_texture_select */

#ifndef GL_SGIX_texture_select
#define GL_SGIX_texture_select 1
#define __GLEE_GL_SGIX_texture_select 1
/* Constants */
#endif 

/* GL_INGR_blend_func_separate */

#ifndef GL_INGR_blend_func_separate
#define GL_INGR_blend_func_separate 1
#define __GLEE_GL_INGR_blend_func_separate 1
/* Constants */
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEINGRPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLEE_EXTERN PFNGLBLENDFUNCSEPARATEINGRPROC pglBlendFuncSeparateINGR;
#define glBlendFuncSeparateINGR pglBlendFuncSeparateINGR
#endif 

/* GL_SGIX_depth_pass_instrument */

#ifndef GL_SGIX_depth_pass_instrument
#define GL_SGIX_depth_pass_instrument 1
#define __GLEE_GL_SGIX_depth_pass_instrument 1
/* Constants */
#endif 

/* GL_SGIX_igloo_interface */

#ifndef GL_SGIX_igloo_interface
#define GL_SGIX_igloo_interface 1
#define __GLEE_GL_SGIX_igloo_interface 1
/* Constants */
typedef void (APIENTRYP PFNGLIGLOOINTERFACESGIXPROC) (GLenum pname, const GLvoid * params);
GLEE_EXTERN PFNGLIGLOOINTERFACESGIXPROC pglIglooInterfaceSGIX;
#define glIglooInterfaceSGIX pglIglooInterfaceSGIX
#endif 

/* GL_EXT_draw_buffers2 */

#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2 1
#define __GLEE_GL_EXT_draw_buffers2 1
/* Constants */
typedef void (APIENTRYP PFNGLCOLORMASKINDEXEDEXTPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLGETBOOLEANINDEXEDVEXTPROC) (GLenum target, GLuint index, GLboolean * data);
typedef void (APIENTRYP PFNGLGETINTEGERINDEXEDVEXTPROC) (GLenum target, GLuint index, GLint * data);
typedef void (APIENTRYP PFNGLENABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISENABLEDINDEXEDEXTPROC) (GLenum target, GLuint index);
GLEE_EXTERN PFNGLCOLORMASKINDEXEDEXTPROC pglColorMaskIndexedEXT;
GLEE_EXTERN PFNGLGETBOOLEANINDEXEDVEXTPROC pglGetBooleanIndexedvEXT;
GLEE_EXTERN PFNGLGETINTEGERINDEXEDVEXTPROC pglGetIntegerIndexedvEXT;
GLEE_EXTERN PFNGLENABLEINDEXEDEXTPROC pglEnableIndexedEXT;
GLEE_EXTERN PFNGLDISABLEINDEXEDEXTPROC pglDisableIndexedEXT;
GLEE_EXTERN PFNGLISENABLEDINDEXEDEXTPROC pglIsEnabledIndexedEXT;
#define glColorMaskIndexedEXT pglColorMaskIndexedEXT
#define glGetBooleanIndexedvEXT pglGetBooleanIndexedvEXT
#define glGetIntegerIndexedvEXT pglGetIntegerIndexedvEXT
#define glEnableIndexedEXT pglEnableIndexedEXT
#define glDisableIndexedEXT pglDisableIndexedEXT
#define glIsEnabledIndexedEXT pglIsEnabledIndexedEXT
#endif 

/* GL_NV_parameter_buffer_object */

#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object 1
#define __GLEE_GL_NV_parameter_buffer_object 1
/* Constants */
typedef void (APIENTRYP PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC) (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat * params);
typedef void (APIENTRYP PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC) (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint * params);
typedef void (APIENTRYP PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC) (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint * params);
GLEE_EXTERN PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC pglProgramBufferParametersfvNV;
GLEE_EXTERN PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC pglProgramBufferParametersIivNV;
GLEE_EXTERN PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC pglProgramBufferParametersIuivNV;
#define glProgramBufferParametersfvNV pglProgramBufferParametersfvNV
#define glProgramBufferParametersIivNV pglProgramBufferParametersIivNV
#define glProgramBufferParametersIuivNV pglProgramBufferParametersIuivNV
#endif 

/* GL_EXT_draw_instanced */

#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
#define __GLEE_GL_EXT_draw_instanced 1
/* Constants */
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC) (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount);
GLEE_EXTERN PFNGLDRAWARRAYSINSTANCEDEXTPROC pglDrawArraysInstancedEXT;
GLEE_EXTERN PFNGLDRAWELEMENTSINSTANCEDEXTPROC pglDrawElementsInstancedEXT;
#define glDrawArraysInstancedEXT pglDrawArraysInstancedEXT
#define glDrawElementsInstancedEXT pglDrawElementsInstancedEXT
#endif 

/* GL_EXT_fragment_lighting */

#ifndef GL_EXT_fragment_lighting
#define GL_EXT_fragment_lighting 1
#define __GLEE_GL_EXT_fragment_lighting 1
/* Constants */
#define GL_FRAGMENT_LIGHTING_EXT                           0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_EXT                     0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_EXT                0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_EXT           0x8403
#define GL_MAX_FRAGMENT_LIGHTS_EXT                         0x8404
#define GL_MAX_ACTIVE_LIGHTS_EXT                           0x8405
#define GL_CURRENT_RASTER_NORMAL_EXT                       0x8406
#define GL_LIGHT_ENV_MODE_EXT                              0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_EXT           0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_EXT               0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_EXT                0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_EXT   0x840B
#define GL_FRAGMENT_LIGHT0_EXT                             0x840C
#define GL_FRAGMENT_LIGHT7_EXT                             0x8413
typedef GLvoid (APIENTRYP PFNGLFRAGMENTLIGHTMODELIEXTPROC) (GLenum pname, GLint param);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTLIGHTMODELFEXTPROC) (GLenum pname, GLfloat param);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTLIGHTMODELIVEXTPROC) (GLenum pname, GLint * params);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTLIGHTMODELFVEXTPROC) (GLenum pname, GLfloat * params);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTLIGHTIEXTPROC) (GLenum light, GLenum pname, GLint param);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTLIGHTFEXTPROC) (GLenum light, GLenum pname, GLfloat param);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTLIGHTIVEXTPROC) (GLenum light, GLenum pname, GLint * params);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTLIGHTFVEXTPROC) (GLenum light, GLenum pname, GLfloat * params);
typedef GLvoid (APIENTRYP PFNGLGETFRAGMENTLIGHTIVEXTPROC) (GLenum light, GLenum pname, GLint * params);
typedef GLvoid (APIENTRYP PFNGLGETFRAGMENTLIGHTFVEXTPROC) (GLenum light, GLenum pname, GLfloat * params);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTMATERIALFEXTPROC) (GLenum face, GLenum pname, const GLfloat param);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTMATERIALIEXTPROC) (GLenum face, GLenum pname, const GLint param);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTMATERIALFVEXTPROC) (GLenum face, GLenum pname, const GLfloat * params);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTMATERIALIVEXTPROC) (GLenum face, GLenum pname, const GLint * params);
typedef GLvoid (APIENTRYP PFNGLFRAGMENTCOLORMATERIALEXTPROC) (GLenum face, GLenum mode);
typedef GLvoid (APIENTRYP PFNGLGETFRAGMENTMATERIALFVEXTPROC) (GLenum face, GLenum pname, const GLfloat * params);
typedef GLvoid (APIENTRYP PFNGLGETFRAGMENTMATERIALIVEXTPROC) (GLenum face, GLenum pname, const GLint * params);
typedef GLvoid (APIENTRYP PFNGLLIGHTENVIEXTPROC) (GLenum pname, GLint param);
GLEE_EXTERN PFNGLFRAGMENTLIGHTMODELIEXTPROC pglFragmentLightModeliEXT;
GLEE_EXTERN PFNGLFRAGMENTLIGHTMODELFEXTPROC pglFragmentLightModelfEXT;
GLEE_EXTERN PFNGLFRAGMENTLIGHTMODELIVEXTPROC pglFragmentLightModelivEXT;
GLEE_EXTERN PFNGLFRAGMENTLIGHTMODELFVEXTPROC pglFragmentLightModelfvEXT;
GLEE_EXTERN PFNGLFRAGMENTLIGHTIEXTPROC pglFragmentLightiEXT;
GLEE_EXTERN PFNGLFRAGMENTLIGHTFEXTPROC pglFragmentLightfEXT;
GLEE_EXTERN PFNGLFRAGMENTLIGHTIVEXTPROC pglFragmentLightivEXT;
GLEE_EXTERN PFNGLFRAGMENTLIGHTFVEXTPROC pglFragmentLightfvEXT;
GLEE_EXTERN PFNGLGETFRAGMENTLIGHTIVEXTPROC pglGetFragmentLightivEXT;
GLEE_EXTERN PFNGLGETFRAGMENTLIGHTFVEXTPROC pglGetFragmentLightfvEXT;
GLEE_EXTERN PFNGLFRAGMENTMATERIALFEXTPROC pglFragmentMaterialfEXT;
GLEE_EXTERN PFNGLFRAGMENTMATERIALIEXTPROC pglFragmentMaterialiEXT;
GLEE_EXTERN PFNGLFRAGMENTMATERIALFVEXTPROC pglFragmentMaterialfvEXT;
GLEE_EXTERN PFNGLFRAGMENTMATERIALIVEXTPROC pglFragmentMaterialivEXT;
GLEE_EXTERN PFNGLFRAGMENTCOLORMATERIALEXTPROC pglFragmentColorMaterialEXT;
GLEE_EXTERN PFNGLGETFRAGMENTMATERIALFVEXTPROC pglGetFragmentMaterialfvEXT;
GLEE_EXTERN PFNGLGETFRAGMENTMATERIALIVEXTPROC pglGetFragmentMaterialivEXT;
GLEE_EXTERN PFNGLLIGHTENVIEXTPROC pglLightEnviEXT;
#define glFragmentLightModeliEXT pglFragmentLightModeliEXT
#define glFragmentLightModelfEXT pglFragmentLightModelfEXT
#define glFragmentLightModelivEXT pglFragmentLightModelivEXT
#define glFragmentLightModelfvEXT pglFragmentLightModelfvEXT
#define glFragmentLightiEXT pglFragmentLightiEXT
#define glFragmentLightfEXT pglFragmentLightfEXT
#define glFragmentLightivEXT pglFragmentLightivEXT
#define glFragmentLightfvEXT pglFragmentLightfvEXT
#define glGetFragmentLightivEXT pglGetFragmentLightivEXT
#define glGetFragmentLightfvEXT pglGetFragmentLightfvEXT
#define glFragmentMaterialfEXT pglFragmentMaterialfEXT
#define glFragmentMaterialiEXT pglFragmentMaterialiEXT
#define glFragmentMaterialfvEXT pglFragmentMaterialfvEXT
#define glFragmentMaterialivEXT pglFragmentMaterialivEXT
#define glFragmentColorMaterialEXT pglFragmentColorMaterialEXT
#define glGetFragmentMaterialfvEXT pglGetFragmentMaterialfvEXT
#define glGetFragmentMaterialivEXT pglGetFragmentMaterialivEXT
#define glLightEnviEXT pglLightEnviEXT
#endif 

/* GL_EXT_packed_depth_stencil */

#ifndef GL_EXT_packed_depth_stencil
#define GL_EXT_packed_depth_stencil 1
#define __GLEE_GL_EXT_packed_depth_stencil 1
/* Constants */
#define GL_DEPTH_STENCIL_EXT                               0x84F9
#define GL_UNSIGNED_INT_24_8_EXT                           0x84FA
#define GL_DEPTH24_STENCIL8_EXT                            0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT                        0x88F1
#endif 

/* GL_EXT_scene_marker */

#ifndef GL_EXT_scene_marker
#define GL_EXT_scene_marker 1
#define __GLEE_GL_EXT_scene_marker 1
/* Constants */
typedef GLvoid (APIENTRYP PFNGLBEGINSCENEEXTPROC) ();
typedef GLvoid (APIENTRYP PFNGLENDSCENEEXTPROC) ();
GLEE_EXTERN PFNGLBEGINSCENEEXTPROC pglBeginSceneEXT;
GLEE_EXTERN PFNGLENDSCENEEXTPROC pglEndSceneEXT;
#define glBeginSceneEXT pglBeginSceneEXT
#define glEndSceneEXT pglEndSceneEXT
#endif 

/* GL_EXT_stencil_clear_tag */

#ifndef GL_EXT_stencil_clear_tag
#define GL_EXT_stencil_clear_tag 1
#define __GLEE_GL_EXT_stencil_clear_tag 1
/* Constants */
#define GL_STENCIL_TAG_BITS_EXT                            0x88F2
#define GL_STENCIL_CLEAR_TAG_VALUE_EXT                     0x88F3
#endif 

/* GL_EXT_texture_compression_dxt1 */

#ifndef GL_EXT_texture_compression_dxt1
#define GL_EXT_texture_compression_dxt1 1
#define __GLEE_GL_EXT_texture_compression_dxt1 1
/* Constants */
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT                    0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT                   0x83F1
#endif 

/* GL_EXT_texture_env */

#ifndef GL_EXT_texture_env
#define GL_EXT_texture_env 1
#define __GLEE_GL_EXT_texture_env 1
/* Constants */
#define GL_TEXTURE_ENV0_EXT                                0
#define GL_TEXTURE_ENV_MODE_ALPHA_EXT                      0
#define GL_ENV_COPY_EXT                                    0
#define GL_ENV_REPLACE_EXT                                 0
#define GL_ENV_MODULATE_EXT                                0
#define GL_ENV_ADD_EXT                                     0
#define GL_ENV_SUBTRACT_EXT                                0
#define GL_ENV_REVERSE_SUBTRACT_EXT                        0
#define GL_ENV_BLEND_EXT                                   0
#define GL_ENV_REVERSE_BLEND_EXT                           0
#define GL_TEXTURE_ENV_SHIFT_EXT                           0
#endif 

/* GL_EXT_texture_sRGB */

#ifndef GL_EXT_texture_sRGB
#define GL_EXT_texture_sRGB 1
#define __GLEE_GL_EXT_texture_sRGB 1
/* Constants */
#define GL_SRGB_EXT                                        0x8C40
#define GL_SRGB8_EXT                                       0x8C41
#define GL_SRGB_ALPHA_EXT                                  0x8C42
#define GL_SRGB8_ALPHA8_EXT                                0x8C43
#define GL_SLUMINANCE_ALPHA_EXT                            0x8C44
#define GL_SLUMINANCE8_ALPHA8_EXT                          0x8C45
#define GL_SLUMINANCE_EXT                                  0x8C46
#define GL_SLUMINANCE8_EXT                                 0x8C47
#define GL_COMPRESSED_SRGB_EXT                             0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_EXT                       0x8C49
#define GL_COMPRESSED_SLUMINANCE_EXT                       0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT                 0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT                   0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT             0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT             0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT             0x8C4F
#endif 

/* GL_IBM_static_data */

#ifndef GL_IBM_static_data
#define GL_IBM_static_data 1
#define __GLEE_GL_IBM_static_data 1
/* Constants */
#define GL_ALL_STATIC_DATA_IBM                             103060
#define GL_STATIC_VERTEX_ARRAY_IBM                         103061
#endif 

/* GL_MESAX_texture_stack */

#ifndef GL_MESAX_texture_stack
#define GL_MESAX_texture_stack 1
#define __GLEE_GL_MESAX_texture_stack 1
/* Constants */
#define GL_TEXTURE_1D_STACK_MESAX                          0x8759
#define GL_TEXTURE_2D_STACK_MESAX                          0x875A
#define GL_PROXY_TEXTURE_1D_STACK_MESAX                    0x875B
#define GL_PROXY_TEXTURE_2D_STACK_MESAX                    0x875C
#define GL_TEXTURE_1D_STACK_BINDING_MESAX                  0x875D
#define GL_TEXTURE_2D_STACK_BINDING_MESAX                  0x875E
#endif 

/* GL_OES_byte_coordinates */

#ifndef GL_OES_byte_coordinates
#define GL_OES_byte_coordinates 1
#define __GLEE_GL_OES_byte_coordinates 1
/* Constants */
#define GL_BYTE                                            0x1400
#endif 

/* GL_OES_compressed_paletted_texture */

#ifndef GL_OES_compressed_paletted_texture
#define GL_OES_compressed_paletted_texture 1
#define __GLEE_GL_OES_compressed_paletted_texture 1
/* Constants */
#define GL_PALETTE4_RGB8_OES                               0x8B90
#define GL_PALETTE4_RGBA8_OES                              0x8B91
#define GL_PALETTE4_R5_G6_B5_OES                           0x8B92
#define GL_PALETTE4_RGBA4_OES                              0x8B93
#define GL_PALETTE4_RGB5_A1_OES                            0x8B94
#define GL_PALETTE8_RGB8_OES                               0x8B95
#define GL_PALETTE8_RGBA8_OES                              0x8B96
#define GL_PALETTE8_R5_G6_B5_OES                           0x8B97
#define GL_PALETTE8_RGBA4_OES                              0x8B98
#define GL_PALETTE8_RGB5_A1_OES                            0x8B99
#endif 

/* GL_OES_single_precision */

#ifndef GL_OES_single_precision
#define GL_OES_single_precision 1
#define __GLEE_GL_OES_single_precision 1
/* Constants */
typedef GLvoid (APIENTRYP PFNGLDEPTHRANGEFOESPROC) (GLclampf n, GLclampf f);
typedef GLvoid (APIENTRYP PFNGLFRUSTUMFOESPROC) (GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
typedef GLvoid (APIENTRYP PFNGLORTHOFOESPROC) (GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
typedef GLvoid (APIENTRYP PFNGLCLIPPLANEFOESPROC) (GLenum plane, const GLfloat* equation);
typedef GLvoid (APIENTRYP PFNGLGETCLIPPLANEFOESPROC) (GLenum plane, GLfloat* equation);
typedef GLvoid (APIENTRYP PFNGLCLEARDEPTHFOESPROC) (GLclampd depth);
GLEE_EXTERN PFNGLDEPTHRANGEFOESPROC pglDepthRangefOES;
GLEE_EXTERN PFNGLFRUSTUMFOESPROC pglFrustumfOES;
GLEE_EXTERN PFNGLORTHOFOESPROC pglOrthofOES;
GLEE_EXTERN PFNGLCLIPPLANEFOESPROC pglClipPlanefOES;
GLEE_EXTERN PFNGLGETCLIPPLANEFOESPROC pglGetClipPlanefOES;
GLEE_EXTERN PFNGLCLEARDEPTHFOESPROC pglClearDepthfOES;
#define glDepthRangefOES pglDepthRangefOES
#define glFrustumfOES pglFrustumfOES
#define glOrthofOES pglOrthofOES
#define glClipPlanefOES pglClipPlanefOES
#define glGetClipPlanefOES pglGetClipPlanefOES
#define glClearDepthfOES pglClearDepthfOES
#endif 

/* GL_SGIX_pixel_texture_bits */

#ifndef GL_SGIX_pixel_texture_bits
#define GL_SGIX_pixel_texture_bits 1
#define __GLEE_GL_SGIX_pixel_texture_bits 1
/* Constants */
#endif 

/* GL_SGIX_texture_range */

#ifndef GL_SGIX_texture_range
#define GL_SGIX_texture_range 1
#define __GLEE_GL_SGIX_texture_range 1
/* Constants */
#define GL_RGB_SIGNED_SGIX                                 0x85E0
#define GL_RGBA_SIGNED_SGIX                                0x85E1
#define GL_ALPHA_SIGNED_SGIX                               0x85E2
#define GL_LUMINANCE_SIGNED_SGIX                           0x85E3
#define GL_INTENSITY_SIGNED_SGIX                           0x85E4
#define GL_LUMINANCE_ALPHA_SIGNED_SGIX                     0x85E5
#define GL_RGB16_SIGNED_SGIX                               0x85E6
#define GL_RGBA16_SIGNED_SGIX                              0x85E7
#define GL_ALPHA16_SIGNED_SGIX                             0x85E8
#define GL_LUMINANCE16_SIGNED_SGIX                         0x85E9
#define GL_INTENSITY16_SIGNED_SGIX                         0x85EA
#define GL_LUMINANCE16_ALPHA16_SIGNED_SGIX                 0x85EB
#define GL_RGB_EXTENDED_RANGE_SGIX                         0x85EC
#define GL_RGBA_EXTENDED_RANGE_SGIX                        0x85ED
#define GL_ALPHA_EXTENDED_RANGE_SGIX                       0x85EE
#define GL_LUMINANCE_EXTENDED_RANGE_SGIX                   0x85EF
#define GL_INTENSITY_EXTENDED_RANGE_SGIX                   0x85F0
#define GL_LUMINANCE_ALPHA_EXTENDED_RANGE_SGIX             0x85F1
#define GL_RGB16_EXTENDED_RANGE_SGIX                       0x85F2
#define GL_RGBA16_EXTENDED_RANGE_SGIX                      0x85F3
#define GL_ALPHA16_EXTENDED_RANGE_SGIX                     0x85F4
#define GL_LUMINANCE16_EXTENDED_RANGE_SGIX                 0x85F5
#define GL_INTENSITY16_EXTENDED_RANGE_SGIX                 0x85F6
#define GL_LUMINANCE16_ALPHA16_EXTENDED_RANGE_SGIX         0x85F7
#define GL_MIN_LUMINANCE_SGIS                              0x85F8
#define GL_MAX_LUMINANCE_SGIS                              0x85F9
#define GL_MIN_INTENSITY_SGIS                              0x85FA
#define GL_MAX_INTENSITY_SGIS                              0x85FB
#endif 

/* WGL  */

#ifdef WIN32

/* Extension querying variables */

GLEE_EXTERN GLboolean _GLEE_WGL_ARB_buffer_region;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_multisample;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_extensions_string;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_pixel_format;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_make_current_read;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_pbuffer;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_render_texture;
GLEE_EXTERN GLboolean _GLEE_WGL_ARB_pixel_format_float;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_make_current_read;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_pixel_format;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_pbuffer;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_depth_float;
GLEE_EXTERN GLboolean _GLEE_WGL_3DFX_multisample;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_multisample;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_digital_video_control;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_gamma;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_genlock;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_image_buffer;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_swap_frame_lock;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_render_depth_texture;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_render_texture_rectangle;
GLEE_EXTERN GLboolean _GLEE_WGL_ATI_pixel_format_float;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_float_buffer;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_display_color_table;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_extensions_string;
GLEE_EXTERN GLboolean _GLEE_WGL_EXT_swap_control;
GLEE_EXTERN GLboolean _GLEE_WGL_NV_vertex_array_range;
GLEE_EXTERN GLboolean _GLEE_WGL_OML_sync_control;
GLEE_EXTERN GLboolean _GLEE_WGL_I3D_swap_frame_usage;
GLEE_EXTERN GLboolean _GLEE_WGL_3DL_stereo_control;

/* Aliases for extension querying variables */

#define GLEE_WGL_ARB_buffer_region     GLeeEnabled(&_GLEE_WGL_ARB_buffer_region)
#define GLEE_WGL_ARB_multisample     GLeeEnabled(&_GLEE_WGL_ARB_multisample)
#define GLEE_WGL_ARB_extensions_string     GLeeEnabled(&_GLEE_WGL_ARB_extensions_string)
#define GLEE_WGL_ARB_pixel_format     GLeeEnabled(&_GLEE_WGL_ARB_pixel_format)
#define GLEE_WGL_ARB_make_current_read     GLeeEnabled(&_GLEE_WGL_ARB_make_current_read)
#define GLEE_WGL_ARB_pbuffer     GLeeEnabled(&_GLEE_WGL_ARB_pbuffer)
#define GLEE_WGL_ARB_render_texture     GLeeEnabled(&_GLEE_WGL_ARB_render_texture)
#define GLEE_WGL_ARB_pixel_format_float     GLeeEnabled(&_GLEE_WGL_ARB_pixel_format_float)
#define GLEE_WGL_EXT_make_current_read     GLeeEnabled(&_GLEE_WGL_EXT_make_current_read)
#define GLEE_WGL_EXT_pixel_format     GLeeEnabled(&_GLEE_WGL_EXT_pixel_format)
#define GLEE_WGL_EXT_pbuffer     GLeeEnabled(&_GLEE_WGL_EXT_pbuffer)
#define GLEE_WGL_EXT_depth_float     GLeeEnabled(&_GLEE_WGL_EXT_depth_float)
#define GLEE_WGL_3DFX_multisample     GLeeEnabled(&_GLEE_WGL_3DFX_multisample)
#define GLEE_WGL_EXT_multisample     GLeeEnabled(&_GLEE_WGL_EXT_multisample)
#define GLEE_WGL_I3D_digital_video_control     GLeeEnabled(&_GLEE_WGL_I3D_digital_video_control)
#define GLEE_WGL_I3D_gamma     GLeeEnabled(&_GLEE_WGL_I3D_gamma)
#define GLEE_WGL_I3D_genlock     GLeeEnabled(&_GLEE_WGL_I3D_genlock)
#define GLEE_WGL_I3D_image_buffer     GLeeEnabled(&_GLEE_WGL_I3D_image_buffer)
#define GLEE_WGL_I3D_swap_frame_lock     GLeeEnabled(&_GLEE_WGL_I3D_swap_frame_lock)
#define GLEE_WGL_NV_render_depth_texture     GLeeEnabled(&_GLEE_WGL_NV_render_depth_texture)
#define GLEE_WGL_NV_render_texture_rectangle     GLeeEnabled(&_GLEE_WGL_NV_render_texture_rectangle)
#define GLEE_WGL_ATI_pixel_format_float     GLeeEnabled(&_GLEE_WGL_ATI_pixel_format_float)
#define GLEE_WGL_NV_float_buffer     GLeeEnabled(&_GLEE_WGL_NV_float_buffer)
#define GLEE_WGL_EXT_display_color_table     GLeeEnabled(&_GLEE_WGL_EXT_display_color_table)
#define GLEE_WGL_EXT_extensions_string     GLeeEnabled(&_GLEE_WGL_EXT_extensions_string)
#define GLEE_WGL_EXT_swap_control     GLeeEnabled(&_GLEE_WGL_EXT_swap_control)
#define GLEE_WGL_NV_vertex_array_range     GLeeEnabled(&_GLEE_WGL_NV_vertex_array_range)
#define GLEE_WGL_OML_sync_control     GLeeEnabled(&_GLEE_WGL_OML_sync_control)
#define GLEE_WGL_I3D_swap_frame_usage     GLeeEnabled(&_GLEE_WGL_I3D_swap_frame_usage)
#define GLEE_WGL_3DL_stereo_control     GLeeEnabled(&_GLEE_WGL_3DL_stereo_control)

/* WGL_ARB_buffer_region */

#ifndef WGL_ARB_buffer_region
#define WGL_ARB_buffer_region 1
#define __GLEE_WGL_ARB_buffer_region 1
/* Constants */
#define WGL_FRONT_COLOR_BUFFER_BIT_ARB                     0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB                      0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB                           0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB                         0x00000008
typedef HANDLE (APIENTRYP PFNWGLCREATEBUFFERREGIONARBPROC) (HDC hDC, int iLayerPlane, UINT uType);
typedef VOID (APIENTRYP PFNWGLDELETEBUFFERREGIONARBPROC) (HANDLE hRegion);
typedef BOOL (APIENTRYP PFNWGLSAVEBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height);
typedef BOOL (APIENTRYP PFNWGLRESTOREBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
GLEE_EXTERN PFNWGLCREATEBUFFERREGIONARBPROC pwglCreateBufferRegionARB;
GLEE_EXTERN PFNWGLDELETEBUFFERREGIONARBPROC pwglDeleteBufferRegionARB;
GLEE_EXTERN PFNWGLSAVEBUFFERREGIONARBPROC pwglSaveBufferRegionARB;
GLEE_EXTERN PFNWGLRESTOREBUFFERREGIONARBPROC pwglRestoreBufferRegionARB;
#define wglCreateBufferRegionARB pwglCreateBufferRegionARB
#define wglDeleteBufferRegionARB pwglDeleteBufferRegionARB
#define wglSaveBufferRegionARB pwglSaveBufferRegionARB
#define wglRestoreBufferRegionARB pwglRestoreBufferRegionARB
#endif 

/* WGL_ARB_multisample */

#ifndef WGL_ARB_multisample
#define WGL_ARB_multisample 1
#define __GLEE_WGL_ARB_multisample 1
/* Constants */
#define WGL_SAMPLE_BUFFERS_ARB                             0x2041
#define WGL_SAMPLES_ARB                                    0x2042
#endif 

/* WGL_ARB_extensions_string */

#ifndef WGL_ARB_extensions_string
#define WGL_ARB_extensions_string 1
#define __GLEE_WGL_ARB_extensions_string 1
/* Constants */
typedef const char * (APIENTRYP PFNWGLGETEXTENSIONSSTRINGARBPROC) (HDC hdc);
GLEE_EXTERN PFNWGLGETEXTENSIONSSTRINGARBPROC pwglGetExtensionsStringARB;
#define wglGetExtensionsStringARB pwglGetExtensionsStringARB
#endif 

/* WGL_ARB_pixel_format */

#ifndef WGL_ARB_pixel_format
#define WGL_ARB_pixel_format 1
#define __GLEE_WGL_ARB_pixel_format 1
/* Constants */
#define WGL_NUMBER_PIXEL_FORMATS_ARB                       0x2000
#define WGL_DRAW_TO_WINDOW_ARB                             0x2001
#define WGL_DRAW_TO_BITMAP_ARB                             0x2002
#define WGL_ACCELERATION_ARB                               0x2003
#define WGL_NEED_PALETTE_ARB                               0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB                        0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB                         0x2006
#define WGL_SWAP_METHOD_ARB                                0x2007
#define WGL_NUMBER_OVERLAYS_ARB                            0x2008
#define WGL_NUMBER_UNDERLAYS_ARB                           0x2009
#define WGL_TRANSPARENT_ARB                                0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB                      0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB                    0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB                     0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB                    0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB                    0x203B
#define WGL_SHARE_DEPTH_ARB                                0x200C
#define WGL_SHARE_STENCIL_ARB                              0x200D
#define WGL_SHARE_ACCUM_ARB                                0x200E
#define WGL_SUPPORT_GDI_ARB                                0x200F
#define WGL_SUPPORT_OPENGL_ARB                             0x2010
#define WGL_DOUBLE_BUFFER_ARB                              0x2011
#define WGL_STEREO_ARB                                     0x2012
#define WGL_PIXEL_TYPE_ARB                                 0x2013
#define WGL_COLOR_BITS_ARB                                 0x2014
#define WGL_RED_BITS_ARB                                   0x2015
#define WGL_RED_SHIFT_ARB                                  0x2016
#define WGL_GREEN_BITS_ARB                                 0x2017
#define WGL_GREEN_SHIFT_ARB                                0x2018
#define WGL_BLUE_BITS_ARB                                  0x2019
#define WGL_BLUE_SHIFT_ARB                                 0x201A
#define WGL_ALPHA_BITS_ARB                                 0x201B
#define WGL_ALPHA_SHIFT_ARB                                0x201C
#define WGL_ACCUM_BITS_ARB                                 0x201D
#define WGL_ACCUM_RED_BITS_ARB                             0x201E
#define WGL_ACCUM_GREEN_BITS_ARB                           0x201F
#define WGL_ACCUM_BLUE_BITS_ARB                            0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB                           0x2021
#define WGL_DEPTH_BITS_ARB                                 0x2022
#define WGL_STENCIL_BITS_ARB                               0x2023
#define WGL_AUX_BUFFERS_ARB                                0x2024
#define WGL_NO_ACCELERATION_ARB                            0x2025
#define WGL_GENERIC_ACCELERATION_ARB                       0x2026
#define WGL_FULL_ACCELERATION_ARB                          0x2027
#define WGL_SWAP_EXCHANGE_ARB                              0x2028
#define WGL_SWAP_COPY_ARB                                  0x2029
#define WGL_SWAP_UNDEFINED_ARB                             0x202A
#define WGL_TYPE_RGBA_ARB                                  0x202B
#define WGL_TYPE_COLORINDEX_ARB                            0x202C
typedef BOOL (APIENTRYP PFNWGLGETPIXELFORMATATTRIBIVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues);
typedef BOOL (APIENTRYP PFNWGLGETPIXELFORMATATTRIBFVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues);
typedef BOOL (APIENTRYP PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats);
GLEE_EXTERN PFNWGLGETPIXELFORMATATTRIBIVARBPROC pwglGetPixelFormatAttribivARB;
GLEE_EXTERN PFNWGLGETPIXELFORMATATTRIBFVARBPROC pwglGetPixelFormatAttribfvARB;
GLEE_EXTERN PFNWGLCHOOSEPIXELFORMATARBPROC pwglChoosePixelFormatARB;
#define wglGetPixelFormatAttribivARB pwglGetPixelFormatAttribivARB
#define wglGetPixelFormatAttribfvARB pwglGetPixelFormatAttribfvARB
#define wglChoosePixelFormatARB pwglChoosePixelFormatARB
#endif 

/* WGL_ARB_make_current_read */

#ifndef WGL_ARB_make_current_read
#define WGL_ARB_make_current_read 1
#define __GLEE_WGL_ARB_make_current_read 1
/* Constants */
#define ERROR_INVALID_PIXEL_TYPE_ARB                       0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB             0x2054
typedef BOOL (APIENTRYP PFNWGLMAKECONTEXTCURRENTARBPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
typedef HDC (APIENTRYP PFNWGLGETCURRENTREADDCARBPROC) ();
GLEE_EXTERN PFNWGLMAKECONTEXTCURRENTARBPROC pwglMakeContextCurrentARB;
GLEE_EXTERN PFNWGLGETCURRENTREADDCARBPROC pwglGetCurrentReadDCARB;
#define wglMakeContextCurrentARB pwglMakeContextCurrentARB
#define wglGetCurrentReadDCARB pwglGetCurrentReadDCARB
#endif 

/* WGL_ARB_pbuffer */

#ifndef WGL_ARB_pbuffer
#define WGL_ARB_pbuffer 1
#define __GLEE_WGL_ARB_pbuffer 1
/* Constants */
#define WGL_DRAW_TO_PBUFFER_ARB                            0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB                         0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB                          0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB                         0x2030
#define WGL_PBUFFER_LARGEST_ARB                            0x2033
#define WGL_PBUFFER_WIDTH_ARB                              0x2034
#define WGL_PBUFFER_HEIGHT_ARB                             0x2035
#define WGL_PBUFFER_LOST_ARB                               0x2036
typedef HPBUFFERARB (APIENTRYP PFNWGLCREATEPBUFFERARBPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList);
typedef HDC (APIENTRYP PFNWGLGETPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer);
typedef int (APIENTRYP PFNWGLRELEASEPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer, HDC hDC);
typedef BOOL (APIENTRYP PFNWGLDESTROYPBUFFERARBPROC) (HPBUFFERARB hPbuffer);
typedef BOOL (APIENTRYP PFNWGLQUERYPBUFFERARBPROC) (HPBUFFERARB hPbuffer, int iAttribute, int * piValue);
GLEE_EXTERN PFNWGLCREATEPBUFFERARBPROC pwglCreatePbufferARB;
GLEE_EXTERN PFNWGLGETPBUFFERDCARBPROC pwglGetPbufferDCARB;
GLEE_EXTERN PFNWGLRELEASEPBUFFERDCARBPROC pwglReleasePbufferDCARB;
GLEE_EXTERN PFNWGLDESTROYPBUFFERARBPROC pwglDestroyPbufferARB;
GLEE_EXTERN PFNWGLQUERYPBUFFERARBPROC pwglQueryPbufferARB;
#define wglCreatePbufferARB pwglCreatePbufferARB
#define wglGetPbufferDCARB pwglGetPbufferDCARB
#define wglReleasePbufferDCARB pwglReleasePbufferDCARB
#define wglDestroyPbufferARB pwglDestroyPbufferARB
#define wglQueryPbufferARB pwglQueryPbufferARB
#endif 

/* WGL_ARB_render_texture */

#ifndef WGL_ARB_render_texture
#define WGL_ARB_render_texture 1
#define __GLEE_WGL_ARB_render_texture 1
/* Constants */
#define WGL_BIND_TO_TEXTURE_RGB_ARB                        0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB                       0x2071
#define WGL_TEXTURE_FORMAT_ARB                             0x2072
#define WGL_TEXTURE_TARGET_ARB                             0x2073
#define WGL_MIPMAP_TEXTURE_ARB                             0x2074
#define WGL_TEXTURE_RGB_ARB                                0x2075
#define WGL_TEXTURE_RGBA_ARB                               0x2076
#define WGL_NO_TEXTURE_ARB                                 0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB                           0x2078
#define WGL_TEXTURE_1D_ARB                                 0x2079
#define WGL_TEXTURE_2D_ARB                                 0x207A
#define WGL_MIPMAP_LEVEL_ARB                               0x207B
#define WGL_CUBE_MAP_FACE_ARB                              0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB                0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB                0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB                0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB                0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB                0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB                0x2082
#define WGL_FRONT_LEFT_ARB                                 0x2083
#define WGL_FRONT_RIGHT_ARB                                0x2084
#define WGL_BACK_LEFT_ARB                                  0x2085
#define WGL_BACK_RIGHT_ARB                                 0x2086
#define WGL_AUX0_ARB                                       0x2087
#define WGL_AUX1_ARB                                       0x2088
#define WGL_AUX2_ARB                                       0x2089
#define WGL_AUX3_ARB                                       0x208A
#define WGL_AUX4_ARB                                       0x208B
#define WGL_AUX5_ARB                                       0x208C
#define WGL_AUX6_ARB                                       0x208D
#define WGL_AUX7_ARB                                       0x208E
#define WGL_AUX8_ARB                                       0x208F
#define WGL_AUX9_ARB                                       0x2090
typedef BOOL (APIENTRYP PFNWGLBINDTEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
typedef BOOL (APIENTRYP PFNWGLRELEASETEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
typedef BOOL (APIENTRYP PFNWGLSETPBUFFERATTRIBARBPROC) (HPBUFFERARB hPbuffer, const int * piAttribList);
GLEE_EXTERN PFNWGLBINDTEXIMAGEARBPROC pwglBindTexImageARB;
GLEE_EXTERN PFNWGLRELEASETEXIMAGEARBPROC pwglReleaseTexImageARB;
GLEE_EXTERN PFNWGLSETPBUFFERATTRIBARBPROC pwglSetPbufferAttribARB;
#define wglBindTexImageARB pwglBindTexImageARB
#define wglReleaseTexImageARB pwglReleaseTexImageARB
#define wglSetPbufferAttribARB pwglSetPbufferAttribARB
#endif 

/* WGL_ARB_pixel_format_float */

#ifndef WGL_ARB_pixel_format_float
#define WGL_ARB_pixel_format_float 1
#define __GLEE_WGL_ARB_pixel_format_float 1
/* Constants */
#define WGL_TYPE_RGBA_FLOAT_ARB                            0x21A0
#endif 

/* WGL_EXT_make_current_read */

#ifndef WGL_EXT_make_current_read
#define WGL_EXT_make_current_read 1
#define __GLEE_WGL_EXT_make_current_read 1
/* Constants */
#define ERROR_INVALID_PIXEL_TYPE_EXT                       0x2043
typedef BOOL (APIENTRYP PFNWGLMAKECONTEXTCURRENTEXTPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
typedef HDC (APIENTRYP PFNWGLGETCURRENTREADDCEXTPROC) ();
GLEE_EXTERN PFNWGLMAKECONTEXTCURRENTEXTPROC pwglMakeContextCurrentEXT;
GLEE_EXTERN PFNWGLGETCURRENTREADDCEXTPROC pwglGetCurrentReadDCEXT;
#define wglMakeContextCurrentEXT pwglMakeContextCurrentEXT
#define wglGetCurrentReadDCEXT pwglGetCurrentReadDCEXT
#endif 

/* WGL_EXT_pixel_format */

#ifndef WGL_EXT_pixel_format
#define WGL_EXT_pixel_format 1
#define __GLEE_WGL_EXT_pixel_format 1
/* Constants */
#define WGL_NUMBER_PIXEL_FORMATS_EXT                       0x2000
#define WGL_DRAW_TO_WINDOW_EXT                             0x2001
#define WGL_DRAW_TO_BITMAP_EXT                             0x2002
#define WGL_ACCELERATION_EXT                               0x2003
#define WGL_NEED_PALETTE_EXT                               0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT                        0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT                         0x2006
#define WGL_SWAP_METHOD_EXT                                0x2007
#define WGL_NUMBER_OVERLAYS_EXT                            0x2008
#define WGL_NUMBER_UNDERLAYS_EXT                           0x2009
#define WGL_TRANSPARENT_EXT                                0x200A
#define WGL_TRANSPARENT_VALUE_EXT                          0x200B
#define WGL_SHARE_DEPTH_EXT                                0x200C
#define WGL_SHARE_STENCIL_EXT                              0x200D
#define WGL_SHARE_ACCUM_EXT                                0x200E
#define WGL_SUPPORT_GDI_EXT                                0x200F
#define WGL_SUPPORT_OPENGL_EXT                             0x2010
#define WGL_DOUBLE_BUFFER_EXT                              0x2011
#define WGL_STEREO_EXT                                     0x2012
#define WGL_PIXEL_TYPE_EXT                                 0x2013
#define WGL_COLOR_BITS_EXT                                 0x2014
#define WGL_RED_BITS_EXT                                   0x2015
#define WGL_RED_SHIFT_EXT                                  0x2016
#define WGL_GREEN_BITS_EXT                                 0x2017
#define WGL_GREEN_SHIFT_EXT                                0x2018
#define WGL_BLUE_BITS_EXT                                  0x2019
#define WGL_BLUE_SHIFT_EXT                                 0x201A
#define WGL_ALPHA_BITS_EXT                                 0x201B
#define WGL_ALPHA_SHIFT_EXT                                0x201C
#define WGL_ACCUM_BITS_EXT                                 0x201D
#define WGL_ACCUM_RED_BITS_EXT                             0x201E
#define WGL_ACCUM_GREEN_BITS_EXT                           0x201F
#define WGL_ACCUM_BLUE_BITS_EXT                            0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT                           0x2021
#define WGL_DEPTH_BITS_EXT                                 0x2022
#define WGL_STENCIL_BITS_EXT                               0x2023
#define WGL_AUX_BUFFERS_EXT                                0x2024
#define WGL_NO_ACCELERATION_EXT                            0x2025
#define WGL_GENERIC_ACCELERATION_EXT                       0x2026
#define WGL_FULL_ACCELERATION_EXT                          0x2027
#define WGL_SWAP_EXCHANGE_EXT                              0x2028
#define WGL_SWAP_COPY_EXT                                  0x2029
#define WGL_SWAP_UNDEFINED_EXT                             0x202A
#define WGL_TYPE_RGBA_EXT                                  0x202B
#define WGL_TYPE_COLORINDEX_EXT                            0x202C
typedef BOOL (APIENTRYP PFNWGLGETPIXELFORMATATTRIBIVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, int * piValues);
typedef BOOL (APIENTRYP PFNWGLGETPIXELFORMATATTRIBFVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, FLOAT * pfValues);
typedef BOOL (APIENTRYP PFNWGLCHOOSEPIXELFORMATEXTPROC) (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats);
GLEE_EXTERN PFNWGLGETPIXELFORMATATTRIBIVEXTPROC pwglGetPixelFormatAttribivEXT;
GLEE_EXTERN PFNWGLGETPIXELFORMATATTRIBFVEXTPROC pwglGetPixelFormatAttribfvEXT;
GLEE_EXTERN PFNWGLCHOOSEPIXELFORMATEXTPROC pwglChoosePixelFormatEXT;
#define wglGetPixelFormatAttribivEXT pwglGetPixelFormatAttribivEXT
#define wglGetPixelFormatAttribfvEXT pwglGetPixelFormatAttribfvEXT
#define wglChoosePixelFormatEXT pwglChoosePixelFormatEXT
#endif 

/* WGL_EXT_pbuffer */

#ifndef WGL_EXT_pbuffer
#define WGL_EXT_pbuffer 1
#define __GLEE_WGL_EXT_pbuffer 1
/* Constants */
#define WGL_DRAW_TO_PBUFFER_EXT                            0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT                         0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT                          0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT                         0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT                      0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT                     0x2032
#define WGL_PBUFFER_LARGEST_EXT                            0x2033
#define WGL_PBUFFER_WIDTH_EXT                              0x2034
#define WGL_PBUFFER_HEIGHT_EXT                             0x2035
typedef HPBUFFEREXT (APIENTRYP PFNWGLCREATEPBUFFEREXTPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList);
typedef HDC (APIENTRYP PFNWGLGETPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer);
typedef int (APIENTRYP PFNWGLRELEASEPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer, HDC hDC);
typedef BOOL (APIENTRYP PFNWGLDESTROYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer);
typedef BOOL (APIENTRYP PFNWGLQUERYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer, int iAttribute, int * piValue);
GLEE_EXTERN PFNWGLCREATEPBUFFEREXTPROC pwglCreatePbufferEXT;
GLEE_EXTERN PFNWGLGETPBUFFERDCEXTPROC pwglGetPbufferDCEXT;
GLEE_EXTERN PFNWGLRELEASEPBUFFERDCEXTPROC pwglReleasePbufferDCEXT;
GLEE_EXTERN PFNWGLDESTROYPBUFFEREXTPROC pwglDestroyPbufferEXT;
GLEE_EXTERN PFNWGLQUERYPBUFFEREXTPROC pwglQueryPbufferEXT;
#define wglCreatePbufferEXT pwglCreatePbufferEXT
#define wglGetPbufferDCEXT pwglGetPbufferDCEXT
#define wglReleasePbufferDCEXT pwglReleasePbufferDCEXT
#define wglDestroyPbufferEXT pwglDestroyPbufferEXT
#define wglQueryPbufferEXT pwglQueryPbufferEXT
#endif 

/* WGL_EXT_depth_float */

#ifndef WGL_EXT_depth_float
#define WGL_EXT_depth_float 1
#define __GLEE_WGL_EXT_depth_float 1
/* Constants */
#define WGL_DEPTH_FLOAT_EXT                                0x2040
#endif 

/* WGL_3DFX_multisample */

#ifndef WGL_3DFX_multisample
#define WGL_3DFX_multisample 1
#define __GLEE_WGL_3DFX_multisample 1
/* Constants */
#define WGL_SAMPLE_BUFFERS_3DFX                            0x2060
#define WGL_SAMPLES_3DFX                                   0x2061
#endif 

/* WGL_EXT_multisample */

#ifndef WGL_EXT_multisample
#define WGL_EXT_multisample 1
#define __GLEE_WGL_EXT_multisample 1
/* Constants */
#define WGL_SAMPLE_BUFFERS_EXT                             0x2041
#define WGL_SAMPLES_EXT                                    0x2042
#endif 

/* WGL_I3D_digital_video_control */

#ifndef WGL_I3D_digital_video_control
#define WGL_I3D_digital_video_control 1
#define __GLEE_WGL_I3D_digital_video_control 1
/* Constants */
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D     0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D           0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D              0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D              0x2053
typedef BOOL (APIENTRYP PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int * piValue);
typedef BOOL (APIENTRYP PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int * piValue);
GLEE_EXTERN PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC pwglGetDigitalVideoParametersI3D;
GLEE_EXTERN PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC pwglSetDigitalVideoParametersI3D;
#define wglGetDigitalVideoParametersI3D pwglGetDigitalVideoParametersI3D
#define wglSetDigitalVideoParametersI3D pwglSetDigitalVideoParametersI3D
#endif 

/* WGL_I3D_gamma */

#ifndef WGL_I3D_gamma
#define WGL_I3D_gamma 1
#define __GLEE_WGL_I3D_gamma 1
/* Constants */
#define WGL_GAMMA_TABLE_SIZE_I3D                           0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D                      0x204F
typedef BOOL (APIENTRYP PFNWGLGETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int * piValue);
typedef BOOL (APIENTRYP PFNWGLSETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int * piValue);
typedef BOOL (APIENTRYP PFNWGLGETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, USHORT * puRed, USHORT * puGreen, USHORT * puBlue);
typedef BOOL (APIENTRYP PFNWGLSETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, const USHORT * puRed, const USHORT * puGreen, const USHORT * puBlue);
GLEE_EXTERN PFNWGLGETGAMMATABLEPARAMETERSI3DPROC pwglGetGammaTableParametersI3D;
GLEE_EXTERN PFNWGLSETGAMMATABLEPARAMETERSI3DPROC pwglSetGammaTableParametersI3D;
GLEE_EXTERN PFNWGLGETGAMMATABLEI3DPROC pwglGetGammaTableI3D;
GLEE_EXTERN PFNWGLSETGAMMATABLEI3DPROC pwglSetGammaTableI3D;
#define wglGetGammaTableParametersI3D pwglGetGammaTableParametersI3D
#define wglSetGammaTableParametersI3D pwglSetGammaTableParametersI3D
#define wglGetGammaTableI3D pwglGetGammaTableI3D
#define wglSetGammaTableI3D pwglSetGammaTableI3D
#endif 

/* WGL_I3D_genlock */

#ifndef WGL_I3D_genlock
#define WGL_I3D_genlock 1
#define __GLEE_WGL_I3D_genlock 1
/* Constants */
#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D                   0x2044
#define WGL_GENLOCK_SOURCE_EXTENAL_SYNC_I3D                0x2045
#define WGL_GENLOCK_SOURCE_EXTENAL_FIELD_I3D               0x2046
#define WGL_GENLOCK_SOURCE_EXTENAL_TTL_I3D                 0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D                0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D               0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D                0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D                 0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D                   0x204C
typedef BOOL (APIENTRYP PFNWGLENABLEGENLOCKI3DPROC) (HDC hDC);
typedef BOOL (APIENTRYP PFNWGLDISABLEGENLOCKI3DPROC) (HDC hDC);
typedef BOOL (APIENTRYP PFNWGLISENABLEDGENLOCKI3DPROC) (HDC hDC, BOOL * pFlag);
typedef BOOL (APIENTRYP PFNWGLGENLOCKSOURCEI3DPROC) (HDC hDC, UINT uSource);
typedef BOOL (APIENTRYP PFNWGLGETGENLOCKSOURCEI3DPROC) (HDC hDC, UINT * uSource);
typedef BOOL (APIENTRYP PFNWGLGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT uEdge);
typedef BOOL (APIENTRYP PFNWGLGETGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT * uEdge);
typedef BOOL (APIENTRYP PFNWGLGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT uRate);
typedef BOOL (APIENTRYP PFNWGLGETGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT * uRate);
typedef BOOL (APIENTRYP PFNWGLGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT uDelay);
typedef BOOL (APIENTRYP PFNWGLGETGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT * uDelay);
typedef BOOL (APIENTRYP PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) (HDC hDC, UINT * uMaxLineDelay, UINT * uMaxPixelDelay);
GLEE_EXTERN PFNWGLENABLEGENLOCKI3DPROC pwglEnableGenlockI3D;
GLEE_EXTERN PFNWGLDISABLEGENLOCKI3DPROC pwglDisableGenlockI3D;
GLEE_EXTERN PFNWGLISENABLEDGENLOCKI3DPROC pwglIsEnabledGenlockI3D;
GLEE_EXTERN PFNWGLGENLOCKSOURCEI3DPROC pwglGenlockSourceI3D;
GLEE_EXTERN PFNWGLGETGENLOCKSOURCEI3DPROC pwglGetGenlockSourceI3D;
GLEE_EXTERN PFNWGLGENLOCKSOURCEEDGEI3DPROC pwglGenlockSourceEdgeI3D;
GLEE_EXTERN PFNWGLGETGENLOCKSOURCEEDGEI3DPROC pwglGetGenlockSourceEdgeI3D;
GLEE_EXTERN PFNWGLGENLOCKSAMPLERATEI3DPROC pwglGenlockSampleRateI3D;
GLEE_EXTERN PFNWGLGETGENLOCKSAMPLERATEI3DPROC pwglGetGenlockSampleRateI3D;
GLEE_EXTERN PFNWGLGENLOCKSOURCEDELAYI3DPROC pwglGenlockSourceDelayI3D;
GLEE_EXTERN PFNWGLGETGENLOCKSOURCEDELAYI3DPROC pwglGetGenlockSourceDelayI3D;
GLEE_EXTERN PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC pwglQueryGenlockMaxSourceDelayI3D;
#define wglEnableGenlockI3D pwglEnableGenlockI3D
#define wglDisableGenlockI3D pwglDisableGenlockI3D
#define wglIsEnabledGenlockI3D pwglIsEnabledGenlockI3D
#define wglGenlockSourceI3D pwglGenlockSourceI3D
#define wglGetGenlockSourceI3D pwglGetGenlockSourceI3D
#define wglGenlockSourceEdgeI3D pwglGenlockSourceEdgeI3D
#define wglGetGenlockSourceEdgeI3D pwglGetGenlockSourceEdgeI3D
#define wglGenlockSampleRateI3D pwglGenlockSampleRateI3D
#define wglGetGenlockSampleRateI3D pwglGetGenlockSampleRateI3D
#define wglGenlockSourceDelayI3D pwglGenlockSourceDelayI3D
#define wglGetGenlockSourceDelayI3D pwglGetGenlockSourceDelayI3D
#define wglQueryGenlockMaxSourceDelayI3D pwglQueryGenlockMaxSourceDelayI3D
#endif 

/* WGL_I3D_image_buffer */

#ifndef WGL_I3D_image_buffer
#define WGL_I3D_image_buffer 1
#define __GLEE_WGL_I3D_image_buffer 1
/* Constants */
#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D                    0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D                          0x00000002
typedef LPVOID (APIENTRYP PFNWGLCREATEIMAGEBUFFERI3DPROC) (HDC hDC, DWORD dwSize, UINT uFlags);
typedef BOOL (APIENTRYP PFNWGLDESTROYIMAGEBUFFERI3DPROC) (HDC hDC, LPVOID pAddress);
typedef BOOL (APIENTRYP PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const HANDLE * pEvent, const LPVOID * pAddress, const DWORD * pSize, UINT count);
typedef BOOL (APIENTRYP PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const LPVOID * pAddress, UINT count);
GLEE_EXTERN PFNWGLCREATEIMAGEBUFFERI3DPROC pwglCreateImageBufferI3D;
GLEE_EXTERN PFNWGLDESTROYIMAGEBUFFERI3DPROC pwglDestroyImageBufferI3D;
GLEE_EXTERN PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC pwglAssociateImageBufferEventsI3D;
GLEE_EXTERN PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC pwglReleaseImageBufferEventsI3D;
#define wglCreateImageBufferI3D pwglCreateImageBufferI3D
#define wglDestroyImageBufferI3D pwglDestroyImageBufferI3D
#define wglAssociateImageBufferEventsI3D pwglAssociateImageBufferEventsI3D
#define wglReleaseImageBufferEventsI3D pwglReleaseImageBufferEventsI3D
#endif 

/* WGL_I3D_swap_frame_lock */

#ifndef WGL_I3D_swap_frame_lock
#define WGL_I3D_swap_frame_lock 1
#define __GLEE_WGL_I3D_swap_frame_lock 1
/* Constants */
typedef BOOL (APIENTRYP PFNWGLENABLEFRAMELOCKI3DPROC) ();
typedef BOOL (APIENTRYP PFNWGLDISABLEFRAMELOCKI3DPROC) ();
typedef BOOL (APIENTRYP PFNWGLISENABLEDFRAMELOCKI3DPROC) (BOOL * pFlag);
typedef BOOL (APIENTRYP PFNWGLQUERYFRAMELOCKMASTERI3DPROC) (BOOL * pFlag);
GLEE_EXTERN PFNWGLENABLEFRAMELOCKI3DPROC pwglEnableFrameLockI3D;
GLEE_EXTERN PFNWGLDISABLEFRAMELOCKI3DPROC pwglDisableFrameLockI3D;
GLEE_EXTERN PFNWGLISENABLEDFRAMELOCKI3DPROC pwglIsEnabledFrameLockI3D;
GLEE_EXTERN PFNWGLQUERYFRAMELOCKMASTERI3DPROC pwglQueryFrameLockMasterI3D;
#define wglEnableFrameLockI3D pwglEnableFrameLockI3D
#define wglDisableFrameLockI3D pwglDisableFrameLockI3D
#define wglIsEnabledFrameLockI3D pwglIsEnabledFrameLockI3D
#define wglQueryFrameLockMasterI3D pwglQueryFrameLockMasterI3D
#endif 

/* WGL_NV_render_depth_texture */

#ifndef WGL_NV_render_depth_texture
#define WGL_NV_render_depth_texture 1
#define __GLEE_WGL_NV_render_depth_texture 1
/* Constants */
#define WGL_BIND_TO_TEXTURE_DEPTH_NV                       0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV             0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV                        0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV                     0x20A6
#define WGL_DEPTH_COMPONENT_NV                             0x20A7
#endif 

/* WGL_NV_render_texture_rectangle */

#ifndef WGL_NV_render_texture_rectangle
#define WGL_NV_render_texture_rectangle 1
#define __GLEE_WGL_NV_render_texture_rectangle 1
/* Constants */
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV               0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV              0x20A1
#define WGL_TEXTURE_RECTANGLE_NV                           0x20A2
#endif 

/* WGL_ATI_pixel_format_float */

#ifndef WGL_ATI_pixel_format_float
#define WGL_ATI_pixel_format_float 1
#define __GLEE_WGL_ATI_pixel_format_float 1
/* Constants */
#define WGL_TYPE_RGBA_FLOAT_ATI                            0x21A0
#endif 

/* WGL_NV_float_buffer */

#ifndef WGL_NV_float_buffer
#define WGL_NV_float_buffer 1
#define __GLEE_WGL_NV_float_buffer 1
/* Constants */
#define WGL_FLOAT_COMPONENTS_NV                            0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV           0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV          0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV         0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV        0x20B4
#define WGL_TEXTURE_FLOAT_R_NV                             0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV                            0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV                           0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV                          0x20B8
#endif 

/* WGL_EXT_display_color_table */

#ifndef WGL_EXT_display_color_table
#define WGL_EXT_display_color_table 1
#define __GLEE_WGL_EXT_display_color_table 1
/* Constants */
typedef GLboolean (APIENTRYP PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC) (GLushort id);
typedef GLboolean (APIENTRYP PFNWGLLOADDISPLAYCOLORTABLEEXTPROC) (const GLushort * table, GLuint length);
typedef GLboolean (APIENTRYP PFNWGLBINDDISPLAYCOLORTABLEEXTPROC) (GLushort id);
typedef VOID (APIENTRYP PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC) (GLushort id);
GLEE_EXTERN PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC pwglCreateDisplayColorTableEXT;
GLEE_EXTERN PFNWGLLOADDISPLAYCOLORTABLEEXTPROC pwglLoadDisplayColorTableEXT;
GLEE_EXTERN PFNWGLBINDDISPLAYCOLORTABLEEXTPROC pwglBindDisplayColorTableEXT;
GLEE_EXTERN PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC pwglDestroyDisplayColorTableEXT;
#define wglCreateDisplayColorTableEXT pwglCreateDisplayColorTableEXT
#define wglLoadDisplayColorTableEXT pwglLoadDisplayColorTableEXT
#define wglBindDisplayColorTableEXT pwglBindDisplayColorTableEXT
#define wglDestroyDisplayColorTableEXT pwglDestroyDisplayColorTableEXT
#endif 

/* WGL_EXT_extensions_string */

#ifndef WGL_EXT_extensions_string
#define WGL_EXT_extensions_string 1
#define __GLEE_WGL_EXT_extensions_string 1
/* Constants */
typedef const char * (APIENTRYP PFNWGLGETEXTENSIONSSTRINGEXTPROC) ();
GLEE_EXTERN PFNWGLGETEXTENSIONSSTRINGEXTPROC pwglGetExtensionsStringEXT;
#define wglGetExtensionsStringEXT pwglGetExtensionsStringEXT
#endif 

/* WGL_EXT_swap_control */

#ifndef WGL_EXT_swap_control
#define WGL_EXT_swap_control 1
#define __GLEE_WGL_EXT_swap_control 1
/* Constants */
typedef BOOL (APIENTRYP PFNWGLSWAPINTERVALEXTPROC) (int interval);
typedef int (APIENTRYP PFNWGLGETSWAPINTERVALEXTPROC) ();
GLEE_EXTERN PFNWGLSWAPINTERVALEXTPROC pwglSwapIntervalEXT;
GLEE_EXTERN PFNWGLGETSWAPINTERVALEXTPROC pwglGetSwapIntervalEXT;
#define wglSwapIntervalEXT pwglSwapIntervalEXT
#define wglGetSwapIntervalEXT pwglGetSwapIntervalEXT
#endif 

/* WGL_NV_vertex_array_range */

#ifndef WGL_NV_vertex_array_range
#define WGL_NV_vertex_array_range 1
#define __GLEE_WGL_NV_vertex_array_range 1
/* Constants */
typedef void* (APIENTRYP PFNWGLALLOCATEMEMORYNVPROC) (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
typedef void (APIENTRYP PFNWGLFREEMEMORYNVPROC) (void * pointer);
GLEE_EXTERN PFNWGLALLOCATEMEMORYNVPROC pwglAllocateMemoryNV;
GLEE_EXTERN PFNWGLFREEMEMORYNVPROC pwglFreeMemoryNV;
#define wglAllocateMemoryNV pwglAllocateMemoryNV
#define wglFreeMemoryNV pwglFreeMemoryNV
#endif 

/* WGL_OML_sync_control */

#ifndef WGL_OML_sync_control
#define WGL_OML_sync_control 1
#define __GLEE_WGL_OML_sync_control 1
/* Constants */
typedef BOOL (APIENTRYP PFNWGLGETSYNCVALUESOMLPROC) (HDC hdc, INT64 * ust, INT64 * msc, INT64 * sbc);
typedef BOOL (APIENTRYP PFNWGLGETMSCRATEOMLPROC) (HDC hdc, INT32 * numerator, INT32 * denominator);
typedef INT64 (APIENTRYP PFNWGLSWAPBUFFERSMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
typedef INT64 (APIENTRYP PFNWGLSWAPLAYERBUFFERSMSCOMLPROC) (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
typedef BOOL (APIENTRYP PFNWGLWAITFORMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 * ust, INT64 * msc, INT64 * sbc);
typedef BOOL (APIENTRYP PFNWGLWAITFORSBCOMLPROC) (HDC hdc, INT64 target_sbc, INT64 * ust, INT64 * msc, INT64 * sbc);
GLEE_EXTERN PFNWGLGETSYNCVALUESOMLPROC pwglGetSyncValuesOML;
GLEE_EXTERN PFNWGLGETMSCRATEOMLPROC pwglGetMscRateOML;
GLEE_EXTERN PFNWGLSWAPBUFFERSMSCOMLPROC pwglSwapBuffersMscOML;
GLEE_EXTERN PFNWGLSWAPLAYERBUFFERSMSCOMLPROC pwglSwapLayerBuffersMscOML;
GLEE_EXTERN PFNWGLWAITFORMSCOMLPROC pwglWaitForMscOML;
GLEE_EXTERN PFNWGLWAITFORSBCOMLPROC pwglWaitForSbcOML;
#define wglGetSyncValuesOML pwglGetSyncValuesOML
#define wglGetMscRateOML pwglGetMscRateOML
#define wglSwapBuffersMscOML pwglSwapBuffersMscOML
#define wglSwapLayerBuffersMscOML pwglSwapLayerBuffersMscOML
#define wglWaitForMscOML pwglWaitForMscOML
#define wglWaitForSbcOML pwglWaitForSbcOML
#endif 

/* WGL_I3D_swap_frame_usage */

#ifndef WGL_I3D_swap_frame_usage
#define WGL_I3D_swap_frame_usage 1
#define __GLEE_WGL_I3D_swap_frame_usage 1
/* Constants */
typedef BOOL (APIENTRYP PFNWGLGETFRAMEUSAGEI3DPROC) (float * pUsage);
typedef BOOL (APIENTRYP PFNWGLBEGINFRAMETRACKINGI3DPROC) ();
typedef BOOL (APIENTRYP PFNWGLENDFRAMETRACKINGI3DPROC) ();
typedef BOOL (APIENTRYP PFNWGLQUERYFRAMETRACKINGI3DPROC) (DWORD * pFrameCount, DWORD * pMissedFrames, float * pLastMissedUsage);
GLEE_EXTERN PFNWGLGETFRAMEUSAGEI3DPROC pwglGetFrameUsageI3D;
GLEE_EXTERN PFNWGLBEGINFRAMETRACKINGI3DPROC pwglBeginFrameTrackingI3D;
GLEE_EXTERN PFNWGLENDFRAMETRACKINGI3DPROC pwglEndFrameTrackingI3D;
GLEE_EXTERN PFNWGLQUERYFRAMETRACKINGI3DPROC pwglQueryFrameTrackingI3D;
#define wglGetFrameUsageI3D pwglGetFrameUsageI3D
#define wglBeginFrameTrackingI3D pwglBeginFrameTrackingI3D
#define wglEndFrameTrackingI3D pwglEndFrameTrackingI3D
#define wglQueryFrameTrackingI3D pwglQueryFrameTrackingI3D
#endif 

/* WGL_3DL_stereo_control */

#ifndef WGL_3DL_stereo_control
#define WGL_3DL_stereo_control 1
#define __GLEE_WGL_3DL_stereo_control 1
/* Constants */
#define WGL_STEREO_EMITTER_ENABLE_3DL                      0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL                     0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL                     0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL                     0x2058
typedef BOOL (APIENTRYP PFNWGLSETSTEREOEMITTERSTATE3DLPROC) (HDC hDC, UINT uState);
GLEE_EXTERN PFNWGLSETSTEREOEMITTERSTATE3DLPROC pwglSetStereoEmitterState3DL;
#define wglSetStereoEmitterState3DL pwglSetStereoEmitterState3DL
#endif 
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else /* GLX */

/* Extension querying variables */

GLEE_EXTERN GLboolean _GLEE_GLX_VERSION_1_3;
GLEE_EXTERN GLboolean _GLEE_GLX_VERSION_1_4;
GLEE_EXTERN GLboolean _GLEE_GLX_ARB_multisample;
GLEE_EXTERN GLboolean _GLEE_GLX_ARB_fbconfig_float;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIS_multisample;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_visual_info;
GLEE_EXTERN GLboolean _GLEE_GLX_SGI_swap_control;
GLEE_EXTERN GLboolean _GLEE_GLX_SGI_video_sync;
GLEE_EXTERN GLboolean _GLEE_GLX_SGI_make_current_read;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_visual_rating;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_import_context;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_fbconfig;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_pbuffer;
GLEE_EXTERN GLboolean _GLEE_GLX_SGI_cushion;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_video_resize;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_swap_group;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_swap_barrier;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIS_blended_overlay;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIS_shared_multisample;
GLEE_EXTERN GLboolean _GLEE_GLX_SUN_get_transparent_index;
GLEE_EXTERN GLboolean _GLEE_GLX_3DFX_multisample;
GLEE_EXTERN GLboolean _GLEE_GLX_MESA_copy_sub_buffer;
GLEE_EXTERN GLboolean _GLEE_GLX_MESA_pixmap_colormap;
GLEE_EXTERN GLboolean _GLEE_GLX_MESA_release_buffers;
GLEE_EXTERN GLboolean _GLEE_GLX_MESA_set_3dfx_mode;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_visual_select_group;
GLEE_EXTERN GLboolean _GLEE_GLX_OML_swap_method;
GLEE_EXTERN GLboolean _GLEE_GLX_OML_sync_control;
GLEE_EXTERN GLboolean _GLEE_GLX_NV_float_buffer;
GLEE_EXTERN GLboolean _GLEE_GLX_SGIX_hyperpipe;
GLEE_EXTERN GLboolean _GLEE_GLX_MESA_agp_offset;
GLEE_EXTERN GLboolean _GLEE_GLX_EXT_scene_marker;

/* Aliases for extension querying variables */

#define GLEE_GLX_VERSION_1_3     GLeeEnabled(&_GLEE_GLX_VERSION_1_3)
#define GLEE_GLX_VERSION_1_4     GLeeEnabled(&_GLEE_GLX_VERSION_1_4)
#define GLEE_GLX_ARB_multisample     GLeeEnabled(&_GLEE_GLX_ARB_multisample)
#define GLEE_GLX_ARB_fbconfig_float     GLeeEnabled(&_GLEE_GLX_ARB_fbconfig_float)
#define GLEE_GLX_SGIS_multisample     GLeeEnabled(&_GLEE_GLX_SGIS_multisample)
#define GLEE_GLX_EXT_visual_info     GLeeEnabled(&_GLEE_GLX_EXT_visual_info)
#define GLEE_GLX_SGI_swap_control     GLeeEnabled(&_GLEE_GLX_SGI_swap_control)
#define GLEE_GLX_SGI_video_sync     GLeeEnabled(&_GLEE_GLX_SGI_video_sync)
#define GLEE_GLX_SGI_make_current_read     GLeeEnabled(&_GLEE_GLX_SGI_make_current_read)
#define GLEE_GLX_EXT_visual_rating     GLeeEnabled(&_GLEE_GLX_EXT_visual_rating)
#define GLEE_GLX_EXT_import_context     GLeeEnabled(&_GLEE_GLX_EXT_import_context)
#define GLEE_GLX_SGIX_fbconfig     GLeeEnabled(&_GLEE_GLX_SGIX_fbconfig)
#define GLEE_GLX_SGIX_pbuffer     GLeeEnabled(&_GLEE_GLX_SGIX_pbuffer)
#define GLEE_GLX_SGI_cushion     GLeeEnabled(&_GLEE_GLX_SGI_cushion)
#define GLEE_GLX_SGIX_video_resize     GLeeEnabled(&_GLEE_GLX_SGIX_video_resize)
#define GLEE_GLX_SGIX_swap_group     GLeeEnabled(&_GLEE_GLX_SGIX_swap_group)
#define GLEE_GLX_SGIX_swap_barrier     GLeeEnabled(&_GLEE_GLX_SGIX_swap_barrier)
#define GLEE_GLX_SGIS_blended_overlay     GLeeEnabled(&_GLEE_GLX_SGIS_blended_overlay)
#define GLEE_GLX_SGIS_shared_multisample     GLeeEnabled(&_GLEE_GLX_SGIS_shared_multisample)
#define GLEE_GLX_SUN_get_transparent_index     GLeeEnabled(&_GLEE_GLX_SUN_get_transparent_index)
#define GLEE_GLX_3DFX_multisample     GLeeEnabled(&_GLEE_GLX_3DFX_multisample)
#define GLEE_GLX_MESA_copy_sub_buffer     GLeeEnabled(&_GLEE_GLX_MESA_copy_sub_buffer)
#define GLEE_GLX_MESA_pixmap_colormap     GLeeEnabled(&_GLEE_GLX_MESA_pixmap_colormap)
#define GLEE_GLX_MESA_release_buffers     GLeeEnabled(&_GLEE_GLX_MESA_release_buffers)
#define GLEE_GLX_MESA_set_3dfx_mode     GLeeEnabled(&_GLEE_GLX_MESA_set_3dfx_mode)
#define GLEE_GLX_SGIX_visual_select_group     GLeeEnabled(&_GLEE_GLX_SGIX_visual_select_group)
#define GLEE_GLX_OML_swap_method     GLeeEnabled(&_GLEE_GLX_OML_swap_method)
#define GLEE_GLX_OML_sync_control     GLeeEnabled(&_GLEE_GLX_OML_sync_control)
#define GLEE_GLX_NV_float_buffer     GLeeEnabled(&_GLEE_GLX_NV_float_buffer)
#define GLEE_GLX_SGIX_hyperpipe     GLeeEnabled(&_GLEE_GLX_SGIX_hyperpipe)
#define GLEE_GLX_MESA_agp_offset     GLeeEnabled(&_GLEE_GLX_MESA_agp_offset)
#define GLEE_GLX_EXT_scene_marker     GLeeEnabled(&_GLEE_GLX_EXT_scene_marker)

/* GLX_VERSION_1_3 */

#ifndef GLX_VERSION_1_3
#define GLX_VERSION_1_3 1
#define __GLEE_GLX_VERSION_1_3 1
/* Constants */
#define GLX_WINDOW_BIT                                     0x00000001
#define GLX_PIXMAP_BIT                                     0x00000002
#define GLX_PBUFFER_BIT                                    0x00000004
#define GLX_RGBA_BIT                                       0x00000001
#define GLX_COLOR_INDEX_BIT                                0x00000002
#define GLX_PBUFFER_CLOBBER_MASK                           0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT                          0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT                         0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT                           0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT                          0x00000008
#define GLX_AUX_BUFFERS_BIT                                0x00000010
#define GLX_DEPTH_BUFFER_BIT                               0x00000020
#define GLX_STENCIL_BUFFER_BIT                             0x00000040
#define GLX_ACCUM_BUFFER_BIT                               0x00000080
#define GLX_CONFIG_CAVEAT                                  0x20
#define GLX_X_VISUAL_TYPE                                  0x22
#define GLX_TRANSPARENT_TYPE                               0x23
#define GLX_TRANSPARENT_INDEX_VALUE                        0x24
#define GLX_TRANSPARENT_RED_VALUE                          0x25
#define GLX_TRANSPARENT_GREEN_VALUE                        0x26
#define GLX_TRANSPARENT_BLUE_VALUE                         0x27
#define GLX_TRANSPARENT_ALPHA_VALUE                        0x28
#define GLX_DONT_CARE                                      0xFFFFFFFF
#define GLX_NONE                                           0x8000
#define GLX_SLOW_CONFIG                                    0x8001
#define GLX_TRUE_COLOR                                     0x8002
#define GLX_DIRECT_COLOR                                   0x8003
#define GLX_PSEUDO_COLOR                                   0x8004
#define GLX_STATIC_COLOR                                   0x8005
#define GLX_GRAY_SCALE                                     0x8006
#define GLX_STATIC_GRAY                                    0x8007
#define GLX_TRANSPARENT_RGB                                0x8008
#define GLX_TRANSPARENT_INDEX                              0x8009
#define GLX_VISUAL_ID                                      0x800B
#define GLX_SCREEN                                         0x800C
#define GLX_NON_CONFORMANT_CONFIG                          0x800D
#define GLX_DRAWABLE_TYPE                                  0x8010
#define GLX_RENDER_TYPE                                    0x8011
#define GLX_X_RENDERABLE                                   0x8012
#define GLX_FBCONFIG_ID                                    0x8013
#define GLX_RGBA_TYPE                                      0x8014
#define GLX_COLOR_INDEX_TYPE                               0x8015
#define GLX_MAX_PBUFFER_WIDTH                              0x8016
#define GLX_MAX_PBUFFER_HEIGHT                             0x8017
#define GLX_MAX_PBUFFER_PIXELS                             0x8018
#define GLX_PRESERVED_CONTENTS                             0x801B
#define GLX_LARGEST_PBUFFER                                0x801C
#define GLX_WIDTH                                          0x801D
#define GLX_HEIGHT                                         0x801E
#define GLX_EVENT_MASK                                     0x801F
#define GLX_DAMAGED                                        0x8020
#define GLX_SAVED                                          0x8021
#define GLX_WINDOW                                         0x8022
#define GLX_PBUFFER                                        0x8023
#define GLX_PBUFFER_HEIGHT                                 0x8040
#define GLX_PBUFFER_WIDTH                                  0x8041
typedef GLXFBConfig * (APIENTRYP PFNGLXGETFBCONFIGSPROC) (Display * dpy, int screen, int * nelements);
typedef GLXFBConfig * (APIENTRYP PFNGLXCHOOSEFBCONFIGPROC) (Display * dpy, int screen, const int * attrib_list, int * nelements);
typedef int (APIENTRYP PFNGLXGETFBCONFIGATTRIBPROC) (Display * dpy, GLXFBConfig config, int attribute, int * value);
typedef XVisualInfo * (APIENTRYP PFNGLXGETVISUALFROMFBCONFIGPROC) (Display * dpy, GLXFBConfig config);
typedef GLXWindow (APIENTRYP PFNGLXCREATEWINDOWPROC) (Display * dpy, GLXFBConfig config, Window win, const int * attrib_list);
typedef void (APIENTRYP PFNGLXDESTROYWINDOWPROC) (Display * dpy, GLXWindow win);
typedef GLXPixmap (APIENTRYP PFNGLXCREATEPIXMAPPROC) (Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list);
typedef void (APIENTRYP PFNGLXDESTROYPIXMAPPROC) (Display * dpy, GLXPixmap pixmap);
typedef GLXPbuffer (APIENTRYP PFNGLXCREATEPBUFFERPROC) (Display * dpy, GLXFBConfig config, const int * attrib_list);
typedef void (APIENTRYP PFNGLXDESTROYPBUFFERPROC) (Display * dpy, GLXPbuffer pbuf);
typedef void (APIENTRYP PFNGLXQUERYDRAWABLEPROC) (Display * dpy, GLXDrawable draw, int attribute, unsigned int * value);
typedef GLXContext (APIENTRYP PFNGLXCREATENEWCONTEXTPROC) (Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
typedef Bool (APIENTRYP PFNGLXMAKECONTEXTCURRENTPROC) (Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef GLXDrawable (APIENTRYP PFNGLXGETCURRENTREADDRAWABLEPROC) ();
typedef Display * (APIENTRYP PFNGLXGETCURRENTDISPLAYPROC) ();
typedef int (APIENTRYP PFNGLXQUERYCONTEXTPROC) (Display * dpy, GLXContext ctx, int attribute, int * value);
typedef void (APIENTRYP PFNGLXSELECTEVENTPROC) (Display * dpy, GLXDrawable draw, unsigned long event_mask);
typedef void (APIENTRYP PFNGLXGETSELECTEDEVENTPROC) (Display * dpy, GLXDrawable draw, unsigned long * event_mask);
GLEE_EXTERN PFNGLXGETFBCONFIGSPROC pglXGetFBConfigs;
GLEE_EXTERN PFNGLXCHOOSEFBCONFIGPROC pglXChooseFBConfig;
GLEE_EXTERN PFNGLXGETFBCONFIGATTRIBPROC pglXGetFBConfigAttrib;
GLEE_EXTERN PFNGLXGETVISUALFROMFBCONFIGPROC pglXGetVisualFromFBConfig;
GLEE_EXTERN PFNGLXCREATEWINDOWPROC pglXCreateWindow;
GLEE_EXTERN PFNGLXDESTROYWINDOWPROC pglXDestroyWindow;
GLEE_EXTERN PFNGLXCREATEPIXMAPPROC pglXCreatePixmap;
GLEE_EXTERN PFNGLXDESTROYPIXMAPPROC pglXDestroyPixmap;
GLEE_EXTERN PFNGLXCREATEPBUFFERPROC pglXCreatePbuffer;
GLEE_EXTERN PFNGLXDESTROYPBUFFERPROC pglXDestroyPbuffer;
GLEE_EXTERN PFNGLXQUERYDRAWABLEPROC pglXQueryDrawable;
GLEE_EXTERN PFNGLXCREATENEWCONTEXTPROC pglXCreateNewContext;
GLEE_EXTERN PFNGLXMAKECONTEXTCURRENTPROC pglXMakeContextCurrent;
GLEE_EXTERN PFNGLXGETCURRENTREADDRAWABLEPROC pglXGetCurrentReadDrawable;
GLEE_EXTERN PFNGLXGETCURRENTDISPLAYPROC pglXGetCurrentDisplay;
GLEE_EXTERN PFNGLXQUERYCONTEXTPROC pglXQueryContext;
GLEE_EXTERN PFNGLXSELECTEVENTPROC pglXSelectEvent;
GLEE_EXTERN PFNGLXGETSELECTEDEVENTPROC pglXGetSelectedEvent;
#define glXGetFBConfigs pglXGetFBConfigs
#define glXChooseFBConfig pglXChooseFBConfig
#define glXGetFBConfigAttrib pglXGetFBConfigAttrib
#define glXGetVisualFromFBConfig pglXGetVisualFromFBConfig
#define glXCreateWindow pglXCreateWindow
#define glXDestroyWindow pglXDestroyWindow
#define glXCreatePixmap pglXCreatePixmap
#define glXDestroyPixmap pglXDestroyPixmap
#define glXCreatePbuffer pglXCreatePbuffer
#define glXDestroyPbuffer pglXDestroyPbuffer
#define glXQueryDrawable pglXQueryDrawable
#define glXCreateNewContext pglXCreateNewContext
#define glXMakeContextCurrent pglXMakeContextCurrent
#define glXGetCurrentReadDrawable pglXGetCurrentReadDrawable
#define glXGetCurrentDisplay pglXGetCurrentDisplay
#define glXQueryContext pglXQueryContext
#define glXSelectEvent pglXSelectEvent
#define glXGetSelectedEvent pglXGetSelectedEvent
#endif 

/* GLX_VERSION_1_4 */

#ifndef GLX_VERSION_1_4
#define GLX_VERSION_1_4 1
#define __GLEE_GLX_VERSION_1_4 1
/* Constants */
#define GLX_SAMPLE_BUFFERS                                 100000
#define GLX_SAMPLES                                        100001
typedef __GLXextFuncPtr (APIENTRYP PFNGLXGETPROCADDRESSPROC) (const GLubyte * procName);
GLEE_EXTERN PFNGLXGETPROCADDRESSPROC pglXGetProcAddress;
#define glXGetProcAddress pglXGetProcAddress
#endif 

/* GLX_ARB_multisample */

#ifndef GLX_ARB_multisample
#define GLX_ARB_multisample 1
#define __GLEE_GLX_ARB_multisample 1
/* Constants */
#define GLX_SAMPLE_BUFFERS_ARB                             100000
#define GLX_SAMPLES_ARB                                    100001
#endif 

/* GLX_ARB_fbconfig_float */

#ifndef GLX_ARB_fbconfig_float
#define GLX_ARB_fbconfig_float 1
#define __GLEE_GLX_ARB_fbconfig_float 1
/* Constants */
#define GLX_RGBA_FLOAT_TYPE_ARB                            0x20B9
#define GLX_RGBA_FLOAT_BIT_ARB                             0x00000004
#endif 

/* GLX_SGIS_multisample */

#ifndef GLX_SGIS_multisample
#define GLX_SGIS_multisample 1
#define __GLEE_GLX_SGIS_multisample 1
/* Constants */
#define GLX_SAMPLE_BUFFERS_SGIS                            100000
#define GLX_SAMPLES_SGIS                                   100001
#endif 

/* GLX_EXT_visual_info */

#ifndef GLX_EXT_visual_info
#define GLX_EXT_visual_info 1
#define __GLEE_GLX_EXT_visual_info 1
/* Constants */
#define GLX_X_VISUAL_TYPE_EXT                              0x22
#define GLX_TRANSPARENT_TYPE_EXT                           0x23
#define GLX_TRANSPARENT_INDEX_VALUE_EXT                    0x24
#define GLX_TRANSPARENT_RED_VALUE_EXT                      0x25
#define GLX_TRANSPARENT_GREEN_VALUE_EXT                    0x26
#define GLX_TRANSPARENT_BLUE_VALUE_EXT                     0x27
#define GLX_TRANSPARENT_ALPHA_VALUE_EXT                    0x28
#define GLX_NONE_EXT                                       0x8000
#define GLX_TRUE_COLOR_EXT                                 0x8002
#define GLX_DIRECT_COLOR_EXT                               0x8003
#define GLX_PSEUDO_COLOR_EXT                               0x8004
#define GLX_STATIC_COLOR_EXT                               0x8005
#define GLX_GRAY_SCALE_EXT                                 0x8006
#define GLX_STATIC_GRAY_EXT                                0x8007
#define GLX_TRANSPARENT_RGB_EXT                            0x8008
#define GLX_TRANSPARENT_INDEX_EXT                          0x8009
#endif 

/* GLX_SGI_swap_control */

#ifndef GLX_SGI_swap_control
#define GLX_SGI_swap_control 1
#define __GLEE_GLX_SGI_swap_control 1
/* Constants */
typedef int (APIENTRYP PFNGLXSWAPINTERVALSGIPROC) (int interval);
GLEE_EXTERN PFNGLXSWAPINTERVALSGIPROC pglXSwapIntervalSGI;
#define glXSwapIntervalSGI pglXSwapIntervalSGI
#endif 

/* GLX_SGI_video_sync */

#ifndef GLX_SGI_video_sync
#define GLX_SGI_video_sync 1
#define __GLEE_GLX_SGI_video_sync 1
/* Constants */
typedef int (APIENTRYP PFNGLXGETVIDEOSYNCSGIPROC) (unsigned int * count);
typedef int (APIENTRYP PFNGLXWAITVIDEOSYNCSGIPROC) (int divisor, int remainder, unsigned int * count);
GLEE_EXTERN PFNGLXGETVIDEOSYNCSGIPROC pglXGetVideoSyncSGI;
GLEE_EXTERN PFNGLXWAITVIDEOSYNCSGIPROC pglXWaitVideoSyncSGI;
#define glXGetVideoSyncSGI pglXGetVideoSyncSGI
#define glXWaitVideoSyncSGI pglXWaitVideoSyncSGI
#endif 

/* GLX_SGI_make_current_read */

#ifndef GLX_SGI_make_current_read
#define GLX_SGI_make_current_read 1
#define __GLEE_GLX_SGI_make_current_read 1
/* Constants */
typedef Bool (APIENTRYP PFNGLXMAKECURRENTREADSGIPROC) (Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef GLXDrawable (APIENTRYP PFNGLXGETCURRENTREADDRAWABLESGIPROC) ();
GLEE_EXTERN PFNGLXMAKECURRENTREADSGIPROC pglXMakeCurrentReadSGI;
GLEE_EXTERN PFNGLXGETCURRENTREADDRAWABLESGIPROC pglXGetCurrentReadDrawableSGI;
#define glXMakeCurrentReadSGI pglXMakeCurrentReadSGI
#define glXGetCurrentReadDrawableSGI pglXGetCurrentReadDrawableSGI
#endif 

/* GLX_EXT_visual_rating */

#ifndef GLX_EXT_visual_rating
#define GLX_EXT_visual_rating 1
#define __GLEE_GLX_EXT_visual_rating 1
/* Constants */
#define GLX_VISUAL_CAVEAT_EXT                              0x20
#define GLX_SLOW_VISUAL_EXT                                0x8001
#define GLX_NON_CONFORMANT_VISUAL_EXT                      0x800D
#endif 

/* GLX_EXT_import_context */

#ifndef GLX_EXT_import_context
#define GLX_EXT_import_context 1
#define __GLEE_GLX_EXT_import_context 1
/* Constants */
#define GLX_SHARE_CONTEXT_EXT                              0x800A
#define GLX_VISUAL_ID_EXT                                  0x800B
#define GLX_SCREEN_EXT                                     0x800C
typedef Display * (APIENTRYP PFNGLXGETCURRENTDISPLAYEXTPROC) ();
typedef int (APIENTRYP PFNGLXQUERYCONTEXTINFOEXTPROC) (Display * dpy, GLXContext context, int attribute, int * value);
typedef GLXContextID (APIENTRYP PFNGLXGETCONTEXTIDEXTPROC) (const GLXContext context);
typedef GLXContext (APIENTRYP PFNGLXIMPORTCONTEXTEXTPROC) (Display * dpy, GLXContextID contextID);
typedef void (APIENTRYP PFNGLXFREECONTEXTEXTPROC) (Display * dpy, GLXContext context);
GLEE_EXTERN PFNGLXGETCURRENTDISPLAYEXTPROC pglXGetCurrentDisplayEXT;
GLEE_EXTERN PFNGLXQUERYCONTEXTINFOEXTPROC pglXQueryContextInfoEXT;
GLEE_EXTERN PFNGLXGETCONTEXTIDEXTPROC pglXGetContextIDEXT;
GLEE_EXTERN PFNGLXIMPORTCONTEXTEXTPROC pglXImportContextEXT;
GLEE_EXTERN PFNGLXFREECONTEXTEXTPROC pglXFreeContextEXT;
#define glXGetCurrentDisplayEXT pglXGetCurrentDisplayEXT
#define glXQueryContextInfoEXT pglXQueryContextInfoEXT
#define glXGetContextIDEXT pglXGetContextIDEXT
#define glXImportContextEXT pglXImportContextEXT
#define glXFreeContextEXT pglXFreeContextEXT
#endif 

/* GLX_SGIX_fbconfig */

#ifndef GLX_SGIX_fbconfig
#define GLX_SGIX_fbconfig 1
#define __GLEE_GLX_SGIX_fbconfig 1
/* Constants */
#define GLX_WINDOW_BIT_SGIX                                0x00000001
#define GLX_PIXMAP_BIT_SGIX                                0x00000002
#define GLX_RGBA_BIT_SGIX                                  0x00000001
#define GLX_COLOR_INDEX_BIT_SGIX                           0x00000002
#define GLX_DRAWABLE_TYPE_SGIX                             0x8010
#define GLX_RENDER_TYPE_SGIX                               0x8011
#define GLX_X_RENDERABLE_SGIX                              0x8012
#define GLX_FBCONFIG_ID_SGIX                               0x8013
#define GLX_RGBA_TYPE_SGIX                                 0x8014
#define GLX_COLOR_INDEX_TYPE_SGIX                          0x8015
typedef int (APIENTRYP PFNGLXGETFBCONFIGATTRIBSGIXPROC) (Display * dpy, GLXFBConfigSGIX config, int attribute, int * value);
typedef GLXFBConfigSGIX * (APIENTRYP PFNGLXCHOOSEFBCONFIGSGIXPROC) (Display * dpy, int screen, int * attrib_list, int * nelements);
typedef GLXPixmap (APIENTRYP PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC) (Display * dpy, GLXFBConfigSGIX config, Pixmap pixmap);
typedef GLXContext (APIENTRYP PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC) (Display * dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
typedef XVisualInfo * (APIENTRYP PFNGLXGETVISUALFROMFBCONFIGSGIXPROC) (Display * dpy, GLXFBConfigSGIX config);
typedef GLXFBConfigSGIX (APIENTRYP PFNGLXGETFBCONFIGFROMVISUALSGIXPROC) (Display * dpy, XVisualInfo * vis);
GLEE_EXTERN PFNGLXGETFBCONFIGATTRIBSGIXPROC pglXGetFBConfigAttribSGIX;
GLEE_EXTERN PFNGLXCHOOSEFBCONFIGSGIXPROC pglXChooseFBConfigSGIX;
GLEE_EXTERN PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC pglXCreateGLXPixmapWithConfigSGIX;
GLEE_EXTERN PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC pglXCreateContextWithConfigSGIX;
GLEE_EXTERN PFNGLXGETVISUALFROMFBCONFIGSGIXPROC pglXGetVisualFromFBConfigSGIX;
GLEE_EXTERN PFNGLXGETFBCONFIGFROMVISUALSGIXPROC pglXGetFBConfigFromVisualSGIX;
#define glXGetFBConfigAttribSGIX pglXGetFBConfigAttribSGIX
#define glXChooseFBConfigSGIX pglXChooseFBConfigSGIX
#define glXCreateGLXPixmapWithConfigSGIX pglXCreateGLXPixmapWithConfigSGIX
#define glXCreateContextWithConfigSGIX pglXCreateContextWithConfigSGIX
#define glXGetVisualFromFBConfigSGIX pglXGetVisualFromFBConfigSGIX
#define glXGetFBConfigFromVisualSGIX pglXGetFBConfigFromVisualSGIX
#endif 

/* GLX_SGIX_pbuffer */

#ifndef GLX_SGIX_pbuffer
#define GLX_SGIX_pbuffer 1
#define __GLEE_GLX_SGIX_pbuffer 1
/* Constants */
#define GLX_PBUFFER_BIT_SGIX                               0x00000004
#define GLX_BUFFER_CLOBBER_MASK_SGIX                       0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT_SGIX                     0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT_SGIX                    0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT_SGIX                      0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT_SGIX                     0x00000008
#define GLX_AUX_BUFFERS_BIT_SGIX                           0x00000010
#define GLX_DEPTH_BUFFER_BIT_SGIX                          0x00000020
#define GLX_STENCIL_BUFFER_BIT_SGIX                        0x00000040
#define GLX_ACCUM_BUFFER_BIT_SGIX                          0x00000080
#define GLX_SAMPLE_BUFFERS_BIT_SGIX                        0x00000100
#define GLX_MAX_PBUFFER_WIDTH_SGIX                         0x8016
#define GLX_MAX_PBUFFER_HEIGHT_SGIX                        0x8017
#define GLX_MAX_PBUFFER_PIXELS_SGIX                        0x8018
#define GLX_OPTIMAL_PBUFFER_WIDTH_SGIX                     0x8019
#define GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX                    0x801A
#define GLX_PRESERVED_CONTENTS_SGIX                        0x801B
#define GLX_LARGEST_PBUFFER_SGIX                           0x801C
#define GLX_WIDTH_SGIX                                     0x801D
#define GLX_HEIGHT_SGIX                                    0x801E
#define GLX_EVENT_MASK_SGIX                                0x801F
#define GLX_DAMAGED_SGIX                                   0x8020
#define GLX_SAVED_SGIX                                     0x8021
#define GLX_WINDOW_SGIX                                    0x8022
#define GLX_PBUFFER_SGIX                                   0x8023
typedef GLXPbufferSGIX (APIENTRYP PFNGLXCREATEGLXPBUFFERSGIXPROC) (Display * dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int * attrib_list);
typedef void (APIENTRYP PFNGLXDESTROYGLXPBUFFERSGIXPROC) (Display * dpy, GLXPbufferSGIX pbuf);
typedef int (APIENTRYP PFNGLXQUERYGLXPBUFFERSGIXPROC) (Display * dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int * value);
typedef void (APIENTRYP PFNGLXSELECTEVENTSGIXPROC) (Display * dpy, GLXDrawable drawable, unsigned long mask);
typedef void (APIENTRYP PFNGLXGETSELECTEDEVENTSGIXPROC) (Display * dpy, GLXDrawable drawable, unsigned long * mask);
GLEE_EXTERN PFNGLXCREATEGLXPBUFFERSGIXPROC pglXCreateGLXPbufferSGIX;
GLEE_EXTERN PFNGLXDESTROYGLXPBUFFERSGIXPROC pglXDestroyGLXPbufferSGIX;
GLEE_EXTERN PFNGLXQUERYGLXPBUFFERSGIXPROC pglXQueryGLXPbufferSGIX;
GLEE_EXTERN PFNGLXSELECTEVENTSGIXPROC pglXSelectEventSGIX;
GLEE_EXTERN PFNGLXGETSELECTEDEVENTSGIXPROC pglXGetSelectedEventSGIX;
#define glXCreateGLXPbufferSGIX pglXCreateGLXPbufferSGIX
#define glXDestroyGLXPbufferSGIX pglXDestroyGLXPbufferSGIX
#define glXQueryGLXPbufferSGIX pglXQueryGLXPbufferSGIX
#define glXSelectEventSGIX pglXSelectEventSGIX
#define glXGetSelectedEventSGIX pglXGetSelectedEventSGIX
#endif 

/* GLX_SGI_cushion */

#ifndef GLX_SGI_cushion
#define GLX_SGI_cushion 1
#define __GLEE_GLX_SGI_cushion 1
/* Constants */
typedef void (APIENTRYP PFNGLXCUSHIONSGIPROC) (Display * dpy, Window window, float cushion);
GLEE_EXTERN PFNGLXCUSHIONSGIPROC pglXCushionSGI;
#define glXCushionSGI pglXCushionSGI
#endif 

/* GLX_SGIX_video_resize */

#ifndef GLX_SGIX_video_resize
#define GLX_SGIX_video_resize 1
#define __GLEE_GLX_SGIX_video_resize 1
/* Constants */
#define GLX_SYNC_FRAME_SGIX                                0x00000000
#define GLX_SYNC_SWAP_SGIX                                 0x00000001
typedef int (APIENTRYP PFNGLXBINDCHANNELTOWINDOWSGIXPROC) (Display * display, int screen, int channel, Window window);
typedef int (APIENTRYP PFNGLXCHANNELRECTSGIXPROC) (Display * display, int screen, int channel, int x, int y, int w, int h);
typedef int (APIENTRYP PFNGLXQUERYCHANNELRECTSGIXPROC) (Display * display, int screen, int channel, int * dx, int * dy, int * dw, int * dh);
typedef int (APIENTRYP PFNGLXQUERYCHANNELDELTASSGIXPROC) (Display * display, int screen, int channel, int * x, int * y, int * w, int * h);
typedef int (APIENTRYP PFNGLXCHANNELRECTSYNCSGIXPROC) (Display * display, int screen, int channel, GLenum synctype);
GLEE_EXTERN PFNGLXBINDCHANNELTOWINDOWSGIXPROC pglXBindChannelToWindowSGIX;
GLEE_EXTERN PFNGLXCHANNELRECTSGIXPROC pglXChannelRectSGIX;
GLEE_EXTERN PFNGLXQUERYCHANNELRECTSGIXPROC pglXQueryChannelRectSGIX;
GLEE_EXTERN PFNGLXQUERYCHANNELDELTASSGIXPROC pglXQueryChannelDeltasSGIX;
GLEE_EXTERN PFNGLXCHANNELRECTSYNCSGIXPROC pglXChannelRectSyncSGIX;
#define glXBindChannelToWindowSGIX pglXBindChannelToWindowSGIX
#define glXChannelRectSGIX pglXChannelRectSGIX
#define glXQueryChannelRectSGIX pglXQueryChannelRectSGIX
#define glXQueryChannelDeltasSGIX pglXQueryChannelDeltasSGIX
#define glXChannelRectSyncSGIX pglXChannelRectSyncSGIX
#endif 

/* GLX_SGIX_swap_group */

#ifndef GLX_SGIX_swap_group
#define GLX_SGIX_swap_group 1
#define __GLEE_GLX_SGIX_swap_group 1
/* Constants */
typedef void (APIENTRYP PFNGLXJOINSWAPGROUPSGIXPROC) (Display * dpy, GLXDrawable drawable, GLXDrawable member);
GLEE_EXTERN PFNGLXJOINSWAPGROUPSGIXPROC pglXJoinSwapGroupSGIX;
#define glXJoinSwapGroupSGIX pglXJoinSwapGroupSGIX
#endif 

/* GLX_SGIX_swap_barrier */

#ifndef GLX_SGIX_swap_barrier
#define GLX_SGIX_swap_barrier 1
#define __GLEE_GLX_SGIX_swap_barrier 1
/* Constants */
typedef void (APIENTRYP PFNGLXBINDSWAPBARRIERSGIXPROC) (Display * dpy, GLXDrawable drawable, int barrier);
typedef Bool (APIENTRYP PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC) (Display * dpy, int screen, int * max);
GLEE_EXTERN PFNGLXBINDSWAPBARRIERSGIXPROC pglXBindSwapBarrierSGIX;
GLEE_EXTERN PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC pglXQueryMaxSwapBarriersSGIX;
#define glXBindSwapBarrierSGIX pglXBindSwapBarrierSGIX
#define glXQueryMaxSwapBarriersSGIX pglXQueryMaxSwapBarriersSGIX
#endif 

/* GLX_SGIS_blended_overlay */

#ifndef GLX_SGIS_blended_overlay
#define GLX_SGIS_blended_overlay 1
#define __GLEE_GLX_SGIS_blended_overlay 1
/* Constants */
#define GLX_BLENDED_RGBA_SGIS                              0x8025
#endif 

/* GLX_SGIS_shared_multisample */

#ifndef GLX_SGIS_shared_multisample
#define GLX_SGIS_shared_multisample 1
#define __GLEE_GLX_SGIS_shared_multisample 1
/* Constants */
#define GLX_MULTISAMPLE_SUB_RECT_WIDTH_SGIS                0x8026
#define GLX_MULTISAMPLE_SUB_RECT_HEIGHT_SGIS               0x8027
#endif 

/* GLX_SUN_get_transparent_index */

#ifndef GLX_SUN_get_transparent_index
#define GLX_SUN_get_transparent_index 1
#define __GLEE_GLX_SUN_get_transparent_index 1
/* Constants */
typedef Status (APIENTRYP PFNGLXGETTRANSPARENTINDEXSUNPROC) (Display * dpy, Window overlay, Window underlay, long * pTransparentIndex);
GLEE_EXTERN PFNGLXGETTRANSPARENTINDEXSUNPROC pglXGetTransparentIndexSUN;
#define glXGetTransparentIndexSUN pglXGetTransparentIndexSUN
#endif 

/* GLX_3DFX_multisample */

#ifndef GLX_3DFX_multisample
#define GLX_3DFX_multisample 1
#define __GLEE_GLX_3DFX_multisample 1
/* Constants */
#define GLX_SAMPLE_BUFFERS_3DFX                            0x8050
#define GLX_SAMPLES_3DFX                                   0x8051
#endif 

/* GLX_MESA_copy_sub_buffer */

#ifndef GLX_MESA_copy_sub_buffer
#define GLX_MESA_copy_sub_buffer 1
#define __GLEE_GLX_MESA_copy_sub_buffer 1
/* Constants */
typedef void (APIENTRYP PFNGLXCOPYSUBBUFFERMESAPROC) (Display * dpy, GLXDrawable drawable, int x, int y, int width, int height);
GLEE_EXTERN PFNGLXCOPYSUBBUFFERMESAPROC pglXCopySubBufferMESA;
#define glXCopySubBufferMESA pglXCopySubBufferMESA
#endif 

/* GLX_MESA_pixmap_colormap */

#ifndef GLX_MESA_pixmap_colormap
#define GLX_MESA_pixmap_colormap 1
#define __GLEE_GLX_MESA_pixmap_colormap 1
/* Constants */
typedef GLXPixmap (APIENTRYP PFNGLXCREATEGLXPIXMAPMESAPROC) (Display * dpy, XVisualInfo * visual, Pixmap pixmap, Colormap cmap);
GLEE_EXTERN PFNGLXCREATEGLXPIXMAPMESAPROC pglXCreateGLXPixmapMESA;
#define glXCreateGLXPixmapMESA pglXCreateGLXPixmapMESA
#endif 

/* GLX_MESA_release_buffers */

#ifndef GLX_MESA_release_buffers
#define GLX_MESA_release_buffers 1
#define __GLEE_GLX_MESA_release_buffers 1
/* Constants */
typedef Bool (APIENTRYP PFNGLXRELEASEBUFFERSMESAPROC) (Display * dpy, GLXDrawable drawable);
GLEE_EXTERN PFNGLXRELEASEBUFFERSMESAPROC pglXReleaseBuffersMESA;
#define glXReleaseBuffersMESA pglXReleaseBuffersMESA
#endif 

/* GLX_MESA_set_3dfx_mode */

#ifndef GLX_MESA_set_3dfx_mode
#define GLX_MESA_set_3dfx_mode 1
#define __GLEE_GLX_MESA_set_3dfx_mode 1
/* Constants */
#define GLX_3DFX_WINDOW_MODE_MESA                          0x1
#define GLX_3DFX_FULLSCREEN_MODE_MESA                      0x2
typedef Bool (APIENTRYP PFNGLXSET3DFXMODEMESAPROC) (int mode);
GLEE_EXTERN PFNGLXSET3DFXMODEMESAPROC pglXSet3DfxModeMESA;
#define glXSet3DfxModeMESA pglXSet3DfxModeMESA
#endif 

/* GLX_SGIX_visual_select_group */

#ifndef GLX_SGIX_visual_select_group
#define GLX_SGIX_visual_select_group 1
#define __GLEE_GLX_SGIX_visual_select_group 1
/* Constants */
#define GLX_VISUAL_SELECT_GROUP_SGIX                       0x8028
#endif 

/* GLX_OML_swap_method */

#ifndef GLX_OML_swap_method
#define GLX_OML_swap_method 1
#define __GLEE_GLX_OML_swap_method 1
/* Constants */
#define GLX_SWAP_METHOD_OML                                0x8060
#define GLX_SWAP_EXCHANGE_OML                              0x8061
#define GLX_SWAP_COPY_OML                                  0x8062
#define GLX_SWAP_UNDEFINED_OML                             0x8063
#endif 

/* GLX_OML_sync_control */

#ifndef GLX_OML_sync_control
#define GLX_OML_sync_control 1
#define __GLEE_GLX_OML_sync_control 1
/* Constants */
typedef Bool (APIENTRYP PFNGLXGETSYNCVALUESOMLPROC) (Display * dpy, GLXDrawable drawable, int64_t * ust, int64_t * msc, int64_t * sbc);
typedef Bool (APIENTRYP PFNGLXGETMSCRATEOMLPROC) (Display * dpy, GLXDrawable drawable, int32_t * numerator, int32_t * denominator);
typedef int64_t (APIENTRYP PFNGLXSWAPBUFFERSMSCOMLPROC) (Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
typedef Bool (APIENTRYP PFNGLXWAITFORMSCOMLPROC) (Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t * ust, int64_t * msc, int64_t * sbc);
typedef Bool (APIENTRYP PFNGLXWAITFORSBCOMLPROC) (Display * dpy, GLXDrawable drawable, int64_t target_sbc, int64_t * ust, int64_t * msc, int64_t * sbc);
GLEE_EXTERN PFNGLXGETSYNCVALUESOMLPROC pglXGetSyncValuesOML;
GLEE_EXTERN PFNGLXGETMSCRATEOMLPROC pglXGetMscRateOML;
GLEE_EXTERN PFNGLXSWAPBUFFERSMSCOMLPROC pglXSwapBuffersMscOML;
GLEE_EXTERN PFNGLXWAITFORMSCOMLPROC pglXWaitForMscOML;
GLEE_EXTERN PFNGLXWAITFORSBCOMLPROC pglXWaitForSbcOML;
#define glXGetSyncValuesOML pglXGetSyncValuesOML
#define glXGetMscRateOML pglXGetMscRateOML
#define glXSwapBuffersMscOML pglXSwapBuffersMscOML
#define glXWaitForMscOML pglXWaitForMscOML
#define glXWaitForSbcOML pglXWaitForSbcOML
#endif 

/* GLX_NV_float_buffer */

#ifndef GLX_NV_float_buffer
#define GLX_NV_float_buffer 1
#define __GLEE_GLX_NV_float_buffer 1
/* Constants */
#define GLX_FLOAT_COMPONENTS_NV                            0x20B0
#endif 

/* GLX_SGIX_hyperpipe */

#ifndef GLX_SGIX_hyperpipe
#define GLX_SGIX_hyperpipe 1
#define __GLEE_GLX_SGIX_hyperpipe 1
/* Constants */
#define GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX                80
#define GLX_BAD_HYPERPIPE_CONFIG_SGIX                      91
#define GLX_BAD_HYPERPIPE_SGIX                             92
#define GLX_HYPERPIPE_DISPLAY_PIPE_SGIX                    0x00000001
#define GLX_HYPERPIPE_RENDER_PIPE_SGIX                     0x00000002
#define GLX_PIPE_RECT_SGIX                                 0x00000001
#define GLX_PIPE_RECT_LIMITS_SGIX                          0x00000002
#define GLX_HYPERPIPE_STEREO_SGIX                          0x00000003
#define GLX_HYPERPIPE_PIXEL_AVERAGE_SGIX                   0x00000004
#define GLX_HYPERPIPE_ID_SGIX                              0x8030
typedef GLXHyperpipeNetworkSGIX * (APIENTRYP PFNGLXQUERYHYPERPIPENETWORKSGIXPROC) (Display * dpy, int * npipes);
typedef int (APIENTRYP PFNGLXHYPERPIPECONFIGSGIXPROC) (Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX * cfg, int * hpId);
typedef GLXHyperpipeConfigSGIX * (APIENTRYP PFNGLXQUERYHYPERPIPECONFIGSGIXPROC) (Display * dpy, int hpId, int * npipes);
typedef int (APIENTRYP PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC) (Display * dpy, int hpId);
typedef int (APIENTRYP PFNGLXBINDHYPERPIPESGIXPROC) (Display * dpy, int hpId);
typedef int (APIENTRYP PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC) (Display * dpy, int timeSlice, int attrib, int size, void * attribList, void * returnAttribList);
typedef int (APIENTRYP PFNGLXHYPERPIPEATTRIBSGIXPROC) (Display * dpy, int timeSlice, int attrib, int size, void * attribList);
typedef int (APIENTRYP PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC) (Display * dpy, int timeSlice, int attrib, int size, void * returnAttribList);
GLEE_EXTERN PFNGLXQUERYHYPERPIPENETWORKSGIXPROC pglXQueryHyperpipeNetworkSGIX;
GLEE_EXTERN PFNGLXHYPERPIPECONFIGSGIXPROC pglXHyperpipeConfigSGIX;
GLEE_EXTERN PFNGLXQUERYHYPERPIPECONFIGSGIXPROC pglXQueryHyperpipeConfigSGIX;
GLEE_EXTERN PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC pglXDestroyHyperpipeConfigSGIX;
GLEE_EXTERN PFNGLXBINDHYPERPIPESGIXPROC pglXBindHyperpipeSGIX;
GLEE_EXTERN PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC pglXQueryHyperpipeBestAttribSGIX;
GLEE_EXTERN PFNGLXHYPERPIPEATTRIBSGIXPROC pglXHyperpipeAttribSGIX;
GLEE_EXTERN PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC pglXQueryHyperpipeAttribSGIX;
#define glXQueryHyperpipeNetworkSGIX pglXQueryHyperpipeNetworkSGIX
#define glXHyperpipeConfigSGIX pglXHyperpipeConfigSGIX
#define glXQueryHyperpipeConfigSGIX pglXQueryHyperpipeConfigSGIX
#define glXDestroyHyperpipeConfigSGIX pglXDestroyHyperpipeConfigSGIX
#define glXBindHyperpipeSGIX pglXBindHyperpipeSGIX
#define glXQueryHyperpipeBestAttribSGIX pglXQueryHyperpipeBestAttribSGIX
#define glXHyperpipeAttribSGIX pglXHyperpipeAttribSGIX
#define glXQueryHyperpipeAttribSGIX pglXQueryHyperpipeAttribSGIX
#endif 

/* GLX_MESA_agp_offset */

#ifndef GLX_MESA_agp_offset
#define GLX_MESA_agp_offset 1
#define __GLEE_GLX_MESA_agp_offset 1
/* Constants */
typedef unsigned int (APIENTRYP PFNGLXGETAGPOFFSETMESAPROC) (const void * pointer);
GLEE_EXTERN PFNGLXGETAGPOFFSETMESAPROC pglXGetAGPOffsetMESA;
#define glXGetAGPOffsetMESA pglXGetAGPOffsetMESA
#endif 

/* GLX_EXT_scene_marker */

#ifndef GLX_EXT_scene_marker
#define GLX_EXT_scene_marker 1
#define __GLEE_GLX_EXT_scene_marker 1
/* Constants */
#endif 
#endif /*end GLX */

/*****************************************************************
 * GLee functions
 *****************************************************************/
 
GLEE_EXTERN GLboolean GLeeInit();
GLEE_EXTERN GLint GLeeForceLink(const char * extensionName);
GLEE_EXTERN const char * GLeeGetErrorString();
GLEE_EXTERN const char * GLeeGetExtStrGL();
GLEE_EXTERN GLboolean GLeeEnabled(GLboolean * extensionQueryingVariable);

#ifdef WIN32
GLEE_EXTERN const char * GLeeGetExtStrWGL();
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#else 
GLEE_EXTERN const char * GLeeGetExtStrGLX();
#endif

#ifdef __cplusplus
}	/* end C linkage */
#endif

#endif /* __glee_h_ defined */
