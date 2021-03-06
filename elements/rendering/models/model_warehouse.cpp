#include "model_warehouse.h"

#include "assets/assets_storage.h"
#include "assets/asset_texture.h"
#include "rendering/state/state_macro.h"
#include "rendering/utils/program_loader.h"
#include "rendering/core/texture_maker.h"
#include "rendering/core/texture_policy.h"

namespace eps {
namespace rendering {

model_warehouse::geometry::geometry(const std::vector<scene::vertex> & vertices,
                                    const std::vector<scene::face> & faces)
{
    vertices_.allocate(vertices.data(), vertices.size(), sizeof(scene::vertex));
    indices_.allocate(faces.data(), faces.size() * scene::face::FACE_INDICES_COUNT,
                      sizeof(unsigned short));
}

void model_warehouse::material::set_texture(scene::material::type_texture type,
                                            const product_type & texture)
{
    textures_[utils::to_int(type)] = texture;
}

void model_warehouse::material::set_color(scene::material::type_color type, const math::vec3 & color)
{
    colors_[utils::to_int(type)] = color;
}

const utils::optional<product_type> & model_warehouse::material::get_texture(scene::material::type_texture type) const
{
    return textures_[utils::to_int(type)];
}

const math::vec3 & model_warehouse::material::get_color(scene::material::type_color type) const
{
    return colors_[utils::to_int(type)];
}

void model_warehouse::add_geometry(const std::vector<scene::vertex> & vertices,
                                   const std::vector<scene::face> & faces)
{
    geometry_.emplace_back(vertices, faces);
}

void model_warehouse::add_material(const scene::material & data)
{
    material result;
    for(size_t i = 0; i < utils::to_int(scene::material::type_texture::COUNT); ++i)
    {
        if(const auto & name = data.get_texture(scene::material::type_texture(i)))
        {
            auto & texture = textures_[name.value()];
            if(!texture.valid())
            {
                if(auto asset = assets_storage::instance().read<asset_texture>(name.value()))
                {
                    auto maker = get_texture_maker<repeat_texture_policy>(asset->format());
                    texture = maker.construct(asset->pixels(), asset->size());
                }
            }

            result.set_texture(scene::material::type_texture(i), texture.get_product());
        }
    }

    for(size_t i = 0; i < utils::to_int(scene::material::type_color::COUNT); ++i)
        result.set_color(scene::material::type_color(i), data.get_color(scene::material::type_color(i)));

    materials_.push_back(std::move(result));
}

} /* rendering */
} /* eps */
