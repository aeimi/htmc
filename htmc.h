#ifndef HTMC_H
#define HTMC_H

#include <stddef.h>
#include <stdint.h>

typedef struct
{
    size_t nb;
    bool *unused;
    size_t *caps;
    char **buffers;
} HtmcAllocations;

#define htmc_htmldoc(...) \
({ \
    HtmcAllocations *ha = malloc(sizeof(HtmcAllocations)); \
    const size_t init_cap = 4; \
    *ha = (HtmcAllocations){ \
        .buffers = calloc(16, sizeof(char*)), \
        .nb = init_cap, \
        .caps = calloc(init_cap, sizeof(size_t)), \
        .unused = malloc(init_cap * sizeof(bool))\
    }; \
    memset(ha->unused, 1, init_cap * sizeof(bool)); \
    char *ret = htmc_concat_strings(ha, ##__VA_ARGS__, NULL); \
    htmc_cleanup_unused_buffers(ha, ret); \
    ret; \
})

#define htmc_a(...) htmc_surround_by_tag(ha, 0, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_abbr(...) htmc_surround_by_tag(ha, 1, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_address(...) htmc_surround_by_tag(ha, 2, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_area(...) htmc_surround_by_tag(ha, 3, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_article(...) htmc_surround_by_tag(ha, 4, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_aside(...) htmc_surround_by_tag(ha, 5, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_audio(...) htmc_surround_by_tag(ha, 6, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_b(...) htmc_surround_by_tag(ha, 7, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_base(...) htmc_surround_by_tag(ha, 8, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_bdi(...) htmc_surround_by_tag(ha, 9, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_bdo(...) htmc_surround_by_tag(ha, 10, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_blockquote(...) htmc_surround_by_tag(ha, 11, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_body(...) htmc_surround_by_tag(ha, 12, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_br(...) htmc_surround_by_tag(ha, 13, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_button(...) htmc_surround_by_tag(ha, 14, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_canvas(...) htmc_surround_by_tag(ha, 15, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_caption(...) htmc_surround_by_tag(ha, 16, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_cite(...) htmc_surround_by_tag(ha, 17, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_code(...) htmc_surround_by_tag(ha, 18, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_col(...) htmc_surround_by_tag(ha, 19, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_colgroup(...) htmc_surround_by_tag(ha, 20, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_data(...) htmc_surround_by_tag(ha, 21, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_datalist(...) htmc_surround_by_tag(ha, 22, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_dd(...) htmc_surround_by_tag(ha, 23, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_del(...) htmc_surround_by_tag(ha, 24, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_details(...) htmc_surround_by_tag(ha, 25, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_dfn(...) htmc_surround_by_tag(ha, 26, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_dialog(...) htmc_surround_by_tag(ha, 27, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_div(...) htmc_surround_by_tag(ha, 28, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_dl(...) htmc_surround_by_tag(ha, 29, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_dt(...) htmc_surround_by_tag(ha, 30, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_em(...) htmc_surround_by_tag(ha, 31, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_embed(...) htmc_surround_by_tag(ha, 32, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_fieldset(...) htmc_surround_by_tag(ha, 33, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_figcaption(...) htmc_surround_by_tag(ha, 34, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_figure(...) htmc_surround_by_tag(ha, 35, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_footer(...) htmc_surround_by_tag(ha, 36, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_form(...) htmc_surround_by_tag(ha, 37, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_h1(...) htmc_surround_by_tag(ha, 38, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_h2(...) htmc_surround_by_tag(ha, 39, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_h3(...) htmc_surround_by_tag(ha, 40, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_h4(...) htmc_surround_by_tag(ha, 41, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_h5(...) htmc_surround_by_tag(ha, 42, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_h6(...) htmc_surround_by_tag(ha, 43, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_head(...) htmc_surround_by_tag(ha, 44, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_header(...) htmc_surround_by_tag(ha, 45, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_hgroup(...) htmc_surround_by_tag(ha, 46, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_hr(...) htmc_surround_by_tag(ha, 47, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_html(...) htmc_surround_by_tag(ha, 48, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_i(...) htmc_surround_by_tag(ha, 49, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_iframe(...) htmc_surround_by_tag(ha, 50, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_img(...) htmc_surround_by_tag(ha, 51, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_input(...) htmc_surround_by_tag(ha, 52, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_ins(...) htmc_surround_by_tag(ha, 53, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_kbd(...) htmc_surround_by_tag(ha, 54, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_label(...) htmc_surround_by_tag(ha, 55, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_legend(...) htmc_surround_by_tag(ha, 56, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_li(...) htmc_surround_by_tag(ha, 57, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_link(...) htmc_surround_by_tag(ha, 58, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_htmc_main(...) htmc_surround_by_tag(ha, 59, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_map(...) htmc_surround_by_tag(ha, 60, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_mark(...) htmc_surround_by_tag(ha, 61, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_math(...) htmc_surround_by_tag(ha, 62, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_menu(...) htmc_surround_by_tag(ha, 63, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_meta(...) htmc_surround_by_tag(ha, 64, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_meter(...) htmc_surround_by_tag(ha, 65, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_nav(...) htmc_surround_by_tag(ha, 66, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_noscript(...) htmc_surround_by_tag(ha, 67, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_object(...) htmc_surround_by_tag(ha, 68, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_ol(...) htmc_surround_by_tag(ha, 69, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_optgroup(...) htmc_surround_by_tag(ha, 70, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_option(...) htmc_surround_by_tag(ha, 71, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_output(...) htmc_surround_by_tag(ha, 72, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_p(...) htmc_surround_by_tag(ha, 73, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_param(...) htmc_surround_by_tag(ha, 74, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_picture(...) htmc_surround_by_tag(ha, 75, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_pre(...) htmc_surround_by_tag(ha, 76, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_progress(...) htmc_surround_by_tag(ha, 77, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_q(...) htmc_surround_by_tag(ha, 78, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_rp(...) htmc_surround_by_tag(ha, 79, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_rt(...) htmc_surround_by_tag(ha, 80, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_ruby(...) htmc_surround_by_tag(ha, 81, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_s(...) htmc_surround_by_tag(ha, 82, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_samp(...) htmc_surround_by_tag(ha, 83, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_script(...) htmc_surround_by_tag(ha, 84, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_section(...) htmc_surround_by_tag(ha, 85, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_select(...) htmc_surround_by_tag(ha, 86, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_slot(...) htmc_surround_by_tag(ha, 87, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_small(...) htmc_surround_by_tag(ha, 88, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_source(...) htmc_surround_by_tag(ha, 89, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_span(...) htmc_surround_by_tag(ha, 90, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_strong(...) htmc_surround_by_tag(ha, 91, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_style(...) htmc_surround_by_tag(ha, 92, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_sub(...) htmc_surround_by_tag(ha, 93, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_summary(...) htmc_surround_by_tag(ha, 94, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_sup(...) htmc_surround_by_tag(ha, 95, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_svg(...) htmc_surround_by_tag(ha, 96, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_table(...) htmc_surround_by_tag(ha, 97, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_tbody(...) htmc_surround_by_tag(ha, 98, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_td(...) htmc_surround_by_tag(ha, 99, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_template(...) htmc_surround_by_tag(ha, 100, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_textarea(...) htmc_surround_by_tag(ha, 101, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_tfoot(...) htmc_surround_by_tag(ha, 102, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_th(...) htmc_surround_by_tag(ha, 103, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_thead(...) htmc_surround_by_tag(ha, 104, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_time(...) htmc_surround_by_tag(ha, 105, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_title(...) htmc_surround_by_tag(ha, 106, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_tr(...) htmc_surround_by_tag(ha, 107, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_track(...) htmc_surround_by_tag(ha, 108, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_u(...) htmc_surround_by_tag(ha, 109, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_ul(...) htmc_surround_by_tag(ha, 110, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_var(...) htmc_surround_by_tag(ha, 111, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_video(...) htmc_surround_by_tag(ha, 112, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))
#define htmc_wbr(...) htmc_surround_by_tag(ha, 113, htmc_concat_strings(ha, ##__VA_ARGS__, NULL))

#define htmc_attr_(...) \
__VA_ARGS__ __VA_OPT__(,) NULL))

