#include "src/layers/Layer.h"
#include "src/entities/Player.h"

class EntityLayer : public Layer
{
private:
	Player* m_Player;

public:
	EntityLayer(const std::string& layerName, SDL_Renderer* renderer);
	~EntityLayer();
	
	void Update() override;
	void Render() override;

	inline Player* GetPlayer() const { return m_Player; }
};

