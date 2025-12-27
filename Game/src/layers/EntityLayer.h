#include "src/layers/Layer.h"
#include "src/entities/Player.h"

class EntityLayer : public Layer
{
private:
	Player* m_Player;

public:
	EntityLayer(const std::string& layerName);
	~EntityLayer();
	
	void Update() override;
	void Render() override;
};