#define htmc_attr(tag, ...) \
htmc_surround_by_tag_with_attrs(ha, htmc_id_##tag, (char*[]){__VA_ARGS__}, sizeof((char*[]){__VA_ARGS__}) / sizeof(char*), htmc_concat_strings(ha, htmc_attr_

#define htmc_id_a 0
#define htmc_id_abbr 1
#define htmc_id_address 2
#define htmc_id_area 3
#define htmc_id_article 4
#define htmc_id_aside 5
#define htmc_id_audio 6
#define htmc_id_b 7
#define htmc_id_base 8
#define htmc_id_bdi 9
#define htmc_id_bdo 10
#define htmc_id_blockquote 11
#define htmc_id_body 12
#define htmc_id_br 13
#define htmc_id_button 14
#define htmc_id_canvas 15
#define htmc_id_caption 16
#define htmc_id_cite 17
#define htmc_id_code 18
#define htmc_id_col 19
#define htmc_id_colgroup 20
#define htmc_id_data 21
#define htmc_id_datalist 22
#define htmc_id_dd 23
#define htmc_id_del 24
#define htmc_id_details 25
#define htmc_id_dfn 26
#define htmc_id_dialog 27
#define htmc_id_div 28
#define htmc_id_dl 29
#define htmc_id_dt 30
#define htmc_id_em 31
#define htmc_id_embed 32
#define htmc_id_fieldset 33
#define htmc_id_figcaption 34
#define htmc_id_figure 35
#define htmc_id_footer 36
#define htmc_id_form 37
#define htmc_id_h1 38
#define htmc_id_h2 39
#define htmc_id_h3 40
#define htmc_id_h4 41
#define htmc_id_h5 42
#define htmc_id_h6 43
#define htmc_id_head 44
#define htmc_id_header 45
#define htmc_id_hgroup 46
#define htmc_id_hr 47
#define htmc_id_html 48
#define htmc_id_i 49
#define htmc_id_iframe 50
#define htmc_id_img 51
#define htmc_id_input 52
#define htmc_id_ins 53
#define htmc_id_kbd 54
#define htmc_id_label 55
#define htmc_id_legend 56
#define htmc_id_li 57
#define htmc_id_link 58
#define htmc_id_main 59
#define htmc_id_map 60
#define htmc_id_mark 61
#define htmc_id_math 62
#define htmc_id_menu 63
#define htmc_id_meta 64
#define htmc_id_meter 65
#define htmc_id_nav 66
#define htmc_id_noscript 67
#define htmc_id_object 68
#define htmc_id_ol 69
#define htmc_id_optgroup 70
#define htmc_id_option 71
#define htmc_id_output 72
#define htmc_id_p 73
#define htmc_id_param 74
#define htmc_id_picture 75
#define htmc_id_pre 76
#define htmc_id_progress 77
#define htmc_id_q 78
#define htmc_id_rp 79
#define htmc_id_rt 80
#define htmc_id_ruby 81
#define htmc_id_s 82
#define htmc_id_samp 83
#define htmc_id_script 84
#define htmc_id_section 85
#define htmc_id_select 86
#define htmc_id_slot 87
#define htmc_id_small 88
#define htmc_id_source 89
#define htmc_id_span 90
#define htmc_id_strong 91
#define htmc_id_style 92
#define htmc_id_sub 93
#define htmc_id_summary 94
#define htmc_id_sup 95
#define htmc_id_svg 96
#define htmc_id_table 97
#define htmc_id_tbody 98
#define htmc_id_td 99
#define htmc_id_template 100
#define htmc_id_textarea 101
#define htmc_id_tfoot 102
#define htmc_id_th 103
#define htmc_id_thead 104
#define htmc_id_time 105
#define htmc_id_title 106
#define htmc_id_tr 107
#define htmc_id_track 108
#define htmc_id_u 109
#define htmc_id_ul 110
#define htmc_id_var 111
#define htmc_id_video 112
#define htmc_id_wbr 113

#define htmc_str_(...) #__VA_ARGS__
#define htmc_str(...) htmc_str_(__VA_ARGS__)

void htmc_cleanup_unused_buffers(HtmcAllocations *ha, char *ret_ptr);
char **htmc_find_buffer(HtmcAllocations *ha, const char *buffer);
void htmc_grow_buffers(HtmcAllocations *ha);
void htmc_set_unused(HtmcAllocations *ha, const char *str);
void htmc_set_unused_if_alloced(HtmcAllocations *ha, const char *str);
char **htmc_find_unused(HtmcAllocations *ha);
char **htmc_get_unused(HtmcAllocations *ha, size_t with_size);
char *htmc_concat_strings(HtmcAllocations *ha, ...);
char *htmc_surround_by_tag(HtmcAllocations *ha, uint16_t tag_id, char *between);
char *htmc_surround_by_tag_with_attrs(HtmcAllocations *ha, uint16_t tag_id, char *attrs[], size_t nb_attrs, char *between);

#endif

#ifdef HTMC_PREFIX

#undef HTMC_PREFIX

#undef htmldoc

#undef a
#undef abbr
#undef address
#undef area
#undef article
#undef aside
#undef audio
#undef b
#undef base
#undef bdi
#undef bdo
#undef blockquote
#undef body
#undef br
#undef button
#undef canvas
#undef caption
#undef cite
#undef code
#undef col
#undef colgroup
#undef data
#undef datalist
#undef dd
#undef del
#undef details
#undef dfn
#undef dialog
#undef div
#undef dl
#undef dt
#undef em
#undef embed
#undef fieldset
#undef figcaption
#undef figure
#undef footer
#undef form
#undef h1
#undef h2
#undef h3
#undef h4
#undef h5
#undef h6
#undef head
#undef header
#undef hgroup
#undef hr
#undef html
#undef i
#undef iframe
#undef img
#undef input
#undef ins
#undef kbd
#undef label
#undef legend
#undef li
#undef link
#undef htmc_main
#undef map
#undef mark
#undef math
#undef menu
#undef meta
#undef meter
#undef nav
#undef noscript
#undef object
#undef ol
#undef optgroup
#undef option
#undef output
#undef p
#undef param
#undef picture
#undef pre
#undef progress
#undef q
#undef rp
#undef rt
#undef ruby
#undef s
#undef samp
#undef script
#undef section
#undef select
#undef slot
#undef small
#undef source
#undef span
#undef strong
#undef style
#undef sub
#undef summary
#undef sup
#undef svg
#undef table
#undef tbody
#undef td
#undef template
#undef textarea
#undef tfoot
#undef th
#undef thead
#undef time
#undef title
#undef tr
#undef track
#undef u
#undef ul
#undef var
#undef video
#undef wbr

#undef attr

#else

#define htmldoc htmc_htmldoc

#define a htmc_a
#define abbr htmc_abbr
#define address htmc_address
#define area htmc_area
#define article htmc_article
#define aside htmc_aside
#define audio htmc_audio
#define b htmc_b
#define base htmc_base
#define bdi htmc_bdi
#define bdo htmc_bdo
#define blockquote htmc_blockquote
#define body htmc_body
#define br htmc_br
#define button htmc_button
#define canvas htmc_canvas
#define caption htmc_caption
#define cite htmc_cite
#define code htmc_code
#define col htmc_col
#define colgroup htmc_colgroup
#define data htmc_data
#define datalist htmc_datalist
#define dd htmc_dd
#define del htmc_del
#define details htmc_details
#define dfn htmc_dfn
#define dialog htmc_dialog
#define div htmc_div
#define dl htmc_dl
#define dt htmc_dt
#define em htmc_em
#define embed htmc_embed
#define fieldset htmc_fieldset
#define figcaption htmc_figcaption
#define figure htmc_figure
#define footer htmc_footer
#define form htmc_form
#define h1 htmc_h1
#define h2 htmc_h2
#define h3 htmc_h3
#define h4 htmc_h4
#define h5 htmc_h5
#define h6 htmc_h6
#define head htmc_head
#define header htmc_header
#define hgroup htmc_hgroup
#define hr htmc_hr
#define html htmc_html
#define i htmc_i
#define iframe htmc_iframe
#define img htmc_img
#define input htmc_input
#define ins htmc_ins
#define kbd htmc_kbd
#define label htmc_label
#define legend htmc_legend
#define li htmc_li
#define link htmc_link
#define htmc_main htmc_htmc_main
#define map htmc_map
#define mark htmc_mark
#define math htmc_math
#define menu htmc_menu
#define meta htmc_meta
#define meter htmc_meter
#define nav htmc_nav
#define noscript htmc_noscript
#define object htmc_object
#define ol htmc_ol
#define optgroup htmc_optgroup
#define option htmc_option
#define output htmc_output
#define p htmc_p
#define param htmc_param
#define picture htmc_picture
#define pre htmc_pre
#define progress htmc_progress
#define q htmc_q
#define rp htmc_rp
#define rt htmc_rt
#define ruby htmc_ruby
#define s htmc_s
#define samp htmc_samp
#define script htmc_script
#define section htmc_section
#define select htmc_select
#define slot htmc_slot
#define small htmc_small
#define source htmc_source
#define span htmc_span
#define strong htmc_strong
#define style htmc_style
#define sub htmc_sub
#define summary htmc_summary
#define sup htmc_sup
#define svg htmc_svg
#define table htmc_table
#define tbody htmc_tbody
#define td htmc_td
#define template htmc_template
#define textarea htmc_textarea
#define tfoot htmc_tfoot
#define th htmc_th
#define thead htmc_thead
#define time htmc_time
#define title htmc_title
#define tr htmc_tr
#define track htmc_track
#define u htmc_u
#define ul htmc_ul
#define var htmc_var
#define video htmc_video
#define wbr htmc_wbr

#define attr htmc_attr

#endif