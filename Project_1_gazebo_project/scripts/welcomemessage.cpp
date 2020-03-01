#include <gazebo/gazebo.hh>

namespace gazebo
{
  class WelcomeMessage : public WorldPlugin
  {
    public: WelcomeMessage() : WorldPlugin()
            {
	      printf("\n");
	      printf("************************************************\n");
              printf("This is a welcome message...Welcome to my cool offce.\n");
 	      printf("************************************************\n");
            }

    public: void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
            {
            }
  };
  GZ_REGISTER_WORLD_PLUGIN(WelcomeMessage)
}
