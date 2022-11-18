#include <emscripten/val.h>
#include "asm-dom.hpp"
#include "globals.h"

bool decrease(emscripten::val) {
  i--;
  render();
  return true;
};

bool increase(emscripten::val) {
  i++;
  render();
  return true;
};

asmdom::VNode* index_() {
  asmdom::VNode* new_node = html(
    <div class="root" onclick={[](emscripten::val e) -> bool {
      emscripten::val::global("console").call<void>("log", emscripten::val("another click"));
      return true;
    }}>
      <a
        class="button"
        onclick={decrease}
      >
        -
      </a>
      {{ std::to_string(i) }}
      <a
        class="button"
        onclick={increase}
      >
        +
      </a>

      <div
        style="
          position: absolute;
          bottom: 8px;
          font-size: 12px;
        "
      >
        asm-dom-boilerplate
      </div>
    </div>
  );
  return new_node;
};