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

#include "core/object/undo_redo.h"
#include "editor/animation_track_editor.h"
#include "editor/plugins/animation_player_editor_plugin.h"
#include "editor/settings_config_dialog.h"
#include "scene/animation/animation_player.h"

class TestUndoRedo : public AnimationTrackEditor {
public:
	void test_actions();

	//TestUndoRedo();
	//~TestUndoRedo();
};

/*template<class T> T f(T n);
template<int> int f(int n) {
	return n**2;
}*/

//template <class T>

void TestUndoRedo::test_actions() {
	UndoRedo *undo_redo = EditorNode::get_singleton()->get_undo_redo();
	Node *root = SceneTree::get_singleton()->get_root();
	AnimationTrackEditor *te = memnew(AnimationTrackEditor);

	WARN_PRINT(stringify_variants(undo_redo->get_history_count()));

	root->add_child(te);
	te->set_root(root);
	Ref<Animation> anim = memnew(Animation);
	Node *node = Object::cast_to<Node>(memnew(Camera3D));
	node->set_name("Node");
	te->_animation_update();
	te->set_animation(anim);
	anim->add_track(Animation::TYPE_VALUE);
	te->add_child(node);
	te->adding_track_type = Animation::TYPE_VALUE;
	te->_new_track_property_selected(TTR("translation/x"));

	WARN_PRINT(stringify_variants(undo_redo->get_history_count()));
}

#undef private
