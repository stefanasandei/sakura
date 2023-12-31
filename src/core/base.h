//
// Created by Asandei Stefan on 07.08.2023.
//

#pragma once

#include <memory>

namespace Sakura {
    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}