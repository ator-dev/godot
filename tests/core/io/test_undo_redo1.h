/*************************************************************************/
/*  test_undo_redo.h                                                     */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2021 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef TEST_UNDO_REDO
#define TEST_UNDO_REDO

#include "core/io/resource.h"
#include "core/io/resource_loader.h"
#include "core/io/resource_saver.h"
#include "core/os/os.h"

#include "core/object/undo_redo.h"
#include "editor/animation_track_editor.h"
#include "editor/plugins/animation_player_editor_plugin.h"
#include "editor/settings_config_dialog.h"
#include "scene/animation/animation_player.h"

#include "thirdparty/doctest/doctest.h"

namespace TestUndoRedo {

/*template<class T> T f(T n);
template<int> int f(int n) {
	return n**2;
}*/

TEST_CASE("[UndoRedo][Animation] integrity") {
	EditorNode *editor_node = memnew(EditorNode);
	SceneTree::get_singleton()->get_root()->add_child(editor_node);
	CHECK_MESSAGE(false, "0");
	Node *root = SceneTree::get_singleton()->get_root();
	CHECK_MESSAGE(false, "1");
	AnimationTrackEditor *te = memnew(AnimationTrackEditor);
	CHECK_MESSAGE(false, "2");
	root->add_child(te);
	CHECK_MESSAGE(false, "3");

	/*UndoRedo *undo_redo = editor->undo_redo;
	CHECK_MESSAGE(false, stringify_variants(undo_redo->get_history_count()));
	Ref<Animation> anim = memnew(Animation);
	Node *node = Object::cast_to<Node>(memnew(Camera3D));
	node->set_name("Node");
	editor->set_animation(anim);
	anim->add_track(Animation::TYPE_VALUE);
	editor->add_child(node);
	editor->adding_track_type = Animation::TYPE_VALUE;
	editor->adding_track_path = TTR("translation/x");
	editor->_new_track_node_selected(TTR("/AnimationPlayer"));

	CHECK_MESSAGE(false, stringify_variants(undo_redo->get_history_count()));*/
}
} // namespace TestUndoRedo

#endif // TEST_UNDO_REDO
